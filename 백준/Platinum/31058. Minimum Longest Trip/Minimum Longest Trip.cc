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

ll n, m;
vector<pll> vec[200010];
vector<ll> yuk[200010];
ll all, bll, cll;
ll deg[200010];
vector<ll> ord;
queue<ll> q;
ll dp[200010];
ll spa[200010][21], hsh[200010][21];
ll ss = 1000000007, hs = 79;
ll P[2000010];
ll dp2[200010];

ll comp(ll X, ll Y, ll len)
{
	len--;
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if((1LL << i) <= len)
		{
			if(hsh[X][i] == hsh[Y][i])
			{
				len -= (1LL << i);
				X = spa[X][i];
				Y = spa[Y][i];
			}
		}
	}
	
	if(hsh[X][0] < hsh[Y][0])
		return -1;
	
	return 1;
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll >> cll;
		
		vec[all].push_back({bll, cll});
		yuk[bll].push_back(all);
		deg[all]++;
	}
	
	P[0] = 1;
	
	for(ll i = 1 ; i < 2000010 ; i++)
		P[i] = P[i - 1] * hs % ss;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!deg[i])
			q.push(i);
	}
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		ord.push_back(qq);
		
		for(auto &i : yuk[qq])
		{
			deg[i]--;
			
			if(!deg[i])
				q.push(i);
		}
	}
	
	for(auto &i : ord)
	{
		if(vec[i].empty())
		{
			dp[i] = 1;
			dp2[i] = 0;
			
			for(ll j = 0 ; j <= 20 ; j++)
				spa[i][j] = i, hsh[i][j] = 0;
			
			continue;
		}
		
		ll maxx = 0;
		
		for(auto &j : vec[i])
			maxx = max(maxx, dp[j.fi]);
		
		ll minn = INF;
		
		for(auto &j : vec[i])
		{
			if(dp[j.fi] == maxx)
				minn = min(minn, j.se);
		}
		
		vector<pll> hubo;
		
		for(auto &j : vec[i])
		{
			if(dp[j.fi] == maxx && j.se == minn)
				hubo.push_back(j);
		}
		
		dp[i] = maxx + 1;
		spa[i][0] = hubo.back().fi, hsh[i][0] = hubo.back().se;
		hubo.pop_back();
		
		for(auto &j : hubo)
		{
			if(comp(spa[i][0], j.fi, dp[i] - 1) == 1)
				spa[i][0] = j.fi, hsh[i][0] = j.se;
		}
		
		dp2[i] = dp2[spa[i][0]] + hsh[i][0];
		
		for(ll j = 1 ; j <= 20 ; j++)
		{
			spa[i][j] = spa[spa[i][j - 1]][j - 1];
			hsh[i][j] = (hsh[i][j - 1] * P[(1LL << (j - 1))] % ss + hsh[spa[i][j - 1]][j - 1]) % ss;
			hsh[i][j] = (hsh[i][j] + ss) % ss;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
		cout << dp[i] - 1 sp << dp2[i] en;
	
	return 0;
}