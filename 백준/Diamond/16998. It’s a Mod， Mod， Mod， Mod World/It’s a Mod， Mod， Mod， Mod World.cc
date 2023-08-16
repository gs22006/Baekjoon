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

ll t;
ll a, b, c;

ll f(ll A, ll B, ll C)
{
	if(C < 0)
		return 0;
	
	if(B > A)
		swap(A, B);
	
	if(B == 0)
		return C / A;
	
	ll q = A / B;
	ll r = A % B;
	ll gap = C * q / A;
	ll ret = f(B, r, C - B * gap);
	ll L = 1, R = gap / q;
	
	if(R < 1)
		return ret;
	
	ret += gap * (R - L + 1);
	ret -= q * (L + R) * (R - L + 1) / 2;
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> a >> b >> c;
		
		ll B = a, C = b, N = c;
		ll ans = B * (N + 1) * N / 2;
		
		cout << ans - f(C, B, (N + 1) * B) * C en;
	}
	
	return 0;
}