#include <stdio.h>
#include <algorithm>

using namespace std;

struct people
{
	int s;
	int c;
	int l;
	int num;
	
	bool operator < (const people &a)const
	{
		if(s != a.s)
		{
			return s < a.s;
		}
		
		else
		{
			if(c != a.c)
			{
				return c > a.c;
			}
			
			else
			{
				return l > a.l;
			}
		}
	}
};

int n;
people a[10010];

int main(void)
{
	scanf("%d", &n);
	
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d %d %d", &a[i].s, &a[i].c, &a[i].l);
		a[i].num = i + 1;
	}
	
	sort(a, a + n);
	
	printf("%d", a[n - 1].num);
	return 0;
}