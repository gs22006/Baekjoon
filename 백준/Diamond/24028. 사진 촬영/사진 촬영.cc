#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n, k, b, c;
ll a[5010];
ll dp1[5010][5010];
ll dp2[5010][5010];

int main(void)
{
	scanf("%lld %lld %lld %lld", &n, &k, &b, &c);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld", &a[i]);
	
	for(ll i = 0 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= n ; j++)
			dp1[i][j] = dp2[i][j] = INF;
	}
	
	dp1[1][0] = a[1];
	dp1[1][1] = b;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= n ; j++)
		{
			if(j)
				dp1[i][j] = min(dp1[i][j], min(dp1[i - 1][j] + a[i] + j * c, dp1[i - 1][j - 1] + b));
			else
				dp1[i][j] = min(dp1[i][j], dp1[i - 1][j] + a[i] + j * c);
		}
		
		for(ll j = 0 ; j <= n ; j++)
		{
			if(j * 2 >= k)
				dp2[i][j] = min(dp2[i][j], dp1[i][j]);
			
			if(j < n && j * 2 + 1 >= k)
				dp2[i][j] = min(dp2[i][j], dp1[i][j + 1]);
		}
		
		for(ll j = 0 ; j <= n ; j++)
		{
			if(j < n)
				dp2[i][j] = min(dp2[i][j], min(dp2[i - 1][j] + a[i] + j * c, dp2[i - 1][j + 1] + b));
			else
				dp2[i][j] = min(dp2[i][j], dp2[i - 1][j] + a[i] + j * c);
		}
		
		dp1[i][0] = min(dp1[i][0], dp2[i][0]);
	}
	
	printf("%lld", min(dp1[n][0], dp2[n][0]));
	return 0;
}