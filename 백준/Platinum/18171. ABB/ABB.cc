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
string a, b;
ll fail[1000010];
ll p;

int main(void)
{
	fastio
	
	cin >> n;
	cin >> a;
	
	b += a;
	reverse(a.begin(), a.end());
	
	if(a == b)
	{
		cout << 0;
		return 0;
	}
	
	b = a + b;
	
	fail[0] = 0;
	p = 0;
	
	for(ll i = 1 ; i < n * 2 ; i++)
	{
		while(p && a[p] != b[i])
			p = fail[p - 1];
		
		if(a[p] == b[i])
			fail[i] = ++p;
	}
	
	cout << n - fail[n * 2 - 1];
	return 0;
}