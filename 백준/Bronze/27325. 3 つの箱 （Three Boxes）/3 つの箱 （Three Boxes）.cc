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
string a;
ll ans;
ll now = 1;

int main(void)
{
	fastio
	
	cin >> n;
	cin >> a;
	
	for(auto &i : a)
	{
		if(i == 'L')
			now = max(1LL, now - 1);
		else
			now = min(3LL, now + 1);
		
		if(now == 3)
			ans++;
	}
	
	cout << ans;
	return 0;
}