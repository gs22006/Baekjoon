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

ll n, m;
ll ss = 1000000007;
ll ans;
ll cou[2010];
ll dp[2010][2010];

struct NCK
{
	ll fac[4010] = {0, }, inv[4010] = {0, };
	
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
	     
	    for(ll i = 2 ; i <= 4000 ; i++)
	        fac[i] = (fac[i - 1] * i) % ss;
	     
	    inv[4000] = power(fac[4000], ss - 2);
	    
	    for(ll i = 3999 ; i >= 0 ; i--)
	        inv[i] = (inv[i + 1] * (i + 1)) % ss;
	}
}nck;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	nck.init();
	
	ans = nck.fac[n * 2];
	
	for(ll i = 1 ; i <= n * 2 ; i++)
	{
		ll gap = i % m;
		
		if(gap == 0)
			gap = m;
		
		cou[gap]++;
	}
	
	for(ll i = 0 ; i <= m ; i++)
		dp[0][i] = 1;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			ll X = cou[j];
			
			for(ll k = 1 ; k * 2 <= X && k <= i ; k++)
				dp[i][j] = (dp[i][j] + dp[i - k][j - 1] * nck.C(X, k * 2) % ss * nck.fac[k * 2] % ss * nck.C(i, k) % ss) % ss;
		}
		
		for(ll j = 1 ; j <= m ; j++)
			dp[i][j] = (dp[i][j] + dp[i][j - 1]) % ss;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll gap = dp[i][m] * nck.C(n, i) % ss * nck.fac[n * 2 - i * 2] % ss;
		
		if(i & 1)
			ans = (ans - gap) % ss;
		else
			ans = (ans + gap) % ss;
	}
	
	ans = (ans + ss) % ss;
	
	cout << ans;
	return 0;
}