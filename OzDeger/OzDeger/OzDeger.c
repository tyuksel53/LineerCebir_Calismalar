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


