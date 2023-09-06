#include "beechtree.h"
#include <bits/stdc++.h>
 
using namespace std;
typedef int ll;
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
 
vector<ll> zip;
vector<ll> vec[200010];
ll chk[200010];
ll siz[200010];
map<ll, ll> mp[200010];
map<ll, ll> st[200010];
ll bun[200010];
ll ans[200010];
 
void dfs0(ll here, ll pa)
{
	siz[here] = 1;
	
	for(auto &i : vec[here])
	{
		dfs0(i, here);
		siz[here] += siz[i];
	}
}
 
void dfs(ll here, ll pa)
{
	if((ll)vec[here].size() == 0)
	{
		mp[here][siz[here]] = here;
		bun[here] = here;
		return;
	}
	
	for(auto &i : vec[here])
	{
		dfs(i, here);
		
		if(ans[i] == -1)
			ans[here] = -1;
	}
	
	if(ans[here] == -1)
		return;
	
	ll maxx = -1;
	ll w = -1;
	
	for(auto &i : vec[here])
	{
		if(maxx < siz[i])
		{
			maxx = siz[i];
			w = i;
		}
	}
	
	bun[here] = bun[w];
	
	for(auto &i : vec[here])
	{
		if(i == w)
			continue;
		
		for(auto &j : mp[bun[i]])
		{
			if(j.fi == 1)
				continue;
			
			auto p = mp[bun[here]].lower_bound(j.fi);
			
			if(p != mp[bun[here]].end())
			{
				auto gap = (*p);
				ll V = gap.se;
				ll U = j.se;
				
				for(auto &k : st[U])
				{
					if(st[V].find(k.fi) == st[V].end())
					{
						ans[here] = -1;
						return;
					}
					
					if(siz[st[V][k.fi]] < siz[k.se])
					{
						ans[here] = -1;
						return;
					}
				}
				
				if(gap.fi == j.fi)
				{
					for(auto &k : st[V])
					{
						if(st[U].find(k.fi) == st[U].end())
						{
							ans[here] = -1;
							return;
						}
						
						if(siz[st[U][k.fi]] < siz[k.se])
						{
							ans[here] = -1;
							return;
						}
					}
				}
			}
			
			p = mp[bun[here]].upper_bound(j.fi);
			
			if(p != mp[bun[here]].begin())
			{
				p--;
				auto gap = (*p);
				ll V = gap.se;
				ll U = j.se;
				
				for(auto &k : st[V])
				{
					if(st[U].find(k.fi) == st[U].end())
					{
						ans[here] = -1;
						return;
					}
					
					if(siz[st[U][k.fi]] < siz[k.se])
					{
						ans[here] = -1;
						return;
					}
				}
			}
		}
		
		for(auto &j : mp[bun[i]])
			mp[bun[here]][j.fi] = j.se;
	}
	
	auto p = mp[bun[here]].rbegin();
	auto gap = (*p);
	ll V = gap.se;
	ll U = here;
	
	for(auto &k : st[V])
	{
		if(st[U].find(k.fi) == st[U].end())
		{
			ans[here] = -1;
			return;
		}
		
		if(siz[st[U][k.fi]] < siz[k.se])
		{
			ans[here] = -1;
			return;
		}
	}
	
	if(gap.fi == siz[here])
	{
		for(auto &k : st[V])
		{
			if(st[U].find(k.fi) == st[U].end())
			{
				ans[here] = -1;
				return;
			}
			
			if(siz[st[U][k.fi]] < siz[k.se])
			{
				ans[here] = -1;
				return;
			}
		}
	}
	
	mp[bun[here]][siz[here]] = here;
}
 
vector<ll> beechtree(ll N, ll M, vector<ll> P, vector<ll> C)
{
	for(ll i = 1 ; i < N ; i++)
		zip.push_back(C[i]);
	
	compress(zip);
	
	M = (ll)zip.size();
	
	for(ll i = 1 ; i < N ; i++)
		C[i] = lower_bound(zip.begin(), zip.end(), C[i]) - zip.begin() + 1;
	
	for(ll i = 1 ; i < N ; i++)
		vec[P[i]].push_back(i);
	
	for(ll i = 0 ; i < N ; i++)
	{
		set<ll> st22;
		
		for(auto &j : vec[i])
			st22.insert(C[j]);
		
		if((ll)st22.size() != (ll)vec[i].size())
			ans[i] = -1;
	}
	
	dfs0(0, -1);
	
	for(ll i = 0 ; i < N ; i++)
	{
		for(auto &j : vec[i])
			st[i][C[j]] = j;
	}
	
	dfs(0, -1);
	
	vector<ll> anss;
	
	for(ll i = 0 ; i < N ; i++)
	{
		if(ans[i] == -1)
			anss.push_back(0);
		else
			anss.push_back(1);
	}
	
	return anss;
}