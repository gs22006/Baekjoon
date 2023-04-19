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
ll a[100010], b[100010];
ll w[100010];

void f(ll s1, ll e1, ll s2, ll e2)
{
	if(s2 > e2)
		return;
	
	cout << b[e2] sp;
	
	ll p = w[b[e2]];
	ll L = p - s1;
	
	f(s1, p - 1, s2, s2 + L - 1);
	f(p + 1, e1, s2 + L, e2 - 1);
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		w[a[i]] = i;
	}
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> b[i];
	
	f(1, n, 1, n);
	return 0;
}