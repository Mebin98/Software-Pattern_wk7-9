#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// w�� ���� ����� -> struct�� ��ü ���� 
// -> ��ü���� ������ ���·� txt���Ͽ� �ֱ� �׸��� "r"
// �ٽ� w�� ���� �޸����� ���� ���ڵ��� �״�� ������ ȭ�鿡 ��½�Ű��
void main()
{
	FILE* myinFile;
	int i;
	char ch;

	myinFile = fopen("cars.txt", "w"); // 1. ���� �����
	
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
		fprintf(myinFile, "%s  %d\n", car[i].name, car[i].year); // ��ü���� ������ ���·� txt ���Ͽ� �־���.
	}

	myinFile = fopen("cars.txt", "r");
	
	for (i = 0; i < 2; i++)
	{
		fprintf(stdout, "%s %d\n", car[i].name, car[i].year);
	}
	fclose(myinFile);
}