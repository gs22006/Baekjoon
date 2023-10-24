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
ll all, bll;
ll idx[300010];
vector< pair<pll, pll> > qry1;
ll qry2[300010], qchk[300010];
ll ans[300010];
vector< vector< pair<ll, pll> > > hist;
vector< pair<ll, pll> > tmp;

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
			tmp.push_back({no, seg[no].line});
			seg[no].line = line2;
			return;
		}
		
		if(Y(line1, mid) < Y(line2, mid))
		{
			tmp.push_back({no, seg[no].line});
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
			tmp.push_back({no, seg[no].line});
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
	
	void rollback(void)
	{
		tmp = hist.back();
		hist.pop_back();
		
		for(auto &i : tmp)
			seg[i.fi].line = i.se;
	}
}lcht;

struct segtree
{
	vector<pll> seg[1200010];
	
	void update(ll no, ll s, ll e, ll l, ll r, pll L)
	{
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			seg[no].push_back(L);
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, l, r, L);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, L);
	}
	
	void dfs(ll no, ll s, ll e)
	{
		for(auto &i : seg[no])
		{
			tmp.clear();
			lcht.update(0, -1000000000, 1000000000, i);
			hist.push_back(tmp);
		}
		
		if(s == e)
		{
			if(qchk[s])
				ans[s] = lcht.query(0, -1000000000, 1000000000, qry2[s]);
			
			for(auto &i : seg[no])
				lcht.rollback();
			
			return;
		}
		
		dfs(no << 1, s, (s + e) >> 1);
		dfs(no << 1 | 1, ((s + e) >> 1) + 1, e);
		
		for(auto &i : seg[no])
			lcht.rollback();
	}
}segt;

int main(void)
{
	fastio
	
	lcht.init();
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> all >> bll;
			idx[i] = (ll)qry1.size();
			qry1.push_back({{all, bll}, {i, n}});
		}
		
		else if(all == 2)
		{
			cin >> all;
			qry1[idx[all]].se.se = i;
		}
		
		else
		{
			cin >> qry2[i];
			qchk[i] = 1;
		}
	}
	
	for(auto &i : qry1)
		segt.update(1, 1, n, i.se.fi, i.se.se, i.fi);
	
	segt.dfs(1, 1, n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(qchk[i])
		{
			if(ans[i] == -INF)
				cout << "EMPTY\n";
			else
				cout << ans[i] en;
		}
	}
	
	return 0;
}