// veridosyaodevi.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main()
{
	int i,j,k=0;
	FILE *dosya;
	char veri[20][20];
	FILE *dosya2;
	dosya = fopen("veriler.txt", "w");
	

	for (i = 0; i < 20; i++) {
		
			printf("Dosyaya kaydedilcek ismi girin(CIKIS ICIN '0' GIRINIZ):");
			scanf("%s", &veri[i]);
			if (strcmp(veri[i], "0") == 0) {
				printf("Veriler veriler.txt Dosyasina Tasindi\nVerilerin Tersine Cevrilmis Hali tersinesirala.txt Dosyasina Tasindi.\n");
				printf("Uygulama Sonlandirildi.\n"); break;
			}
			fputs(veri[i], dosya);
			fputs("\n", dosya);
		
	}
	if ((dosya = fopen("veriler.txt", "w")) != NULL) {

		dosya2 = fopen("tersinesirala.txt", "w");

		for (j = i-1; j >= 0; j--) {
			if (veri[j] != NULL) {
				fputs(veri[j], dosya2);
				fputs("\n", dosya2);
			}
			else continue;
		}
		fclose(dosya2);
	}
	else printf("veriler.txt Dosyasi bulunamadi.\n");

	fclose(dosya);
	

	system("pause"); 
    return 0; 
}


