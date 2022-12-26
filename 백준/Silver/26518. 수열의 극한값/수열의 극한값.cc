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

ll b, c, a1, a2;

int main(void)
{
	fastio
	
	cin >> b >> c >> a1 >> a2;
	
	ld ans = b + sqrt(b * b + 4 * c);
	ans /= (ld)2;
	
	cout << ans;
	return 0;
}