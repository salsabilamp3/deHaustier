/*
	DeHaustier
	Program: queue.h
	Deskripsi: File header ADT Priority Queue
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <conio.h>
#include "..\boolean.h"
#include "..\list\list.h"
#include "..\time\time.h"

#define HEAD(Q) (Q).HEAD
#define InfoQ(P) (P)->info
#define NextQ(P) (P)->next

typedef struct tElmQueue *address;
typedef struct {
	char namaPemilik[50];
	char namaHewan[25];
	time waktuDatang;
	int nilaiPrioritas;
	int waktuEstimasi;
	int waktuTunggu;
	time waktuMulai;
	time waktuSelesai;
	List listPenyakit;
}infoPasien;
typedef struct tElmQueue {
	infoPasien info;
	address next;
}ElmQueue; 
typedef struct{
	address HEAD;
}Queue;

/* ==== Konstruktor ==== */
/* Mengirimkan address hasil alokasi elemen dengan info X 
   Author : Fariz Muhamad Ibnu */
address alokasi(infoPasien X);

/* Melakukan dealokasi memori dari elmen P
   Author : Yane Pradita */
void dealokasi(address P);

/* Membuat Queue kosong dengan HEAD = Nil dan TAIL = Nil
   Author : Fariz Muhamad Ibnu */
void createQueue(Queue *Q);

/* Mengembalikan nilai true jika Queue kosong 
   Author : Fariz Muhamad Ibnu */
boolean isQueEmpty(Queue Q);

/* Memasukkan info elemen baru ke dalam Queue 
   Author : Salsabila Maharani Putri */
void enQueue(Queue *Q, infoPasien X);

/* Mengeluarkan elemen dari Queue */
void deQueue(Queue *Q);

/* Melakukan registrasi untuk menambahkan data pasien 
   Author : Salsabila Maharani Putri */
void registrasi(Queue *Q);

/* Menampilkan isi antrian Queue 
   Author : Fariz Muhamad Ibnu */
void printQueue(Queue Q);

/* Memproses antrian untuk dilakukan pelayanan pada pasien dan keluar dari antrian 
   Author : Yane Pradita */
void prosesAntrian(Queue *Q);

/* Menampilkan list penyakit yang bisa dipilih 
   Author : Fariz Muhamad Ibnu */
void printPenyakit();

/* Memeriksa kategori penyakit 
   Author : Yane Pradita */
char *cekKategori(int penyakit);

/* Menghitung nilai prioritas berdasarkan kategori penyakit 
   Author : Yane Pradita */
int hitungPrioritas(int ringan, int sedang, int berat);

/* Menghitung estimasi lama pelayanan berdasarkan penyakit yang diderita 
   Author : Yane Pradita */
int cekEkstimasi(int penyakit);

/* Menghitung estimasi pelayanan selesai 
   Author : Yane Pradita */
int hitungEstimasi(int ringan, int sedang, int berat);

/* Menghitung waktu mulai hingga selesai dan berapa lama pasien menunggu 
   Author : Salsabila Maharani Putri */
void hitungWaktu(Queue *Q);

/* Mengirimkan nilai waktu datang terbaru atau terbesar 
   Author : Salsabila Maharani Putri */
time getWaktuDatangTerbaru(Queue Q);

/* Menghitung jumlah antrian
   Author : Yane Pradita */
int jumlahAntrian(Queue Q);

#endif
