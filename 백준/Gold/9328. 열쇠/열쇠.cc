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

ll t;
ll n, m;
char a[110][110];
queue<pll> q, door[30];
ll chk[110][110];
char ky[110];
ll now[30];
ll dx[10] = {-1, 1, 0, 0};
ll dy[10] = {0, 0, -1, 1};

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		ll ans = 0;
		
		cin >> n >> m;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= m ; j++)
				cin >> a[i][j];
		}
		
		while(!q.empty())
			q.pop();
		
		for(ll i = 0 ; i < 26 ; i++)
		{
			while(!door[i].empty())
				door[i].pop();
			
			now[i] = 0;
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= m ; j++)
				chk[i][j] = 0;
		}
		
		for(ll i = 1 ; i <= m ; i++)
		{
			if(a[1][i] == '*')
				continue;
			
			if('A' <= a[1][i] && a[1][i] <= 'Z')
			{
				door[a[1][i] - 'A'].push({1, i});
				continue;
			}
			
			if(chk[1][i])
				continue;
			
			q.push({1, i});
			chk[1][i] = 1;
		}
		
		for(ll i = 1 ; i <= m ; i++)
		{
			if(a[n][i] == '*')
				continue;
			
			if('A' <= a[n][i] && a[n][i] <= 'Z')
			{
				door[a[n][i] - 'A'].push({n, i});
				continue;
			}
			
			if(chk[n][i])
				continue;
			
			q.push({n, i});
			chk[n][i] = 1;
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(a[i][1] == '*')
				continue;
			
			if('A' <= a[i][1] && a[i][1] <= 'Z')
			{
				door[a[i][1] - 'A'].push({i, 1});
				continue;
			}
			
			if(chk[i][1])
				continue;
			
			q.push({i, 1});
			chk[i][1] = 1;
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(a[i][m] == '*')
				continue;
			
			if('A' <= a[i][m] && a[i][m] <= 'Z')
			{
				door[a[i][m] - 'A'].push({i, m});
				continue;
			}
			
			if(chk[i][m])
				continue;
			
			q.push({i, m});
			chk[i][m] = 1;
		}
		
		cin >> ky;
		
		if(strcmp(ky, "0"))
		{
			for(ll i = 0 ; ky[i] != '\0' ; i++)
			{
				now[ky[i] - 'a'] = 1;
				
				while(!door[ky[i] - 'a'].empty())
				{
					pll qq = door[ky[i] - 'a'].front();
					door[ky[i] - 'a'].pop();
					
					q.push(qq);
					chk[qq.fi][qq.se] = 1;
				}
			}
		}
		
		while(!q.empty())
		{
			pll qq = q.front();
			q.pop();
			
			if(a[qq.fi][qq.se] == '$')
				ans++;
			
			else if('a' <= a[qq.fi][qq.se] && a[qq.fi][qq.se] <= 'z')
			{
				now[a[qq.fi][qq.se] - 'a'] = 1;
				
				while(!door[a[qq.fi][qq.se] - 'a'].empty())
				{
					pll qqq = door[a[qq.fi][qq.se] - 'a'].front();
					door[a[qq.fi][qq.se] - 'a'].pop();
					
					q.push(qqq);
					chk[qqq.fi][qqq.se] = 1;
				}
			}
			
			for(ll d = 0 ; d < 4 ; d++)
			{
				ll nx = qq.fi + dx[d];
				ll ny = qq.se + dy[d];
				
				if(nx <= 0 || ny <= 0 || nx > n || ny > m)
					continue;
				
				if(a[nx][ny] == '*' || chk[nx][ny])
					continue;
				
				if('A' <= a[nx][ny] && a[nx][ny] <= 'Z')
				{
					if(now[a[nx][ny] - 'A'])
					{
						chk[nx][ny] = 1;
						q.push({nx, ny});
					}
					
					else
						door[a[nx][ny] - 'A'].push({nx, ny});
					
					continue;
				}
				
				chk[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
		
		cout << ans en;
	}
	
	return 0;
}