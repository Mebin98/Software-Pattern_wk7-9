#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE* myInFile, * myoutFile;
	char ch;

	myInFile = fopen("myinFile.txt", "r+");
	if (myInFile == NULL)
	{
		printf("Could Not Open data.txt!\n");
		exit(1);
	}
	myoutFile = fopen("myoutFile.txt", "a+");

	while ((ch = fgetc(myInFile)) != EOF)
	{
		fputc(ch, myoutFile);
	}
	fclose(myInFile);
	fclose(myoutFile);
}