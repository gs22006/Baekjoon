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

int main(void)
{
	fastio
	
	cin >> n;
	cin >> s;
	
	ll ff = 0;
	
	for(ll i = 0 ; i < n ; i++)
	{
		if(s[i] == 'P')
			ff = 1;
		
		else if(ff == 1)
		{
			if(s[i] == 'S')
				ff = 2;
			else
				ff = 0;
		}
		
		else if(ff == 2)
		{
			if(s[i] == '4' || s[i] == '5')
				continue;
			
			ff = 0;
		}
		
		cout << s[i];
	}
	
	return 0;
}