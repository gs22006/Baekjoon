#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 987654321
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n, K;
ll cost[5010][5010];
pair<pll, ll> a[5010];
vector<ll> zip;
ll dp[5010];
ll sum2;

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
		
		zip.push_back(a[i].fi.fi);
		zip.push_back(a[i].fi.se);
		sum2 += a[i].se;
	}
	
	compress(zip);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		a[i].fi.fi = lower_bound(zip.begin(), zip.end(), a[i].fi.fi) - zip.begin() + 1;
		a[i].fi.se = lower_bound(zip.begin(), zip.end(), a[i].fi.se) - zip.begin() + 1;
	}
	
	ll siz = (ll)zip.size();
	
	for(ll i = 1 ; i <= siz ; i++)
	{
		priority_queue<ll> pq;
		ll sum = 0;
		vector<pll> vv;
		ll p = 0;
		ll gaet = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			if(a[j].fi.fi >= i)
				vv.push_back({a[j].fi.se, a[j].se});
		}
		
		sort(vv.begin(), vv.end());
		
		ll sz = (ll)vv.size();
		
		for(ll j = i ; j <= siz ; j++)
		{
			while(p < sz && vv[p].fi <= j)
			{
				pq.push(-vv[p].se);
				sum += vv[p].se;
				gaet++;
				
				if(gaet > K)
				{
					gaet--;
					sum += pq.top();
					pq.pop();
				}
				
				p++;
			}
			
			cost[i][j] = sum;
		}
	}
	
	for(ll i = 1 ; i <= siz ; i++)
	{
		dp[i] = cost[i][i];
		
		for(ll j = 0 ; j < i ; j++)
			dp[i] = max(dp[i], dp[j] + cost[j + 1][i]);
	}
	
	cout << sum2 - dp[siz];
	return 0;
}