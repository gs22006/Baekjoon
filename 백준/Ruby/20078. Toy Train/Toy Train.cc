#include "train.h"
#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define fi first
#define se second

ll n, m;
vector<ll> vec[5010], yuk[5010];
ll deg[5010], chk[5010], chk2[5010];
ll del[5010];
ll pre[5010];

vector<ll> who_wins(vector<ll> a, vector<ll> r, vector<ll> u, vector<ll> v)
{
	n = (ll)a.size();
	m = (ll)u.size();
	
	for(ll i = 0 ; i < m ; i++)
	{
		vec[u[i]].push_back(v[i]);
		yuk[v[i]].push_back(u[i]);
		deg[u[i]]++;
	}
	
	for(ll oo = 0 ; oo < n ; oo++)
	{
		queue<ll> q;
		
		for(ll i = 0 ; i < n ; i++)
		{
			if(del[i])
				continue;
			
			if(r[i])
				q.push(i);
			
			chk[i] = r[i];
			chk2[i] = 0;
		}
		
		while(!q.empty())
		{
			ll qq = q.front();
			q.pop();
			
			for(ll &i : yuk[qq])
			{
				if(del[i])
					continue;
				
				chk2[i]++;
				
				if(!chk[i])
				{
					if(a[i] && chk2[i])
					{
						chk[i] = 1;
						q.push(i);
					}
					
					else if(!a[i] && chk2[i] == deg[i])
					{
						chk[i] = 1;
						q.push(i);
					}
				}
			}
		}
		
		for(ll i = 0 ; i < n ; i++)
		{
			if(del[i])
				continue;
			
			if(!r[i])
			{
				if(!chk[i])
					del[i] = 1;
				
				continue;
			}
			
			ll cou = 0;
			
			for(ll &j : vec[i])
			{
				if(del[j])
					continue;
				
				cou += chk[j];
			}
			
			if(a[i] && !cou)
			{
				r[i] = 0;
				del[i] = 1;
			}
			
			else if(!a[i] && cou != deg[i])
			{
				r[i] = 0;
				del[i] = 1;
			}
		}
		
		ll ff = 0;
		
		for(ll i = 0 ; i < n ; i++)
		{
			if(del[i])
			{
				if(pre[i] != 0)
					ff = 1;
			}
			
			else
			{
				if(pre[i] != chk[i])
					ff = 1;
			}
		}
		
		if(oo && !ff)
			break;
	}
	
	vector<ll> ans;
	
	for(ll i = 0 ; i < n ; i++)
	{
		if(del[i])
			ans.push_back(0);
		else
			ans.push_back(chk[i]);
	}
	
	return ans;
}