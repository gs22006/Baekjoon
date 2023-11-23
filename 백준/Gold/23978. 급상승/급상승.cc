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

ll n, K;
ll a[1000010];
ll l, r;

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	l = 0, r = 1000000000000000000;
	
	while(l <= r)
	{
		lll mid = (l + r) >> 1;
		lll sum = 0;
		
		a[n + 1] = INF;
		
		ll ff = 0;
		
		for(ll i = 2 ; i <= n + 1 ; i++)
		{
			lll cha = min((lll)a[i] - a[i - 1], mid);
			
			if(sum >= (lll)K - cha * (mid + mid - cha + 1) / 2)
			{
				ff = 1;
				break;
			}
			
			sum += cha * (mid + mid - cha + 1) / 2;
		}
		
		if(ff)
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	cout << l;
	return 0;
}