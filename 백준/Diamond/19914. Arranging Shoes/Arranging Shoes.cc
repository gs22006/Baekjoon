//shoes.cpp
#include "shoes.h"
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775808LL

vector<ll> a;
ll n;
ll ans;
vector< pair<ll, ll> > e;
queue<ll> shoe[200010];

struct fenwicktree
{
	ll bit[1000010];
	
	void update(ll p, ll v)
	{
		if(p > n)
			return;
		
		bit[p] += v;
		p += p & (-p);
		update(p, v);
	}
	
	ll query(ll p)
	{
		if(p == 0)
			return 0;
		
		return query(p - (p & (-p))) + bit[p];
	}
	
	ll query2(ll L, ll R)
	{
		return query(R) - query(L - 1);
	}
}BIT;

ll count_swaps(vector<int> s)
{
	n = (ll)s.size();
	
	for(ll i = 0 ; i < n ; i++)
		a.push_back(s[i]);
	
	for(ll i = 0 ; i < n ; i++)
	{
		if((shoe[abs(a[i])].empty()) || (a[shoe[abs(a[i])].front()] == a[i]))
			shoe[abs(a[i])].push(i);
		
		else
		{
			e.push_back(make_pair(shoe[abs(a[i])].front(), i));
			shoe[abs(a[i])].pop();
		}
	}
	
	sort(e.begin(), e.end());
	
	for(ll i = 0 ; i < (ll)e.size() ; i++)
	{
		if(a[e[i].first] > 0)
			ans++;
		
		ans += e[i].second + BIT.query(e[i].second + 1) - e[i].first - BIT.query(e[i].first + 1) - 1;
		BIT.update(1, 1);
		BIT.update(e[i].second + 1, -1);
	}
	
	return ans;
}
//