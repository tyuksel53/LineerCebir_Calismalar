#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define DOSYA_YOLU = "C:\\users\\taha\\desktop\\"

int *rastgeleSayi_Uret(int sayiMiktari);

void ekrana_yaz(int boyut, int **matris)
{
	char str[200] = "C:\\users\\taha\\desktop\\";
	char snum[12];
	sprintf(snum, "%d", boyut);
	strcat(str, snum);
	strcat(str, "submatrix.txt");
	FILE *fp;
	fp = fopen(str, "a");
	int i, j;
	for (i = 0; i < boyut; i++)
	{
		for (j = 0; j < boyut; j++)
		{
			//printf("%d ", matris[i][j]);
			fprintf(fp, "%d ",matris[i][j]);

		}
		//printf("\n");
		fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
	fclose(fp);
	//printf("\n\n------>Ekrana Yazildi\n\n");
	
}
void **alt_matris(int MatrisBoyut,int subBoyut, int **matris,int SiLsatir,int SiLsutun)
{
	int i, j;
	int **suBmatris = (int **)malloc(sizeof(int) * subBoyut - 1);
	int satir = 0;
	int sutun = 0;
	for (i = 0; i < subBoyut; i++)
	{
		suBmatris[i] = (int *)malloc(sizeof(int)* subBoyut - 1);
	}
	for (i = 0; i < MatrisBoyut; i++)
	{
		for (j = 0; j < MatrisBoyut; j++)
		{
			if (i != SiLsatir && j != SiLsutun)
			{
				suBmatris[satir][sutun] = matris[i][j];
				satir++;
			}	
		}
		if (satir == subBoyut)
		{
			satir = 0;
			sutun++;
		}
	}
	ekrana_yaz(subBoyut, suBmatris);
	if (subBoyut != 2)
	{
		for (i = 0; i < subBoyut; i++)
		{
			for (j = 0; j < subBoyut; j++)
			{
				alt_matris(subBoyut, subBoyut - 1, suBmatris, i, j);
			}
		}
	}

	//return suBmatris;
}
void alt_matrisBul(int boyut, int **matris)
{
	int i, j;
	int satir, sutun;
	for (i = 0; i < boyut; i++)
	{
		for (j = 0; j < boyut; j++)
		{
			////int **suBmatris;
			///suBmatris =
			alt_matris(boyut, boyut-1, matris, i, j);
			/////////ekrana_yaz(boyut-1, suBmatris);
		}
		//printf("\n");
	}

	for (i = 0; i < boyut; i++)
	{
		for (j = 0; j < boyut; j++)
		{
			printf("%d ", matris[i][j]);
		}
		printf("\n");
	}
	
}
int main()
{
	int matris_boyut = 5;
	int **matris = (int **)malloc(sizeof(int) * matris_boyut);
	int i, j;
	for (i = 0; i < matris_boyut; i++)
	{
		matris[i] = (int *)malloc(sizeof(int)* matris_boyut);
	}
	int sayac = 1;
	for (i = 0; i < matris_boyut; i++)
	{
		for (j = 0; j < matris_boyut; j++)
		{
			matris[i][j] = sayac;
			sayac++;
		}
	}
	alt_matrisBul(matris_boyut, matris);

	printf("Kac tane sayi uretmek istiyorsunuz ?\n");
	
	int rastgeleMiktar = 0;
	printf("---> ");
	scanf_s("%d", &rastgeleMiktar);
	
	printf("\n");
	
	int *rastgele_sayilar;
	
	rastgele_sayilar = rastgeleSayi_Uret(rastgeleMiktar);

	printf("\nRastgele sayilarin ilk terimi: %d\n", *(rastgele_sayilar + 0));

	printf("\nRastgele sayilarin son terimi: %d\n\n", *(rastgele_sayilar + rastgeleMiktar -1) );

	system("PAUSE");
	return 0;
}
int *rastgeleSayi_Uret(int sayiMiktari)
{
	int i = 0;
	srand(time(NULL));
	int *rastgeleSayilar = malloc(sizeof(int) * sayiMiktari);
	for (i = 0; i<sayiMiktari; i++)
	{
		rastgeleSayilar[i] = rand() % 241;
		printf("%d ", rastgeleSayilar[i] ) ;
	}
	printf("\n");
	return rastgeleSayilar;
}


