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

ll n, m, K, q;
ll all, bll, cll;
vector<pll> vec[20010], yuk[20010];
ll hub[210];
ll dist1[210][20010], dist2[210][20010];
ll ans1, ans2;

void get_dist(ll X)
{
	priority_queue<pll> pq;
	
	for(ll i = 1 ; i <= n ; i++)
		dist1[X][i] = dist2[X][i] = INF;
	
	dist1[X][hub[X]] = 0;
	pq.push({0, hub[X]});
	
	while(!pq.empty())
	{
		pll qq = pq.top();
		pq.pop();
		
		for(auto &i : vec[qq.se])
		{
			if(dist1[X][i.fi] > dist1[X][qq.se] + i.se)
			{
				dist1[X][i.fi] = dist1[X][qq.se] + i.se;
				pq.push({-dist1[X][i.fi], i.fi});
			}
		}
	}
	
	dist2[X][hub[X]] = 0;
	pq.push({0, hub[X]});
	
	while(!pq.empty())
	{
		pll qq = pq.top();
		pq.pop();
		
		for(auto &i : yuk[qq.se])
		{
			if(dist2[X][i.fi] > dist2[X][qq.se] + i.se)
			{
				dist2[X][i.fi] = dist2[X][qq.se] + i.se;
				pq.push({-dist2[X][i.fi], i.fi});
			}
		}
	}
}

int main(void)
{
	fastio
	
	cin >> n >> m >> K >> q;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll >> cll;
		
		vec[all].push_back({bll, cll});
		yuk[bll].push_back({all, cll});
	}
	
	for(ll i = 1 ; i <= K ; i++)
	{
		cin >> hub[i];
		get_dist(i);
	}
	
	while(q--)
	{
		ll ans = INF;
		
		cin >> all >> bll;
		
		for(ll i = 1 ; i <= K ; i++)
			ans = min(ans, dist2[i][all] + dist1[i][bll]);
		
		if(ans != INF)
		{
			ans1++;
			ans2 += ans;
		}
	}
	
	cout << ans1 en << ans2;
	return 0;
}