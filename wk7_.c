#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{

	struct disk {
		int RRN;
		char name[20];
		int salary;
		int bonus;
	}; 

	struct disk employee[4];

	for (int i = 0; i < 4; i++)
	{
		printf("input RRN, name, salary, and bonus in order to\n");
		scanf("%d %s %d %d", &employee[i].RRN, &employee[i].name, &employee[i].salary, &employee[i].bonus);
		while (employee[i].salary <= employee[i].bonus)
		{
			printf("Error! Input salary and bonus again!\n"); // constraint<1>
			scanf("%d %d", &employee[i].salary, &employee[i].bonus);
		}

		
		    for (int j = 0; j < i; j++) // ��ġ�� ��ȣ�� �־��µ� �ٽ� ���������� �ȶ߰� ����ȴ� -> �̸� �ذ��ؾ���
		    {
			    if (employee[j].RRN == employee[i].RRN)
			    {
				    printf("Error! Input the RRN again!\n"); // constraint<1>
				    scanf("%d", &employee[i].RRN);	
					j = -1;
					continue;

			    }
		    }	
	}
	return 0;
}

