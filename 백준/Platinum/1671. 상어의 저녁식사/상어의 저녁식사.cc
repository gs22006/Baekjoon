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
ll a[5010], b[5010], c[5010];
vector<ll> vec[5010];
vector<pll> vv;
ll ltr[5010], rtl[5010];
ll chk[5010];
ll ans;
ll cc;

ll dfs(ll here)
{
	chk[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(rtl[i] == -1 || (!chk[rtl[i]] && dfs(rtl[i])))
		{
			ltr[here] = i;
			rtl[i] = here;
			return 1;
		}
	}
	
	return 0;
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i] >> b[i] >> c[i];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll ff = 0;
		
		for(ll j = i + 1 ; j <= n ; j++)
		{
			if(a[i] == a[j] && b[i] == b[j] && c[i] == c[j])
				ff = 1;
		}
		
		ll cou = 2;
		
		for(ll j = 1 ; j < i ; j++)
		{
			if(a[i] == a[j] && b[i] == b[j] && c[i] == c[j])
				cou++;
		}
		
		if(!ff)
			vv.push_back({i, cou});
	}
	
	ll cc = 0;
	ll ans = (ll)vv.size();
	
	for(ll i = 0 ; i < (ll)vv.size() ; i++)
	{
		for(ll j = 0 ; j < (ll)vv.size() ; j++)
		{
			if(i == j)
				continue;
			
			if(a[vv[i].fi] >= a[vv[j].fi] && b[vv[i].fi] >= b[vv[j].fi] && c[vv[i].fi] >= c[vv[j].fi])
			{
				for(ll k = 0 ; k < (ll)vv[i].se ; k++)
					vec[cc + k].push_back(vv[j].fi);
			}
		}
		
		cc += vv[i].se;
	}
	
	for(ll i = 0 ; i < cc ; i++)
		ltr[i] = rtl[i] = -1;
	
	for(ll i = 0 ; i < cc ; i++)
	{
		if(ltr[i] == -1)
		{
			for(ll j = 0 ; j < cc ; j++)
				chk[j] = 0;
			
			ans -= dfs(i);
		}
	}
	
	cout << ans;
	return 0;
}