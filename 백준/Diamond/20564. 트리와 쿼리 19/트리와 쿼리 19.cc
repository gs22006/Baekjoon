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

ll n, q;
ll a[500010];
ll P[500010];
ll all;
vector<ll> vec[500010];
ll sub[500010], dp[500010];
ll IN[500010], OUT[500010];
ll tp[500010];
ll dep[500010];
ll cc;
ll ans;

struct segtree
{
	ll seg[2000010];
	ll lazy[2000010];
	
	void prop(ll no, ll s, ll e)
	{
		seg[no] += lazy[no] * (e - s + 1);
		
		if(s != e)
		{
			lazy[no << 1] += lazy[no];
			lazy[no << 1 | 1] += lazy[no];
		}
		
		lazy[no] = 0;
	}
	
	void update(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			seg[no] += v * (e - s + 1);
			
			if(s != e)
			{
				lazy[no << 1] += v;
				lazy[no << 1 | 1] += v;
			}
			
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, l, r, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, v);
		
		seg[no] = seg[no << 1] + seg[no << 1 | 1];
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return query(no << 1, s, (s + e) >> 1, l, r) + query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
	}
}segt;

void dfs0(ll here)
{
	sub[here] = 1;
	dp[here] = a[here];
	
	for(auto &i : vec[here])
	{
		dep[i] = dep[here] + 1;
		dfs0(i);
		sub[here] += sub[i];
		dp[here] += dp[i];
	}
	
	if(vec[here].empty())
		return;
	
	for(auto &i : vec[here])
	{
		if(sub[vec[here][0]] < sub[i])
			swap(vec[here][0], i);
	}
}

void dfs(ll here)
{
	IN[here] = ++cc;
	
	for(auto &i : vec[here])
	{
		if(i == vec[here][0])
			tp[i] = tp[here];
		else
			tp[i] = i;
		
		dfs(i);
	}
	
	OUT[here] = cc;
}

void update(ll X, ll v)
{
	while(X)
	{
		segt.update(1, 1, cc, IN[tp[X]], IN[X], v);
		X = P[tp[X]];
	}
}

ll query(ll X)
{
	ll ret = 0;
	
	while(X)
	{
		ret += segt.query(1, 1, cc, IN[tp[X]], IN[X]);
		X = P[tp[X]];
	}
	
	ret -= segt.query(1, 1, cc, IN[1], IN[1]);
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n >> q;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 2 ; i <= n ; i++)
	{
		cin >> P[i];
		vec[P[i]].push_back(i);
	}
	
	dfs0(1);
	tp[1] = 1;
	dfs(1);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll sum1 = 0, sum2 = 0;
		
		for(auto &j : vec[i])
		{
			sum1 += dp[j];
			sum2 += dp[j] * dp[j];
		}
		
		ans += dep[i] * (sum1 * sum1 - sum2) / 2;
		
		if(a[i])
			ans += dep[i] * sum1;
	}
	
	for(ll i = 1 ; i <= n ; i++)
		segt.update(1, 1, cc, IN[i], IN[i], dp[i]);
	
	cout << ans en;
	
	while(q--)
	{
		cin >> all;
		
		if(a[all] == 0)
		{
			a[all] = 1;
			ans += query(all);
			update(all, 1);
		}
		
		else
		{
			a[all] = 0;
			ans -= query(all) - dep[all];
			update(all, -1);
		}
		
		cout << ans en;
	}
	
	return 0;
}