#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL

struct edge
{
	ll u, v, cost, num;
	
	bool operator < (const edge &xx) const
	{
		return cost < xx.cost;
	}
};

ll n, m;
edge e[300010];
ll chk[300010], chk2[300010];
ll pa[100010], ra[100010];
ll sum;
ll dep[100010];
ll p[100010], cp[100010], np[100010], spa[100010][20];
vector<ll> vec[100010], cvec[100010], nvec[100010];
ll ans[300010];

ll ffind(ll here)
{
	if(here == pa[here])
		return here;
	
	return pa[here] = ffind(pa[here]);
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	if(X == Y)
		return;
	
	if(ra[X] < ra[Y])
		pa[X] = Y;
	else if(ra[Y] < ra[X])
		pa[Y] = X;
	
	else
	{
		pa[X] = Y;
		ra[Y]++;
	}
}

void dfs(ll here, ll pa)
{
	dep[here] = dep[pa] + 1;
	
	for(ll i = 0 ; i < vec[here].size() ; i++)
	{
		ll nx = vec[here][i];
		
		if(nx == pa)
			continue;
		
		p[nx] = here;
		cp[nx] = cvec[here][i];
		np[nx] = nvec[here][i];
		spa[nx][0] = here;
		
		dfs(nx, here);
	}
}

ll LCA(ll X, ll Y)
{
	if(dep[X] != dep[Y])
	{
		if(dep[X] > dep[Y])
			swap(X, Y);
		
		for(ll i = 19 ; i >= 0 ; i--)
		{
			if(dep[X] <= dep[spa[Y][i]])
				Y = spa[Y][i];
		}
	}
	
	ll ret = X;
	
	if(X != Y)
	{
		for(ll i = 19 ; i >= 0 ; i--)
		{
			if(spa[X][i] != spa[Y][i])
			{
				X = spa[X][i];
				Y = spa[Y][i];
			}
			
			ret = spa[X][i];
		}
	}
	
	return ret;
}

int main(void)
{
	scanf("%lld %lld", &n, &m);
	
	for(ll i = 1 ; i <= m ; i++)
	{
		scanf("%lld %lld %lld", &e[i].u, &e[i].v, &e[i].cost);
		
		e[i].num = i;
		ans[i] = MAX;
	}
	
	sort(e + 1, e + 1 + m);
	
	for(ll i = 1 ; i <= n ; i++)
		pa[i] = i;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(ffind(e[i].u) == ffind(e[i].v))
			continue;
		
		chk[e[i].num] = 1;
		sum += e[i].cost;
		uunion(e[i].u, e[i].v);
		
		vec[e[i].u].push_back(e[i].v);
		vec[e[i].v].push_back(e[i].u);
		cvec[e[i].u].push_back(e[i].cost);
		cvec[e[i].v].push_back(e[i].cost);
		nvec[e[i].u].push_back(e[i].num);
		nvec[e[i].v].push_back(e[i].num);
	}
	
	dfs(1, 0);
	
	for(ll i = 1 ; i < 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(!chk[i])
			ans[i] = sum;
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(chk[e[i].num])
			continue;
		
		ll w = e[i].u;
		ll lca = LCA(e[i].u, e[i].v);
		
		while(dep[w] > dep[lca])
		{
			if(!chk2[np[w]])
			{
				ans[np[w]] = min(ans[np[w]], sum - cp[w] + e[i].cost);
				chk2[np[w]] = 1;
			}
			
			ll tmp = p[w];
			
			p[w] = lca;
			w = tmp;
		}
		
		w = e[i].v;
		
		while(dep[w] > dep[lca])
		{
			if(!chk2[np[w]])
			{
				ans[np[w]] = min(ans[np[w]], sum - cp[w] + e[i].cost);
				chk2[np[w]] = 1;
			}
			
			ll tmp = p[w];
			
			p[w] = lca;
			w = tmp;
		}
	}
	
	for(ll i = 1 ; i <= m ; i++)
		printf("%lld\n", ans[i] == MAX ? -1 : ans[i]);
	
	return 0;
}