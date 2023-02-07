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

ll n, m, K;
ll a[510][510];
ll nu[510][510];
ll cou[1000010];
ll ans;

ll sum(ll X1, ll X2, ll Y1, ll Y2)
{
	return nu[X2][Y2] - nu[X2][Y1 - 1] - nu[X1 - 1][Y2] + nu[X1 - 1][Y1 - 1];
}

int main(void)
{
	fastio
	
	cin >> n >> m >> K;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			cin >> a[i][j];
			nu[i][j] = nu[i - 1][j] + nu[i][j - 1] - nu[i - 1][j - 1] + a[i][j];
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = i ; j <= n ; j++)
		{
			vector<ll> vec;
			
			vec.push_back(0LL);
			
			for(ll k = 1 ; k <= m ; k++)
				vec.push_back((vec.back() + sum(i, j, k, k)) % K);
			
			for(ll k = 0 ; k < (ll)vec.size() ; k++)
				cou[vec[k] % K]++;
			
			for(ll k = 0 ; k < (ll)vec.size() ; k++)
			{
				ans += cou[vec[k] % K] * (cou[vec[k] % K] - 1) / 2;
				cou[vec[k] % K] = 0;
			}
		}
	}
	
	cout << ans;
	return 0;
}