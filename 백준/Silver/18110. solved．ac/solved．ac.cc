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
ll a[300010];
ll E;
ll sum;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	if(n == 0)
	{
		cout << 0;
		return 0;
	}
	
	E = n * 15.0;
	
	if(E % 100 >= 50)
		E = E / 100 + 1;
	else
		E = E / 100;
	
	for(ll i = 1 + E ; i <= n - E ; i++)
		sum += a[i];
	
	n -= E * 2;
	
	if(sum % n * 2 >= n)
		sum = sum / n + 1;
	else
		sum = sum / n;
	
	cout << sum;
	return 0;
}