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
ll a[1000010];
ll fail[1000010];
ll p;
ll minn = INF;
ll ans1, ans2;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 0 ; i < n ; i++)
		cin >> a[n - 1 - i];
	
	for(ll i = 1 ; i < n ; i++)
	{
		while(p && a[i] != a[p])
			p = fail[p - 1];
		
		if(a[p] == a[i])
			fail[i] = ++p;
	}
	
	for(ll i = 0 ; i < n ; i++)
	{
		ll K = n - 1 - i;
		ll P = i + 1 - fail[i];
		
		if(K + P < minn)
		{
			minn = K + P;
			ans1 = K;
			ans2 = P;
		}
		
		else if(K + P == minn && ans2 > P)
		{
			ans1 = K;
			ans2 = P;
		}
	}
	
	cout << ans1 sp << ans2;
	return 0;
}