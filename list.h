/*
	DeHaustier
	Program: list.h
	Deskripsi: File header ADT List untuk list penyakit
*/

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <conio.h>
#include "boolean.h"

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
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
/* Mengirimkan address hasil alokasi elemen dengan info X */
address alokList(infoPenyakit X);

/* Melakukan dealokasi memori dari elmen P */
void dealokList(address P);

/* Membuat List kosong dengan First = Nil */
void createList(List *L);

/* Mengembalikan nilai true jika Queue kosong */
boolean isListEmpty(List L);

/* Menambahkan elemen pertama pada List dengan nilai X */
void insertFirst(List *L, infoPenyakit X);

/* Menambahkan elemen terakhir pada List dengan nilai X */
void insertLast(List *L, infoPenyakit X);

/* Menghapus elemen pertama pada List */
void delFirst(List *L, infotype *X);

/* Menghapus elemen terakhir pada List */
void delLast(List *L, infotype *X);

/* Menampilkan isi elemen yang ada pada List */
void printList(List L, char **namaPenyakit);

#endif
