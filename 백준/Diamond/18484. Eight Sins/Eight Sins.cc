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

ll n, K;
ll last;
ll all;
map<ll, ll> mp[110];
ll gu = 1;

ll query(ll I, ll X)
{
	if(mp[I].find(X) != mp[I].end())
		return mp[I][X];
	
	printf("%lld\n", X);
	fflush(stdout);
	
	scanf(" %c", &all);
	
	if(all == '<')
		return mp[I][X] = -1;
	
	if(all == '=')
		return mp[I][X] = 0;
	
	return mp[I][X] = 1;
}

int main(void)
{
	scanf("%lld %lld", &n, &K);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(query(i, gu * K / n) == 1)
			gu++;
		
		if(!query(i, gu * K / n))
			continue;
		
		ll l = (gu - 1) * K / n + 1, r = gu * K / n;
		ll ff = 0;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(query(i, mid) == 0)
			{
				ff = 1;
				break;
			}
			
			if(query(i, mid) == 1)
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		if(!ff)
			query(i, l);
	}
	
	return 0;
}