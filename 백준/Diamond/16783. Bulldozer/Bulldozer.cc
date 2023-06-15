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
pair<pll, ll> a[5010];
ll ord[5010], W[5010];

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
	ll gap, Lgap, Rgap, sum;
};

struct segtree
{
	node seg[250010];
	
	node merge(node N1, node N2)
	{
		node ret;
		
		ret.Lgap = max(N1.Lgap, N1.sum + max(0LL, N2.Lgap));
		ret.Rgap = max(N2.Rgap, N2.sum + max(0LL, N1.Rgap));
		ret.gap = max(max(N1.gap, N2.gap), max(0LL, N1.Rgap) + max(0LL, N2.Lgap));
		ret.sum = N1.sum + N2.sum;
		
		return ret;
	}
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no].gap = seg[no].Lgap = seg[no].Rgap = seg[no].sum = v;
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, w, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, w, v);
		
		seg[no] = merge(seg[no << 1], seg[no << 1 | 1]);
	}
	
	node query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return {-INF, -INF, -INF, -INF};
		
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
		cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
	
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
	
	ans = 0;
	ans = max(ans, segt.query(1, 1, n, 1, n).gap);
	
	line last;
	
	last.dx = 0;
	last.dy = 1;
	
	for(auto &i : vec)
	{
		if(last.dy * i.dx != last.dx * i.dy)
			ans = max(ans, segt.query(1, 1, n, 1, n).gap);
		
		last = i;
		
		ll W1 = W[i.P1];
		ll W2 = W[i.P2];
		ll num1 = ord[W1];
		ll num2 = ord[W2];
		
		swap(ord[W1], ord[W2]);
		swap(W[i.P1], W[i.P2]);
		
		segt.update(1, 1, n, W2, (ll)a[num1].se);
		segt.update(1, 1, n, W1, (ll)a[num2].se);
	}
	
	cout << ans;
	return 0;
}