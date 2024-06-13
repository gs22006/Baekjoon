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

ll n, S;
string s;
ll ans, now;

int main(void)
{
	fastio
	
	cin >> n >> S;
	
	now = S;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll gap = 0;
		
		cin >> s;
		
		if((ll)s.length() == 2)
			gap = s[0] - '0' + 1;
		else
			gap = s[0] - '0';
		
		if(now < gap)
		{
			ans++;
			now = S;
		}
		
		now -= gap;
	}
	
	cout << ans;
	return 0;
}