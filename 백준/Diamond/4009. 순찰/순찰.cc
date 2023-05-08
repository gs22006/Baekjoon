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
vector<ll> vec[100010], vec2[100010];
ll max_dep[100010];
ll padep[100010];
ll ans = MAX;
ll p[100010];
ll dp[100010];

void dfs(ll here, ll pa)
{
	p[here] = pa;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs(i, here);
		max_dep[here] = max(max_dep[here], max_dep[i] + 1);
	}
}

void dfs2(ll here, ll pa, ll gap)
{
	vector<ll> tmp;
	
	padep[here] = gap;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		tmp.push_back(max_dep[i]);
	}
	
	sort(tmp.begin(), tmp.end());
	reverse(tmp.begin(), tmp.end());
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		if(max_dep[i] == tmp[0])
		{
			if((ll)tmp.size() == 1)
				dfs2(i, here, gap + 1);
			else
				dfs2(i, here, max(gap, tmp[1]) + 1);
		}
		
		else
			dfs2(i, here, max(gap, tmp[0]) + 1);
	}
}

void dfs3(ll here, ll pa)
{
	vector<ll> tmp;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		tmp.push_back(max_dep[i] + 1);
	}
	
	sort(tmp.begin(), tmp.end());
	reverse(tmp.begin(), tmp.end());
	
	if((ll)tmp.size() >= 1)
		dp[here] = max(dp[here], tmp[0] + 1);
	
	if((ll)tmp.size() >= 2)
		dp[here] = max(dp[here], tmp[0] + tmp[1] + 1);
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs3(i, here);
		dp[here] = max(dp[here], dp[i]);
	}
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
	dfs2(1, 0, -1);
	dfs3(1, 0);
	
	for(ll i = 1 ; i <= n ; i++)
		padep[i]++;
	
	ans = min(ans, (n - 1) * 2 + k);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(i != 1)
			vec2[i].push_back(padep[i]);
		
		for(auto &j : vec[i])
		{
			if(p[i] != j)
				vec2[i].push_back(max_dep[j] + 1);
		}
		
		sort(vec2[i].begin(), vec2[i].end());
		reverse(vec2[i].begin(), vec2[i].end());
		
		if((ll)vec2[i].size() >= 1)
			ans = min(ans, n * 2 - (vec2[i][0] + 1) + k - 1);
		
		if((ll)vec2[i].size() >= 2)
			ans = min(ans, n * 2 - (vec2[i][0] + vec2[i][1] + 1) + k - 1);
		
		ll sizz = min((ll)vec2[i].size(), 4LL);
		ll sum = 0;
		
		for(ll j = 0 ; j < sizz ; j++)
			sum += vec2[i][j];
		
		if(k == 2)
			ans = min(ans, n * 2 - sum);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		vector<ll> tmp;
		
		for(auto &j : vec[i])
		{
			if(j == p[i])
				continue;
			
			tmp.push_back(dp[j]);
		}
		
		sort(tmp.begin(), tmp.end());
		reverse(tmp.begin(), tmp.end());
		
		if((ll)tmp.size() >= 2 && k == 2)
			ans = min(ans, 2 * (n + 1) - tmp[0] - tmp[1]);
		
		if((ll)tmp.size() >= 1 && k == 2)
			ans = min(ans, 2 * n - tmp[0] + 1);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		vector<ll> tmp;
		
		for(auto &j : vec[i])
		{
			if(j == p[i])
				continue;
			
			tmp.push_back(max_dep[j] + 1);
		}
		
		sort(tmp.begin(), tmp.end());
		reverse(tmp.begin(), tmp.end());
		
		for(auto &j : vec[i])
		{
			if(j == p[i] || k != 2)
				continue;
			
			if((ll)tmp.size() >= 1 && max_dep[j] + 1 == tmp[0])
			{
				ans = min(ans, 2 * (n + 1) - (dp[j] + padep[i] + 1));
				
				if((ll)tmp.size() >= 2)
					ans = min(ans, 2 * (n + 1) - (dp[j] + padep[i] + tmp[1] + 1));
				
				if((ll)tmp.size() >= 3)
					ans = min(ans, 2 * (n + 1) - (dp[j] + tmp[1] + tmp[2] + 1));
			}
			
			else if((ll)tmp.size() >= 2 && max_dep[j] + 1 == tmp[1])
			{
				ans = min(ans, 2 * (n + 1) - (dp[j] + padep[i] + tmp[0] + 1));
				
				if((ll)tmp.size() >= 3)
					ans = min(ans, 2 * (n + 1) - (dp[j] + tmp[0] + tmp[2] + 1));
			}
			
			else
			{
				if((ll)tmp.size() >= 2)
					ans = min(ans, 2 * (n + 1) - (dp[j] + tmp[0] + tmp[1] + 1));
				
				if((ll)tmp.size() >= 1)
					ans = min(ans, 2 * (n + 1) - (dp[j] + padep[i] + tmp[0] + 1));
				
				ans = min(ans, 2 * (n + 1) - (dp[j] + padep[i] + 1));
			}
		}
	}
	
	cout << ans;
	return 0;
}