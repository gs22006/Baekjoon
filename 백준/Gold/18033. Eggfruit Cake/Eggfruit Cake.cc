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

string s;
ll K;
ll n;
ll EE[300010];
ll w = INF;
ll ans;

int main(void)
{
	fastio
	
	cin >> s;
	cin >> K;
	
	n = (ll)s.length();
	s += s;
	
	for(ll i = n * 2 - 1 ; i >= 0 ; i--)
	{
		if(s[i] == 'E')
			w = i;
		
		EE[i] = w;
	}
	
	for(ll i = 0 ; i < n ; i++)
	{
		ll nam = K - (EE[i] - i + 1);
		ans += max(0LL, nam + 1);
	}
	
	cout << ans;
	return 0;
}