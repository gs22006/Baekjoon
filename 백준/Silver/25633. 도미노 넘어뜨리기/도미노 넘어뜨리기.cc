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

ll n;
ll a[1010];
ll ans;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll cou = 1;
		ll sum = a[i];
		
		for(ll j = i + 1 ; j <= n ; j++)
		{
			if(a[j] <= sum)
			{
				sum += a[j];
				cou++;
			}
		}
		
		ans = max(ans, cou);
	}
	
	cout << ans;
	return 0;
}