#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE* infile = NULL;
	char line[100];
	int cnt = 0;

	if ((infile = fopen("charstream.txt", "r")) == NULL)
	{
		printf("File Could Not Be Opened.\n");
		exit(1);
	}

	while (fgets(line, sizeof(line), infile) != EOF) //fgets에 포인터가 
		//들어가는 이유???
	{
		cnt++;
		printf("Line %d: %s", cnt, line);
	}
	fclose(infile);
}