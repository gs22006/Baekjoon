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

ll n, B, C;
ll a[1000010];
ll ans;

int main(void)
{
	fastio
	
	cin >> n >> B >> C;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	if(B <= C)
	{
		for(ll i = 1 ; i <= n ; i++)
			ans += a[i] * B;
		
		cout << ans;
		return 0;
	}
	
	for(ll i = 1 ; i <= n - 2 ; i++)
	{
		if(a[i] <= a[i + 1] && a[i + 1] <= a[i + 2])
		{
			ans += (B + C * 2) * a[i];
			a[i + 1] -= a[i];
			a[i + 2] -= a[i];
			a[i] = 0;
		}
		
		else if(a[i] <= a[i + 1] && a[i + 1] > a[i + 2])
		{
			ll cha = a[i + 1] - a[i + 2];
			
			if(cha < a[i])
			{
				ans += (B + C) * cha;
				a[i] -= cha;
				a[i + 1] -= cha;
				i--;
				continue;
			}
			
			ans += (B + C) * a[i];
			a[i + 1] -= a[i];
			a[i] = 0;
		}
		
		else
		{
			ll cha = a[i] - a[i + 1];
			
			ans += B * cha;
			a[i] -= cha;
			i--;
		}
	}
	
	if(a[n - 1] <= a[n])
	{
		ans += (B + C) * a[n - 1];
		ans += B * (a[n] - a[n - 1]);
	}
	
	else
	{
		ans += (B + C) * a[n];
		ans += B * (a[n - 1] - a[n]);
	}
	
	cout << ans;
	return 0;
}