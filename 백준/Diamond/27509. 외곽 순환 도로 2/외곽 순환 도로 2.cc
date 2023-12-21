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
pll L[500010], R[500010];
ll spe[500010];
ll idx[500010];
ll deg[500010];
ll cost[500010];
ll Llf[500010], Rlf[500010];
ll dp[500010][2][2][2];

void dfs(ll here, ll pa)
{
	Llf[here] = INF;
	Rlf[here] = -INF;
	
	if(deg[here] == 1)
	{
		Llf[here] = here;
		Rlf[here] = here;
		dp[here][0][0][0] = 0;
		dp[here][1][1][1] = 0;
		
		return;
	}
	
	if(L[here].fi)
	{
		dfs(L[here].fi, here);
		Llf[here] = min(Llf[here], Llf[L[here].fi]);
		Rlf[here] = max(Rlf[here], Rlf[L[here].fi]);
	}
	
	if(R[here].fi)
	{
		dfs(R[here].fi, here);
		Llf[here] = min(Llf[here], Llf[R[here].fi]);
		Rlf[here] = max(Rlf[here], Rlf[R[here].fi]);
	}
	
	if(!L[here].fi && R[here].fi)
		assert(0);
	
	if(!R[here].fi)
	{
		for(ll i = 0 ; i < 2 ; i++)
		{
			for(ll j = 0 ; j < 2 ; j++)
			{
				for(ll k = 0 ; k < 2 ; k++)
				{
					for(ll l = 0 ; l < 2 ; l++)
					{
						if(spe[L[here].fi] && i != j)
							continue;
						
						if(i != j)
							dp[here][i][k][l] = min(dp[here][i][k][l], dp[L[here].fi][j][k][l]);
						else
							dp[here][i][k][l] = min(dp[here][i][k][l], dp[L[here].fi][j][k][l] + L[here].se);
					}
				}
			}
		}
	}
	
	else
	{
		for(ll i = 0 ; i < 2 ; i++)
		{
			for(ll c1 = 0 ; c1 < 2 ; c1++)
			{
				if(spe[L[here].fi] && i != c1)
					continue;
				
				for(ll c2 = 0 ; c2 < 2 ; c2++)
				{
					if(spe[R[here].fi] && i != c2)
						continue;
					
					for(ll L1 = 0 ; L1 < 2 ; L1++)
					{
						for(ll R1 = 0 ; R1 < 2 ; R1++)
						{
							for(ll L2 = 0 ; L2 < 2 ; L2++)
							{
								for(ll R2 = 0 ; R2 < 2 ; R2++)
								{
									ll gap = dp[L[here].fi][c1][L1][R1] + dp[R[here].fi][c2][L2][R2];
									
									if(i == c1)
										gap += L[here].se;
									
									if(i == c2)
										gap += R[here].se;
									
									if(R1 == L2)
										gap += cost[idx[Rlf[L[here].fi]]];
									
									dp[here][i][L1][R2] = min(dp[here][i][L1][R2], gap);
								}
							}
						}
					}
				}
			}
		}
	}
}

ll place_police(vector<int> P, vector<ll> C, vector<ll> W)
{
	n = (ll)P.size() + 1;
	
	ll cc = n;
	
	for(ll i = 0 ; i < n - 1 ; i++)
	{
		ll V1 = i + 2;
		ll V2 = P[i] + 1;
		
		deg[V1]++;
		deg[V2]++;
		
		if(L[V2].fi == 0)
			L[V2] = {V1, C[i]};
		else if(R[V2].fi == 0)
			R[V2] = {V1, C[i]};
		
		else
		{
			cc++;
			L[cc] = R[V2];
			R[cc] = {V1, C[i]};
			R[V2] = {cc, 0};
			spe[cc] = 1;
		}
	}
	
	vector<ll> lf;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(deg[i] == 1)
			lf.push_back(i);
	}
	
	sort(lf.begin(), lf.end());
	
	if((ll)lf.size() != (ll)W.size())
		assert(0);
	
	for(ll i = 0 ; i < (ll)lf.size() ; i++)
	{
		idx[lf[i]] = i + 1;
		cost[i + 1] = W[i];
	}
	
	n = cc;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 0 ; j < 2 ; j++)
		{
			for(ll k = 0 ; k < 2 ; k++)
			{
				for(ll l = 0 ; l < 2 ; l++)
					dp[i][j][k][l] = INF;
			}
		}
	}
	
	dfs(1, 0);
	
	ll ans = INF;
	
	for(ll i = 0 ; i < 2 ; i++)
	{
		ans = min(ans, dp[1][i][0][1]);
		ans = min(ans, dp[1][i][1][0]);
		ans = min(ans, dp[1][i][0][0] + W.back());
		ans = min(ans, dp[1][i][1][1] + W.back());
	}
	
	return ans;
}