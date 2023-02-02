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

ll n, t;
ll a[100010];
ll sq;

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

Query Q[100010];
ll l, r;
ll cou[1000010];
ll ans;
ll ans2[100010];

int main(void)
{
	fastio
	
	cin >> n >> t;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	sq = sqrt(n);
	
	for(ll i = 1 ; i <= t ; i++)
	{
		cin >> Q[i].L >> Q[i].R;
		Q[i].num = i;
	}
	
	sort(Q + 1, Q + 1 + t);
	
	l = 1;
	r = 1;
	cou[a[1]] = 1;
	ans = a[1];
	
	for(ll i = 1 ; i <= t ; i++)
	{
		while(l < Q[i].L)
		{
			ans -= a[l] * cou[a[l]] * cou[a[l]];
			cou[a[l]]--;
			ans += a[l] * cou[a[l]] * cou[a[l]];
			l++;
		}
		
		while(Q[i].L < l)
		{
			l--;
			ans -= a[l] * cou[a[l]] * cou[a[l]];
			cou[a[l]]++;
			ans += a[l] * cou[a[l]] * cou[a[l]];
		}
		
		while(Q[i].R < r)
		{
			ans -= a[r] * cou[a[r]] * cou[a[r]];
			cou[a[r]]--;
			ans += a[r] * cou[a[r]] * cou[a[r]];
			r--;
		}
		
		while(r < Q[i].R)
		{
			r++;
			ans -= a[r] * cou[a[r]] * cou[a[r]];
			cou[a[r]]++;
			ans += a[r] * cou[a[r]] * cou[a[r]];
		}
		
		ans2[Q[i].num] = ans;
	}
	
	for(ll i = 1 ; i <= t ; i++)
		cout << ans2[i] en;
	
	return 0;
}