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

ll n, k;
ll all, bll;
vector<ll> vec[100010];
ll dp[100010];
ll ans;

void dfs(ll here, ll pa)
{
	vector<ll> vec2;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs(i, here);
		vec2.push_back(dp[i] + 1);
	}
	
	sort(vec2.begin(), vec2.end());
	reverse(vec2.begin(), vec2.end());
	
	ll p = 0;
	
	while(p < (ll)vec2.size())
	{
		if(p + 1 < (ll)vec2.size())
		{
			if(vec2[p] + vec2[p + 1] > 2 * k)
			{
				p++;
				ans++;
			}
			
			else
				break;
			
			continue;
		}
		
		if(vec2[p] > 2 * k)
		{
			p++;
			ans++;
		}
		
		else
			break;
	}
	
	if(p == (ll)vec2.size())
		dp[here] = 0;
	else
		dp[here] = vec2[p];
}

int main(void)
{
	fastio
	
	cin >> n >> k;
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	dfs(1, 0);
	
	cout << ans + 1;
	return 0;
}