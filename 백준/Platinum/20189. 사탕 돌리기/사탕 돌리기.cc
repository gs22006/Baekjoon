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

ll n, k, q;
vector<ll> w[2010];
ll a[2010][2010];
ll sum;

int main(void)
{
	fastio
	
	cin >> n >> k >> q;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= k ; j++)
		{
			cin >> a[i][j];
			
			if(a[i][j] >= i)
				sum += a[i][j] - i;
			else
				sum += n + a[i][j] - i;
		}
	}
	
	ll ff = 0, ff2 = 0;
	
	for(ll i = 1 ; i <= k ; i++)
	{
		if(a[1][i] != 1)
			ff = 1;
	}
	
	for(ll i = 2 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= k ; j++)
		{
			if(a[i][j] != i)
				ff2 = 1;
		}
	}
	
	if(!ff && ff2)
		sum += n;
	
	if((sum + n - 1) / n <= q)
		cout << 1;
	else
		cout << 0;
	
	return 0;
}