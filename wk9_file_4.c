#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	FILE* myFile;
	myFile = fopen("myinFile.txt", "r");
	char ch; // 한 글자

	if (myFile == NULL) // defensive coding
	{
		printf("\nFile Could Not Be Opened\n");
	}
	else
	{
		ch = fgetc(myFile);    // fgetc는 한글자씩 넣는다, myFile에서 한글자(ch) get함
		while (ch != EOF)
		{
			putchar(ch); // ch를 출력
			ch = fgetc(myFile);  // 반복
		}
	}

	printf("\nFinished Printing the File\n");
	fclose(myFile);
}
