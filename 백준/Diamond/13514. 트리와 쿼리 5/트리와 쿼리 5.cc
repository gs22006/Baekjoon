#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n;
ll all, bll;
vector<ll> vec[100010];
vector<ll> Cenvec[100010];
ll R[100010], sub[100010];
ll Cenpa[100010];
ll m;
priority_queue<ll> pq[100010], epq[100010];
ll col[100010];
ll spa[100010][21], dep[100010];

void dfs0(ll here, ll pa)
{
	spa[here][0] = pa;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dep[i] = dep[here] + 1;
		dfs0(i, here);
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
		Cenpa[rt] = last;
		Cenvec[rt].push_back(last);
		Cenvec[last].push_back(rt);
	}
	
	R[rt] = 1;
	
	for(auto &i : vec[rt])
	{
		if(!R[i])
			f(i, rt);
	}
}

ll dist(ll X, ll Y)
{
	return dep[X] + dep[Y] - 2 * dep[LCA(X, Y)];
}

void update(ll no, ll typ, ll won)
{
	if(!no)
		return;
	
	if(!typ)
		epq[no].push(-dist(no, won));
	else
		pq[no].push(-dist(no, won));
	
	update(Cenpa[no], typ, won);
}

ll query(ll no, ll won)
{
	if(!no)
		return INF;
	
	while(!pq[no].empty() && !epq[no].empty() && pq[no].top() == epq[no].top())
	{
		pq[no].pop();
		epq[no].pop();
	}
	
	if(pq[no].empty())
		return query(Cenpa[no], won);
	
	return min(-pq[no].top() + dist(no, won), query(Cenpa[no], won));
}

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i < n ; i++)
	{
		scanf("%lld %lld", &all, &bll);
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	dfs0(1, 0);
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	f(1, 0);
	
	scanf("%lld", &m);
	
	while(m--)
	{
		scanf("%lld %lld", &all, &bll);
		
		if(all == 1)
		{
			update(bll, col[bll] ^ 1, bll);
			col[bll] ^= 1;
		}
		
		else
		{
			ll gap = query(bll, bll);
			printf("%lld\n", gap == INF ? -1 : gap);
		}
	}
	
	return 0;
}