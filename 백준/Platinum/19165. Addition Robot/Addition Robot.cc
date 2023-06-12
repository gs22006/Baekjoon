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

ll n, q;
char a[100010];
ll all, bll, cll, dll;
ll ss = 1000000007;

struct node
{
	ll A1, B1;
	ll A2, B2;
};

struct segtree
{
	node seg[400010];
	ll lazy[400010];
	
	node merge(node no1, node no2)
	{
		node ret;
		
		ret.A1 = (no1.A1 * no2.A1 % ss + no1.A2 * no2.B1 % ss) % ss;
		ret.B1 = (no1.B1 * no2.A1 % ss + no1.B2 * no2.B1 % ss) % ss;
		ret.A2 = (no1.A1 * no2.A2 % ss + no1.A2 * no2.B2 % ss) % ss;
		ret.B2 = (no1.B1 * no2.A2 % ss + no1.B2 * no2.B2 % ss) % ss;
		
		return ret;
	}
	
	void prop(ll no, ll s, ll e)
	{
		if(lazy[no])
		{
			swap(seg[no].A1, seg[no].B2);
			swap(seg[no].B1, seg[no].A2);
			
			if(s != e)
			{
				lazy[no << 1] ^= 1;
				lazy[no << 1 | 1] ^= 1;
			}
			
			lazy[no] = 0;
		}
	}
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
		{
			if(a[s] == 'A')
				seg[no] = {1, 1, 0, 1};
			else
				seg[no] = {1, 0, 1, 1};
			
			return;
		}
		
		init(no << 1, s, (s + e) >> 1);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e);
		
		seg[no] = merge(seg[no << 1], seg[no << 1 | 1]);
	}
	
	void update(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			swap(seg[no].A1, seg[no].B2);
			swap(seg[no].B1, seg[no].A2);
			
			if(s != e)
			{
				lazy[no << 1] ^= 1;
				lazy[no << 1 | 1] ^= 1;
			}
			
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, l, r);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
		
		seg[no] = merge(seg[no << 1], seg[no << 1 | 1]);
	}
	
	node query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return {1, 0, 0, 1};
		
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
	
	cin >> n >> q;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	segt.init(1, 1, n);
	
	while(q--)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> all >> bll;
			segt.update(1, 1, n, all, bll);
		}
		
		else
		{
			cin >> all >> bll >> cll >> dll;
			
			node qry = segt.query(1, 1, n, all, bll);
			ll ans1 = (cll * qry.A1 % ss + dll * qry.B1 % ss) % ss;
			ll ans2 = (cll * qry.A2 % ss + dll * qry.B2 % ss) % ss;
			
			ans1 = (ans1 % ss + ss) % ss;
			ans2 = (ans2 % ss + ss) % ss;
			
			cout << ans1 sp << ans2 en;
		}
	}
	
	return 0;
}