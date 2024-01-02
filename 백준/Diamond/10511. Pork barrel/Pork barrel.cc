#include <bits/stdc++.h>

using namespace std;
typedef int ll;
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

ll t;
ll n, m;
ll all, bll, cll;
vector< pair<ll, pll> > edg;
vector<pll> vec[1010];
ll q;
ll pa[1010], ra[1010];
ll rt[500010];

ll ffind(ll here)
{
	if(here == pa[here])
		return here;
	
	return pa[here] = ffind(pa[here]);
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	if(X == Y)
		return;
	
	if(ra[X] < ra[Y])
		pa[X] = Y;
	else if(ra[Y] < ra[X])
		pa[Y] = X;
	
	else
	{
		pa[X] = Y;
		ra[Y]++;
	}
}

struct node
{
	ll L, R, gap;
};

struct persistentsegtree
{
	vector<node> seg;
	
	void init(ll no, ll s, ll e)
	{
		seg[no] = {-1, -1, 0};
		
		if(s == e)
			return;
		
		if(seg[no].L == -1)
		{
			seg[no].L = (ll)seg.size();
			seg.push_back({-1, -1, 0});
		}
		
		if(seg[no].R == -1)
		{
			seg[no].R = (ll)seg.size();
			seg.push_back({-1, -1, 0});
		}
		
		init(seg[no].L, s, (s + e) >> 1);
		init(seg[no].R, ((s + e) >> 1) + 1, e);
	}
	
	void update(ll no, ll last, ll s, ll e, ll w, ll v)
	{
		if(s == e)
		{
			seg[no].gap = seg[last].gap + v;
			return;
		}
		
		ll mid = (s + e) >> 1;
		
		if(s <= w && w <= mid)
		{
			seg[no].R = seg[last].R;
			
			if(seg[no].L == -1)
			{
				seg[no].L = (ll)seg.size();
				seg.push_back({-1, -1, 0});
			}
			
			update(seg[no].L, seg[last].L, s, mid, w, v);
		}
		
		else
		{
			seg[no].L = seg[last].L;
			
			if(seg[no].R == -1)
			{
				seg[no].R = (ll)seg.size();
				seg.push_back({-1, -1, 0});
			}
			
			update(seg[no].R, seg[last].R, mid + 1, e, w, v);
		}
		
		seg[no].gap = 0;
		
		if(seg[no].L != -1)
			seg[no].gap += seg[seg[no].L].gap;
		
		if(seg[no].R != -1)
			seg[no].gap += seg[seg[no].R].gap;
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no].gap;
		
		ll L = 0, R = 0;
		
		if(seg[no].L != -1)
			L = query(seg[no].L, s, (s + e) >> 1, l, r);
		
		if(seg[no].R != -1)
			R = query(seg[no].R, ((s + e) >> 1) + 1, e, l, r);
		
		return L + R;
	}
}segt;

ll U, V;
pair<ll, pll> gapp;
ll idx1[1000010], idx2[1000010];
ll chk[1000010];

void dfs2(ll here, ll pa, ll maxx, ll ans1, ll ans2)
{
	if(here == V)
	{
		gapp = {maxx, {ans1, ans2}};
		return;
	}
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		if(maxx < i.se)
			dfs2(i.fi, here, i.se, here, i.fi);
		else
			dfs2(i.fi, here, maxx, ans1, ans2);
	}
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		ll cc = 0;
		
		segt.seg.clear();
		segt.seg.push_back({-1, -1, 0});
		rt[cc++] = 0;
		segt.init(0, 1, 1000000);
		
		cin >> n >> m;
		
		for(ll i = 1 ; i <= n ; i++)
			pa[i] = i, ra[i] = 0;
		
		for(ll i = 1 ; i <= m ; i++)
		{
			cin >> all >> bll >> cll;
			edg.push_back({cll, {all, bll}});
		}
		
		sort(edg.begin(), edg.end());
		reverse(edg.begin(), edg.end());
		
		vector<pll> vv;
		
		for(auto &i : edg)
		{
			U = i.se.fi, V = i.se.se;
			
			if(ffind(U) != ffind(V))
			{
				uunion(U, V);
				rt[cc++] = (ll)segt.seg.size();
				segt.seg.push_back({-1, -1, 0});
				segt.update(rt[cc - 1], rt[cc - 2], 1, 1000000, i.fi, i.fi);
				vec[U].push_back({V, i.fi});
				vec[V].push_back({U, i.fi});
			}
			
			else
			{
				dfs2(U, 0, 0, 0, 0);
				
				ll U2 = gapp.se.fi, V2 = gapp.se.se;
				
				for(ll i = 0 ; i < (ll)vec[U2].size() ; i++)
				{
					if(vec[U2][i].fi == V2)
					{
						vec[U2].erase(vec[U2].begin() + i);
						break;
					}
				}
				
				for(ll i = 0 ; i < (ll)vec[V2].size() ; i++)
				{
					if(vec[V2][i].fi == U2)
					{
						vec[V2].erase(vec[V2].begin() + i);
						break;
					}
				}
				
				rt[cc++] = (ll)segt.seg.size();
				segt.seg.push_back({-1, -1, 0});
				segt.update(rt[cc - 1], rt[cc - 2], 1, 1000000, gapp.fi, -gapp.fi);
				
				rt[cc++] = (ll)segt.seg.size();
				segt.seg.push_back({-1, -1, 0});
				segt.update(rt[cc - 1], rt[cc - 2], 1, 1000000, i.fi, i.fi);
				
				vec[U].push_back({V, i.fi});
				vec[V].push_back({U, i.fi});
			}
			
			vv.push_back({i.fi, cc - 1});
		}
		
		ll last = 0;
		
		cin >> q;
		
		while(q--)
		{
			cin >> all >> bll;
			
			all -= last, bll -= last;
			
			ll l = 0, r = (ll)vv.size() - 1;
			
			while(l <= r)
			{
				ll mid = (l + r) >> 1;
				
				if(vv[mid].fi >= all)
					l = mid + 1;
				else
					r = mid - 1;
			}
			
			if(r == -1)
			{
				last = 0;
				cout << 0 en;
				continue;
			}
			
			last = segt.query(rt[vv[r].se], 1, 1000000, all, bll);
			
			cout << last en;
		}
		
		edg.clear();
		
		for(ll i = 1 ; i <= n ; i++)
			vec[i].clear();
	}
	
	return 0;
}