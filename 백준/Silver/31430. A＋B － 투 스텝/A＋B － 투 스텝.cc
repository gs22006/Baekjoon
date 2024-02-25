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

ll T;
ll a, b;
string s;

int main(void)
{
	fastio
	
	cin >> T;
	
	if(T == 1)
	{
		cin >> a >> b;
		
		a += b;
		
		string ret;
		
		ret.clear();
		
		while(a)
		{
			ret.push_back(a % 26 + 'a');
			a /= 26;
		}
		
		for(ll i = (ll)ret.size() + 1 ; i <= 13 ; i++)
			ret.push_back('a');
		
		cout << ret;
		return 0;
	}
	
	cin >> s;
	
	reverse(s.begin(), s.end());
	
	ll ans = 0;
	
	for(auto &i : s)
		ans = ans * 26 + i - 'a';
	
	cout << ans;
	return 0;
}