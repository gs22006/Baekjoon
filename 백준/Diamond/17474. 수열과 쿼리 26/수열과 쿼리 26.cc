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
ll a[1000010];
ll q;
ll all, bll, cll;

struct segtree_beats
{
	//max, max2, sum, gaet
	ll seg[4000010][4];
	
	void prop(ll no, ll s, ll e)
	{
		if(s == e)
			return;
		
		if(seg[no * 2][0] > seg[no][0])
		{
			seg[no * 2][2] -= seg[no * 2][3] * (seg[no * 2][0] - seg[no][0]);
			seg[no * 2][0] = seg[no][0];
		}
		
		if(seg[no * 2 + 1][0] > seg[no][0])
		{
			seg[no * 2 + 1][2] -= seg[no * 2 + 1][3] * (seg[no * 2 + 1][0] - seg[no][0]);
			seg[no * 2 + 1][0] = seg[no][0];
		}
	}
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
		{
			seg[no][0] = a[s];
			seg[no][1] = MIN;
			seg[no][2] = a[s];
			seg[no][3] = 1;
			
			return;
		}
		
		init(no * 2, s, (s + e) / 2);
		init(no * 2 + 1, (s + e) / 2 + 1, e);
		
		seg[no][0] = max(seg[no * 2][0], seg[no * 2 + 1][0]);
		seg[no][2] = seg[no * 2][2] + seg[no * 2 + 1][2];
		
		if(seg[no * 2][0] == seg[no * 2 + 1][0])
		{
			seg[no][3] = seg[no * 2][3] + seg[no * 2 + 1][3];
			seg[no][1] = max(seg[no * 2][1], seg[no * 2 + 1][1]);
		}
		
		else if(seg[no * 2][0] > seg[no * 2 + 1][0])
		{
			seg[no][3] = seg[no * 2][3];
			seg[no][1] = max(seg[no * 2][1], seg[no * 2 + 1][0]);
		}
		
		else
		{
			seg[no][3] = seg[no * 2 + 1][3];
			seg[no][1] = max(seg[no * 2 + 1][1], seg[no * 2][0]);
		}
	}
	
	void update(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		prop(no, s, e);
		
		if(e < l || r < s || seg[no][0] <= v)
			return;
		
		if(l <= s && e <= r && seg[no][1] < v)
		{
			seg[no][2] -= seg[no][3] * (seg[no][0] - v);
			seg[no][0] = v;
			prop(no, s, e);
			
			return;
		}
		
		update(no * 2, s, (s + e) / 2, l, r, v);
		update(no * 2 + 1, (s + e) / 2 + 1, e, l, r, v);
		
		seg[no][0] = max(seg[no * 2][0], seg[no * 2 + 1][0]);
		seg[no][2] = seg[no * 2][2] + seg[no * 2 + 1][2];
		
		if(seg[no * 2][0] == seg[no * 2 + 1][0])
		{
			seg[no][3] = seg[no * 2][3] + seg[no * 2 + 1][3];
			seg[no][1] = max(seg[no * 2][1], seg[no * 2 + 1][1]);
		}
		
		else if(seg[no * 2][0] > seg[no * 2 + 1][0])
		{
			seg[no][3] = seg[no * 2][3];
			seg[no][1] = max(seg[no * 2][1], seg[no * 2 + 1][0]);
		}
		
		else
		{
			seg[no][3] = seg[no * 2 + 1][3];
			seg[no][1] = max(seg[no * 2 + 1][1], seg[no * 2][0]);
		}
	}
	
	ll query1(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(r < s || e < l)
			return MIN;
		
		if(l <= s && e <= r)
			return seg[no][0];
		
		return max(query1(no * 2, s, (s + e) / 2, l, r), query1(no * 2 + 1, (s + e) / 2 + 1, e, l, r));
	}
	
	ll query2(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(r < s || e < l)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no][2];
		
		return query2(no * 2, s, (s + e) / 2, l, r) + query2(no * 2 + 1, (s + e) / 2 + 1, e, l, r);
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
			cin >> all >> bll >> cll;
			segt.update(1, 1, n, all, bll, cll);
		}
		
		else if(all == 2)
		{
			cin >> all >> bll;
			cout << segt.query1(1, 1, n, all, bll) en;
		}
		
		else if(all == 3)
		{
			cin >> all >> bll;
			cout << segt.query2(1, 1, n, all, bll) en;
		}
	}
	
	return 0;
}