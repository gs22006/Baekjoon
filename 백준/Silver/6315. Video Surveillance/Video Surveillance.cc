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
pll a[2000010];
ll L, R, U, D;
ll CC;

int main(void)
{
	fastio
	
	while(1)
	{
		cin >> n;
		
		if(n == 0)
			break;
		
		for(ll i = 1 ; i <= n ; i++)
			cin >> a[i].fi >> a[i].se;
		
		L = -INF, R = INF, U = -INF, D = INF;
		
		a[n + 1] = a[1];
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(a[i].se == a[i + 1].se)
			{
				if(a[i].fi > a[i + 1].fi)
					U = max(U, a[i].se);
				else
					D = min(D, a[i].se);
			}
			
			else
			{
				if(a[i].se > a[i + 1].se)
					R = min(R, a[i].fi);
				else
					L = max(L, a[i].fi);
			}
		}
		
		if(D - U < 0 || R - L < 0)
		{
			cout << "Floor #" << ++CC en;
			cout << "Surveillance is impossible.\n\n";
		}
		
		else
		{
			cout << "Floor #" << ++CC en;
			cout << "Surveillance is possible.\n\n";
		}
	}
	
	/*cout << (D - U) * (R - L) en;
	cout << L sp << U;*/
	return 0;
}