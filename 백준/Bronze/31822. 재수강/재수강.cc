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
ll n;
string all;
ll ans;

int main(void)
{
	fastio
	
	cin >> s;
	cin >> n;
	
	while(n--)
	{
		cin >> all;
		
		if(s[0] == all[0] && s[1] == all[1] && s[2] == all[2] && s[3] == all[3] && s[4] == all[4])
			ans++;
	}
	
	cout << ans;
	return 0;
}