#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

ll n, m, k;
ll a[1000010];
ll all, bll;

struct fenwicktree
{
	ll seg[1000010];
	
	void update(ll w, ll v)
	{
		for(ll i = w ; i <= n ; i += (i & (-i)))
			seg[i] += v;
	}
	
	ll query(ll X)
	{
		ll ret = 0;
		
		for(ll i = X ; i > 0 ; i -= (i & (-i)))
			ret += seg[i];
		
		return ret;
	}
}BIT;

int main(void)
{
	fastio
	
	cin >> n >> m >> k;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		BIT.update(i, a[i]);
	}
	
	m += k;
	
	while(m--)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> all >> bll;
			
			BIT.update(all, bll - a[all]);
			a[all] = bll;
		}
		
		else
		{
			cin >> all >> bll;
			cout << BIT.query(bll) - BIT.query(all - 1) en;
		}
	}
	
	return 0;
}