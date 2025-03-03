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

ll n, m;
ll a[1010][1010];
ll minn = INF, X, Y;
ll R;
ll x, y;
string ans;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			cin >> a[i][j];
			
			if(((i + j) & 1) && minn > a[i][j])
			{
				minn = a[i][j];
				X = i, Y = j;
			}
		}
	}
	
	if(!(n & 1) && !(m & 1))
	{
		if(X == n)
			R = X - 1;
		else
			R = X;
	}
	
	else
	{
		if(n & 1)
		{
			for(ll i = 1 ; i <= n ; i++)
			{
				if(i & 1)
				{
					for(ll j = 1 ; j < m ; j++)
						cout << "R";
				}
				
				else
				{
					for(ll j = 1 ; j < m ; j++)
						cout << "L";
				}
				
				if(i != n)
					cout << "D";
			}
		}
		
		else
		{
			for(ll i = 1 ; i <= m ; i++)
			{
				if(i & 1)
				{
					for(ll j = 1 ; j < n ; j++)
						cout << "D";
				}
				
				else
				{
					for(ll j = 1 ; j < n ; j++)
						cout << "U";
				}
				
				if(i != m)
					cout << "R";
			}
		}
		
		return 0;
	}
	
	for(ll i = 1 ; i < R ; i++)
	{
		if(i & 1)
		{
			for(ll j = 2 ; j <= m ; j++)
				ans += 'R';
		}
		
		else
		{
			for(ll j = m - 1 ; j >= 1 ; j--)
				ans += 'L';
		}
		
		ans += 'D';
	}
	
	if(R & 1)
	{
		x = R;
		
		for(ll i = 1 ; i < Y ; i++)
		{
			if(x == R)
				ans += "DR", x++;
			else
				ans += "UR", x--;
		}
		
		for(ll i = Y ; i < m ; i++)
		{
			if(x == R)
				ans += "RD", x++;
			else
				ans += "RU", x--;
		}
	}
	
	else
	{
		x = R;
		
		for(ll i = m ; i > Y ; i--)
		{
			if(x == R)
				ans += "DL", x++;
			else
				ans += "UL", x--;
		}
		
		for(ll i = Y ; i >= 2 ; i--)
		{
			if(x == R)
				ans += "LD", x++;
			else
				ans += "LU", x--;
		}
	}
	
	for(ll i = R + 1 ; i < n ; i++)
	{
		if((n - i) & 1)
		{
			ans += 'D';
			
			for(ll j = 1 ; j < m ; j++)
				ans += 'R';
		}
		
		else
		{
			ans += 'D';
			
			for(ll j = m ; j >= 2 ; j--)
				ans += 'L';
		}
	}
	
	cout << ans;
	return 0;
}