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
ll a[200010];
ll q;
ll all, bll, cll;

struct segtree_beats
{
	//ONE, ZERO, max
	ll seg[800010][3];
	ll lazy[800010][2];
	
	void prop(ll no, ll s, ll e)
	{
		seg[no][2] &= ~lazy[no][0];
		seg[no][1] |= lazy[no][0];
		seg[no][0] -= (seg[no][0] & lazy[no][0]);
		
		seg[no][2] |= lazy[no][1];
		seg[no][0] |= lazy[no][1];
		seg[no][1] -= (seg[no][1] & lazy[no][1]);
		
		if(s != e)
		{
			lazy[no * 2][0] &= ~lazy[no][1];
			lazy[no * 2][0] |= lazy[no][0];
			lazy[no * 2][1] &= ~lazy[no][0];
			lazy[no * 2][1] |= lazy[no][1];
			
			lazy[no * 2 + 1][0] &= ~lazy[no][1];
			lazy[no * 2 + 1][0] |= lazy[no][0];
			lazy[no * 2 + 1][1] &= ~lazy[no][0];
			lazy[no * 2 + 1][1] |= lazy[no][1];
		}
		
		lazy[no][0] = lazy[no][1] = 0;
	}
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
		{
			seg[no][0] = a[s];
			seg[no][1] = ~a[s];
			seg[no][2] = a[s];
			
			return;
		}
		
		init(no * 2, s, (s + e) / 2);
		init(no * 2 + 1, (s + e) / 2 + 1, e);
		
		seg[no][0] = (seg[no * 2][0] & seg[no * 2 + 1][0]);
		seg[no][1] = (seg[no * 2][1] & seg[no * 2 + 1][1]);
		seg[no][2] = max(seg[no * 2][2], seg[no * 2 + 1][2]);
	}
	
	void update1(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		v -= (seg[no][1] & v);
		
		if(l <= s && e <= r && (v & seg[no][0]))
		{
			lazy[no][0] = (v & seg[no][0]);
			v -= (v & seg[no][0]);
			prop(no, s, e);
		}
		
		if(!v)
			return;
		
		update1(no * 2, s, (s + e) / 2, l, r, v);
		update1(no * 2 + 1, (s + e) / 2 + 1, e, l, r, v);
		
		seg[no][0] = (seg[no * 2][0] & seg[no * 2 + 1][0]);
		seg[no][1] = (seg[no * 2][1] & seg[no * 2 + 1][1]);
		seg[no][2] = max(seg[no * 2][2], seg[no * 2 + 1][2]);
	}
	
	void update2(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		v -= (v & seg[no][0]);
		
		if(l <= s && e <= r && (v & seg[no][1]))
		{
			lazy[no][1] = (v & seg[no][1]);
			v -= (v & seg[no][1]);
			prop(no, s, e);
		}
		
		if(!v)
			return;
		
		update2(no * 2, s, (s + e) / 2, l, r, v);
		update2(no * 2 + 1, (s + e) / 2 + 1, e, l, r, v);
		
		seg[no][0] = (seg[no * 2][0] & seg[no * 2 + 1][0]);
		seg[no][1] = (seg[no * 2][1] & seg[no * 2 + 1][1]);
		seg[no][2] = max(seg[no * 2][2], seg[no * 2 + 1][2]);
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return MIN;
		
		if(l <= s && e <= r)
			return seg[no][2];
		
		return max(query(no * 2, s, (s + e) / 2, l, r), query(no * 2 + 1, (s + e) / 2 + 1, e, l, r));
	}
	
	void print(ll no, ll s, ll e)
	{
		prop(no, s, e);
		
		if(s == e)
		{
			cout << s << " ~ " << e sp << seg[no][2] en;
			return;
		}
		
		print(no * 2, s, (s + e) / 2);
		print(no * 2 + 1, (s + e) / 2 + 1, e); 
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
		//segt.print(1, 1, n);
		
		cin >> all;
		
		if(all == 1)
		{
			cin >> all >> bll >> cll;
			segt.update1(1, 1, n, all, bll, ~cll);
		}
		
		else if(all == 2)
		{
			cin >> all >> bll >> cll;
			segt.update2(1, 1, n, all, bll, cll);
		}
		
		else if(all == 3)
		{
			cin >> all >> bll;
			cout << segt.query(1, 1, n, all, bll) en;
		}
	}
	
	return 0;
}