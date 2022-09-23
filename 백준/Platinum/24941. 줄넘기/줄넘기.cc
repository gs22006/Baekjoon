#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n;
ll a[500010];
vector<ll> zip;
unordered_map<ll, ll> ZIP;
ll cc;
vector<ll> w[500010];
vector< pair<ll, ll> > vec;
vector< pair< pair<ll, ll>, ll> > qry;
ll q;
ll all, bll;
ll ans[500010];

struct segtree
{
	ll seg[2500010];
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(w < s || e < w)
			return;
		
		if(s == e)
		{
			seg[no] = v;
			return;
		}
		
		update(no * 2, s, (s + e) / 2, w, v);
		update(no * 2 + 1, (s + e) / 2 + 1, e, w, v);
		
		seg[no] = max(seg[no * 2], seg[no * 2 + 1]);
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return max(query(no * 2, s, (s + e) / 2, l, r), query(no * 2 + 1, (s + e) / 2 + 1, e, l, r));
	}
}segt;

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		scanf("%lld", &a[i]);
		zip.push_back(a[i]);
	}
	
	sort(zip.begin(), zip.end());
	
	for(ll i = 0 ; i < zip.size() ; i++)
	{
		if(i != 0 && zip[i - 1] == zip[i])
			continue;
		
		ZIP[zip[i]] = ++cc;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		a[i] = ZIP[a[i]];
		w[a[i]].push_back(i);
	}
	
	for(ll i = 1 ; i <= cc ; i++)
	{
		for(ll j = 1 ; j < w[i].size() ; j++)
			vec.push_back(make_pair(w[i][j - 1], w[i][j]));
	}
	
	sort(vec.begin(), vec.end());
	
	for(pair<ll, ll> i : vec)
		segt.update(1, 1, n, i.se, i.se - i.fi + 1);
	
	scanf("%lld", &q);
	
	for(ll i = 1 ; i <= q ; i++)
	{
		scanf("%lld %lld", &all, &bll);
		qry.push_back(make_pair(make_pair(all, bll), i));
	}
	
	sort(qry.begin(), qry.end());
	
	ll p = 0;
	
	for(pair< pair<ll, ll>, ll> i : qry)
	{
		while(p < (ll)vec.size() && i.fi.fi > vec[p].fi)
		{
			segt.update(1, 1, n, vec[p].se, 0);
			p++;
		}
		
		ans[i.se] = segt.query(1, 1, n, i.fi.fi, i.fi.se);
	}
	
	for(ll i = 1 ; i <= q ; i++)
		printf("%lld\n", ans[i]);
	
	return 0;
}