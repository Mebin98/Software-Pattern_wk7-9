#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (a) personal.txt에 있는 내용을 fscanf로 읽어서 구조체에 대입
void main()
{
	FILE* myfile, * agefile, * hobbyfile;
	myfile = fopen("personal.txt", "r");
	if (myfile == NULL)
	{
		printf("Enable to open personal.txt\n");
		exit(1);
	}

	struct person {
		char name[20];
		int age;
		char hobby[100];
	};
	struct person group[100];

	int n = 0; // 내가 몇들을 읽었는지에 대한 변수
	// 파일에 있는 값을 다 읽은것을 무엇으로 표시하지 ?

	while (fscanf(myfile, "%s %d %s", group[n].name, &group[n].age, group[n].hobby) == 3) 
	{
		n++;
	}
	fclose(myfile);
	// n = 6이다

	
	
	int i,j,temp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (group[j].age > group[j + 1].age)
			{
				temp = group[j].age;
				group[j].age = group[j + 1].age;
				group[j + 1].age = temp;
			}
		}

	}
	agefile = fopen("age.txt", "w");
	for (i = 0; i < n; i++)
	{
		fprintf(agefile, "%s %d %s\n", group[i].name, group[i].age, group[i].hobby);
	}
	fclose(agefile);
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (strcmp(group[j].hobby , group[j+1].hobby) > 0)
			{
				struct person temp;
				temp = group[j];
				group[j] = group[j + 1];
				group[j + 1] = temp;

				/*strcpy(temp, group[j].hobby);
				strcpy(group[j].hobby, group[j + 1].hobby);
				strcpy(group[j + 1].hobby, temp);*/
			}
		}

	}
	


	hobbyfile = fopen("hobby.txt", "w");
	for (i = 0; i < n; i++)
	{
		fprintf(hobbyfile, "%s %d %s\n", group[i].name, group[i].age, group[i].hobby);
	}
	fclose(hobbyfile);
}

