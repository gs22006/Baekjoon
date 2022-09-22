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

ll n, m;
ll w, h;
pair< pair<ll, ll>, ll> a[200010];
ll b[200010];
vector<ll> vec, vec2;
unordered_map<ll, ll> ZIP;
ll won[400010];
ll cc;
ll p = 1, p2 = 1;
ll ans = MIN, X, Y;

struct lazysegtree
{
	ll seg[2000010][4];
	ll lazy[2000010];
	
	void init(ll no, ll s, ll e)
	{
		seg[no][2] = seg[no][3] = s;
		
		if(s == e)
			return;
		
		init(no * 2, s, (s + e) / 2);
		init(no * 2 + 1, (s + e) / 2 + 1, e);
	}
	
	void prop(ll no, ll s, ll e)
	{
		if(lazy[no])
		{
			seg[no][0] += lazy[no];
			seg[no][1] += lazy[no];
			
			if(s != e)
			{
				lazy[no * 2] += lazy[no];
				lazy[no * 2 + 1] += lazy[no];
			}
			
			lazy[no] = 0;
		}
	}
	
	void update(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			seg[no][0] += v;
			seg[no][1] += v;
			
			if(s != e)
			{
				lazy[no * 2] += v;
				lazy[no * 2 + 1] += v;
			}
			
			return;
		}
		
		update(no * 2, s, (s + e) / 2, l, r, v);
		update(no * 2 + 1, (s + e) / 2 + 1, e, l, r, v);
		
		if(seg[no * 2][0] > seg[no * 2 + 1][0])
		{
			seg[no][0] = seg[no * 2][0];
			seg[no][2] = seg[no * 2][2];
		}
		
		else
		{
			seg[no][0] = seg[no * 2 + 1][0];
			seg[no][2] = seg[no * 2 + 1][2];
		}
		
		if(seg[no * 2][1] < seg[no * 2 + 1][1])
		{
			seg[no][1] = seg[no * 2][1];
			seg[no][3] = seg[no * 2][3];
		}
		
		else
		{
			seg[no][1] = seg[no * 2 + 1][1];
			seg[no][3] = seg[no * 2 + 1][3];
		}
	}
	
	pair<ll, ll> query(ll no, ll s, ll e, ll l, ll r, ll typ)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
		{
			if(!typ)
				return {MIN, MIN};
			
			return {MAX, MAX};
		}
		
		if(l <= s && e <= r)
			return {seg[no][typ], seg[no][typ + 2]};
		
		pair<ll, ll> L = query(no * 2, s, (s + e) / 2, l, r, typ);
		pair<ll, ll> R = query(no * 2 + 1, (s + e) / 2 + 1, e, l, r, typ);
		
		if(!typ)
		{
			if(L.fi < R.fi)
				return R;
			
			return L;
		}
		
		if(L.fi < R.fi)
			return L;
		
		return R;
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n >> m >> w >> h;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].fi.fi >> a[i].fi.se;
		a[i].se = 1;
	}
	
	for(ll i = n + 1 ; i <= n + m ; i++)
	{
		cin >> a[i].fi.fi >> a[i].fi.se;
		a[i].se = -1;
	}
	
	for(ll i = 1 ; i <= n + m ; i++)
	{
		vec.push_back(a[i].fi.se);
		vec.push_back(a[i].fi.se + h);
	}
	
	sort(vec.begin(), vec.end());
	
	for(ll i = 0 ; i < (ll)vec.size() ; i++)
	{
		if(i && vec[i] == vec[i - 1])
			continue;
		
		if(!ZIP[vec[i]])
		{
			ZIP[vec[i]] = ++cc;
			won[cc] = vec[i];
		}
	}
	
	for(ll i = 1 ; i <= n + m ; i++)
		a[i].fi.se = ZIP[a[i].fi.se];
	
	sort(a + 1, a + n + m + 1);
	
	for(ll i = 1 ; i <= n + m ; i++)
	{
		vec2.push_back(a[i].fi.fi);
		vec2.push_back(a[i].fi.fi - w);
	}
	
	sort(vec2.begin(), vec2.end());
	segt.init(1, 1, cc);
	
	for(auto &i : vec2)
	{
		while(p <= n + m && a[p].fi.fi <= i + w)
		{
			segt.update(1, 1, cc, a[p].fi.se, ZIP[won[a[p].fi.se] + h], a[p].se);
			p++;
		}
		
		while(p2 <= n + m && a[p2].fi.fi < i)
		{
			segt.update(1, 1, cc, a[p2].fi.se, ZIP[won[a[p2].fi.se] + h], -a[p2].se);
			p2++;
		}
		
		pair<ll, ll> tmp = segt.query(1, 1, cc, 1, cc, 0);
		
		if(ans < tmp.fi)
		{
			ans = tmp.fi;
			X = i;
			Y = won[tmp.se];
		}
		
		tmp = segt.query(1, 1, cc, 1, cc, 1);
		
		if(ans < -tmp.fi)
		{
			ans = -tmp.fi;
			X = i;
			Y = won[tmp.se];
		}
	}
	
	cout << ans en << X sp << Y - h;
	return 0;
}