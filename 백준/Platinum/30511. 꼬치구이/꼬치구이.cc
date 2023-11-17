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
char a[110][110];
ll num[110][110];
ll cc1, cc2;
ll dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
ll dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
vector<ll> vec[10010];
set<pll> st;
ll ans;
ll chk[10010];
ll np[10010];

ll dfs(ll here)
{
	for(auto &i : vec[here])
	{
		if(chk[i])
			continue;
		
		chk[i] = 1;
		
		if(!np[i] || dfs(np[i]))
		{
			np[i] = here;
			return 1;
		}
	}
	
	return 0;
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
			if(a[i][j] == 'S')
				num[i][j] = ++cc1;
			else if(a[i][j] == 'G')
				num[i][j] = ++cc2;
		}
	}
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < m ; j++)
		{
			if(a[i][j] == 'M')
			{
				for(ll d = 0 ; d < 8 ; d++)
				{
					ll nx = i + dx[d];
					ll ny = j + dy[d];
					ll nnx = nx + dx[d];
					ll nny = ny + dy[d];
					
					if(nx < 0 || ny < 0 || nx >= n || ny >= m)
						continue;
					
					if(nnx < 0 || nny < 0 || nnx >= n || nny >= m)
						continue;
					
					if(a[nx][ny] == 'G' && a[nnx][nny] == 'S')
						swap(nx, nnx), swap(ny, nny);
					
					if(a[nx][ny] == 'S' && a[nnx][nny] == 'G')
					{
						if(st.find({num[nx][ny], num[nnx][nny]}) == st.end())
						{
							st.insert({num[nx][ny], num[nnx][nny]});
							vec[num[nx][ny]].push_back(num[nnx][nny]);
						}
					}
				}
			}
		}
	}
	
	for(ll i = 1 ; i <= cc1 ; i++)
	{
		memset(chk, 0, sizeof(chk));
		ans += dfs(i);
	}
	
	cout << ans;
	return 0;
}