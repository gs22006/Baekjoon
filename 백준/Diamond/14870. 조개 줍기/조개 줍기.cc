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
ll a[1510][1510];
char all;
ll bll, cll;
ll sum;

struct fenwicktree
{
	ll bit[1510];
	
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
}dp[1510];

ll Qf(ll X, ll Y)
{
	return dp[X].query(Y);
}

void Uf(ll X, ll L, ll R, ll v)
{
	dp[X].update(L, v);
	dp[X].update(R + 1, -v);
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			cin >> a[i][j];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			Uf(i, j, j, max(Qf(i, j - 1), Qf(i - 1, j)) + a[i][j]);
			sum += Qf(i, j);
		}
	}
	
	cout << sum en;
	
	for(ll oo = 0 ; oo < n ; oo++)
	{
		ll l, r;
		
		cin >> all >> bll >> cll;
		
		if(all == 'U')
		{
			l = r = cll;
			
			Uf(bll, cll, cll, 1);
			sum++;
			
			for(ll i = cll + 1 ; i <= n ; i++)
			{
				if(Qf(bll, i - 1) > Qf(bll - 1, i))
				{
					r = i;
					sum++;
					Uf(bll, i, i, 1);
				}
				
				else
					break;
			}
			
			for(ll i = bll + 1 ; i <= n ; i++)
			{
				for(ll j = l ; j <= r ; j++)
				{
					if(Qf(i - 1, j) <= Qf(i, j - 1))
						l = j + 1;
					else
						break;
				}
				
				if(l > r)
					break;
				
				sum += r - l + 1;
				Uf(i, l, r, 1);
				
				for(ll j = r + 1 ; j <= n ; j++)
				{
					if(Qf(i, j - 1) > Qf(i - 1, j))
					{
						r = j;
						sum++;
						Uf(i, j, j, 1);
					}
					
					else
						break;
				}
			}
		}
		
		else
		{
			l = r = cll;
			
			sum--;
			Uf(bll, cll, cll, -1);
			
			for(ll i = cll + 1 ; i <= n ; i++)
			{
				if(Qf(bll, i - 1) >= Qf(bll - 1, i))
				{
					r = i;
					sum--;
					Uf(bll, i, i, -1);
				}
				
				else
					break;
			}
			
			for(ll i = bll + 1 ; i <= n ; i++)
			{
				for(ll j = l ; j <= r ; j++)
				{
					if(Qf(i - 1, j) < Qf(i, j - 1))
						l = j + 1;
					else
						break;
				}
				
				if(l > r)
					break;
				
				sum -= r - l + 1;
				Uf(i, l, r, -1);
				
				for(ll j = r + 1 ; j <= n ; j++)
				{
					if(Qf(i, j - 1) >= Qf(i - 1, j))
					{
						r = j;
						sum--;
						Uf(i, j, j, -1);
					}
					
					else
						break;
				}
			}
		}
		
		cout << sum en;
	}
	
	return 0;
}