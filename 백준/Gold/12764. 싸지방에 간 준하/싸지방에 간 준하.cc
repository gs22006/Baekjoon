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
pll a[100010];
ll ans[100010];
ll us[100010];
pll b[1000010];
priority_queue<ll> pq;
ll maxx;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].fi >> a[i].se;
		
		b[a[i].fi] = {1, i};
		b[a[i].se] = {-1, i};
		pq.push(-i);
	}
	
	for(ll i = 0 ; i <= 1000000 ; i++)
	{
		if(!b[i].fi)
			continue;
		
		if(b[i].fi > 0)
		{
			us[b[i].se] = -(ll)pq.top();
			pq.pop();
		}
		
		else
			pq.push(-us[b[i].se]);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ans[us[i]]++;
		maxx = max(maxx, us[i]);
	}
	
	cout << maxx en;
	
	for(ll i = 1 ; i <= maxx ; i++)
		cout << ans[i] sp;
	
	return 0;
}