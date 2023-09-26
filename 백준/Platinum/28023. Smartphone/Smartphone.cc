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

struct gujo
{
	ll S, E, C;
	
	bool operator < (const gujo &xx) const
	{
		return S < xx.S;
	}
};

ll n, K;
gujo a[300010];
priority_queue<pll, vector<pll>, greater<pll> > pq;
ll now = 1;
ll ans;

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].S >> a[i].E >> a[i].C;
	
	sort(a + 1, a + 1 + n);
	
	pq.push({a[1].E, 1});
	now = a[1].S;
	
	a[n + 1].S = K + 1;
	
	for(ll i = 2 ; i <= n + 1 ; i++)
	{
		if(a[i].S == a[i - 1].S)
		{
			pq.push({a[i].E, i});
			continue;
		}
		
		while(!pq.empty())
		{
			pll qq = pq.top();
			pq.pop();
			
			ll num = qq.se;
			
			if(qq.fi < a[i].S)
			{
				if(now + a[num].C - 1 <= qq.fi)
				{
					ans += a[num].C;
					now += a[num].C;
				}
				
				else
				{
					ans += qq.fi - now + 1;
					a[num].C -= (qq.fi - now + 1);
					now = qq.fi + 1;
				}
			}
			
			else
			{
				if(now + a[num].C - 1 < a[i].S)
				{
					ans += a[num].C;
					now += a[num].C;
				}
				
				else
				{
					ans += a[i].S - now;
					a[num].C -= (a[i].S - now);
					now = a[i].S;
					pq.push(qq);
					break;
				}
			}
		}
		
		now = a[i].S;
		pq.push({a[i].E, i});
	}
	
	cout << ans;
	return 0;
}