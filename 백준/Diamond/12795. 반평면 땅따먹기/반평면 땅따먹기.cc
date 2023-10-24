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

ll q;
ll all, bll;

struct node
{
	ll L, R;
	pll line;
};

ll Y(pll L, ll X)
{
	return L.fi * X + L.se;
}

struct lichaotree
{
	vector<node> seg;
	
	void init(void)
	{
		seg.push_back({-1, -1, {0, -INF}});
	}
	
	void update(ll no, ll s, ll e, pll L)
	{
		ll mid = (s + e) >> 1;
		pll line1 = seg[no].line;
		pll line2 = L;
		
		if(Y(line1, s) > Y(line2, s))
			swap(line1, line2);
		
		if(Y(line1, e) <= Y(line2, e))
		{
			seg[no].line = line2;
			return;
		}
		
		if(Y(line1, mid) < Y(line2, mid))
		{
			seg[no].line = line2;
			
			if(seg[no].R == -1)
			{
				seg[no].R = (ll)seg.size();
				seg.push_back({-1, -1, {0, -INF}});
			}
			
			update(seg[no].R, mid + 1, e, line1);
		}
		
		else
		{
			seg[no].line = line1;
			
			if(seg[no].L == -1)
			{
				seg[no].L = (ll)seg.size();
				seg.push_back({-1, -1, {0, -INF}});
			}
			
			update(seg[no].L, s, mid, line2);
		}
	}
	
	ll query(ll no, ll s, ll e, ll w)
	{
		if(e < w || w < s)
			return -INF;
		
		if(s == e)
			return Y(seg[no].line, w);
		
		ll ret = Y(seg[no].line, w);
		
		if(seg[no].L != -1)
			ret = max(ret, query(seg[no].L, s, (s + e) >> 1, w));
		
		if(seg[no].R != -1)
			ret = max(ret, query(seg[no].R, ((s + e) >> 1) + 1, e, w));
		
		return ret;
	}
}segt;

int main(void)
{
	fastio
	
	segt.init();
	
	cin >> q;
	
	while(q--)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> all >> bll;
			segt.update(0, -1000000000000, 1000000000000, {all, bll});
		}
		
		else
		{
			cin >> all;
			cout << segt.query(0, -1000000000000, 1000000000000, all) en;
		}
	}
	
	return 0;
}