#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10;
void yaz(int boyut, int matrix[4][4])
{
	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{

				printf("%d ", matrix[i][j]);

		}
		printf("\n");as
	}
}
void determinat_bul(int boyut, int matrix[4][4],int satir[],int sutun[],int division)
{
	int i, j;
	if (division==boyut)
	{
		for (i = 0; i < boyut; i++)
		{
			for (j = 0; j < boyut; j++)
			{
				satir[0] = i;
				sutun[0] = j;
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
					if (satir[] != i && sutun != j)
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

int main()
{
	printf("Hello World\n");
	//int x=5;
	int i;
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
	determinat_bul(4,matrix,0,0,4);
	system("PAUSE");
	return 0;
}

