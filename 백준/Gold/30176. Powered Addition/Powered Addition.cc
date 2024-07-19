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

ll t;
ll n;
ll a[100010];
ll P[100010];

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			cin >> a[i];
			P[i] = 0;
		}
		
		for(ll i = 2 ; i <= n ; i++)
		{
			ll last = a[i - 1] + P[i - 1];
			
			if(a[i] < last)
				P[i] = last - a[i];
		}
		
		ll maxx = 0;
		
		for(ll i = 1 ; i <= n ; i++)
			maxx = max(maxx, P[i]);
		
		for(ll i = 0 ; ; i++)
		{
			if(maxx <= 0)
			{
				cout << i en;
				break;
			}
			
			maxx -= (1LL << i);
		}
	}
	
	return 0;
}