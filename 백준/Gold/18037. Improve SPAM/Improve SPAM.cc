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

ll n, L;
vector<ll> vec[2010], vv[2010];
ll siz[2010];
ll deg[2010];
ll dp[2010];
ll ss = 1000000007;
ll all;
ll chk[2010];
ll ans;
set<ll> st;

void dfs(ll here)
{
	chk[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(chk[i])
			continue;
		
		dfs(i);
	}
}

int main(void)
{
	fastio
	
	cin >> n >> L;
	
	for(ll i = 1 ; i <= L ; i++)
	{
		cin >> siz[i];
		
		for(ll j = 1 ; j <= siz[i] ; j++)
		{
			cin >> all;
			
			if(1 <= all && all <= L)
				vec[i].push_back(all);
			else
				vv[i].push_back(all);
		}
	}
	
	dfs(1);
	
	for(ll i = 1 ; i <= L ; i++)
	{
		if(!chk[i])
			continue;
		
		for(auto &j : vec[i])
			deg[j]++;
		
		for(auto &j : vv[i])
			st.insert(j);
	}
	
	queue<ll> q;
	
	dp[1] = 1;
	q.push(1);
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		for(auto &i : vec[qq])
		{
			deg[i]--;
			dp[i] = (dp[i] + dp[qq]) % ss;
			
			if(chk[i] && !deg[i])
				q.push(i);
		}
	}
	
	for(ll i = 1 ; i <= L ; i++)
	{
		if(!chk[i])
			continue;
		
		ans = (ans + dp[i] * (ll)vv[i].size() % ss) % ss;
	}
	
	cout << (ans + ss) % ss sp << (ll)st.size();
	return 0;
}