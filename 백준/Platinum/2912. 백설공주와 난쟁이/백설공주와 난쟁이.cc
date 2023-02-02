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

ll n, C;
ll a[300010];
ll m;
ll all, bll;
vector<ll> w[10010];

int main(void)
{
	fastio
	
	srand(time(NULL));
	
	cin >> n >> C;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		w[a[i]].push_back(i);
	}
	
	cin >> m;
	
	while(m--)
	{
		ll ans = -1;
		
		cin >> all >> bll;
		
		for(ll i = 1 ; i <= 50 ; i++)
		{
			ll W = rand() % (bll - all + 1) + all;
			ll l = 0, r = (ll)w[a[W]].size() - 1;
			ll gap = 0;
			
			while(l <= r)
			{
				ll mid = (l + r) / 2;
				
				if(w[a[W]][mid] <= bll)
					l = mid + 1;
				else
					r = mid - 1;
			}
			
			gap = r;
			
			l = 0, r = (ll)w[a[W]].size() - 1;
			
			while(l <= r)
			{
				ll mid = (l + r) / 2;
				
				if(w[a[W]][mid] < all)
					l = mid + 1;
				else
					r = mid - 1;
			}
			
			if((gap - r) * 2 > bll - all + 1)
				ans = a[W];
		}
		
		if(ans == -1)
			cout << "no\n";
		else
			cout << "yes " << ans en;
	}
	
	return 0;
}