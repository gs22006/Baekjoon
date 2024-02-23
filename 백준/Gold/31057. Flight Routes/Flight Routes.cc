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
char a[1010][1010];
ll dp[1010][1010];
ll ans;
vector<ll> vec[1010];

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i < n ; i++)
	{
		for(ll j = i + 1 ; j <= n ; j++)
			cin >> a[i][j];
	}
	
	for(ll i = n - 1 ; i >= 1 ; i--)
	{
		for(ll j = i + 1 ; j <= n ; j++)
		{
			if(dp[i][j] % 2 != a[i][j] - '0')
			{
				ans++;
				vec[i].push_back(j);
				dp[i][j] ^= 1;
				
				for(ll k = j + 1 ; k <= n ; k++)
					dp[i][k] = (dp[i][k] + dp[j][k]) % 2;
			}
		}
	}
	
	cout << ans;
	return 0;
}