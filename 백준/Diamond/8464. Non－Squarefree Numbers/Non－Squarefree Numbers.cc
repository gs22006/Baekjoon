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
ll era[1000010];
ll mo[1000010];

ll f(ll X)
{
	ll ret = 0;
	
	for(ll i = 1 ; i * i <= X ; i++)
		ret += mo[i] * (X / (i * i));
	
	return X - ret;
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= 1000000 ; i++)
		mo[i] = 1;
	
	for(ll i = 2 ; i <= 1000000 ; i++)
	{
		if(era[i])
			continue;
		
		for(ll j = i * i ; j <= 1000000 ; j += i)
			era[j] = 1;
		
		for(ll j = i ; j <= 1000000 ; j += i)
			mo[j] *= -1;
		
		for(ll j = i * i ; j <= 1000000 ; j += i * i)
			mo[j] = 0;
	}
	
	ll l = 1, r = 1000000000000;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		ll gap = f(mid);
		
		if(n <= gap)
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	cout << l;
	return 0;
}