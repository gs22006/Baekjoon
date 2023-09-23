#include <bits/stdc++.h>
 
using namespace std;
typedef int ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 987654321
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())
 
ll n, U, D, S;
ll all, bll, cll;
vector<pll> vec[500010];
ll dp[500010];
ll nu[500010], maxx1[500010], maxx2[500010];
ll ans;
 
struct segtree
{
	ll seg[2000010];
	
	void init(ll no, ll s, ll e)
	{
		seg[no] = -INF;
		
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
			seg[no] = v;
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, w, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, w, v);
		
		seg[no] = max(seg[no << 1], seg[no << 1 | 1]);
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s || l > r)
			return -INF;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return max(query(no << 1, s, (s + e) >> 1, l, r), query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r));
	}
}segt1, segt2;
 
int main(void)
{
	fastio
	
	cin >> n >> U >> D >> S;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all >> bll >> cll;
		vec[all].push_back({bll, cll});
	}
	
	segt1.init(1, 1, 500001);
	segt2.init(1, 1, 500001);
	segt1.update(1, 1, 500001, S, 0 + U * S);
	segt2.update(1, 1, 500001, S, 0 - D * S);
	
	for(ll i = 1 ; i <= 500001 ; i++)
	{
		if(vec[i].empty())
			continue;
		
		ll siz = (ll)vec[i].size();
		
      
		sort(vec[i].begin(), vec[i].end());
		reverse(vec[i].begin(), vec[i].end());
		vec[i].push_back({0, 0});
		reverse(vec[i].begin(), vec[i].end());
		vec[i].push_back({500002, 0});
		
		nu[0] = 0;
		maxx1[0] = -INF;
		maxx2[500002] = -INF;
		
		for(ll j = 1 ; j <= siz ; j++)
			nu[vec[i][j].fi] = nu[vec[i][j - 1].fi] + vec[i][j].se;
		
		ll gap = -INF;
		
		for(ll j = 1 ; j <= siz ; j++)
		{
			ll gap1 = segt1.query(1, 1, 500001, vec[i][j - 1].fi + 1, vec[i][j].fi - 1) - nu[vec[i][j - 1].fi];
			ll gap2 = gap + segt2.query(1, 1, 500001, vec[i][j - 1].fi + 1, vec[i][j].fi - 1);
			maxx1[vec[i][j].fi] = max(max(gap1, gap2), maxx1[vec[i][j - 1].fi]);
			gap = max(gap, (U + D) * vec[i][j].fi - nu[vec[i][j - 1].fi]);
		}
		
		gap = -INF;
		
		for(ll j = siz ; j >= 1 ; j--)
		{
			ll gap1 = segt2.query(1, 1, 500001, vec[i][j].fi + 1, vec[i][j + 1].fi - 1) + nu[vec[i][j].fi];
			ll gap2 = gap + segt1.query(1, 1, 500001, vec[i][j].fi + 1, vec[i][j + 1].fi - 1);
			maxx2[vec[i][j].fi] = max(max(gap1, gap2), maxx2[vec[i][j + 1].fi]);
			gap = max(gap, -(U + D) * vec[i][j].fi + nu[vec[i][j].fi]);
		}
		
		for(ll j = 1 ; j <= siz ; j++)
		{
			dp[vec[i][j].fi] = max(maxx1[vec[i][j].fi] + nu[vec[i][j].fi] - U * vec[i][j].fi, maxx2[vec[i][j].fi] + D * vec[i][j].fi - nu[vec[i][j - 1].fi]);
			segt1.update(1, 1, 500001, vec[i][j].fi, U * vec[i][j].fi + dp[vec[i][j].fi]);
			segt2.update(1, 1, 500001, vec[i][j].fi, dp[vec[i][j].fi] - D * vec[i][j].fi);
		}
	}
	
	for(ll i = 0 ; i <= 500002 ; i++)
	{
		if(i <= S)
			ans = max(ans, dp[i] - U * (S - i));
		else
			ans = max(ans, dp[i] - D * (i - S));
	}
	
	cout << ans;
	return 0;
}
