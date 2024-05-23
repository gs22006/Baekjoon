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

ll L, D, X;

int main(void)
{
	fastio
	
	cin >> L >> D >> X;
	
	for(ll i = L ; i <= D ; i++)
	{
		ll now = i;
		ll ff = 0;
		
		while(now)
		{
			ff += now % 10;
			now /= 10;
		}
		
		if(ff == X)
		{
			cout << i en;
			break;
		}
	}
	
	for(ll i = D ; i >= L ; i--)
	{
		ll now = i;
		ll ff = 0;
		
		while(now)
		{
			ff += now % 10;
			now /= 10;
		}
		
		if(ff == X)
		{
			cout << i en;
			break;
		}
	}
	
	return 0;
}