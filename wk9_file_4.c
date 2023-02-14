#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	FILE* myFile;
	myFile = fopen("myinFile.txt", "r");
	char ch; // �� ����

	if (myFile == NULL) // defensive coding
	{
		printf("\nFile Could Not Be Opened\n");
	}
	else
	{
		ch = fgetc(myFile);    // fgetc�� �ѱ��ھ� �ִ´�, myFile���� �ѱ���(ch) get��
		while (ch != EOF)
		{
			putchar(ch); // ch�� ���
			ch = fgetc(myFile);  // �ݺ�
		}
	}

	printf("\nFinished Printing the File\n");
	fclose(myFile);
}
