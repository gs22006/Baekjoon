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
ll all, bll;
ll deg[100010];
ll cou[100010], now[100010];
ll sum, sum2;
ll ans;

ll nck(ll X, ll Y)
{
	if(X == Y)
		return 1;
	
	Y = min(Y, X - Y);
	
	ll ret = 1;
	
	for(ll i = 1 ; i <= Y ; i++)
	{
		ret = ret * (X - i + 1);
		ret = ret / i;
	}
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all;
		deg[i] = all;
		
		while(all--)
			cin >> bll;
	}
	
	sort(deg + 1, deg + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cou[deg[i]]++;
		sum += deg[i];
	}
	
	for(ll i = 1 ; i < n ; i++)
	{
		now[deg[i]]++;
		sum -= deg[i];
		sum2 += deg[i];
		
		if(sum - (n - i) * (n - i - 1) == sum2)
			ans += nck(cou[deg[i]], now[deg[i]]);
	}
	
	cout << ans;
	return 0;
}