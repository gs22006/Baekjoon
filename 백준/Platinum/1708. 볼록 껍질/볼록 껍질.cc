#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

ll n;
pair<ll, ll> a[100010];
vector< pair<ll, ll> > ans;

ll ccw(pair<ll, ll> X, pair<ll, ll> Y, pair<ll, ll> Z)
{
	return X.fi * Y.se + Y.fi * Z.se + Z.fi * X.se - X.se * Y.fi - Y.se * Z.fi - Z.se * X.fi;
}

void solve(void)
{
	vector< pair<ll, ll> > h1, h2;
	
	h1.push_back(a[1]);
	h1.push_back(a[2]);
	
	for(ll i = 3 ; i <= n ; i++)
	{
		while((ll)h1.size() >= 2 && ccw(h1[(ll)h1.size() - 2], h1[(ll)h1.size() - 1], a[i]) >= 0)
			h1.pop_back();
		
		h1.push_back(a[i]);
	}
	
	h2.push_back(a[n]);
	h2.push_back(a[n - 1]);
	
	for(ll i = n - 2 ; i >= 1 ; i--)
	{
		while((ll)h2.size() >= 2 && ccw(h2[(ll)h2.size() - 2], h2[(ll)h2.size() - 1], a[i]) >= 0)
			h2.pop_back();
		
		h2.push_back(a[i]);
	}
	
	for(auto &i : h1)
		ans.push_back(i);
	
	for(auto &i : h2)
	{
		if(i == ans.back())
			continue;
		
		ans.push_back(i);
	}
	
	ans.pop_back();
	return;
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	
	sort(a + 1, a + 1 + n);
	
	solve();
	
	cout << (ll)ans.size();
	return 0;
}