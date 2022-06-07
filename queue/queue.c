/*
	DeHaustier
	Program: queue.c
	Deskripsi: implementasi body dari queue.h
*/

#include "queue.h"
#include <string.h>
#include <stdlib.h>

time latestSelesai; //untuk menyimpan waktu selesai terakhir yang telah terhapus
//Daftar penyakit yang tersedia
char *arrPenyakit[9] = {
	"Penyakit kulit",
	"Luka ringan",
	"Bersin",
	"Cacingan",
	"Diare",
	"Luka dalam",
	"Kerongkongan berlendir dan berbau busuk",
	"Penyakit kuning",
	"Terkena virus"
};

/* ==== Konstruktor ==== */
/* Mengirimkan address hasil alokasi elemen dengan info X 
   Author : Fariz Muhamad Ibnu */
address alokasi(infoPasien X){
	address P;
	
	P = (address)malloc(sizeof(ElmQueue));
	if(P != Nil){
		InfoQ(P) = X;
		NextQ(P) = Nil;
	}
	
	return P;
}

/* Melakukan dealokasi memori dari elmen P
   Author : Yane Pradita */
void dealokasi(address P){
	NextQ(P) = Nil;
	free(P);
}

/* Membuat Queue kosong dengan HEAD = Nil dan TAIL = Nil
   Author : Fariz Muhamad Ibnu */
void createQueue(Queue *Q){
	HEAD(*Q) = Nil;
}

/* Mengembalikan nilai true jika Queue kosong 
   Author : Fariz Muhamad Ibnu */
boolean isQueEmpty(Queue Q){
	return (HEAD(Q) == Nil);
}

/* Memasukkan info elemen baru ke dalam Queue 
   Author : Salsabila Maharani Putri */
void enQueue(Queue *Q, infoPasien X){
	address P, temp;
	
	P = alokasi(X);
	if(P != Nil){
		if(isQueEmpty((*Q)) || X.nilaiPrioritas > InfoQ(HEAD(*Q)).nilaiPrioritas){
			NextQ(P) = HEAD(*Q);
			HEAD(*Q) = P;
		}
		else{
			temp = HEAD(*Q);
			while((NextQ(temp) != Nil) && (InfoQ(NextQ(temp)).nilaiPrioritas >= X.nilaiPrioritas)){
				temp = NextQ(temp);
			}
			NextQ(P) = NextQ(temp);
			NextQ(temp) = P;
		}
	}
}

/* Mengeluarkan elemen dari Queue 
   Author : Fariz Muhamad Ibnu */
void deQueue(Queue *Q){
	address P;
	
	if(isQueEmpty(*Q)){
		printf("Antrian kosong\n");
	}
	else{
		P = HEAD(*Q);
		latestSelesai = InfoQ(P).waktuSelesai;
		if(NextQ(P) == Nil){
			HEAD(*Q) = Nil;
		}
		else{
			HEAD(*Q) = NextQ(HEAD(*Q));
		}
		NextQ(P) = Nil;
		dealokasi(P);
	}
}

/* Melakukan registrasi untuk menambahkan data pasien 
   Author : Salsabila Maharani Putri */
void registrasi(Queue *Q){
	infoPasien X;
	createList(&X.listPenyakit);
	infoPenyakit Y;
	int tempPenyakit[9];
	int i, totalPenyakit, countRingan, countSedang, countBerat;
	char empty = ' ';
	time maxWaktuDatang = getWaktuDatangTerbaru((*Q));
	
	printf("\n%40.cNama Pemilik: ",empty);
	scanf("%s", &X.namaPemilik);
	printf("%40.cNama Hewan: ",empty);
	scanf("%s", &X.namaHewan);
	
	do{
		printf("%40.cWaktu datang (e.g 7 20): ",empty);
		readTime(&X.waktuDatang);
	}while(!isTimeValid(X.waktuDatang) || isLessThan(X.waktuDatang, maxWaktuDatang));
	
	fflush(stdin);
	printf("\n%40.cPenyakit:\n",empty);
	printPenyakit();
	printf("\n%40.cJumlah Penyakit: ",empty);
	scanf("%d", &totalPenyakit);
	printf("%40.cPenyakit yang diderita (1-9): ",empty);
	for(i=0; i < totalPenyakit; i++){
		scanf(" %d", &tempPenyakit[i]);
		printf("%70.c",empty);
	}
	printf("\n");
	
	countRingan = 0;
	countSedang = 0;
	countBerat = 0;
	for(i=0; i < totalPenyakit; i++){
		Y.penyakit = tempPenyakit[i];
		strcpy(Y.kategori, cekKategori(tempPenyakit[i]));
		Y.waktuEstimasi = cekEkstimasi(tempPenyakit[i]);
		insertLast(&X.listPenyakit, Y);
		
		if((tempPenyakit[i] > 0) && (tempPenyakit[i] < 4)){
			countRingan++;
		}
		if((tempPenyakit[i] >= 4) && (tempPenyakit[i] < 7)){
			countSedang++;
		}
		if((tempPenyakit[i] >= 7) && (tempPenyakit[i] < 10)){
			countBerat++;
		}
	}
	
	X.nilaiPrioritas = hitungPrioritas(countRingan, countSedang, countBerat);
	X.waktuEstimasi = hitungEstimasi(countRingan, countSedang, countBerat);
	
	enQueue(Q, X);
	hitungWaktu(*(&Q));
}

