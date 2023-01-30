#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

ll n, m;
ll a[4010][4010];
map< vector<ll>, ll> num;
vector<ll> won[4010];
ll adj[4010][4010];
ll now[4010];
ll cc;
ll IN[4010], OUT[4010];
vector<ll> ans, ans2;

void f(ll here)
{
	for(ll i = 1 ; i <= cc ; i++)
	{
		while(adj[here][i])
		{
			adj[here][i]--;
			f(i);
		}
	}
	
	ans.push_back(here);
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n - m + 1 ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	}
	
	for(ll i = 1 ; i <= n - m + 1 ; i++)
	{
		vector<ll> V, V2;
		
		for(ll j = 1 ; j < m ; j++)
			V.push_back(a[i][j]);
		
		if(num.find(V) == num.end())
		{
			num[V] = ++cc;
			won[cc] = V;
		}
		
		for(ll j = 2 ; j <= m ; j++)
			V2.push_back(a[i][j]);
		
		if(num.find(V2) == num.end())
		{
			num[V2] = ++cc;
			won[cc] = V2;
		}
		
		adj[num[V]][num[V2]]++;
		IN[num[V2]]++;
		OUT[num[V]]++;
	}
	
	ll ff = 0;
	
	for(ll i = 1 ; i <= cc ; i++)
	{
		if(IN[i] < OUT[i])
		{
			f(i);
			ff = 1;
			break;
		}
	}
	
	if(!ff)
	{
		for(ll i = 1 ; i <= cc ; i++)
		{
			if(OUT[i])
				f(i);
		}
	}
	
	reverse(ans.begin(), ans.end());
	
	for(ll i = 0 ; i < m - 1 ; i++)
		ans2.push_back(won[ans[0]][i]);
	
	for(ll i = 1 ; i < (ll)ans.size() ; i++)
		ans2.push_back(won[ans[i]].back());
	
	for(auto &i : ans2)
		cout << i sp;
	
	return 0;
}