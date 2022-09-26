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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

ll n;
char a[110];
ll ans;

int main(void)
{
	fastio
	
	cin >> n;
	cin >> a;
	
	for(ll i = 0 ; i < n / 2 ; i++)
		ans += (a[i] != a[n - 1 - i]);
	
	cout << ans;
	return 0;
}