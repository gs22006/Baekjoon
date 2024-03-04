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
string a[610];
ll x, y;
ll ans;

void dfs(ll X, ll Y)
{
	if(X < 0 || Y < 0 || X >= n || Y >= m)
		return;
	
	if(a[X][Y] == 'X')
		return;
	
	if(a[X][Y] == 'P')
		ans++;
	
	a[X][Y] = 'X';
	dfs(X + 1, Y);
	dfs(X, Y + 1);
	dfs(X - 1, Y);
	dfs(X, Y - 1);
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 0 ; i < n ; i++)
		cin >> a[i];
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < m ; j++)
		{
			if(a[i][j] == 'I')
			{
				x = i, y = j;
				break;
			}
		}
	}
	
	dfs(x, y);
	
	if(ans == 0)
		cout << "TT";
	else
		cout << ans;
	
	return 0;
}