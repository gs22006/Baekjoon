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
ll a[200010];
pll b[200010];
ll all, bll;
vector<ll> vec[200010];
ll dep[200010];
ll spa[200010][21];
ll p[200010], ra[200010], maxx[200010];
ll dp[200010];

void dfs(ll here, ll pa)
{
	dep[here] = dep[pa] + 1;
	spa[here][0] = pa;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs(i, here);
	}
}

ll LCA(ll X, ll Y)
{
	if(dep[X] < dep[Y])
		swap(X, Y);
	
	ll cha = dep[X] - dep[Y];
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if((1LL << i) <= cha)
		{
			cha -= (1LL << i);
			X = spa[X][i];
		}
	}
	
	if(X == Y)
		return X;
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if(spa[X][i] != spa[Y][i])
		{
			X = spa[X][i];
			Y = spa[Y][i];
		}
	}
	
	return spa[X][0];
}

ll dist(ll X, ll Y)
{
	return dep[X] + dep[Y] - dep[LCA(X, Y)] * 2;
}

ll ffind(ll here)
{
	if(p[here] == here)
		return p[here];
	
	return p[here] = ffind(p[here]);
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	if(ra[X] > ra[Y])
		swap(X, Y);
	
	if(ra[X] == ra[Y])
		ra[Y]++;
	
	p[X] = Y;
	
	if(a[maxx[Y]] < a[maxx[X]])
		maxx[Y] = maxx[X];
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		b[i] = {a[i], i};
	}
	
	sort(b + 1, b + 1 + n);
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	dfs(1, 0);
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	for(ll i = 1 ; i <= n ; i++)
		p[i] = i, ra[i] = 0, maxx[i] = i;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll num = b[i].se;
		
		for(auto &j : vec[num])
		{
			if(a[j] < a[num])
			{
				dp[num] = max(dp[num], dp[maxx[ffind(j)]] + dist(maxx[ffind(j)], num));
				uunion(j, num);
			}
		}
	}
	
	cout << dp[b[n].se];
	return 0;
}