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
	};

	struct CAR car[2] = {
		{"Avante",2007},
		{"Sonata",2008}
	};

	for (i = 0; i < 2; i++)
	{
		fprintf(myinFile, "%s  %d\n", car[i].name, car[i].year); // 객체들을 정리한 형태로 txt 파일에 넣었다.
	}

	myinFile = fopen("cars.txt", "r");
	
	for (i = 0; i < 2; i++)
	{
		fprintf(stdout, "%s %d\n", car[i].name, car[i].year);
	}
	fclose(myinFile);
}