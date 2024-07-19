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

ll a, b, s, m, n;

int main(void)
{
	while(1)
	{
		scanf("%lld %lld %lld %lld %lld", &a, &b, &s, &n, &m);
		
		if(a + b + s + m + n == 0)
			break;
		
		ld t = atan((ld)(m * b) / (ld)(n * a));
		ld theta = round(100.0 * atan((ld)(m * b) / (ld)(n * a)) / 3.14159265358979 * 180) / 100.0;
		ld v = round((ld)(n * a * 100) / (ld)(s * cos(t))) / 100.0;
		
		printf("%.2Lf %.2Lf\n", theta, v);
	}
	
	return 0;
}