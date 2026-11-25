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

ll n, A, B;
ll a[1000010];
ll b[1000010];
ll w[1000010];

struct fenwicktree
{
	ll bit[1000010];
	
	void update(ll w, ll v)
	{
		for(ll i = w ; i <= n ; i += (i & (-i)))
			bit[i] += v;
	}
	
	ll query(ll X)
	{
		ll ret = 0;
		
		for(ll i = X ; i > 0 ; i -= (i & (-i)))
			ret += bit[i];
		
		return ret;
	}
}BIT;

void input(void)
{
	cin >> n >> A >> B;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> b[i];
}

void solve(void)
{
	for(ll i = 1 ; i <= n ; i++)
		w[a[i]] = i;
	
	for(ll i = 1 ; i <= n ; i++)
		b[i] = w[b[i]];
	
	ll cou = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cou += BIT.query(b[i]);
		BIT.update(b[i], 1);
	}
	
	cout << min(0LL, A + B) * cou + min(A, B) * (n * (n - 1) / 2 - cou);
}

int main(void)
{
	fastio
	
	input();
	solve();
	
	return 0;
}