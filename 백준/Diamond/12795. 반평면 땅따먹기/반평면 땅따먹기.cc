#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;

struct Li_Chao
{
	ll getx(pair<ll, ll> L, ll x)
	{
		return L.first * x + L.second;
	}
	
	struct node
	{
		ll lnode, rnode;
		ll xl, xr;
		pair<ll, ll> line;
	};
	
	vector<node> tree;
	
	void init(ll xmin, ll xmax)
	{
		tree.push_back({-1, -1, xmin, xmax, {0, -1000000000000000000}});
	}
	
	void update(ll N, pair<ll, ll> lin)
	{
		ll xl = tree[N].xl;
		ll xr = tree[N].xr;
		ll xm = (xl + xr) >> 1;
		pair<ll, ll> Llow = tree[N].line;
		pair<ll, ll> Lhigh = lin;
		
		if(getx(Llow, xl) >= getx(Lhigh, xl))
			swap(Llow, Lhigh);
			
		if(getx(Llow, xr) <= getx(Lhigh, xr))
			tree[N].line = Lhigh;
		
		else if(getx(Llow, xm) <= getx(Lhigh, xm))
		{
			tree[N].line = Lhigh;
			
			if(tree[N].rnode == -1)
			{
				tree[N].rnode = tree.size();
				tree.push_back({-1, -1, xm + 1, xr, {0, -1000000000000000000}});
			}
			
			update(tree[N].rnode, Llow);
		}
		
		else
		{
			tree[N].line = Llow;
			
			if(tree[N].lnode == -1)
			{
				tree[N].lnode = tree.size();
				tree.push_back({-1, -1, xl, xm, {0, -1000000000000000000}});
			}
			
			update(tree[N].lnode, Lhigh);
		}
	}
	
	ll query(ll N, ll xq)
	{
		if(N == -1)
			return -1000000000000000000;
		
		ll xl = tree[N].xl;
		ll xr = tree[N].xr;
		ll xm = (xl + xr) >> 1;
		
		if(xq <= xm)
			return max(getx(tree[N].line, xq), query(tree[N].lnode, xq));
		else
			return max(getx(tree[N].line, xq), query(tree[N].rnode, xq));
	}
}lichao;

ll t;
ll all, bll, cll;

int main(void)
{
	lichao.init(-2000000000000, 2000000000000);
	
	scanf("%lld", &t);
	
	while(t--)
	{
		scanf("%lld", &all);
		
		if(all == 1)
		{
			scanf("%lld %lld", &bll, &cll);
			lichao.update(0, {bll, cll});
		}
		
		else if(all == 2)
		{
			scanf("%lld", &bll);
			printf("%lld\n", lichao.query(0, bll));
		}
	}
	
	return 0;
}