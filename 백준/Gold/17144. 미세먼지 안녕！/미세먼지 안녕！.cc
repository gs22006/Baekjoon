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

ll n, m, T;
ll a[110][110];
ll tmp[110][110];
ll w;
ll dx[10] = {-1, 1, 0, 0}, dy[10] = {0, 0, -1, 1};
ll ans;

void spread(void)
{
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			tmp[i][j] = 0;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			if(a[i][j] == -1)
			{
				tmp[i][j] = -1;
				continue;
			}
			
			ll gap = a[i][j] / 5;
			ll cou = 0;
			
			for(ll d = 0 ; d < 4 ; d++)
			{
				ll nx = i + dx[d];
				ll ny = j + dy[d];
				
				if(nx <= 0 || ny <= 0 || nx > n || ny > m || a[nx][ny] == -1)
					continue;
				
				cou++;
				tmp[nx][ny] += gap;
			}
			
			tmp[i][j] += a[i][j] - gap * cou;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			a[i][j] = tmp[i][j];
	}
}

void air_cleaner(void)
{
	for(ll i = w - 1 ; i >= 1 ; i--)
		a[i + 1][1] = a[i][1];
	
	a[w][1] = -1;
	
	for(ll i = 2 ; i <= m ; i++)
		a[1][i - 1] = a[1][i];
	
	for(ll i = 2 ; i <= w ; i++)
		a[i - 1][m] = a[i][m];
	
	for(ll i = m ; i >= 3 ; i--)
		a[w][i] = a[w][i - 1];
	
	a[w][2] = 0;
	
	for(ll i = w + 1 ; i < n ; i++)
		a[i][1] = a[i + 1][1];
	
	a[w + 1][1] = -1;
	
	for(ll i = 1 ; i < m ; i++)
		a[n][i] = a[n][i + 1];
	
	for(ll i = n ; i >= w + 2 ; i--)
		a[i][m] = a[i - 1][m];
	
	for(ll i = m ; i >= 3 ; i--)
		a[w + 1][i] = a[w + 1][i - 1];
	
	a[w + 1][2] = 0;
}

int main(void)
{
	fastio
	
	cin >> n >> m >> T;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i][1] == -1)
		{
			w = i;
			break;
		}
	}
	
	while(T--)
	{
		spread();
		air_cleaner();
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			if(a[i][j] == -1)
				continue;
			
			ans += a[i][j];
		}
	}
	
	cout << ans;
	return 0;
}