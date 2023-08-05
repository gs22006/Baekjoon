#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second

ll n, k;
pll a[110];
ll b[110];
ll ans = (1LL << 62);

void f(ll here, ll gaet)
{
	if(here > n)
	{
		if(gaet != k)
			return;
		
		vector<pll> vec;

		for(ll i = 1 ; i <= n ; i++)
		{
			if(b[i])
				vec.push_back(a[i]);
		}

		ll maxx = 0;

		for(ll i = 1 ; i <= n ; i++)
		{
			ll minn = (1LL << 62);

			for(auto &j : vec)
				minn = min(minn, abs(a[i].fi - j.fi) + abs(a[i].se - j.se));
			
			maxx = max(maxx, minn);
		}

		ans = min(ans, maxx);
		return;
	}

	b[here] = 0;
	f(here + 1, gaet);

	if(gaet < k)
	{
		b[here] = 1;
		f(here + 1, gaet + 1);
		b[here] = 0;
	}
}

int main(void)
{
	scanf("%lld %lld", &n, &k);

	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld %lld", &a[i].fi, &a[i].se);
	
	f(1, 0);

	cout << ans;
	return 0;
}