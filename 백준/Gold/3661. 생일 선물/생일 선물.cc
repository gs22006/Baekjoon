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
ll P, n;
pll a[110];
ll cost[110];
ll ans[110];
ll nu[110];
ll sad[110];

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> P >> n;
		
		ll S = 0;
		
		for(ll i = 1 ; i <= n ; i++)
			cost[i] = ans[i] = nu[i] = 0;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			cin >> a[i].fi;
			
			sad[i] = a[i].fi;
			a[i].fi *= n;
			S += a[i].fi;
			a[i].se = i;
		}
		
		sort(a + 1, a + 1 + n);
		
		ll sum = P * n;
		
		if(S < sum)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(a[i].fi <= P)
			{
				cost[a[i].se] += a[i].fi;
				sum -= a[i].fi;
				a[i].fi = 0;
			}
			
			else
			{
				cost[a[i].se] += P / n * n;
				a[i].fi -= P / n * n;
				sum -= P / n * n;
			}
		}
		
		ll now = 0;
		vector<pll> nam;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if((a[i].fi - now) * (n - i + 1) >= sum)
			{
				for(ll j = i ; j <= n ; j++)
					nam.push_back({-sad[a[j].se], a[j].se});
				
				break;
			}
			
			sum -= (a[i].fi - now) * (n - i + 1);
			nu[i] += (a[i].fi - now);
			now = a[i].fi;
		}
		
		for(ll i = 1 ; i <= n ; i++)
			nu[i] += nu[i - 1];
		
		for(ll i = 1 ; i <= n ; i++)
			cost[a[i].se] += nu[i];
		
		sort(nam.begin(), nam.end());
		
		ll mok = sum / n / (ll)nam.size() * n;
		ll nm = sum / n % (ll)nam.size();
		
		for(auto &i : nam)
		{
			if(nm)
			{
				cost[i.se] += n;
				nm--;
			}
			
			cost[i.se] += mok;
		}
		
		for(ll i = 1 ; i <= n ; i++)
			cout << cost[i] / n sp;
		
		cout en;
	}
	
	return 0;
}