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
vector<pll> vec[2500010];
set<ll> st[2500010];
ll pa[2500010], ra[2500010], len[2500010];
ll bun[2500010];
ll gap[2500010];
ll ans;
ll ss = 1000000007;

ll ffind(ll here)
{
	if(pa[here] == here)
		return here;
	
	return pa[here] = ffind(pa[here]);
}

ll get_len(ll X)
{
	return len[ffind(X)];
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	if(X == Y)
		return;
	
	if(ra[X] < ra[Y])
	{
		pa[X] = Y;
		len[Y] += len[X];
	}
	
	else if(ra[X] > ra[Y])
	{
		pa[Y] = X;
		len[X] += len[Y];
	}
	
	else
	{
		ra[Y]++;
		pa[X] = Y;
		len[Y] += len[X];
	}
}

void IN(ll w, ll X)
{
	auto p1 = st[w].lower_bound(X);
	auto p2 = st[w].upper_bound(X);
	ll L = 0, R = 0;
	
	if(p1 == st[w].begin())
		L = 0;
	
	else
	{
		p1--;
		L = (*p1);
	}
	
	if(p2 == st[w].end())
		R = n + 1;
	else
		R = (*p2);
	
	gap[w] -= (R - L - 1) * (R - L) / 2;
	gap[w] += (X - L - 1) * (X - L) / 2;
	gap[w] += (R - X - 1) * (R - X) / 2;
	gap[w]++;
	
	if(st[w].find(X - 1) != st[w].end())
	{
		ll len1 = get_len(X - 1);
		ll len2 = get_len(X);
		
		gap[w] -= (len1 + 1) * len1 / 2;
		gap[w] -= (len2 + 1) * len2 / 2;
		
		uunion(X - 1, X);
		len1 = get_len(X);
		
		gap[w] += (len1 + 1) * len1 / 2;
	}
	
	if(st[w].find(X + 1) != st[w].end())
	{
		ll len1 = get_len(X + 1);
		ll len2 = get_len(X);
		
		gap[w] -= (len1 + 1) * len1 / 2;
		gap[w] -= (len2 + 1) * len2 / 2;
		
		uunion(X + 1, X);
		len1 = get_len(X);
		
		gap[w] += (len1 + 1) * len1 / 2;
	}
	
	st[w].insert(X);
}

void dfs(ll here, ll p, ll LEN)
{
	ll chld = 0;
	
	for(auto &i : vec[here])
	{
		if(i.fi == p)
			continue;
		
		dfs(i.fi, here, i.se);
		chld++;
	}
	
	if(!chld)
	{
		bun[here] = here;
		gap[here] = n * (n + 1) / 2;
		IN(here, here);
		ans = ((n * (n + 1) / 2 - gap[here]) % ss * LEN % ss + ans) % ss;
		
		return;
	}
	
	ll maxx = 0, w = -1;
	
	for(auto &i : vec[here])
	{
		if(i.fi == p)
			continue;
		
		if((ll)st[bun[i.fi]].size() > maxx)
		{
			maxx = (ll)st[bun[i.fi]].size();
			w = i.fi;
		}
	}
	
	bun[here] = bun[w];
	
	for(auto &i : vec[here])
	{
		if(i.fi == p || i.fi == w)
			continue;
		
		for(auto &j : st[bun[i.fi]])
			IN(bun[here], j);
	}
	
	IN(bun[here], here);
	
	ans = ((n * (n + 1) / 2 - gap[bun[here]]) % ss * LEN % ss + ans) % ss;
}

int maintenance_costs_sum(vector<int> U, vector<int> V, vector<int> W)
{
	n = (ll)U.size() + 1;
	
	for(ll i = 0 ; i < n - 1 ; i++)
	{
		vec[U[i] + 1].push_back({V[i] + 1, W[i]});
		vec[V[i] + 1].push_back({U[i] + 1, W[i]});
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		pa[i] = i;
		len[i] = 1;
		ra[i] = 0;
	}
	
	dfs(1, 0, 0);
	
	ans = (ans % ss + ss) % ss;
	
	return (int)ans;
}