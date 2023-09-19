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
pll a[5010];
ll ss = 1000000007;
ll S[5010][5010];
ll nu[5010];
vector<ll> w[5010];
ll fac[5010], inv[5010];
ll tmp[5010];
ll dp[5010][5010];
ll numL[5010], numR[5010];
ll nu1[5010][5010], nuR[5010][5010], nuL[5010][5010];
vector<pll> vec;
map<ll, ll> mp;

ll sqrmtp(ll X, ll Y)
{
	ll ret = 1;
	
	while(Y)
	{
		if(Y & 1)
			ret = ret * X % ss;
		
		X = X * X % ss;
		Y >>= 1;
	}
	
	return ret;
}

ll solve(void)
{
	ll siz = (ll)vec.size();
	ll L = vec[0].fi, R = 0;
	ll ini = vec[0].fi - 1;
	
	mp[siz]++;
	
	for(ll i = 0 ; i < siz ; i++)
	{
		vec[i].fi = vec[i].fi - L + 1;
		vec[i].se = vec[i].se - L + 1;
		R = max(R, vec[i].se);
	}
	
	L = 1;
	
	for(ll i = 0 ; i <= R ; i++)
	{
		for(ll j = 0 ; j <= R ; j++)
		{
			dp[i][j] = 0;
			nu1[i][j] = 0;
			nuL[i][j] = 0;
			nuR[i][j] = 0;
		}
		
		numL[i] = numR[i] = -1;
	}
	
	for(ll i = 0 ; i < siz ; i++)
	{
		dp[vec[i].fi][vec[i].se] = fac[siz - 1] * inv[siz - S[vec[i].fi + ini][vec[i].se + ini]];
		numL[vec[i].fi] = i;
		numR[vec[i].se] = i;
	}
	
	for(ll len = 0 ; len <= R - L ; len++)
	{
		for(ll i = L ; i <= R - len ; i++)
		{
			ll j = i + len;
			nu1[i][j] = (nu1[i][j] + nu1[i + 1][j] + nu1[i][j - 1] - nu1[i + 1][j - 1]) % ss;
			nuL[i][j] = (nuL[i][j] + nuL[i][j - 1]) % ss;
			nuR[i][j] = (nuR[i + 1][j] + nuR[i][j]) % ss;
		}
		
		for(ll i = L ; i <= R - len ; i++)
		{
			ll j = i + len;
			
			if(numL[i] == -1 || numR[j] == -1)
				continue;
			
			ll S1 = vec[numL[i]].fi, E1 = vec[numL[i]].se;
			ll S2 = vec[numR[j]].fi, E2 = vec[numR[j]].se;
			
			if(S2 < i || j < E1)
				continue;
			
			if(numL[i] == numR[j])
				dp[i][j] = (dp[i][j] + nu1[i][j] * inv[siz - S[i + ini][j + ini]] % ss) % ss;
			
			else
			{
				ll SS = vec[numL[i]].fi, EE = vec[numL[i]].se;
				dp[i][j] = (dp[i][j] + (nuR[SS + 1][j] - nuR[EE][j]) * inv[siz - S[i + ini][j + ini]] % ss) % ss;
				SS = vec[numR[j]].fi, EE = vec[numR[j]].se;
				dp[i][j] = (dp[i][j] + (nuL[i][EE - 1] - nuL[i][SS]) * inv[siz - S[i + ini][j + ini]] % ss) % ss;
			}
			
			if(siz - S[i][j] - 1 >= 0)
			{
				nu1[i - 1][j + 1] = (nu1[i - 1][j + 1] + dp[i][j] * fac[siz - S[i][j] - 1] % ss) % ss;
				nuL[i][j] = (nuL[i][j] + dp[i][j] * fac[siz - S[i][j] - 1] % ss) % ss;
				nuR[i][j] = (nuR[i][j] + dp[i][j] * fac[siz - S[i][j] - 1] % ss) % ss;
			}
		}
	}
	
	return dp[L][R] % ss;
}

int count_removals(vector<int> SS, vector<int> EE)
{
	n = (ll)SS.size();
	
	for(ll i = 0 ; i < n ; i++)
		a[i + 1] = {SS[i], EE[i]};
	
	for(ll i = 1 ; i <= n ; i++)
		w[a[i].fi].push_back(i);
	
	m = n * 2;
	
	for(ll i = m ; i >= 1 ; i--)
	{
		for(auto &j : w[i])
			nu[a[j].se]++;
		
		for(ll j = 1 ; j <= m ; j++)
			tmp[j] = nu[j];
		
		for(ll j = 1 ; j <= m ; j++)
		{
			tmp[j] += tmp[j - 1];
			S[i][j] = tmp[j];
		}
	}
	
	fac[0] = 1;
	
	for(ll i = 1 ; i <= n ; i++)
		fac[i] = fac[i - 1] * i % ss;
	
	for(ll i = 0 ; i <= n ; i++)
		inv[i] = sqrmtp(fac[i], ss - 2);
	
	sort(a + 1, a + 1 + n);
	
	ll last = a[1].se;
	vec.push_back(a[1]);
	ll ans = 1;
	
	for(ll i = 2 ; i <= n ; i++)
	{
		if(last < a[i].fi)
		{
			ans = ans * solve() % ss;
			last = a[i].se;
			vec.clear();
			vec.push_back(a[i]);
		}
		
		else
		{
			last = max(last, a[i].se);
			vec.push_back(a[i]);
		}
	}
	
	ans = ans * solve() % ss;
	
	for(auto &i : mp)
		ans = ans * fac[i.se] % ss;
	
	return (ans % ss + ss) % ss;
}