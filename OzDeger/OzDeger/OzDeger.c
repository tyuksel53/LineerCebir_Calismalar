#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int *rastgeleSayi_Uret(int sayiMiktari);


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

	/*matris[0][0] = 3;
	matris[0][1] = 4;
	matris[0][2] = 1;
	matris[0][3] = 5;
	matris[1][0] = 5;
	matris[1][1] = 6;
	matris[1][2] = 2;
	matris[1][3] = 3;
	matris[2][0] = 4;
	matris[2][1] = 6;
	matris[2][2] = 10;
	matris[2][3] = 23;
	matris[3][0] = 24;
	matris[3][1] = 12;
	matris[3][2] = 3;
	matris[3][3] = 5;*/

	matris[0][0] = 2;
	matris[0][1] = 5;
	matris[0][2] = 4;
	matris[0][3] = 1;
	matris[0][4] = 6;
	matris[1][0] = 4;
	matris[1][1] = 6;
	matris[1][2] = 7;
	matris[1][3] = 1;
	matris[1][4] = 3;
	matris[2][0] = 4;
	matris[2][1] = 2;
	matris[2][2] = 6;
	matris[2][3] = 6;
	matris[2][4] = 10;
	matris[3][0] = 23;
	matris[3][1] = 14;
	matris[3][2] = 15;
	matris[3][3] = 3;
	matris[3][4] = 6;
	matris[4][0] = 13;
	matris[4][1] = 24;
	matris[4][2] = 24;
	matris[4][3] = 23;
	matris[4][4] = 11;

	/*matris[0][0] = 3;
	matris[0][1] = 4;
	matris[0][2] = 2;
	matris[1][0] = 7;
	matris[1][1] = 8;
	matris[1][2] = 10;
	matris[2][0] = 23;
	matris[2][1] = 12;
	matris[2][2] = 4;*/

	determinantBul(matris_boyut, matris);
	//alt_matrisBul(matris_boyut, matris);
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


