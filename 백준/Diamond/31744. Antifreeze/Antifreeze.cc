#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
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
 
ll n, T;
ll a[100010];
ll all, bll, cll;
ll q;
ll pa[100010], ra[100010];
vector<pll> vec[100010];
priority_queue<pll, vector<pll>, greater<pll> > pq[100010];
ll bun[100010], cc;
ll dep[100010];
 
ll ffind(ll here)
{
	if(here == pa[here])
		return here;
	
	return pa[here] = ffind(pa[here]);
}
 
void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	if(ra[X] < ra[Y])
		pa[X] = Y;
	else if(ra[Y] < ra[X])
		pa[Y] = X;
	
	else
	{
		pa[X] = Y;
		ra[Y]++;
	}
}
 
void dfs0(ll here, ll pa)
{
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		dep[i.fi] = dep[here] + i.se;
		dfs0(i.fi, here);
	}
}
 
void dfs(ll here, ll pa)
{
	ll chld = 0;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		dfs(i.fi, here);
		chld++;
	}
	
	if(!chld)
	{
		bun[here] = ++cc;
		
		if(a[here])
			pq[bun[here]].push({dep[here], here});
		else
			pq[bun[here]].push({INF, 0});
		
		return;
	}
	
	ll maxx = -1, w = 0;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		if((ll)pq[bun[i.fi]].size() > maxx)
		{
			maxx = (ll)pq[bun[i.fi]].size();
			w = i.fi;
		}
	}
	
	bun[here] = bun[w];
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa || i.fi == w)
			continue;
		
		while(!pq[bun[i.fi]].empty())
		{
			pll gap = pq[bun[i.fi]].top();
			pq[bun[i.fi]].pop();
			
			if(gap.fi > pq[bun[here]].top().fi)
			{
				if(pq[bun[here]].top().fi + gap.fi - 2 * dep[here] <= T)
					uunion(pq[bun[here]].top().se, gap.se);
				
				pq[bun[here]].push(gap);
			}
			
			else
			{
				while(!pq[bun[here]].empty() && pq[bun[here]].top().fi + gap.fi - 2 * dep[here] <= T)
				{
					pll gap2 = pq[bun[here]].top();
					pq[bun[here]].pop();
					
					uunion(gap2.se, gap.se);
				}
				
				pq[bun[here]].push(gap);
			}
		}
	}
	
	if(a[here])
	{
		while(!pq[bun[here]].empty() && pq[bun[here]].top().fi - dep[here] <= T)
		{
			pll gap2 = pq[bun[here]].top();
			pq[bun[here]].pop();
			
			uunion(gap2.se, here);
		}
		
		pq[bun[here]].push({dep[here], here});
	}
}
 
int main(void)
{
	fastio
	
	cin >> n >> T;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll >> cll;
		
		vec[all].push_back({bll, cll});
		vec[bll].push_back({all, cll});
	}
	
	for(ll i = 1 ; i <= n ; i++)
		pa[i] = i;
	
	dfs0(1, 0);
	dfs(1, 0);
	
	cin >> q;
	
	while(q--)
	{
		cin >> all >> bll;
		
		if(ffind(all) == ffind(bll))
			cout << 1 en;
		else
			cout << 0 en;
	}
	
	return 0;
}
