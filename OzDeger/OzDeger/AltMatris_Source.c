#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
	author: tyuksel53
	date:	8.10.2017
*/
void file_write(int boyut, int **matris)
{
	char str[200] = "C:\\users\\taha\\desktop\\"; // dosya yolu
	char snum[12];
	sprintf(snum, "%d", boyut); // boyuta g�re ayr� dosyaya yaz
	strcat(str, snum);
	strcat(str, "submatrix.txt");

	FILE *fp; // dosya a�
	fp = fopen(str, "a");

	int i, j;
	for (i = 0; i < boyut; i++)
	{
		for (j = 0; j < boyut; j++)
		{
			fprintf(fp, "%d ", matris[i][j]);

		}
		fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
	fclose(fp); // dosya kapa
}
void alt_matris(int MatrisBoyut, int subBoyut, int **matris, int SiLsatir, int SiLsutun) // alt matris bulan recusive fonksiyon
{
	int i, j;
	int **suBmatris = (int **)malloc(sizeof(int) * subBoyut - 1); // alt matrisi olu�tur
	int satir = 0;
	int sutun = 0;

	for (i = 0; i < subBoyut; i++) // alt matrisi tan�mla
	{
		suBmatris[i] = (int *)malloc(sizeof(int)* subBoyut - 1);
	}

	for (i = 0; i < MatrisBoyut; i++)
	{
		for (j = 0; j < MatrisBoyut; j++)
		{
			if (i != SiLsatir && j != SiLsutun) // sat�r ve sutunu sil
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

	file_write(subBoyut, suBmatris); // dosyaya yaz

	if (subBoyut != 2) // 2x2 matris oluncaya kadar ilerle
	{
		for (i = 0; i < subBoyut; i++)
		{
			for (j = 0; j < subBoyut; j++)
			{
				alt_matris(subBoyut, subBoyut - 1, suBmatris, i, j); // yukar�da olu�turulan alt matrisi tekrar �a��r
			}
		}
	}
}
void alt_matrisBul(int boyut, int **matris)
{
	int i, j;
	int satir, sutun;
	for (i = 0; i < boyut; i++)
	{
		for (j = 0; j < boyut; j++)
		{
			alt_matris(boyut, boyut - 1, matris, i, j);
		}
	}
}