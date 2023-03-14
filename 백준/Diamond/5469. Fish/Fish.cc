#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n, K;
ll ss;
pll a[500010];
vector<ll> w[500010];
pll tmp[500010];
ll idx[500010];
ll ans;
ll p;

struct segtree
{
	ll seg[2000010];
	
	void init(ll no, ll s, ll e)
	{
		seg[no] = 1;
		
		if(s == e)
			return;
		
		init(no << 1, s, (s + e) >> 1);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e);
	}
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no] = (seg[no] + v) % ss;
			return;
		}
		
		ll mid = (s + e) >> 1;
		
		update(no << 1, s, mid, w, v);
		update(no << 1 | 1, mid + 1, e, w, v);
		
		seg[no] = seg[no << 1] * seg[no << 1 | 1] % ss;
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s || e < s)
			return 1;
		
		if(l <= s && e <= r)
			return seg[no];
		
		ll mid = (s + e) >> 1;
		
		return (query(no << 1, s, mid, l, r) * query(no << 1 | 1, mid + 1, e, l, r)) % ss;
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n;
	cin >> K;
	cin >> ss;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
		w[a[i].se].push_back(i);
	
	for(ll i = 1 ; i <= K ; i++)
		tmp[i] = {w[i].back(), i};
	
	sort(tmp + 1, tmp + 1 + K);
	
	for(ll i = 1 ; i <= K ; i++)
		idx[tmp[i].se] = i;
	
	segt.init(1, 1, K);
	
	p = 1;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(p <= n && a[p].fi * 2 <= a[i].fi)
		{
			segt.update(1, 1, K, idx[a[p].se], 1);
			p++;
		}
		
		if(w[a[i].se].back() == i)
		{
			//cout << a[i].fi sp << a[i].se en;
			
			ll W = 0;
			ll l = 0, r = (ll)w[a[i].se].size() - 2;
			
			while(l <= r)
			{
				ll mid = (l + r) >> 1;
				
				if(a[w[a[i].se][mid]].fi * 2 <= a[i].fi)
					l = mid + 1;
				else
					r = mid - 1;
			}
			
			W = w[a[i].se][r + 1];
			
			ll gg = r + 1;
			//cout << "W" << a[W].fi sp << a[W].se en;
			l = idx[a[i].se] + 1;
			r = K;
			
			while(l <= r)
			{
				ll mid = (l + r) >> 1;
				
				if(a[W].fi * 2 <= a[tmp[mid].fi].fi)
					r = mid - 1;
				else
					l = mid + 1;
			}
			
			ll gap = segt.query(1, 1, K, 1, idx[a[i].se] - 1);
			gap = gap * segt.query(1, 1, K, idx[a[i].se] + 1, r) % ss;
			
			//cout << "First query : " << gap en;
			ans = (ans + gap) % ss;
			
			W = w[a[i].se][0];
			l = idx[a[i].se] + 1;
			r = K;
			
			while(l <= r)
			{
				ll mid = (l + r) >> 1;
				
				if(a[W].fi * 2 <= a[tmp[mid].fi].fi)
					r = mid - 1;
				else
					l = mid + 1;
			}
			
			segt.update(1, 1, K, idx[a[i].se], -1);
			gap = segt.query(1, 1, K, 1, r);
			segt.update(1, 1, K, idx[a[i].se], 1);
			
			if(!gg)
				gap = 0;
			
			//cout << "Second query : " << gap en;
			ans = (ans + gap) % ss;
			
			//cout << ans en;
		}
	}
	
	ans = ans % ss < 0 ? ans % ss + ss : ans % ss;
	
	cout << ans;
	return 0;
}