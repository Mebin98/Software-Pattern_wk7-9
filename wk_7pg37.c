#include <stdio.h>

int cnt = 0;
// list���� lo�� hi�� �����ε� �̸� �������� ������ ���� �� �ִ� ����� �ֳ�?

int srch(int list[], int lo, int hi, int key)
{
	int temp;
	int mid;
	if (lo > hi)
	{
		return -1;
	}
	mid = lo + hi;
    if ((mid % 2) == 0)
	{
		mid = (lo + hi) / 2;
	}
	else if ((mid % 2) != 0)
	{
		mid = (lo + hi + 1) / 2;
	}
	temp = mid;

	if (list[mid] == key)
	{
		return cnt;
	}
	else if (list[mid] > key)
	{
		cnt++;
		return srch(list, lo, mid, key);
	}
	else if (list[mid] < key)
	{
		cnt++;
		return srch(list, mid, hi, key);
	}
	
}


void main()
{
	int arr1[] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
	int ans = srch(arr1, 0, 12, 5);
	printf("%d", ans);
	
	return 0;
}