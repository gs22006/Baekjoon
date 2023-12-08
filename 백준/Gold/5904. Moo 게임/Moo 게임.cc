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
ll dp[1010];

int main(void)
{
	fastio
	
	cin >> n;
	
	dp[2] = 3;
	
	for(ll i = 3 ; i < 50 ; i++)
		dp[i] = dp[i - 1] * 2 + i + 1;
	
	for(ll i = 49 ; i >= 2 ; i--)
	{
		if(n <= dp[i - 1])
			continue;
		
		if(n == dp[i - 1] + 1)
		{
			cout << "m";
			return 0;
		}
		
		if(n <= dp[i - 1] + i + 1)
		{
			cout << "o";
			return 0;
		}
		
		n -= dp[i - 1] + 1 + i;
	}
	
	return 0;
}