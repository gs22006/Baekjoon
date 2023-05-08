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

ll n, L;
pll a[100010];
ll dp[100010];
ll nu[100010];
deque<pll> dq;
priority_queue<ll> pq, epq;

int main(void)
{
	fastio
	
	cin >> n >> L;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	
	for(ll i = 1 ; i <= n ; i++)
		nu[i] = nu[i - 1] + a[i].se;
	
	dq.push_back({0, 0});
	pq.push(0);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll w = -1;
		
		while(!dq.empty() && dq.back().fi < a[i].fi)
		{
			w = dq.back().se;
			epq.push(-(dp[w] + dq.back().fi));
			dq.pop_back();
		}
		
		if(w != -1)
		{
			dq.push_back({a[i].fi, w});
			pq.push(-(dp[w] + a[i].fi));
		}
		
		while(!dq.empty() && nu[i] - nu[dq.front().se] > L)
		{
			pll qq = dq.front();
			dq.pop_front();
			
			epq.push(-(dp[qq.se] + qq.fi));
			
			if(!dq.empty())
			{
				if(dq.front().se > qq.se + 1)
				{
					dq.push_front({qq.fi, qq.se + 1});
					pq.push(-(dp[qq.se + 1] + qq.fi));
				}
			}
			
			else
			{
				dq.push_front({qq.fi, qq.se + 1});
				pq.push(-(dp[qq.se + 1] + qq.fi));
			}
		}
		
		while(!pq.empty() && !epq.empty() && pq.top() == epq.top())
			pq.pop(), epq.pop();
		
		dp[i] = -pq.top();
		dq.push_back({0, i});
		pq.push(-dp[i]);
	}
	
	cout << dp[n];
	return 0;
}