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
ll all, bll, cll;
vector<pll> vec[510];
ll dist[510];
ll cou[510];
ll chk[510];
queue<ll> q;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll >> cll;
		vec[all].push_back({bll, cll});
	}
	
	for(ll i = 1 ; i <= n ; i++)
		dist[i] = INF;
	
	dist[1] = 0;
	cou[1]++;
	chk[1] = 1;
	q.push(1);
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		if(cou[qq] > n)
		{
			cout << -1;
			return 0;
		}
		
		chk[qq] = 0;
		
		for(auto &i : vec[qq])
		{
			if(dist[i.fi] > dist[qq] + i.se)
			{
				dist[i.fi] = dist[qq] + i.se;
				
				if(!chk[i.fi])
				{
					chk[i.fi] = 1;
					cou[i.fi]++;
					q.push(i.fi);
				}
			}
		}
	}
	
	for(ll i = 2 ; i <= n ; i++)
	{
		if(dist[i] == INF)
			cout << -1 en;
		else
			cout << dist[i] en;
	}
	
	return 0;
}