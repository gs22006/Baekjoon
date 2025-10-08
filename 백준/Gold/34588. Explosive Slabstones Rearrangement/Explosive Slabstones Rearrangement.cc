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

ll n, m, K;
pll a[250010];
ll b[510][510];
ll chk[510][510];
ll dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
ll l, r;
ll L, R, U, D;

int main(void)
{
	fastio
	
	cin >> n >> m >> K;
	
	for(ll i = 1 ; i <= K ; i++)
	{
		cin >> a[i].fi >> a[i].se;
		b[a[i].fi][a[i].se] = i;
	}
	
	cin >> U >> L >> D >> R;
	
	l = 0;
	r = K;
	
	while(l <= r)
	{
		ll mid = (l + r) >> 1;
		ll ff = 0;
		
		for(ll i = U ; i <= D ; i++)
		{
			for(ll j = L ; j <= R ; j++)
			{
				if(b[i][j] > mid)
					ff = 1;
			}
		}
		
		if(ff)
		{
			l = mid + 1;
			continue;
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= m ; j++)
				chk[i][j] = 0;
		}
		
		queue<pll> q;
		
		q.push({U, L});
		chk[U][L] = 1;
		
		while(!q.empty())
		{
			pll qq = q.front();
			q.pop();
			
			for(ll d = 0 ; d < 4 ; d++)
			{
				ll nx = qq.fi + dx[d];
				ll ny = qq.se + dy[d];
				
				if(1 <= nx && nx <= n && 1 <= ny && ny <= m && !chk[nx][ny] && b[nx][ny] <= mid)
				{
					q.push({nx, ny});
					chk[nx][ny] = 1;
				}
			}
		}
		
		ll cou1 = 0, cou2 = 0;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= m ; j++)
			{
				if(!chk[i][j])
					continue;
				
				cou1++;
				
				if(1 <= b[i][j] && b[i][j] <= mid)
					cou2++;
			}
		}
		
		cou1 -= (D - U + 1) * (R - L + 1);
		
		if(cou1 >= cou2)
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	if(l == K + 1)
	{
		cout << -1;
		return 0;
	}
	
	cout << l;
	return 0;
}