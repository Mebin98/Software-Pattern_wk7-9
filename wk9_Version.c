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
	int n = 0; // ���� ����� �о������� ���� ���� v1��
	

	while (fscanf(v1, "%s %d %f", p[n].name,&p[n].age,&p[n].salary) == 3)
	{
		n++;
	}
	// ���� n=6
	fclose(v1);

	// Update_ver2
	v2 = fopen("salary_v2.txt", "w");
	for (i = 0; i < n; i++)
	{
		if ((p[i].age >= 40) && (p[i].age <= 49))
		{
			p[i].salary += p[i].salary / 10; // 10% �λ�
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
			p[i].salary += p[i].salary / 5; // 20% �λ�
		}
	}
	for (i = 0; i < n; i++)
	{
		fprintf(v3, "%s %d %.1f\n", p[i].name, p[i].age, p[i].salary);
	}
	fclose(v3);
}
// fscanf���� float ���� �����ڸ� %.2f, �Ǵ� %.1f�� �ѵ��� v2, v3 ����� �ȵ���. 
// ���� �����ڸ� %f�� �ٲٰ� �����ذ�
// fopen("w") �ϰ�� ��� ��ɾ �ִ��� �� Ȯ���Ұ