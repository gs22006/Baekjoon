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
ll a[1010];
ll q;
ll all, bll, cll;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	cin >> q;
	
	while(q--)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> all >> bll >> cll;
			
			ll ans = 0;
			
			for(ll i = all ; i <= bll ; i++)
				ans += (a[i] == cll);
			
			cout << ans en;
		}
		
		else
		{
			cin >> all >> bll;
			
			for(ll i = all ; i <= bll ; i++)
				a[i] = 0;
		}
	}
	
	return 0;
}