#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
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
 
ll n, m;
vector< pair<pll, ll> > vv;
ll all, bll, cll;
pair<pll, ll> qry[500010];
vector<ll> zip;
ll ans[500010];
 
struct segtree
{
	ll seg[2000010];
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no] += v;
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, w, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, w, v);
		
		seg[no] = seg[no << 1] + seg[no << 1 | 1];
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return query(no << 1, s, (s + e) >> 1, l, r) + query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
	}
}segt;
 
int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all >> bll >> cll;
		
		vv.push_back({{all, cll}, 1});
		vv.push_back({{bll + 1, cll}, -1});
		zip.push_back(cll);
	}
	
	cin >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> qry[i].fi.fi >> qry[i].fi.se;
		
		qry[i].se = i;
		zip.push_back(qry[i].fi.se);
	}
	
	sort(vv.begin(), vv.end());
	sort(qry + 1, qry + 1 + m);
	compress(zip);
	
	for(ll i = 0 ; i < (ll)vv.size() ; i++)
		vv[i].fi.se = lower_bound(zip.begin(), zip.end(), vv[i].fi.se) - zip.begin() + 1;
	
	for(ll i = 1 ; i <= m ; i++)
		qry[i].fi.se = lower_bound(zip.begin(), zip.end(), qry[i].fi.se) - zip.begin() + 1;
	
	ll siz = (ll)zip.size();
	ll p = 0;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		while(p < (ll)vv.size() && vv[p].fi.fi <= qry[i].fi.fi)
		{
			segt.update(1, 1, siz, vv[p].fi.se, zip[vv[p].fi.se - 1] * vv[p].se);
			p++;
		}
		
		ans[qry[i].se] = segt.query(1, 1, siz, 1, qry[i].fi.se) + zip[qry[i].fi.se - 1];
	}
	
	for(ll i = 1 ; i <= m ; i++)
		cout << ans[i] en;
	
	return 0;
}