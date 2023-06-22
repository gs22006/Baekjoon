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

struct gujo
{
	ll ql, qr, qw;
};

ll n, q;
pll a[100010];
gujo qry[100010];
ll L[100010], R[100010], mid[100010];

struct node
{
	ll sum, Lsum, Rsum, Asum;
};

struct segtree
{
	node seg[500010];
	
	node merge(node X1, node X2)
	{
		node ret;
		
		ret.Lsum = X1.Lsum;
		
		if(X1.Asum)
			ret.Lsum = max(ret.Lsum, X1.sum + X2.Lsum);
		
		ret.Rsum = X2.Rsum;
		
		if(X2.Asum)
			ret.Rsum = max(ret.Rsum, X2.sum + X1.Rsum);
		
		ret.Asum = (X1.Asum & X2.Asum);
		ret.sum = max(max(X1.sum, X2.sum), X1.Rsum + X2.Lsum);
		
		return ret;
	}
	
	void init(ll no, ll s, ll e)
	{
		seg[no] = {0, 0, 0, 0};
		
		if(s == e)
			return;
		
		init(no << 1, s, (s + e) >> 1);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e);
	}
	
	void update(ll no, ll s, ll e, ll w)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no] = {1, 1, 1, 1};
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, w);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, w);
		
		seg[no] = merge(seg[no << 1], seg[no << 1 | 1]);
	}
	
	node query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return {0, 0, 0, 1};
		
		if(l <= s && e <= r)
			return seg[no];
		
		node L = query(no << 1, s, (s + e) >> 1, l, r);
		node R = query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
		
		return merge(L, R);
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].fi;
		a[i].se = i;
	}
	
	sort(a + 1, a + 1 + n);
	
	cin >> q;
	
	for(ll i = 1 ; i <= q ; i++)
		cin >> qry[i].ql >> qry[i].qr >> qry[i].qw;
	
	for(ll i = 1 ; i <= q ; i++)
		L[i] = 1, R[i] = 10000000000;
	
	for(ll o = 0 ; o < 35 ; o++)
	{
		vector<pll> Q;
		
		segt.init(1, 1, n);
		
		for(ll i = 1 ; i <= q ; i++)
		{
			if(L[i] <= R[i])
			{
				mid[i] = (L[i] + R[i]) >> 1;
				Q.push_back({mid[i], i});
			}
		}
		
		sort(Q.begin(), Q.end());
		reverse(Q.begin(), Q.end());
		
		ll p = n;
		
		for(auto &i : Q)
		{
			while(p >= 1 && a[p].fi >= i.fi)
			{
				segt.update(1, 1, n, a[p].se);
				p--;
			}
			
			if(segt.query(1, 1, n, qry[i.se].ql, qry[i.se].qr).sum >= qry[i.se].qw)
				L[i.se] = mid[i.se] + 1;
			else
				R[i.se] = mid[i.se] - 1;
		}
	}
	
	for(ll i = 1 ; i <= q ; i++)
		cout << R[i] en;
	
	return 0;
}