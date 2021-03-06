/*
	DeHaustier
	Program: list.h
	Deskripsi: implementasi body dari list.h
*/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/* ==== Konstruktor ==== */
/* Mengirimkan address hasil alokasi elemen dengan info X 
   Author : Fariz Muhamad Ibnu */
adrList alokList(infoPenyakit X){
	adrList P;
	P = (ElmList *)malloc(sizeof(ElmList));
	if(P != Nil){
		InfoL(P) = X;
		NextL(P) = Nil;
	}
	
	return P;
}

/* Melakukan dealokasi memori dari elmen P 
   Author : Yane Pradita */
void dealokList(adrList P){
	NextL(P) = Nil;
	free(P);
}

/* Membuat List kosong dengan First = Nil 
   Author : Yane Pradita */
void createList(List *L){
	First(*L) = Nil;
}

/* Mengembalikan nilai true jika Queue kosong 
   Author : Fariz Muhamad Ibnu */
boolean isListEmpty(List L){
	return(First(L) == Nil);
}

/* Menambahkan elemen pertama pada List dengan nilai X 
   Author : Yane Pradita */
void insertFirst(List *L, infoPenyakit X){
	adrList P = alokList(X);
	if(P != Nil){
		NextL(P) = First(*L);
		First(*L) = P;
	}
}

/* Menambahkan elemen terakhir pada List dengan nilai X 
   Author : Yane Pradita */
void insertLast(List *L, infoPenyakit X){
	adrList P = alokList(X);
	adrList Last;
	if(P != Nil){
		if(isListEmpty((*L))){
			insertFirst(&(*L), X);
		}
		else{
			Last = First(*L);
			while(NextL(Last) != Nil){
				Last = NextL(Last);
			}
			NextL(Last) = P;
		}
	}
}

/* Menghapus elemen pertama pada List 
   Author : Fariz Muhamad Ibnu */
void delFirst(List *L, infoPenyakit *X){
	adrList P;
	P  = First(*L);
	if(NextL(First(*L)) == Nil){
		createList(L);
	}
	else{
		First(*L) = NextL(First(*L));
	}
	dealokList(P);
}

/* Menghapus elemen terakhir pada List 
   Author : Fariz Muhamad Ibnu */
void delLast(List *L, infoPenyakit *X){
	adrList P, Last, newLast;
	
	Last = First(*L);
	if(NextL(Last) == Nil){
		delFirst(&(*L), &(*X));
	}
	else{
		while(NextL(Last) != Nil){
			newLast = Last;
			Last = NextL(Last);
		}
		P = Last;
		NextL(newLast) = Nil;
	}
	
	dealokList(P);
}

/* Menampilkan isi elemen yang ada pada List 
   Author : Fariz Muhamad Ibnu */
void printList(List L, char **namaPenyakit){
	adrList P = First(L);
	int i = 1;
	char empty = ' ';
	
	if(isListEmpty(L)){
		printf("List Kosong.\n");
	}
	else{
		do{
			printf("%d) %s : %s (%d menit)\n", i, namaPenyakit[InfoL(P).penyakit -1], InfoL(P).kategori, InfoL(P).waktuEstimasi);
			printf("%70.c", empty);
			P = NextL(P);
			i += 1;
		} while(P != Nil);
	}
}
