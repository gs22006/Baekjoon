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

ll t;
ll n;
ll a[110];

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		for(ll i = 1 ; i <= n ; i++)
			cin >> a[i];
		
		ll cou = 0;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j < i ; j++)
			{
				if(a[j] > a[i])
					cou++;
			}
		}
		
		if(cou & 1)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	
	return 0;
}