#include <bits/stdc++.h>

using namespace std;

struct xy
{
	int x;
	int y;
};

int n;
xy a[100010];
int nux[1000010], nuy[1000010];
int nx[1000010], ny[1000010];
int maxx;

int main(void)
{
	scanf("%d", &n);
	
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d %d", &a[i].x, &a[i].y);
		a[i].x += 500001;
		a[i].y += 500001;
	}
	
	a[n].x = a[0].x;
	a[n].y = a[0].y;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(a[i].x == a[i + 1].x)
		{
			nux[min(a[i].y, a[i + 1].y)]++;
			nux[max(a[i].y, a[i + 1].y)]--;
		}
		
		if(a[i].y == a[i + 1].y)
		{
			nuy[min(a[i].x, a[i + 1].x)]++;
			nuy[max(a[i].x, a[i + 1].x)]--;
		}
	}
	
	for(int i = 1 ; i <= 1000001 ; i++)
	{
		nx[i] = nx[i - 1] + nux[i];
		ny[i] = ny[i - 1] + nuy[i];
		maxx = max(maxx, max(nx[i], ny[i]));
	}
	
	printf("%d", maxx);
	return 0;
}