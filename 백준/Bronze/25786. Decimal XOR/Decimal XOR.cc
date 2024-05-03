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

string a, b;
string ans;

int main(void)
{
	fastio
	
	cin >> a >> b;
	
	ll len1 = (ll)a.length();
	ll len2 = (ll)b.length();
	ll len = max(len1, len2);
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	for(ll i = len1 ; i < len ; i++)
		a.push_back('0');
	
	for(ll i = len2 ; i < len ; i++)
		b.push_back('0');
	
	for(ll i = 0 ; i < len ; i++)
	{
		if(a[i] <= '2' && b[i] <= '2')
			ans.push_back('0');
		else if(a[i] >= '7' && b[i] >= '7')
			ans.push_back('0');
		else
			ans.push_back('9');
	}
	
	reverse(ans.begin(), ans.end());
	
	cout << ans;
	return 0;
}