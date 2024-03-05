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

ll n, m, K;
ll a[30010];
ll all, bll;
vector<ll> vec[30010];
ll chk[30010];
ll sum, gaet;
vector<pll> vv;
ll dp[30010][3010];
ll ans;

void dfs(ll here)
{
	chk[here] = 1;
	sum += a[here];
	gaet++;
	
	for(auto &i : vec[here])
	{
		if(chk[i])
			continue;
		
		dfs(i);
	}
}

int main(void)
{
	fastio
	
	cin >> n >> m >> K;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!chk[i])
		{
			sum = gaet = 0;
			dfs(i);
			vv.push_back({sum, gaet});
		}
	}
	
	for(ll i = 0 ; i < (ll)vv.size() ; i++)
	{
		for(ll j = 0 ; j < K - vv[i].se ; j++)
			dp[i + 1][j + vv[i].se] = max(dp[i + 1][j + vv[i].se], dp[i][j] + vv[i].fi);
		
		for(ll j = 0 ; j < K ; j++)
		{
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			ans = max(ans, dp[i + 1][j]);
		}
	}
	
	cout << ans;
	return 0;
}