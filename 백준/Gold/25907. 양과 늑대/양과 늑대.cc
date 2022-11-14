#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

ll n;
ll l, r;
ll qry[100010];

ll query(ll X)
{
	if(qry[X])
		return qry[X];
	
	ll ret = 0;
	
	printf("? %lld\n", X);
	fflush(stdout);
	
	scanf("%lld", &ret);
	
	return qry[X] = ret;
}

int main(void)
{
	scanf("%lld", &n);
	
	l = 1;
	r = n;
	
	qry[1] = 1;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		ll gap = query(mid) * 2 - mid;
		
		if(gap == 0)
		{
			printf("! %lld\n", mid);
			return 0;
		}
		
		if(gap < 0)
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	return 0;
}