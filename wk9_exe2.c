#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// w로 파일 만들기 -> struct로 객체 생성 
// -> 객체들을 정리한 형태로 txt파일에 넣기 그리고 "r"
// 다시 w로 만들어서 메모지에 적힌 글자들을 그대로 컴파일 화면에 출력시키기
void main()
{
	FILE* myinFile;
	int i;
	char ch;

	myinFile = fopen("cars.txt", "w"); // 1. 파일 만들기

	struct CAR {
		char name[20];
		int year;
		double price;
	};

	struct CAR car[4] = {
		{"Avante",2007,13000.00},
		{"Sonata",2008,18000.00},
		{"SM7",2009,22000.00},
		{"Equss",2010,35000.00}
	};

	fprintf(myinFile, "=====================================================\n");
	fprintf(myinFile, "|Name                |Year                |Price\n");
	fprintf(myinFile, "=====================================================\n");
	for (i = 0; i < 4; i++)
	{
		fprintf(myinFile, " %s %15d %15.2f \n", car[i].name, car[i].year, car[i].price); // 객체들을 정리한 형태로 txt 파일에 넣었다.
	}
	fprintf(myinFile, "=====================================================\n");
	

	myinFile = fopen("cars.txt", "r");

	fprintf(stdout, "=====================================================\n");
	fprintf(stdout, "|Name                |Year                |Price\n");
	fprintf(stdout, "=====================================================\n");
	for (i = 0; i < 4; i++)
	{
		fprintf(stdout, " %s %15d %15.2f \n", car[i].name, car[i].year, car[i].price);
	}
	fprintf(stdout, "=====================================================\n");
	fclose(myinFile);
}