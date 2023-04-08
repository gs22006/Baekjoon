#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
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

ll n, m, q;
vector<string> a, a2, X, Y;
string tmp;
ll all, bll, cll;
ll x, y;
ll cou, cou2;

int main(void)
{
	fastio
	
	cin >> n >> m >> q;
	
	for(ll i = 0 ; i < n ; i++)
	{
		cin >> tmp;
		a.push_back(tmp);
	}
	
	for(ll i = n - 1 ; i >= 0 ; i--)
	{
		tmp = a[i];
		
		reverse(tmp.begin(), tmp.end());
		a2.push_back(tmp);
	}
	
	for(ll oo = 0 ; oo < 2 ; oo++)
	{
		for(ll i = 0 ; i < n ; i++)
		{
			tmp.clear();
			
			for(ll j = 0 ; j < m ; j++)
				tmp.push_back(a[i][j]);
			
			for(ll j = 0 ; j < m ; j++)
				tmp.push_back(a[i][j]);
			
			Y.push_back(tmp);
		}
		
		for(ll i = 0 ; i < n ; i++)
		{
			tmp.clear();
			
			for(ll j = 0 ; j < m ; j++)
				tmp.push_back(a2[i][j]);
			
			for(ll j = 0 ; j < m ; j++)
				tmp.push_back(a2[i][j]);
			
			X.push_back(tmp);
		}
	}
	
	while(q--)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> bll >> cll;
			
			bll--;
			cll--;
			
			if(x <= bll && y <= cll)
			{
				x = bll - x;
				y = cll - y;
			}
			
			else if(bll < x && y <= cll)
			{
				x = n + bll - x;
				y = cll - y;
			}
			
			else if(x <= bll && cll < y)
			{
				x = bll - x;
				y = m + cll - y;
			}
			
			else
			{
				x = n + bll - x;
				y = m + cll - y;
			}
			
			cou++;
		}
		
		else
		{
		    cou2++;
		    
		    if(cou2 > 100)
		        assert(0);
		    
			if(cou & 1)
			{
				for(ll i = 0 ; i < n ; i++)
				{
					for(ll j = 0 ; j < m ; j++)
						cout << X[n - 1 + i - x][m - 1 + j - y];
					
					cout en;
				}
			}
			
			else
			{
				for(ll i = 0 ; i < n ; i++)
				{
					for(ll j = 0 ; j < m ; j++)
						cout << Y[n + i - x][m + j - y];
					
					cout en;
				}
			}
		}
	}
	
	return 0;
}