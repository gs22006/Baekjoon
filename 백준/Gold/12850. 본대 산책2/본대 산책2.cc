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

ll D;
ll ans[10][10];
ll arr[10][10];
ll tmp[10][10];
ll ans2;
ll ss = 1000000007;

int main(void)
{
	fastio
	
	cin >> D;
	
	arr[1][2] = 1;
	arr[1][3] = 1;
	arr[2][1] = 1;
	arr[2][3] = 1;
	arr[2][4] = 1;
	arr[3][1] = 1;
	arr[3][2] = 1;
	arr[3][4] = 1;
	arr[3][5] = 1;
	arr[4][2] = 1;
	arr[4][3] = 1;
	arr[4][5] = 1;
	arr[4][6] = 1;
	arr[5][3] = 1;
	arr[5][4] = 1;
	arr[5][6] = 1;
	arr[5][8] = 1;
	arr[6][4] = 1;
	arr[6][5] = 1;
	arr[6][7] = 1;
	arr[7][6] = 1;
	arr[7][8] = 1;
	arr[8][5] = 1;
	arr[8][7] = 1;
	ans[1][1] = 1;
	
	while(D)
	{
		if(D & 1)
		{
			for(ll i = 1 ; i <= 8 ; i++)
			{
				for(ll j = 1 ; j <= 8 ; j++)
					tmp[i][j] = 0;
			}
			
			for(ll i = 1 ; i <= 8 ; i++)
			{
				for(ll j = 1 ; j <= 8 ; j++)
				{
					for(ll k = 1 ; k <= 8 ; k++)
						tmp[i][j] = (ans[i][k] * arr[k][j] % ss + tmp[i][j]) % ss;
				}
			}
			
			for(ll i = 1 ; i <= 8 ; i++)
			{
				for(ll j = 1 ; j <= 8 ; j++)
					ans[i][j] = tmp[i][j];
			}
		}
		
		D >>= 1;
		
		for(ll i = 1 ; i <= 8 ; i++)
		{
			for(ll j = 1 ; j <= 8 ; j++)
				tmp[i][j] = 0;
		}
		
		for(ll i = 1 ; i <= 8 ; i++)
		{
			for(ll j = 1 ; j <= 8 ; j++)
			{
				for(ll k = 1 ; k <= 8 ; k++)
					tmp[i][j] = (arr[i][k] * arr[k][j] % ss + tmp[i][j]) % ss;
			}
		}
		
		for(ll i = 1 ; i <= 8 ; i++)
		{
			for(ll j = 1 ; j <= 8 ; j++)
				arr[i][j] = tmp[i][j];
		}
	}
	
	cout << (ans[1][1] % ss < 0 ? ans[1][1] % ss + ss : ans[1][1]);
	return 0;
}