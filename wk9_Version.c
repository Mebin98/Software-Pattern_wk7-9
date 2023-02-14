#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	FILE* v1, * v2, * v3;
	v1 = fopen("salary_v1.txt", "r");
	int i;

	struct person {
		char name[100];
		int age;
		float salary;
	};
	struct person p[100];
	int n = 0; // 내가 몇들을 읽었는지에 대한 변수 v1용
	

	while (fscanf(v1, "%s %d %f", p[n].name,&p[n].age,&p[n].salary) == 3)
	{
		n++;
	}
	// 현재 n=6
	fclose(v1);

	// Update_ver2
	v2 = fopen("salary_v2.txt", "w");
	for (i = 0; i < n; i++)
	{
		if ((p[i].age >= 40) && (p[i].age <= 49))
		{
			p[i].salary += p[i].salary / 10; // 10% 인상
		}
	}
	for (i = 0; i < n; i++)
	{
		fprintf(v2, "%s %d %.1f\n", p[i].name, p[i].age, p[i].salary);
	}
	fclose(v2);

	n = 0;
	
	v2 = fopen("salary_v2.txt", "r");
	while (fscanf(v2, "%s %d %f", p[n].name, &p[n].age, &p[n].salary) == 3)
	{
		n++;
	}
	fclose(v2);

	v3 = fopen("salary_v3.txt", "w");
	for (i = 0; i < n; i++)
	{
		if ((p[i].age >= 30) && (p[i].age <= 39))
		{
			p[i].salary += p[i].salary / 5; // 20% 인상
		}
	}
	for (i = 0; i < n; i++)
	{
		fprintf(v3, "%s %d %.1f\n", p[i].name, p[i].age, p[i].salary);
	}
	fclose(v3);
}
// fscanf에서 float 형식 지정자를 %.2f, 또는 %.1f로 한동안 v2, v3 출력이 안됐음. 
// 형식 지정자를 %f로 바꾸고 문제해결
// fopen("w") 일경우 어디에 명령어가 있는지 잘 확인할것