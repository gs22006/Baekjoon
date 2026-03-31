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
ll all, bll;
vector<ll> vec[100010];
ll num[100010], dep[100010];
ll chu[100010];

void dfs(ll here, ll pa)
{
	dep[here] = dep[pa] + 1;
	
	for(auto &i : vec[here])
		chu[i] = 0;
	
	for(auto &i : vec[here])
	{
		if(i < here)
			chu[i] += (ll)vec[i].size();
		
		chu[i] -= upper_bound(vec[i].begin(), vec[i].end(), here) - vec[i].begin();
	}
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		num[i] = num[pa] + chu[pa] - chu[i];
        dfs(i, here);
	}
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
	
	for(ll i = 1 ; i <= n ; i++)
		sort(vec[i].begin(), vec[i].end());
	
	dfs(1, 0);
	
	ll minn[2] = {INF, INF};
	
	for(ll i = 1 ; i <= n ; i++)
		minn[dep[i] & 1] = min(minn[dep[i] & 1], num[i]);
	
	for(ll i = 1 ; i <= n ; i++)
		cout << num[i] - minn[dep[i] & 1] + n sp;
	
	return 0;
}