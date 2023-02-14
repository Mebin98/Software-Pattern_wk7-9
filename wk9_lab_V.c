#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	FILE* myfile,*agefile,*hobbyfile;
	myfile = fopen("personal.txt", "r");
	int i;

	struct person {
		char name[20];
		int age;
		char hobby[100];
	};
	struct person group[100];

	int n = 0; // 내가 몇들을 읽었는지에 대한 변수

	while (fscanf(myfile, "%s %d %s", group[n].name, &group[n].age, group[n].hobby) == 3)
	{
		n++;
	}
	fclose(myfile);

	agefile = fopen("age.txt", "w");
    
	for (i = 0; i < n; i++)
	{
		fprintf(agefile, "%s %d\n", group[i].name, group[i].age);
	}
	fclose(agefile);
	hobbyfile = fopen("hobby.txt", "w");
	for (i = 0; i < n; i++)
	{
		fprintf(hobbyfile, "%s %s\n", group[i].name, group[i].hobby);
	}
	fclose(hobbyfile);
}