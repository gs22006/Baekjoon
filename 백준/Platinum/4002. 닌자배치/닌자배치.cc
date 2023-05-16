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
ll p[100010], C[100010], L[100010];
vector<ll> vec[100010];
ll rt;
ll ans;
vector< priority_queue<ll> > pq;
priority_queue<ll> emp;
ll bun[100010];
ll sum[100010];

void dfs(ll here, ll pa)
{
	ll maxx = -1, w = -1;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs(i, here);
		
		if((ll)pq[bun[i]].size() > maxx)
		{
			maxx = (ll)pq[bun[i]].size();
			w = i;
		}
	}
	
	if(w == -1)
	{
		bun[here] = (ll)pq.size();
		pq.push_back(emp);
		
		if(C[here] <= m)
		{
			pq[bun[here]].push(C[here]);
			sum[here] = C[here];
		}
		
		ans = max(ans, L[here] * (ll)pq[bun[here]].size());
		return;
	}
	
	bun[here] = bun[w];
	sum[here] = sum[w];
	
	for(auto &i : vec[here])
	{
		if(i == pa || i == w)
			continue;
		
		while(!pq[bun[i]].empty())
		{
			if(pq[bun[i]].top() + sum[here] <= m)
			{
				sum[here] += pq[bun[i]].top();
				pq[bun[here]].push(pq[bun[i]].top());
				pq[bun[i]].pop();
				
				continue;
			}
			
			if(pq[bun[here]].empty())
			{
				pq[bun[i]].pop();
				continue;
			}
			
			if(pq[bun[here]].top() > pq[bun[i]].top())
			{
				sum[here] -= pq[bun[here]].top();
				pq[bun[here]].pop();
				sum[here] += pq[bun[i]].top();
				pq[bun[here]].push(pq[bun[i]].top());
				pq[bun[i]].pop();
			}
			
			else
				pq[bun[i]].pop();
		}
	}
	
	if(sum[here] + C[here] <= m)
	{
		sum[here] += C[here];
		pq[bun[here]].push(C[here]);
	}
	
	else if(!pq[bun[here]].empty() && pq[bun[here]].top() > C[here])
	{
		sum[here] = sum[here] - pq[bun[here]].top() + C[here];
		pq[bun[here]].pop();
		pq[bun[here]].push(C[here]);
	}
	
	ans = max(ans, L[here] * (ll)pq[bun[here]].size());
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> p[i] >> C[i] >> L[i];
		
		vec[i].push_back(p[i]);
		vec[p[i]].push_back(i);
		
		if(!p[i])
			rt = i;
	}
	
	dfs(rt, 0);
	
	cout << ans;
	return 0;
}