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

ll n, m;
ll a[110][10];
ll l, r;
ll b[110];

ll solve(ll X)
{
	for(ll i = 1 ; i <= n ; i++)
		b[i] = max(0LL, a[i][1] * X - a[i][2]);
	
	ll cou = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll minn = INF;
		
		for(ll j = 0 ; j <= 200 ; j++)
		{
			minn = min(minn, a[i][4] * j + (max(0LL, b[i] - a[i][3] * j) + a[i][5] - 1) / a[i][5] * a[i][6]);
			
			if(a[i][3] * j > b[i])
				break;
		}
		
		for(ll j = 0 ; j <= 200 ; j++)
		{
			minn = min(minn, a[i][6] * j + (max(0LL, b[i] - a[i][5] * j) + a[i][3] - 1) / a[i][3] * a[i][4]);
			
			if(a[i][5] * j > b[i])
				break;
		}
		
		cou += minn;
	}
	
	return cou <= m;
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= 6 ; j++)
			cin >> a[i][j];
	}
	
	l = 0;
	r = 1000000LL;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		ll gap = solve(mid);
		
		if(gap)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	cout << r;
	return 0;
}