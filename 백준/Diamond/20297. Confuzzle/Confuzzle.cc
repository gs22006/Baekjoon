#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

struct mapD
{
	map<ll, ll> M;
};

ll n;
ll a[100010];
ll dep[100010], deg[100010];
mapD nod[100010];
vector<ll> vec[100010];
ll all, bll;
ll bun[100010];
queue<ll> q;
ll ans = MAX;

void dfs0(ll here, ll pa)
{
	dep[here] = dep[pa] + 1;
	
	for(ll i = 0 ; i < vec[here].size() ; i++)
	{
		if(vec[here][i] == pa)
			continue;
		
		dfs0(vec[here][i], here);
	}
}

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		scanf("%lld", &a[i]);
		bun[i] = i;
	}
	
	for(ll i = 1 ; i < n ; i++)
	{
		scanf("%lld %lld", &all, &bll);
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	dfs0(1, 0);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j : vec[i])
		{
			if(dep[i] < dep[j])
				deg[i]++;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		nod[i].M[a[i]] = dep[i];
		
		if(!deg[i])
			q.push(i);
	}
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		for(ll i : vec[qq])
		{
			ll w1 = bun[qq];
			ll w2 = bun[i];
			
			if(dep[qq] >= dep[i])
				continue;
			
			if(nod[w1].M.size() >= nod[w2].M.size())
			{
				for(auto j : nod[w2].M)
				{
					if(nod[w1].M[j.first])
					{
						ans = min(ans, nod[w1].M[j.first] + j.second - 2 * dep[qq]);
						nod[w1].M[j.first] = min(nod[w1].M[j.first], j.second);
					}
					
					else
						nod[w1].M[j.first] = j.second;
				}
				
				nod[w2].M.clear();
			}
			
			else
			{
				for(auto j : nod[w1].M)
				{
					if(nod[w2].M[j.first])
					{
						ans = min(ans, nod[w2].M[j.first] + j.second - 2 * dep[qq]);
						nod[w2].M[j.first] = min(nod[w2].M[j.first], j.second);
					}
					
					else
						nod[w2].M[j.first] = j.second;
				}
				
				bun[qq] = w2;
				nod[w1].M.clear();
			}
		}
		
		for(ll i : vec[qq])
		{
			if(dep[qq] <= dep[i])
				continue;
			
			deg[i]--;
			
			if(!deg[i])
				q.push(i);
		}
	}
	
	printf("%lld", ans);
	return 0;
}