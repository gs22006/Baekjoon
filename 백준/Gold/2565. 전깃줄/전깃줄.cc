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
ll all, bll;
ll ans;
vector<pll> vv;
ll dp[500010];

struct indextree
{
	ll mx;
	ll K;
	ll seg[5000010];
	
	void init(void)
	{
		mx = 500010;
		K = 1;
		
		while(K <= mx)
			K <<= 1;
	}
	
	void update(ll w, ll v)
	{
		ll W = w + K;
		
		while(W)
		{
			seg[W] = max(seg[W], v);
			W >>= 1;
		}
	}
	
	ll query(ll l, ll r)
	{
		ll ret = 0;
		
		l += K;
		r += K;
		
		while(l <= r)
		{
			if(l & 1)
			{
				ret = max(ret, seg[l]);
				l++;
			}
			
			if(!(r & 1))
			{
				ret = max(ret, seg[r]);
				r--;
			}
			
			l >>= 1;
			r >>= 1;
		}
		
		return ret;
	}
}idxt;

int main(void)
{
	fastio
	
	cin >> n;
	
	idxt.init();
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all >> bll;
		vv.push_back({all, bll});
	}
	
	sort(vv.begin(), vv.end());
	
	for(ll i = 0 ; i < n ; i++)
	{
		dp[i] = idxt.query(1, vv[i].se - 1) + 1;
		idxt.update(vv[i].se, dp[i]);
		ans = max(ans, dp[i]);
	}
	
	cout << n - ans;
	return 0;
}