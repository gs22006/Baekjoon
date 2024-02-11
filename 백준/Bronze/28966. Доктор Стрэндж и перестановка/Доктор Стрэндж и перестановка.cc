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
ll a[1010];
vector<ll> O, E;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(i % 2 == 1 && a[i] % 2 == 0)
			O.push_back(i);
		else if(i % 2 == 0 && a[i] % 2 == 1)
			E.push_back(i);
	}
	
	if((ll)O.size() >= 2 || (ll)E.size() >= 2)
	{
		cout << -1 sp << -1;
		return 0;
	}
	
	if(((ll)O.size() + (ll)E.size()) % 2 == 1)
	{
		cout << -1 sp << -1;
		return 0;
	}
	
	if(n == 2)
	{
		if((ll)O.size() == 0)
			cout << -1 sp << -1;
		else
			cout << 1 sp << 2;
		
		return 0;
	}
	
	if((ll)O.size() == 0)
	{
		cout << 1 sp << 3 en;
		return 0;
	}
	
	cout << O[0] sp << E[0] en;
	return 0;
}