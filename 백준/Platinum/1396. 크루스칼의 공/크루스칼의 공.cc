#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

struct edg
{
	ll al, bl, cl;
	
	bool operator < (const edg &xx) const
	{
		return cl < xx.cl;
	}
};

ll n, m;
vector<edg> vec;
ll all, bll, cll;
ll q;
pair<ll, ll> Q[100010];
ll l[100010], r[100010], mid[100010];
ll pa[100010], siz[100010];
pair<ll, ll> ans[100010];

ll ffind(ll x)
{
	if(x == pa[x])
		return x;
	
	return pa[x] = ffind(pa[x]);
}

void uunion(ll x, ll y)
{
	x = ffind(x);
	y = ffind(y);
	
	if(x == y)
		return;
	
	if(siz[x] < siz[y])
	{
		pa[x] = y;
		siz[y] += siz[x];
		siz[x] = 0;
	}
	
	else
	{
		pa[y] = x;
		siz[x] += siz[y];
		siz[y] = 0;
	}
}

int main(void)
{
	scanf("%lld %lld", &n, &m);
	
	for(ll i = 0 ; i < m ; i++)
	{
		scanf("%lld %lld %lld", &all, &bll, &cll);
		
		vec.push_back({all, bll, cll});
	}
	
	sort(vec.begin(), vec.end());
	
	scanf("%lld", &q);
	
	for(ll i = 1 ; i <= q ; i++)
	{
		scanf("%lld %lld", &Q[i].first, &Q[i].second);
		
		l[i] = 0;
		r[i] = 1000010;
	}
	
	for(ll cou = 0 ; cou < 100 ; cou++)
	{
		for(ll i = 1 ; i <= q ; i++)
			mid[i] = (l[i] + r[i]) / 2;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			pa[i] = i;
			siz[i] = 1;
		}
		
		vector< pair<ll, ll> > que;
		
		for(ll i = 1 ; i <= q ; i++)
		{
			if(l[i] <= r[i])
				que.push_back(make_pair(mid[i], i));
		}
		
		sort(que.begin(), que.end());
		
		ll p = 0;
		
		for(ll i = 0 ; i < que.size() ; i++)
		{
			while(p < vec.size() && vec[p].cl <= que[i].first)
			{
				uunion(vec[p].al, vec[p].bl);
				p++;
			}
			
			if(ffind(Q[que[i].second].first) == ffind(Q[que[i].second].second))
				r[que[i].second] = mid[que[i].second] - 1;
			else
				l[que[i].second] = mid[que[i].second] + 1;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		pa[i] = i;
		siz[i] = 1;
	}
	
	ll p = 0;
	
	vector< pair<ll, ll> > qqq;
	
	for(ll i = 1 ; i <= q ; i++)
		qqq.push_back(make_pair(l[i], i));
	
	sort(qqq.begin(), qqq.end());
	
	for(ll i = 0 ; i < qqq.size() ; i++)
	{
		while(p < vec.size() && vec[p].cl <= qqq[i].first)
		{
			uunion(vec[p].al, vec[p].bl);
			p++;
		}
		
		ans[qqq[i].second] = make_pair(qqq[i].first, siz[ffind(Q[qqq[i].second].first)]);
	}
	
	for(ll i = 1 ; i <= q ; i++)
	{
		if(ans[i].first == 1000011)
			printf("-1\n");
		else
			printf("%lld %lld\n", ans[i].first, ans[i].second);
	}
	
	return 0;
}