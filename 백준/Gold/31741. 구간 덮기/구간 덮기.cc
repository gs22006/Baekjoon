#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
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
 
ll n, S, E;
ll all, bll;
vector<ll> lf, rg;
vector<pll> vv;
ll ans = INF;
 
int main(void)
{
	fastio
	
	cin >> n >> S >> E;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all >> bll;
		
		if(all <= S && bll >= E)
		{
			cout << 0;
			return 0;
		}
		
		if(all <= S)
			lf.push_back(bll);
		else if(bll >= E)
			rg.push_back(all);
		else
			vv.push_back({all, bll});
	}
	
	sort(lf.begin(), lf.end());
	sort(rg.begin(), rg.end());
	
	for(auto &i : lf)
	{
		ll idx = upper_bound(rg.begin(), rg.end(), i) - rg.begin() - 1;
		
		if(0 <= idx && idx < (ll)rg.size())
			ans = min(ans, i - rg[idx]);
	}
	
	for(auto &i : vv)
	{
		ll idx = upper_bound(rg.begin(), rg.end(), i.se) - rg.begin() - 1;
		ll idx2 = lower_bound(lf.begin(), lf.end(), i.fi) - lf.begin();
		
		if(0 <= idx && idx < (ll)rg.size() && 0 <= idx2 && idx2 < (ll)lf.size())
			ans = min(ans, i.se - rg[idx] + lf[idx2] - i.fi);
	}
	
	if(ans == INF)
		cout << -1;
	else
		cout << ans;
	
	return 0;
}
