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

ll n, m, q;
char all[110];
ll a[50010][5];
vector<ll> zip;
ll cc;

struct lazysegtree
{
	ll seg[500010][3];
	ll lazy[500010];
	
	void prop(ll no, ll s, ll e)
	{
		seg[no][0] += lazy[no];
		seg[no][1] += lazy[no];
		
		if(s != e)
		{
			lazy[no << 1] += lazy[no];
			lazy[no << 1 | 1] += lazy[no];
		}
		
		lazy[no] = 0;
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
				lazy[no << 1] += v;
				lazy[no << 1 | 1] += v;
			}
			
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, l, r, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, v);
		
		seg[no][0] = min(seg[no << 1][0], seg[no << 1 | 1][0]);
		seg[no][1] = max(seg[no << 1][1], seg[no << 1 | 1][1]);
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r, ll typ)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
		{
			if(!typ)
				return MAX;
			
			return MIN;
		}
		
		if(l <= s && e <= r)
			return seg[no][typ];
		
		ll LL = query(no << 1, s, (s + e) >> 1, l, r, typ);
		ll RR = query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, typ);
		
		if(!typ)
			return min(LL, RR);
		
		return max(LL, RR);
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n >> m >> q;
	
	for(ll i = 1 ; i <= q ; i++)
	{
		cin >> all;
		
		if(!strcmp(all, "state"))
		{
			a[i][0] = 1;
			cin >> a[i][1];
			zip.push_back(a[i][1]);
		}
		
		else if(!strcmp(all, "groupchange"))
		{
			a[i][0] = 2;
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			zip.push_back(a[i][1]);
			zip.push_back(a[i][2]);
		}
		
		else
		{
			a[i][0] = 3;
			cin >> a[i][1] >> a[i][2];
			zip.push_back(a[i][1]);
		}
	}
	
	compress(zip);
	cc = (ll)zip.size();
	
	for(ll i = 1 ; i <= q ; i++)
	{
		if(a[i][0] == 1)
			a[i][1] = lower_bound(zip.begin(), zip.end(), a[i][1]) - zip.begin() + 1;
		else if(a[i][0] == 3)
			a[i][1] = lower_bound(zip.begin(), zip.end(), a[i][1]) - zip.begin() + 1;
		
		else
		{
			a[i][1] = lower_bound(zip.begin(), zip.end(), a[i][1]) - zip.begin() + 1;
			a[i][2] = lower_bound(zip.begin(), zip.end(), a[i][2]) - zip.begin() + 1;
		}
	}
	
	for(ll i = 1 ; i <= q ; i++)
	{
		if(a[i][0] == 1)
			cout << segt.query(1, 1, cc, a[i][1], a[i][1], 0) en;
		
		else if(a[i][0] == 3)
		{
			ll gap = segt.query(1, 1, cc, a[i][1], a[i][1], 0);
			
			if(a[i][2] > 0)
			{
				if(gap + a[i][2] > m)
					a[i][2] = m - gap;
			}
			
			else if(a[i][2] < 0)
			{
				if(gap + a[i][2] < 0)
					a[i][2] = -gap;
			}
			
			cout << a[i][2] en;
			segt.update(1, 1, cc, a[i][1], a[i][1], a[i][2]);
		}
		
		else
		{
			if(a[i][3] > 0)
			{
				ll gap = segt.query(1, 1, cc, a[i][1], a[i][2], 1);
				
				if(gap + a[i][3] > m)
					a[i][3] = m - gap;
			}
			
			else if(a[i][3] < 0)
			{
				ll gap = segt.query(1, 1, cc, a[i][1], a[i][2], 0);
				
				if(gap + a[i][3] < 0)
					a[i][3] = -gap;
			}
			
			cout << a[i][3] en;
			segt.update(1, 1, cc, a[i][1], a[i][2], a[i][3]);
		}
	}
	
	return 0;
}