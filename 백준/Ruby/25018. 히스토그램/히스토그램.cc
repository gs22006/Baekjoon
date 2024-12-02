#include "histogram.h"
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
ll h[500001];
pll a[500001];
vector<ll> vec[500001];
ll cc;
vector<ll> ans;
ll dp[500001];
pll gu[500001];

struct segtree
{
	int seg[2000001];
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
		{
			seg[no] = s;
			return;
		}
		
		init(no << 1, s, (s + e) >> 1);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e);
		
		if(h[seg[no << 1]] < h[seg[no << 1 | 1]])
			seg[no] = seg[no << 1];
		else
			seg[no] = seg[no << 1 | 1];
	}
	
	int query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return -1;
		
		if(l <= s && e <= r)
			return seg[no];
		
		int L = query(no << 1, s, (s + e) >> 1, l, r);
		int R = query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
		
		if(L == -1)
			return R;
		
		if(R == -1)
			return L;
		
		if(h[L] < h[R])
			return L;
		
		return R;
	}
}segt;

struct line
{
	int A;
	ll B;
	ld S;
	
	bool operator < (const line &xx) const
	{
		return A > xx.A;
	}
};

line flin[1000010];
vector<int> S[2500010];

ld gyo(ll A1, ll B1, ll A2, ll B2)
{
	if(A1 == A2)
		assert(0);
	
	return (ld)(B2 - B1) / (ld)(A1 - A2);
}

int ININ;

struct RollbackCHT
{
	ll siz;
	pair<line, ll> lin[500010];
	line lin2[500010];
	pll his[500010];
	ll cc;
	
	void init(void)
	{
		cc = max(cc, siz);
		
		for(ll i = 0 ; i <= cc ; i++)
		{
			lin[i] = {{0, 0, 0}, 0};
			lin2[i] = {0, 0, 0};
			his[i] = {0, 0};
		}
		
		siz = cc = 0;
	}
	
	void update(ll X, ll Y)
	{
		cc++;
		
		if(siz == 0)
		{
			ININ = 1;
			his[cc] = {0, lin[0].se};
			lin2[cc] = {X, Y, INF};
			lin[0] = {{X, Y, INF}, cc};
			siz = 1;
			
			return;
		}
		
		if(lin[siz - 1].fi.A == X && lin[siz - 1].fi.B >= Y)
		{
			ININ = 0;
			return;
		}
		
		ININ = 1;
		
		ll l = 0, r = siz - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) / 2;
			
			if(lin[mid].fi.A == X)
			{
				if(lin[mid].fi.B >= Y)
					l = mid + 1;
				else
					r = mid - 1;
			}
			
			else
			{
				if(gyo(lin[mid].fi.A, lin[mid].fi.B, X, Y) >= lin[mid].fi.S)
					r = mid - 1;
				else
					l = mid + 1;
			}
		}
		
		ld gy = INF;
		
		if(l != 0)
			gy = gyo(lin[r].fi.A, lin[r].fi.B, X, Y);
		
		his[cc] = {siz, lin[l].se};
		lin2[cc] = {X, Y, gy};
		lin[l] = {lin2[cc], cc};
		siz = l + 1;
	}
	
	void update2(ll X, ll Y)
	{
		if(siz == 0)
		{
			lin[0] = {{X, Y, INF}, 0};
			siz = 1;
			return;
		}
		
		if(lin[siz - 1].fi.A == X && lin[siz - 1].fi.B >= Y)
			return;
		
		if(lin[siz - 1].fi.A == X && lin[siz - 1].fi.B < Y)
			siz--;
		
		while(siz - 1 >= 0)
		{
			if(gyo(lin[siz - 1].fi.A, lin[siz - 1].fi.B, X, Y) >= lin[siz - 1].fi.S)
			{
				lin[siz - 1] = {{0, 0, 0}, 0};
				siz--;
			}
			
			else
				break;
		}
		
		ld gy = INF;
		
		if(siz > 0)
			gy = gyo(lin[siz - 1].fi.A, lin[siz - 1].fi.B, X, Y);
		
		lin[siz] = {{X, Y, gy}, 0};
		siz++;
	}
	
	ll query(ll X)
	{
		ll l = 0, r = siz - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) / 2;
			
			if(X < lin[mid].fi.S)
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		return lin[r].fi.A * X + lin[r].fi.B;
	}
	
	void erase(void)
	{
		ll num = lin[siz - 1].se;
		
		lin[siz - 1].fi = lin2[his[num].se];
		lin[siz - 1].se = his[num].se;
		siz = his[num].fi;
	}
}cht, cht2;

void f(ll s, ll e, ll pa)
{
	if(s > e)
		return;
	
	cc++;
	
	ll w = segt.query(1, 1, n, s, e);
	
	gu[cc] = {s, e};
	a[cc].fi = e - s + 1;
	a[cc].se = h[w];
	
	if(pa)
		vec[pa].push_back(cc);
	
	ll tmp = cc;
	
	f(s, w - 1, tmp);
	f(w + 1, e, tmp);
}

void dfs0(ll here, ll pa)
{
	ll sum = 0;
	
	dp[here] = a[here].fi * a[here].se;
	
	for(auto &i : vec[here])
	{
		dfs0(i, here);
		
		dp[here] = max(dp[here], dp[i]);
		sum += dp[i];
	}
	
	ans[1] = max(ans[1], sum);
}

