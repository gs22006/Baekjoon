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
ll a[1010];
ld dp[1010];

int main(void)
{
	fastio
	
	cin >> n;
	cin >> K;
	
	for(ll i = 1 ; i <= K ; i++)
		cin >> a[i];
	
	dp[0] = 1;
	
	for(ll i = 1 ; i <= K ; i++)
		dp[i] = dp[i - 1] * (ld)(n - a[i]) / (ld)n + (1 - dp[i - 1]) * (ld)a[i] / (ld)n;
	
	cout << n * dp[K];
	return 0;
}