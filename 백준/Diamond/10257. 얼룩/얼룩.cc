#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

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

ll t;
ll n, m;
ll C;
ll all, bll;
ll a[20][1010];
ll gapa[1010];
ll dp[1010][30][30];
vector< vector<ll> > vec;
vector<ll> vvec;
ll chk[20], chch[20];

void f(ll here)
{
	if(here > n)
	{
		ll ff = 0;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(i > 1 && chk[i] && chk[i - 1])
				ff = 1;
			
			if(i > 2 && chk[i] && chk[i - 2])
				ff = 1;
			
			if(i >= n - 1 && chk[i])
				ff = 1;
		}
		
		if(!ff)
		{
			vector<ll> vv;
			
			for(ll i = 1 ; i <= n ; i++)
			{
				if(chk[i])
					vv.push_back(i);
			}
			
			vec.push_back(vv);
		}
		
		return;
	}
	
	f(here + 1);
	chk[here] = 1;
	f(here + 1);
	chk[here] = 0;
}

ll cover(ll I, ll X, ll Y, ll Z)
{
	ll hh = (vvec[X] | vvec[Y] | vvec[Z]);
	
	if((hh | gapa[I]) == hh)
		return 1;
	
	return 0;
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		cin >> C;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= m ; j++)
				a[i][j] = 0;
		}
		
		for(ll i = 1 ; i <= C ; i++)
		{
			cin >> all >> bll;
			a[all][bll] = 1;
		}
		
		vec.clear();
		vvec.clear();
		
		f(1);
		
		vector<ll> tmp;
		
		for(ll i = 1 ; i <= n ; i += 3)
			tmp.push_back(i);
		
		vec.push_back(tmp);
		
		ll siz = (ll)vec.size();
		
		for(ll i = 0 ; i < siz ; i++)
		{
			ll gap = 0;
			
			for(auto &j : vec[i])
			{
				gap |= (1LL << j);
				gap |= (1LL << (j + 1));
				gap |= (1LL << (j + 2));
			}
			
			vvec.push_back(gap);
		}
		
		for(ll i = 0 ; i <= m ; i++)
		{
			for(ll j = 0 ; j < siz ; j++)
			{
				for(ll k = 0 ; k < siz ; k++)
					dp[i][j][k] = INF;
			}
		}
		
		dp[0][0][0] = 0;
		
		for(ll i = 1 ; i <= m ; i++)
		{
			gapa[i] = 0;
			
			for(ll j = 1 ; j <= n ; j++)
			{
				if(a[j][i])
					gapa[i] |= (1LL << j);
			}
			
			for(ll j = 0 ; j < siz ; j++)
			{
				for(ll k = 0 ; k < siz ; k++)
				{
					for(ll l = 0 ; l < siz ; l++)
					{
						if(cover(i, j, k, l))
							dp[i][j][k] = min(dp[i][j][k], dp[i - 1][l][j] + (ll)vec[k].size());
					}
				}
			}
		}
		
		ll ans = INF;
		
		for(ll i = 0 ; i < siz ; i++)
		{
			for(ll j = 0 ; j < siz ; j++)
				ans = min(ans, dp[m][i][j]);
		}
		
		cout << ans en;
	}
	
	return 0;
}