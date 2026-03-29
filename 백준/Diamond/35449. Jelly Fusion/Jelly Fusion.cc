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
pll a[300010];
pll b[300010];
ll dp[300010];

struct node
{
	ll L, R;
	pll line;
};

ll Y(pll L, ll X)
{
	return L.fi * X + L.se;
}

struct lichaotree
{
	vector<node> seg;
	
	void init(void)
	{
		seg.clear();
		seg.push_back({-1, -1, {0, -INF}});
	}
	
	void update(ll no, ll s, ll e, pll L)
	{
		ll mid = (s + e) >> 1;
		pll line1 = seg[no].line;
		pll line2 = L;
		
		if(Y(line1, s) > Y(line2, s))
			swap(line1, line2);
		
		if(Y(line1, e) <= Y(line2, e))
		{
			seg[no].line = line2;
			return;
		}
		
		if(Y(line1, mid) < Y(line2, mid))
		{
			seg[no].line = line2;
			
			if(seg[no].R == -1)
			{
				seg[no].R = (ll)seg.size();
				seg.push_back({-1, -1, {0, -INF}});
			}
			
			update(seg[no].R, mid + 1, e, line1);
		}
		
		else
		{
			seg[no].line = line1;
			
			if(seg[no].L == -1)
			{
				seg[no].L = (ll)seg.size();
				seg.push_back({-1, -1, {0, -INF}});
			}
			
			update(seg[no].L, s, mid, line2);
		}
	}
	
	ll query(ll no, ll s, ll e, ll w)
	{
		if(e < w || w < s)
			return -INF;
		
		if(s == e)
			return Y(seg[no].line, w);
		
		ll ret = Y(seg[no].line, w);
		
		if(seg[no].L != -1)
			ret = max(ret, query(seg[no].L, s, (s + e) >> 1, w));
		
		if(seg[no].R != -1)
			ret = max(ret, query(seg[no].R, ((s + e) >> 1) + 1, e, w));
		
		return ret;
	}
}segt, segt2;

ll solve(void)
{
	segt.init();
	segt2.init();
	
	for(ll i = 1 ; i <= n ; i++)
		dp[i] = 0;
	
	segt.update(0, -1000000000000, 1000000000000, {b[1].se, 0});
	segt2.update(0, -1000000000000, 1000000000000, {b[1].fi, 0});
	
	for(ll i = 1 ; i <= n ; i++)
	{
		dp[i] = max(dp[i], segt.query(0, -1000000000000, 1000000000000, b[i].fi));
		dp[i] = max(dp[i], segt2.query(0, -1000000000000, 1000000000000, b[i].se));
		segt.update(0, -1000000000000, 1000000000000, {b[i + 1].se, dp[i]});
		segt2.update(0, -1000000000000, 1000000000000, {b[i + 1].fi, dp[i]});
	}
	
	ll ret = 0;
	
	for(ll i = 1 ; i <= n ; i++)
		ret = max(ret, dp[i]);
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	
	ll ans = 0;
	ll maxx = 0, w = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i].fi > maxx)
		{
			maxx = a[i].fi;
			w = i;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll W = i - w + 1;
		
		if(W < 1)
			W += n;
		
		b[W] = a[i];
	}
	
	ans = max(ans, solve());
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll W = i - w;
		
		if(W < 1)
			W += n;
		
		b[W] = a[i];
	}
	
	ans = max(ans, solve());
	
	maxx = 0, w = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i].se > maxx)
		{
			maxx = a[i].se;
			w = i;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll W = i - w + 1;
		
		if(W < 1)
			W += n;
		
		b[W] = a[i];
	}
	
	ans = max(ans, solve());
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll W = i - w;
		
		if(W < 1)
			W += n;
		
		b[W] = a[i];
	}
	
	ans = max(ans, solve());
	
	cout << ans en;
	return 0;
}