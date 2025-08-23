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
vector<pll> vec[1010];
vector<ll> vec2[1010];
ll dist[1010], dp[1010], deg[1010];

int main(void)
{
	fastio
	
	while(1)
	{
		cin >> n;
		
		if(!n)
			break;
		
		cin >> m;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			vec[i].clear();
			vec2[i].clear();
			dist[i] = INF;
			dp[i] = deg[i] = 0;
		}
		
		for(ll i = 1 ; i <= m ; i++)
		{
			cin >> all >> bll >> cll;
			
			vec[all].push_back({bll, cll});
			vec[bll].push_back({all, cll});
		}
		
		priority_queue<pll> pq;
		
		dist[2] = 0;
		pq.push({0, 2});
		
		while(!pq.empty())
		{
			pll qq = pq.top();
			pq.pop();
			
			for(auto &i : vec[qq.se])
			{
				if(dist[i.fi] > dist[qq.se] + i.se)
				{
					dist[i.fi] = dist[qq.se] + i.se;
					pq.push({-dist[i.fi], i.fi});
				}
			}
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(auto &j : vec[i])
			{
				if(dist[i] > dist[j.fi])
				{
					vec2[i].push_back(j.fi);
					deg[j.fi]++;
				}
			}
		}
		
		dp[1] = 1;
		
		queue<ll> q;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(!deg[i])
				q.push(i);
		}
		
		while(!q.empty())
		{
			ll qq = q.front();
			q.pop();
			
			for(auto &i : vec2[qq])
			{
				deg[i]--;
				dp[i] += dp[qq];
				
				if(!deg[i])
					q.push(i);
			}
		}
		
		cout << dp[2] en;
	}
	
	return 0;
}