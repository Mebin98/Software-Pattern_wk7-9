#include <stdio.h>

int pow(int a, int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return (pow(a, n - 1) * a);
	}
}

void main()
{
	int ans = pow(2, 3);
	printf("%d", ans);

	return 0;
}