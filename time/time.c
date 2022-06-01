/*
	DeHaustier
	Program: time.h
	Deskripsi: implementasi body dari time.h
*/

#include "time.h"

/* Membentuk sebuah Time dari HH sebagai jam dan MM sebagai menit */
void createTime(time *waktu, int HH, int MM){
	(*waktu).hour = HH;
	(*waktu).minute =MM;
}

/* Mereset atau mengatur ulang waktu menjadi 00:00 */
void resetTime(time *waktu){
	(*waktu).hour = 0;
	(*waktu).minute = 0;
}

/* ====== Getter Setter ====== */
/* Mengirimkan nilai hour */
int getHour(time waktu){
	return waktu.hour;
}

/* Merubah nilai hour dengan HH */
void setHour(time *waktu, int HH){
	(*waktu).hour = HH;
}

/* Mengirimkan nilai menit */
int getMinute(time waktu){
	return waktu.minute;
}

/* Merubah nilai minute dengan HH */
void setMinute(time *waktu, int MM){
	(*waktu).minute = MM;
}

/* ====== Input Output ====== */
/* Membaca input dari keyboard user hingga membentu time */
void readTime(time *waktu){
	time waktuBaru;
	
	scanf("%d %d", &waktuBaru.hour, &waktuBaru.minute);
	
	(*waktu) = waktuBaru;
}

/* Menampilkan time yang terbentuk ke layar */
void printTime(time waktu){
	if(waktu.minute < 10){
		printf("%d:0%d", waktu.hour, waktu.minute);
	}
	else{
		printf("%d:%d", waktu.hour, waktu.minute);
	}
	
}

/* ====== Validasi & Relational ====== */
/* Mengirimkan true jika time yang terbentuk valid dengan rentang tertentu */
boolean isTimeValid(time waktu){
	return (((waktu.hour >= 0) && (waktu.hour < 24)) && ((waktu.minute >= 0) && (waktu.minute < 60)));
}

/* Mengembalikan nilai true jika start = end */
boolean isEqual(time start, time end){
	return ((start.hour == end.hour) && (start.minute == end.minute));
}

/* Mengembalikan nilai true jika start < end */
boolean isLessThan(time start, time end){
	if(!isEqual(start, end)){
		if(start.hour < end.hour){
			return true;
		}
		else if(start.hour > end.hour){
			return false;
		}
		else{
			if(start.minute < end.minute){
				return true;
			}
			else{
				return false;
			}
		}
	}
	else{
		return false;
	}
}

/* Mengembalikan nilai true jika start > end */
boolean isGreatestThan(time start, time end){
	return (!isEqual(start, end) && !isLessThan(start, end));
}

/* Mengembalikan nilai true jika waktu belum dimulai atau masih 00:00 */
boolean isNotStarted(time waktu){
	return (waktu.hour == 0 && waktu.minute == 0);
}

/* ====== Operasi Lain ====== */
/* Mengirimkan hasil pengurangan time */
time substractTime(time start, time end){
	time result;
	
	while(end.minute > start.minute){
		--start.hour;
		start.minute += 60;
	}
	
	result.minute = start.minute - end.minute;
	result.hour = start.hour - end.hour;
	
	if(result.hour < 0){
		setHour(&result, 0);
		setMinute(&result, 0);
	}
	
	return result;
}

/* Mengirimkan hasil pertambahan 2 time berbeda */
time addTime(time start, time end){
	time result;
	
	result.hour = start.hour + end.hour;
	result.minute = start.minute - start.minute;
	
	if(start.minute > 59){
		result.hour++;
		result.minute -= 60;
	}
	
	return result;
}

/* Mengirimkan hasil pertambahan time dengan menit */
time addMinute(time start, int MM){
	time result;
	
	result.hour = start.hour;
	result.minute = start.minute + MM;
	
	while(result.minute > 59){
		result.hour++;
		result.minute -= 60;
	}
	
	return result;
}

/* Mengirimkan nilai hasil perubahan jam ke menit */
int hourToMinute(time waktu){
	return ((waktu.hour * 60) + waktu.minute);
}
