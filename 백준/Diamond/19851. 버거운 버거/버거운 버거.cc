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
char a[1000010];
ll q;
ll all, bll, cll;

struct segtree
{
	ll seg[4000010][3];
	ll lazy[4000010];
	
	void merge(ll no)
	{
		seg[no][0] = seg[no << 1][0] + seg[no << 1 | 1][0];
		seg[no][1] = min(seg[no << 1][1], seg[no << 1][0] + seg[no << 1 | 1][1]);
		seg[no][2] = max(seg[no << 1][2], seg[no << 1][0] + seg[no << 1 | 1][2]);
	}
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
		{
			if(a[s - 1] == '(')
			{
				seg[no][0] = 1;
				seg[no][1] = 0;
				seg[no][2] = 1;
			}
			
			else
			{
				seg[no][0] = -1;
				seg[no][1] = -1;
				seg[no][2] = 0;
			}
			
			return;
		}
		
		init(no << 1, s, (s + e) >> 1);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e);
		merge(no);
	}
	
	void prop(ll no, ll s, ll e)
	{
		if(lazy[no])
		{
			seg[no][0] *= -1;
			seg[no][1] *= -1;
			seg[no][2] *= -1;
			swap(seg[no][1], seg[no][2]);
		}
		
		if(s != e)
		{
			lazy[no << 1] ^= lazy[no];
			lazy[no << 1 | 1] ^= lazy[no];
		}
		
		lazy[no] = 0;
	}
	
	void update(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			seg[no][0] *= -1;
			seg[no][1] *= -1;
			seg[no][2] *= -1;
			swap(seg[no][1], seg[no][2]);
			
			if(s != e)
			{
				lazy[no << 1] ^= 1;
				lazy[no << 1 | 1] ^= 1;
			}
			
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, l, r);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
		merge(no);
	}
	
	pair<ll, pll> query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return {0, {0, 0}};
		
		if(l <= s && e <= r)
			return {seg[no][0], {seg[no][1], seg[no][2]}};
		
		pair<ll, pll> L = query(no << 1, s, (s + e) >> 1, l, r);
		pair<ll, pll> R = query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
		pair<ll, pll> ret;
		
		ret.fi = L.fi + R.fi;
		ret.se.fi = min(L.se.fi, L.fi + R.se.fi);
		ret.se.se = max(L.se.se, L.fi + R.se.se);
		
		return ret;
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n;
	cin >> a;
	cin >> q;
	
	segt.init(1, 1, n);
	
	while(q--)
	{
		cin >> all >> bll >> cll;
		
		if(all == 1)
			segt.update(1, 1, n, bll, cll);
		
		else
		{
			pair<ll, pll> gap = segt.query(1, 1, n, bll, cll);
			ll ans = cll - bll + 1 + abs(gap.se.fi) + abs(gap.fi - gap.se.fi);
			
			cout << ans en;
		}
	}
	
	return 0;
}