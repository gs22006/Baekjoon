#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

ll t;
ll n;
ll a[2010][2010];
ll minw[2010][20];
ll maxw[2010][20];
ll minw2[2010][20];
ll maxw2[2010][20];
ll minu[20], mind[20];
ll minl[20], minr[20];
ll ans[20];

int main(void)
{
	scanf("%lld", &t);
	
	while(t--)
	{
		scanf("%lld", &n);
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
				scanf("%1lld", &a[i][j]);
			
			for(ll j = 0 ; j < 20 ; j++)
			{
				minw[i][j] = 0;
				maxw[i][j] = 0;
				minw2[i][j] = 0;
				maxw2[i][j] = 0;
				ans[j] = 0;
				minu[j] = MAX;
				mind[j] = 0;
				minl[j] = MAX;
				minr[j] = 0;
			}
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
			{
				if(!minw[i][a[i][j]])
					minw[i][a[i][j]] = j;
			}
			
			for(ll j = n ; j >= 1 ; j--)
			{
				if(!maxw[i][a[i][j]])
					maxw[i][a[i][j]] = j;
			}
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 0 ; j < 10 ; j++)
				ans[j] = max(ans[j], (maxw[i][j] - minw[i][j]) * max(i - 1, n - i));
		}
		
		for(ll j = 1 ; j <= n ; j++)
		{
			for(ll i = 1 ; i <= n ; i++)
			{
				if(!minw2[j][a[i][j]])
					minw2[j][a[i][j]] = i;
			}
			
			for(ll i = n ; i >= 1 ; i--)
			{
				if(!maxw2[j][a[i][j]])
					maxw2[j][a[i][j]] = i;
			}
		}
		
		for(ll j = 1 ; j <= n ; j++)
		{
			for(ll i = 0 ; i < 10 ; i++)
				ans[i] = max(ans[i], (maxw2[j][i] - minw2[j][i]) * max(j - 1, n - j));
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
			{
				if(!minu[a[i][j]])
					minu[a[i][j]] = i;
			}
		}
		
		for(ll i = n ; i >= 1 ; i--)
		{
			for(ll j = 1 ; j <= n ; j++)
			{
				if(!mind[a[i][j]])
					mind[a[i][j]] = i;
			}
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
			{
				minu[a[i][j]] = min(minu[a[i][j]], i);
				mind[a[i][j]] = max(mind[a[i][j]], i);
				minr[a[i][j]] = max(minr[a[i][j]], j);
				minl[a[i][j]] = min(minl[a[i][j]], j);
			}
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
			{
				if(minu[a[i][j]] != MAX)
					ans[a[i][j]] = max(ans[a[i][j]], (i - minu[a[i][j]]) * max(j - 1, n - j));
				if(mind[a[i][j]] != 0)
					ans[a[i][j]] = max(ans[a[i][j]], (mind[a[i][j]] - i) * max(j - 1, n - j));
				if(minl[a[i][j]] != MAX)
					ans[a[i][j]] = max(ans[a[i][j]], (j - minl[a[i][j]]) * max(i - 1, n - i));
				if(minr[a[i][j]] != 0)
					ans[a[i][j]] = max(ans[a[i][j]], (minr[a[i][j]] - j) * max(i - 1, n - i));
 			}
		}
		
		for(ll i = 0 ; i < 10 ; i++)
			printf("%lld ", ans[i]);
		
		printf("\n");
	}
	
	return 0;
}