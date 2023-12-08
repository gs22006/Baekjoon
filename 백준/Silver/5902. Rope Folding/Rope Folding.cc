#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll L, n;
ll a[110];
ll ans;

int main(void)
{
	fastio
	
	cin >> n >> L;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		a[i] *= 2;
	}
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = 1 ; i < L * 2 ; i++)
	{
		map<ll, ll> mp;
		ll cou = 0, cou2 = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			if(a[j] == i)
				continue;
			
			if(a[j] < i)
				mp[i * 2 - a[j]]++, cou++;
			else
				mp[a[j]]++, cou2++;
		}
		
		cou2 = min(cou, cou2);
		ll ff = 0, ff2 = 0;
		
		for(auto &j : mp)
		{
			if(j.se % 2 == 0)
			{
				ff++;
				
				if(ff2)
					ff = -INF;
			}
			
			else
				ff2 = 1;
		}
		
		if(ff == cou2)
		{
			ans++;
			continue;
		}
		
		ff = 0, ff2 = 0;
		
		for(auto &j : mp)
		{
			if(j.se % 2 == 0)
				ff++;
			else if(ff)
				ff = -INF;
		}
		
		if(ff == cou2)
			ans++;
	}
	
	cout << ans;
	return 0;
}