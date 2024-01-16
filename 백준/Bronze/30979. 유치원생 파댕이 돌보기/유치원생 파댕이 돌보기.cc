#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 987654321
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll T;
ll n;
ll all;
ll sum;

int main(void)
{
	fastio
	
	cin >> T;
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all;
		sum += all;
	}
	
	if(sum >= T)
		cout << "Padaeng_i Happy";
	else
		cout << "Padaeng_i Cry";
	
	return 0;
}