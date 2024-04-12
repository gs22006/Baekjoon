#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
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
ll a[10000010];
ll dp[10000010];
ll IN[10000010];
ll OUT[10000010];
ll cc;
vector<ll> vec[10000010];
ll grp[10000010];
ll P[10000010];
 
void dfs(ll here, ll pa)
{
	IN[here] = ++cc;
	dp[here] = a[here];
	P[here] = pa;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs(i, here);
		dp[here] += dp[i];
	}
	
	OUT[here] = cc;
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
		cin >> a[i];
	
	dfs(1, 0);
	
	ll minn = INF, w = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(abs(dp[1] - dp[i] * 2) < minn)
		{
			minn = abs(dp[1] - dp[i] * 2);
			w = i;
		}
	}
	
	cout << minn en;
	cout << w sp << P[w];
	return 0;
}
