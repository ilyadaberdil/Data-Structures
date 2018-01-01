// 1358130094.cpp : Defines the entry point for the console application.
//
// #include "stdafx.h" 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 10

struct yigin {
	int top ;
	int elemanyigin[N];
}p;

struct queue {
	int bas;
	int son;
	int elemanqueue[N];
}q;

void elemanekle(struct yigin *p,int x) {
	if (p->top == N - 1) {
		printf("Stack dolu");
	}
	p->top++;
	p->elemanyigin[p->top]=x;
}

void elemanaktar(struct yigin *p, struct queue *q) {
	for (int i =p->top; i >= 0; i--) {
		if (q->son == N - 1) break;
		q->son++;
		q->elemanqueue[q->son] = p->elemanyigin[p->top];	
		p->top--;
	}
}

void listele(struct queue *q) {
	
	for (q->bas = 0; q->bas <= q->son; q->bas++ ) {
		printf("%d\n", q->elemanqueue[q->bas]);
	}
}

int main()
{
	int a[N];
	q.bas = q.son = -1;
	p.top = -1;
	printf("Yigin 10 elemanlidir.\n");
	printf("Elemanlari Giriniz..\nCikis icin \"0\" Giriniz..\n");
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0) {
			printf("Cikis Elemani girildi.\n"); 
			break;
		}	
		elemanekle(&p, a[i]);
	}
	printf("Elemanlar yigin yapisindan kuyruk yapisina aktariliyor.\n");
	elemanaktar(&p, &q);
	printf("Kuyruk yapisina aktarilan elemanlar listeleniyor.. \n");
	listele(&q);
	system("Pause");
    return 0;
}

