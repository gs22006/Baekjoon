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

int main(void)
{
	fastio
	
	cin >> n;
	
	if(n == 1)
		cout << 1;
	else if(n == 12)
		cout << 2;
	else if(n == 123)
		cout << 3;
	else if(n == 1234)
		cout << 4;
	else if(n == 12345)
		cout << 5;
	else if(n == 123456)
		cout << 6;
	else if(n == 1234567)
		cout << 7;
	else if(n == 12345678)
		cout << 8;
	else if(n == 123456789)
		cout << 9;
	else
		cout << -1;
	
	return 0;
}