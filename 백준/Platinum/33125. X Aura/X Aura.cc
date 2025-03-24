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

ll n, m, X;
char all;
ll a[1010][1010];
ll q;
ll ff;
ll Rs, Cs, Rf, Cf;
ll Gnu[1010][1010], Snu[1010][1010];

ll pw(ll X, ll Y)
{
	ll ret = 1;
	
	while(Y--)
		ret *= X;
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n >> m >> X;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			cin >> all;
			a[i][j] = all - '0';
		}
	}
	
	for(ll i = 2 ; i <= n ; i++)
	{
		for(ll j = 2 ; j <= m ; j++)
		{
			if(pw(a[i - 1][j - 1] - a[i - 1][j], X) + pw(a[i - 1][j] - a[i][j], X) + pw(a[i][j] - a[i][j - 1], X) + pw(a[i][j - 1] - a[i - 1][j - 1], X))
				ff = 1;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 2 ; j <= m ; j++)
			Gnu[i][j] = Gnu[i][j - 1] + pw(a[i][j - 1] - a[i][j], X);
	}
	
	for(ll j = 1 ; j <= m ; j++)
	{
		for(ll i = 2 ; i <= n ; i++)
			Snu[i][j] = Snu[i - 1][j] + pw(a[i - 1][j] - a[i][j], X);
	}
	
	cin >> q;
	
	while(q--)
	{
		cin >> Rs >> Cs >> Rf >> Cf;
		
		if(ff)
		{
			cout << "INVALID\n";
			continue;
		}
		
		ll ans = 0;
		
		ans += Gnu[Rs][Cf] - Gnu[Rs][Cs];
		ans += Snu[Rf][Cf] - Snu[Rs][Cf];
		
		cout << ans en;
	}
	
	return 0;
}