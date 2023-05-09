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

ll n, m, C;
ll all, bll, cll;
vector<pll> vec[100010];
ll dist[100010];
priority_queue<pll> pq;
ll sum, ans = INF;
ll chk[100010];

int main(void)
{
	fastio
	
	cin >> n >> m >> C;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll >> cll;
		
		vec[all].push_back({bll, cll});
		vec[bll].push_back({all, cll});
		sum += cll;
	}
	
	ans = sum;
	
	for(ll i = 1 ; i <= n ; i++)
		dist[i] = INF;
	
	dist[1] = 0;
	pq.push({0, 1});
	
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
	
	vector<pll> vv;
	
	for(ll i = 1 ; i <= n ; i++)
		vv.push_back({dist[i], i});
	
	sort(vv.begin(), vv.end());
	
	for(auto &i : vv)
	{
		for(auto &j : vec[i.se])
		{
			if(chk[j.fi])
				sum -= j.se;
		}
		
		chk[i.se] = 1;
		ans = min(ans, sum + C * i.fi);
	}
	
	cout << ans;
	return 0;
}