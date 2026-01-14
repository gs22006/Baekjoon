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
ll dist[510][510];
ll pa[510];
vector<pll> edg;
vector<ll> ans;
ll sum;

ll ffind(ll here)
{
	if(here == pa[here])
		return here;
	
	return pa[here] = ffind(pa[here]);
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	pa[X] = Y;
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			dist[i][j] = INF;
		
		dist[i][i] = 0;
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll;
		
		edg.push_back({all, bll});
		dist[all][bll] = dist[bll][all] = 1;
	}
	
	for(ll k = 1 ; k <= n ; k++)
	{
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		pa[i] = i;
		
		for(ll j = 1 ; j <= n ; j++)
			sum += dist[i][j];
	}
	
	reverse(edg.begin(), edg.end());
	
	ans.push_back(sum);
	
	for(auto &i : edg)
	{
		if(ffind(i.fi) == ffind(i.se))
		{
			ans.push_back(sum);
			continue;
		}
		
		uunion(i.fi, i.se);
		
		for(ll j = 1 ; j <= n ; j++)
		{
			for(ll k = 1 ; k <= n ; k++)
			{
				if((dist[j][i.fi] + dist[i.se][k] + 1 == dist[j][k]) || (dist[j][i.se] + dist[i.fi][k] + 1 == dist[j][k]))
				{
					dist[j][k]--;
					sum--;
				}
			}
		}
		
		ans.push_back(sum);
	}
	
	ans.pop_back();
	reverse(ans.begin(), ans.end());
	
	for(auto &i : ans)
		cout << i en;
	
	return 0;
}