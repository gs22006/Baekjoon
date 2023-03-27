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

ll x, a, b;
ll ans[] = {0, 287, 311, 80, 96, 609, 675, 76, 315, 543, 455, 351, 342, 188, 204, 286, 47, 0, 175, 55, 94, 630, 516, 69, 431, 364, 615, 171, 177, 252, 116, 172, 55, 175, 0, 47, 69, 516, 630, 94, 171, 615, 364, 431, 172, 116, 252, 177, 80, 311, 287, 0, 76, 675, 609, 96, 351, 455, 543, 315, 286, 204, 188, 342};
ll cc;

int main(void)
{
	fastio
	
	cin >> x;
	cin >> a >> b;
	
	for(ll i = 1 ; i <= 4 ; i++)
	{
		for(ll j = 1 ; j <= 4 ; j++)
		{
			for(ll k = 1 ; k <= 4 ; k++)
			{
				if(i == x && j == a && k == b)
				{
					cout << ans[cc];
					return 0;
				}
				
				cc++;
			}
		}
	}
	
	return 0;
}