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
char a[110][110];
ll ans[110][110];

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 0 ; i < n ; i++)
		cin >> a[i];
	
	for(ll i = 0 ; i < n ; i++)
	{
		ll gap = -INF;
		
		for(ll j = 0 ; j < m ; j++)
		{
			if(a[i][j] == 'c')
				ans[i][j] = gap = 0;
			else if(gap == -INF)
				ans[i][j] = -1;
			else
				ans[i][j] = ++gap;
			
			cout << ans[i][j] sp;
		}
		
		cout en;
	}
	
	return 0;
}