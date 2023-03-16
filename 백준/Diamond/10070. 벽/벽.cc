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

ll n, k;
ll all, bll, cll, dll;

struct lazysegtree
{
	ll seg[8000010][2];
	
	void prop(ll no)
	{
		if(no != 1)
		{
			seg[no][0] = max(seg[no][0], seg[no >> 1][0]);
			seg[no][1] = max(seg[no][1], seg[no >> 1][0]);
			seg[no][0] = min(seg[no][0], seg[no >> 1][1]);
			seg[no][1] = min(seg[no][1], seg[no >> 1][1]);
		}
	}
	
	void update(ll no, ll s, ll e, ll l, ll r, ll v, ll typ)
	{
		prop(no);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			if(!typ)
			{
				seg[no][0] = max(seg[no][0], v);
				seg[no][1] = max(seg[no][1], v);
			}
			
			else
			{
				seg[no][1] = min(seg[no][1], v);
				seg[no][0] = min(seg[no][0], v);
			}
			
			return;
		}
		
		ll mid = (s + e) >> 1;
		
		update(no << 1, s, mid, l, r, v, typ);
		update(no << 1 | 1, mid + 1, e, l, r, v, typ);
		
		seg[no][0] = min(seg[no << 1][0], seg[no << 1 | 1][0]);
		seg[no][1] = max(seg[no << 1][1], seg[no << 1 | 1][1]);
	}
	
	ll query(ll no, ll s, ll e, ll w)
	{
		prop(no);
		
		if(e < w || w < s)
			return INF;
		
		if(s == e)
			return seg[no][1];
		
		ll mid = (s + e) >> 1;
		ll LL = query(no << 1, s, mid, w);
		ll RR = query(no << 1 | 1, mid + 1, e, w);
		
		if(LL != INF)
			return LL;
		
		return RR;
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n >> k;
	
	while(k--)
	{
		cin >> all >> bll >> cll >> dll;
		segt.update(1, 0, n - 1, bll, cll, dll, all - 1);
	}
	
	for(ll i = 0 ; i < n ; i++)
		cout << segt.query(1, 0, n - 1, i) en;
	
	return 0;
}