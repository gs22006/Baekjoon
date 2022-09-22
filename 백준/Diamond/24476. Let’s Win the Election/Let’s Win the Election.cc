#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n, k;
pair<ll, ll> a[510];
vector<ll> vec;
ll suma[510];
ld ans = INF;
ld dp[510][510];

int main(void)
{
	scanf("%lld", &n);
	scanf("%lld", &k);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		scanf("%lld %lld", &a[i].se, &a[i].fi);
		
		if(a[i].fi == -1)
			a[i].fi = 10000000000;
		
		a[i].se *= -1;
	}
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
		a[i].se *= -1;
	
	for(ll i = n ; i >= 0 ; i--)
	{
		sort(vec.begin(), vec.end());
		
		for(ll j = i ; j < k ; j++)
			suma[i] += vec[j - i];
		
		vec.push_back(a[i].se);
	}
	
	for(ll i = 0 ; i <= k ; i++)
	{
		for(ll j = 0 ; j <= n ; j++)
		{
			for(ll o = 0 ; o <= n ; o++)
				dp[j][o] = INF;
		}
		
		dp[0][0] = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			dp[j][0] = dp[j - 1][0] + (ld)a[j].se / (ld)(i + 1);
			
			for(ll o = 1 ; o <= i ; o++)
				dp[j][o] = min(dp[j - 1][o] + (ld)a[j].se / (ld)(i + 1), dp[j - 1][o - 1] + (ld)a[j].fi / (ld)o);
		}
		
		for(ll j = i ; j <= n ; j++)
			ans = min(ans, dp[j][i] + (ld)suma[j] / (ld)(i + 1));
	}
	
	printf("%.10Lf", ans);
	return 0;
}