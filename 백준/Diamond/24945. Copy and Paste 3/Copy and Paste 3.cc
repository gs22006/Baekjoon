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
char s[2510];
ll A, B, C;
ll dp[2510][2510];
ll je[2510], je2[2510];
ll inv[2510], inv2[2510];
ll num[2510][2510];
ll nu[2510];
ll nu2[2510];
ll hs = 79, hs2 = 31;
ll ss = 1000000007;
ll L[6300010], R[6300010];
ll GO[6300010];
vector< pair<pll, ll> > sad;
ll cc;
ll gaet[2510];
vector<ll> vv[2510];

ll sqrmtp(ll X, ll Y)
{
	ll ret = 1;
	
	while(Y)
	{
		if(Y & 1)
			ret = ret * X % ss;
		
		X = X * X % ss;
		Y >>= 1;
	}
	
	return ret;
}

ll f(ll L, ll R)
{
	ll ret = (nu[R] - nu[L - 1]) * inv[L] % ss;
	return (ret + ss) % ss;
}

ll f2(ll L, ll R)
{
	ll ret = (nu2[R] - nu2[L - 1]) * inv2[L] % ss;
	return (ret + ss) % ss;
}

ll comp(ll L1, ll R1, ll L2, ll R2)
{
	return (f(L1, R1) == f(L2, R2) && f2(L1, R1) == f2(L2, R2));
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; ++i)
		cin >> s[i];
	
	cin >> A;
	cin >> B;
	cin >> C;
	
	je[0] = 1;
	je2[0] = 1;
	
	for(ll i = 1 ; i <= n ; ++i)
	{
		je[i] = je[i - 1] * hs % ss;
		je2[i] = je2[i - 1] * hs2 % ss;
	}
	
	for(ll i = 0 ; i <= n ; ++i)
	{
		inv[i] = sqrmtp(je[i], ss - 2);
		inv2[i] = sqrmtp(je2[i], ss - 2);
	}
	
	for(ll i = 1 ; i <= n ; ++i)
	{
		nu[i] = (nu[i - 1] + je[i] * (s[i] - 'a' + 1) % ss) % ss;
		nu2[i] = (nu2[i - 1] + je2[i] * (s[i] - 'a' + 1) % ss) % ss;
	}
	
	for(ll i = 1 ; i <= n ; ++i)
	{
		for(ll j = i ; j <= n ; ++j)
		{
			num[i][j] = ++cc;
			sad.push_back({{f(i, j), f2(i, j)}, cc});
			L[cc] = i, R[cc] = j;
		}
	}
	
	vector<ll> tmp;
	
	sort(sad.begin(), sad.end());
	
	tmp.push_back(sad[0].se);
	
	for(ll i = 1 ; i <= (ll)sad.size() ; ++i)
	{
		if(i == (ll)sad.size() || sad[i].fi != sad[i - 1].fi)
		{
			ll siz = (ll)tmp.size();
			
			for(ll j = 1 ; j < siz ; ++j)
			{
				ll l = 0, r = j - 1;
				
				while(l <= r)
				{
					ll mid = (l + r) >> 1;
					
					if(R[tmp[mid]] < L[tmp[j]])
						l = mid + 1;
					else
						r = mid - 1;
				}
				
				if(r == -1)
					continue;
				
				GO[tmp[j]] = tmp[r];
			}
			
			tmp.clear();
			
			if(i < (ll)sad.size())
				tmp.push_back(sad[i].se);
		}
		
		else
			tmp.push_back(sad[i].se);
	}
	
	for(ll i = 1 ; i <= n ; ++i)
	{
		for(ll j = 1 ; j <= i ; ++j)
		{
			vv[j].clear();
			gaet[j] = 0;
		}
		
		ll minn = INF;
		
		for(ll j = i ; j >= 1 ; --j)
		{
			ll X = num[j][i];
			
			while(X)
			{
				vv[L[X]].push_back(j);
				X = GO[X];
			}
		}
		
		for(ll j = i ; j >= 1 ; --j)
		{
			dp[j][i] = (i - j + 1) * A;
			dp[j][i] = min(dp[j][i], dp[j][i - 1] + A);
			
			for(auto &k : vv[j])
			{
				gaet[k]++;
				minn = min(minn, B + dp[k][i] + gaet[k] * (C - A * (i - k + 1)));
			}
			
			dp[j][i] = min(dp[j][i], minn + A * (i - j + 1));
		}
	}
	
	cout << dp[1][n];
	return 0;
}