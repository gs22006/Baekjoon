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
ll a[] = {12, 11, 11, 10, 9, 9, 9, 8, 7, 6, 6};
ll b[] = {1600, 894, 1327, 1311, 1004, 1178, 1357, 837, 1055, 556, 773};

int main(void)
{
	fastio
	
	cin >> n;
	cout << a[n - 1] sp << b[n - 1];
	return 0;
}