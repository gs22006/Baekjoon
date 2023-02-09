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
ll S, D;
ll all, bll, cll;
vector<pll> vec[1010];
ll dist[1010][1010];
ll gap;
priority_queue< pair<ll, pll> > pq;

int main(void)
{
	fastio
	
	cin >> n >> m >> K;
	cin >> S >> D;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll >> cll;
		
		vec[all].push_back({bll, cll});
		vec[bll].push_back({all, cll});
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= n ; j++)
			dist[i][j] = INF;
	}
	
	dist[S][0] = 0;
	pq.push({0, {S, 0}});
	
	while(!pq.empty())
	{
		pair<ll, pll> qq = pq.top();
		pq.pop();
		
		if(dist[qq.se.fi][qq.se.se] < -qq.fi || qq.se.se > n)
			continue;
		
		for(auto &i : vec[qq.se.fi])
		{
			if(dist[i.fi][qq.se.se + 1] > dist[qq.se.fi][qq.se.se] + i.se)
			{
				dist[i.fi][qq.se.se + 1] = dist[qq.se.fi][qq.se.se] + i.se;
				pq.push({-dist[i.fi][qq.se.se + 1], {i.fi, qq.se.se + 1}});
			}
		}
	}
	
	ll ans = INF;
	
	for(ll j = 0 ; j <= n ; j++)
		ans = min(ans, dist[D][j] + gap * j);
	
	cout << ans en;
	
	for(ll i = 1 ; i <= K ; i++)
	{
		ans = INF;
		
		cin >> all;
		gap += all;
		
		for(ll j = 0 ; j <= n ; j++)
			ans = min(ans, dist[D][j] + gap * j);
		
		cout << ans en;
	}
	
	return 0;
}