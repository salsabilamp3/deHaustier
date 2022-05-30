#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printLogo();

int main(int argc, char *argv[]) {
	Queue Q;
	createQueue(&Q);
	
	char pilihanMenu;
	int panjang;
	char nama;
	char empty = ' ';
	
	do{
		printLogo();
		/** M E N U   R E G I S T R A S I **/
		printf("\n%10.c%c",empty,186);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c",186);                                                                                           
		printf("\n%10.c%c%40.c1. Registrasi     ",empty,186,empty);printf("%42.c%c\n",empty,186);
		printf("%10.c%c%40.c2. Proses Antrian ",empty,186,empty);printf("%42.c%c\n",empty,186);
		printf("%10.c%c%40.c3. List Antrian   ",empty,186,empty);printf("%42.c%c\n",empty,186);
		printf("%10.c%c%40.c4. Tentang        ",empty,186,empty);printf("%42.c%c\n",empty,186);
		printf("%10.c%c%40.c5. Keluar         ",empty,186,empty);printf("%42.c%c\n",empty,186);
		printf("%10.c%c",empty,186);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c\n",186);
	    printf("%10.c%c",empty,186);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c\n",186);                                                          
	    printf("%10.c%c",empty,200);for(panjang=0; panjang<100; panjang++){printf("%c",205);}printf("%c",188); 
		printf("\n%52.cPilih Menu: ",empty);
		scanf(" %c", &pilihanMenu);
		
		if(pilihanMenu == '1'){
			system("cls");
			printLogo();
			printf("\n%10.c%c%29.c __   ___  __     __  ___  __        __    ",empty,186,empty);printf("%28.c%c\n",empty,186);
			printf("%10.c%c%29.c|__) |__  / _` | /__`  |  |__)  /%c  /__` | ",empty,186,empty,92);printf("%28.c%c\n",empty,186);
			printf("%10.c%c%29.c|  %c |___ %c__> | .__/  |  |  %c /~~%c .__/ | ",empty,186,empty,92,92,92,92);printf("%28.c%c\n",empty,186);
		    printf("%10.c%c",empty,186);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c\n",186);                                                          
		    printf("%10.c%c",empty,200);for(panjang=0; panjang<100; panjang++){printf("%c",205);}printf("%c\n",188); 
			registrasi(&Q);
			system("pause");
		}
		
		if(pilihanMenu == '2'){
			system("cls");
			printLogo();
			printf("\n%10.c%c%19.c __   __   __   __   ___  __               ___  __             ",empty,186,empty);printf("%18.c%c\n",empty,186);
			printf("%10.c%c%19.c|__) |__) /  %c /__` |__  /__`     /%c  |%c |  |  |__) |  /%c  |%c |",empty,186,empty,92,92,92,92,92);printf("%18.c%c\n",empty,186);
			printf("%10.c%c%19.c|    |  %c %c__/ .__/ |___ .__/    /~~%c | %c|  |  |  %c | /~~%c | %c|",empty,186,empty,92,92,92,92,92,92,92);printf("%18.c%c\n",empty,186);
			printf("%10.c%c",empty,186);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c\n",186);                                                          
		    printf("%10.c%c",empty,200);for(panjang=0; panjang<100; panjang++){printf("%c",205);}printf("%c\n",188); 
			prosesAntrian(&Q);
			system("pause");
		}
		
		if(pilihanMenu == '3'){
			system("cls");
			printLogo();
			printf("\n%10.c%c%25.c        __  ___              ___  __              ",empty,186,empty);printf("%25.c%c\n",empty,186);
			printf("%10.c%c%25.c|    | /__`  |      /%c  |%c |  |  |__) |  /%c  |%c | ",empty,186,empty,92,92,92,92);printf("%25.c%c\n",empty,186);
			printf("%10.c%c%25.c|___ | .__/  |     /~~%c | %c|  |  |  %c | /~~%c | %c| ",empty,186,empty,92,92,92,92,92);printf("%25.c%c\n",empty,186);
            printf("%10.c%c",empty,186);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c\n",186);                                                          
		    printf("%10.c%c",empty,200);for(panjang=0; panjang<100; panjang++){printf("%c",205);}printf("%c\n",188);                                      
			printQueue(Q);
			system("pause");
		}
		
		if(pilihanMenu == '4'){
			system("cls");
			printLogo();
			printf("\n%10.c%c%34.c___  ___      ___            __  ",empty,186,empty);printf("%33.c%c\n",empty,186);
			printf("%10.c%c%34.c |  |__  |%c |  |   /%c  |%c | / _` ",empty,186,empty,92,92,92);printf("%33.c%c\n",empty,186);
			printf("%10.c%c%34.c |  |___ | %c|  |  /~~%c | %c| %c__> ",empty,186,empty,92,92,92,92);printf("%33.c%c\n",empty,186);
            printf("%10.c%c",empty,186);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c\n",186);                                                          
		    printf("%10.c%c",empty,204);for(panjang=0; panjang<100; panjang++){printf("%c",205);}printf("%c\n",185);
		    printf("%10.c%c",empty,186);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c\n",186); 
		    printf("%10.c%c%5.cAplikasi layanan dokter hewan ini dirancang dan dibuat oleh Kelompok 8 yang",empty,186,empty);printf("%20.c%c\n",empty,186); 
		    printf("%10.c%c%5.cberanggotakan:",empty,186,empty);printf("%81.c%c\n",empty,186); 
		    printf("%10.c%c",empty,186);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c\n",186); 
		    printf("%10.c%c%27.cSalsabila Maharani Putri (211524026) (Leader)",empty,186,empty);printf("%28.c%c\n",empty,186); 
		    printf("%10.c%c%27.cFariz Muhamad Ibnu Hisyam (211524010)",empty,186,empty);printf("%36.c%c\n",empty,186); 
		    printf("%10.c%c%27.cYane Pradita (211524029)",empty,186,empty);printf("%49.c%c\n",empty,186); 
		    printf("%10.c%c",empty,186);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c\n",186); 
		    printf("%10.c%c%5.cdeHaustier merupakan program untuk memproses antrian layanan dokter hewan, yang dibuat",empty,186,empty);printf("%9.c%c\n",empty,186); 
			printf("%10.c%c%5.cdengan bahasa C. Antrian pada program ini menggunakan priority queue dengan impelementasi",empty,186,empty);printf("%6.c%c\n",empty,186); 
			printf("%10.c%c%5.cmenggunakan linked list. Sehingga antrian akan berubah urutannya berdasarkan nilai prioritas.",empty,186,empty);printf("%2.c%c\n",empty,186); 
			printf("%10.c%c",empty,186);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c\n",186); 
		    printf("%10.c%c",empty,200);for(panjang=0; panjang<100; panjang++){printf("%c",205);}printf("%c\n",188);
			system("pause");
		}
	} while(pilihanMenu != '5');
	
	return 0;
}
void printLogo(){                                                                                           
	int panjang;
	char empty = ' ';
	
	/** M E N U   U T A M A **/
	system("cls");
	printf("%10.c%c",empty,201);for(panjang=0; panjang<100; panjang++){printf("%c",205);}printf("%c",187);
	printf("\n%10.c%c%3.c                                      __   __       ___  ___  __           ___                ",empty,186,empty);printf("%3.c%c\n",empty,186);
	printf("%10.c%c%3.c|     /%c  %c /  /%c  |%c |  /%c  |%c |    |  %c /  %c |__/  |  |__  |__)    |__| |__  |  |  /%c  |%c | ",empty,186,empty,92,92,92,92,92,92,92,92,92,92);printf("%3.c%c\n",empty,186);
	printf("%10.c%c%3.c|___ /~~%c  |  /~~%c | %c| /~~%c | %c|    |__/ %c__/ |  %c  |  |___ |  %c    |  | |___ |/%c| /~~%c | %c| ",empty,186,empty,92,92,92,92,92,92,92,92,92,92,92);printf("%3.c%c\n",empty,186);
    printf("%10.c%c",empty,186);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c\n",186);
    printf("%10.c%c",empty,204);for(panjang=0; panjang<100; panjang++){printf("%c",205);}printf("%c",185);
	printf("\n%10.c%c",empty,186);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c",186);  
	printf("\n%10.c%c%3.c$$$$$$$%c            $$%c   $$%c                                 $$%c     $$%c                     ",empty,186,empty,92,92,92,92,92);printf("%3.c%c\n",empty,186);
	printf("%10.c%c%3.c$$  __$$%c           $$ |  $$ |                                $$ |    %c__|                    ",empty,186,empty,92,92);printf("%3.c%c\n",empty,186);
	printf("%10.c%c%3.c$$ |  $$ | $$$$$$%c  $$ |  $$ | $$$$$$%c  $$%c   $$%c  $$$$$$$%c $$$$$$%c   $$%c  $$$$$$%c   $$$$$$%c  ",empty,186,empty,92,92,92,92,92,92,92,92,92);printf("%3.c%c\n",empty,186);
	printf("%10.c%c%3.c$$ |  $$ |$$  __$$%c $$$$$$$$ | %c____$$%c $$ |  $$ |$$  _____|%c_$$  _|  $$ |$$  __$$%c $$  __$$%c ",empty,186,empty,92,92,92,92,92,92);printf("%3.c%c\n",empty,186);
	printf("%10.c%c%3.c$$ |  $$ |$$$$$$$$ |$$  __$$ | $$$$$$$ |$$ |  $$ |%c$$$$$$%c    $$ |    $$ |$$$$$$$$ |$$ |  %c__|",empty,186,empty,92,92,92);printf("%3.c%c\n",empty,186);
	printf("%10.c%c%3.c$$ |  $$ |$$   ____|$$ |  $$ |$$  __$$ |$$ |  $$ | %c____$$%c   $$ |$$%c $$ |$$   ____|$$ |      ",empty,186,empty,92,92,92);printf("%3.c%c\n",empty,186);
	printf("%10.c%c%3.c$$$$$$$  |%c$$$$$$$%c $$ |  $$ |%c$$$$$$$ |%c$$$$$$  |$$$$$$$  |  %c$$$$  |$$ |%c$$$$$$$%c $$ |  ",empty,186,empty,92,92,92,92,92,92,92);printf("%7.c%c\n",empty,186);
	printf("%10.c%c%3.c%c_______/  %c_______|%c__|  %c__| %c_______| %c______/ %c_______/    %c____/ %c__| %c_______|%c__|      ",empty,186,empty,92,92,92,92,92,92,92,92,92,92,92);printf("%3.c%c\n",empty,186);	 
	printf("%10.c%c",empty,186);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c\n",186);
    printf("%10.c%c",empty,204);for(panjang=0; panjang<100; panjang++){printf("%c",205);}printf("%c",185);
}
