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

ll n, K;
ll dist[500010][2];
queue<pll> q;
ll ans = INF;

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 0 ; i <= 500000 ; i++)
		dist[i][0] = dist[i][1] = INF;
	
	dist[n][0] = 0;
	q.push({n, 0});
	
	while(!q.empty())
	{
		pll qq = q.front();
		q.pop();
		
		if(qq.fi * 2 <= 500000 && dist[qq.fi * 2][qq.se ^ 1] == INF)
		{
			dist[qq.fi * 2][qq.se ^ 1] = dist[qq.fi][qq.se] + 1;
			q.push({qq.fi * 2, qq.se ^ 1});
		}
		
		if(qq.fi - 1 >= 0 && dist[qq.fi - 1][qq.se ^ 1] == INF)
		{
			dist[qq.fi - 1][qq.se ^ 1] = dist[qq.fi][qq.se] + 1;
			q.push({qq.fi - 1, qq.se ^ 1});
		}
		
		if(qq.fi + 1 <= 500000 && dist[qq.fi + 1][qq.se ^ 1] == INF)
		{
			dist[qq.fi + 1][qq.se ^ 1] = dist[qq.fi][qq.se] + 1;
			q.push({qq.fi + 1, qq.se ^ 1});
		}
	}
	
	for(ll i = 0 ; ; i++)
	{
		if(K + i * (i + 1) / 2 > 500000)
			break;
		
		if(dist[K + i * (i + 1) / 2][i & 1] <= i)
			ans = min(ans, i);
	}
	
	if(ans == INF)
		cout << -1;
	else
		cout << ans;
	
	return 0;
}