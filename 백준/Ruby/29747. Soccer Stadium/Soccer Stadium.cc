#include "soccer.h"
#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 987654321
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n;
ll a[2010][2010];
ll nu[2010][2010];
vector<pll> vec[2010];
map< pair<pll, pll>, ll> dp;

ll sum(ll x1, ll y1, ll x2, ll y2)
{
	return nu[x2][y2] - nu[x1 - 1][y2] - nu[x2][y1 - 1] + nu[x1 - 1][y1 - 1];
}

ll get_top(ll I, ll L, ll R)
{
	ll l = 1, r = I;
	
	while(l <= r)
	{
		ll mid = (l + r) >> 1;
		
		if(!sum(mid, L, I, R))
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	return l;
}

ll get_bottom(ll I, ll L, ll R)
{
	ll l = I, r = n;
	
	while(l <= r)
	{
		ll mid = (l + r) >> 1;
		
		if(!sum(I, L, mid, R))
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	return r;
}

ll f(ll x1, ll y1, ll x2, ll y2)
{
	if(dp.find({{x1, y1}, {x2, y2}}) != dp.end())
		return dp[{{x1, y1}, {x2, y2}}];
	
	ll ret = (x2 - x1 + 1) * (y2 - y1 + 1);
	
	if(x2 < n)
	{
		ll l = 0, r = (ll)vec[x2 + 1].size() - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(y1 <= vec[x2 + 1][mid].se)
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		for(ll i = l ; i < (ll)vec[x2 + 1].size() ; i++)
		{
			ll L = max(vec[x2 + 1][i].fi, y1);
			ll R = min(vec[x2 + 1][i].se, y2);
			
			if(L > R)
				break;
			
			ll tp = get_top(x2 + 1, L, R);
			ll bt = get_bottom(x2 + 1, L, R);
			
			ret = max(ret, f(tp, L, bt, R) + (x2 - x1 + 1) * (y2 - y1 - R + L));
		}
	}
	
	if(1 < x1)
	{
		ll l = 0, r = (ll)vec[x1 - 1].size() - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(y1 <= vec[x1 - 1][mid].se)
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		for(ll i = l ; i < (ll)vec[x1 - 1].size() ; i++)
		{
			ll L = max(vec[x1 - 1][i].fi, y1);
			ll R = min(vec[x1 - 1][i].se, y2);
			
			if(L > R)
				break;
			
			ll tp = get_top(x1 - 1, L, R);
			ll bt = get_bottom(x1 - 1, L, R);
			
			ret = max(ret, f(tp, L, bt, R) + (x2 - x1 + 1) * (y2 - y1 - R + L));
		}
	}
	
	return dp[{{x1, y1}, {x2, y2}}] = ret;
}

ll biggest_stadium(ll N, vector<vector<ll> > F)
{
	n = N;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			a[i][j] = F[i - 1][j - 1];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			nu[i][j] = nu[i - 1][j] + nu[i][j - 1] - nu[i - 1][j - 1] + a[i][j];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll st = -1;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			if(st == -1)
			{
				if(!a[i][j])
					st = j;
			}
			
			else
			{
				if(a[i][j])
				{
					vec[i].push_back({st, j - 1});
					st = -1;
				}
			}
		}
		
		if(st != -1)
			vec[i].push_back({st, n});
	}
	
	ll ans = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(auto &j : vec[i])
		{
			ll L = j.fi, R = j.se, tp = get_top(i, L, R), bt = get_bottom(i, L, R);
			ans = max(ans, f(tp, L, bt, R));
		}
	}
	
	return ans;
}