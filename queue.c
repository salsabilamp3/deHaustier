/*
	DeHaustier
	Program: queue.c
	Deskripsi: implementasi bpdy dari queue.h
*/

#include "queue.h"
#include <string.h>
#include <stdlib.h>

int latestSelesai = 0;
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
/* Mengirimkan address hasil alokasi elemen dengan info X */
address alokasi(infoPasien X){
	address P;
	
	P = (address)malloc(sizeof(ElmQueue));
	if(P != Nil){
		InfoQ(P) = X;
		NextQ(P) = Nil;
	}
	
	return P;
}

/* Melakukan dealokasi memori dari elmen P */
void dealokasi(address P){
	NextQ(P) = Nil;
	free(P);
}

/* Membuat Queue kosong dengan HEAD = Nil dan TAIL = Nil */
void createQueue(Queue *Q){
	HEAD(*Q) = Nil;
}

/* Mengembalikan nilai true jika Queue kosong */
boolean isQueEmpty(Queue Q){
	return (HEAD(Q) == Nil);
}

/* Memasukkan info elemen baru ke dalam Queue */
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

/* Mengeluarkan elemen dari Queue */
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

/* Melakukan registrasi untuk menambahkan data pasien */
void registrasi(Queue *Q){
	infoPasien X;
	createList(&X.listPenyakit);
	infoPenyakit Y;
	int tempPenyakit[9];
	int i, totalPenyakit, countRingan, countSedang, countBerat;
	char empty = ' ';
	int maxWaktuDatang = getWaktuDatangTerbaru((*Q));
	
	printf("\n%40.cNama Pemilik: ",empty);
	scanf("%s", &X.namaPemilik);
	printf("%40.cNama Hewan: ",empty);
	scanf("%s", &X.namaHewan);
	
	do{
		printf("%40.cWaktu datang: ",empty);
		scanf("%d", &X.waktuDatang);
	}while(X.waktuDatang < maxWaktuDatang);
	
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

/* Menampilkan isi antrian Queue */
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
			printf("%40.cWaktu datang : %d\n",empty, InfoQ(P).waktuDatang);
			printf("%40.cPenyakit yang diderita : ",empty);
			printList(InfoQ(P).listPenyakit, arrPenyakit);
			printf("\n%40.cNilai prioritas : %d\n",empty, InfoQ(P).nilaiPrioritas);
			printf("%40.cEstimasi waktu pelayanan : %d\n",empty, InfoQ(P).waktuEstimasi);
			printf("%40.cWaktu tunggu : %d\n",empty, InfoQ(P).waktuTunggu);
			printf("%40.cWaktu mulai pelayanan : %d\n",empty, InfoQ(P).waktuMulai);
			printf("%40.cWaktu pelayanan selesai : %d\n",empty, InfoQ(P).waktuSelesai);
			printf("%40.c-----------------------------------------------\n",empty);
			i++;
			P = NextQ(P);
		}
	
	}
}

/* Memproses antrian untuk dilakukan pelayanan pada pasien dan keluar dari antrian */
void prosesAntrian(Queue *Q){
	address P;
	infoPasien R;	
	int i=1;
	char pilih;
	char empty = ' ';
	
	P = (*Q).HEAD;
	
	
	
	if (P == Nil) { // Jika Queue Kosong
		printf("\n%43.c* Tidak Ada Antrian yang Terdaftar *\n\n",empty);
    } else {
		do{
			printf("\n%40.cNo. Antrian                 : %d\n",empty, i++);
			printf("%40.cNama Hewan                  : %s\n",empty, InfoQ(P).namaHewan);
			printf("%40.cDatang di menit ke          : %d\n",empty, InfoQ(P).waktuDatang);
			printf("%40.cPenyakit yang diderita : ",empty);
			printList(InfoQ(P).listPenyakit, arrPenyakit);
			printf("\n%40.cNilai Prioritas             : %d\n",empty, InfoQ(P).nilaiPrioritas);
			printf("%40.cEstimasi Waktu Pelayanan    : %d\n",empty, InfoQ(P).waktuEstimasi);
			printf("%40.cWaktu Tunggu Pelayanan      : %d\n",empty, InfoQ(P).waktuTunggu);
			printf("%40.cWaktu Mulai Pelayanan       : %d\n",empty, InfoQ(P).waktuMulai);
			printf("%40.cWaktu Selesai Pelayanan     : %d\n",empty, InfoQ(P).waktuSelesai);		
			printf("%40.c------------------------------------\n",empty);
			P = NextQ(P);
			R = (*Q).HEAD->info ;
			printf("%40.cMemulai Proses Pelayanan Untuk %s? [Y/N] ",empty, R.namaHewan);
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
		}while(P != Nil && (pilih == 'Y' || pilih == 'y'));
	}	
}

/* Menampilkan list penyakit yang bisa dipilih */
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

/* Memeriksa kategori penyakit */
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

/* Menghitung nilai prioritas berdasarkan kategori penyakit */
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

/* Menghitung estimasi lama pelayanan berdasarkan penyakit yang diderita */
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

/* Menghitung estimasi pelayanan selesai */
int hitungEstimasi(int ringan, int sedang, int berat){
	return ((ringan * 15) + (sedang * 30) + (berat *45));
}

/* Menghitung waktu mulai hingga selesai dan berapa lama pasien menunggu */
void hitungWaktu(Queue *Q){
	address P, prev;
	
	P = HEAD(*Q);
	if(latestSelesai == 0 || latestSelesai < InfoQ(P).waktuDatang){
		InfoQ(P).waktuTunggu = 0;
		InfoQ(P).waktuMulai = InfoQ(P).waktuDatang;
	}
	else{
		InfoQ(P).waktuTunggu = latestSelesai - InfoQ(P).waktuDatang;
		InfoQ(P).waktuMulai = latestSelesai;
	}
	
	InfoQ(P).waktuSelesai = InfoQ(P).waktuMulai + InfoQ(P).waktuEstimasi;
	prev = P;
	P = NextQ(P);
	while(P != Nil){
		InfoQ(P).waktuTunggu = InfoQ(prev).waktuSelesai - InfoQ(P).waktuDatang;
		InfoQ(P).waktuMulai = InfoQ(P).waktuTunggu + InfoQ(P).waktuDatang;
		if(InfoQ(P).waktuTunggu <= 0){
			InfoQ(P).waktuTunggu = 0;
			InfoQ(P).waktuMulai = InfoQ(P).waktuDatang;
		}
		InfoQ(P).waktuSelesai = InfoQ(P).waktuMulai + InfoQ(P).waktuEstimasi;
		prev = P;
		P = NextQ(P);
	}
}

/* Mengirimkan nilai waktu datang terbaru atau terbesar */
int getWaktuDatangTerbaru(Queue Q){
	int max = 0;
	address P = HEAD(Q);
	
	if(!isQueEmpty(Q)){
		max = InfoQ(P).waktuDatang;
		while(NextQ(P) != Nil){
			if(InfoQ(P).waktuDatang >= InfoQ(NextQ(P)).waktuDatang){
				max = InfoQ(P).waktuDatang;
			}
			else{
				max = InfoQ(NextQ(P)).waktuDatang;
			}
			P = NextQ(P);
		}
	}
	
	return max;
	
}

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
