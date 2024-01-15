#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 987654321
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n;
ll all, bll;

struct fenwicktree
{
	ll bit[100010];
	
	void update(ll w, ll v)
	{
		for(ll i = w ; i <= 100000 ; i += (i & (-i)))
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

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all >> bll;
		
		ll gap1 = BIT.query(all);
		ll gap2 = BIT.query(bll);
		
		cout << gap1 + gap2 en;
		
		BIT.update(all, -gap1);
		BIT.update(bll, -gap2);
		BIT.update(all + 1, gap1);
		BIT.update(bll + 1, gap2);
		
		if(all + 1 <= bll - 1)
		{
			BIT.update(all + 1, 1);
			BIT.update(bll, -1);
		}
	}
	
	return 0;
}