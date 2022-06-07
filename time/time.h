/*
	DeHaustier
	Program: time.h
	Deskripsi: File header ADT time
	Author : Salsabila Maharani Putri 
*/

#ifndef time_H
#define time_H

#include <stdlib.h>
#include <stdio.h>
#include "..\boolean.h"

typedef struct{
	int hour;
	int minute;
} time; 

/* Membentuk sebuah Time dari HH sebagai jam dan MM sebagai menit */
void createTime(time *waktu, int HH, int MM);

/* Mereset atau mengatur ulang waktu menjadi 00:00 */
void resetTime(time *waktu);

/* ====== Getter Setter ====== */
/* Mengirimkan nilai hour */
int getHour(time waktu);

/* Merubah nilai hour dengan HH */
void setHour(time *waktu, int HH);

/* Mengirimkan nilai menit */
int getMinute(time waktu);

/* Merubah nilai minute dengan HH */
void setMinute(time *waktu, int MM);

/* ====== Input Output ====== */
/* Membaca input dari keyboard user hingga membentu time */
void readTime(time *waktu);

/* Menampilkan time yang terbentuk ke layar */
void printTime(time waktu);

/* ====== Validasi & Relational ====== */
/* Mengirimkan true jika time yang terbentuk valid dengan rentang tertentu */
boolean isTimeValid(time waktu);

/* Mengembalikan nilai true jika start = end */
boolean isEqual(time start, time end);

/* Mengembalikan nilai true jika start < end */
boolean isLessThan(time start, time end);

/* Mengembalikan nilai true jika start > end */
boolean isGreatestThan(time start, time end);

/* Mengembalikan nilai true jika waktu belum dimulai atau masih 00:00 */
boolean isNotStarted(time waktu);

/* ====== Operasi Lain ====== */
/* Mengirimkan hasil pengurangan time */
time substractTime(time start, time end);

/* Mengirimkan hasil pertambahan 2 time berbeda */
time addTime(time start, time end);

/* Mengirimkan hasil pertambahan time dengan menit */
time addMinute(time start, int MM);

/* Mengirimkan nilai hasil perubahan jam ke menit */
int hourToMinute(time waktu);

#endif
