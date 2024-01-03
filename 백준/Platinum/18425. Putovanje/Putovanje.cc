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
vector< pair<pll, pll> > edg;
ll all, bll, cll, dll;
vector<pll> vec[200010];
ll Pnum[200010];
ll dep[200010], spa[200010][21];
ll nu[200010];
ll sum[200010];
ll ans;

void dfs(ll here, ll pa)
{
	spa[here][0] = pa;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		dep[i.fi] = dep[here] + 1;
		Pnum[i.fi] = i.se;
		dfs(i.fi, here);
	}
}

ll LCA(ll X, ll Y)
{
	if(dep[X] < dep[Y])
		swap(X, Y);
	
	ll cha = dep[X] - dep[Y];
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if(cha >= (1LL << i))
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

void dfs2(ll here, ll pa)
{
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		dfs2(i.fi, here);
		nu[here] += nu[i.fi];
	}
	
	sum[Pnum[here]] += nu[here];
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll >> cll >> dll;
		
		edg.push_back({{all, bll}, {cll, dll}});
		vec[all].push_back({bll, i - 1});
		vec[bll].push_back({all, i - 1});
	}
	
	dfs(1, 0);
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	for(ll i = 1 ; i < n ; i++)
	{
		nu[i]++, nu[i + 1]++;
		nu[LCA(i, i + 1)] -= 2;
	}
	
	dfs2(1, 0);
	
	for(ll i = 0 ; i < n - 1 ; i++)
		ans += min(sum[i] * edg[i].se.fi, edg[i].se.se);
	
	cout << ans;
	return 0;
}