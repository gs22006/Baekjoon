#include "evolution.h"
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

ll n = 1;
ll dp[1000010], dp2[1000010];
multiset<ll> st[1000010], st2[1000010];
ll pa[1000010], dep[1000010];

void init()
{
	
}

ll calc_dp(ll X)
{
	if((ll)st[X].size() == 0)
		return 0;
	
	if((ll)st[X].size() == 1)
		return (*st[X].begin());
	
	ll ret = 0;
	auto p = st[X].rbegin();
	
	ret = max(ret, (*p));
	p++;
	ret = max(ret, (*p) + 1);
	
	return ret;
}

ll calc_dp2(ll X)
{
	ll ret = dp[X];
	
	if(!st2[X].empty())
		ret = max(ret, (*st2[X].rbegin()));
	
	if((ll)st[X].size() >= 2)
	{
		auto p = st[X].rbegin();
		auto p2 = p;
		
		p2++;
		ret = max(ret, (*p) + (*p2) + 1);
	}
	
	if((ll)st[X].size() >= 3)
	{
		auto p = st[X].rbegin();
		auto p2 = p;
		p2++;
		auto p3 = p2;
		p3++;
		
		ret = max(ret, (*p2) + (*p3) + 2);
	}
	
	return ret;
}

void observation(ll P)
{
	n++;
	dp[n] = 0;
	dp2[n] = 0;
	st[P].insert(0);
	st2[P].insert(0);
	pa[n] = P;
	dep[n] = dep[P] + 1;
	
	ll now = P;
	
	while(now)
	{
		ll gap = calc_dp(now);
		
		if(gap == dp[now])
			break;
		
		if(pa[now])
			st[pa[now]].erase(st[pa[now]].find(dp[now]));
		
		dp[now] = gap;
		
		if(pa[now])
			st[pa[now]].insert(dp[now]);
		
		now = pa[now];
	}
	
	ll D = dep[now];
	
	now = P;
	
	while(now)
	{
		ll gap = calc_dp2(now);
		
		if(gap == dp2[now] && dep[now] < D)
			break;
		
		if(pa[now])
			st2[pa[now]].erase(st2[pa[now]].find(dp2[now]));
		
		dp2[now] = gap;
		
		if(pa[now])
			st2[pa[now]].insert(dp2[now]);
		
		now = pa[now];
	}
	
	/*cout << "update  :" << P en;
	
	for(ll i = 1 ; i <= n ; i++)
		cout << dp[i] sp;
	
	cout en;
	
	for(ll i = 1 ; i <= n ; i++)
		cout << dp2[i] sp;
	
	cout en;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cout << "i : " << i en;
		cout << "st1\n";
		
		for(auto &j : st[i])
			cout << j sp;
		
		cout << "\nst2\n";
		
		for(auto &j : st2[i])
			cout << j sp;
		
		cout << "\ndp : " << calc_dp2(i) en;
	}*/
}

int analyze(ll R)
{
	return dp2[R];
}