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
ll a[1000010];

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	if(K == 0)
	{
		cout << 0;
		return 0;
	}
	
	ll ans = n;
	
	for(ll i = 1 ; i <= n ; i++)
		a[i]--;
	
	ll nam = 0;
	ll sum = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i] & 1)
		{
			nam++;
			a[i]--;
		}
		
		sum += a[i] / 2;
	}
	
	if(sum + nam < K)
	{
		cout << -1;
		return 0;
	}
	
	if(K <= sum)
		ans += K * 2 - 1;
	else
		ans += sum * 2 + K - sum;
	
	cout << ans;
	return 0;
}