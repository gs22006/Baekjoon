#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
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
pll a[200010];
vector<ll> zip;
ll spa[200010][21];
ll all, bll;
ll cc;
vector< pair<pll, ll> > vec;

struct lazysegtree
{
	ll seg[800010];
	ll lazy[800010];
	
	void prop(ll no, ll s, ll e)
	{
		if(!lazy[no])
			return;
		
		if(a[seg[no]].fi > a[lazy[no]].fi)
			seg[no] = lazy[no];
		
		if(s != e)
		{
			if(a[lazy[no << 1]].fi > a[lazy[no]].fi)
				lazy[no << 1] = lazy[no];
			
			if(a[lazy[no << 1 | 1]].fi > a[lazy[no]].fi)
				lazy[no << 1 | 1] = lazy[no];
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
			if(a[seg[no]].fi > a[v].fi)
				seg[no] = v;
			
			if(s != e)
			{
				if(a[lazy[no << 1]].fi > a[v].fi)
					lazy[no << 1] = v;
				
				if(a[lazy[no << 1 | 1]].fi > a[v].fi)
					lazy[no << 1 | 1] = v;
			}
			
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, l, r, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, v);
		
		if(a[seg[no << 1]].fi < a[seg[no << 1 | 1]].fi)
			seg[no] = seg[no << 1];
		else
			seg[no] = seg[no << 1 | 1];
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return -1;
		
		if(l <= s && e <= r)
			return seg[no];
		
		ll L = query(no << 1, s, (s + e) >> 1, l, r);
		ll R = query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
		
		if(L == -1 && R == -1)
			return -1;
		
		if(L == -1)
			return R;
		
		if(R == -1)
			return L;
		
		if(a[L].fi < a[R].fi)
			return L;
		
		return R;
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n >> q;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].fi >> a[i].se;
		
		zip.push_back(a[i].fi);
		zip.push_back(a[i].se);
		vec.push_back({{a[i].se, a[i].fi}, i});
	}
	
	compress(zip);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		a[i].fi = lower_bound(zip.begin(), zip.end(), a[i].fi) - zip.begin() + 1;
		a[i].se = lower_bound(zip.begin(), zip.end(), a[i].se) - zip.begin() + 1;
		cc = max(cc, max(a[i].fi, a[i].se));
	}
	
	sort(vec.begin(), vec.end());
	
	a[0].fi = INF;
	
	for(auto &i : vec)
	{
		segt.update(1, 1, cc, a[i.se].fi, a[i.se].se, i.se);
		
		ll gap = segt.query(1, 1, cc, a[i.se].fi, a[i.se].se);
		
		if(a[gap].fi == a[i.se].fi)
			spa[i.se][0] = i.se;
		else
			spa[i.se][0] = gap;
	}
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	while(q--)
	{
		ll hap = 0;
		ll ans = INF;
		
		cin >> all >> bll;
		
		if(all == bll)
		{
			cout << 0 en;
			continue;
		}
		
		if(a[all].se > a[bll].se)
		{
			cout << "impossible\n";
			continue;
		}
		
		for(ll i = 20 ; i >= 0 ; i--)
		{
			ll nxt = spa[bll][i];
			
			if(a[nxt].fi <= a[all].se && a[all].se <= a[nxt].se)
				ans = min(ans, hap + (1LL << i) + 1);
			
			if(a[nxt].fi > a[all].se)
			{
				bll = nxt;
				hap += (1LL << i);
			}
		}
		
		if(a[bll].fi <= a[all].se && a[all].se <= a[bll].se)
			ans = min(ans, hap + 1);
		
		bll = spa[bll][0];
		
		if(a[bll].fi <= a[all].se && a[all].se <= a[bll].se)
			ans = min(ans, hap + 2);
		
		if(ans == INF)
			cout << "impossible\n";
		else
			cout << ans en;
	}
	
	return 0;
}