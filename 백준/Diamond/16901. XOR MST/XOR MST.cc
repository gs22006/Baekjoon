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

ll n;
ll all;
vector<ll> a;
vector<ll> vv[6000010];
ll bun[6000010];
pll vec[6000010];
ll dep[6000010];
ll gap[6000010];
ll ans;
ll cc;

void init(void)
{
	dep[cc] = 29;
	vec[cc++] = {-1, -1};
}

void update(ll X)
{
	ll w = 0;
	
	for(ll i = 29 ; i >= 0 ; i--)
	{
		if(X & (1LL << i))
		{
			if(vec[w].se == -1)
			{
				vec[w].se = cc;
				dep[cc] = dep[w] - 1;
				w = cc;
				vec[cc++] = {-1, -1};
			}
			
			else
				w = vec[w].se;
		}
		
		else
		{
			if(vec[w].fi == -1)
			{
				vec[w].fi = cc;
				dep[cc] = dep[w] - 1;
				w = cc;
				vec[cc++] = {-1, -1};
			}
			
			else
				w = vec[w].fi;
		}
	}
	
	gap[w] = X;
}

ll f(ll here, ll X)
{
	if(dep[here] == -1)
		return 0;
	
	ll I = dep[here];
	
	if(X & (1LL << I))
	{
		if(vec[here].se != -1)
			return f(vec[here].se, X);
		
		return (f(vec[here].fi, X) | (1LL << I));
	}
	
	else
	{
		if(vec[here].fi != -1)
			return f(vec[here].fi, X);
		
		return (f(vec[here].se, X) | (1LL << I));
	}
}

void dfs(ll here)
{
	if(vec[here].fi == -1 && vec[here].se == -1)
	{
		bun[here] = here;
		vv[here].push_back(gap[here]);
		return;
	}
	
	ll maxx = -INF, w = -1;
	
	if(vec[here].fi != -1)
	{
		dfs(vec[here].fi);
		
		if(maxx < (ll)vv[bun[vec[here].fi]].size())
		{
			maxx = (ll)vv[bun[vec[here].fi]].size();
			w = bun[vec[here].fi];
		}
	}
	
	if(vec[here].se != -1)
	{
		dfs(vec[here].se);
		
		if(maxx < (ll)vv[bun[vec[here].se]].size())
		{
			maxx = (ll)vv[bun[vec[here].se]].size();
			w = bun[vec[here].se];
		}
	}
	
	bun[here] = w;
	
	if(vec[here].fi != -1 && vec[here].se != -1)
	{
		ll idx = 0, st = 0;
		ll minn = INF;
		
		if(bun[vec[here].fi] != w)
		{
			idx = bun[vec[here].fi];
			st = vec[here].se;
		}
		
		else
		{
			idx = bun[vec[here].se];
			st = vec[here].fi;
		}
		
		for(auto &i : vv[idx])
		{
			minn = min(minn, (f(st, i) | (1LL << dep[here])));
			vv[bun[here]].push_back(i);
		}
		
		vv[idx].clear();
		ans += minn;
	}
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 0 ; i < n ; i++)
	{
		cin >> all;
		a.push_back(all);
	}
	
	compress(a);
	n = (ll)a.size();
	
	init();
	
	for(ll i = 0 ; i < n ; i++)
		update(a[i]);
	
	dfs(0);
	
	cout << ans;
	return 0;
}