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

string all;
map<string, ll> mp;
ll a[20][20];
ll cc;

int main(void)
{
	fastio
	
	for(ll i = 1 ; i <= 10 ; i++)
	{
		for(ll j = 1 ; j <= 10 ; j++)
		{
			cin >> all;
			
			if(!mp[all])
				mp[all] = ++cc;
			
			a[i][j] = mp[all];
		}
	}
	
	for(ll i = 1 ; i <= 10 ; i++)
	{
		for(ll j = 1 ; j <= 10 ; j++)
		{
			ll ff = 0;
			
			for(ll k = 1 ; k <= 10 ; k++)
			{
				if(a[i][j] != a[i][k])
					ff = 1;
			}
			
			if(!ff)
			{
				cout << 1;
				return 0;
			}
			
			ff = 0;
			
			for(ll k = 1 ; k <= 10 ; k++)
			{
				if(a[i][j] != a[k][j])
					ff = 1;
			}
			
			if(!ff)
			{
				cout << 1;
				return 0;
			}
		}
	}
	
	cout << 0;
	return 0;
}