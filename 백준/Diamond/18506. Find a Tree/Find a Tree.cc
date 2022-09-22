#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll t;
ll n, k, m;
ll all, bll;
vector<ll> vec[1000010], vec2[1000010], vec4[1000010];
ll deg[1000010], deg2[1000010];
ll chk[1000010], chk2[1000010], chk3[1000010];
ll ans[1000010];
vector<ll> whut;
ll p;

void dfs0(ll here, ll pa)
{
	whut.push_back(here);
	
	for(auto &i : vec2[here])
	{
		if(i == pa)
			continue;
		
		dfs0(i, here);
	}
	
	whut.push_back(-here);
}

void dfs(ll here)
{
	chk3[here] = 1;
	
	if(p >= (ll)whut.size())
		return;
	
	ans[whut[p]] = here;
	p++;
	
	if(p >= (ll)whut.size() || whut[p] < 0)
	{
		p++;
		return;
	}
	
	for(auto &i : vec4[here])
	{
		if(chk3[i])
			continue;
		
		dfs(i);
		
		if(p >= (ll)whut.size() || whut[p] < 0)
			break;
	}
	
	p++;
}

int main(void)
{
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d %d %d", &n, &m, &k);
		
		if(m == 0)
		{
			printf("Yes\n1\n");
			continue;
		}
		
		whut.clear();
		p = 0;
		
		for(ll i = 0 ; i <= n ; i++)
		{
			vec[i].clear();
			vec2[i].clear();
			vec4[i].clear();
			deg[i] = deg2[i] = chk[i] = chk2[i] = ans[i] = chk3[i] = 0;
		}
		
		for(ll i = 1 ; i <= m ; i++)
		{
			scanf("%d %d", &all, &bll);
			
			vec[all].push_back(bll);
			vec[bll].push_back(all);
			deg[all]++;
			deg[bll]++;
		}
		
		for(ll i = 1 ; i < k ; i++)
		{
			scanf("%d %d", &all, &bll);
			
			vec2[all].push_back(bll);
			vec2[bll].push_back(all);
		}
		
		queue<ll> q;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(deg[i] < k - 1)
				q.push(i);
		}
		
		while(!q.empty())
		{
			ll qq = q.front();
			q.pop();
			
			for(auto &i : vec[qq])
			{
				deg[i]--;
				
				if(deg[i] == k - 2)
					q.push(i);
			}
		}
		
		ll st = 0;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(auto &j : vec[i])
			{
				if(deg[i] >= k - 1 && deg[j] >= k - 1)
				{
					vec4[i].push_back(j);
					vec4[j].push_back(i);
					st = i;
				}
			}
		}
		
		dfs0(1, 0);
		dfs(st);
		
		printf("Yes\n");
		
		for(ll i = 1 ; i <= k ; i++)
			printf("%d ", ans[i]);
		
		printf("\n");
	}
	
	return 0;
}