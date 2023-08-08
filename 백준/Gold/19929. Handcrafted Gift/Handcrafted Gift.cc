#include "gift.h"
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

ll arr[5000010];
ll num[5000010];
string ans;
vector<pll> vec;

int construct(int n, int r, vector<int> a, vector<int> b, vector<int> x)
{
	for(ll i = 0 ; i < r ; i++)
	{
		if(x[i] == 1)
			vec.push_back({a[i], b[i]});
	}
	
	ll cc = 1, cc2 = 1;
	ll gapa = 0;
	
	if(!vec.empty())
	{
		sort(vec.begin(), vec.end());
		
		ll S = vec[0].fi;
		ll E = vec[0].se;
		
		for(auto &i : vec)
		{
			if(!gapa)
			{
				gapa = 1;
				continue;
			}
			
			if(E < i.fi)
			{
				for(ll j = S ; j <= E ; j++)
					arr[j] = cc;
				
				cc++;
				S = i.fi, E = i.se;
			}
			
			else
				E = max(E, i.se);
		}
		
		for(ll j = S ; j <= E ; j++)
			arr[j] = cc;
		
		cc++;
	}
	
	for(ll i = 0 ; i < n ; i++)
	{
		if(!arr[i])
			arr[i] = cc++;
	}
	
	for(ll i = 0 ; i < n ; i++)
	{
		if(!num[arr[i]])
			num[arr[i]] = cc2++;
	}
	
	for(ll i = 0 ; i < r ; i++)
	{
		if(x[i] == 2)
		{
			if(num[arr[b[i]]] - num[arr[a[i]]] == 0)
				return 0;
		}
	}
	
	char now = 'R';
	
	ans.push_back('R');
	
	for(ll i = 1 ; i < n ; i++)
	{
		if(arr[i] != arr[i - 1])
			now = 'B' + 'R' - now;
		
		ans.push_back(now);
	}
	
	craft(ans);
	return 1;
}