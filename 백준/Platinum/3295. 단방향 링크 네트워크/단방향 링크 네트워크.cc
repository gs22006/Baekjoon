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
ll n, m;
ll all, bll;
vector<ll> vec[2010];
ll ltr[2010], rtl[2010];
ll chk[2010];

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
		ll ans = 0;
		
		cin >> n >> m;
		
		for(ll i = 1 ; i <= n * 2 ; i++)
			vec[i].clear();
		
		for(ll i = 1 ; i <= m ; i++)
		{
			cin >> all >> bll;
			
			all++, bll++;
			vec[all + n].push_back(bll);
		}
		
		for(ll i = 1 ; i <= n * 2 ; i++)
			ltr[i] = rtl[i] = -1;
		
		for(ll i = n ; i <= n * 2 ; i++)
		{
			if(ltr[i] == -1)
			{
				for(ll j = 1 ; j <= n * 2 ; j++)
					chk[j] = 0;
				
				ans += dfs(i);
			}
		}
		
		cout << ans en;
	}
	
	return 0;
}