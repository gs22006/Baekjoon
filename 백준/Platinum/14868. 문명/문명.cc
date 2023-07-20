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

ll n;
ll K;
pll a[100010];
ll pa[100010], ra[100010];
ll chk[2010][2010];
queue<pll> q;
queue<ll> cq;
ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
ll cou;

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
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= K ; i++)
	{
		cin >> a[i].fi >> a[i].se;
		
		pa[i] = i;
		chk[a[i].fi][a[i].se] = i;
		q.push(a[i]);
		cq.push(0);
	}
	
	for(ll i = 1 ; i <= K ; i++)
	{
		for(ll d = 0 ; d < 4 ; d++)
		{
			ll nx = a[i].fi + dx[d];
			ll ny = a[i].se + dy[d];
			
			if(nx <= 0 || ny <= 0 || nx > n || ny > n)
				continue;
			
			if(chk[nx][ny] && ffind(chk[a[i].fi][a[i].se]) != ffind(chk[nx][ny]))
			{
				uunion(chk[nx][ny], chk[a[i].fi][a[i].se]);
				cou++;
			}
		}
	}
	
	if(cou == K - 1)
	{
		cout << 0;
		return 0;
	}
	
	while(!q.empty())
	{
		pll qq = q.front();
		q.pop();
		ll cc = cq.front();
		cq.pop();
		
		for(ll d = 0 ; d < 4 ; d++)
		{
			ll nx = qq.fi + dx[d];
			ll ny = qq.se + dy[d];
			
			if(nx <= 0 || ny <= 0 || nx > n || ny > n)
				continue;
			
			if(chk[nx][ny])
			{
				if(ffind(chk[nx][ny]) != ffind(chk[qq.fi][qq.se]))
				{
					uunion(chk[nx][ny], chk[qq.fi][qq.se]);
					cou++;
				}
				
				continue;
			}
			
			chk[nx][ny] = chk[qq.fi][qq.se];
			q.push({nx, ny});
			cq.push(cc + 1);
			
			for(ll dd = 0 ; dd < 4 ; dd++)
			{
				ll nx2 = nx + dx[dd];
				ll ny2 = ny + dy[dd];
				
				if(nx2 <= 0 || ny2 <= 0 || nx2 > n || ny2 > n)
					continue;
				
				if(chk[nx2][ny2] && ffind(chk[nx][ny]) != ffind(chk[nx2][ny2]))
				{
					uunion(chk[nx2][ny2], chk[nx][ny]);
					cou++;
				}
			}
		}
		
		if(cou == K - 1)
		{
			cout << cc + 1;
			return 0;
		}
	}
	
	return 0;
}