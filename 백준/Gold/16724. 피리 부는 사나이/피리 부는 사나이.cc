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

ll n, m;
char a[1010][1010];
ll pa[1000010], ra[1000010];
ll bun[30];
ll dx[10] = {-1, 1, 0, 0};
ll dy[10] = {0, 0, -1, 1};
set<ll> st;

ll ffind(ll here)
{
	if(here == pa[here])
		return here;
	
	return pa[here] = ffind(pa[here]);
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	if(X == Y)
		return;
	
	if(ra[X] < ra[Y])
		pa[X] = Y;
	else if(ra[Y] < ra[X])
		pa[Y] = X;
	
	else
	{
		pa[X] = Y;
		ra[Y]++;
	}
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 0 ; i < n ; i++)
		cin >> a[i];
	
	for(ll i = 0 ; i < n * m ; i++)
		pa[i] = i;
	
	bun['L' - 'A'] = 2;
	bun['R' - 'A'] = 3;
	bun['U' - 'A'] = 0;
	bun['D' - 'A'] = 1;
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < m ; j++)
		{
			ll nx = i + dx[bun[a[i][j] - 'A']];
			ll ny = j + dy[bun[a[i][j] - 'A']];
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			
			uunion(i * m + j, nx * m + ny);
		}
	}
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < m ; j++)
			st.insert(ffind(i * m + j));
	}
	
	cout << (ll)st.size();
	return 0;
}