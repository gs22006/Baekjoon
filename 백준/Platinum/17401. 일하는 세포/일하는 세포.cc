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

ll T, n, D;
ll M;
ll a[110][30][30];
ll arr[30][30];
ll tmp[30][30];
ll ans[30][30];
ll all, bll, cll;
ll ss = 1000000007;

int main(void)
{
	fastio
	
	cin >> T >> n >> D;
	
	for(ll i = 1 ; i <= T ; i++)
	{
		cin >> M;
		
		for(ll j = 1 ; j <= M ; j++)
		{
			cin >> all >> bll >> cll;
			a[i][all][bll] += cll;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			arr[i][j] = a[1][i][j];
	}
	
	for(ll i = 2 ; i <= T ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			for(ll k = 1 ; k <= n ; k++)
				tmp[j][k] = 0;
		}
		
		for(ll j = 1 ; j <= n ; j++)
		{
			for(ll k = 1 ; k <= n ; k++)
			{
				for(ll l = 1 ; l <= n ; l++)
					tmp[j][k] = (tmp[j][k] + arr[j][l] * a[i][l][k] % ss) % ss;
			}
		}
		
		for(ll j = 1 ; j <= n ; j++)
		{
			for(ll k = 1 ; k <= n ; k++)
				arr[j][k] = tmp[j][k];
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
		ans[i][i] = 1;
	
	ll mk = D / T;
	ll nm = D % T;
	
	while(mk)
	{
		if(mk & 1)
		{
			for(ll i = 1 ; i <= n ; i++)
			{
				for(ll j = 1 ; j <= n ; j++)
					tmp[i][j] = 0;
			}
			
			for(ll i = 1 ; i <= n ; i++)
			{
				for(ll j = 1 ; j <= n ; j++)
				{
					for(ll k = 1 ; k <= n ; k++)
						tmp[i][j] = (tmp[i][j] + ans[i][k] * arr[k][j] % ss) % ss;
				}
			}
			
			for(ll i = 1 ; i <= n ; i++)
			{
				for(ll j = 1 ; j <= n ; j++)
					ans[i][j] = tmp[i][j];
			}
		}
		
		mk >>= 1;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
				tmp[i][j] = 0;
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
			{
				for(ll k = 1 ; k <= n ; k++)
					tmp[i][j] = (tmp[i][j] + arr[i][k] * arr[k][j] % ss) % ss;
			}
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
				arr[i][j] = tmp[i][j];
		}
	}
	
	for(ll o = 1 ; o <= nm ; o++)
	{
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
				tmp[i][j] = 0;
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
			{
				for(ll k = 1 ; k <= n ; k++)
					tmp[i][j] = (tmp[i][j] + ans[i][k] * a[o][k][j] % ss) % ss;
			}
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
				ans[i][j] = tmp[i][j];
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			cout << (ans[i][j] % ss < 0 ? ans[i][j] % ss + ss : ans[i][j] % ss) sp;
		
		cout en;
	}
	
	return 0;
}