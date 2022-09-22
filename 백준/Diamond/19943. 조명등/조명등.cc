#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

ll t;
ll n;
pair<ll, ll> a[100010];
vector< pair<ll, ll> > vec;
ll chk[100010];
ll dp[100010];
ll ai[100010], bi[100010];

void pre(void)
{
	stack< pair<ll, ll> > s1, s2;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(!s1.empty() && s1.top().first <= (a[i].second - a[i].first))
		{
			chk[s1.top().second] = 1;
			s1.pop();
		}
		
		s1.push(make_pair(a[i].second - a[i].first, i));
	}
	
	for(ll i = n ; i >= 1 ; i--)
	{
		while(!s2.empty() && s2.top().first <= (a[i].first + a[i].second))
		{
			chk[s2.top().second] = 1;
			s2.pop();
		}
		
		s2.push(make_pair(a[i].first + a[i].second, i));
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!chk[i])
			vec.push_back(make_pair(a[i].first, a[i].second));
	}
}

ll sol(ll x, ll y)
{
	ll x1 = vec[x].first;
	ll y1 = vec[x].second;
	ll x2 = vec[y].first;
	ll y2 = vec[y].second;
	
	return (-x1 + y1 + x2 + y2) * (-x1 + y1 + x2 + y2);
}

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
		tree.push_back({-1, -1, xmin, xmax, {0, MAX}});
	}
	
	void update(ll no, pair<ll, ll> lin)
	{
		ll s = tree[no].xl;
		ll e = tree[no].xr;
		ll m = (s + e) / 2;
		
		pair<ll, ll> low = tree[no].line;
		pair<ll, ll> high = lin;
		
		if(getx(low, s) >= getx(high, s))
			swap(low, high);
		
		if(getx(low, e) <= getx(high, e))
			tree[no].line = low;
		
		else if(getx(low, m) <= getx(high, m))
		{
			tree[no].line = low;
			
			if(tree[no].rnode == -1)
			{
				tree[no].rnode = tree.size();
				tree.push_back({-1, -1, m + 1, e, {0, MAX}});
			}
			
			update(tree[no].rnode, high);
		}
		
		else
		{
			tree[no].line = high;
			
			if(tree[no].lnode == -1)
			{
				tree[no].lnode = tree.size();
				tree.push_back({-1, -1, s, m, {0, MAX}});
			}
			
			update(tree[no].lnode, low);
		}
	}
	
	ll query(ll no, ll x)
	{
		if(no == -1)
			return MAX;
		
		ll s = tree[no].xl;
		ll e = tree[no].xr;
		ll m = (s + e) / 2;
		
		if(x <= m)
			return min(getx(tree[no].line, x), query(tree[no].lnode, x));
		else
			return min(getx(tree[no].line, x), query(tree[no].rnode, x));
	}
};

int main(void)
{
	scanf("%lld", &t);
	
	while(t--)
	{
		scanf("%lld", &n);
		
		for(ll i = 1 ; i <= n ; i++)
		{
			scanf("%lld %lld", &a[i].first, &a[i].second);
			
			chk[i] = 0;
			dp[i] = 0;
			ai[i] = 0;
			bi[i] = 0;
		}
		
		vec.clear();
		vec.push_back(make_pair(0, 0));
		pre();
		
		Li_Chao lichao;
		lichao.init(-500000000, 5000000000);
		
		for(ll i = 1 ; i < vec.size() ; i++)
		{
			ai[i] = vec[i].first + vec[i].second;
			bi[i] = -vec[i].first + vec[i].second;
		}
		
		lichao.update(0, {2 * bi[1], bi[1] * bi[1]});
		
		for(ll i = 1 ; i < vec.size() ; i++)
		{
			dp[i] = lichao.query(0, ai[i]) + ai[i] * ai[i];
			lichao.update(0, {2 * bi[i + 1], dp[i] + bi[i + 1] * bi[i + 1]});
		}
		
		printf("%lld.", dp[vec.size() - 1] / 4LL);
		
		if(dp[vec.size() - 1] % 4 == 0)
			printf("00\n");
		else if(dp[vec.size() - 1] % 4 == 1)
			printf("25\n");
		else if(dp[vec.size() - 1] % 4 == 2)
			printf("50\n");
		else if(dp[vec.size() - 1] % 4 == 3)
			printf("75\n");
	}
	
	return 0;
}