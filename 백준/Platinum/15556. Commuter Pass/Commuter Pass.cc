#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n, m;
ll S, T;
ll U, V;
ll all, bll, cll;
vector<ll> vec[100010], cvec[100010];
ll dist[100010][7];
ll chk[100010], chk2[100010];
ll cc;
ll ans = MAX;
vector<ll> vec2[100010], vec3[100010];
ll deg1[100010], deg2[100010], deg3[100010], deg4[100010];
ll dp[100010], dp2[100010];

void dijk(ll sta)
{
	for(ll i = 1 ; i <= n ; i++)
		dist[i][cc] = INF;
	
	priority_queue< pair<ll, ll> > pq;
	
	dist[sta][cc] = 0;
	pq.push({-dist[sta][cc], sta});
	
	while(!pq.empty())
	{
		pair<ll, ll> qq = pq.top();
		pq.pop();
		
		for(ll i = 0 ; i < (ll)vec[qq.se].size() ; i++)
		{
			ll nx = vec[qq.se][i];
			
			if(dist[nx][cc] > dist[qq.se][cc] + cvec[qq.se][i])
			{
				dist[nx][cc] = dist[qq.se][cc] + cvec[qq.se][i];
				pq.push({-dist[nx][cc], nx});
			}
		}
	}
	
	return;
}

void dfs(ll here, ll distS, ll distT)
{
	chk2[here] = 1;
	
	for(ll i = 0 ; i < (ll)vec[here].size() ; i++)
	{
		ll nx = vec[here][i];
		ll cost = cvec[here][i];
		
		if(distS + cost == dist[nx][0] && distT - cost == dist[nx][1])
		{
			vec2[here].push_back(nx);
			vec3[nx].push_back(here);
			deg1[nx]++;
			deg2[here]++;
			deg3[nx]++;
			deg4[here]++;
			
			if(chk2[nx])
				continue;
			
			dfs(nx, distS + cost, distT - cost);
		}
	}
}

int main(void)
{
	scanf("%lld %lld", &n, &m);
	scanf("%lld %lld", &S, &T);
	scanf("%lld %lld", &U, &V);
	
	for(ll i = 1 ; i <= m ; i++)
	{
		scanf("%lld %lld %lld", &all, &bll, &cll);
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
		cvec[all].push_back(cll);
		cvec[bll].push_back(cll);
	}
	
	dijk(S); //0
	cc++;
	dijk(T); //1
	cc++;
	dijk(U); //2
	cc++;
	dijk(V); //3
	cc++;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(dist[T][0] == dist[i][0] + dist[i][1])
			chk[i] = 1;
	}
	
	dfs(S, 0, dist[S][1]);
	
	queue<ll> q;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		dp[i] = dist[i][2];
		
		if(!deg1[i])
			q.push(i);
	}
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		for(auto &i : vec2[qq])
		{
			deg1[i]--;
			dp[i] = min(dp[i], dp[qq]);
			
			if(!deg1[i])
				q.push(i);
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		dp2[i] = dist[i][3];
		
		if(!deg2[i])
			q.push(i);
	}
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		for(auto &i : vec3[qq])
		{
			deg2[i]--;
			dp2[i] = min(dp2[i], dp2[qq]);
			
			if(!deg2[i])
				q.push(i);
		}
	}
	
	ans = dist[V][2];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(chk[i])
			ans = min(ans, dp[i] + dp2[i]);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		dp[i] = dist[i][2];
		
		if(!deg4[i])
			q.push(i);
	}
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		for(auto &i : vec3[qq])
		{
			deg4[i]--;
			dp[i] = min(dp[i], dp[qq]);
			
			if(!deg4[i])
				q.push(i);
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		dp2[i] = dist[i][3];
		
		if(!deg3[i])
			q.push(i);
	}
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		for(auto &i : vec2[qq])
		{
			deg3[i]--;
			dp2[i] = min(dp2[i], dp2[qq]);
			
			if(!deg3[i])
				q.push(i);
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(chk[i])
			ans = min(ans, dp[i] + dp2[i]);
	}
	
	printf("%lld", ans);
	return 0;
}