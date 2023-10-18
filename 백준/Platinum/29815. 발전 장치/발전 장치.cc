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

ll A, B, n;
ll t;
ll R, C;
ll ss = 1000000007;

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
		if(xx < yy || yy < 0)
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
	
	cin >> A >> B >> n;
	cin >> t;
	
	nck.init();
	
	while(t--)
	{
		cin >> R >> C;
		
		R = n + 1 - R;
		
		if((R + 1) / 2 < C)
			C = R + 1 - C;
		
		ll ans = 0;
		
		ans = (ans + nck.C(R - 1, C - 1) * A % ss) % ss;
		ans = (ans + nck.C(R - 1, C - 1) * n % ss * B % ss) % ss;
		ans = (ans - (nck.C(R, C) + nck.C(R - 1, C - 2)) % ss * B % ss) % ss;
		ans = (ans + ss) % ss;
		
		cout << ans en;
	}
	
	return 0;
}