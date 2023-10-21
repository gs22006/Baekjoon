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

ll K, n, m;
ll a[2010][2010];
ll ans = INF;
ll nu[2010][2010];
ll tmp[2010][2010];

ll sum(ll x1, ll y1, ll x2, ll y2)
{
	return nu[x2][y2] - nu[x1 - 1][y2] - nu[x2][y1 - 1] + nu[x1 - 1][y1 - 1];
}

ll f(ll Lf, ll Rg)
{
	ll U = 1, D = n;
	ll L = 1, R = m;
	
	while(1)
	{
		if(U > D)
			break;
		
		if(sum(U, L, U, R) <= K)
			U++;
		else if(sum(D, L, D, R) <= K)
			D--;
		else if(L < Lf && sum(U, L, D, L) <= K)
			L++;
		else if(R > Rg && sum(U, R, D, R) <= K)
			R--;
		else
			break;
	}
	
	return (U > D);
}

void solve(void)
{
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			nu[i][j] = nu[i - 1][j] + nu[i][j - 1] - nu[i - 1][j - 1] + a[i][j];
	}
	
	ll s = 1, e = 1;
	
	while(e <= m)
	{
		e = max(e, s);
		
		ll chk = f(s, e);
		
		if(chk)
		{
			ans = min(ans, n + m -  (e - s + 1));
			e++;
		}
		
		else
			s++;
	}
}

int main(void)
{
	fastio
	
	cin >> K >> m >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	}
	
	solve();
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			tmp[j][i] = a[i][j];
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			a[i][j] = tmp[i][j];
	}
	
	swap(n, m);
	solve();
	
	cout << ans;
	return 0;
}