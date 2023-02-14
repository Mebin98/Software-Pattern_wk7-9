#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE* myFile;
	char ch;

	myFile = fopen("myinFile.txt", "r");

	if (myFile == NULL)
	{
		printf("\nCould Not open file!\n");
		exit(1);
	}

	while ((ch = fgetc(myFile)) != EOF)
	{
		putchar(ch);
	}
	fclose(myFile);
}