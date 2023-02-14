#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE* myInFile, * myOutFile;
	char ch;

	myInFile = fopen("data.txt", "r+");
	if (myInFile == NULL)
	{
		printf("Could Not Open data.txt!\n");
		exit(1); 
	}
	myOutFile = fopen("data2.txt", "w");

	while ((ch = fgetc(myInFile)) != EOF)
	{
		fputc(ch, myOutFile);
	}
	fclose(myInFile);
	fclose(myOutFile);
}