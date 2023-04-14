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

ll n, q;
ll all, bll, cll;
vector<ll> vec[100010];
ll spa[100010][21];
ll dep[100010];

void dfs(ll here, ll pa)
{
	spa[here][0] = pa;
	dep[here] = dep[pa] + 1;
	
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

ll dist(ll X, ll Y)
{
	return dep[X] + dep[Y] - 2 * dep[LCA(X, Y)];
}

int main(void)
{
	fastio
	
	cin >> n;
	
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
	
	cin >> q;
	
	while(q--)
	{
		cin >> all >> bll >> cll;
		
		ll d1 = dist(all, bll);
		ll d2 = dist(all, cll);
		ll d3 = dist(bll, cll);
		ll d = max(d1, max(d2, d3));
		
		if(d2 == d)
			swap(bll, cll);
		else if(d3 == d)
			swap(all, cll);
		
		if(d & 1)
		{
			cout << -1 en;
			continue;
		}
		
		d >>= 1;
		
		ll tmp = d;
		ll lca = LCA(all, bll);
		ll dist1 = dep[all] - dep[lca];
		ll dist2 = dep[bll] - dep[lca];
		
		if(dist1 < dist2)
			swap(all, bll);
		
		for(ll i = 20 ; i >= 0 ; i--)
		{
			if((1LL << i) <= tmp)
			{
				tmp -= (1LL << i);
				all = spa[all][i];
			}
		}
		
		if(dist(all, cll) != d)
			cout << -1 en;
		else
			cout << all en;
	}
	
	return 0;
}