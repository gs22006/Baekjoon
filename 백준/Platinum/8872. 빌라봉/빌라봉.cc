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

ll n, m, L;
ll all, bll, cll;
vector<pll> vec[100010];
ll grp[100010], cc;
ll dp[100010], dp2[100010];
ll minn[100010];
vector<ll> vv;
ll ans;

void dfs(ll here, ll pa)
{
	grp[here] = cc;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		dfs(i.fi, here);
		dp[here] = max(dp[here], dp[i.fi] + i.se);
	}
}

void dfs2(ll here, ll pa, ll gap)
{
	dp2[here] = max(dp[here], gap);
	
	ll maxx[2] = {0, };
	ll chld = 0;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		if(dp[i.fi] + i.se > maxx[0])
			maxx[1] = maxx[0], maxx[0] = dp[i.fi] + i.se;
		else if(dp[i.fi] + i.se > maxx[1])
			maxx[1] = dp[i.fi] + i.se;
	}
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		if(dp[i.fi] + i.se != maxx[0])
			dfs2(i.fi, here, max(gap, maxx[0]) + i.se);
		else
			dfs2(i.fi, here, max(gap, maxx[1]) + i.se);
	}
}

int main(void)
{
	fastio
	
	cin >> n >> m >> L;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll >> cll;
		
		all++, bll++;
		vec[all].push_back({bll, cll});
		vec[bll].push_back({all, cll});
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!grp[i])
		{
			cc++;
			dfs(i, 0);
			dfs2(i, 0, 0);
		}
	}
	
	for(ll i = 1 ; i <= cc ; i++)
		minn[i] = INF;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		minn[grp[i]] = min(minn[grp[i]], dp2[i]);
		ans = max(ans, dp2[i]);
	}
	
	for(ll i = 1 ; i <= cc ; i++)
		vv.push_back(minn[i]);
	
	sort(vv.begin(), vv.end());
	reverse(vv.begin(), vv.end());
	
	if((ll)vv.size() >= 2)
		ans = max(ans, vv[0] + vv[1] + L);
	
	if((ll)vv.size() >= 3)
		ans = max(ans, vv[1] + vv[2] + L * 2);
	
	cout << ans;
	return 0;
}