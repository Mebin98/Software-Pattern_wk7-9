#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int a, sum = 0;
	FILE* inFile, * outFile;

	inFile = fopen("myinFile.txt", "r");
	if (inFile == NULL)
	{
		printf("Input File Could Not Be Opened.\n");
		exit(1);
	}
	outFile = fopen("myoutFile.txt", "w");
	if (outFile == NULL)
	{
		printf("Output File Could Not Be Opened\n");
		exit(1);
	}

	while (fscanf(inFile, "%d", &a) == 1)
	{
		sum += a;
	}
	fprintf(outFile, "The sum is %d\n", sum);
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}