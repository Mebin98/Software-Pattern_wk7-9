#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// (a) employee.dat 파일을 만들어서 다음의 정보를 적는 프로그램을 작성해라
// (b) fcopy()함수를 만들어라 -> employee.dat -> employee.back copy 하는 함수
// (c) 위 내용의 프로그램을 scanf를 이용하여 키보드로 input 입력 -> output 구현 ! -> pdf 참조

void main()
{
	FILE* myInFile;
	int i;
	char ch;

	myInFile = fopen("employee.txt", "w");

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

	for (i = 0; i < 5; i++)
	{
		fprintf(myInFile, " %s %20s %20d %20.2f %20s \n", matrix[i].name, matrix[i].init, matrix[i].num, matrix[i].rate, matrix[i].date);
	}

	fclose(myInFile);

}