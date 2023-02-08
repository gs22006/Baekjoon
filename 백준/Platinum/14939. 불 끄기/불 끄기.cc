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

char a[20][20];
ll b[20];
char all[20][20];
ll ans = INF;

void FLIP(ll X, ll Y)
{
	all[X - 1][Y] = 'O' + '#' - all[X - 1][Y];
	all[X + 1][Y] = 'O' + '#' - all[X + 1][Y];
	all[X][Y - 1] = 'O' + '#' - all[X][Y - 1];
	all[X][Y + 1] = 'O' + '#' - all[X][Y + 1];
	all[X][Y] = 'O' + '#' - all[X][Y];
}

void f(ll here)
{
	if(here > 10)
	{
		ll cou = 0;
		
		for(ll i = 1 ; i <= 10 ; i++)
		{
			for(ll j = 1 ; j <= 10 ; j++)
				all[i][j] = a[i][j];
		}
		
		for(ll i = 1 ; i <= 10 ; i++)
		{
			if(b[i])
			{
				FLIP(1, i);
				cou++;
			}
		}
		
		for(ll i = 2 ; i <= 10 ; i++)
		{
			for(ll j = 1 ; j <= 10 ; j++)
			{
				if(all[i - 1][j] == 'O')
				{
					FLIP(i, j);
					cou++;
				}
			}
		}
		
		ll ff = 0;
		
		for(ll i = 1 ; i <= 10 ; i++)
		{
			for(ll j = 1 ; j <= 10 ; j++)
			{
				if(all[i][j] == 'O')
					ff = 1;
			}
		}
		
		if(!ff)
			ans = min(ans, cou);
		
		return;
	}
	
	b[here] = 0;
	f(here + 1);
	b[here] = 1;
	f(here + 1);
}

int main(void)
{
	fastio
	
	for(ll i = 1 ; i <= 10 ; i++)
	{
		for(ll j = 1 ; j <= 10 ; j++)
			cin >> a[i][j];
	}
	
	f(1);
	
	if(ans == INF)
		cout << -1;
	else
		cout << ans;
	
	return 0;
}