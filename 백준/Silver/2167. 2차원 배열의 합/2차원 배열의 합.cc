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
ll a[310][310];
ll nu[310][310];
ll q;
ll all, bll, cll, dll;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			cin >> a[i][j];
			nu[i][j] = nu[i - 1][j] + nu[i][j - 1] - nu[i - 1][j - 1] + a[i][j];
		}
	}
	
	cin >> q;
	
	while(q--)
	{
		cin >> all >> bll >> cll >> dll;
		cout << nu[cll][dll] - nu[all - 1][dll] - nu[cll][bll - 1] + nu[all - 1][bll - 1] en;
	}
	
	return 0;
}