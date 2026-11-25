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

struct gujo
{
	pll p;
	ll z, idx;
};

ll n, K;
gujo a[310];
ll idx;
vector<gujo> vec[310];
ll ans;
ll w[310][310];
ll p1[310], p2[310];
ll Z;
ll dcou[310], ccou[310];

ll ccw(pll X, pll Y, pll Z)
{
	return (X.fi * Y.se + Y.fi * Z.se + Z.fi * X.se) - (X.se * Y.fi + Y.se * Z.fi + Z.se * X.fi);
}

ll half(gujo X)
{
	if(X.p.se > a[idx].p.se || (X.p.se == a[idx].p.se && X.p.fi > a[idx].p.fi))
		return 0;
	
	return 1;
}

bool comp(gujo X, gujo Y)
{
	ll hX = half(X);
	ll hY = half(Y);
	
	if(hX != hY)
		return hX < hY;
	
	return ccw(a[idx].p, X.p, Y.p) > 0;
}

void solve(void)
{
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			if(i == j)
				continue;
			
			vec[i].push_back(a[j]);
		}
		
		idx = i;
		sort(vec[i].begin(), vec[i].end(), comp);
		
		for(ll j = 0 ; j < (ll)vec[i].size() ; j++)
			w[i][vec[i][j].idx] = j;
		
		for(ll j = 1 ; j < n ; j++)
			vec[i].push_back(vec[i][j - 1]);
		
		for(ll j = 1 ; j < n ; j++)
			vec[i].push_back(vec[i][j - 1]);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			if(i == j || a[i].z == a[j].z)
				continue;
			
			pll rngi, rngj;
			ll now = w[i][j];
			
			rngi = {-1, -1};
			rngj = {-1, -1};
			
			for(ll k = now + 1 ; k < (ll)vec[i].size() ; k++)
			{
				if(ccw(a[i].p, a[j].p, vec[i][k].p) < 0)
				{
					if(rngi.fi == -1)
						rngi.fi = k;
				}
				
				if(vec[i][k].idx == j)
				{
					rngi.se = k - 1;
					break;
				}
			}
			
			now = w[j][i];
			rngj.fi = now + 1;
			rngj.se = now + n - 2;
			
			for(ll k = now + 1 ; k < now + n - 1 ; k++)
			{
				if(ccw(a[j].p, a[i].p, vec[j][k].p) < 0)
				{
					rngj.se = k - 1;
					break;
				}
			}
			
			if(rngi.fi > rngi.se || rngj.fi > rngj.se)
				continue;
			
			//i suffix, j prefix
			for(ll k = 1 ; k <= n ; k++)
				dcou[k] = ccou[k] = 0;
			
			Z = K;
			
			Z -= (ccou[a[i].z]++ == 0);
			Z -= (ccou[a[j].z]++ == 0);
			
			for(ll k = rngi.fi ; k <= rngi.se ; k++)
				dcou[vec[i][k].idx]++;
			
			ll p = rngi.fi;
			
			for(ll k = rngj.fi ; k <= rngj.se ; k++)
			{
				dcou[vec[j][k].idx]++;
				
				if(dcou[vec[j][k].idx] == 2)
					Z -= (ccou[vec[j][k].z]++ == 0);
				
				while(p <= rngi.se && !Z)
				{
					dcou[vec[i][p].idx]--;
					
					if(dcou[vec[i][p].idx] == 1)
						Z += (ccou[vec[i][p].z]-- == 1);
					
					p++;
				}
				
				p1[k] = p;
			}
			
			for(ll k = 1 ; k <= n ; k++)
				dcou[k] = ccou[k] = 0;
			
			ccou[a[i].z]++;
			ccou[a[j].z]++;
			
			for(ll k = rngi.fi ; k <= rngi.se ; k++)
				dcou[vec[i][k].idx]++;
			
			p = rngi.fi;
			
			for(ll k = rngj.fi ; k <= rngj.se ; k++)
			{
				dcou[vec[j][k].idx]++;
				
				if(dcou[vec[j][k].idx] == 2)
				{
					ccou[vec[j][k].z]++;
					
					while(p <= rngi.se && ccou[vec[j][k].z] >= 2)
					{
						dcou[vec[i][p].idx]--;
						
						if(dcou[vec[i][p].idx] == 1)
							ccou[vec[i][p].z]--;
						
						p++;
					}
				}
				
				p2[k] = p;
			}
			
			for(ll k = rngj.fi ; k <= rngj.se ; k++)
			{
				ll W = w[i][vec[j][k].idx];
				
				while(W < rngi.fi)
					W += n - 1;
				
				if(p2[k] <= W && W < p1[k])
					ans++;
			}
		}
	}
	
	cout << ans / 3;
}

void input(void)
{
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].p.fi >> a[i].p.se >> a[i].z;
		a[i].idx = i;
	}
}

int main(void)
{
	fastio
	
	input();
	solve();
	
	return 0;
}