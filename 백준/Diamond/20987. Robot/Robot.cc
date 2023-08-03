#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
 
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
 
struct edge
{
	ll v, col, cost, num;
};
 
ll n, m;
vector<edge> vec[500010];
pair<pll, pll> edg[500010];
ll all, bll, cll, dll;
map<pll, ll> bun;
map<pll, vector<pll> > vv;
map<pll, ll> sum;
ll cc;
vector<pll> vec2[500010];
ll dist[500010];
priority_queue<pll> pq;
ll ans = INF;
 
int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= m ; ++i)
	{
		cin >> all >> bll >> cll >> dll;
		
		vec[all].push_back({bll, cll, dll, i});
		vec[bll].push_back({all, cll, dll, i});
		edg[i] = {{all, bll}, {cll, dll}};
	}
	
	for(ll i = 1 ; i <= n ; ++i)
	{
		bun[{i, 0}] = ++cc;
		
		for(auto &j : vec[i])
		{
			bun[{i, j.num}] = ++cc;
			
			if((ll)vv[{i, j.col}].size() < 2)
			{
				vv[{i, j.col}].push_back({j.cost, j.num});
				sort(vv[{i, j.col}].begin(), vv[{i, j.col}].end());
				reverse(vv[{i, j.col}].begin(), vv[{i, j.col}].end());
			}
			
			else
			{
				if(vv[{i, j.col}][0].fi < j.cost)
				{
					vv[{i, j.col}][1] = vv[{i, j.col}][0];
					vv[{i, j.col}][0] = {j.cost, j.num};
				}
				
				else if(vv[{i, j.col}][1].fi < j.cost)
					vv[{i, j.col}][1] = {j.cost, j.num};
			}
			
			sum[{i, j.col}] += j.cost;
			vec2[cc].push_back({bun[{i, 0}], 0});
		}
	}
	
	for(ll i = 1 ; i <= n ; ++i)
	{
		for(auto &j : vec[i])
		{
			ll C = sum[{i, j.col}] - j.cost;
			
			vec2[bun[{i, 0}]].push_back({bun[{j.v, 0}], C});
			vec2[bun[{i, 0}]].push_back({bun[{j.v, j.num}], j.cost});
			
			if((ll)vv[{i, j.col}].size() <= 1)
				continue;
			
			if((ll)vv[{i, j.col}][0].se != j.num)
			{
				ll numm = vv[{i, j.col}][0].se;
				vec2[bun[{i, j.num}]].push_back({bun[{edg[numm].fi.fi + edg[numm].fi.se - i, 0}], C - edg[numm].se.se});
			}
			
			else
			{
				ll numm = vv[{i, j.col}][1].se;
				vec2[bun[{i, j.num}]].push_back({bun[{edg[numm].fi.fi + edg[numm].fi.se - i, 0}], C - edg[numm].se.se});
			}
		}
	}
	
	for(ll i = 1 ; i <= cc ; ++i)
		dist[i] = INF;
	
	dist[bun[{1, 0}]] = 0;
	pq.push({0, bun[{1, 0}]});
	
	while(!pq.empty())
	{
		pll qq = pq.top();
		pq.pop();
		
		if(-qq.fi > dist[qq.se])
			continue;
		
		for(auto &i : vec2[qq.se])
		{
			if(dist[i.fi] > dist[qq.se] + i.se)
			{
				dist[i.fi] = dist[qq.se] + i.se;
				pq.push({-dist[i.fi], i.fi});
			}
		}
	}
	
	ans = min(ans, dist[bun[{n, 0}]]);
	
	for(auto &i : vec[n])
		ans = min(ans, dist[bun[{n, i.num}]]);
	
	if(ans == INF)
		cout << -1;
	else
		cout << ans;
	
	return 0;
}