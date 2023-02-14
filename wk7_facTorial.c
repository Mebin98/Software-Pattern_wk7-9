#include <stdio.h>

int factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return (n * factorial(n - 1));
	}
}


void main()
{
	int x = factorial(3);
	printf("%d", x); 
}