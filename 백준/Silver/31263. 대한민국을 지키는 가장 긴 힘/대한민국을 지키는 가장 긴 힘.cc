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
char a[5010];
ll dp[5010];

int main(void)
{
	fastio
	
	cin >> n;
	cin >> a;
	
	for(ll i = n ; i >= 1 ; i--)
		a[i] = a[i - 1];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		dp[i] = INF;
		
		for(ll j = i - 1 ; j >= 0 ; j--)
		{
			if(i - j >= 4)
				break;
			
			vector<ll> num;
			ll gap = 0;
			
			for(ll k = j + 1 ; k <= i ; k++)
			{
				num.push_back(a[k] - '0');
				gap = gap * 10 + a[k] - '0';
			}
			
			if(num[0] == 0)
				continue;
			
			if(gap <= 641)
				dp[i] = min(dp[i], dp[j] + 1);
		}
	}
	
	cout << dp[n];
	return 0;
}