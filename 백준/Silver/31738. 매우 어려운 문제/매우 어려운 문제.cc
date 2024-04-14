#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
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
ll ans = 1;
 
int main(void)
{
	fastio
	
	cin >> n >> m;
	
	assert(2 <= n && n <= 1000000000000000000);
	assert(2 <= m && m <= 10000000);
	
	if(n >= m)
	{
		cout << 0;
		return 0;
	}
	
	for(ll i = 1 ; i <= n ; i++)
		ans = ans * i % m;
	
	cout << ans;
	return 0;
}
