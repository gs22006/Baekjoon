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

ll n;
ll S, E, T;
char all[20][20];
ll a[20][20];
ll num[20][20];
ll arr[1010][1010];
ll ans[1010][1010];
ll cc;
ll tmp[1010][1010];
ll ss = 1000003;

int main(void)
{
	fastio
	
	cin >> n >> S >> E >> T;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			cin >> all[i][j];
			a[i][j] = all[i][j] - '0';
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= 5 ; j++)
			num[i][j] = ++cc;
		
		for(ll j = 1 ; j <= 5 ; j++)
			arr[num[i][j]][num[i][j - 1]] = 1;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			if(!a[i][j])
				continue;
			
			arr[num[i][0]][num[j][a[i][j] - 1]] = 1;
		}
	}
	
	S = num[S][0];
	E = num[E][0];
	ans[S][S] = 1;
	
	while(T)
	{
		if(T & 1)
		{
			for(ll i = 1 ; i <= cc ; i++)
			{
				for(ll j = 1 ; j <= cc ; j++)
					tmp[i][j] = 0;
			}
			
			for(ll i = 1 ; i <= cc ; i++)
			{
				for(ll j = 1 ; j <= cc ; j++)
				{
					for(ll k = 1 ; k <= cc ; k++)
						tmp[i][j] = (tmp[i][j] + ans[i][k] * arr[k][j] % ss) % ss;
				}
			}
			
			for(ll i = 1 ; i <= cc ; i++)
			{
				for(ll j = 1 ; j <= cc ; j++)
					ans[i][j] = tmp[i][j];
			}
		}
		
		T >>= 1;
		
		for(ll i = 1 ; i <= cc ; i++)
		{
			for(ll j = 1 ; j <= cc ; j++)
				tmp[i][j] = 0;
		}
		
		for(ll i = 1 ; i <= cc ; i++)
		{
			for(ll j = 1 ; j <= cc ; j++)
			{
				for(ll k = 1 ; k <= cc ; k++)
					tmp[i][j] = (tmp[i][j] + arr[i][k] * arr[k][j] % ss) % ss;
			}
		}
		
		for(ll i = 1 ; i <= cc ; i++)
		{
			for(ll j = 1 ; j <= cc ; j++)
				arr[i][j] = tmp[i][j];
		}
	}
	
	cout << (ans[S][E] % ss < 0 ? ans[S][E] % ss + ss : ans[S][E] % ss);
	return 0;
}