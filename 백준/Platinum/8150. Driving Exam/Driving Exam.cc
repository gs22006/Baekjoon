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

ll n, m, P, K;
vector<pll> vec[100010];
ll all, bll, cll;
ll L[100010], R[100010];
ll p;
ll ans;

struct segtree
{
	ll seg[500010];
	
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
			return MIN;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return max(query(no << 1, s, (s + e) >> 1, l, r), query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r));
	}
}segt;

struct segtree2
{
	ll seg[500010];
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no] += v;
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, w, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, w, v);
		
		seg[no] = seg[no << 1] + seg[no << 1 | 1];
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return query(no << 1, s, (s + e) >> 1, l, r) + query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
	}
}segt2;

int main(void)
{
	fastio
	
	cin >> n >> m >> P >> K;
	
	for(ll i = 1 ; i <= P ; i++)
	{
		cin >> all >> bll >> cll;
		
		if(cll == 0)
			vec[all].push_back({bll, cll});
		else
			vec[all + 1].push_back({bll, cll});
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		vector<ll> tmp;
		
		for(auto &k : vec[i])
		{
			if(k.se == 1)
				tmp.push_back(segt.query(1, 0, m, k.fi, m) + 1);
		}
		
		ll cc = 0;
		L[i] = L[i - 1];
		
		for(auto &k : vec[i])
		{
			if(k.se == 1)
			{
				L[i] = max(L[i], tmp[cc]);
				segt.update(1, 0, m, k.fi, tmp[cc++]);
			}
		}
	}
	
	segt.init(1, 0, m);
	
	for(ll i = n ; i >= 1 ; i--)
	{
		vector<ll> tmp;
		
		for(auto &k : vec[i])
		{
			if(k.se == 0)
				tmp.push_back(segt.query(1, 0, m, k.fi, m) + 1);
		}
		
		ll cc = 0;
		R[i] = R[i + 1];
		
		for(auto &k : vec[i])
		{
			if(k.se == 0)
			{
				R[i] = max(R[i], tmp[cc]);
				segt.update(1, 0, m, k.fi, tmp[cc++]);
			}
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if((n - i - R[i]) + (i - 1 - L[i]) == 0)
			segt2.update(1, 1, n, i, 1);
	}
	
	p = 1;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(p <= n && (n - i - R[i]) + (p - 1 - L[p]) <= K)
			p++;
		
		ans = max(ans, p - i - segt2.query(1, 1, n, i, p - 1));
	}
	
	cout << ans;
	return 0;
}