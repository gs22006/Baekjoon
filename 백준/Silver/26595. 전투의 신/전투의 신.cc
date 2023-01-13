#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

ll n;
ll a, pa, b, pb;
ll ans, x, y;

int main(void)
{
	fastio
	
	cin >> n;
	cin >> a >> pa >> b >> pb;
	
	for(ll i = 0 ; i <= n / pa ; i++)
	{
		if(ans < i * a + (n - pa * i) / pb * b)
		{
			ans = i * a + (n - pa * i) / pb * b;
			x = i;
			y = (n - pa * i) / pb;
		}
	}
	
	cout << x sp << y;
	return 0;
}