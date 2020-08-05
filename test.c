#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define SIZE 128

char pengeluaran[SIZE], fname[] = "D:\data.txt", temp[] = "D:\data2.txt";

void cls() {
	system("cls");
}

void menu(){
char b;
	back :
		b = _getch();
		if (b == 'Y') {add_saldo();}
		else if (b == 'N') {main();}
		else {goto back;}
}

void menu2(){
char b;
	back :
		b = _getch();
		if (b == 'Y') {dua();}
		else if (b == 'N') {main();}
		else {goto back;}
}

int main(){
	cls();
	int pil;
	printf("\t |--------------------------------------------------------------------------------------|\n");
    printf("\t |\t\t\t\t\tPENGELUARAN\t\t\t\t\t|\n");
    printf("\t |--------------------------------------------------------------------------------------|\n");
    printf("\t |\t\t\t\t1. Detail Pengeluaran\t\t\t\t\t|\n");
	printf("\t |\t\t\t\t2. Tambah Pengeluaran\t\t\t\t\t|\n");
	printf("\t |\t\t\t\t3. Delete Pengeluaran \t\t\t\t\t|\n");
	printf("\t |\t\t\t\t4. EXIT\t\t\t\t\t\t\t|\n");
	printf("\t |--------------------------------------------------------------------------------------|\n");
	printf("\t \t\t\t\tMasukan pilihan : "); scanf("%d", &pil);
	printf("\t\t\t\t|\n");
	switch (pil) {
		case 1 : satu();break;
		case 2 : dua();break;
		case 3 : tiga();break;
		case 4 : exit(0);break;
		default : 
			printf ("\n\a\tPILIHAN YANG ANDA MASUKAN TIDAK TERSEDIA, SILAHKAN MASUKAN PILIHAN LAGI");
			Sleep (1000);
			return main();
	}
	return 0;
}

int satu(){
	cls();
	fflush(stdin);
	FILE *fptr1 = fopen(fname, "r");
		if (fptr1 == NULL){
			fclose(fptr1);
			add_saldo();
		}else{
			printf("\t |--------------------------------------------------------------------------------------|\n");
			printf("\t |\t\t\t\t\tData Pengeluaran\t\t\t\t|\n");
			printf("\t |--------------------------------------------------------------------------------------|\n");
			fclose(fptr1);
			view();
			printf("\n\t |--------------------------------------------------------------------------------------|\n");	
			printf("\n\t \t\t\tIngin Menambahakan Data Pengeluaran?(Y/N) :");
			menu2();
			printf("\t\t\t|\n");
		}
	return 0;
}

int view(){
	FILE *fptr1 = fopen(fname, "r");
	while (fgets(pengeluaran, sizeof(pengeluaran), fptr1)) {
		printf("\t  %s", pengeluaran);
	}
	fclose(fptr1);
}

int add_saldo(){
	cls();
	printf("\t |--------------------------------------------------------------------------------------|\n");
	printf("\t |\t\t\t\t\tFILE TIDAK ADA!\t\t\t\t\t|\n");
	printf("\t \t\t\t\tTambahkan Data Pengeluaran (Y/N) :");
	char b;
	back :
		b = _getch();
		if (b == 'Y') {
			cls();
			int pemasukan;
			printf("\t |--------------------------------------------------------------------------------------|\n");
			printf("\t |\t\t\t\tMasukkan Total Pemasukan Bulan Ini :");scanf("%d", &pemasukan);
			FILE* fp=fopen(fname,"w+");
				fprintf(fp,"\t\tSisa pemasukan : %d\n",pemasukan);
				fprintf(fp,"\t\tTotal pemasukan : %d\n",pemasukan);
				fprintf(fp, "--------------------------------------------------------------------------------------\n");
				fprintf(fp,"|\tPengeluaran\t|\tTanggal\t|\tKegiatan\t|\n");
				fprintf(fp,"---------------------------------------------------------------\n");
			fclose(fp);
			printf("\n\t |--------------------------------------------------------------------------------------|\n");
			printf("\t\t\t\t\tIngin Menambahkan Pengeluaran? (Y/N) :");
			menu2();
			printf("\t\t\t|\n");
		}
		else if (b == 'N') {main();}
		else {goto back;}
	return 0;
}

