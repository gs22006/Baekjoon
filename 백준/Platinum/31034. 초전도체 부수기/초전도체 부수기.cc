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
ll n, K;

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n >> K;
		
		if(K == 2)
		{
			cout << n en;
			continue;
		}
		
		map<ll, ll> mp;
		ll gaet = K;
		ll ans = 0;
		
		mp[1] += K - 1;
		mp[n - K + 1]++;
		ll fycj = 0;
		
		while(1)
		{
			if(K == 1)
				break;
			
			auto p = mp.begin();
			pll gap = (*p);
			
			if(gap.se % 2 == 0)
			{
				K -= gap.se;
				K += gap.se / 2;
				ans += gap.se * gap.fi;
				mp[gap.fi * 2] += gap.se / 2;
				mp.erase(gap.fi);
			}
			
			else
			{
				if(gap.se > 1)
				{
					K -= gap.se / 2;
					ans += gap.se / 2 * gap.fi * 2;
					mp[gap.fi] = 1;
					mp[gap.fi * 2] += gap.se / 2;
				}
				
				else
				{
					auto p2 = p;
					p2++;
					pll gap2 = (*p2);
					
					K--;
					ans += gap.fi + gap2.fi;
					mp[gap.fi + gap2.fi]++;
					mp.erase(gap.fi);
					
					if(gap2.se == 1)
						mp.erase(gap2.fi);
					else
						mp[gap2.fi]--;
				}
			}
		}
		
		cout << ans en;
	}
	
	return 0;
}