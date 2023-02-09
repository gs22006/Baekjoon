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
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n;
ll a[200010];
pll b[200010];
ll ans = INF;

ll solve(ll X, ll Y)
{
	ll gap1 = a[X], gap2 = a[Y];
	ll gaet1 = abs(Y - X) - 1;
	ll gaet2 = n - 2 - gaet1;
	
	if(gaet1)
	{
		gap1--;
		gap2--;
		
		for(ll i = 1 ; i < gaet1 ; i++)
		{
			if(gap1 > gap2)
				gap1--;
			else
				gap2--;
		}
	}
	
	if(gaet2)
	{
		gap1--;
		gap2--;
		
		for(ll i = 1 ; i < gaet2 ; i++)
		{
			if(gap1 > gap2)
				gap1--;
			else
				gap2--;
		}
	}
	
	return max(gap1, gap2);
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		b[i] = {a[i], i};
	}
	
	sort(b + 1, b + 1 + n);
	
	ll siz = min(5LL, n);
	
	for(ll i = 1 ; i <= siz ; i++)
	{
		for(ll j = i + 1 ; j <= siz ; j++)
			ans = min(ans, solve(b[i].se, b[j].se));
	}
	
	cout << ans;
	return 0;
}