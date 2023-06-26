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

ll n, m, q;
ll a[1010][1010];
ll num[1010][1010];
ll cc;
pll qry[1000010];
ll all, bll, cll, dll;
ll L[1000010], R[1000010], mid[1000010];
ll pa[1000010], ra[1000010];
pll yuk[1000010];
vector<pll> A;
ll dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

ll ffind(ll here)
{
	if(pa[here] == here)
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
	
	cin >> n >> m >> q;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			cin >> a[i][j];
			
			num[i][j] = ++cc;
			yuk[cc] = {i, j};
			A.push_back({a[i][j], cc});
		}
	}
	
	for(ll i = 1 ; i <= q ; i++)
	{
		cin >> all >> bll >> cll >> dll;
		qry[i] = {num[all][bll], num[cll][dll]};
	}
	
	for(ll i = 1 ; i <= q ; i++)
		L[i] = 1, R[i] = 2000000;
	
	sort(A.begin(), A.end());
	
	for(ll o = 0 ; o < 25 ; o++)
	{
		vector<pll> Q;
		
		for(ll i = 1 ; i <= cc ; i++)
			pa[i] = i, ra[i] = 0;
		
		for(ll i = 1 ; i <= q ; i++)
		{
			if(L[i] <= R[i])
			{
				mid[i] = (L[i] + R[i]) >> 1;
				Q.push_back({mid[i], i});
			}
		}
		
		sort(Q.begin(), Q.end());
		
		ll p = 0;
		
		for(auto &i : Q)
		{
			while(p < n * m && A[p].fi <= i.fi)
			{
				for(ll d = 0 ; d < 4 ; d++)
				{
					ll nx = yuk[A[p].se].fi + dx[d];
					ll ny = yuk[A[p].se].se + dy[d];
					
					if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && a[nx][ny] <= i.fi)
						uunion(A[p].se, num[nx][ny]);
				}
				
				p++;
			}
			
			if(ffind(qry[i.se].fi) == ffind(qry[i.se].se))
				R[i.se] = mid[i.se] - 1;
			else
				L[i.se] = mid[i.se] + 1;
		}
	}
	
	for(ll i = 1 ; i <= q ; i++)
	{
		if(qry[i].fi == qry[i].se)
			cout << a[yuk[qry[i].fi].fi][yuk[qry[i].fi].se] en;
		else
			cout << L[i] en;
	}
	
	return 0;
}