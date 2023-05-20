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

ll ans = -1;
ll a, b, c;

void f(ll X)
{
	if(ans == -1)
		ans = X;
	
	else
	{
		if(X % 2 == 0 && ans % 2 == 1)
			return;
		else if(X % 2 == 0 && ans % 2 == 0)
			ans = max(ans, X);
		else if(X % 2 == 1 && ans % 2 == 0)
			ans = X;
		else if(X % 2 == 1 && ans % 2 == 1)
			ans = max(ans, X);
	}
}

int main(void)
{
	fastio
	
	cin >> a >> b >> c;
	
	f(a);
	f(b);
	f(c);
	f(a * b);
	f(b * c);
	f(a * c);
	f(a * b * c);
	
	cout << ans;
	return 0;
}