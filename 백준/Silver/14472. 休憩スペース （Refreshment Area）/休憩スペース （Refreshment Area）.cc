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

ll n, m, d;
char a[110][110];
ll ans;

int main(void)
{
	fastio
	
	cin >> n >> m >> d;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll cou = 0;
		
		for(ll j = 1 ; j <= m ; j++)
		{
			if(a[i][j] == '#')
				ans += max(0LL, cou - d + 1), cou = 0;
			else
				cou++;
		}
		
		ans += max(0LL, cou - d + 1);
	}
	
	for(ll j = 1 ; j <= m ; j++)
	{
		ll cou = 0;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(a[i][j] == '#')
				ans += max(0LL, cou - d + 1), cou = 0;
			else
				cou++;
		}
		
		ans += max(0LL, cou - d + 1);
	}
	
	cout << ans;
	return 0;
}