/* Menampilkan isi antrian Queue 
   Author : Fariz Muhamad Ibnu */
void printQueue(Queue Q){
	address P = HEAD(Q);
	int i = 1;
	char empty = ' ';
	
	if(isQueEmpty(Q)){
		printf("\n%50.cAntrian kosong\n",empty);
	}
	else{
			printf("\n%40.cJUMLAH ANTRIAN : %d\n\n",empty, (jumlahAntrian(Q)));
		while(P != Nil){
			printf("%40.cNo. Antrian : %d\n",empty, i);
			printf("%40.cNama Pemilik : %s\n",empty, InfoQ(P).namaPemilik);
			printf("%40.cNama Hewan : %s\n",empty, InfoQ(P).namaHewan);
			printf("%40.cWaktu datang : ",empty); printTime(InfoQ(P).waktuDatang);
			printf("\n%40.cPenyakit yang diderita : ",empty);
			printList(InfoQ(P).listPenyakit, arrPenyakit);
			printf("\n%40.cNilai prioritas : %d\n",empty, InfoQ(P).nilaiPrioritas);
			printf("%40.cEstimasi waktu pelayanan : %d menit\n",empty, InfoQ(P).waktuEstimasi);
			printf("%40.cWaktu tunggu : %d menit\n",empty, InfoQ(P).waktuTunggu);
			printf("%40.cWaktu mulai pelayanan : ",empty); printTime(InfoQ(P).waktuMulai);
			printf("\n%40.cWaktu pelayanan selesai : ",empty); printTime(InfoQ(P).waktuSelesai);
			printf("\n%40.c-----------------------------------------------\n",empty);
			i++;
			P = NextQ(P);
		}
	
	}
}

/* Memproses antrian untuk dilakukan pelayanan pada pasien dan keluar dari antrian 
   Author : Yane Pradita */
void prosesAntrian(Queue *Q){
	address P;	
	int i=1;
	char pilih;
	char empty = ' ';
	
	P = (*Q).HEAD;
	
	
	
	if (P == Nil) { // Jika Queue Kosong
		printf("\n%43.c* Tidak Ada Antrian yang Terdaftar *\n\n",empty);
    } else {
			printf("\n%40.cNo. Antrian                 : %d\n",empty, i++);
			printf("%40.cNama Pemilik                : %s\n",empty, InfoQ(P).namaPemilik);
			printf("%40.cNama Hewan                  : %s\n",empty, InfoQ(P).namaHewan);
			printf("%40.cWaktu Datang                : ",empty); printTime(InfoQ(P).waktuDatang);
			printf("\n%40.cPenyakit yang diderita : ",empty);
			printList(InfoQ(P).listPenyakit, arrPenyakit);
			printf("\n%40.cNilai Prioritas             : %d\n",empty, InfoQ(P).nilaiPrioritas);
			printf("%40.cEstimasi Waktu Pelayanan    : %d menit\n",empty, InfoQ(P).waktuEstimasi);
			printf("%40.cWaktu Tunggu Pelayanan      : %d menit\n",empty, InfoQ(P).waktuTunggu);
			printf("%40.cWaktu Mulai Pelayanan       : ",empty); printTime(InfoQ(P).waktuMulai);
			printf("\n%40.cWaktu Selesai Pelayanan     : ",empty); printTime(InfoQ(P).waktuSelesai);
			printf("\n%40.c------------------------------------\n",empty);
			printf("%40.cMemulai Proses Pelayanan Untuk %s? [Y/N] ",empty, InfoQ(P).namaHewan);
			fflush(stdin);
			scanf("%c", &pilih);
			
			if(pilih == 'Y' || pilih == 'y'){
				deQueue(Q);
				printf("\n");
				printf("					       * Harap bersabar *\n");
				printf("					  * Hewan Anda Sedang Diobati *\n\n");
			} 
			else if(pilih == 'N' || pilih == 'n'){
				printf("					*  Silahkan Kembali Ke Antrian *\n");
			}
	}	
}

/* Menampilkan list penyakit yang bisa dipilih 
   Author : Fariz Muhamad Ibnu */
