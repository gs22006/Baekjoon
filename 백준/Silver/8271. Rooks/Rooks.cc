#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
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
char a[1010][1010];
ll chk[1010];

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 0 ; i < n ; i++)
		cin >> a[i];
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < n ; j++)
		{
			if(a[i][j] == 'W')
				chk[j] = 1;
		}
	}
	
	for(ll i = 0 ; i < n ; i++)
	{
		ll ff = 0;
		
		for(ll j = 0 ; j < n ; j++)
		{
			if(a[i][j] == 'W')
				ff = 1;
		}
		
		if(!ff)
		{
			for(ll j = 0 ; j < n ; j++)
			{
				if(!chk[j])
				{
					a[i][j] = 'W';
					chk[j] = 1;
					
					break;
				}
			}
		}
		
		cout << a[i] en;
	}
	
	return 0;
}