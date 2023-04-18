#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775808LL

ll n;
ll a[1010];
ll w;
ll ff;

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= i ; j++)
		{
			if(__gcd(i, j) == 1)
				a[i]++;
		}
	}
	
	printf("%lld ", n);
	
	a[n]--;
	
	for(ll i = n ; i >= 1 ; i--)
	{
		if(a[i] != 0)
		{
			if(i % 2 == 0)
			{
				ll gap = a[i];
				
				for(ll j = 1 ; j <= gap ; j++)
				{
					printf("%lld %lld ", i - 1, i);
					a[i - 1]--;
					a[i]--;
				}
			}
			
			else
			{
				if(a[i - 1] >= a[i])
				{
					ll gap = a[i];
					
					for(ll j = 1 ; j <= gap ; j++)
					{
						printf("%lld %lld ", i - 1, i);
						a[i - 1]--;
						a[i]--;
					}
				}
				
				else
				{
					ll gap = a[i - 1];
					
					for(ll j = 1 ; j <= gap ; j++)
					{
						printf("%lld %lld ", i - 1, i);
						a[i - 1]--;
						a[i]--;
					}
					
					gap = a[i];
					
					for(ll j = 1 ; j <= gap ; j++)
					{
						printf("%lld %lld ", i - 2, i);
						a[i - 2]--;
						a[i]--;
					}
				}
			}
		}
		
		if(a[i - 1] != 0)
		{
			printf("%lld ", i - 1);
			a[i - 1]--;
			continue;
		}
		
		else if(a[i - 2] != 0)
		{
			printf("%lld ", i - 2);
			a[i - 2]--;
			i--;
			continue;
		}
		
		else if(a[i - 3] != 0)
		{
			printf("%lld ", i - 3);
			a[i - 3]--;
			i -= 2;
			continue;
		}
	}
	
	return 0;
}