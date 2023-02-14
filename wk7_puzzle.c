#include <stdio.h>

int puzzle(int n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n % 2 == 0)
	{
		return (puzzle(n / 2) + n);
	}
	else
	{
		return (puzzle((3*n)+1));
	}
}


void main()
{
	int ans = puzzle(5);
	printf("ans is %d", ans);
	
	return 0;
}