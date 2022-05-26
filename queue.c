/*
	DeHaustier
	Program: queue.c
	Deskripsi: implementasi bpdy dari queue.h
*/

#include "queue.h"
#include <string.h>
#include <stdlib.h>

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
		if(isQueEmpty((*Q))){
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
		print("Antrian kosong\n");
	}
	else{
		P = HEAD(*Q);
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
	system("cls");
	infoPasien X;
	createList(&X.listPenyakit);
	infoPenyakit Y;
	int tempPenyakit[9];
	int i, totalPenyakit, countRingan, countSedang, countBerat;
	
	printf("Registrasi\n");
	printf("=======================\n\n");
	printf("Nama Pemilik: ");
	scanf("%s", &X.namaPemilik);
	printf("Nama Hewan: ");
	scanf("%s", &X.namaHewan);
	printf("Waktu datang: ");
	scanf("%d", &X.waktuDatang);
	printf("Penyakit:\n");
	printPenyakit();
	printf("\nJumlah Penyakit: ");
	scanf("%d", &totalPenyakit);
	printf("Penyakit yang diderita (1-9): ");
	for(i=0; i < totalPenyakit; i++){
		scanf(" %d", &tempPenyakit[i]);
	}
	
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
	system("cls");
	address P = HEAD(Q);
	int i = 1;
	
	printf("Antrian\n");
	printf("============================\n\n");
	
	if(isQueEmpty(Q)){
		printf("Antrian kosong\n");
	}
	else{
		while(P != Nil){
			printf("No. Antrian : %d\n", i);
			printf("Nama Pemilik : %s\n", InfoQ(P).namaPemilik);
			printf("Nama Hewan : %s\n", InfoQ(P).namaHewan);
			printf("Waktu datang : %d\n", InfoQ(P).waktuDatang);
			printf("Penyakit yang diderita : ");
			printList(InfoQ(P).listPenyakit, arrPenyakit);
			printf("Nilai prioritas : %d\n", InfoQ(P).nilaiPrioritas);
			printf("Estimasi waktu pelayanan :", InfoQ(P).waktuEstimasi);
			printf("Waktu tunggu : %d\n", InfoQ(P).waktuTunggu);
			printf("Waktu mulai pelayanan : %d\n", InfoQ(P).waktuMulai);
			printf("Waktu pelayanan selesai : %d\n", InfoQ(P).waktuSelesai);
			printf("-----------------------------------------------\n");
			i++;
			P = NextQ(P);
		}
	}
}

/* Memproses antrian untuk dilakukan pelayanan pada pasien dan keluar dari antrian */
void prosesAntrian(Queue *Q){
	
}

/* Menampilkan list penyakit yang bisa dipilih */
void printPenyakit(){
	int i;
	
	for(i = 0; i<9; i++){
		printf("%d. %s\n", i+1, arrPenyakit[i]);
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
	/*ver 1 masih error 26 Mei 22*/
	address P, prev;
	
	P = HEAD(*Q);
	while(P != Nil){
		if(P == HEAD(*Q)){
			InfoQ(P).waktuTunggu = 0;
			InfoQ(P).waktuMulai = InfoQ(P).waktuDatang;
			InfoQ(P).waktuSelesai = InfoQ(P).waktuMulai + InfoQ(P).waktuEstimasi;
		}
		else{
			if(InfoQ(prev).waktuSelesai > InfoQ(P).waktuDatang){
				InfoQ(P).waktuTunggu = InfoQ(prev).waktuSelesai - InfoQ(P).waktuDatang;
			}
			else{
				InfoQ(P).waktuTunggu = 0;
				InfoQ(P).waktuMulai = InfoQ(P).waktuTunggu + InfoQ(P).waktuDatang;
				InfoQ(P).waktuSelesai = InfoQ(P).waktuMulai + InfoQ(P).waktuEstimasi;
			}
		}
		prev = P;
		P = NextQ(P);
	}
}