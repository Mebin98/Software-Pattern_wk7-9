#include <stdio.h>

int sum(int element[], int n)
{
	if (n == 1)
	{
		return element[0];
	}
	else
	{
		return (element[n - 1] + sum(element, n - 1)); 
	}
}

void main()
{
	int arr[] = {20,30,10,50,15,45,80,25};
	int num = 4;

	int add = sum(arr, num);

	printf("Answer : %d\n", add);
	return 0;
}