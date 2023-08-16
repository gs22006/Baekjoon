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
ll all, bll;
set<ll> st[300010];
vector<ll> vec[300010];
vector<pll> edg;
ll ans;
ll deg[300010];

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll;
		
		st[all].insert(bll);
		st[bll].insert(all);
		vec[all].push_back(bll);
		vec[bll].push_back(all);
		edg.push_back({all, bll});
		deg[all]++, deg[bll]++;
	}
	
	for(auto &i : edg)
	{
		ll X = i.fi, Y = i.se;
		
		if(deg[X] > deg[Y])
			swap(X, Y);
		
		for(auto &j : vec[X])
			ans += st[Y].count(j);
	}
	
	cout << ans / 3;
	return 0;
}