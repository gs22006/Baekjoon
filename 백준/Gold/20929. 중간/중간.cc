#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n;
ll qry[1000010][2];
ll l, r;

ll query1(ll X)
{
	if(X <= 0 || X > n)
		return MIN;
	
	ll ret = 0;
	
	if(qry[X][0])
		return qry[X][0];
	
	printf("? A %lld\n", X);
	fflush(stdout);
	
	scanf("%lld", &ret);
	
	return qry[X][0] = ret;
}

ll query2(ll X)
{
	if(X <= 0 || X > n)
		return MIN;
	
	ll ret = 0;
	
	if(qry[X][1])
		return qry[X][1];
	
	printf("? B %lld\n", X);
	fflush(stdout);
	
	scanf("%lld", &ret);
	
	return qry[X][1] = ret;
}

int main(void)
{
	scanf("%lld", &n);
	
	l = 1;
	r = n;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		ll gap1 = query1(mid);
		ll gap2 = query2(n - mid + 1);
		
		if(gap1 <= gap2)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	ll ans = max(query1(r), query2(n - l + 1));
	
	printf("! %lld\n", ans);
	fflush(stdout);
	
	return 0;
}