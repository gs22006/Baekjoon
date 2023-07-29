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
vector< vector<ll> > a, chk, nu[110], tmp2;
vector<ll> tmp;
ll gap[50010], gap2[50010], gap3[50010];
ll on[50010], tlf[50010], trg[50010], lf[50010], md[50010], rg[50010];
ll cou[50010];
ll A[50010], B[50010];
ll all;
vector<ll> L, R, U, D;
ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
ll num[5][5][5][5];
ll ans;

void make_nu(void)
{
	for(ll x = 0 ; x < 81 ; x++)
	{
		for(ll i = 0 ; i <= n ; i++)
		{
			for(ll j = 0 ; j <= m ; j++)
				chk[i][j] = 0;
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= m ; j++)
			{
				ll Ux = max(0LL, i - U[x]);
				ll Dx = min(n, i + D[x]);
				ll Lx = max(0LL, j - L[x]);
				ll Rx = min(m, j + R[x]);
				
				for(ll d = 0 ; d < 4 ; d++)
				{
					ll nx = i + dx[d];
					ll ny = j + dy[d];
					
					if(nx <= 0 || ny <= 0 || nx > n || ny > m)
						continue;
					
					if(!(Ux <= nx && nx <= Dx && Lx <= ny && ny <= Rx))
						continue;
					
					ll maxx = -INF;
					
					for(ll dd = 0 ; dd < 4 ; dd++)
					{
						ll nnx = nx + dx[dd];
						ll nny = ny + dy[dd];
						
						if(nnx <= 0 || nny <= 0 || nnx > n || nny > m)
							continue;
						
						if(!(Ux <= nnx && nnx <= Dx && Lx <= nny && nny <= Rx))
							continue;
						
						if(a[nx][ny] > a[nnx][nny])
							maxx = max(maxx, a[nnx][nny]);
					}
					
					if(maxx == a[i][j])
					{
						chk[i][j] = 1;
						break;
					}
				}
			}
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= m ; j++)
				nu[x][i][j] = nu[x][i - 1][j] + nu[x][i][j - 1] - nu[x][i - 1][j - 1] + 1 - chk[i][j];
		}
	}
}

