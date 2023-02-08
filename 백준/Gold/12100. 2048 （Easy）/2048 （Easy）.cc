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
ll a[30][30];
ll arr[30][30];
ll tmp[30][30];
ll b[10];
ll ans;

void U(void)
{
	vector<ll> vec[30];
	vector<ll> vec2[30];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			if(arr[j][i])
				vec[i].push_back(arr[j][i]);
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 0 ; j < (ll)vec[i].size() ; j++)
		{
			if(j < (ll)vec[i].size() - 1 && vec[i][j] == vec[i][j + 1])
			{
				vec2[i].push_back(vec[i][j] << 1);
				j++;
			}
			
			else
				vec2[i].push_back(vec[i][j]);
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			if(j - 1 >= (ll)vec2[i].size())
				arr[j][i] = 0;
			else
				arr[j][i] = vec2[i][j - 1];
		}
	}
}

void f(ll here)
{
	if(here >= 5)
	{
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
				arr[i][j] = a[i][j];
		}
		
		for(ll i = 0 ; i < 5 ; i++)
		{
			if(b[i] == 1)
				U();
			
			else if(b[i] == 2)
			{
				for(ll j = 1 ; j <= n ; j++)
				{
					for(ll k = 1 ; k <= n ; k++)
						tmp[k][n - j + 1] = arr[j][k];
				}
				
				for(ll j = 1 ; j <= n ; j++)
				{
					for(ll k = 1 ; k <= n ; k++)
						arr[j][k] = tmp[j][k];
				}
				
				U();
				
				for(ll j = 1 ; j <= n ; j++)
				{
					for(ll k = 1 ; k <= n ; k++)
						tmp[n - k + 1][j] = arr[j][k];
				}
				
				for(ll j = 1 ; j <= n ; j++)
				{
					for(ll k = 1 ; k <= n ; k++)
						arr[j][k] = tmp[j][k];
				}
			}
			
			else if(b[i] == 3)
			{
				for(ll j = 1 ; j <= n ; j++)
				{
					for(ll k = 1 ; k <= n ; k++)
						tmp[n - j + 1][k] = arr[j][k];
				}
				
				for(ll j = 1 ; j <= n ; j++)
				{
					for(ll k = 1 ; k <= n ; k++)
						arr[j][k] = tmp[j][k];
				}
				
				U();
				
				for(ll j = 1 ; j <= n ; j++)
				{
					for(ll k = 1 ; k <= n ; k++)
						tmp[n - j + 1][k] = arr[j][k];
				}
				
				for(ll j = 1 ; j <= n ; j++)
				{
					for(ll k = 1 ; k <= n ; k++)
						arr[j][k] = tmp[j][k];
				}
			}
			
			else
			{
				for(ll j = 1 ; j <= n ; j++)
				{
					for(ll k = 1 ; k <= n ; k++)
						tmp[n - k + 1][j] = arr[j][k];
				}
				
				for(ll j = 1 ; j <= n ; j++)
				{
					for(ll k = 1 ; k <= n ; k++)
						arr[j][k] = tmp[j][k];
				}
				
				U();
				
				for(ll j = 1 ; j <= n ; j++)
				{
					for(ll k = 1 ; k <= n ; k++)
						tmp[k][n - j + 1] = arr[j][k];
				}
				
				for(ll j = 1 ; j <= n ; j++)
				{
					for(ll k = 1 ; k <= n ; k++)
						arr[j][k] = tmp[j][k];
				}
			}
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
				ans = max(ans, arr[i][j]);
		}
		
		return;
	}
	
	for(ll i = 1 ; i <= 4 ; i++)
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
		for(ll j = 1 ; j <= n ; j++)
			cin >> a[i][j];
	}
	
	f(0);
	
	cout << ans;
	return 0;
}