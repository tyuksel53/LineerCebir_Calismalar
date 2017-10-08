#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
author: tyuksel53
date:	8.10.2017
*/
double determinant(int MatrisBoyut, int subBoyut, int **matris, int SiLsatir, int SiLsutun,int sonuc,int katsayi,int mark) // alt matris bulan recusive fonksiyon
{
	int i, j;
	int **suBmatris = (int **)malloc(sizeof(int) * subBoyut - 1); // alt matrisi oluþtur
	int satir = 0;
	int sutun = 0;

	for (i = 0; i < subBoyut; i++) // alt matrisi tanýmla
	{
		suBmatris[i] = (int *)malloc(sizeof(int)* subBoyut - 1);
	}

	for (i = 0; i < MatrisBoyut; i++)
	{
		for (j = 0; j < MatrisBoyut; j++)
		{
			if (i != SiLsatir && j != SiLsutun) // satýr ve sutunu sil
			{
				suBmatris[satir][sutun] = matris[i][j];
				sutun++;
			}
		}
		if (sutun == subBoyut)
		{
			sutun = 0;
			satir++;
		}
	}

	if (subBoyut == 2)
	{
		int tmp = ((katsayi*mark) * determinantHesapla(suBmatris));
		sonuc = sonuc +  tmp;
		return sonuc;
	}

	if (subBoyut != 2) // 2x2 matris oluncaya kadar ilerle
	{
		int localMark = 1;
		for (i = 0; i < subBoyut; i++)
		{
			for (j = 0; j < subBoyut; j++)
			{
				int zundi = suBmatris[i][j];
				sonuc = determinant(subBoyut, subBoyut - 1, suBmatris, i, j,sonuc,suBmatris[i][j], localMark);
				localMark = localMark * -1;
			}
			break;
		}
	}

	return sonuc * (katsayi*mark);
	
}
void determinantBul(int boyut, int **matris)
{
	int sonuc = 0;
	int i, j;
	int satir, sutun;
	for (i = 0; i < boyut; i++)
	{
		for (j = 0; j < boyut; j++)
		{
			printf("%d ", matris[i][j]);

		}
		printf("\n");
	}
	int mark = 1;
	for (i = 0; i < boyut; i++)
	{
		for (j = 0; j < boyut; j++)
		{
			sonuc = sonuc + determinant(boyut, boyut - 1, matris, i, j,0,matris[i][j],mark);
			mark = mark  * (-1);
		}
		break;
	}
	printf("Determinant Hesabý: %d\n", sonuc);
}
int determinantHesapla(int **matris)
{
	
	return ( matris[0][0] * matris[1][1] ) - (matris[1][0] * matris[0][1]);
}