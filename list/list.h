/*
	DeHaustier
	Program: list.h
	Deskripsi: File header ADT List untuk list penyakit
*/

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <conio.h>
#include "..\boolean.h"

#define Nil NULL
#define InfoL(P) (P)->info
#define NextL(P) (P)->next
#define First(L) (L).First

typedef struct  {
	int penyakit;
	int waktuEstimasi;
	char kategori[8];
}infoPenyakit;
typedef struct tElmtList *adrList;
typedef struct tElmtList{
	infoPenyakit info;
	adrList next;
}ElmList;
typedef struct {
	adrList First;
}List;

/* ==== Konstruktor ==== */
/* Mengirimkan address hasil alokasi elemen dengan info X 
   Author : Fariz Muhamad Ibnu */
adrList alokList(infoPenyakit X);

/* Melakukan dealokasi memori dari elmen P 
   Author : Yane Pradita */
void dealokList(adrList P);

/* Membuat List kosong dengan First = Nil 
   Author : Yane Pradita */
void createList(List *L);

/* Mengembalikan nilai true jika Queue kosong 
   Author : Fariz Muhamad Ibnu */
boolean isListEmpty(List L);

/* Menambahkan elemen pertama pada List dengan nilai X 
   Author : Yane Pradita */
void insertFirst(List *L, infoPenyakit X);

/* Menambahkan elemen terakhir pada List dengan nilai X 
   Author : Yane Pradita */
void insertLast(List *L, infoPenyakit X);

/* Menghapus elemen pertama pada List 
   Author : Fariz Muhamad Ibnu */
void delFirst(List *L, infoPenyakit *X);

/* Menghapus elemen terakhir pada List 
   Author : Fariz Muhamad Ibnu */
void delLast(List *L, infoPenyakit *X);

/* Menampilkan isi elemen yang ada pada List 
   Author : Fariz Muhamad Ibnu */
void printList(List L, char **namaPenyakit);

#endif
