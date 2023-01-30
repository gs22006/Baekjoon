#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

struct edge
{
	ll u, v, w, p;
};

ll n, m, x;
edge a[200010];
vector< pair<ll, ll> > vec[200010];
ll dist[200010];
ll l, r;
ll ans = -INF;

ll solve(ll X)
{
	priority_queue< pair<ll, ll> > pq;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		vec[i].clear();
		dist[i] = INF;
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(a[i].p == 1)
		{
			vec[a[i].u].push_back({a[i].v, a[i].w + X});
			vec[a[i].v].push_back({a[i].u, a[i].w + X});
		}
		
		else if(a[i].p == 2)
		{
			vec[a[i].u].push_back({a[i].v, a[i].w + x - X});
			vec[a[i].v].push_back({a[i].u, a[i].w + x - X});
		}
		
		else
		{
			vec[a[i].u].push_back({a[i].v, a[i].w});
			vec[a[i].v].push_back({a[i].u, a[i].w});
		}
	}
	
	dist[1] = 0;
	pq.push({0, 1});
	
	while(!pq.empty())
	{
		pair<ll, ll> qq = pq.top();
		pq.pop();
		
		if(dist[qq.se] < -qq.fi)
			continue;
		
		for(ll i = 0 ; i < (ll)vec[qq.se].size() ; i++)
		{
			ll nx = vec[qq.se][i].fi;
			
			if(dist[nx] > dist[qq.se] + vec[qq.se][i].se)
			{
				dist[nx] = dist[qq.se] + vec[qq.se][i].se;
				pq.push({-dist[nx], nx});
			}
		}
	}
	
	return dist[n];
}

int main(void)
{
	fastio
	
	cin >> n >> m >> x;
	
	for(ll i = 1 ; i <= m ; i++)
		cin >> a[i].u >> a[i].v >> a[i].w >> a[i].p;
	
	l = 0;
	r = x;
	
	while(l <= r)
	{
		ll mid1 = (l * 2 + r) / 3;
		ll mid2 = (l + r * 2) / 3;
		ll gap1 = solve(mid1);
		ll gap2 = solve(mid2);
		
		if(gap1 < gap2)
			l = mid1 + 1;
		else
			r = mid2 - 1;
	}
	
	for(ll i = l - 5 ; i <= l + 5 ; i++)
	{
		if(0 <= i && i <= x)
			ans = max(ans, solve(i));
	}
	
	cout << ans;
	return 0;
}