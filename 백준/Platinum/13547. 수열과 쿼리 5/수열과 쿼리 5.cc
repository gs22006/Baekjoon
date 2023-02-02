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
ll a[100010];
ll m;
ll sq;
ll ans[100010], print[100010];
ll cou[1000010];
ll L, R;

struct QRY
{
	ll num;
	ll l, r;
	
	bool operator < (const QRY &xx) const
	{
		if(l / sq != xx.l / sq)
			return l / sq < xx.l / sq;
		
		return r < xx.r;
	}
}qry[100010];

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld", &a[i]);
	
	scanf("%lld", &m);
	
	for(ll i = 1 ; i <= m ; i++)
	{
		scanf("%lld %lld", &qry[i].l, &qry[i].r);
		qry[i].num = i;
	}
	
	for(sq = 1 ; sq * sq <= m ; sq++);
	sq--;
	
	sort(qry + 1, qry + 1 + m);
	
	L = R = 1;
	cou[a[1]]++;
	ans[0] = 1;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		ans[i] = ans[i - 1];
		
		while(L > qry[i].l)
		{
			L--;
			cou[a[L]]++;
			
			if(cou[a[L]] == 1)
				ans[i]++;
		}
		
		while(L < qry[i].l)
		{
			cou[a[L]]--;
			
			if(!cou[a[L]])
				ans[i]--;
			
			L++;
		}
		
		while(R > qry[i].r)
		{
			cou[a[R]]--;
			
			if(!cou[a[R]])
				ans[i]--;
			
			R--;
		}
		
		while(R < qry[i].r)
		{
			R++;
			cou[a[R]]++;
			
			if(cou[a[R]] == 1)
				ans[i]++;
		}
		
		print[qry[i].num] = ans[i];
	}
	
	for(ll i = 1 ; i <= m ; i++)
		printf("%lld\n", print[i]);
	
	return 0;
}