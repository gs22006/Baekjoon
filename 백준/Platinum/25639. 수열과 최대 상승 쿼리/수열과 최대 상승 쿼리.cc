#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

ll n;
ll a[100010];
ll q;
ll all, bll;

struct segtree
{
	ll seg[400010][3];
	
	void merge(ll no)
	{
		seg[no][0] = max(max(seg[no * 2][0], seg[no * 2 + 1][0]), seg[no * 2 + 1][2] - seg[no * 2][1]);
		seg[no][1] = min(seg[no * 2][1], seg[no * 2 + 1][1]);
		seg[no][2] = max(seg[no * 2][2], seg[no * 2 + 1][2]);
	}
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
		{
			seg[no][0] = 0;
			seg[no][1] = a[s];
			seg[no][2] = a[s];
			
			return;
		}
		
		init(no * 2, s, (s + e) / 2);
		init(no * 2 + 1, (s + e) / 2 + 1, e);
		
		merge(no);
	}
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no][0] = 0;
			seg[no][1] = v;
			seg[no][2] = v;
			
			return;
		}
		
		update(no * 2, s, (s + e) / 2, w, v);
		update(no * 2 + 1, (s + e) / 2 + 1, e, w, v);
		
		merge(no);
	}
	
	pair<ll, pair<ll, ll> > query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return {-INF, {INF, -INF}};
		
		if(l <= s && e <= r)
			return {seg[no][0], {seg[no][1], seg[no][2]}};
		
		pair<ll, pair<ll, ll> > L = query(no * 2, s, (s + e) / 2, l, r);
		pair<ll, pair<ll, ll> > R = query(no * 2 + 1, (s + e) / 2 + 1, e, l, r);
		pair<ll, pair<ll, ll> > ret;
		
		ret.fi = max(max(L.fi, R.fi), R.se.se - L.se.fi);
		ret.se.fi = min(L.se.fi, R.se.fi);
		ret.se.se = max(L.se.se, R.se.se);
		
		return ret;
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	segt.init(1, 1, n);
	
	cin >> q;
	
	while(q--)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> all >> bll;
			segt.update(1, 1, n, all, bll);
		}
		
		else
		{
			cin >> all >> bll;
			cout << segt.query(1, 1, n, all, bll).fi en;
		}
	}
	
	return 0;
}