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

ll m;
ll all, bll, cll;
ll rt[500010];
ll cc;

struct node
{
	ll gap, L, R;
};

struct persistentsegtree
{
	vector<node> seg;
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
			return;
		
		seg[no].L = (ll)seg.size();
		seg.push_back({0, -1, -1});
		seg[no].R = (ll)seg.size();
		seg.push_back({0, -1, -1});
		
		init(seg[no].L, s, (s + e) / 2);
		init(seg[no].R, (s + e) / 2 + 1, e);
	}
	
	void update(ll prev, ll no, ll s, ll e, ll w, ll v)
	{
		if(s == e)
		{
			seg[no].gap = seg[prev].gap + v;
			return;
		}
		
		ll mid = (s + e) / 2;
		
		if(w <= mid)
		{
			seg[no].L = (ll)seg.size();
			seg.push_back({0, -1, -1});
			seg[no].R = seg[prev].R;
			update(seg[prev].L, seg[no].L, s, mid, w, v);
		}
		
		else
		{
			seg[no].R = (ll)seg.size();
			seg.push_back({0, -1, -1});
			seg[no].L = seg[prev].L;
			update(seg[prev].R, seg[no].R, mid + 1, e, w, v);
		}
		
		seg[no].gap = 0;
		
		if(seg[no].L != -1)
			seg[no].gap += seg[seg[no].L].gap;
		
		if(seg[no].R != -1)
			seg[no].gap += seg[seg[no].R].gap;
	}
	
	ll query4(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no].gap;
		
		return query4(seg[no].L, s, (s + e) / 2, l, r) + query4(seg[no].R, (s + e) / 2 + 1, e, l, r);
	}
	
	ll query5(ll noL, ll noR, ll s, ll e, ll k)
	{
		if(s == e)
			return s;
		
		ll tmp = seg[seg[noR].L].gap - seg[seg[noL].L].gap;
		
		if(tmp >= k)
			return query5(seg[noL].L, seg[noR].L, s, (s + e) / 2, k);
		
		return query5(seg[noL].R, seg[noR].R, (s + e) / 2 + 1, e, k - tmp);
	}
	
	ll query2(ll noL, ll noR, ll s, ll e, ll dep, ll X)
	{
		ll tmp = (1LL << dep);
		
		if(s == e)
			return s;
		
		if(X & tmp)
		{
			ll tmp2 = seg[seg[noR].L].gap - seg[seg[noL].L].gap;
			
			if(tmp2)
				return query2(seg[noL].L, seg[noR].L, s, (s + e) / 2, dep - 1, X);
			
			return query2(seg[noL].R, seg[noR].R, (s + e) / 2 + 1, e, dep - 1, X);
		}
		
		else
		{
			ll tmp2 = seg[seg[noR].R].gap - seg[seg[noL].R].gap;
			
			if(tmp2)
				return query2(seg[noL].R, seg[noR].R, (s + e) / 2 + 1, e, dep - 1, X);
			
			return query2(seg[noL].L, seg[noR].L, s, (s + e) / 2, dep - 1, X);
		}
	}
}segt;

int main(void)
{
	fastio
	
	cin >> m;
	
	segt.seg.push_back({0, -1, -1});
	rt[0] = 0;
	segt.init(0, 0, 524287);
	cc++;
	
	while(m--)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> all;
			
			rt[cc] = (ll)segt.seg.size();
			segt.seg.push_back({0, -1, -1});
			segt.update(rt[cc - 1], rt[cc], 0, 524287, all, 1);
			cc++;
		}
		
		else if(all == 2)
		{
			cin >> all >> bll >> cll;
			cout << (segt.query2(rt[all - 1], rt[bll], 0, 524287, 18, cll)) en;
		}
		
		else if(all == 3)
		{
			cin >> all;
			cc -= all;
		}
		
		else if(all == 4)
		{
			cin >> all >> bll >> cll;
			cout << (segt.query4(rt[bll], 0, 524287, 1, cll) - segt.query4(rt[all - 1], 0, 524287, 1, cll)) en;
		}
		
		else if(all == 5)
		{
			cin >> all >> bll >> cll;
			cout << (segt.query5(rt[all - 1], rt[bll], 0, 524287, cll)) en;
		}
	}
	
	return 0;
}