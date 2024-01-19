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

ll n, m;
pll a[1000010];
ll zipy[1000010];
priority_queue< pair<ll, pll> > pq;
ll rt1[1000010], rt2[1000010];
vector<ll> zip;
vector<ll> sad[1000010];

struct node
{
	ll L, R, gap, idx;
};

struct persistentsegtree
{
	vector<node> seg;
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
			return;
		
		seg[no].L = (ll)seg.size();
		seg.push_back({-1, -1, INF, -1});
		seg[no].R = (ll)seg.size();
		seg.push_back({-1, -1, INF, -1});
		
		init(seg[no].L, s, (s + e) >> 1);
		init(seg[no].R, ((s + e) >> 1) + 1, e);
	}
	
	void update(ll last, ll no, ll s, ll e, ll w, ll v, ll v2)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no].gap = v;
			seg[no].idx = v2;
			return;
		}
		
		ll mid = (s + e) >> 1;
		
		if(w <= mid)
		{
			seg[no].R = seg[last].R;
			
			if(seg[no].L == -1)
			{
				seg[no].L = (ll)seg.size();
				seg.push_back({-1, -1, INF, -1});
			}
			
			update(seg[last].L, seg[no].L, s, mid, w, v, v2);
		}
		
		else
		{
			seg[no].L = seg[last].L;
			
			if(seg[no].R == -1)
			{
				seg[no].R = (ll)seg.size();
				seg.push_back({-1, -1, INF, -1});
			}
			
			update(seg[last].R, seg[no].R, mid + 1, e, w, v, v2);
		}
		
		if(seg[seg[no].L].gap < seg[seg[no].R].gap)
			seg[no].gap = seg[seg[no].L].gap, seg[no].idx = seg[seg[no].L].idx;
		else
			seg[no].gap = seg[seg[no].R].gap, seg[no].idx = seg[seg[no].R].idx;
	}
	
	pll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return {INF, -1};
		
		if(l <= s && e <= r)
			return {seg[no].gap, seg[no].idx};
		
		pll ret;
		
		ret = {INF, -1};
		
		if(seg[no].L != -1)
			ret = min(ret, query(seg[no].L, s, (s + e) >> 1, l, r));
		
		if(seg[no].R != -1)
			ret = min(ret, query(seg[no].R, ((s + e) >> 1) + 1, e, l, r));
		
		return ret;
	}
}segt1, segt2;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
		zip.push_back(a[i].se);
	
	compress(zip);
	
	ll siz = (ll)zip.size();
	
	for(ll i = 1 ; i <= n ; i++)
	{
		zipy[i] = lower_bound(zip.begin(), zip.end(), a[i].se) - zip.begin() + 1;
		sad[zipy[i]].push_back(i);
	}
	
	rt1[n] = (ll)segt1.seg.size();
	segt1.seg.push_back({-1, -1, INF, -1});
	segt1.init(rt1[n], 1, siz);
	
	rt2[n] = (ll)segt2.seg.size();
	segt2.seg.push_back({-1, -1, INF, -1});
	segt2.init(rt2[n], 1, siz);
	
	for(ll i = n - 1 ; i >= 1 ; i--)
	{
		rt1[i] = (ll)segt1.seg.size();
		segt1.seg.push_back({-1, -1, INF, -1});
		segt1.update(rt1[i + 1], rt1[i], 1, siz, zipy[i + 1], a[i + 1].fi + a[i + 1].se, i + 1);
		
		rt2[i] = (ll)segt2.seg.size();
		segt2.seg.push_back({-1, -1, INF, -1});
		segt2.update(rt2[i + 1], rt2[i], 1, siz, zipy[i + 1], a[i + 1].fi - a[i + 1].se, i + 1);
	}
	
	for(ll i = 1 ; i < n ; i++)
	{
		pll gap1 = segt1.query(rt1[i], 1, siz, zipy[i], siz);
		pll gap2 = segt2.query(rt2[i], 1, siz, 1, zipy[i]);
		
		gap1.fi -= (a[i].fi + a[i].se);
		gap2.fi -= (a[i].fi - a[i].se);
		gap1 = min(gap1, gap2);
		
		pq.push({-gap1.fi, {i, gap1.se}});
	}
	
	while(!pq.empty() && m)
	{
		pair<ll, pll> qq = pq.top();
		pq.pop();
		
		cout << -qq.fi en;
		m--;
		
		ll i = qq.se.fi;
		ll won = rt1[i], won2 = rt2[i];
		ll Y = zipy[qq.se.se];
		ll idx2 = upper_bound(sad[Y].begin(), sad[Y].end(), qq.se.se) - sad[Y].begin();
		ll V1 = 0, V2 = 0;
		
		if(idx2 >= (ll)sad[Y].size())
			V1 = INF, V2 = -1;
		
		else
		{
			ll w = sad[Y][idx2];
			V1 = a[w].fi + a[w].se, V2 = w;
		}
		
		rt1[i] = (ll)segt1.seg.size();
		segt1.seg.push_back({-1, -1, INF, -1});
		segt1.update(won, rt1[i], 1, siz, zipy[qq.se.se], V1, V2);
		
		if(idx2 >= (ll)sad[Y].size())
			V1 = INF, V2 = -1;
		
		else
		{
			ll w = sad[Y][idx2];
			V1 = a[w].fi - a[w].se, V2 = w;
		}
		
		rt2[i] = (ll)segt2.seg.size();
		segt2.seg.push_back({-1, -1, INF, -1});
		segt2.update(won2, rt2[i], 1, siz, zipy[qq.se.se], V1, V2);
		
		pll gap1 = segt1.query(rt1[i], 1, siz, zipy[i], siz);
		pll gap2 = segt2.query(rt2[i], 1, siz, 1, zipy[i]);
		
		gap1.fi -= (a[i].fi + a[i].se);
		gap2.fi -= (a[i].fi - a[i].se);
		
		gap1 = min(gap1, gap2);
		pq.push({-gap1.fi, {i, gap1.se}});
	}
	
	return 0;
}