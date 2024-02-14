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

struct gujo
{
	ll L, R, X, Y, V;
};

ll n, q;
ll all, bll, cll;
map<pll, pll> mp;
pll qry[100010];
vector<gujo> edg;
vector<gujo> seg[400010];
ll ans[100010];

struct unionfind
{
	ll pa[100010], ra[100010];
	stack< pair<ll, pll> > stk;
	
	void init(void)
	{
		for(ll i = 1 ; i <= n ; i++)
			pa[i] = i, ra[i] = 0;
		
		while(!stk.empty())
			stk.pop();
	}
	
	ll ffind(ll here)
	{
		if(here == pa[here])
			return here;
		
		return ffind(pa[here]);
	}
	
	void uunion(ll X, ll Y)
	{
		X = ffind(X);
		Y = ffind(Y);
		
		if(X == Y)
		{
			stk.push({-1, {X, Y}});
			return;
		}
		
		if(ra[X] < ra[Y])
		{
			pa[X] = Y;
			stk.push({0, {X, Y}});
		}
		
		else if(ra[X] > ra[Y])
		{
			pa[Y] = X;
			stk.push({0, {Y, X}});
		}
		
		else
		{
			pa[X] = Y;
			ra[Y]++;
			stk.push({1, {X, Y}});
		}
	}
	
	void rollback(void)
	{
		if(stk.empty())
			assert(0);
		
		pair<ll, pll> tp = stk.top();
		stk.pop();
		
		if(tp.fi == -1)
			return;
		
		pa[tp.se.fi] = tp.se.fi;
		ra[tp.se.se] -= tp.fi;
	}
}uf[11];

void update(ll no, ll s, ll e, ll l, ll r, gujo E)
{
	if(e < l || r < s)
		return;
	
	if(l <= s && e <= r)
	{
		seg[no].push_back(E);
		return;
	}
	
	update(no << 1, s, (s + e) >> 1, l, r, E);
	update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, E);
}

void dfs(ll no, ll s, ll e)
{
	for(auto &i : seg[no])
	{
		for(ll j = i.V ; j <= 9 ; j++)
			uf[j].uunion(i.X, i.Y);
	}
	
	if(s == e)
	{
		if(qry[s].fi)
		{
			ll l = 0, r = 9;
			
			while(l <= r)
			{
				ll mid = (l + r) >> 1;
				
				if(uf[mid].ffind(qry[s].fi) != uf[mid].ffind(qry[s].se))
					l = mid + 1;
				else
					r = mid - 1;
			}
			
			if(l == 10)
				ans[s] = -1;
			else
				ans[s] = l;
		}
		
		for(auto &i : seg[no])
		{
			for(ll j = i.V ; j <= 9 ; j++)
				uf[j].rollback();
		}
		
		return;
	}
	
	dfs(no << 1, s, (s + e) >> 1);
	dfs(no << 1 | 1, ((s + e) >> 1) + 1, e);
	
	for(auto &i : seg[no])
	{
		for(ll j = i.V ; j <= 9 ; j++)
			uf[j].rollback();
	}
}

int main(void)
{
	fastio
	
	cin >> n >> q;
	
	for(ll i = 1 ; i <= q ; i++)
	{
		cin >> all;
		
		if(all == 0)
		{
			cin >> all >> bll >> cll;
			
			all++, bll++;
			mp[{all, bll}] = {i, cll};
		}
		
		else if(all == 1)
		{
			cin >> all >> bll;
			
			all++, bll++;
			
			if(mp.find({all, bll}) == mp.end())
				swap(all, bll);
			
			edg.push_back({mp[{all, bll}].fi, i, all, bll, mp[{all, bll}].se});
			mp.erase({all, bll});
		}
		
		else
		{
			cin >> all >> bll;
			
			all++, bll++;
			qry[i] = {all, bll};
		}
	}
	
	for(auto &i : mp)
		edg.push_back({i.se.fi, q + 1, i.fi.fi, i.fi.se, i.se.se});
	
	q++;
	
	for(ll i = 0 ; i < 10 ; i++)
		uf[i].init();
	
	for(auto &i : edg)
		update(1, 1, q, i.L, i.R, i);
	
	dfs(1, 1, q);
	
	for(ll i = 1 ; i <= q ; i++)
	{
		if(qry[i].fi)
			cout << ans[i] en;
	}
	
	return 0;
}