#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 1987654321
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n, m;
ll a[500010];
vector<ll> vec[500010];
stack<ll> stk;
ll L[500010], R[500010];
ll gap;
char all;
ll bll, cll;

struct lazysegtree
{
	ll seg[2000010];
	ll lazy[2000010];
	
	void init(ll no, ll s, ll e, ll typ)
	{
		if(s == e)
		{
			seg[no] = (typ == 1 ? L[s] : R[s]);
			return;
		}
		
		init(no << 1, s, (s + e) >> 1, typ);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e, typ);
		seg[no] = max(seg[no << 1], seg[no << 1 | 1]);
	}
	
	void prop(ll no, ll s, ll e)
	{
		if(lazy[no])
			seg[no] = lazy[no];
		
		if(s != e && lazy[no])
		{
			lazy[no << 1] = lazy[no];
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
			lazy[no] = v;
			prop(no, s, e);
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, l, r, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, v);
		
		seg[no] = max(seg[no << 1], seg[no << 1 | 1]);
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return -INF;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return max(query(no << 1, s, (s + e) >> 1, l, r), query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r));
	}
}Lsegt, Rsegt;

struct segtree
{
	pll seg[2000010];
	
	void update(ll no, ll s, ll e, ll w, pll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no] = v;
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, w, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, w, v);
		
		seg[no] = max(seg[no << 1], seg[no << 1 | 1]);
	}
	
	pll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s || l > r)
			return {-INF, -1};
		
		if(l <= s && e <= r)
			return seg[no];
		
		return max(query(no << 1, s, (s + e) >> 1, l, r), query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r));
	}
	
	ll find_left(ll no, ll s, ll e, ll w, ll v)
	{
		if(w < s)
			return -1;
		
		if(s == e)
		{
			if(seg[no].fi < v)
				return -1;
			
			return s;
		}
		
		ll gap = -1;
		
		if(seg[no << 1 | 1].fi > v)
			gap = find_left(no << 1 | 1, ((s + e) >> 1) + 1, e, w, v);
		
		if(gap == -1)
			gap = find_left(no << 1, s, (s + e) >> 1, w, v);
		
		return gap;
	}
	
	ll find_right(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w)
			return -1;
		
		if(s == e)
		{
			if(seg[no].fi < v)
				return -1;
			
			return s;
		}
		
		ll gap = -1;
		
		if(seg[no << 1].fi > v)
			gap = find_right(no << 1, s, (s + e) >> 1, w, v);
		
		if(gap == -1)
			gap = find_right(no << 1 | 1, ((s + e) >> 1) + 1, e, w, v);
		
		return gap;
	}
}Hsegt;

void dfs(ll here)
{
	if(here & 1)
		R[here / 2] = gap;
	else
		L[here / 2] = gap;
	
	for(auto &i : vec[here])
		dfs(i);
}

ll DEG[500010];

void init(void)
{
	for(ll i = 1 ; i <= n ; i++)
	{
		while(!stk.empty() && a[i] > a[stk.top()])
		{
			DEG[stk.top() * 2 + 1]++;
			vec[i * 2].push_back(stk.top() * 2 + 1);
			stk.pop();
		}
		
		stk.push(i);
	}
	
	while(!stk.empty())
		stk.pop();
	
	for(ll i = n ; i >= 1 ; i--)
	{
		while(!stk.empty() && a[i] > a[stk.top()])
		{
			DEG[stk.top() * 2]++;
			vec[i * 2 + 1].push_back(stk.top() * 2);
			stk.pop();
		}
		
		stk.push(i);
	}
	
	for(ll i = 2 ; i <= n * 2 + 1 ; i++)
	{
		if(DEG[i])
			continue;
		
		if(i & 1)
		{
			if(!R[i / 2])
			{
				gap = i / 2;
				dfs(i);
			}
		}
		
		else
		{
			if(!L[i / 2])
			{
				gap = i / 2;
				dfs(i);
			}
		}
	}
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	init();
	
	Lsegt.init(1, 1, n, 1);
	Rsegt.init(1, 1, n, 2);
	
	for(ll i = 1 ; i <= n ; i++)
		Hsegt.update(1, 1, n, i, {a[i], i});
	
	while(m--)
	{
		cin >> all;
		
		if(all == 'L')
		{
			cin >> bll;
			cout << Lsegt.query(1, 1, n, bll, bll) en;
		}
		
		else if(all == 'R')
		{
			cin >> bll;
			cout << Rsegt.query(1, 1, n, bll, bll) en;
		}
		
		else
		{
			cin >> bll >> cll;
			
			ll l, r;
			pll w;
			ll gap;
			
			gap = Hsegt.find_left(1, 1, n, bll - 1, cll);
			
			if(gap == -1)
				gap = 0;
			
			if(gap == 0)
				L[bll] = bll;
			else
				L[bll] = Rsegt.query(1, 1, n, gap, gap);
			
			w = Hsegt.query(1, 1, n, gap + 1, bll - 1);
			
			if(w.se != -1)
			{
				if(w.se + 1 <= bll - 1)
				{
					Lsegt.update(1, 1, n, w.se + 1, bll - 1, L[bll]);
					Rsegt.update(1, 1, n, w.se, bll - 1, L[bll]);
				}
				
				else
					Rsegt.update(1, 1, n, w.se, w.se, L[bll]);
			}
			
			gap = Hsegt.find_right(1, 1, n, bll + 1, cll);
			
			if(gap == -1)
				gap = n + 1;
			
			if(gap == n + 1)
				R[bll] = bll;
			else
				R[bll] = Lsegt.query(1, 1, n, gap, gap);
			
			w = Hsegt.query(1, 1, n, bll + 1, gap - 1);
			
			if(w.se != -1)
			{
				if(bll + 1 <= w.se - 1)
				{
					Lsegt.update(1, 1, n, bll + 1, w.se, R[bll]);
					Rsegt.update(1, 1, n, bll + 1, w.se - 1, R[bll]);
				}
				
				else
					Lsegt.update(1, 1, n, w.se, w.se, R[bll]);
			}
			
			Lsegt.update(1, 1, n, bll, bll, L[bll]);
			Rsegt.update(1, 1, n, bll, bll, R[bll]);
			Hsegt.update(1, 1, n, bll, {cll, bll});
		}
	}
	
	return 0;
}