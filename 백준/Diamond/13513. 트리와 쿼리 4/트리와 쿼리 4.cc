#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n, m;
ll all, bll, cll;
vector<ll> vec[100010], cvec[100010], nvec[100010];
ll sub[100010], R[100010], spa[100010][21];
ll dep[100010], dis[100010];
vector<ll> Cenvec[100010];
ll Cenpa[100010], panum[100010];
vector<ll> his;
ll col[100010];
ll cc;
ll RT;

struct PQPQ
{
	priority_queue<ll> PQ, EPQ;
	
	void ERASE(void)
	{
		while(!PQ.empty() && !EPQ.empty() && PQ.top() == EPQ.top())
			PQ.pop(), EPQ.pop();
	}
	
	void PUSH(ll X)
	{
		PQ.push(X);
		ERASE();
	}
	
	void DEL(ll X)
	{
		EPQ.push(X);
		ERASE();
	}
	
	ll TOP(void)
	{
		ERASE();
		return PQ.top();
	}
	
	ll EMPTY(void)
	{
		return PQ.empty();
	}
}pq1[100010], pq2[100010], pq3[100010], pq4, pq5;

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
	
	if(!RT)
		RT = rt;
	
	if(last)
	{
		Cenpa[rt] = last;
		Cenvec[rt].push_back(last);
		Cenvec[last].push_back(rt);
		nvec[rt].push_back(++cc);
		nvec[last].push_back(cc);
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
	spa[here][0] = pa;
	dep[here] = dep[pa] + 1;
	
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

void help(ll no)
{
	if(!no)
		return;
	
	his.push_back(no);
	help(Cenpa[no]);
}

void update(ll no, ll won, ll typ, ll edg, vector<ll> IN, vector<ll> OUT)
{
	if(!no)
		return;
	
	vector<ll> tree_and_query;
	
	for(ll i = 0 ; i < (ll)Cenvec[no].size() ; i++)
	{
		if(Cenvec[no][i] == Cenpa[no])
			continue;
		
		if(!pq2[nvec[no][i]].EMPTY())
			tree_and_query.push_back(pq2[nvec[no][i]].TOP());
	}
	
	if((ll)tree_and_query.size() >= 2)
	{
		sort(tree_and_query.begin(), tree_and_query.end());
		reverse(tree_and_query.begin(), tree_and_query.end());
		pq3[no].DEL(tree_and_query[0] + tree_and_query[1]);
	}
	
	if(edg != -1)
	{
		for(auto &i : IN)
			pq2[edg].PUSH(i);
		
		for(auto &i : OUT)
			pq2[edg].DEL(i);
	}
	
	IN.clear();
	OUT.clear();
	tree_and_query.clear();
	
	for(ll i = 0 ; i < (ll)Cenvec[no].size() ; i++)
	{
		if(Cenvec[no][i] == Cenpa[no])
			continue;
		
		if(!pq2[nvec[no][i]].EMPTY())
			tree_and_query.push_back(pq2[nvec[no][i]].TOP());
	}
	
	if((ll)tree_and_query.size() >= 2)
	{
		sort(tree_and_query.begin(), tree_and_query.end());
		reverse(tree_and_query.begin(), tree_and_query.end());
		pq3[no].PUSH(tree_and_query[0] + tree_and_query[1]);
	}
	
	if(!typ)
	{
		pq1[no].DEL(dist(no, won));
		OUT.push_back(dist(won, Cenpa[no]));
	}
	
	else
	{
		pq1[no].PUSH(dist(no, won));
		IN.push_back(dist(won, Cenpa[no]));
	}
	
	update(Cenpa[no], won, typ, panum[no], IN, OUT);
}

ll query(void)
{
	ll ret = -1;
	
	if(!pq5.EMPTY())
		ret = max(ret, pq5.TOP());
	
	if(!pq4.EMPTY())
		ret = max(ret, pq4.TOP());
	
	return ret;
}

int main(void)
{
	scanf("%d", &n);
	
	for(ll i = 1 ; i < n ; i++)
	{
		scanf("%d %d %d", &all, &bll, &cll);
		
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
	
	for(ll i = 1 ; i <= n ; i++)
	{
		his.clear();
		help(i);
		
		for(auto &j : his)
		{
			if(col[j] && !pq1[j].EMPTY())
				pq4.DEL(pq1[j].TOP());
			
			if(!pq3[j].EMPTY())
				pq5.DEL(pq3[j].TOP());
		}
		
		col[i] ^= 1;
		update(i, i, col[i], -1, {}, {});
		
		for(auto &j : his)
		{
			if(col[j] && !pq1[j].EMPTY())
				pq4.PUSH(pq1[j].TOP());
			
			if(!pq3[j].EMPTY())
				pq5.PUSH(pq3[j].TOP());
		}
	}
	
	scanf("%d", &m);
	
	while(m--)
	{
		scanf("%d", &all);
		
		if(all == 1)
		{
			scanf("%d", &bll);
			
			his.clear();
			help(bll);
			
			for(auto &j : his)
			{
				if(col[j] && !pq1[j].EMPTY())
					pq4.DEL(pq1[j].TOP());
				
				if(!pq3[j].EMPTY())
					pq5.DEL(pq3[j].TOP());
			}
			
			col[bll] ^= 1;
			update(bll, bll, col[bll], -1, {}, {});
			
			for(auto &j : his)
			{
				if(col[j] && !pq1[j].EMPTY())
					pq4.PUSH(pq1[j].TOP());
				
				if(!pq3[j].EMPTY())
					pq5.PUSH(pq3[j].TOP());
			}
		}
		
		else
			printf("%d\n", query());
	}
	
	return 0;
}