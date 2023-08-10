#include "workshop.h"
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
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

ll ten[200010], three[200010], two[200010];
ll cc;

void init(void)
{
	vector<ll> vv;
	
	vv.clear();
	
	for(ll i = 0 ; i < 10 ; i++)
		vv.push_back(0);
	
	for(ll i = 0 ; i < 10 ; i++)
		vv.push_back(1);
	
	cc = 0;
	
	do
	{
		ll gap = 0;
		
		for(ll i = 0 ; i < 20 ; i++)
			gap = gap + vv[i] * (1LL << i);
		
		ten[cc++] = gap;
	}while(next_permutation(vv.begin(), vv.end()));
	
	reverse(ten, ten + cc);
	vv.clear();
	
	for(ll i = 0 ; i < 3 ; i++)
		vv.push_back(0);
	
	for(ll i = 0 ; i < 3 ; i++)
		vv.push_back(1);
	
	cc = 0;
	
	do
	{
		ll gap = 0;
		
		for(ll i = 0 ; i < 6 ; i++)
			gap = gap + vv[i] * (1LL << i);
		
		three[cc++] = gap;
	}while(next_permutation(vv.begin(), vv.end()));
	
	reverse(three, three + cc);
	vv.clear();
	
	for(ll i = 0 ; i < 2 ; i++)
		vv.push_back(0);
	
	for(ll i = 0 ; i < 2 ; i++)
		vv.push_back(1);
	
	cc = 0;
	
	do
	{
		ll gap = 0;
		
		for(ll i = 0 ; i < 4 ; i++)
			gap = gap + vv[i] * (1LL << i);
		
		two[cc++] = gap;
	}while(next_permutation(vv.begin(), vv.end()));
	
	reverse(two, two + cc);
}

ll comp(ll X, ll Y)
{
	for(ll i = 0 ; ; i++)
	{
		if(!(X & (1LL << i)) && (Y & (1LL << i)))
			return i;
	}
}

int morning(int my_num, int right_num)
{
	return comp(ten[my_num], ten[right_num]);
}

int afternoon(int left_num, int my_num, int right_num)
{
	return comp(two[comp(three[left_num], three[my_num])], two[comp(three[my_num], three[right_num])]);
}

int evening(int left_num, int my_num, int right_num)
{
	if(my_num <= 2)
		return my_num;
	
	ll chk[5] = {0, };
	
	chk[left_num] = 1;
	chk[right_num] = 1;
	
	for(ll i = 0 ; i < 3 ; i++)
	{
		if(!chk[i])
			return i;
	}
}
