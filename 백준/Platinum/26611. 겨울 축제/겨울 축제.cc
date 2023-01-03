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

ll n, m, k;
ll a[2000010];
ll b[2000010];
ll tmp[2000010];
ll ans[2000010];
ll carry;

int main(void)
{
	fastio
	
	cin >> n >> m >> k;
	
	for(ll i = 0 ; i <= n ; i++)
	{
		cin >> a[i];
		tmp[i] = a[i];
	}
	
	for(ll i = 0 ; i <= n + 50 ; i++)
	{
		b[i] = tmp[i];
		tmp[i + 1] += tmp[i] / k;
		tmp[i] %= k;
	}
	
	for(ll i = n + 50 ; i >= 0 ; i--)
	{
		ll gaet = (b[i] - carry) / m * m;
		ans[i] += (b[i] - carry) / m;
		carry += gaet;
		
		if(carry <= a[i])
		{
			a[i] -= carry;
			carry = 0;
		}
		
		else
		{
			carry -= a[i];
			a[i] = 0;
		}
		
		carry *= k;
	}
	
	for(ll i = 0 ; i <= n + 50 ; i++)
	{
		ans[i + 1] += ans[i] / k;
		ans[i] %= k;
	}
	
	ll w = -1;
	
	for(ll i = n + 50 ; i >= 0 ; i--)
	{
		if(ans[i])
		{
			w = i;
			break;
		}
	}
	
	if(w == -1)
	{
		cout << 0;
		return 0;
	}
	
	for(ll i = w ; i >= 0 ; i--)
		cout << ans[i];
	
	return 0;
}