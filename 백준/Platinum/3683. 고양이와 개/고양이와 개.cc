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

ll t;
ll C, D, n;
char all;
ll bll;
vector<ll> vec[510];
ll ltr[510], rtl[510];
ll chk[510];

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
	
	cin >> t;
	
	while(t--)
	{
		vector<pll> vv;
		
		cin >> C >> D >> n;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			pll gap;
			
			cin >> all >> bll;
			
			if(all == 'C')
				gap.fi = bll;
			else
				gap.fi = bll + C;
			
			cin >> all >> bll;
			
			if(all == 'D')
				gap.se = bll + C;
			else
				gap.se = bll;
			
			vv.push_back(gap);
		}
		
		for(ll i = 0 ; i < n ; i++)
			vec[i].clear();
		
		for(ll i = 0 ; i < n ; i++)
		{
			for(ll j = i + 1 ; j < n ; j++)
			{
				if(vv[i].fi == vv[j].se || vv[i].se == vv[j].fi)
				{
					if(vv[i].fi <= C)
						vec[i].push_back(j);
					else
						vec[j].push_back(i);
				}
			}
		}
		
		ll ans = n;
		
		for(ll i = 0 ; i < n ; i++)
			ltr[i] = rtl[i] = -1;
		
		for(ll i = 0 ; i < n ; i++)
		{
			if(ltr[i] == -1)
			{
				for(ll j = 0 ; j < n ; j++)
					chk[j] = 0;
				
				ans -= dfs(i);
			}
		}
		
		cout << ans en;
	}
	
	return 0;
}