#include <bits/stdc++.h>

using namespace std;
typedef int ll;
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

ll S, B;
ll dp[5010][5010];
ll nu1[5010][5010];
ll ss = 1000000007;

int main(void)
{
	fastio
	
	cin >> S >> B;
    
    dp[0][0] = 1;
	
	for(ll j = 1 ; j <= B ; ++j)
	{
		for(ll i = 1 ; i <= j ; ++i)
			dp[i][j] = ((dp[i][j - i] + (dp[i - 1][j - 1] << 1) % ss) % ss - (min(i, j) >= 2 ? dp[i - 2][j - 2] : 0)) % ss;
        
        dp[j][j] = 1;
	}
	
	cout << (dp[S][B] + ss) % ss;
	return 0;
}