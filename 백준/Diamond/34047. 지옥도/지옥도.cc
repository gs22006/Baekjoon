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
 
ll is_prime(ll X)
{
	for(ll i = 2 ; i * i <= X ; i++)
	{
		if(X % i == 0)
			return 0;
	}
	
	return 1;
}
 
int main(void)
{
	fastio
	
	cin >> n >> m;
	
	if(n == 0 || m == 1)
	{
		cout << 0 sp << 1;
		return 0;
	}
	
	if(m == 2)
	{
		if(n * 2 - 1 > 1000000000 && is_prime(2 * n - 1) && is_prime(2 * n - 3))
			cout << n - 2 sp << m;
		else
			cout << n sp << m;
		
		return 0;
	}
	
	ll gap = n / 3;
	
	gap = max(gap, min(n, 1000000000LL - n));
	gap = min(gap + 1, m);
	
	cout << n sp << gap;
	return 0;
}
