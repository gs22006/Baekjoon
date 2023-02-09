#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
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
ll a[100010];
ll all, bll, cll;
vector<pll> vec[100010];
ll spa[100010][21];
ll dep[100010], dep2[100010];

void dfs(ll here, ll pa)
{
	spa[here][0] = pa;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		dep[i.fi] = dep[here] + i.se;
		dep2[i.fi] = dep2[here] + 1;
		dfs(i.fi, here);
	}
}

ll LCA(ll X, ll Y)
{
	if(dep2[X] < dep2[Y])
		swap(X, Y);
	
	ll cha = dep2[X] - dep2[Y];
	
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
	return dep[X] + dep[Y] - 2 * dep[LCA(X, Y)];
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll >> cll;
		
		vec[all].push_back({bll, cll});
		vec[bll].push_back({all, cll});
	}
	
	dfs(1, 0);
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll w = i;
		ll sum = 0;
		
		for(ll j = 20 ; j >= 0 ; j--)
		{
			if(!spa[w][j])
				continue;
			
			ll gap = dist(w, spa[w][j]);
			
			if(sum + gap <= a[i])
			{
				w = spa[w][j];
				sum += gap;
			}
		}
		
		cout << w en;
	}
	
	return 0;
}