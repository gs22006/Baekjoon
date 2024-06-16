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
ll n;

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		if(n == 1)
			cout << 1 en;
		else if(n == 2)
			cout << 2 en;
		else if(n == 3)
			cout << 6 en;
		else if(n == 4)
			cout << 4 en;
		else
			cout << 0 en;
	}
	
	return 0;
}