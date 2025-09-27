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
string s;
vector<lll> gn;
vector<lll> poly;

int main(void)
{
	fastio
	
	cin >> s;
	
	n = (ll)s.length();
	
	for(ll i = 1 ; i < n ; i++)
	{
		if(s[i] != s[i - 1])
			gn.push_back(i * 2 + 1);
	}
	
	poly.push_back(1);
	
	for(auto &i : gn)
	{
		vector<lll> tmp;
		
		for(auto &j : poly)
			tmp.push_back(0);
		
		tmp.push_back(0);
		
		for(ll j = 0 ; j < (ll)poly.size() ; j++)
		{
			tmp[j + 1] += poly[j];
			tmp[j] += poly[j] * (-i);
		}
		
		poly = tmp;
	}
	
	cout << (ll)poly.size() - 1 en;
	
	if((ll)gn.size() % 2 == 0 && s[0] == 'A')
	{
		for(auto &i : poly)
			i *= -1;
	}
	
	else if((ll)gn.size() % 2 == 1 && s[0] == 'H')
	{
		for(auto &i : poly)
			i *= -1;
	}
	
	reverse(poly.begin(), poly.end());
	
	for(auto &i : poly)
		cout << (ll)i sp;
	
	return 0;
}