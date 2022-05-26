#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void mainMenu(){
	system("cls");
	printf("\n\n==== Layanan Dokter Hewan ====");
    printf("\n1. Registrasi");
    printf("\n2. Proses");
    printf("\n3. Lihat antrian");
    printf("\n4. Quit");
}

int main(int argc, char *argv[]) {
	Queue Q;
	createQueue(&Q);
	
	char pilihanMenu;
	
	do{
		mainMenu();
		printf("Menu Pilihan(1-4): ");
		scanf(" %c", &pilihanMenu);
		
		if(pilihanMenu == '1'){
			registrasi(&Q);
			system("pause");
		}
		
		if(pilihanMenu == '2'){
			prosesAntrian(&Q);
			system("pause");
		}
		
		if(pilihanMenu == '3'){
			printQueue(Q);
			system("pause");
		}
	} while(pilihanMenu != '4');
	
	return 0;
}
