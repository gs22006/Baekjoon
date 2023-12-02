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
pll a[300010];
ll sum;
ll hol, jjak;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].fi >> a[i].se;
		
		if((a[i].fi + a[i].se) & 1)
			hol = i;
		else
			jjak = i;
	}
	
	if(hol && jjak)
	{
		cout << "YES\n";
		cout << hol sp;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(i != hol && i != jjak)
				cout << i sp;
		}
		
		cout << jjak;
	}
	
	else
		cout << "NO";
	
	return 0;
}