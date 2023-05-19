#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 987654321
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n, w, h;
char a[510][510];
ll num[510][510];
pll fin[5][510][510];
ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
ll A[] = {2, 3, 1, 0};
ll C[] = {3, 2, 0, 1};
vector<ll> vec[250010];
ll dist[50][510][510];
ll gnum[20][20];
ll cc;
pll p[20];
pll gu[110];
ll ans = INF;

int main(void)
{
	fastio
	
	cin >> n >> w >> h;
	
	for(ll i = 1 ; i <= h ; i++)
	{
		for(ll j = 1 ; j <= w ; j++)
		{
			cin >> a[i][j];
			num[i][j] = (i - 1) * w + j;
		}
	}
	
	for(ll i = 1 ; i <= h ; i++)
	{
		for(ll j = 1 ; j <= w ; j++)
		{
			if('1' <= a[i][j] && a[i][j] <= '9')
				p[a[i][j] - '0'] = {i, j};
		}
	}
	
	for(ll i = 1 ; i <= h ; i++)
	{
		for(ll j = 1 ; j <= w ; j++)
		{
			if(a[i][j] == 'x')
				continue;
			
			for(ll d = 0 ; d < 4 ; d++)
			{
				if(fin[d][i][j].fi)
					continue;
				
				vector< pair<ll, pll> > trl;
				ll X = i, Y = j;
				ll D = d;
				pll gap;
				
				while(1)
				{
					ll nx = X + dx[D];
					ll ny = Y + dy[D];
					
					trl.push_back({D, {X, Y}});
					
					if(nx <= 0 || ny <= 0 || nx > h || ny > w)
					{
						gap = {X, Y};
						break;
					}
					
					ll nd = D;
					
					if(a[nx][ny] == 'x')
					{
						gap = {X, Y};
						break;
					}
					
					if(a[nx][ny] == 'A')
						nd = A[nd];
					else if(a[nx][ny] == 'C')
						nd = C[nd];
					
					if(fin[nd][nx][ny].fi)
					{
						gap = fin[nd][nx][ny];
						break;
					}
					
					X = nx;
					Y = ny;
					D = nd;
				}
				
				for(auto &o : trl)
					fin[o.fi][o.se.fi][o.se.se] = gap;
			}
		}
	}
	
	for(ll i = 1 ; i <= h ; i++)
	{
		for(ll j = 1 ; j <= w ; j++)
		{
			for(ll d = 0 ; d < 4 ; d++)
			{
				if(fin[d][i][j].fi)
					vec[num[i][j]].push_back(num[fin[d][i][j].fi][fin[d][i][j].se]);
			}
		}
	}
	
	for(ll L = 0 ; L < n ; L++)
	{
		for(ll i = 1 ; i <= n ; i++)
		{
			ll j = i + L;
			
			if(j > n)
				break;
			
			gnum[i][j] = ++cc;
			gu[cc] = {i, j};
		}
	}
	
	for(ll i = 1 ; i <= cc ; i++)
	{
		for(ll j = 1 ; j <= h ; j++)
		{
			for(ll k = 1 ; k <= w ; k++)
				dist[i][j][k] = INF;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
		dist[i][p[i].fi][p[i].se] = 0;
	
	for(ll i = 1 ; i <= cc ; i++)
	{
		if(i > n)
		{
			for(ll j = 1 ; j <= h ; j++)
			{
				for(ll k = 1 ; k <= w ; k++)
				{
					for(ll o = gu[i].fi ; o < gu[i].se ; o++)
						dist[i][j][k] = min(dist[i][j][k], dist[gnum[gu[i].fi][o]][j][k] + dist[gnum[o + 1][gu[i].se]][j][k]);
				}
			}
		}
		
		priority_queue<pll> pq;
		
		for(ll j = 1 ; j <= h ; j++)
		{
			for(ll k = 1 ; k <= w ; k++)
			{
				if(dist[i][j][k] != INF)
					pq.push({-dist[i][j][k], num[j][k]});
			}
		}
		
		while(!pq.empty())
		{
			pll qq = pq.top();
			pq.pop();
			
			ll x = (qq.se - 1) / w + 1;
			ll y = (qq.se - 1) % w + 1;
			
			for(auto &j : vec[qq.se])
			{
				ll nx = (j - 1) / w + 1;
				ll ny = (j - 1) % w + 1;
				
				if(dist[i][nx][ny] > dist[i][x][y] + 1)
				{
					dist[i][nx][ny] = dist[i][x][y] + 1;
					pq.push({-dist[i][nx][ny], j});
				}
			}
		}
	}
	
	for(ll i = 1 ; i <= h ; i++)
	{
		for(ll j = 1 ; j <= w ; j++)
			ans = min(ans, dist[cc][i][j]);
	}
	
	if(ans == INF)
		cout << -1;
	else
		cout << ans;
	
	return 0;
}