#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

struct ohno
{
	map<ll, ll> gaet;
};

ll n, Q;
ll a[500010];
ll pa[500010];
ll deg[500010];
vector<ll> vec[500010], yuk[500010];
ll dep[500010];
queue<ll> q;
ohno nod[500010];
ll ans[500010];
ll k, all;
ll bun[500010];

void dfs0(ll here, ll pa)
{
	dep[here] = dep[pa] + 1;
	
	for(ll i = 0 ; i < yuk[here].size() ; i++)
		dfs0(yuk[here][i], here);
}

int main(void)
{
	scanf("%lld %lld", &n, &Q);
	
	for(ll i = 2 ; i <= n ; i++)
	{
		scanf("%lld", &pa[i]);
		
		deg[pa[i]]++;
		vec[i].push_back(pa[i]);
		yuk[pa[i]].push_back(i);
	}
	
	dep[0] = -1;
	dfs0(1, 0);
	
	for(ll i = 1 ; i <= Q ; i++)
	{
		scanf("%lld", &k);
		
		for(ll j = 1 ; j <= k ; j++)
		{
			scanf("%lld", &all);
			nod[all].gaet[i]++;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		bun[i] = i;
		
		if(!deg[i])
			q.push(i);
	}
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		for(ll i = 0 ; i < yuk[qq].size() ; i++)
		{
			ll X = bun[qq];
			ll Y = bun[yuk[qq][i]];
			
			if(nod[X].gaet.size() >= nod[Y].gaet.size())
			{
				for(auto j : nod[Y].gaet)
				{
					ans[j.first] += (nod[X].gaet[j.first] * j.second * dep[qq]);
					nod[X].gaet[j.first] += j.second;
				}
				
				nod[Y].gaet.clear();
			}
			
			else
			{
				for(auto j : nod[X].gaet)
				{
					ans[j.first] += (nod[Y].gaet[j.first] * j.second * dep[qq]);
					nod[Y].gaet[j.first] += j.second;
				}
				
				nod[X].gaet.clear();
				bun[qq] = bun[yuk[qq][i]];
			}
		}
		
		for(ll i = 0 ; i < vec[qq].size() ; i++)
		{
			deg[vec[qq][i]]--;
			
			if(!deg[vec[qq][i]])
				q.push(vec[qq][i]);
		}
	}
	
	for(ll i = 1 ; i <= Q ; i++)
		printf("%lld\n", ans[i]);
	
	return 0;
}