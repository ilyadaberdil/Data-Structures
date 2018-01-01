// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int matris[4][4] = { 0,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0 };

void matrisyazdir(int matris[][4]) {
	int i, j;
	printf("   A    B    C    D\n");

	for (i = 0; i < 4; i++) {
		if (i == 0)
			printf("A  ");
		else if (i == 1)
			printf("B  ");
		else if (i == 2)
			printf("C  ");
		else if (i == 3)
			printf("D  ");
		for (j = 0; j < 4; j++) {
			printf("%d    ", matris[i][j]);
		} printf("\n");
	}printf("\n");
}

char yaz(int yol) {
	if (yol == 1)
		return 'A';
	if (yol == 2)
		return 'B';
	if (yol == 3)
		return 'C';
	if (yol == 4)
		return 'D';
}

void yolbul(int ana, int hedef, int matris[][4]) {
	int i, j, k;
	for (i = 0; i < 4; i++) {
		if (matris[ana - 1][i] == 1) {
			if (i + 1 == hedef) {
				if (ana != hedef)
					printf("%c - %c\n", yaz(ana), yaz(hedef));
				else continue;
			}
			for (j = 0; j < 4; j++) {
				if (matris[i][j] == 1) {
					if (j + 1 == hedef) {
						if (ana != hedef && ana != i + 1 && i + 1 != hedef)
							printf("%c - %c - %c\n", yaz(ana), yaz(i + 1), yaz(hedef));
						else continue;
					}
					for (k = 0; k < 4; k++) {
						if (matris[j][k] == 1) {
							if (k + 1 == hedef) {
								if (ana != hedef  && ana != i + 1 && ana != j + 1 && hedef != i + 1 && hedef != j + 1 && j + 1 != i + 1)
									printf("%c - %c - %c - %c\n", yaz(ana), yaz(i + 1), yaz(j + 1), yaz(hedef));
								else continue;
							}
						}
					}
				}
			}
		}
	}

}

int main()
{
	int anadugum, hedefdugum;

	matrisyazdir(matris);
	printf("A icin ->1\nB icin ->2\nC icin ->3\nD icin ->4\n");
	printf("Dugum girmek icin Dugume ait rakami giriniz.\n(hedef dugumu C olarak girmek icin ornek olarak..\n(hedef dugumu girin:3) seklinde giris yapiniz) \n");
	printf("Ana dugumu girin:");
	scanf("%d", &anadugum);
	while (anadugum > 4 || anadugum <= 0) {
		printf("Ana dugum uygun sekilde girilmedi.\nLutfen 1(A)-2(B)-3(C)-4(D) rakamlarindan birini giriniz\n");
		printf("Ana dugumu girin:");
		scanf("%d", &anadugum);
	}

	printf("Hedef dugumu girin:");
	scanf("%d", &hedefdugum);

	while (hedefdugum > 4 || hedefdugum <= 0) {
		printf("Hedef dugum uygun sekilde girilmedi.\nLutfen 1(A)-2(B)-3(C)-4(D) rakamlarindan birini giriniz\n");
		printf("Hedef dugumu girin:");
		scanf("%d", &hedefdugum);
	}

	printf("___________\n\n");
	printf("%c ile % c arasindaki yollar : \n", yaz(anadugum), yaz(hedefdugum));
	yolbul(anadugum, hedefdugum, matris);








	system("pause");
	return 0;
}
