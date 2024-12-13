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
vector<ll> vec[1000010];
vector<ll> V[1000010];
ll Q;
ll dp[1000010][3];
ll N;
ll ans;
ll chk[1000010];
queue<ll> q;

ll num(ll X, ll Y)
{
	return n * Y + X;
}

void dfs(ll here, ll pa)
{
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs(i, here);
	}
	
	ll minn = INF, chld = 0;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		chld++;
		
		minn = min(minn, dp[i][1] - dp[i][0]);
		dp[here][2] += min(dp[i][0], dp[i][1]);
		dp[here][0] += min(dp[i][0], dp[i][1]);
		dp[here][1] += dp[i][2];
		
		if(dp[i][0] <= dp[i][1])
			V[num(here, 2)].push_back(num(i, 0));
		
		if(dp[i][0] >= dp[i][1])
			V[num(here, 2)].push_back(num(i, 1));
		
		V[num(here, 1)].push_back(num(i, 2));
	}
	
	dp[here][1]++;
	
	if(!chld)
	{
		dp[here][0] = INF;
		dp[here][1] = 1;
		dp[here][2] = 0;
		return;
	}
	
	if(minn < 0)
	{
		for(auto &i : vec[here])
		{
			if(i == pa)
				continue;
			
			if(dp[i][0] <= dp[i][1])
				V[num(here, 0)].push_back(num(i, 0));
			
			if(dp[i][0] >= dp[i][1])
				V[num(here, 0)].push_back(num(i, 1));
		}
	}
	
	else
	{
		ll C = 0;
		
		for(auto &i : vec[here])
		{
			if(i == pa)
				continue;
			
			if(dp[i][1] - dp[i][0] == minn)
				C++;
		}
		
		for(auto &i : vec[here])
		{
			if(i == pa)
				continue;
			
			if(dp[i][1] - dp[i][0] == minn)
			{
				V[num(here, 0)].push_back(num(i, 1));
				
				if(C >= 2)
					V[num(here, 0)].push_back(num(i, 0));
			}
			
			else
				V[num(here, 0)].push_back(num(i, 0));
		}
	}
	
	dp[here][0] += max(0LL, minn);
}

void solve(void)
{
	for(ll i = 1 ; i <= n ; i++)
		dp[i][0] = dp[i][1] = dp[i][2] = 0;
	
	dfs(1, 0);
	return;
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
	
	solve();
	
	if(dp[1][0] <= dp[1][1])
	{
		chk[num(1, 0)] = 1;
		q.push(num(1, 0));
	}
	
	if(dp[1][0] >= dp[1][1])
	{
		chk[num(1, 1)] = 1;
		q.push(num(1, 1));
	}
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		for(auto &i : V[qq])
		{
			if(chk[i])
				continue;
			
			chk[i] = 1;
			q.push(i);
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
	    if(chk[num(i, 1)])
			cout << min(dp[1][0], dp[1][1]) en;
		else
			cout << min(dp[1][0], dp[1][1]) + 1 en;
	}
	
	return 0;
}