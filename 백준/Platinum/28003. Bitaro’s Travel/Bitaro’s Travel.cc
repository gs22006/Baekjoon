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
ll a[200010];
ll q;
ll X;
ll gap1[200010], gap2[200010];
ll minn[2500010][21], maxx[2500010][21];

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 2 ; i <= n ; i++)
		gap1[i] = 2 * a[i] - a[i - 1];
	
	gap1[1] = INF / n;
	
	for(ll i = 1 ; i < n ; i++)
		gap2[i] = 2 * a[i] - a[i + 1];
	
	gap2[n] = -INF / n;
	
	for(ll i = 1 ; i <= n ; i++)
		minn[i][0] = gap2[i], maxx[i][0] = gap1[i];
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			ll L = max(2LL, j - (1LL << (i - 1)));
			ll R = min(n - 1, j + (1LL << (i - 1)));
			
			minn[j][i] = min(minn[j][i - 1], minn[R][i - 1]);
			maxx[j][i] = max(maxx[j][i - 1], maxx[L][i - 1]);
		}
	}
	
	cin >> q;
	
	while(q--)
	{
		cin >> X;
		
		if(n == 1)
		{
			cout << abs(X - a[1]) en;
			continue;
		}
		
		ll st = 0;
		ll ans = 0;
		
		if(X <= a[1])
			st = 1, ans += a[1] - X;
		else if(X >= a[n])
			st = n, ans += X - a[n];
		
		else
		{
			ll idx = lower_bound(a + 1, a + 1 + n, X) - a;
			ll idx2 = idx - 1;
			
			if(X - a[idx2] <= a[idx] - X)
				st = idx2, ans += X - a[idx2];
			else
				st = idx, ans += a[idx] - X;
		}
		
		ll L = st, R = st;
		ll D;
		
		if(st == 1)
			D = 1;
		else if(st == n)
			D = -1;
		
		else
		{
			if(a[st] - a[st - 1] <= a[st + 1] - a[st])
				D = -1;
			else
				D = 1;
		}
		
		while(1)
		{
			if(L <= 1)
			{
				if(D == 1)
					ans += a[n] - a[R];
				else
					ans += a[n] - a[1];
				
				break;
			}
			
			if(R >= n)
			{
				if(D == -1)
					ans += a[L] - a[1];
				else
					ans += a[n] - a[1];
				
				break;
			}
			
			if(D == -1)
			{
				ll XX = a[R + 1];
				ll now = L;
				
				for(ll i = 20 ; i >= 0 ; i--)
				{
					if(now <= 1)
						break;
					
					if(maxx[now][i] <= XX)
						now -= (1LL << i);
				}
				
				if(now <= 1)
				{
					ans += a[L] - a[1];
					ans += a[n] - a[1];
					break;
				}
				
				ans += a[L] - a[now];
				ans += a[R + 1] - a[now];
				
				L = now, R = R + 1, D = 1;
			}
			
			else
			{
				ll XX = a[L - 1];
				ll now = R;
				
				for(ll i = 20 ; i >= 0 ; i--)
				{
					if(now >= n)
						break;
					
					if(minn[now][i] > XX)
						now += (1LL << i);
				}
				
				if(now >= n)
				{
					ans += a[n] - a[R];
					ans += a[n] - a[1];
					break;
				}
				
				ans += a[now] - a[R];
				ans += a[now] - a[L - 1];
				
				L = L - 1, R = now, D = -1;
			}
		}
		
		cout << ans en;
	}
	
	return 0;
}