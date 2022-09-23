#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
	int a[10], sum = 0, aa, b;
	
	for(int i = 0 ; i < 9 ; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a, a + 9);
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			if(i == j)
				continue;
			else
			{
				if(sum - a[i] - a[j] == 100)
				{
					aa = i;
					b = j;
					break;
				}
			}
		}
	}
	
	for(int i = 0 ; i < 9 ; i++)
	{
		if(i == aa || i == b)
			continue;
		else
			printf("%d\n", a[i]);
	}
	return 0;
}