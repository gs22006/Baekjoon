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
char all[1010][1010];
ll a[1010][1010];
ll tmp[1010][1010];
ll ans;
ll dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
ll dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
queue<pll> q;
queue<ll> cq;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 0 ; i < n ; i++)
	{
		cin >> all[i];
		
		for(ll j = 0 ; j < m ; j++)
		{
			if(all[i][j] == '.')
				a[i][j] = 0;
			else
				a[i][j] = all[i][j] - '0';
		}
	}
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < m ; j++)
		{
			tmp[i][j] = a[i][j];
			
			for(ll d = 0 ; d < 8 ; d++)
			{
				ll nx = i + dx[d];
				ll ny = j + dy[d];
				
				if(nx < 0 || ny < 0 || nx >= n || ny >= m)
					continue;
				
				if(!a[nx][ny])
					tmp[i][j]--;
			}
			
			if(a[i][j] > 0 && tmp[i][j] <= 0)
			{
				q.push({i, j});
				cq.push(1);
				tmp[i][j] = 0;
			}
		}
	}
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < m ; j++)
			a[i][j] = tmp[i][j];
	}
	
	while(!q.empty())
	{
		pll qq = q.front();
		q.pop();
		ll cc = cq.front();
		cq.pop();
		
		ans = max(ans, cc);
		
		for(ll d = 0 ; d < 8 ; d++)
		{
			ll nx = qq.fi + dx[d];
			ll ny = qq.se + dy[d];
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			
			if(a[nx][ny])
			{
				a[nx][ny]--;
				
				if(!a[nx][ny])
				{
					q.push({nx, ny});
					cq.push(cc + 1);
				}
			}
		}
	}
	
	cout << ans;
	return 0;
}