ll sum(ll X, ll x1, ll y1, ll x2, ll y2)
{
	return nu[X][x2][y2] - nu[X][x1 - 1][y2] - nu[X][x2][y1 - 1] + nu[X][x1 - 1][y1 - 1];
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	ll fff = 0;
	
	if(n >= m)
		swap(n, m), fff = 1;
	
	for(ll i = 0 ; i <= m ; i++)
		tmp.push_back(0);
	
	for(ll i = 0 ; i <= n ; i++)
	{
		a.push_back(tmp);
		chk.push_back(tmp);
		
		for(ll j = 0 ; j < 81 ; j++)
			nu[j].push_back(tmp);
	}
	
	if(fff)
		swap(n, m);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			if(fff)
				cin >> a[j][i];
			else
				cin >> a[i][j];
		}
	}
	
	if(fff)
		swap(n, m);
	
	for(ll i = 0 ; i <= 2 ; i++)
	{
		for(ll j = 0 ; j <= 2 ; j++)
		{
			for(ll k = 0 ; k <= 2 ; k++)
			{
				for(ll l = 0 ; l <= 2 ; l++)
				{
					num[i][j][k][l] = (ll)L.size();
					L.push_back(i);
					R.push_back(j);
					U.push_back(k);
					D.push_back(l);
				}
			}
		}
	}
	
	make_nu();
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = i ; j <= n ; j++)
		{
			for(ll k = 0 ; k <= m ; k++)
				gap[k] = gap2[k] = gap3[k] = on[k] = tlf[k] = trg[k] = lf[k] = md[k] = rg[k] = 0;
			
			for(ll k = 1 ; k <= m ; k++)
			{
				if(j - i == 0)
					gap[k] += sum(num[2][2][0][0], i, k, i, k);
				else if(j - i == 1)
					gap[k] += sum(num[2][2][0][1], i, k, i, k) + sum(num[2][2][1][0], j, k, j, k);
				else if(j - i == 2)
					gap[k] += sum(num[2][2][0][2], i, k, i, k) + sum(num[2][2][1][1], i + 1, k, i + 1, k) + sum(num[2][2][2][0], j, k, j, k);
				else if(j - i == 3)
					gap[k] += sum(num[2][2][0][2], i, k, i, k) + sum(num[2][2][1][2], i + 1, k, i + 1, k) + sum(num[2][2][2][1], i + 2, k, i + 2, k) + sum(num[2][2][2][0], j, k, j, k);
				else
					gap[k] += sum(num[2][2][0][2], i, k, i, k) + sum(num[2][2][1][2], i + 1, k, i + 1, k) + sum(num[2][2][2][2], i + 2, k, j - 2, k) + sum(num[2][2][2][1], j - 1, k, j - 1, k) + sum(num[2][2][2][0], j, k, j, k);
			}
			
			for(ll k = 1 ; k <= m ; k++)
			{
				if(j - i == 0)
				{
					gap2[k] += sum(num[0][2][0][0], i, k, i, k);
					gap2[k] += sum(num[1][2][0][0], i, k + 1, i, k + 1);
					gap3[k] += sum(num[2][1][0][0], i, k, i, k);
					gap3[k] += sum(num[2][0][0][0], i, k + 1, i, k + 1);
					on[k] += sum(num[0][0][0][0], i, k, i, k);
					tlf[k] += sum(num[0][1][0][0], i, k, i, k);
					trg[k] += sum(num[1][0][0][0], i, k, i, k);
					lf[k] += sum(num[0][2][0][0], i, k, i, k);
					rg[k] += sum(num[2][0][0][0], i, k, i, k);
					md[k] += sum(num[1][1][0][0], i, k, i, k);
				}
				
				else if(j - i == 1)
				{
					gap2[k] += sum(num[0][2][0][1], i, k, i, k) + sum(num[0][2][1][0], j, k, j, k);
					gap2[k] += sum(num[1][2][0][1], i, k + 1, i, k + 1) + sum(num[1][2][1][0], j, k + 1, j, k + 1);
					gap3[k] += sum(num[2][1][0][1], i, k, i, k) + sum(num[2][1][1][0], j, k, j, k);
					gap3[k] += sum(num[2][0][0][1], i, k + 1, i, k + 1) + sum(num[2][0][1][0], j, k + 1, j, k + 1);
					on[k] += sum(num[0][0][0][1], i, k, i, k) + sum(num[0][0][1][0], j, k, j, k);
					tlf[k] += sum(num[0][1][0][1], i, k, i, k) + sum(num[0][1][1][0], j, k, j, k);
					trg[k] += sum(num[1][0][0][1], i, k, i, k) + sum(num[1][0][1][0], j, k, j, k);
					lf[k] += sum(num[0][2][0][1], i, k, i, k) + sum(num[0][2][1][0], j, k, j, k);
					rg[k] += sum(num[2][0][0][1], i, k, i, k) + sum(num[2][0][1][0], j, k, j, k);
					md[k] += sum(num[1][1][0][1], i, k, i, k) + sum(num[1][1][1][0], j, k, j, k);
				}
				
				else if(j - i == 2)
				{
					gap2[k] += sum(num[0][2][0][2], i, k, i, k) + sum(num[0][2][1][1], i + 1, k, i + 1, k) + sum(num[0][2][2][0], j, k, j, k);
					gap2[k] += sum(num[1][2][0][2], i, k + 1, i, k + 1) + sum(num[1][2][1][1], i + 1, k + 1, i + 1, k + 1) + sum(num[1][2][2][0], j, k + 1, j, k + 1);
					gap3[k] += sum(num[2][1][0][2], i, k, i, k) + sum(num[2][1][1][1], i + 1, k, i + 1, k) + sum(num[2][1][2][0], j, k, j, k);
					gap3[k] += sum(num[2][0][0][2], i, k + 1, i, k + 1) + sum(num[2][0][1][1], i + 1, k + 1, i + 1, k + 1) + sum(num[2][0][2][0], j, k + 1, j, k + 1);
					on[k] += sum(num[0][0][0][2], i, k, i, k) + sum(num[0][0][1][1], i + 1, k, i + 1, k) + sum(num[0][0][2][0], j, k, j, k);
					tlf[k] += sum(num[0][1][0][2], i, k, i, k) + sum(num[0][1][1][1], i + 1, k, i + 1, k) + sum(num[0][1][2][0], j, k, j, k);
					trg[k] += sum(num[1][0][0][2], i, k, i, k) + sum(num[1][0][1][1], i + 1, k, i + 1, k) + sum(num[1][0][2][0], j, k, j, k);
					lf[k] += sum(num[0][2][0][2], i, k, i, k) + sum(num[0][2][1][1], i + 1, k, i + 1, k) + sum(num[0][2][2][0], j, k, j, k);
					rg[k] += sum(num[2][0][0][2], i, k, i, k) + sum(num[2][0][1][1], i + 1, k, i + 1, k) + sum(num[2][0][2][0], j, k, j, k);
					md[k] += sum(num[1][1][0][2], i, k, i, k) + sum(num[1][1][1][1], i + 1, k, i + 1, k) + sum(num[1][1][2][0], j, k, j, k);
				}
				
				else if(j - i == 3)
				{
					gap2[k] += sum(num[0][2][0][2], i, k, i, k) + sum(num[0][2][1][2], i + 1, k, i + 1, k) + sum(num[0][2][2][1], i + 2, k, i + 2, k) + sum(num[0][2][2][0], j, k, j, k);
					gap2[k] += sum(num[1][2][0][2], i, k + 1, i, k + 1) + sum(num[1][2][1][2], i + 1, k + 1, i + 1, k + 1) + sum(num[1][2][2][1], i + 2, k + 1, i + 2, k + 1) + sum(num[1][2][2][0], j, k + 1, j, k + 1);
					gap3[k] += sum(num[2][1][0][2], i, k, i, k) + sum(num[2][1][1][2], i + 1, k, i + 1, k) + sum(num[2][1][2][1], i + 2, k, i + 2, k) + sum(num[2][1][2][0], j, k, j, k);
					gap3[k] += sum(num[2][0][0][2], i, k + 1, i, k + 1) + sum(num[2][0][1][2], i + 1, k + 1, i + 1, k + 1) + sum(num[2][0][2][1], i + 2, k + 1, i + 2, k + 1) + sum(num[2][0][2][0], j, k + 1, j, k + 1);
					on[k] += sum(num[0][0][0][2], i, k, i, k) + sum(num[0][0][1][2], i + 1, k, i + 1, k) + sum(num[0][0][2][1], i + 2, k, i + 2, k) + sum(num[0][0][2][0], j, k, j, k);
					tlf[k] += sum(num[0][1][0][2], i, k, i, k) + sum(num[0][1][1][2], i + 1, k, i + 1, k) + sum(num[0][1][2][1], i + 2, k, i + 2, k) + sum(num[0][1][2][0], j, k, j, k);
					trg[k] += sum(num[1][0][0][2], i, k, i, k) + sum(num[1][0][1][2], i + 1, k, i + 1, k) + sum(num[1][0][2][1], i + 2, k, i + 2, k) + sum(num[1][0][2][0], j, k, j, k);
					lf[k] += sum(num[0][2][0][2], i, k, i, k) + sum(num[0][2][1][2], i + 1, k, i + 1, k) + sum(num[0][2][2][1], i + 2, k, i + 2, k) + sum(num[0][2][2][0], j, k, j, k);
					rg[k] += sum(num[2][0][0][2], i, k, i, k) + sum(num[2][0][1][2], i + 1, k, i + 1, k) + sum(num[2][0][2][1], i + 2, k, i + 2, k) + sum(num[2][0][2][0], j, k, j, k);
					md[k] += sum(num[1][1][0][2], i, k, i, k) + sum(num[1][1][1][2], i + 1, k, i + 1, k) + sum(num[1][1][2][1], i + 2, k, i + 2, k) + sum(num[1][1][2][0], j, k, j, k);
				}
				
				else
				{
					gap2[k] += sum(num[0][2][0][2], i, k, i, k) + sum(num[0][2][1][2], i + 1, k, i + 1, k) + sum(num[0][2][2][2], i + 2, k, j - 2, k) + sum(num[0][2][2][1], j - 1, k, j - 1, k) + sum(num[0][2][2][0], j, k, j, k);
					gap2[k] += sum(num[1][2][0][2], i, k + 1, i, k + 1) + sum(num[1][2][1][2], i + 1, k + 1, i + 1, k + 1) + sum(num[1][2][2][2], i + 2, k + 1, j - 2, k + 1) + sum(num[1][2][2][1], j - 1, k + 1, j - 1, k + 1) + sum(num[1][2][2][0], j, k + 1, j, k + 1);
					gap3[k] += sum(num[2][1][0][2], i, k, i, k) + sum(num[2][1][1][2], i + 1, k, i + 1, k) + sum(num[2][1][2][2], i + 2, k, j - 2, k) + sum(num[2][1][2][1], j - 1, k, j - 1, k) + sum(num[2][1][2][0], j, k, j, k);
					gap3[k] += sum(num[2][0][0][2], i, k + 1, i, k + 1) + sum(num[2][0][1][2], i + 1, k + 1, i + 1, k + 1) + sum(num[2][0][2][2], i + 2, k + 1, j - 2, k + 1) + sum(num[2][0][2][1], j - 1, k + 1, j - 1, k + 1) + sum(num[2][0][2][0], j, k + 1, j, k + 1);
					on[k] += sum(num[0][0][0][2], i, k, i, k) + sum(num[0][0][1][2], i + 1, k, i + 1, k) + sum(num[0][0][2][2], i + 2, k, j - 2, k) + sum(num[0][0][2][1], j - 1, k, j - 1, k) + sum(num[0][0][2][0], j, k, j, k);
					tlf[k] += sum(num[0][1][0][2], i, k, i, k) + sum(num[0][1][1][2], i + 1, k, i + 1, k) + sum(num[0][1][2][2], i + 2, k, j - 2, k) + sum(num[0][1][2][1], j - 1, k, j - 1, k) + sum(num[0][1][2][0], j, k, j, k);
					trg[k] += sum(num[1][0][0][2], i, k, i, k) + sum(num[1][0][1][2], i + 1, k, i + 1, k) + sum(num[1][0][2][2], i + 2, k, j - 2, k) + sum(num[1][0][2][1], j - 1, k, j - 1, k) + sum(num[1][0][2][0], j, k, j, k);
					lf[k] += sum(num[0][2][0][2], i, k, i, k) + sum(num[0][2][1][2], i + 1, k, i + 1, k) + sum(num[0][2][2][2], i + 2, k, j - 2, k) + sum(num[0][2][2][1], j - 1, k, j - 1, k) + sum(num[0][2][2][0], j, k, j, k);
					rg[k] += sum(num[2][0][0][2], i, k, i, k) + sum(num[2][0][1][2], i + 1, k, i + 1, k) + sum(num[2][0][2][2], i + 2, k, j - 2, k) + sum(num[2][0][2][1], j - 1, k, j - 1, k) + sum(num[2][0][2][0], j, k, j, k);
					md[k] += sum(num[1][1][0][2], i, k, i, k) + sum(num[1][1][1][2], i + 1, k, i + 1, k) + sum(num[1][1][2][2], i + 2, k, j - 2, k) + sum(num[1][1][2][1], j - 1, k, j - 1, k) + sum(num[1][1][2][0], j, k, j, k);
				}
			}
			
			for(ll k = 1 ; k <= m ; k++)
				gap[k] += gap[k - 1];
					
			for(ll k = 1 ; k <= m ; k++)
			{
				if(k + 1 <= m)
					A[k] = gap[k + 1] - gap2[k];
				
				if(1 <= k - 2)
					B[k] = gap[k - 2] + gap3[k - 1];
			}
			
			for(ll k = 1 ; k <= m ; k++)
			{
				if(k >= 4)
					cou[A[k - 3]]++;
				
				if(k >= 4 && B[k] >= 1)
					ans += cou[B[k] - 1];
			}
			
			for(ll k = 1 ; k <= m ; k++)
				cou[A[k]] = 0;
			
			for(ll k = 1 ; k <= m ; k++)
			{
				if(k <= m)
				{
					if(on[k] == 1)
						ans++;
				}
				
				if(k + 1 <= m)
				{
					if(tlf[k] + trg[k + 1] == 1)
						ans++;
				}
				
				if(k + 2 <= m)
				{
					if(lf[k] + md[k + 1] + rg[k + 2] == 1)
						ans++;
				}
			}
		}
	}
	
	cout << ans;
	return 0;
}