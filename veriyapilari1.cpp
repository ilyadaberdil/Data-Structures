// #include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10

struct yigit
{
	int elemanlar[N];

}p;



void ekle() {
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &p.elemanlar[i]);
		if (p.elemanlar[i] == 0)
		{
			printf("Cikis komutu girildi veri alimi durduruldu..\n");
			break; // 0 girilse de listeleme yapsýn diye exit(1); komutunu kullanmadým.
		}
		else continue;
	}
	if (i == 10) printf("Stack Dolu\n");
}
void listele() {
	int i;
	for (i = 9; i >= 0; i--) {
		printf("%d",p.elemanlar[i]);
		printf("\n");
	}
}
int main()
{
	printf("Yigit 10 elemanlidir. \n");
	printf("Cikis icin \"0\" giriniz..\nSayilari giriniz..\n");
	ekle();
	printf("\nListele.execute\n\n");
	listele();
	system("PAUSE");
	return 0;
}
