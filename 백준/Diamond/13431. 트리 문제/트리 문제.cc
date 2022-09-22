#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n, q;
ll all, bll, cll;
vector<ll> vec[100010], cvec[100010], Cenvec[100010], nvec[100010];
ll cc;
ll Cenpa[100010], panum[100010];
ll R[100010], sub[100010];
ll dis[100010], spa[100010][21], dep[100010];
ll col[100010], gaet[100010], sum[100010];

void dfs(ll here, ll pa)
{
	sub[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(i == pa || R[i])
			continue;
		
		dfs(i, here);
		sub[here] += sub[i];
	}
}

ll get_centroid(ll here, ll pa, ll TS)
{
	for(auto &i : vec[here])
	{
		if(i == pa || R[i])
			continue;
		
		if(sub[i] * 2 > TS)
			return get_centroid(i, here, TS);
	}
	
	return here;
}

void f(ll here, ll last)
{
	dfs(here, 0);
	
	ll rt = get_centroid(here, 0, sub[here]);
	
	if(last)
	{
		Cenvec[rt].push_back(last);
		Cenvec[last].push_back(rt);
		nvec[rt].push_back(++cc);
		nvec[last].push_back(cc);
		Cenpa[rt] = last;
		panum[rt] = cc;
	}
	
	R[rt] = 1;
	
	for(auto &i : vec[rt])
	{
		if(!R[i])
			f(i, rt);
	}
}

void dfs0(ll here, ll pa)
{
	dep[here] = dep[pa] + 1;
	spa[here][0] = pa;
	
	for(ll i = 0 ; i < (ll)vec[here].size() ; i++)
	{
		if(vec[here][i] == pa)
			continue;
		
		dis[vec[here][i]] = dis[here] + cvec[here][i];
		dfs0(vec[here][i], here);
	}
}

ll LCA(ll X, ll Y)
{
	if(dep[X] < dep[Y])
		swap(X, Y);
	
	ll cha = dep[X] - dep[Y];
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if((1LL << i) <= cha)
		{
			cha -= (1LL << i);
			X = spa[X][i];
		}
	}
	
	if(X == Y)
		return X;
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if(spa[X][i] != spa[Y][i])
		{
			X = spa[X][i];
			Y = spa[Y][i];
		}
	}
	
	return spa[X][0];
}

ll dist(ll X, ll Y)
{
	return dis[X] + dis[Y] - 2 * dis[LCA(X, Y)];
}

void update(ll no, ll won)
{
	if(!no)
		return;
	
	gaet[panum[no]]++;
	sum[panum[no]] += dist(Cenpa[no], won);
	update(Cenpa[no], won);
}

ll query(ll no, ll won, ll last)
{
	ll ret = 0;
	
	if(!no)
		return 0;
	
	if(col[no])
		ret += dist(no, won);
	
	for(ll i = 0 ; i < (ll)Cenvec[no].size() ; i++)
	{
		if(nvec[no][i] == last || Cenvec[no][i] == Cenpa[no])
			continue;
		
		ret += dist(no, won) * gaet[nvec[no][i]];
		ret += sum[nvec[no][i]];
	}
	
	return query(Cenpa[no], won, panum[no]) + ret;
}

int main(void)
{
	scanf("%lld %lld", &n, &q);
	
	for(ll i = 1 ; i < n ; i++)
	{
		scanf("%lld %lld %lld", &all, &bll, &cll);
		
		all++, bll++;
		vec[all].push_back(bll);
		vec[bll].push_back(all);
		cvec[all].push_back(cll);
		cvec[bll].push_back(cll);
	}
	
	f(1, 0);
	dfs0(1, 0);
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	while(q--)
	{
		scanf("%lld %lld", &all, &bll);
		
		bll++;
		
		if(all == 1)
		{
			if(!col[bll])
			{
				col[bll] = 1;
				update(bll, bll);
			}
		}
		
		else
			printf("%lld\n", query(bll, bll, 0));
	}
	
	return 0;
}