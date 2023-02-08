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

struct shark
{
	ll spd, dir, siz;
};

ll R, C, M;
ll dx[10] = {0, -1, 1, 0, 0};
ll dy[10] = {0, 0, 0, 1, -1};
shark a[110][110];
ll all, bll;
shark cll;
ll ans;
shark tmp[110][110];

int main(void)
{
	cin >> R >> C >> M;
	
	for(ll i = 1 ; i <= M ; i++)
	{
		cin >> all >> bll >> cll.spd >> cll.dir >> cll.siz;
		a[all][bll] = cll;
	}
	
	for(ll i = 1 ; i <= C ; i++)
	{
		for(ll j = 1 ; j <= R ; j++)
		{
			if(a[j][i].dir)
			{
				ans += a[j][i].siz;
				a[j][i] = {0, 0, 0};
				
				break;
			}
		}
		
		for(ll j = 1 ; j <= R ; j++)
		{
			for(ll k = 1 ; k <= C ; k++)
				tmp[j][k] = {0, 0, 0};
		}
		
		for(ll j = 1 ; j <= R ; j++)
		{
			for(ll k = 1 ; k <= C ; k++)
			{
				if(a[j][k].dir)
				{
					ll gap = a[j][k].spd;
					ll dr = a[j][k].dir;
					
					if(a[j][k].dir <= 2)
						gap %= (R - 1) * 2;
					else
						gap %= (C - 1) * 2;
					
					ll X = j, Y = k;
					
					while(gap--)
					{
						ll nx = X + dx[dr];
						ll ny = Y + dy[dr];
						
						if(nx <= 0 || ny <= 0 || nx > R || ny > C)
						{
							if(dr <= 2)
								dr = 3 - dr;
							else
								dr = 7 - dr;
							
							nx = X + dx[dr];
							ny = Y + dy[dr];
						}
						
						X = nx, Y = ny;
					}
					
					if(tmp[X][Y].siz < a[j][k].siz)
					{
						tmp[X][Y] = a[j][k];
						tmp[X][Y].dir = dr;
					}
				}
			}
		}
		
		for(ll j = 1 ; j <= R ; j++)
		{
			for(ll k = 1 ; k <= C ; k++)
				a[j][k] = tmp[j][k];
		}
	}
	
	cout << ans;
	return 0;
}