int dua(){
	cls();
	FILE* VIEW = fopen(fname, "r");
	if (VIEW == NULL){
	    fclose(VIEW);
	    add_saldo();
	}else{
		int tgl, jum, sisa, lno =1, ctr = 1;
		char keg [SIZE], str1[10], str2[10], str3[10];
		
		printf("\t |--------------------------------------------------------------------------------------|\n");
		printf("\t |\t\t\t\t\tTambah Pengeluaran\t\t\t\t|\n");
		printf("\t |--------------------------------------------------------------------------------------|\n");
		
		fgets(pengeluaran, sizeof(pengeluaran), VIEW);
		printf("\t\t\t%s", pengeluaran);
		fgets(pengeluaran, sizeof(pengeluaran), VIEW);
		printf("\t\t\t%s", pengeluaran);
		fclose(VIEW);
		
    	printf("\n\t |--------------------------------------------------------------------------------------|\n");
    	printf("\t \t\t\t\tMasukkan Tanggal :");scanf("%d", &tgl);
    	printf("\t \t\t\t\tMasukkan Jumlah Pengeluaran :");scanf("%d", &jum);
    	fflush(stdin);
    	printf("\t \t\t\t\tKegunaan Pengeluan :");scanf("%[^\n]", &keg);
    	
    	FILE* VIEW = fopen(fname, "r");
	    	fscanf(VIEW, "%s %s %s %d", str1, str2, str3, &sisa);
	    	sisa = sisa - jum;
		fclose(VIEW);
		
    	FILE* fp=fopen(fname,"a");
    		fprintf(fp,"|\t%d\t|\t%d\t|\t%s\t|\n", jum, tgl, keg);
    	fclose(fp);
    	
    	FILE*fptr1 = fopen(fname, "r");
		FILE*fptr2 = fopen(temp, "w+");
			lno++;
			while (!feof(fptr1)) 
	        {
	            strcpy(pengeluaran, "\0");
	            fgets(pengeluaran, SIZE, fptr1);
	            if (!feof(fptr1)) 
	            {
	                ctr++;
	                if (ctr != lno) 
	                {
	                	fprintf(fptr2, "%s", pengeluaran);
	                }else if(ctr = lno) {
	                	fprintf(fptr2,"\t\tSisa pemasukan : %d\n",sisa);
					}
				}
	        }
	    fclose(fptr1);
	    fclose(fptr2);
	    remove(fname); 
		rename(temp, fname);
		printf ("\n\t\t\t\tDATA BERHASIL DIINPUT\n");
		Sleep (1000);
		printf("\t |--------------------------------------------------------------------------------------|\n");
		printf("\t\t\t\t\tIngin Menambahkan Pengeluaran? (Y/N) :");
		menu2();
	}
	return 0;
}

int tiga(){
	cls();
	int no;
	FILE* VIEW = fopen(fname, "r");
	if (VIEW == NULL){
	    fclose(VIEW);
	    add_saldo();
	}else{
		fclose(VIEW);
		printf("\t |--------------------------------------------------------------------------------------|\n");
		printf("\t |\t\t\t\t\tHapus Pengeluaran\t\t\t\t|\n");
		printf("\t |--------------------------------------------------------------------------------------|\n");
		view();
		printf("\t |--------------------------------------------------------------------------------------|\n");
		FILE*fptr1 = fopen(fname, "r");
			while (fgets(pengeluaran, sizeof(pengeluaran), fptr1)) {
				no++;
			}
		fclose(fptr1);
		if(no == 5){
			printf("\t |\t\t\t\t\tData Pengeluaran Kosong!\t\t\t\t\t|\n");
			printf("\t |--------------------------------------------------------------------------------------|\n");
			printf("\t\t\t\t\tIngin Menambahkan Pengeluaran? (Y/N) :");
			menu2();
		}else if(no == 6){
			del(no);
		}else{
			int no2;
			printf("\t\t\t\t\tPilih Baris yang Ingin Dihapus :");scanf("%d", &no2);
			no2 = no2+5;
			if(no2 > no){
				printf ("\n\a\tINPUT INVALID !!");
				Sleep (1000);
				return tiga();
			}else{
				del(no2);
			}	
		}
	}
	return 0;
}

int del(int no){
	
	FILE*fptr1 = fopen(fname, "r");
	int lno =0;
	//char sisa[10];
	printf("\t |\t\t\t\tData Yang Dipilih :\t\t\t\t\t|\n\n");
	while(lno != no){
		lno++;
		fgets(pengeluaran, sizeof(pengeluaran), fptr1);
	}
	printf("\t\t\t%s", pengeluaran);
	fclose(fptr1);
	
	FILE*fptr2 = fopen(fname, "r");
	lno =0;
	while(lno != no-1){
		lno++;
		fgets(pengeluaran, sizeof(pengeluaran), fptr2);
	}
	char s[SIZE], str1[10], str2[10], str3[10];
	int s2, sisa;
	fscanf(fptr2, "%s %d", s, &s2);
	fclose(fptr2);
	
	FILE* VIEW = fopen(fname, "r");
	    	fscanf(VIEW, "%s %s %s %d", str1, str2, str3, &sisa);
	    	sisa = sisa + s2;
	fclose(VIEW);
	
	printf("%d",sisa);

	printf("\t |--------------------------------------------------------------------------------------|\n");
	printf("\n\t\t\t\t\tHapus Data Pengeluaran Ini? (Y/N) :");
	lno =0;
	char b;
	back :
		b = _getch();
		if (b == 'Y') {
			int ctr =0;
			FILE*fptr1 = fopen(fname, "r");
			FILE*fptr2 = fopen(temp, "w+");
				lno++;
				while (!feof(fptr1)) 
		        {
		            strcpy(pengeluaran, "\0");
		            fgets(pengeluaran, SIZE, fptr1);
		            if (!feof(fptr1)) 
		            {
		                ctr++;
		                if(ctr == 1) {
		                	fprintf(fptr2,"\t\tSisa pemasukan : %d\n",sisa);
						}else if (ctr != no){
		                	fprintf(fptr2, "%s", pengeluaran);
		                }
					}
		        }
		    fclose(fptr1);
		    fclose(fptr2);
		    remove(fname); 
			rename(temp, fname);
		}
		else if (b == 'N') {main();}
		else {goto back;}
	printf ("\n\t\t\t\tDATA BERHASIL DIHAPUS\n");
	Sleep (1000);
	cls();
	printf("\n\t\t\t\t\tIngin Menghapus Data Lagi? (Y/N) :");
	back2 :
		b = _getch();
		if (b == 'Y') {tiga();}
		else if (b == 'N') {main();}
		else {goto back;}
	return 0;
}
