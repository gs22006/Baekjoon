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
ld a[510];
ld P[510];
ld ans[510];

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 0 ; i <= n ; i++)
	{
		P[i] = (ld)K / (ld)n;
		
		for(ll j = 1 ; j <= i ; j++)
			P[i] *= (ld)(n - K - j + 1) / (ld)(n - j);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= n ; j++)
		{
			if(n - j - 1 < K - 1)
				break;
			
			ans[i] += P[j] * a[(i - j - 1 + n) % n + 1];
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
		cout << ans[i] sp;
	
	return 0;
}