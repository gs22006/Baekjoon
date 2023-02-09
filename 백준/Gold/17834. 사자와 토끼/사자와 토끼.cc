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

ll n, m;
ll all, bll;
vector<ll> vec[50010];
vector<pll> edg;
ll chk[50010];
ll cou[5];

void dfs(ll here, ll dep)
{
	chk[here] = dep;
	
	for(auto &i : vec[here])
	{
		if(chk[i])
			continue;
		
		dfs(i, 3 - dep);
	}
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
		edg.push_back({all, bll});
	}
	
	dfs(1, 1);
	
	for(auto &i : edg)
	{
		if(chk[i.fi] == chk[i.se])
		{
			cout << "0";
			return 0;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
		cou[chk[i]]++;
	
	cout << cou[1] * cou[2] * 2;
	return 0;
}