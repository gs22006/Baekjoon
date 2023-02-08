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

ll n, K;
ll a[100010];
char all;
ll bll, cll;

struct fenwicktree
{
	ll seg[100010];
	
	void init(void)
	{
		for(ll i = 0 ; i <= n ; i++)
			seg[i] = 0;
	}
	
	void update(ll X, ll V)
	{
		for(ll i = X ; i <= n ; i += (i & (-i)))
			seg[i] += V;
	}
	
	ll query(ll X)
	{
		ll ret = 0;
		
		for(ll i = X ; i > 0 ; i -= (i & (-i)))
			ret += seg[i];
		
		return ret;
	}
}BIT1, BIT2;

int main(void)
{
	fastio
	
	while(cin >> n >> K)
	{
		BIT1.init();
		BIT2.init();
		
		for(ll i = 1 ; i <= n ; i++)
			cin >> a[i];
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(a[i] == 0)
				BIT1.update(i, 1);
			else if(a[i] < 0)
				BIT2.update(i, 1);
		}
		
		while(K--)
		{
			cin >> all;
			
			if(all == 'C')
			{
				cin >> bll >> cll;
				
				if(a[bll] == 0)
					BIT1.update(bll, -1);
				else if(a[bll] < 0)
					BIT2.update(bll, -1);
				
				a[bll] = cll;
				
				if(a[bll] == 0)
					BIT1.update(bll, 1);
				else if(a[bll] < 0)
					BIT2.update(bll, 1);
			}
			
			else
			{
				cin >> bll >> cll;
				
				if(BIT1.query(cll) - BIT1.query(bll - 1) > 0)
					cout << 0;
				else if((BIT2.query(cll) - BIT2.query(bll - 1)) & 1)
					cout << "-";
				else
					cout << "+";
			}
		}
		
		cout en;
	}
	
	return 0;
}