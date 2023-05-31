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

ll n, m;
char all[1501][1501];
ll a[1501][1501];
ll nu[1501][1501];
ll col[1501][1501];
ll maxx[1250010][2], minn[1250010][2];
ll dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
ll dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
ll ddx[] = {-1, -1, 0};
ll ddy[] = {-1, 0, -1};
ll rng[1501][1501][4];
ll cc;
ll ans = INF, xans, yans;

ll f(ll x1, ll y1, ll x2, ll y2)
{
	return nu[x2][y2] - nu[x1 - 1][y2] - nu[x2][y1 - 1] + nu[x1 - 1][y1 - 1];
}

void dfs(ll x, ll y)
{
	if(x <= 0 || y <= 0 || x > n || y > m)
		return;
	
	if(col[x][y] || !a[x][y])
		return;
	
	maxx[cc][0] = max(maxx[cc][0], x);
	maxx[cc][1] = max(maxx[cc][1], y);
	minn[cc][0] = min(minn[cc][0], x);
	minn[cc][1] = min(minn[cc][1], y);
	col[x][y] = cc;
	
	for(ll d = 0 ; d < 8 ; d++)
		dfs(x + dx[d], y + dy[d]);
}

int main(void)
{
	fastio
	
	cin >> m >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			cin >> all[i][j];
			
			if(all[i][j] == '#')
				a[i][j] = 1;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			nu[i][j] += nu[i - 1][j] + nu[i][j - 1] - nu[i - 1][j - 1] + a[i][j];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			if(!a[i][j] || col[i][j])
				continue;
			
			cc++;
			maxx[cc][0] = maxx[cc][1] = -INF;
			minn[cc][0] = minn[cc][1] = INF;
			
			dfs(i, j);
		}
	}
	
	for(ll i = 0 ; i < 4 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			for(ll k = 1 ; k <= m ; k++)
				rng[j][k][i] = INF;
		}
	}
	
	for(ll i = 0 ; i < 4 ; i++)
	{
		queue< pair<ll, pll> > q;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			for(ll k = 1 ; k <= m ; k++)
			{
				if((i == 0 && minn[col[j][k]][0] == 1) || (i == 1 && maxx[col[j][k]][0] == n) || (i == 2 && minn[col[j][k]][1] == 1) || (i == 3 && maxx[col[j][k]][1] == m))
				{
					if(rng[j][k][i] == INF)
					{
						q.push({0, {j, k}});
						rng[j][k][i] = -1;
					}
				}
			}
		}
		
		for(ll j = 1 ; j <= n ; j++)
		{
			for(ll k = 1 ; k <= m ; k++)
			{
				if((i == 0 && minn[col[j][k]][0] == 1) || (i == 1 && maxx[col[j][k]][0] == n) || (i == 2 && minn[col[j][k]][1] == 1) || (i == 3 && maxx[col[j][k]][1] == m))
				{
					if(j + 1 <= n && k - 1 >= 1 && rng[j + 1][k - 1][i] == INF)
					{
						q.push({2, {j + 1, k - 1}});
						rng[j + 1][k - 1][i] = 0;
					}
					
					if(j - 1 >= 1 && k + 1 <= m && rng[j - 1][k + 1][i] == INF)
					{
						q.push({1, {j - 1, k + 1}});
						rng[j - 1][k + 1][i] = 0;
					}
					
					if(j + 1 <= n && k + 1 <= m && rng[j + 1][k + 1][i] == INF)
						rng[j + 1][k + 1][i] = 0;
					
					if(j + 1 <= n && rng[j + 1][k][i] == INF)
						rng[j + 1][k][i] = 0;
					
					if(k + 1 <= m && rng[j][k + 1][i] == INF)
						rng[j][k + 1][i] = 0;
				}
			}
		}
		
		while(!q.empty())
		{
			pair<ll, pll> qq = q.front();
			q.pop();
			
			if(qq.fi == 0)
			{
				for(ll d = 0 ; d < 3 ; d++)
				{
					pair<ll, pll> nxt;
					
					nxt.fi = qq.fi;
					nxt.se.fi = qq.se.fi + ddx[d];
					nxt.se.se = qq.se.se + ddy[d];
					
					if(nxt.se.fi <= 0 || nxt.se.se <= 0)
						continue;
					
					if(rng[nxt.se.fi][nxt.se.se][i] != INF)
						continue;
					
					rng[nxt.se.fi][nxt.se.se][i] = rng[qq.se.fi][qq.se.se][i] + 1;
					q.push(nxt);
				}
			}
			
			else
			{
				for(ll d = qq.fi ; d <= qq.fi ; d++)
				{
					pair<ll, pll> nxt;
					
					nxt.fi = qq.fi;
					nxt.se.fi = qq.se.fi + ddx[d];
					nxt.se.se = qq.se.se + ddy[d];
					
					if(nxt.se.fi <= 0 || nxt.se.se <= 0)
						continue;
					
					if(rng[nxt.se.fi][nxt.se.se][i] != INF)
						continue;
					
					rng[nxt.se.fi][nxt.se.se][i] = rng[qq.se.fi][qq.se.se][i] + 1;
					q.push(nxt);
				}
			}
		}
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		rng[1][i][0] = 0;
		rng[n][i][1] = 0;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		rng[i][1][2] = 0;
		rng[i][m][3] = 0;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			rng[i][j][1] = min(rng[i][j][1], n - i);
			rng[i][j][3] = min(rng[i][j][3], m - j);
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			ll l = 0, r = max(n, m) + 1;
			
			if(i == 1 && j == 1)
				continue;
			
			if(i == n && j == m)
				continue;
			
			if(a[i][j])
				continue;
			
			while(l <= r)
			{
				ll mid = (l + r) / 2;
				ll X = i + mid, Y = j + mid;
				
				if(X > n || Y > m)
					r = mid - 1;
				else if(X == n && Y == m)
					r = mid - 1;
				else if(f(i, j, X, Y))
					r = mid - 1;
				else
					l = mid + 1;
			}
			
			if(max(rng[i][j][0], rng[i][j][1]) <= r)
			{
				if(ans > max(rng[i][j][0], rng[i][j][1]))
				{
					ans = max(rng[i][j][0], rng[i][j][1]);
					xans = i;
					yans = j;
				}
			}
			
			if(max(rng[i][j][2], rng[i][j][3]) <= r)
			{
				if(ans > max(rng[i][j][2], rng[i][j][3]))
				{
					ans = max(rng[i][j][2], rng[i][j][3]);
					xans = i;
					yans = j;
				}
			}
			
			if(max(rng[i][j][0], rng[i][j][2]) <= r)
			{
				if(ans > max(rng[i][j][0], rng[i][j][2]))
				{
					ans = max(rng[i][j][0], rng[i][j][2]);
					xans = i;
					yans = j;
				}
			}
			
			if(max(rng[i][j][1], rng[i][j][3]) <= r)
			{
				if(ans > max(rng[i][j][1], rng[i][j][3]))
				{
					ans = max(rng[i][j][1], rng[i][j][3]);
					xans = i;
					yans = j;
				}
			}
		}
	}
	
	if(ans == INF)
		cout << "Impossible";
	else
		cout << ans + 1 sp << yans sp << xans;
	
	return 0;
}