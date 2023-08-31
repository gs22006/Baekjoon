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

ll n, m;
char a[3010][3010];
ll O[3010][3010], I[3100][3010];
ll ans;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = m ; j >= 1 ; j--)
		{
			O[i][j] = O[i][j + 1];
			
			if(a[i][j] == 'O')
				O[i][j]++;
		}
	}
	
	for(ll j = 1 ; j <= m ; j++)
	{
		for(ll i = n ; i >= 1 ; i--)
		{
			I[i][j] = I[i + 1][j];
			
			if(a[i][j] == 'I')
				I[i][j]++;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			if(a[i][j] == 'J')
				ans += I[i][j] * O[i][j];
		}
	}
	
	cout << ans;
	return 0;
}