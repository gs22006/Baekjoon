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
pll a[1000010];
vector<pll> ans;

ll ccw(pll X, pll Y, pll Z)
{
	return X.fi * Y.se + Y.fi * Z.se + Z.fi * X.se - X.se * Y.fi - Y.se * Z.fi - Z.se * X.fi;
}

void solve(void)
{
	vector<pll> h1, h2;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while((ll)h1.size() >= 2 && ccw(h1[(ll)h1.size() - 2], h1[(ll)h1.size() - 1], a[i]) > 0)
			h1.pop_back();
		
		h1.push_back(a[i]);
	}
	
	for(ll i = n - 1 ; i >= 1 ; i--)
	{
		while((ll)h1.size() >= 2 && ccw(h1[(ll)h1.size() - 2], h1[(ll)h1.size() - 1], a[i]) > 0)
			h1.pop_back();
		
		h1.push_back(a[i]);
	}
	
	compress(h1);
	
	for(auto &i : h1)
		ans.push_back(i);
	
	return;
}

ll f(pair<pll, pll> L1, pair<pll, pll> L2)
{
	if((L1.se.se - L1.fi.se) * (L2.se.fi - L2.fi.fi) == (L2.se.se - L2.fi.se) * (L1.se.fi - L1.fi.fi))
		return 1;
	
	return 0;
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	
	if(n == 1)
	{
		cout << 0;
		return 0;
	}
	
	sort(a + 1, a + 1 + n);
	solve();
	
	ll A = (ll)ans.size();
	ll B = n - A;
	
	ll ff = 0;
	
	for(ll i = 1 ; i < (ll)ans.size() ; i++)
	{
		if(!f({ans[0], ans[i]}, {ans[0], ans[1]}))
			ff = 1;
	}
	
	if(!ff)
	{
		cout << n - 1;
		return 0;
	}
	
	cout << 2 * A - 3 + 3 * B;
	return 0;
}