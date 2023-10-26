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

ll n, m, D;
char a[510][510];
ll dist[510][510];
deque<pll> dq;
deque<ll> cq;
vector<pll> dir;
ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};

int main(void)
{
	fastio
	
	cin >> n >> m >> D;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			cin >> a[i][j];
			dist[i][j] = INF;
		}
	}
	
	for(ll i = -(D - 1) ; i <= (D - 1) ; i++)
	{
		dir.push_back({-D, i});
		dir.push_back({D, i});
		dir.push_back({i, -D});
		dir.push_back({i, D});
	}
	
	compress(dir);
	
	dist[1][1] = 1;
	dq.push_back({1, 1});
	cq.push_back(1);
	
	while(!dq.empty())
	{
		pll qq = dq.front();
		dq.pop_front();
		ll cc = cq.front();
		cq.pop_front();
		
		if(dist[qq.fi][qq.se] != cc)
			continue;
		
		for(ll d = 0 ; d < 4 ; d++)
		{
			ll nx = qq.fi + dx[d];
			ll ny = qq.se + dy[d];
			
			if(1 <= nx && nx <= n && 1 <= ny && ny <= m && a[nx][ny] == '.' && dist[nx][ny] > dist[qq.fi][qq.se])
			{
				dist[nx][ny] = dist[qq.fi][qq.se];
				dq.push_front({nx, ny});
				cq.push_front(dist[nx][ny]);
			}
		}
		
		for(auto &d : dir)
		{
			ll nx = qq.fi + d.fi;
			ll ny = qq.se + d.se;
			
			if(nx <= 0)
				nx = 1;
			else if(nx > n)
				nx = n;
			
			if(ny <= 0)
				ny = 1;
			else if(ny > m)
				ny = m;
			
			if(dist[nx][ny] > dist[qq.fi][qq.se] + 1)
			{
				dist[nx][ny] = dist[qq.fi][qq.se] + 1;
				dq.push_back({nx, ny});
				cq.push_back(dist[nx][ny]);
			}
		}
	}
	
	cout << dist[n][m] - 1;
	return 0;
}