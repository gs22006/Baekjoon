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
vector<ll> vec[10010], yuk[10010];
stack<ll> stk;
ll chk[10010];
ll scc[10010];
ll cc;
vector< vector<ll> > ans;
vector<ll> tmp[10010];

void dfs(ll here)
{
	chk[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(chk[i])
			continue;
		
		dfs(i);
	}
	
	stk.push(here);
}

void dfs2(ll here)
{
	scc[here] = cc;
	
	for(auto &i : yuk[here])
	{
		if(scc[i])
			continue;
		
		dfs2(i);
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
		yuk[bll].push_back(all);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!chk[i])
			dfs(i);
	}
	
	while(!stk.empty())
	{
		ll qq = stk.top();
		stk.pop();
		
		if(scc[qq])
			continue;
		
		cc++;
		dfs2(qq);
	}
	
	for(ll i = 1 ; i <= n ; i++)
		tmp[scc[i]].push_back(i);
	
	for(ll i = 1 ; i <= cc ; i++)
	{
		if(!tmp[i].empty())
		{
			sort(tmp[i].begin(), tmp[i].end());
			ans.push_back(tmp[i]);
		}
	}
	
	sort(ans.begin(), ans.end());
	
	cout << (ll)ans.size() en;
	
	for(auto &i : ans)
	{
		for(auto &j : i)
			cout << j sp;
		
		cout << -1 en;
	}
	
	return 0;
}