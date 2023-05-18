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

ll n;
ll a[20];
vector<ll> vec[20], tmp;
ll dp[100010];
ll fac[20];
ll siz;

void f(ll gaet, ll last, ll gap, ll gap2)
{
	if(gaet >= siz)
	{
		dp[gap] += dp[gap2] * fac[gaet];
		return;
	}
	
	for(ll i = last + 1 ; i < (ll)tmp.size() ; i++)
		f(gaet + 1, i, gap | (1LL << tmp[i]), gap2);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	for(ll i = 0 ; i < n ; i++)
		cin >> a[i];
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			if(a[i] % j == 0)
				vec[j].push_back(i);
		}
	}
	
	fac[0] = 1;
	
	for(ll i = 1 ; i <= n ; i++)
		fac[i] = fac[i - 1] * i;
	
	ll m = (1LL << n);
	
	dp[0] = 1;
	
	for(ll i = 0 ; i < m ; i++)
	{
		ll w = 0;
		
		for(ll j = 0 ; j < n ; j++)
		{
			if(!(i & (1LL << j)))
			{
				w = j;
				break;
			}
		}
		
		for(ll j = 1 ; j <= n ; j++)
		{
			ll ff = 0;
			tmp.clear();
			
			for(auto &k : vec[j])
			{
				if(i & (1LL << k))
					continue;
				
				if(ff)
					tmp.push_back(k);
				
				if(k == w)
					ff = 1;
			}
			
			if(ff)
			{
				siz = j - 1;
				f(0, -1, i | (1LL << w), i);
			}
		}
	}
	
	cout << dp[m - 1];
	return 0;
}