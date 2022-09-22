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
ll all, bll, cll;

struct segtree_beats
{
	//max, min, sum
	ll seg[400010][3];
	ll lazy[400010][2];
	
	void prop(ll no, ll s, ll e)
	{
		if(!lazy[no][0] && lazy[no][1] == INF)
			return;
		
		if(lazy[no][1] == INF)
		{
			seg[no][0] += lazy[no][0];
			seg[no][1] += lazy[no][0];
			seg[no][2] += (e - s + 1) * lazy[no][0];
			
			if(s != e)
			{
				lazy[no * 2][0] += lazy[no][0];
				lazy[no * 2 + 1][0] += lazy[no][0];
			}
		}
		
		else
		{
			seg[no][0] = seg[no][1] = lazy[no][1] + lazy[no][0];
			seg[no][2] = (e - s + 1) * (lazy[no][1] + lazy[no][0]);
			
			if(s != e)
			{
				lazy[no * 2][0] = lazy[no * 2 + 1][0] = lazy[no][0];
				lazy[no * 2][1] = lazy[no * 2 + 1][1] = lazy[no][1];
			}
		}
		
		lazy[no][0] = 0;
		lazy[no][1] = INF;
	}
	
	void update1(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			lazy[no][0] = v;
			prop(no, s, e);
			
			return;
		}
		
		update1(no * 2, s, (s + e) / 2, l, r, v);
		update1(no * 2 + 1, (s + e) / 2 + 1, e, l, r, v);
		
		seg[no][0] = max(seg[no * 2][0], seg[no * 2 + 1][0]);
		seg[no][1] = min(seg[no * 2][1], seg[no * 2 + 1][1]);
		seg[no][2] = seg[no * 2][2] + seg[no * 2 + 1][2];
	}
	
	void update2(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			if(floor((ld)seg[no][0] / (ld)v) == floor((ld)seg[no][1] / (ld)v))
			{
				lazy[no][1] = floor((ld)seg[no][0] / (ld)v);
				prop(no, s, e);
				
				return;
			}
			
			if(seg[no][1] + 1 == seg[no][0])
			{
				lazy[no][0] = floor((ld)seg[no][1] / (ld)v) - seg[no][1];
				prop(no, s, e);
				
				return;
			}
		}
		
		update2(no * 2, s, (s + e) / 2, l, r, v);
		update2(no * 2 + 1, (s + e) / 2 + 1, e, l, r, v);
		
		seg[no][0] = max(seg[no * 2][0], seg[no * 2 + 1][0]);
		seg[no][1] = min(seg[no * 2][1], seg[no * 2 + 1][1]);
		seg[no][2] = seg[no * 2][2] + seg[no * 2 + 1][2];
	}
	
	ll query1(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return MAX;
		
		if(l <= s && e <= r)
			return seg[no][1];
		
		return min(query1(no * 2, s, (s + e) / 2, l, r), query1(no * 2 + 1, (s + e) / 2 + 1, e, l, r));
	}
	
	ll query2(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no][2];
		
		return query2(no * 2, s, (s + e) / 2, l, r) + query2(no * 2 + 1, (s + e) / 2 + 1, e, l, r);
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n >> q;
	
	for(ll i = 0 ; i < 400010 ; i++)
		segt.lazy[i][1] = INF;
	
	for(ll i = 0 ; i < n ; i++)
	{
		cin >> a[i];
		segt.update1(1, 0, n - 1, i, i, a[i]);
	}
	
	while(q--)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> all >> bll >> cll;
			segt.update1(1, 0, n - 1, all, bll, cll);
		}
		
		else if(all == 2)
		{
			cin >> all >> bll >> cll;
			segt.update2(1, 0, n - 1, all, bll, cll);
		}
		
		else if(all == 3)
		{
			cin >> all >> bll;
			cout << segt.query1(1, 0, n - 1, all, bll) en;
		}
		
		else if(all == 4)
		{
			cin >> all >> bll;
			cout << segt.query2(1, 0, n - 1, all, bll) en;
		}
	}
	
	return 0;
}