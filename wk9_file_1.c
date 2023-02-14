#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void main()
{
	FILE* myFile;
	double price[2] = { 139.25, 19.03 };
	char description[2][5] = { {"glove"}, {"CD"} };

	myFile = fopen("ok.dat", "w");
	if (myFile == NULL) // 파일이 존재하지 않으면
	{
		printf("\nFile Could Not Be Opened\n");
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			fprintf(myFile, "%-9s %6.2f\n", description[i], price[i]);
		}
		fclose(myFile);
	}
	return 0;
}