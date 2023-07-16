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
string all;
ll ans;

int main(void)
{
	fastio
	
	cin >> n;
	
	while(n--)
	{
		cin >> all;
		
		if(all[0] == 'P')
			ans += 1500;
		else if(all[0] == 'M')
			ans += 6000;
		else if(all[0] == 'S')
			ans += 15500;
		else if(all[0] == 'C')
			ans += 40000;
		else if(all[0] == 'T')
			ans += 75000;
		else
			ans += 125000;
	}
	
	cout << ans en;
	return 0;
}