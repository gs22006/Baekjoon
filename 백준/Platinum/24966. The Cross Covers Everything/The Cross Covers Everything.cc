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
pll a[200010];
ll ans;
ll minn[200010], maxx[200010];
ll mini[2000010], maxi[2000010];
ll minn2[200010], maxx2[200010];

void solve(void)
{
	minn[0] = 2000000;
	maxx[0] = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		minn[i] = min(minn[i - 1], a[i].se);
		maxx[i] = max(maxx[i - 1], a[i].se);
	}
	
	minn2[n + 1] = 2000000;
	maxx2[n + 1] = 0;
	
	for(ll i = n ; i >= 1 ; i--)
	{
		minn2[i] = min(minn2[i + 1], a[i].se);
		maxx2[i] = max(maxx2[i + 1], a[i].se);
	}
	
	vector<pll> LD;
	vector<pll> RU;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i].se <= minn[i - 1])
			LD.push_back(a[i]);
		
		if(a[i].se >= maxx2[i + 1])
			RU.push_back(a[i]);
	}
	
	sort(LD.begin(), LD.end());
	sort(RU.begin(), RU.end());
	
	for(auto &i : RU)
	{
		ll X = mini[i.se];
		ll Y = maxi[i.fi];
		ll l = 0, r = (ll)LD.size() - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(LD[mid].fi <= X)
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		ll siz = r;
		l = 0, r = r;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(LD[mid].se <= Y)
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		ans += siz - l + 1;
	}
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	
	for(ll i = 0 ; i <= 1000001 ; i++)
	{
		mini[i] = INF;
		maxi[i] = INF;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		maxi[a[i].fi] = min(maxi[a[i].fi], a[i].se);
		mini[a[i].se] = min(mini[a[i].se], a[i].fi);
	}
	
	for(ll i = 1000000 ; i >= 1 ; i--)
	{
		mini[i] = min(mini[i + 1], mini[i]);
		maxi[i] = min(maxi[i + 1], maxi[i]);
	}
	
	sort(a + 1, a + 1 + n);
	solve();
	
	cout << ans;
	return 0;
}