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
ll a[1010][1010];
ll sx, sy;
queue<pll> q;
ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
ll chk[1010][1010];
ll dist[1010][1010];

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			if(a[i][j] == 2)
				sx = i, sy = j;
		}
	}
	
	q.push({sx, sy});
	chk[sx][sy] = 1;
	dist[sx][sy] = 0;
	
	while(!q.empty())
	{
		pll qq = q.front();
		q.pop();
		
		for(ll d = 0 ; d < 4 ; d++)
		{
			ll nx = qq.fi + dx[d];
			ll ny = qq.se + dy[d];
			
			if(nx <= 0 || ny <= 0 || nx > n || ny > m || chk[nx][ny] || a[nx][ny] == 0)
				continue;
			
			q.push({nx, ny});
			chk[nx][ny] = 1;
			dist[nx][ny] = dist[qq.fi][qq.se] + 1;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			if(!chk[i][j] && a[i][j] == 1)
				cout << -1 sp;
			else
				cout << dist[i][j] sp;
		}
		
		cout en;
	}
	
	return 0;
}