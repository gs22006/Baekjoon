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
char all;
pair<pll, ll> a[1010];
ll ord[1010], W[1010];

struct line
{
	ll P1, P2, dx, dy;
	
	bool operator < (const line &xx) const
	{
		if(dy * xx.dx == xx.dy * dx)
		{
			if(P1 == xx.P1)
				return P2 < xx.P2;
			
			return P1 < xx.P1;
		}
		
		return dy * xx.dx < xx.dy * dx;
	}
};

vector<line> vec;

struct node
{
	ll gap, Lgap, Rgap, Agap;
};

struct segtree
{
	node seg[5010];
	
	node merge(node N1, node N2)
	{
		node ret;
		
		if(N1.Agap)
			ret.Lgap = N1.gap + N2.Lgap;
		else
			ret.Lgap = N1.Lgap;
		
		if(N2.Agap)
			ret.Rgap = N1.Rgap + N2.gap;
		else
			ret.Rgap = N2.Rgap;
		
		ret.gap = max(max(N1.gap, N2.gap), N1.Rgap + N2.Lgap);
		ret.Agap = (N1.Agap & N2.Agap);
		
		return ret;
	}
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			if(!v)
				seg[no].gap = seg[no].Lgap = seg[no].Rgap = seg[no].Agap = 0;
			else
				seg[no].gap = seg[no].Lgap = seg[no].Rgap = seg[no].Agap = 1;
			
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, w, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, w, v);
		
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

ll ans;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].fi.fi >> a[i].fi.se >> all;
		
		if(all == 'R')
			a[i].se = 1;
		else
			a[i].se = 0;
	}
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = i + 1 ; j <= n ; j++)
			vec.push_back({i, j, a[j].fi.fi - a[i].fi.fi, a[j].fi.se - a[i].fi.se});
	}
	
	sort(vec.begin(), vec.end());
	
	for(ll i = 1 ; i <= n ; i++)
	{
		segt.update(1, 1, n, i, a[i].se);
		
		ord[i] = i;
		W[i] = i;
	}
	
	ans = segt.query(1, 1, n, 1, n).gap;
	
	for(auto &i : vec)
	{
		ll W1 = W[i.P1];
		ll W2 = W[i.P2];
		ll num1 = ord[W1];
		ll num2 = ord[W2];
		
		swap(ord[W1], ord[W2]);
		swap(W[i.P1], W[i.P2]);
		
		segt.update(1, 1, n, W2, (ll)a[num1].se);
		segt.update(1, 1, n, W1, (ll)a[num2].se);
		
		ans = max(ans, segt.query(1, 1, n, 1, n).gap);
	}
	
	cout << ans;
	return 0;
}