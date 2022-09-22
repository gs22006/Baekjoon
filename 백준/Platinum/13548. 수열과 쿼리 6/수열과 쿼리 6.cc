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
ll cou[100010], ccou[100010];
ll L, R;
ll maxx;

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
	ccou[1]++;
	maxx = 1;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		while(L > qry[i].l)
		{
			L--;
			ccou[cou[a[L]]]--;
			
			if(maxx == cou[a[L]])
				maxx++;
			
			cou[a[L]]++;
			ccou[cou[a[L]]]++;
		}
		
		while(L < qry[i].l)
		{
			ccou[cou[a[L]]]--;
			
			if(maxx == cou[a[L]] && !ccou[cou[a[L]]])
				maxx--;
			
			cou[a[L]]--;
			ccou[cou[a[L]]]++;
			L++;
		}
		
		while(R > qry[i].r)
		{
			ccou[cou[a[R]]]--;
			
			if(maxx == cou[a[R]] && !ccou[cou[a[R]]])
				maxx--;
			
			cou[a[R]]--;
			ccou[cou[a[R]]]++;
			R--;
		}
		
		while(R < qry[i].r)
		{
			R++;
			ccou[cou[a[R]]]--;
			
			if(maxx == cou[a[R]])
				maxx++;
			
			cou[a[R]]++;
			ccou[cou[a[R]]]++;
		}
		
		print[qry[i].num] = maxx;
	}
	
	for(ll i = 1 ; i <= m ; i++)
		printf("%lld\n", print[i]);
	
	return 0;
}