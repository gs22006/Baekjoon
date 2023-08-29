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

ll n, K;
ll a[250010];
ll m;
ll all, bll, cll;

struct node
{
	ll gap, AND;
};

struct segtree
{
	node seg[1500010];
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
		{
			seg[no].AND = a[s];
			seg[no].gap = (a[s] == K);
			
			return;
		}
		
		init(no << 1, s, (s + e) >> 1);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e);
		
		seg[no].AND = (seg[no << 1].AND & seg[no << 1 | 1].AND);
		seg[no].gap = seg[no << 1].gap + seg[no << 1 | 1].gap;
	}
	
	void update(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r && (seg[no].AND & v) == v)
			return;
		
		if(s == e)
		{
			if(seg[no].AND == K)
				seg[no].gap = 0;
			
			seg[no].AND |= v;
			
			if(seg[no].AND == K)
				seg[no].gap = 1;
			
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, l, r, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, v);
		
		seg[no].AND = (seg[no << 1].AND & seg[no << 1 | 1].AND);
		seg[no].gap = seg[no << 1].gap + seg[no << 1 | 1].gap;
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no].gap;
		
		return query(no << 1, s, (s + e) >> 1, l, r) + query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	segt.init(1, 1, n);
	
	cin >> m;
	
	while(m--)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> all >> bll >> cll;
			segt.update(1, 1, n, all, bll, cll);
		}
		
		else
		{
			cin >> all >> bll;
			cout << segt.query(1, 1, n, all, bll) en;
		}
	}
	
	return 0;
}