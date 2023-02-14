#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 미국 대선 프로그램
void main()
{
	FILE* myfile;
	myfile = fopen("vote.txt", "r");

	struct person {
		char region[100];
		int age;
		char cand[100];
	};

	struct person p[100];
	int n = 0; // 내가 몇들을 읽었는지에 대한 변수

	while (fscanf(myfile, "%s %d %s", p[n].region, &p[n].age, p[n].cand) == 3)
	{
		n++;
	}
	fclose(myfile);
	// n명 투표.. 배열은 [0] ~ [n-1]

	int biden = 0;
	int trump = 0;
	int i;

	for (i = 0; i < n; i++)
	{
		if (strcmp(p[i].cand, "biden") == 0)
		{
			biden++;
		}
		if (strcmp(p[i].cand, "trump") == 0)
		{
			trump++;
		}
	}
	printf("Current Voting Rate\n");
	printf("Biden : %.2f\n", (float)biden / (float)n * 100);
	printf("Trump : %.2f\n", (float)trump / (float)n * 100);

	printf("Sample evert third row\n");
	int biden_b = 0;
	int trump_b = 0;
	int cnt_b = 0;
	for (i = 2; i < n; i += 3)
	{
		if (strcmp(p[i].cand, "biden") == 0)
		{
			(biden_b)++;
			cnt_b++;
		}
		if (strcmp(p[i].cand, "trump") == 0)
		{
			(trump_b)++;
			cnt_b++;
		}
	}
	printf("Biden : %.2f\n", (float)biden_b / (float)cnt_b * 100);
	printf("Trump : %.2f\n", (float)trump_b / (float)cnt_b * 100);

	int biden_a = 0;
	int trump_a = 0;
	int cnt_a = 0;

	printf("Sample every tenth row\n");
	for (i = 9; i < n; i += 10)
	{
		if (strcmp(p[i].cand, "biden") == 0)
		{
			(biden_a)++;
			cnt_a++;
		}
		if (strcmp(p[i].cand, "trump") == 0)
		{
			(trump_a)++;
			cnt_a++;
		}
	}

	printf("Biden : %.2f\n", (float)biden_a / (float)cnt_a * 100);
	printf("Trump : %.2f\n", (float)trump_a / (float)cnt_a * 100);
}