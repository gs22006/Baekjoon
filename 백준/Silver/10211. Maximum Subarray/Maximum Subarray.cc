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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

ll t;
ll n;
ll a[1010];
ll nu[1010];

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
			nu[i] = nu[i - 1] + a[i];
		}
		
		ll ans = MIN;
		ll minn = 0;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			ans = max(ans, nu[i] - minn);
			minn = min(minn, nu[i]);
		}
		
		cout << ans en;
	}
	
	return 0;
}