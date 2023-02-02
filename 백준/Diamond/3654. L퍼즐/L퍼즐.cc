#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

ll t;
ll n, m;
char a[510][510];
ll chk[510][510];
ll dx[10] = {-1, 1, 0, 0};
ll dy[10] = {0, 0, -1, 1};
ll B, W;
ll XX, YY;

void f(ll x, ll y)
{
	if(x < 0 || x >= n || y < 0 || y >= m)
		return;
	
	if(chk[x][y])
		return;
	
	chk[x][y] = 1;
	
	if(a[x][y] == '.')
		return;
	
	if(a[x][y] == 'W' && (x % 2 != XX || y % 2 != YY))
		return;
	if(a[x][y] == 'B' && ((x % 2 == XX && y % 2 == YY) || (x % 2 != XX && y % 2 != YY)))
		return;
		
	if(a[x][y] == 'W')
		W++;
	if(a[x][y] == 'B')
		B++;
	
	f(x - 1, y);
	f(x + 1, y);
	f(x, y - 1);
	f(x, y + 1);
}

int main(void)
{
	scanf("%lld", &t);
	
	while(t--)
	{
		scanf("%lld %lld", &n, &m);
		
		ll ww = 0, bb = 0;
		
		for(ll i = 0 ; i < n ; i++)
			scanf("%s", a[i]);
		
		for(ll i = 0 ; i < n ; i++)
		{
			for(ll j = 0 ; j < m ; j++)
			{
				if(a[i][j] == 'W')
					ww++;
				else if(a[i][j] == 'B')
					bb++;
			}
		}
		
		if(ww != bb * 2)
		{
			printf("NO\n");
			continue;
		}
		
		ll ff = 0;
		
		for(ll x = 0 ; x <= 1 ; x++)
		{
			for(ll y = 0 ; y <= 1 ; y++)
			{
				XX = x;
				YY = y;
				
				for(ll i = 0 ; i < n ; i++)
				{
					for(ll j = 0 ; j < m ; j++)
						chk[i][j] = 0;
				}
				
				for(ll i = 0 ; i < n ; i++)
				{
					for(ll j = 0 ; j < m ; j++)
					{
						B = 0, W = 0;
						
						f(i, j);
						
						if(B != W)
							ff = 1;
					}
				}
			}
		}
		
		printf("%s\n", ff ? "NO" : "YES");
	}
	
	return 0;
}