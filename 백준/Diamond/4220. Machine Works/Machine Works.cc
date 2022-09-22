#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef double ld;
 
struct M
{
    ll a;
    ll b;
    ll c;
    ll d;
 
    bool operator < (const M &xx) const
    {
        return a < xx.a;
    }
};
 
ll N, C, K;
M m[100010];
ll dp[100010];
ll cocu;
 
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
};
 
int main(void)
{
    while(1)
    {
    	Li_Chao lichao;
    	
    	scanf("%lld %lld %lld", &N, &C, &K);
	 	
	 	if(N + C + K == 0)
	 		break;
	 	
	 	for(ll i = 1 ; i <= N + 1 ; i++)
	 	{
	 		m[i] = {0, 0, 0, 0};
	 		dp[i] = 0;
		}
	 	
	    for(ll i = 1 ; i <= N ; i++)
	        scanf("%lld %lld %lld %lld", &m[i].a, &m[i].b, &m[i].c, &m[i].d);
	 
	    sort(m + 1, m + 1 + N);
	 
	    m[N + 1].a = K + 1;
	    m[N + 1].b = 0;
	    m[N + 1].c = 0;
	    m[N + 1].d = 0;
	 
	    lichao.init(-1000000000, 1000000000);
	 
	    for(ll i = 1 ; i <= N + 1 ; i++)
	    {
	        ll gap = max(lichao.query(0, m[i].a), C);
	 
	        if(gap < m[i].b)
	            continue;
	 
	        gap -= m[i].b;
	        dp[i] = gap;
	 
	        lichao.update(0, {m[i].d, dp[i] + m[i].c - m[i].a * m[i].d - m[i].d});
	    }
	 
	    printf("Case %lld: %lld\n", ++cocu, dp[N + 1]);
	}
	
	return 0;
}