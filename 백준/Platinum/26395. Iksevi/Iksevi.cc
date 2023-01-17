#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

ll n;
ll x, y;
unordered_map<ll, ll> ans;

ll f(ll X)
{
	ll ret = 0;
	
	while(X % 2 == 0)
	{
		X /= 2;
		ret++;
	}
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n;
	
	while(n--)
	{
		cin >> x >> y;
		
		if(!x && !y)
		{
			cout << 0 en;
			continue;
		}
		
		if(!y)
			swap(x, y);
		
		ll g = __gcd(x, y);
		ll gap = 1;
		
		if(!x)
			g = y;
		
		else
		{
			ll fx = f(x);
			ll fy = f(y);
			
			if(fx == fy)
			{
				cout << 0 en;
				continue;
			}
			
			if(fx > fy)
				swap(x, y);
		}
		
		while(g % 2 == 0)
			g /= 2;
		
		if(ans.find(g) != ans.end())
		{
			cout << ans[g] en;
			continue;
		}
		
		ll G = g;
		
		for(ll i = 2 ; i * i <= g ; i++)
		{
			ll cou = 0;
			
			while(G % i == 0)
			{
				G /= i;
				cou++;
			}
			
			gap *= (cou + 1);
		}
		
		if(G != 1)
			gap *= 2;
		
		ans[g] = gap;
		cout << gap en;
	}
	
	return 0;
}