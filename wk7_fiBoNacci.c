#include <stdio.h>

int fibo(int n)
{
	if (n < 2)
	{
		return n;
	}
	else
	{
		return (fibo(n - 1) + fibo(n - 2));
	}
}


void main()
{
	int x = fibo(5);
	printf("%d", x);
}