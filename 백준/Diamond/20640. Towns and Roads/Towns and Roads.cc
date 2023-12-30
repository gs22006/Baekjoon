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
ll all, bll, cll;
map<pll, ll> mp;
vector<ll> vec[200010];
ll IN[200010], OUT[200010];
pll edg[200010];
ll dist[200010];
ll yuk[200010];
ll cc;
ll q;
ll now;

void dfs(ll here, ll pa)
{
	IN[here] = ++cc;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dist[i] = dist[here] + mp[{here, i}];
		dfs(i, here);
	}
	
	OUT[here] = cc;
}

struct segtree
{
	pll seg[1000010];
	ll lazy[1000010];
	
	void init(ll no, ll s, ll e)
	{
		seg[no] = {0, s};
		
		if(s == e)
			return;
		
		init(no << 1, s, (s + e) >> 1);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e);
	}
	
	void prop(ll no, ll s, ll e)
	{
		seg[no].fi += lazy[no];
		
		if(s != e)
		{
			lazy[no << 1] += lazy[no];
			lazy[no << 1 | 1] += lazy[no];
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
			seg[no].fi += v;
			
			if(s != e)
			{
				lazy[no << 1] += v;
				lazy[no << 1 | 1] += v;
			}
			
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, l, r, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, v);
		
		seg[no] = max(seg[no << 1], seg[no << 1 | 1]);
	}
	
	pll query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return {-INF, -INF};
		
		if(l <= s && e <= r)
			return seg[no];
		
		pll L = query(no << 1, s, (s + e) >> 1, l, r);
		pll R = query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
		
		return max(L, R);
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll >> cll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
		mp[{all, bll}] = mp[{bll, all}] = cll;
		edg[i] = {all, bll};
	}
	
	dfs(1, 0);
	
	segt.init(1, 1, n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		segt.update(1, 1, n, IN[i], IN[i], dist[i]);
		yuk[IN[i]] = i;
	}
	
	now = 1;
	
	cin >> q;
	
	ll boo = q;
	
	while(q--)
	{
		cin >> all >> bll;
		
		if(all == 1)
		{
			ll U = now, V = bll, D = mp[{now, bll}];
			
			if(dist[U] < dist[V])
			{
				segt.update(1, 1, n, IN[V], OUT[V], -D * 2);
				segt.update(1, 1, n, 1, n, D);
			}
			
			else
			{
				segt.update(1, 1, n, IN[U], OUT[U], D * 2);
				segt.update(1, 1, n, 1, n, -D);
			}
			
			now = bll;
		}
		
		else if(all == 2)
		{
			ll U = edg[bll].fi, V = edg[bll].se;
			
			if(dist[U] > dist[V])
				swap(U, V);
			
			if(IN[V] <= IN[now] && OUT[now] <= OUT[V])
			{
				segt.update(1, 1, n, 1, n, -INF / boo);
				segt.update(1, 1, n, IN[V], OUT[V], INF / boo);
			}
			
			else
				segt.update(1, 1, n, IN[V], OUT[V], -INF / boo);
		}
		
		else
		{
			ll U = edg[bll].fi, V = edg[bll].se;
			
			if(dist[U] > dist[V])
				swap(U, V);
			
			if(IN[V] <= IN[now] && OUT[now] <= OUT[V])
			{
				segt.update(1, 1, n, 1, n, INF / boo);
				segt.update(1, 1, n, IN[V], OUT[V], -INF / boo);
			}
			
			else
				segt.update(1, 1, n, IN[V], OUT[V], INF / boo);
		}
		
		pll maxx = segt.query(1, 1, n, 1, n);
		vector<pll> ans;
		pll tmp = maxx;
		
		while(1)
		{
			if(tmp.fi != maxx.fi)
				break;
			
			ans.push_back(tmp);
			segt.update(1, 1, n, tmp.se, tmp.se, -INF / boo);
			tmp = segt.query(1, 1, n, 1, n);
		}
		
		vector<ll> sad;
		
		for(auto &i : ans)
		{
			segt.update(1, 1, n, i.se, i.se, INF / boo);
			sad.push_back(yuk[i.se]);
		}
		
		sort(sad.begin(), sad.end());
		
		cout << (ll)sad.size() sp;
		
		for(auto &i : sad)
			cout << i sp;
		
		cout en;
	}
	
	return 0;
}