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
ll a[200010];

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		for(ll i = 1 ; i <= n ; i++)
			cin >> a[i];
		
		sort(a + 1, a + 1 + n);
		
		ll l = 0, r = n;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(mid * (mid + 1) / 2 >= a[n])
			{
				r = mid - 1;
				continue;
			}
			
			vector<pll> vv;
			ll sum = 0;
			
			for(ll i = mid ; i >= 1 ; i--)
			{
				sum += i;
				vv.push_back({sum, -1});
			}
			
			for(ll i = 1 ; i <= n ; i++)
				vv.push_back({a[i], 1});
			
			sort(vv.begin(), vv.end());
			
			sum = 0;
			
			for(auto &i : vv)
			{
				if(i.se == -1)
				{
					sum = max(sum, 0LL);
					sum++;
				}
				
				else
					sum--;
			}
			
			if(sum >= 0)
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		cout << min(l * (l + 1) / 2, a[n]) en;
	}
	
	return 0;
}