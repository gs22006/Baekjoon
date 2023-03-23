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

ll n, k;
vector<ll> jin;
ll ans[1000010];
ll w;
vector<ll> vec[1010];
ll b1[1000010];
ll ans2;

void f(ll X, ll Y)
{
	jin.clear();
	
	while(X)
	{
		jin.push_back(X % Y);
		X /= Y;
	}
	
	reverse(jin.begin(), jin.end());
}

int main(void)
{
	fastio
	
	cin >> n >> k;
	
	for(ll i = 2 ; i <= n + 1 ; i++)
		ans[i] = INF;
	
	k++;
	ans[k] = 0;
	
	for(ll i = 2 ; i <= k ; i++)
	{
		f(k, i);
		
		if((ll)jin.size() >= 3)
		{
			ll maxx = 0;
			
			for(auto &j : jin)
				maxx = max(maxx, j);
			
			for(ll j = maxx + 1 ; j <= 1000 ; j++)
			{
				ll gap = 0;
				
				for(auto &k : jin)
				{
					gap = gap * j + k;
					
					if(gap > n + 1)
						break;
				}
				
				if(gap > n + 1)
					continue;
				
				ans[gap] = min(ans[gap], i + j);
			}
		}
		
		else
		{
			w = i;
			break;
		}
	}
	
	for(ll i = w ; i <= k ; i++)
	{
		ll AA = k / i;
		ll BB = k % i;
		
		vec[AA].push_back(i);
		b1[AA] = BB;
	}
	
	for(ll i = 1 ; i <= 1000 ; i++)
	{
		if(vec[i].empty())
			continue;
		
		ll p = (ll)vec[i].size() - 1;
		
		for(ll j = b1[i] ; j <= n + 1 ; j += i)
		{
			if(j <= 1)
				continue;
			
			p = min(p, (ll)vec[i].size() - 1);
			
			while(p >= 0)
			{
				ll P = vec[i][p];
				ll AA = i;
				ll BB = k % P;
				
				if(j <= BB)
					break;
				
				if((j - BB) / AA <= max(AA, BB))
					break;
				
				ans[j] = min(ans[j], (j - BB) / AA + P);
				p--;
			}
			
			p++;
		}
	}
	
	for(ll i = 2 ; i <= n + 1 ; i++)
		ans2 += ans[i];
	
	cout << ans2;
	return 0;
}