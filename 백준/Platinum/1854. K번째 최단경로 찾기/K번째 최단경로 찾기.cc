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

ll n, m, K;
ll all, bll, cll;
vector<pll> vec[1010];
priority_queue<ll> dist[1010];
priority_queue<pll> pq;

int main(void)
{
	fastio
	
	cin >> n >> m >> K;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll >> cll;
		vec[all].push_back({bll, cll});
	}
	
	dist[1].push(0);
	pq.push({0, 1});
	
	while(!pq.empty())
	{
		pll qq = pq.top();
		pq.pop();
		
		for(auto &i : vec[qq.se])
		{
			ll gap = -qq.fi + i.se;
			
			if((ll)dist[i.fi].size() < K)
			{
				dist[i.fi].push(gap);
				pq.push({-gap, i.fi});
			}
			
			else
			{
				if(dist[i.fi].top() > gap)
				{
					dist[i.fi].pop();
					dist[i.fi].push(gap);
					pq.push({-gap, i.fi});
				}
			}
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if((ll)dist[i].size() < K)
			cout << -1 en;
		else
			cout << dist[i].top() en;
	}
	
	return 0;
}