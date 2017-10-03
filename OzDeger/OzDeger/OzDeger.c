#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZE 10;
int *rastgeleSayi_Uret(int sayiMiktari);
/*void yaz(int boyut, int matrix[4][4])
{
	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{

				printf("%d ", matrix[i][j]);

		}
		printf("\n");
	}
}
void determinat_bul(int boyut, int matrix[4][4],int satir ,int sutun,int division)
{
	int i, j,k,t;
	if (division==boyut)
	{
		for (i = 0; i < boyut; i++)
		{
			for (j = 0; j < boyut; j++)
			{
				int *arr = (int *)malloc(boyut-1 * boyut-1 * sizeof(int));
				for (k = 0; k < boyut; k++)
				{
					for ( t = 0; t < boyut; t++)
					{
						if (k != i && t != j)
						{

						}
					}
				}
				for
				determinat_bul(boyut, matrix, satir, sutun,division-1);
			}
			printf("\n");
		}
	}
	else if(division >= 2)
	{
		for (i = 0; i < boyut; i++)
		{
			for (j = 0; j < boyut; j++)
			{ 
				for (int k = 0; k < boyut - division; k++)
				{
					if (satir != i && sutun != j)
					{
						printf("%d ", matrix[i][j]);
					}
				}
				
			}
			printf("\n");
		}
		printf("\nDongu bir");
	}else
	{
		return;
	}
	
}
*/
int main()
{
	///printf("Hello World\n");
	//int x=5;
	/*int i;
	int tmp = -999;
	int terim1 = -6, terim2 = -2;
	printf("x^2 %dx %d\n", terim2 + terim1, terim1*terim2);
	for (i = 1; i <= abs(terim1*terim2); i++)
	{
		if (terim1*terim2 % i == 0)
		{
			tmp = (i*i + ((terim1 + terim2)*i) + (terim1 * terim2));
			if (tmp == 0)
			{
				printf("Denklemin koklerinden biri: %d\n", i);
			}

		}
		if (terim1*terim2 % -i == 0)
		{
			i = i * -1;
			tmp = (i*i + ((terim1 + terim2)*i) + (terim1 * terim2));
			if (tmp == 0)
			{
				printf("Denklemin koklerinden biri: %d\n", i);
			}
			i = i* -1;

		}
	}
	int matrix[4][4];
	int sayac = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{

			matrix[i][j] = sayac;
			sayac++;
		}
	}
	int dizi[2] = { 0,0 };
	//yaz(4, matrix);
	determinat_bul(4,matrix,0,0,4);*/

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


