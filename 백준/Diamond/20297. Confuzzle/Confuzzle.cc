#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

ll n;
ll a[100010];
ll all, bll;
vector<ll> vec[100010];
ll R[100010];
ll siz[100010];
ll col[100010], cc;
vector<ll> clr;
ll dist[100010][3];
ll ans = INF;

void dfs(ll here, ll pa)
{
	siz[here] = 1;
	
	if(col[a[here]] != cc)
		clr.push_back(a[here]);
	
	col[a[here]] = cc;
	
	for(auto &i : vec[here])
	{
		if(i == pa || R[i])
			continue;
		
		dfs(i, here);
		siz[here] += siz[i];
	}
}

ll get_cent(ll here, ll pa, ll Tsiz)
{
	for(auto &i : vec[here])
	{
		if(i == pa || R[i])
			continue;
		
		if(siz[i] * 2 > Tsiz)
			return get_cent(i, here, Tsiz);
	}
	
	return here;
}

void dfs2(ll here, ll pa, ll dis)
{
	if(dist[a[here]][0] > dis)
	{
		dist[a[here]][1] = dist[a[here]][0];
		dist[a[here]][0] = dis;
	}
	
	else if(dist[a[here]][1] > dis)
		dist[a[here]][1] = dis;
	
	for(auto &i : vec[here])
	{
		if(i == pa || R[i])
			continue;
		
		dfs2(i, here, dis + 1);
	}
}

void f(ll here)
{
	cc++;
	clr.clear();
	dfs(here, 0);
	
	for(auto &i : clr)
		dist[i][0] = dist[i][1] = INF;
	
	ll rt = get_cent(here, 0, siz[here]);
	
	dfs2(rt, 0, 0);
	
	for(auto &i : clr)
		ans = min(ans, dist[i][0] + dist[i][1]);
	
	R[rt] = 1;
	
	for(auto &i : vec[rt])
	{
		if(R[i])
			continue;
		
		f(i);
	}
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	f(1);
	
	cout << ans;
	return 0;
}