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

ll n, K;
char a[200010];
ll l, r;
ll nu[200010][5];
ll idx[200010][5];

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		
		for(ll j = 0 ; j <= 2 ; j++)
			nu[i][j] = nu[i - 1][j];
		
		if(a[i] == 'J')
			nu[i][0]++;
		else if(a[i] == 'O')
			nu[i][1]++;
		else
			nu[i][2]++;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= 2 ; j++)
		{
			ll l = i, r = n;
			
			while(l <= r)
			{
				ll mid = (l + r) / 2;
				
				if(nu[mid][j] - nu[i - 1][j] >= K)
					r = mid - 1;
				else
					l = mid + 1;
			}
			
			idx[i][j] = l;
		}
	}
	
	l = 0, r = n - K * 3;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		ll ff = 0;
		
		for(ll i = 0 ; i <= mid ; i++)
		{
			ll L = 1 + i;
			ll R = n - (mid - i);
			ll now = L, gg = 0;
			
			for(ll j = 0 ; j <= 2 ; j++)
			{
				if(now > R)
					gg = 1;
				
				now = idx[now][j];
				
				if(now > R)
					gg = 1;
				
				now++;
			}
			
			if(!gg)
				ff = 1;
		}
		
		if(ff)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	if(r == -1)
		cout << -1;
	else
		cout << n - K * 3 - r;
	
	return 0;
}