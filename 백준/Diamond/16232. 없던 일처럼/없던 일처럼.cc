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

ll n;
ll a[200010], b[200010], k[200010];
vector<ll> tmp;

struct segtree
{
	vector< pair<ll, ll> > seg[800010];
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
		{
			seg[no].push_back({-INF, a[s]});
			seg[no].push_back({k[s], b[s]});
			return;
		}
		
		init(no * 2, s, (s + e) / 2);
		init(no * 2 + 1, (s + e) / 2 + 1, e);
		
		seg[no].clear();
		
		ll p1 = 0, p2 = 0;
		
		seg[no].push_back({-INF, seg[no * 2][0].se + seg[no * 2 + 1][0].se});
		
		while(1)
		{
			if(p1 == (ll)seg[no * 2].size() - 1 && p2 == (ll)seg[no * 2 + 1].size() - 1)
				break;
			
			if(p1 == (ll)seg[no * 2].size() - 1)
			{
				seg[no].push_back({seg[no * 2 + 1][p2 + 1].fi - seg[no * 2][p1].se, seg[no * 2 + 1][p2 + 1].se + seg[no * 2][p1].se});
				p2++;
				continue;
			}
			
			if(p2 == (ll)seg[no * 2 + 1].size() - 1)
			{
				seg[no].push_back({seg[no * 2][p1 + 1].fi, seg[no * 2][p1 + 1].se + seg[no * 2 + 1][p2].se});
				p1++;
				continue;
			}
			
			if(seg[no * 2][p1 + 1].fi <= seg[no * 2 + 1][p2 + 1].fi - seg[no * 2][p1].se)
			{
				seg[no].push_back({seg[no * 2][p1 + 1].fi, seg[no * 2][p1 + 1].se + seg[no * 2 + 1][p2].se});
				p1++;
			}
			
			else
			{
				seg[no].push_back({seg[no * 2 + 1][p2 + 1].fi - seg[no * 2][p1].se, seg[no * 2 + 1][p2 + 1].se + seg[no * 2][p1].se});
				p2++;
			}
		}
		
		for(ll i = 1 ; i < (ll)seg[no].size() ; i++)
			seg[no][i].fi = max(seg[no][i].fi, seg[no][i - 1].fi);
	}
	
	vector<ll> qry(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return tmp;
		
		if(l <= s && e <= r)
		{
			vector<ll> hhh;
			hhh.push_back(no);
			return hhh;
		}
		
		vector<ll> L = qry(no * 2, s, (s + e) / 2, l, r);
		vector<ll> R = qry(no * 2 + 1, (s + e) / 2 + 1, e, l, r);
		
		for(auto &i : R)
			L.push_back(i);
		
		return L;
	}
	
	ll query(ll s, ll e, ll v)
	{
		if(s > e)
			return v;
		
		vector<ll> vv = qry(1, 1, n, s, e);
		
		for(auto &i : vv)
		{
			ll l = 0;
			ll r = (ll)seg[i].size() - 1;
			
			while(l + 1 < r)
			{
				ll mid = (l + r) / 2;
				
				if(seg[i][mid].fi <= v)
					l = mid;
				else
					r = mid;
			}
			
			if(seg[i][r].fi <= v)
				v += seg[i][r].se;
			else
				v += seg[i][l].se;
		}
		
		return v;
	}
}segt;

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld %lld %lld", &a[i], &b[i], &k[i]);
	
	segt.init(1, 1, n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll gap = segt.query(1, i - 1, 0);
		ll gap2 = segt.query(i + 1, n, gap);
		
		printf("%lld\n", gap2);
	}
	
	return 0;
}