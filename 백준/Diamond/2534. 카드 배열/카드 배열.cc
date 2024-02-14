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

ll n, k, P;
ll all, bll;
vector<ll> vec[300010], vec2[300010];
ll deg[300010], deg2[300010];
priority_queue<ll> pq;
ll a[300010], b[300010];
ll ans;
ll ss = 1000000007;

int main(void)
{
	fastio
	
	cin >> n >> k >> P;
	
	for(ll i = 0 ; i < P ; i++)
	{
		cin >> all >> bll;
		
		vec[bll].push_back(all);
		vec2[all].push_back(bll);
		deg[all]++;
		deg2[bll]++;
	}
	
	for(ll i = 0 ; i < k ; i++)
	{
		if(!deg[i])
			pq.push(-i);
	}
	
	for(ll i = k - 1 ; i >= 0 ; i--)
	{
		ll qq = -pq.top();
		pq.pop();
		
		a[qq] = i;
		
		for(auto &j : vec[qq])
		{
			deg[j]--;
			
			if(!deg[j])
				pq.push(-j);
		}
	}
	
	while(!pq.empty())
		pq.pop();
	
	for(ll i = 0 ; i < k ; i++)
	{
		if(!deg2[i])
			pq.push(-i);
	}
	
	for(ll i = k - 1 ; i >= 0 ; i--)
	{
		ll qq = -pq.top();
		pq.pop();
		
		b[qq] = n - 1 - i;
		
		for(auto &j : vec2[qq])
		{
			deg2[j]--;
			
			if(!deg2[j])
				pq.push(-j);
		}
	}
	
	ll now = 1;
	
	for(ll i = 0 ; i < k ; i++)
	{
		ans = (ans + (b[i] - a[i]) * now % ss) % ss;
		now = now * n % ss;
	}
	
	cout << ((ans + ss) % ss);
	return 0;
}