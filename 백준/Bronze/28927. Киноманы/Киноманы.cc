#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll a, b, c;
ll d, e, f;

int main(void)
{
	fastio
	
	cin >> a >> b >> c;
	cin >> d >> e >> f;
	
	if(a * 3 + b * 20 + c * 120 < d * 3 + e * 20 + f * 120)
		cout << "Mel";
	else if(a * 3 + b * 20 + c * 120 > d * 3 + e * 20 + f * 120)
		cout << "Max";
	else
		cout << "Draw";
	
	return 0;
}