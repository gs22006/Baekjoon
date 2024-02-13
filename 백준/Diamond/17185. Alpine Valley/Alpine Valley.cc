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

ll n, s, q, e;
ll all, bll, cll;
vector<pll> edg, vec[100010];
ll a[100010];
ll IN[100010], OUT[100010];
ll cc, P[100010];
ll dp[100010], dep[100010], DEP[100010];
ll spa[100010][21], minn[100010][21];

void dfs0(ll here, ll pa)
{
	IN[here] = ++cc;
	P[here] = pa;
	spa[here][0] = pa;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		dep[i.fi] = dep[here] + i.se;
		DEP[i.fi] = DEP[here] + 1;
		dfs0(i.fi, here);
	}
	
	OUT[here] = cc;
}

void dfs(ll here, ll pa)
{
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		dfs(i.fi, here);
		dp[here] = min(dp[here], dp[i.fi]);
	}
}

int main(void)
{
	fastio
	
	cin >> n >> s >> q >> e;
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll >> cll;
		
		edg.push_back({all, bll});
		vec[all].push_back({bll, cll});
		vec[bll].push_back({all, cll});
	}
	
	for(ll i = 1 ; i <= n ; i++)
		dp[i] = INF;
	
	for(ll i = 1 ; i <= s ; i++)
		cin >> a[i];
	
	dfs0(e, 0);
	
	for(ll i = 1 ; i <= s ; i++)
		dp[a[i]] = dep[a[i]];
	
	dfs(e, 0);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		dp[i] -= 2 * dep[i];
		minn[i][0] = dp[i];
	}
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
			minn[j][i] = min(minn[j][i - 1], minn[spa[j][i - 1]][i - 1]);
		}
	}
	
	while(q--)
	{
		cin >> bll >> all;
		
		pll E = edg[bll - 1];
		
		if(dep[E.fi] < dep[E.se])
			swap(E.fi, E.se);
		
		if(!(IN[E.fi] <= IN[all] && OUT[all] <= OUT[E.fi]))
		{
			cout << "escaped\n";
			continue;
		}
		
		ll gaet = DEP[all] - DEP[E.fi] + 1;
		ll ans = INF;
		ll now = all;
		
		for(ll i = 20 ; i >= 0 ; i--)
		{
			if(gaet >= (1LL << i))
			{
				gaet -= (1LL << i);
				ans = min(ans, minn[now][i] + dep[all]);
				now = spa[now][i];
			}
		}
		
		ans = min(ans, dp[E.fi] + dep[all]);
		
		if(ans >= INF / 100)
			cout << "oo\n";
		else
			cout << ans en;
	}
	
	return 0;
}