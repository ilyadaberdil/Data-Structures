
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 30

struct queue {
	int ar[MAX];
	int on, arka;
}p;


void ekle(struct queue *p, int x) {
	if (p->arka == MAX - 1) {
		p->arka = 0;
	}

	else
		p->arka++;
	p->ar[p->arka] = x;
	return;
}

int cikar(struct queue *p) {
	if (p->on == p->arka == MAX - 1) {
		printf("Kuyruk Bos");
		exit(1);
	}
	if (p->on == MAX - 1)
		p->on = 0;
	else p->on++;
	return p->ar[p->on];

}

void insertionsort(int dizi[]) {
	int yedek, i, j;
	for (i = 1; i < MAX; i++) {
		for (j = i; j > 0; j--) {
			if (dizi[j] < dizi[j - 1]) {
				yedek = dizi[j];
				dizi[j] = dizi[j - 1];
				dizi[j - 1] = yedek;
			}
			else break;
		}
	}
}

int main()
{
	int i, dizi[MAX];
	p.arka = MAX - 1;
	p.on = MAX - 1;

	printf("30 elemanli Kuyruk dolduruluyor.\n");
	printf("Kuyruk Elemanlari :\n");

	srand(time(NULL));

	for (i = 0; i < MAX; i++) {
		ekle(&p, rand() % 100 + 1);
	}
	for (i = 0; i < MAX; i++) {
		printf("%d\n", cikar(&p));
	}
	printf("___________________________________\n");

	printf("Kuyruk Diziye Aktarilip Insertion Sort ile siralama yapiliyor.\n");
	for (i = 0; i < MAX; i++) {
		dizi[i] = cikar(&p);
	}

	insertionsort(dizi);

	printf("Sirali Dizi Kuyruga aktariliyor..\nSirali kuyruk elemanlari:\n");

	for (i = 0; i < 30; i++) {
		ekle(&p, dizi[i]);
	}
	for (i = 0; i < 30; i++) {
		printf("%d\n", cikar(&p));
	}



	system("PAUSE");
	return 0;
}

