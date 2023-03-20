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

ll n, m, k, q;
ll a[200010];
ll b[200010];
pair<pll, ll> qry[200010];
priority_queue<pll> pq[200010];
ll ans[200010];
ll h[200010];
ll ok[200010];

int main(void)
{
	fastio
	
	cin >> n >> m >> k >> q;
	
	for(ll i = 1 ; i <= m ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= k ; i++)
		cin >> b[i];
	
	for(ll i = 1 ; i <= q ; i++)
	{
		cin >> qry[i].fi.fi >> qry[i].fi.se >> qry[i].se;
		
		pq[qry[i].fi.fi].push({-((a[qry[i].se] + 1) / 2), i});
		pq[qry[i].fi.se].push({-((a[qry[i].se] + 1) / 2), i});
	}
	
	for(ll i = 1 ; i <= k ; i++)
	{
		ans[i] = ans[i - 1];
		
		if(i >= 3 && ans[i - 1] > ans[i - 2])
			h[b[i]] += 2;
		else
			h[b[i]]++;
		
		while(!pq[b[i]].empty())
		{
			pll qq = pq[b[i]].top();
			
			if(h[b[i]] < -qq.fi)
				break;
			
			pq[b[i]].pop();
			
			ll num = qq.se;
			
			if(h[qry[num].fi.fi] + h[qry[num].fi.se] >= a[qry[num].se])
			{
				ans[i] += 1 - ok[num];
				ok[num] = 1;
			}
			
			else
			{
				ll nam = (a[qry[num].se] - h[qry[num].fi.fi] - h[qry[num].fi.se]);
				
				pq[qry[num].fi.fi].push({-(h[qry[num].fi.fi] + (nam + 1) / 2), num});
				pq[qry[num].fi.se].push({-(h[qry[num].fi.se] + (nam + 1) / 2), num});
			}
		}
	}
	
	for(ll i = 1 ; i <= k ; i++)
		cout << ans[i] en;
	
	return 0;
}