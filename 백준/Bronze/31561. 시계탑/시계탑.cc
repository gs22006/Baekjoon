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

ll m;

int main(void)
{
	fastio
	
	cin >> m;
	
	if(m <= 30)
	{
		cout << m / 2;
		
		if(m & 1)
			cout << ".5";
		else
			cout << ".0";
	}
	
	else
	{
		cout << 15 + (m - 30) * 3 / 2;
		
		if(((m - 30) * 3) & 1)
			cout << ".5";
		else
			cout << ".0";
	}
	
	return 0;
}