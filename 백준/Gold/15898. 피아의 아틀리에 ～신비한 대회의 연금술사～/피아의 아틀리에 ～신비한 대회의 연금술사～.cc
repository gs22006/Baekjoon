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

struct gujo
{
	ll hyo[10][10];
	char col[10][10];
};

ll n;
gujo a[20], pan, tmp, tmp2;
ll b[20];
ll X[10];
ll ans;

void rot(void)
{
	for(ll i = 1 ; i <= 4 ; i++)
	{
		for(ll j = 1 ; j <= 4 ; j++)
		{
			tmp2.hyo[i][j] = tmp.hyo[5 - j][i];
			tmp2.col[i][j] = tmp.col[5 - j][i];
		}
	}
	
	for(ll i = 1 ; i <= 4 ; i++)
	{
		for(ll j = 1 ; j <= 4 ; j++)
		{
			tmp.hyo[i][j] = tmp2.hyo[i][j];
			tmp.col[i][j] = tmp2.col[i][j];
		}
	}
}

void add(ll X, ll Y)
{
	for(ll i = 1 ; i <= 4 ; i++)
	{
		for(ll j = 1 ; j <= 4 ; j++)
		{
			pan.hyo[X + i][Y + j] += tmp.hyo[i][j];
			
			if(pan.hyo[X + i][Y + j] < 0)
				pan.hyo[X + i][Y + j] = 0;
			else if(pan.hyo[X + i][Y + j] > 9)
				pan.hyo[X + i][Y + j] = 9;
			
			if(tmp.col[i][j] != 'W')
				pan.col[X + i][Y + j] = tmp.col[i][j];
		}
	}
}

void f(ll here)
{
	if(here >= 6)
	{
		for(ll i = 1 ; i <= 5 ; i++)
		{
			for(ll j = 1 ; j <= 5 ; j++)
			{
				pan.hyo[i][j] = 0;
				pan.col[i][j] = 'W';
			}
		}
		
		for(ll o = 0 ; o < 3 ; o++)
		{
			for(ll i = 1 ; i <= 4 ; i++)
			{
				for(ll j = 1 ; j <= 4 ; j++)
				{
					tmp.hyo[i][j] = a[X[o]].hyo[i][j];
					tmp.col[i][j] = a[X[o]].col[i][j];
				}
			}
			
			for(ll i = 0 ; i < b[o * 2] ; i++)
				rot();
			
			if(b[o * 2 + 1] == 0)
				add(0, 0);
			else if(b[o * 2 + 1] == 1)
				add(1, 0);
			else if(b[o * 2 + 1] == 2)
				add(0, 1);
			else
				add(1, 1);
		}
		
		ll R = 0, B = 0, G = 0, Y = 0;
		
		for(ll i = 1 ; i <= 5 ; i++)
		{
			for(ll j = 1 ; j <= 5 ; j++)
			{
				if(pan.col[i][j] == 'R')
					R += pan.hyo[i][j];
				else if(pan.col[i][j] == 'B')
					B += pan.hyo[i][j];
				else if(pan.col[i][j] == 'G')
					G += pan.hyo[i][j];
				else if(pan.col[i][j] == 'Y')
					Y += pan.hyo[i][j];
			}
		}
		
		ans = max(ans, R * 7 + B * 5 + G * 3 + Y * 2);
		return;
	}
	
	for(ll i = 0 ; i < 4 ; i++)
	{
		b[here] = i;
		f(here + 1);
	}
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= 4 ; j++)
		{
			for(ll k = 1 ; k <= 4 ; k++)
				cin >> a[i].hyo[j][k];
		}
		
		for(ll j = 1 ; j <= 4 ; j++)
		{
			for(ll k = 1 ; k <= 4 ; k++)
				cin >> a[i].col[j][k];
		}
	}
	
	for(ll o = 1 ; o <= n ; o++)
	{
		for(ll oo = 1 ; oo <= n ; oo++)
		{
			for(ll ooo = 1 ; ooo <= n ; ooo++)
			{
				if(o == oo || o == ooo || oo == ooo)
					continue;
				
				X[0] = o;
				X[1] = oo;
				X[2] = ooo;
				
				f(0);
			}
		}
	}
	
	cout << ans;
	return 0;
}