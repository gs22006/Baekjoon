#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
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
ll a[100010];
ll ss = 1000000007;
ll ans = 1;

struct NCK
{
	ll fac[4000010] = {0, }, inv[4000010] = {0, };
	
	ll power(ll xx, ll yy)
	{
	    ll ret = 1;
	     
	    while(yy > 0)
	    {
	        if(yy % 2)
	            ret = (ret * xx) % ss;
	        xx = (xx * xx) % ss;
	        yy /= 2;
	    }
	     
	    return ret;
	}
	 
	ll C(ll xx, ll yy)
	{
		if(xx < yy)
			return 0;
		
	    if(xx == yy || !yy)
	        return 1;
	    
	    long long r = (fac[xx] * inv[xx - yy]) % ss;
	    r = (r * inv[yy]) % ss;
	    return r;
	}
	
	void init(void)
	{
		fac[0] = 1;
	    fac[1] = 1;
	     
	    for(ll i = 2 ; i <= 4000000 ; i++)
	        fac[i] = (fac[i - 1] * i) % ss;
	     
	    inv[4000000] = power(fac[4000000], ss - 2);
	    
	    for(ll i = 3999999 ; i >= 0 ; i--)
	        inv[i] = (inv[i + 1] * (i + 1)) % ss;
	}
}nck;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i] & 1)
		{
			cout << 0;
			return 0;
		}
		
		a[i] >>= 1;
	}
	
	nck.init();
	
	for(ll i = 2 ; i <= n ; i++)
	{
		if(a[i - 1] <= a[i])
			ans = ans * nck.C(a[i] - 1, a[i - 1] - 1) % ss;
		else
			ans = ans * nck.C(a[i - 1], a[i]) % ss;
	}
	
	ans = (ans + ss) % ss;
	
	cout << ans;
	return 0;
}