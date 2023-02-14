#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// 파일을 복사할 때 , struct를 이용
void fcopy(FILE*, FILE*);
char name[100];

struct table {
	char name[10];
	char init[5];
	int num;
	double rate;
	char date[9];
};

struct table matrix[5] = {
	{"Anthony","A.J.",10031,7.82,"12/18/62"},
	{"Burrows","W.K.",10067,9.14,"6/9/63"},
	{"Fain","B.D.",10083,8.79,"5/18/59"},
	{"Janney","P.",10095,10.57,"9/28/62"},
	{"Smith","G.J.",10105,8.50,"12/20/61"}
};


void main()
{
	FILE* myInFile;
	FILE* myOutFile;

	int i;
	printf("output file name? :");
	scanf("%s", &name);
	myInFile = fopen("input.txt", "w");
	myOutFile = fopen(name, "w");


	for (i = 0; i < 5; i++)
	{
		fprintf(myInFile, " %s %20s %20d %20.2f %20s \n", matrix[i].name, matrix[i].init, matrix[i].num, matrix[i].rate, matrix[i].date);
	} // struct정보를 input 파일에 삽입!
	fclose(myInFile);
	fclose(myOutFile);
	fcopy(myInFile, myOutFile);

}


void fcopy(FILE* practice1, FILE* practice2)
{
	char line[1000];
	practice1 = fopen("input.txt", "r");
	if (practice1 == NULL) {
		printf("Unable to open input.txt for writing\n");
		exit(1);
	}
	practice2 = fopen(name, "w");
	if (practice2 == NULL) {
		printf("Unable to open input.txt for writing\n");
		exit(1);
	}

	while ((fgets(line, sizeof(line), practice1) != NULL))
	{
		fprintf(practice2, "%s", line);
	}

	fclose(practice1);
	fclose(practice2);
}