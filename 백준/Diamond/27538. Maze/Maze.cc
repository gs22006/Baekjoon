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

ll R, C, N;
ll sx, sy;
ll ex, ey;
vector<string> a;
vector< vector<ll> > chk;
vector<ll> tmp;
string all;
vector<pll> now;
ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
ll T;

void Wbfs(void)
{
	queue<pll> q;
	
	for(auto &i : now)
		q.push(i);
	
	while(!q.empty())
	{
		pll qq = q.front();
		q.pop();
		
		for(ll d = 0 ; d < 4 ; d++)
		{
			ll nx = qq.fi + dx[d];
			ll ny = qq.se + dy[d];
			
			if(nx < 0 || ny < 0 || nx >= R || ny >= C)
				continue;
			
			if(a[nx][ny] == '#' || chk[nx][ny])
				continue;
			
			chk[nx][ny] = T;
			now.push_back({nx, ny});
			q.push({nx, ny});
		}
	}
}

int main(void)
{
	fastio
	
	cin >> R >> C >> N;
	cin >> sx >> sy;
	cin >> ex >> ey;
	
	sx--, sy--;
	ex--, ey--;
	
	for(ll i = 0 ; i < R ; i++)
	{
		cin >> all;
		a.push_back(all);
	}
	
	for(ll i = 0 ; i < C ; i++)
		tmp.push_back(0);
	
	for(ll i = 0 ; i < R ; i++)
		chk.push_back(tmp);
	
	T = 1;
	chk[sx][sy] = T;
	now.push_back({sx, sy});
	Wbfs();
	
	while(1)
	{
		if(chk[ex][ey])
		{
			cout << chk[ex][ey] - 1;
			return 0;
		}
		
		T++;
		
		vector<pll> tmp2;
		
		for(auto &i : now)
		{
			for(ll d = 0 ; d < 4 ; d++)
			{
				ll nx = i.fi + dx[d];
				ll ny = i.se + dy[d];
				
				if(nx < 0 || ny < 0 || nx >= R || ny >= C)
					continue;
				
				if(chk[nx][ny] || a[nx][ny] == '.')
					continue;
				
				chk[nx][ny] = T;
				tmp2.push_back({nx, ny});
			}
		}
		
		now = tmp2;
		
		for(auto &i : tmp2)
		{
			for(ll d = 1 ; d < N ; d++)
			{
				ll nx = i.fi - d;
				ll ny = i.se;
				
				if(nx < 0 || nx >= R)
					continue;
				
				if(chk[nx][ny])
					break;
				
				chk[nx][ny] = T;
				now.push_back({nx, ny});
			}
			
			for(ll d = 1 ; d < N ; d++)
			{
				ll nx = i.fi + d;
				ll ny = i.se;
				
				if(nx < 0 || nx >= R)
					continue;
				
				if(chk[nx][ny])
					break;
				
				chk[nx][ny] = T;
				now.push_back({nx, ny});
			}
		}
		
		tmp2 = now;
		
		for(auto &i : tmp2)
		{
			for(ll d = 1 ; d < N ; d++)
			{
				ll nx = i.fi;
				ll ny = i.se - d;
				
				if(ny < 0 || ny >= C)
					continue;
				
				if(chk[nx][ny])
					break;
				
				chk[nx][ny] = T;
				now.push_back({nx, ny});
			}
			
			for(ll d = 1 ; d < N ; d++)
			{
				ll nx = i.fi;
				ll ny = i.se + d;
				
				if(ny < 0 || ny >= C)
					continue;
				
				if(chk[nx][ny])
					break;
				
				chk[nx][ny] = T;
				now.push_back({nx, ny});
			}
		}
		
		Wbfs();
	}
	
	return 0;
}