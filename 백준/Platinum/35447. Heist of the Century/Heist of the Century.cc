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

ll n;
vector<ll> tmp;
ll ans[100010];

ll query(void)
{
	ll ret = 0;
	
	for(auto &i : tmp)
		printf("%lld ", i);
	
	printf("\n");
	fflush(stdout);
	
	scanf("%lld", &ret);
	
	return ret;
}

int main(void)
{
	scanf("%lld", &n);
	
	if(n == 1)
	{
		tmp.clear();
		tmp.push_back(1);
		
		if(!query())
			return 0;
		
		tmp.clear();
		tmp.push_back(2);
		query();
		
		return 0;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		tmp.clear();
		
		for(ll j = 1 ; j <= n ; j++)
		{
			if(i == j)
				tmp.push_back(1);
			else
				tmp.push_back(n + 1);
		}
		
		ll gap = query();
		
		if(gap == 0)
			return 0;
		
		tmp.clear();
		
		for(ll j = 1 ; j <= n ; j++)
		{
			if(i == j)
				tmp.push_back(n * 2);
			else
				tmp.push_back(n + 1);
		}
		
		ll gap2 = query();
		
		if(gap2 == 0)
			return 0;
		
		if(gap > n)
			ans[i] = gap + 1;
		else if(gap2 > n)
			ans[i] = n * 2 - gap2;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(ans[i])
			continue;
		
		tmp.clear();
		
		for(ll j = 1 ; j <= n ; j++)
		{
			if(ans[j])
				tmp.push_back(ans[j]);
			else if(i == j)
				tmp.push_back(1);
			else
				tmp.push_back(n + 1);
		}
		
		if(n == 2)
		{
			ll gap = query();
			
			if(!gap)
				return 0;
			
			if(gap == 2)
				ans[i] = 3;
			else
				ans[i] = 2;
		}
		
		else
		{
			ll gap = query();
			
			if(!gap)
				return 0;
			
			ans[i] = gap + 1;
		}
	}
	
	tmp.clear();
	
	for(ll i = 1 ; i <= n ; i++)
		tmp.push_back(ans[i]);
	
	ll ret = query();
	
	if(ret)
		assert(0);
	
	return 0;
}