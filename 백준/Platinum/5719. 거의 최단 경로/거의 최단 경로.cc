#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
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
ll S, D;
ll all, bll, cll;
vector<pll> vec[510], yuk[510];
vector<pll> vv[510];
ll tdist[510];
ll dist[510], dist2[510];

void get_dist(ll X)
{
	priority_queue<pll> pq;
	
	for(ll i = 1 ; i <= n ; i++)
		tdist[i] = INF;
	
	tdist[X] = 0;
	pq.push({0, X});
	
	while(!pq.empty())
	{
		pll qq = pq.top();
		pq.pop();
		
		for(auto &i : vv[qq.se])
		{
			if(tdist[i.fi] > tdist[qq.se] + i.se)
			{
				tdist[i.fi] = tdist[qq.se] + i.se;
				pq.push({-tdist[i.fi], i.fi});
			}
		}
	}
}

int main(void)
{
	fastio
	
	while(1)
	{
		cin >> n >> m;
		
		if(!n && !m)
			break;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			vec[i].clear();
			yuk[i].clear();
		}
		
		cin >> S >> D;
		
		S++, D++;
		
		for(ll i = 1 ; i <= m ; i++)
		{
			cin >> all >> bll >> cll;
			
			all++, bll++;
			vec[all].push_back({bll, cll});
			yuk[bll].push_back({all, cll});
		}
		
		for(ll i = 1 ; i <= n ; i++)
			vv[i].clear();
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(auto &j : vec[i])
				vv[i].push_back(j);
		}
		
		get_dist(S);
		
		for(ll i = 1 ; i <= n ; i++)
			dist[i] = tdist[i];
		
		for(ll i = 1 ; i <= n ; i++)
			vv[i].clear();
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(auto &j : yuk[i])
				vv[i].push_back(j);
		}
		
		get_dist(D);
		
		for(ll i = 1 ; i <= n ; i++)
			dist2[i] = tdist[i];
		
		for(ll i = 1 ; i <= n ; i++)
			vv[i].clear();
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(auto &j : vec[i])
			{
				if(dist[i] + dist2[j.fi] + j.se != dist[D])
					vv[i].push_back(j);
			}
		}
		
		get_dist(S);
		
		if(tdist[D] == INF)
			cout << -1 en;
		else
			cout << tdist[D] en;
	}
	
	return 0;
}