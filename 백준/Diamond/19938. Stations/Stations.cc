//stations.cpp
#include "stations.h"
#include <bits/stdc++.h>
 
using namespace std;
typedef int ll;
typedef double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775808LL
 
ll I[1010], O[1010];
ll cou = 1;
vector<ll> vec[1010];
ll dep[1010];
 
void f(ll here, ll pa)
{
	if(here != 0)
		dep[here] = dep[pa] + 1;
	
	ll cocou = 0;
	
	I[here] = cou;
	
	if(dep[here] % 2 == 0)
		cou++;
	
	for(ll nx : vec[here])
	{
		if(nx == pa)
			continue;
		
		cocou++;
		f(nx, here);
	}
	
	O[here] = cou;
	
	if(dep[here] % 2 == 1)
		cou++;
}
 
vector<int> label(int n, int k, vector<int> u, vector<int> v)
{
	ll sta = 0, maxx = 0;
	vector<int> ret;
	ll lab[2010] = {0, }, chk[2010] = {0, };
	cou = 0;
	
	for(ll i = 0 ; i < n ; i++)
		vec[i].clear(), I[i] = 0, O[i] = 0;
	
	for(ll i = 0 ; i < u.size() ; i++)
	{
		vec[u[i]].push_back(v[i]);
		vec[v[i]].push_back(u[i]);
	}
	
	f(0, -1);
	
	for(ll i = 0 ; i < n ; i++)
	{
		if(dep[i] % 2 == 0)
			lab[i] = I[i];
		else
			lab[i] = O[i];
	}
	
	for(ll i = 0 ; i < n ; i++)
		ret.push_back(lab[i]);
	
	return ret;
}
 
int find_next_station(int s, int t, vector<int> c)
{
	if(c.size() == 1)
		return c[0];
	
	sort(c.begin(), c.end());
	
	if(s < c[0]) //maybe <=
	{
		for(ll i : c)
		{
			if(s <= t && t <= i)
				return i;
		}
		
		return c[c.size() - 1];
	}
	
	else
	{
		reverse(c.begin(), c.end());
		
		for(ll i : c)
		{
			if(i <= t && t <= s)
				return i;
		}
		
		return c[c.size() - 1];
	}
}