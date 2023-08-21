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
ll a[200010];
ll ans;
ll fff, ff1, ff2;

struct fenwicktree
{
	ll BIT[200010];
	
	void init(void)
	{
		for(ll i = 0 ; i <= n ; i++)
			BIT[i] = 0;
	}
	
	void update(ll w, ll v)
	{
		for(ll i = w ; i <= n ; i += (i & (-i)))
			BIT[i] += v;
	}
	
	ll query(ll X)
	{
		ll ret = 0;
		
		for(ll i = X ; i > 0 ; i -= (i & (-i)))
			ret += BIT[i];
		
		return ret;
	}
}bit;

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	ll w = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i] == 1)
			w = i;
	}
	
	if(w != K)
	{
		fff = 1;
		swap(a[w], a[K]);
	}
	
	bit.init();
	
	for(ll i = K ; i >= 1 ; i--)
	{
		ans += bit.query(n) - bit.query(a[i]);
		bit.update(a[i], 1);
	}
	
	ff1 = ans % 2;
	
	bit.init();
	ans = 0;
	
	for(ll i = K + 1 ; i <= n ; i++)
	{
		ans += bit.query(n) - bit.query(a[i]);
		bit.update(a[i], 1);
	}
	
	ff2 = ans % 2;
	
	if(ff1 == ff2)
	{
		if(fff)
			cout << "Minchan\n";
		else
			cout << "Junee\n";
	}
	
	else
	{
		if(fff)
			cout << "Junee\n";
		else
			cout << "Minchan\n";
	}
	
	return 0;
}