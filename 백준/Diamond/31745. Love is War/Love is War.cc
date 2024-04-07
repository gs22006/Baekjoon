#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
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
ll a[500010];
ll b[500010];
vector<ll> w[500010];
vector< pair<pll, ll> > vv;
ll ans;
 
struct segtree_beats
{
	//min, min2, sum, gaet
	ll seg[4000010][4];
	
	void prop(ll no, ll s, ll e)
	{
		if(s == e)
			return;
		
		if(seg[no * 2][0] < seg[no][0])
		{
			seg[no * 2][2] += seg[no * 2][3] * (seg[no][0] - seg[no * 2][0]);
			seg[no * 2][0] = seg[no][0];
		}
		
		if(seg[no * 2 + 1][0] < seg[no][0])
		{
			seg[no * 2 + 1][2] += seg[no * 2 + 1][3] * (seg[no][0] - seg[no * 2 + 1][0]);
			seg[no * 2 + 1][0] = seg[no][0];
		}
	}
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
		{
			seg[no][0] = 0;
			seg[no][1] = MAX;
			seg[no][2] = 0;
			seg[no][3] = 1;
			
			return;
		}
		
		init(no * 2, s, (s + e) / 2);
		init(no * 2 + 1, (s + e) / 2 + 1, e);
		
		seg[no][0] = min(seg[no * 2][0], seg[no * 2 + 1][0]);
		seg[no][2] = seg[no * 2][2] + seg[no * 2 + 1][2];
		
		if(seg[no * 2][0] == seg[no * 2 + 1][0])
		{
			seg[no][3] = seg[no * 2][3] + seg[no * 2 + 1][3];
			seg[no][1] = min(seg[no * 2][1], seg[no * 2 + 1][1]);
		}
		
		else if(seg[no * 2][0] < seg[no * 2 + 1][0])
		{
			seg[no][3] = seg[no * 2][3];
			seg[no][1] = min(seg[no * 2][1], seg[no * 2 + 1][0]);
		}
		
		else
		{
			seg[no][3] = seg[no * 2 + 1][3];
			seg[no][1] = min(seg[no * 2 + 1][1], seg[no * 2][0]);
		}
	}
	
	void update(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		prop(no, s, e);
		
		if(e < l || r < s || seg[no][0] >= v)
			return;
		
		if(l <= s && e <= r && seg[no][1] > v)
		{
			seg[no][2] += seg[no][3] * (v - seg[no][0]);
			seg[no][0] = v;
			prop(no, s, e);
			
			return;
		}
		
		update(no * 2, s, (s + e) / 2, l, r, v);
		update(no * 2 + 1, (s + e) / 2 + 1, e, l, r, v);
		
		seg[no][0] = min(seg[no * 2][0], seg[no * 2 + 1][0]);
		seg[no][2] = seg[no * 2][2] + seg[no * 2 + 1][2];
		
		if(seg[no * 2][0] == seg[no * 2 + 1][0])
		{
			seg[no][3] = seg[no * 2][3] + seg[no * 2 + 1][3];
			seg[no][1] = min(seg[no * 2][1], seg[no * 2 + 1][1]);
		}
		
		else if(seg[no * 2][0] < seg[no * 2 + 1][0])
		{
			seg[no][3] = seg[no * 2][3];
			seg[no][1] = min(seg[no * 2][1], seg[no * 2 + 1][0]);
		}
		
		else
		{
			seg[no][3] = seg[no * 2 + 1][3];
			seg[no][1] = min(seg[no * 2 + 1][1], seg[no * 2][0]);
		}
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(r < s || e < l)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no][2];
		
		return query(no * 2, s, (s + e) / 2, l, r) + query(no * 2 + 1, (s + e) / 2 + 1, e, l, r);
	}
}segt;
 
int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> b[i];
		w[b[i]].push_back(i);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll idx = upper_bound(w[a[i]].begin(), w[a[i]].end(), i) - w[a[i]].begin();
		
		if(0 <= idx && idx < (ll)w[a[i]].size())
			vv.push_back({{i, w[a[i]][idx]}, a[i]});
		
		idx--;
		
		if(0 <= idx && idx < (ll)w[a[i]].size())
			vv.push_back({{w[a[i]][idx], i}, a[i]});
	}
	
	sort(vv.begin(), vv.end());
	reverse(vv.begin(), vv.end());
	
	segt.init(1, 1, n);
	
	ll p = 0;
	
	for(ll i = n ; i >= 1 ; i--)
	{
		while(p < (ll)vv.size() && vv[p].fi.fi >= i)
		{
			segt.update(1, 1, n, vv[p].fi.se, n, vv[p].se);
			p++;
		}
		
		ans += segt.query(1, 1, n, i, n);
	}
	
	cout << ans;
	return 0;
}