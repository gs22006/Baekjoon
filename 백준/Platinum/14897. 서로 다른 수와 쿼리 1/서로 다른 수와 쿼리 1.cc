# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>

using namespace std;
typedef int ll;
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

ll n, q;
ll a[1000010];
vector<ll> vec;
ll cou[1000010];
ll sq;
ll l, r;
ll ans;
ll ans2[1000010];

struct Query
{
	ll L, R;
	ll num;
	
	bool operator < (const Query &xx) const
	{
		if(L / sq == xx.L / sq)
			return R < xx.R;
		
		return L / sq < xx.L / sq;
	}
};

Query Q[1000010];

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		vec.push_back(a[i]);
	}
	
	compress(vec);
	
	for(ll i = 1 ; i <= n ; i++)
		a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
	
	cin >> q;
	
	sq = max(1, (ll)(n / sqrt(q)));
	
	for(ll i = 1 ; i <= q ; i++)
	{
		cin >> Q[i].L >> Q[i].R;
		Q[i].num = i;
	}
	
	sort(Q + 1, Q + 1 + q);
	
	l = r = 1;
	cou[a[1]]++;
	ans = 1;
	
	for(ll i = 1 ; i <= q ; i++)
	{
		while(l < Q[i].L)
		{
			cou[a[l]]--;
			
			if(!cou[a[l]])
				ans--;
			
			l++;
		}
		
		while(l > Q[i].L)
		{
			l--;
			cou[a[l]]++;
			
			if(cou[a[l]] == 1)
				ans++;
		}
		
		while(r > Q[i].R)
		{
			cou[a[r]]--;
			
			if(!cou[a[r]])
				ans--;
			
			r--;
		}
		
		while(r < Q[i].R)
		{
			r++;
			cou[a[r]]++;
			
			if(cou[a[r]] == 1)
				ans++;
		}
		
		ans2[Q[i].num] = ans;
	}
	
	for(ll i = 1 ; i <= q ; i++)
		cout << ans2[i] en;
	
	return 0;
}