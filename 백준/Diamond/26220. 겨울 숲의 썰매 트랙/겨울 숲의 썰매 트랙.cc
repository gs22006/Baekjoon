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
ll a[1010][1010];
ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, 1, 0, -1};
ll chk[1010][1010];
ll ans;
char dc[] = {'U', 'R', 'D', 'L'};
string ans2;

int main(void)
{
	fastio
	
	cin >> n;
	
	if(n == 3)
	{
		cout << 4 en << 1 sp << 1 en << "RDLU";
		return 0;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(i & 1)
			a[1][i] = 2;
		else
			a[1][i] = 1;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(i & 1)
			a[2][i] = 1;
		else
			a[2][i] = 0;
	}
	
	a[2][n - 1] = 2;
	
	for(ll i = n ; i >= 2 ; i--)
	{
		if((n - i) % 4 == 0)
		{
			for(ll j = 3 ; j <= n ; j++)
			{
				if(j & 1)
					a[j][i] = 2;
				else
					a[j][i] = 3;
			}
		}
		
		else if((n - i) % 4 == 1)
		{
			for(ll j = 3 ; j <= n ; j++)
			{
				if(j & 1)
					a[j][i] = 1;
				else
					a[j][i] = 2;
			}
			
			a[n][i] = 3;
		}
		
		else if((n - i) % 4 == 2)
		{
			for(ll j = 3 ; j <= n ; j++)
			{
				if(j & 1)
					a[j][i] = 0;
				else
					a[j][i] = 3;
			}
		}
		
		else
		{
			for(ll j = 3 ; j <= n ; j++)
			{
				if(j & 1)
					a[j][i] = 1;
				else
					a[j][i] = 0;
			}
			
			a[3][i] = 3;
		}
	}
	
	a[3][1] = 0;
	
	if(n % 4 == 3)
	{
		a[n][5] = 0;
		a[n - 1][4] = 0;
		a[n - 1][5] = 3;
		a[n - 2][4] = 1;
		a[n - 2][5] = 0;
		
		for(ll i = n - 3 ; i >= 3 ; i--)
		{
			if((n - 3 - i) % 4 == 0)
			{
				a[i][2] = a[i][4] = 0;
				a[i][3] = a[i][5] = 3;
			}
			
			else if((n - 3 - i) % 4 == 1)
			{
				a[i][1] = 0;
				a[i][2] = a[i][4] = 3;
				a[i][3] = 2;
			}
			
			else if((n - 3 - i) % 4 == 2)
			{
				a[i][1] = a[i][3] = 1;
				a[i][2] = a[i][4] = 0;
			}
			
			else
			{
				a[i][2] = a[i][4] = 1;
				a[i][3] = 2;
				a[i][5] = 0;
			}
		}
	}
	
	ll X = 1, Y = 2;
	
	while(!chk[X][Y])
	{
		chk[X][Y] = 1;
		ans++;
		
		ll d = a[X][Y];
		
		X += dx[d];
		Y += dy[d];
		ans2.push_back(dc[d]);
	}
	
	cout << ans en;
	cout << 1 sp << 2 en;
	cout << ans2;
	
	return 0;
}