void dfs(ll here, ll pa)
{
	if(pa)
		ans[1] = max(ans[1], cht.query(a[here].fi) + a[here].fi * a[here].se);
	
	ll sad = 0;
	cht.update(-a[here].se, a[here].fi * a[here].se);
	sad = ININ;
	
	for(auto &i : vec[here])
		dfs(i, here);
	
	if(sad)
		cht.erase();
}

void dfs2(ll here, ll pa, ll maxx)
{
	if(pa && vec[here].size() >= 2)
		ans[2] = max(ans[2], dp[vec[here][0]] + dp[vec[here][1]] + maxx);
	
	if(cht.siz > 0)
		ans[2] = max(ans[2], cht.query(a[here].fi) + a[here].fi * a[here].se);
	
	ll sum = 0;
	
	for(auto &i : vec[here])
		sum += dp[i];
	
	for(auto &i : vec[here])
	{
		ll sad = 0;
		
		if(maxx > 0)
		{
			cht.update(-a[here].se, a[here].fi * a[here].se + maxx);
			sad = ININ;
		}
		
		dfs2(i, here, max(maxx, sum - dp[i]));
		
		if(maxx > 0 && sad)
			cht.erase();
	}
}

void dfs3(ll here, ll pa)
{
	ll ff = 0;
	ll sad1 = 0, sad2 = 0;
	
	if(cht2.siz > 0)
		ans[2] = max(ans[2], cht2.query(a[here].fi) + a[here].fi * a[here].se);
	
	if(cht.siz > 0)
	{
		ff = 1;
		cht2.update(-a[here].se, cht.query(a[here].fi) + a[here].fi * a[here].se);
		sad2 = ININ;
	}
	
	cht.update(-a[here].se, a[here].fi * a[here].se);
	sad1 = ININ;
	
	for(auto &i : vec[here])
		dfs3(i, here);
	
	if(sad1)
		cht.erase();
	
	if(ff && sad2)
		cht2.erase();
}

ll sum = 0;

void dfs5(ll no, ll s, ll e, ll w, ll v)
{
	if(w < s || e < w)
		return;
	
	S[no].push_back(v);
	
	if(s == e)
		return;
	
	dfs5(no << 1, s, (s + e) >> 1, w, v);
	dfs5(no << 1 | 1, ((s + e) >> 1) + 1, e, w, v);
}

void dfs4(ll no, ll s, ll e)
{
	if((ll)S[no].size() <= 1)
		return;
	
	ll mid = (s + e) >> 1;
	
	cht.init();
	cht2.init();
	
	for(auto &i : S[no])
	{
		if(gu[i].se <= mid)
			cht.update2(-a[i].fi, a[i].fi * a[i].se);
		else if(mid < gu[i].fi)
			cht2.update2(-a[i].fi, a[i].fi * a[i].se);
	}
	
	S[no].clear();
	
	ll p1 = cht.siz - 1;
	ll p2 = cht2.siz - 1;
	
	while(1)
	{
		if(p1 < 0 || p2 < 0)
			break;
		
		line tmp;
		
		tmp.A = cht.lin[p1].fi.A + cht2.lin[p2].fi.A;
		tmp.B = cht.lin[p1].fi.B + cht2.lin[p2].fi.B;
		
		if(cht.lin[p1].fi.S < cht2.lin[p2].fi.S)
		{
			tmp.S = cht.lin[p1].fi.S;
			p1--;
		}
		
		else
		{
			tmp.S = cht2.lin[p2].fi.S;
			p2--;
		}
		
		if(flin[-tmp.A].B == 0)
			flin[-tmp.A] = tmp;
		else if(flin[-tmp.A].B < tmp.B)
			flin[-tmp.A] = tmp;
	}
	
	if(mid < e)
		dfs4(no << 1, s, mid);
	
	if(s < mid + 1)
		dfs4(no << 1 | 1, mid + 1, e);
}

vector<ll> max_area(vector<int> H)
{
    n = (ll)H.size();
    
    for(ll i = 1 ; i <= n ; i++)
    	h[i] = H[i - 1];
    
    segt.init(1, 1, n);
    
    f(1, n, 0);
    
    ans.push_back(0);
    ans.push_back(0);
    ans.push_back(0);
    
    for(ll i = 1 ; i <= n ; i++)
    	ans[0] = max(ans[0], a[i].fi * a[i].se);
    
    dfs0(1, 0);
    
    cht.init();
    dfs(1, 0);
    
    ans[1] = max(ans[1], ans[0]);
    
    cht.init();
    dfs2(1, 0, 0);
    
    cht.init();
    cht2.init();
    dfs3(1, 0);
    
    vector< pair<line, ll> > SS;
    
    for(ll i = 1 ; i <= n ; i++)
    	SS.push_back({{-a[i].fi, a[i].fi * a[i].se, 0}, i});
    
    sort(SS.begin(), SS.end());
    
    for(auto &i : SS)
    {
    	dfs5(1, 1, n, gu[i.se].fi, i.se);
    	dfs5(1, 1, n, gu[i.se].se, i.se);
	}
    
	dfs4(1, 1, n);
    
    cht.init();
    
    for(ll i = 0 ; i <= 2 * n + 1 ; i++)
    {
    	if(flin[i].B)
    		cht.update2(flin[i].A, flin[i].B);
	}
	
	if(cht.siz > 0)
	{
		for(ll i = 1 ; i <= n ; i++)
			ans[2] = max(ans[2], cht.query(a[i].se) + a[i].fi * a[i].se);
	}
    
    ans[2] = max(ans[2], ans[1]);
    return ans;
}