#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

ll n;
vector<ll> vec[1010], chk[1010];
ll adj[1010][1010];
ll deg[1010];
ll now[1010];
vector<ll> ans;
ll last;
ll cou;
ll ff;

void dfs(ll here)
{
	for(ll i = now[here] ; i <= n ; i++)
	{
		while(adj[here][i])
		{
			adj[here][i]--;
			adj[i][here]--;
			ff = 1;
			dfs(i);
		}
		
		now[here]++;
	}
	
	ans.push_back(here);
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		now[i] = 1;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			cin >> adj[i][j];
			deg[i] += adj[i][j];
		}
	}
	
	dfs(1);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			if(adj[i][j] || (deg[i] & 1))
				cou = INF;
		}
	}
	
	if(cou >= 2)
		cout << -1;
	
	else
	{
		for(auto &i : ans)
			cout << i sp;
	}
	
	return 0;
}