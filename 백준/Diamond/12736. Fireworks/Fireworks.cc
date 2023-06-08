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

ll n, m;
ll all, bll;
vector<pll> vec[300010];
priority_queue<ll> pq[300010];
ll bun[300010];
ll dp[300010];
ll cc;

void dfs(ll here, ll pa, ll pdist)
{
	ll coco = 0;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		dfs(i.fi, here, i.se);
		coco++;
	}
	
	if(!coco)
	{
		bun[here] = ++cc;
		pq[bun[here]].push(pdist);
		pq[bun[here]].push(pdist);
		dp[bun[here]] = 0;
		
		return;
	}
	
	ll maxx = 0;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		if(maxx < (ll)pq[bun[i.fi]].size())
		{
			maxx = (ll)pq[bun[i.fi]].size();
			bun[here] = bun[i.fi];
		}
	}
	
	dp[bun[here]] -= pq[bun[here]].top();
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa || bun[here] == bun[i.fi])
			continue;
		
		dp[bun[here]] += dp[bun[i.fi]];
		dp[bun[here]] -= pq[bun[i.fi]].top();
		
		while(!pq[bun[i.fi]].empty())
		{
			pq[bun[here]].push(pq[bun[i.fi]].top());
			pq[bun[i.fi]].pop();
		}
	}
	
	for(ll i = 1 ; i < coco ; i++)
	{
		dp[bun[here]] += pq[bun[here]].top();
		pq[bun[here]].pop();
	}
	
	ll gap1 = pq[bun[here]].top();
	pq[bun[here]].pop();
	ll gap2 = pq[bun[here]].top();
	pq[bun[here]].pop();
	
	dp[bun[here]] += gap1;
	pq[bun[here]].push(gap1 + pdist);
	pq[bun[here]].push(gap2 + pdist);
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	n += m;
	
	for(ll i = 2 ; i <= n ; i++)
	{
		cin >> all >> bll;
		
		vec[i].push_back({all, bll});
		vec[all].push_back({i, bll});
	}
	
	dfs(1, 0, 0);
	
	cout << dp[bun[1]];
	return 0;
}