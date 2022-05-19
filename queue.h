/*
	DeHaustier
	Program: queue.h
	Deskripsi: File header ADT Priority Queue
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <conio.h>
#include "boolean.h"
#include "list.h"

#define Nil NULL
#define HEAD(Q) (Q).HEAD
#define TAIL(Q) (Q).TAIL
#define Info(P) (P)->info
#define Next(P) (P)->next

typedef struct tElmQueue *address;
typedef struct {
	char namaPemilik[50];
	char namaHewan[25];
	int waktuDatang;
	int nilaiPrioritas;
	int waktuEstimasi;
	int waktuTunggu;
	int waktuMulai;
	int waktuSelesai;
	List listPenyakit;
}infoPasien;
typedef struct tElmQueue {
	infoPasien info;
	address next;
}ElmQueue; 
typedef struct{
	address HEAD;
	address TAIL;
}Queue;

/* ==== Konstruktor ==== */
/* Mengirimkan address hasil alokasi elemen dengan info X */
address alokasi(infoPasien X);

/* Melakukan dealokasi memori dari elmen P */
void dealokasi(address P);

/* Membuat Queue kosong dengan HEAD = Nil dan TAIL = Nil */
void createQueue(Queue *Q);

/* Mengembalikan nilai true jika Queue kosong */
boolean isQueEmpty(Queue Q);

/* Memasukkan info elemen baru ke dalam Queue */
void enQueue(Queue *Q, infoPasien X);

/* Mengeluarkan elemen dari Queue */
void deQueue(Queue *Q);

/* Melakukan registrasi untuk menambahkan data pasien */
void registrasi(Queue *Q);

/* Menampilkan isi antrian Queue */
void printQueue(Queue Q);

/* Memproses antrian untuk dilakukan pelayanan pada pasien dan keluar dari antrian */
void prosesAntrian(Queue *Q);

/* Menampilkan list penyakit yang bisa dipilih */
void printPenyakit();

/* Memeriksa kategori penyakit */
char *cekKategori(int penyakit);

/* Menghitung nilai prioritas berdasarkan kategori penyakit */
int hitungPrioritas(int ringan, int sedang, int berat);

/* Menghitung estimasi lama pelayanan berdasarkan penyakit yang diderita */
int cekEkstimasi(int penyakit);

/* Menghitung estimasi pelayanan selesai */
int hitungEstimasi(int ringan, int sedang, int berat);

/* Menghitung waktu mulai hingga selesai dan berapa lama pasien menunggu */
void hitungWaktu(Queue *Q);

#endif
