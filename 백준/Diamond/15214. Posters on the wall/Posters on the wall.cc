#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<lll, lll> pll;
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

struct gujo
{
	lll X, Y, A, B, C, D;
	
	bool operator < (const gujo &xx) const
	{
		return X < xx.X;
	}
};

ll r, c, n, q, m;
vector<gujo> upd;
vector<lll> zip;
ll all, bll, cll, dll, ell;
lll LL;
lll rt[5000010];
lll x[5000010];
ll cc;
ll siz;

struct node
{
	ll L, R;
	pair<pll, pll> gap;
};

struct persistentsegtree
{
	vector<node> seg;
	
	void new_node(void)
	{
		seg.push_back({-1, -1, {{0, 0}, {0, 0}}});
	}
	
	void init(lll no, lll s, lll e)
	{
		if(s == e)
			return;
		
		seg[no].L = (ll)seg.size();
		new_node();
		seg[no].R = (ll)seg.size();
		new_node();
		
		init(seg[no].L, s, (s + e) >> 1);
		init(seg[no].R, ((s + e) >> 1) + 1, e);
	}
	
	void update(lll no, lll last, lll s, lll e, lll w, pair<pll, pll> v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no].gap.fi.fi = seg[last].gap.fi.fi + v.fi.fi;
			seg[no].gap.fi.se = seg[last].gap.fi.se + v.fi.se;
			seg[no].gap.se.fi = seg[last].gap.se.fi + v.se.fi;
			seg[no].gap.se.se = seg[last].gap.se.se + v.se.se;
			
			return;
		}
		
		lll mid = (s + e) >> 1;
		
		if(s <= w && w <= mid)
		{
			if(seg[no].L == -1)
			{
				seg[no].L = (ll)seg.size();
				new_node();
			}
			
			seg[no].R = seg[last].R;
			update(seg[no].L, seg[last].L, s, mid, w, v);
		}
		
		else
		{
			if(seg[no].R == -1)
			{
				seg[no].R = (ll)seg.size();
				new_node();
			}
			
			seg[no].L = seg[last].L;
			update(seg[no].R, seg[last].R, mid + 1, e, w, v);
		}
		
		seg[no].gap.fi.fi = seg[seg[no].L].gap.fi.fi;
		seg[no].gap.fi.se = seg[seg[no].L].gap.fi.se;
		seg[no].gap.se.fi = seg[seg[no].L].gap.se.fi;
		seg[no].gap.se.se = seg[seg[no].L].gap.se.se;
		
		seg[no].gap.fi.fi += seg[seg[no].R].gap.fi.fi;
		seg[no].gap.fi.se += seg[seg[no].R].gap.fi.se;
		seg[no].gap.se.fi += seg[seg[no].R].gap.se.fi;
		seg[no].gap.se.se += seg[seg[no].R].gap.se.se;
	}
	
	pair<pll, pll> query(lll no, lll s, lll e, lll l, lll r)
	{
		if(e < l || r < s || l > r)
			return {{0, 0}, {0, 0}};
		
		if(l <= s && e <= r)
			return seg[no].gap;
		
		pair<pll, pll> ret;
		
		ret = {{0, 0}, {0, 0}};
		
		if(seg[no].L != -1)
		{
			pair<pll, pll> tmp = query(seg[no].L, s, (s + e) >> 1, l, r);
			
			ret.fi.fi += tmp.fi.fi;
			ret.fi.se += tmp.fi.se;
			ret.se.fi += tmp.se.fi;
			ret.se.se += tmp.se.se;
		}
		
		if(seg[no].R != -1)
		{
			pair<pll, pll> tmp = query(seg[no].R, ((s + e) >> 1) + 1, e, l, r);
			
			ret.fi.fi += tmp.fi.fi;
			ret.fi.se += tmp.fi.se;
			ret.se.fi += tmp.se.fi;
			ret.se.se += tmp.se.se;
		}
		
		return ret;
	}
}segt;

void update(lll W, lll A, lll B, lll C, lll D)
{
	segt.update(rt[cc], rt[cc - 1], 1, siz, W, {{A * C, A * D}, {B * C, B * D}});
}

lll num(lll X)
{
	return lower_bound(zip.begin(), zip.end(), X) - zip.begin() + 1;
}

lll query(lll X, lll Y)
{
	lll real_X = 0;
	lll real_Y = upper_bound(zip.begin(), zip.end(), Y) - zip.begin();
	
	lll l = 0, r = cc;
	
	while(l <= r)
	{
		ll mid = (l + r) >> 1;
		
		if(x[mid] <= X)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	real_X = r;
	
	if(real_X <= 0)
		return 0;
	
	pair<pll, pll> gye = segt.query(rt[real_X], 1, siz, 1, real_Y);
	lll ret = (lll)gye.fi.fi * X * Y + (lll)gye.fi.se * X + (lll)gye.se.fi * Y + (lll)gye.se.se;
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> r >> c >> n >> q >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all >> cll >> bll >> dll;
		
		if(all > bll)
			swap(all, bll);
		
		if(cll > dll)
			swap(cll, dll);
		
		all++, cll++;
		
		zip.push_back(all);
		zip.push_back(bll);
		zip.push_back(cll);
		zip.push_back(dll);
		upd.push_back({all, cll, 1, -(all - 1), 1, -(cll - 1)});
		upd.push_back({all, dll, 1, -(all - 1), -1, dll});
		upd.push_back({bll, cll, -1, bll, 1, -(cll - 1)});
		upd.push_back({bll, dll, 1, -bll, 1, -dll});
	}
	
	zip.push_back(-1);
	compress(zip);
	sort(upd.begin(), upd.end());
	
	siz = (ll)zip.size();
	segt.new_node();
	segt.init(0, 1, siz);
	x[0] = 0, rt[0] = 0;
	
	for(ll i = 0 ; i < (ll)upd.size() ; i++)
	{
		cc++;
		x[cc] = upd[i].X;
		rt[cc] = (ll)segt.seg.size();
		segt.new_node();
		
		update(num(upd[i].Y), upd[i].A, upd[i].B, upd[i].C, upd[i].D);
	}
	
	while(q--)
	{
		cin >> all >> cll >> bll >> dll >> ell;
		
		all = (all + LL * ell % m) % m;
		bll = (bll + LL * ell % m) % m;
		cll = (cll + LL * ell % m) % m;
		dll = (dll + LL * ell % m) % m;
		
		if(all > bll)
			swap(all, bll);
		
		if(cll > dll)
			swap(cll, dll);
		
		all++, cll++;
		
		LL = query(bll, dll) - query(bll, cll - 1) - query(all - 1, dll) + query(all - 1, cll - 1);
		cout << (ll)LL en;
	}
	
	return 0;
}