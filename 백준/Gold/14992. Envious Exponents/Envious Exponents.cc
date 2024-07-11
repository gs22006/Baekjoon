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
ll a[110], b[110];

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 0 ; i <= 60 ; i++)
		a[i] = (n & (1LL << i));
	
	for(ll i = 60 ; i >= 0 ; i--)
	{
		if(a[i])
		{
			b[i] = 1;
			K--;
			continue;
		}
		
		ll cou = 0;
		
		for(ll j = i - 1 ; j >= 0 ; j--)
		{
			if(a[j])
				cou++;
			else
				break;
		}
		
		if(cou >= K)
		{
			b[i] = 1;
			K--;
			break;
		}
	}
	
	for(ll i = 0 ; i <= 60 ; i++)
	{
		if(!K)
			break;
		
		if(!b[i])
		{
			b[i] = 1;
			K--;
		}
	}
	
	ll ans = 0;
	
	for(ll i = 60 ; i >= 0 ; i--)
		ans = ans * 2 + b[i];
	
	cout << ans;
	return 0;
}