void printPenyakit(){
		int i, j;
		char empty = ' ';
	for(i = 1; i < 4; i++){
		if(i == 1){
			printf(" %40.c [Kategori Ringan]\n",empty);
			for(j = 0; j < 3; j++){
					printf("%40.c%d. %s\n",empty, j+1, arrPenyakit[j]);
			}
		}else if(i == 2){
				printf(" %40.c [Kategori Sedang]\n",empty);
			for(j = 3; j < 6; j++){
				printf("%40.c%d. %s\n",empty, j+1, arrPenyakit[j]);
			}
		}else{
				printf(" %40.c [Kategori Berat]\n",empty);
			for(j = 6; j < 9; j++){
					printf("%40.c%d. %s\n",empty, j+1, arrPenyakit[j]);
			}
		}
	}
}

/* Memeriksa kategori penyakit 
   Author : Yane Pradita */
char *cekKategori(int penyakit){
	if(penyakit < 4){
		return "Ringan";
	}
	else if(penyakit <7){
		return "Sedang";
	}
	else{
		return "Berat";
	}
}

/* Menghitung nilai prioritas berdasarkan kategori penyakit 
   Author : Yane Pradita */
int hitungPrioritas(int ringan, int sedang, int berat){
	int nilai = 1;
	
	if(berat >= 1){
		nilai += 4;
	}
	if(sedang >= 2){
		nilai += 3;
	}
	if(ringan >= 3){
		nilai += 2;
	}
	
	return nilai;
}

/* Menghitung estimasi lama pelayanan berdasarkan penyakit yang diderita 
   Author : Yane Pradita */
int cekEkstimasi(int penyakit){
	int estimasi = 0;
	if(penyakit < 4){
		estimasi = 15;
	}
	else if(penyakit < 7){
		estimasi = 30;
	}
	else if(penyakit < 10){
		estimasi = 45;
	}
	return estimasi;
}

/* Menghitung estimasi pelayanan selesai 
   Author : Yane Pradita */
int hitungEstimasi(int ringan, int sedang, int berat){
	return ((ringan * 15) + (sedang * 30) + (berat *45));
}

/* Menghitung waktu mulai hingga selesai dan berapa lama pasien menunggu 
   Author : Salsabila Maharani Putri */
void hitungWaktu(Queue *Q){
	address P, prev;
	
	P = HEAD(*Q);
	if(isNotStarted(latestSelesai) || isLessThan(latestSelesai, InfoQ(P).waktuDatang)){
		InfoQ(P).waktuTunggu = 0;
		InfoQ(P).waktuMulai = InfoQ(P).waktuDatang;
	}
	else{
		InfoQ(P).waktuTunggu = hourToMinute(substractTime(latestSelesai, InfoQ(P).waktuDatang));
		InfoQ(P).waktuMulai = latestSelesai;
	}
	
	InfoQ(P).waktuSelesai = addMinute(InfoQ(P).waktuMulai, InfoQ(P).waktuEstimasi);
	prev = P;
	P = NextQ(P);
	while(P != Nil){
		InfoQ(P).waktuTunggu = hourToMinute(substractTime(InfoQ(prev).waktuSelesai, InfoQ(P).waktuDatang));
		InfoQ(P).waktuMulai = addMinute(InfoQ(P).waktuDatang, InfoQ(P).waktuTunggu);
		if(InfoQ(P).waktuTunggu <= 0){
			InfoQ(P).waktuTunggu = 0;
			InfoQ(P).waktuMulai = InfoQ(P).waktuDatang;
		}
		InfoQ(P).waktuSelesai = addMinute(InfoQ(P).waktuMulai, InfoQ(P).waktuEstimasi);
		prev = P;
		P = NextQ(P);
	}
}

/* Mengirimkan nilai waktu datang terbaru atau terbesar 
   Author : Salsabila Maharani Putri */
time getWaktuDatangTerbaru(Queue Q){
	time waktuMax;
	createTime(&waktuMax, 0, 0);
	
	address P = HEAD(Q);
	
	if(!isQueEmpty(Q)){
		waktuMax = InfoQ(P).waktuDatang;
		while(NextQ(P) != Nil){
			if(isEqual(InfoQ(P).waktuDatang, InfoQ(NextQ(P)).waktuDatang) || isGreatestThan(InfoQ(P).waktuDatang, InfoQ(NextQ(P)).waktuDatang)){
				waktuMax = InfoQ(P).waktuDatang;
			}
			else{
				waktuMax = InfoQ(NextQ(P)).waktuDatang;
			}
			P = NextQ(P);
		}
	}
	
	return waktuMax;
	
}

/* Menghitung jumlah antrian
   Author : Yane Pradita */
int jumlahAntrian(Queue Q){
		int jumlah = 0;
		address P = HEAD(Q);
		char empty = ' ';
		
		if(isQueEmpty(Q)){
		printf("\n%50.cAntrian kosong\n",empty);	
		}else {
			while (P != NULL) {
				jumlah++;
				P = NextQ(P);
			}
			
		}
		return jumlah;
}
