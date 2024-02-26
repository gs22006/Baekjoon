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
};

struct gujo
{
	ll l, r, idx;
	
	bool operator < (const gujo &xx) const
	{
		return l < xx.l;
	}
};

struct maxsegtree
{
	ll seg[400010];
	
	void init(ll no, ll s, ll e)
	{
		seg[no] = 0;
		
		if(s == e)
			return;
		
		init(no << 1, s, (s + e) >> 1);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e);
	}
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no] = max(seg[no], v);
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, w, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, w, v);
		
		seg[no] = max(seg[no << 1], seg[no << 1 | 1]);
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return -INF;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return max(query(no << 1, s, (s + e) >> 1, l, r), query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r));
	}
}mxsegt;

ll n, q;
ll a[100010];
ll L[100010], R[100010];
gujo qry[100010];
pair<pll, ll> LR[100010];
ll ans[100010];

struct lichaosegtree
{
	lichaotree seg[400010];
	
	void init(ll no, ll s, ll e)
	{
		seg[no].seg.clear();
		seg[no].init();
		
		if(s == e)
			return;
		
		init(no << 1, s, (s + e) >> 1);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e);
	}
	
	void update(ll no, ll s, ll e, ll w, pll v)
	{
		if(e < w || w < s)
			return;
		
		seg[no].update(0, 1, n, v);
		
		if(s == e)
			return;
		
		update(no << 1, s, (s + e) >> 1, w, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, w, v);
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r, ll X)
	{
		if(e < l || r < s)
			return -INF;
		
		if(l <= s && e <= r)
			return seg[no].query(0, 1, n, X);
		
		return max(query(no << 1, s, (s + e) >> 1, l, r, X), query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, X));
	}
}segt;

void find_right(void)
{
	stack<pll> stk;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(!stk.empty())
		{
			if(stk.top().fi > a[i])
			{
				R[stk.top().se] = i - 1;
				stk.pop();
			}
			
			else
				break;
		}
		
		stk.push({a[i], i});
	}
	
	while(!stk.empty())
	{
		R[stk.top().se] = n;
		stk.pop();
	}
}

void find_left(void)
{
	stack<pll> stk;
	
	for(ll i = n ; i >= 1 ; i--)
	{
		while(!stk.empty())
		{
			if(stk.top().fi > a[i])
			{
				L[stk.top().se] = i + 1;
				stk.pop();
			}
			
			else
				break;
		}
		
		stk.push({a[i], i});
	}
	
	while(!stk.empty())
	{
		L[stk.top().se] = 1;
		stk.pop();
	}
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	find_left();
	find_right();
	
	for(ll i = 1 ; i <= n ; i++)
		LR[i] = {{L[i], R[i]}, i};
	
	sort(LR + 1, LR + 1 + n);
	
	cin >> q;
	
	for(ll i = 1 ; i <= q ; i++)
	{
		cin >> qry[i].l >> qry[i].r;
		qry[i].idx = i;
	}
	
	sort(qry + 1, qry + 1 + q);
	
	mxsegt.init(1, 1, n);
	segt.init(1, 1, n);
	
	ll p = 1;
	
	for(ll i = 1 ; i <= q ; i++)
	{
		while(p <= n && LR[p].fi.fi <= qry[i].l)
		{
			segt.update(1, 1, n, LR[p].fi.se, {-a[LR[p].se], (LR[p].fi.se + 1) * a[LR[p].se]});
			mxsegt.update(1, 1, n, LR[p].fi.se, a[LR[p].se]);
			p++;
		}
		
		ans[qry[i].idx] = max(ans[qry[i].idx], mxsegt.query(1, 1, n, qry[i].r, n) * (qry[i].r - qry[i].l + 1));
		ans[qry[i].idx] = max(ans[qry[i].idx], segt.query(1, 1, n, qry[i].l, qry[i].r, qry[i].l));
	}
	
	mxsegt.init(1, 1, n);
	segt.init(1, 1, n);
	
	reverse(LR + 1, LR + 1 + n);
	reverse(qry + 1, qry + 1 + q);
	
	p = 1;
	
	for(ll i = 1 ; i <= q ; i++)
	{
		while(p <= n && LR[p].fi.fi >= qry[i].l)
		{
			segt.update(1, 1, n, LR[p].fi.se, {a[LR[p].se], (1 - LR[p].fi.fi) * a[LR[p].se]});
			mxsegt.update(1, 1, n, LR[p].fi.se, a[LR[p].se] * (LR[p].fi.se - LR[p].fi.fi + 1));
			p++;
		}
		
		ans[qry[i].idx] = max(ans[qry[i].idx], mxsegt.query(1, 1, n, qry[i].l, qry[i].r));
		ans[qry[i].idx] = max(ans[qry[i].idx], segt.query(1, 1, n, qry[i].r, n, qry[i].r));
	}
	
	for(ll i = 1 ; i <= q ; i++)
		cout << ans[i] en;
	
	return 0;
}