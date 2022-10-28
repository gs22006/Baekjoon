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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

ll n, m;
ll all, bll, cll, dll;
ll a[1030][1030];

struct FenwickTree2D
{
	ll seg[1030][1030];
	
	void update(ll x, ll y, ll v)
	{
		if(x > n)
			return;
		
		ll gap = y;
		
		while(gap <= n)
		{
			seg[x][gap] += v;
			gap += (gap & (-gap));
		}
		
		update(x + (x & (-x)), y, v);
	}
	
	ll query(ll x, ll y)
	{
		if(x <= 0)
			return 0;
		
		ll gap = y;
		ll sum = 0;
		
		while(gap)
		{
			sum += seg[x][gap];
			gap -= (gap & (-gap));
		}
		
		return query(x - (x & (-x)), y) + sum;
	}
}BIT;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			cin >> a[i][j];
			BIT.update(i, j, a[i][j]);
		}
	}
	
	while(m--)
	{
		cin >> all;
		
		if(!all)
		{
			cin >> all >> bll >> cll;
			
			BIT.update(all, bll, cll - a[all][bll]);
			a[all][bll] = cll;
		}
		
		else
		{
			cin >> all >> bll >> cll >> dll;
			
			ll gap = BIT.query(cll, dll);
			gap -= BIT.query(all - 1, dll);
			gap -= BIT.query(cll, bll - 1);
			gap += BIT.query(all - 1, bll - 1);
			
			cout << gap en;
		}
	}
	
	return 0;
}