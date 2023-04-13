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

struct edge
{
	ll u, v, cost;
	
	bool operator < (const edge &xx) const
	{
		return cost < xx.cost;
	}
};

ll n, m, k;
char all;
ll bll, cll;
vector<edge> edg;
ll pa[1010], ra[1010];

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
	
	if(X == Y)
		return;
	
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

ll get_mst(void)
{
	ll ret = 0;
	
	for(ll i = 1 ; i <= n ; i++)
		pa[i] = i, ra[i] = 0;
	
	sort(edg.begin(), edg.end());
	
	for(auto &i : edg)
	{
		if(ffind(i.u) == ffind(i.v))
			continue;
		
		uunion(i.u, i.v);
		ret += i.cost;
	}
	
	return ret;
}

int main(void)
{
	fastio
	
	while(1)
	{
		edg.clear();
		
		cin >> n >> m >> k;
		
		if(!n && !m && !k)
			break;
		
		for(ll i = 1 ; i <= m ; i++)
		{
			cin >> all >> bll >> cll;
			
			if(all == 'B')
				edg.push_back({bll, cll, 0});
			else
				edg.push_back({bll, cll, 1});
		}
		
		ll maxx = n - 1 - get_mst();
		
		for(auto &i : edg)
			i.cost ^= 1;
		
		ll minn = get_mst();
		
		if(minn <= k && k <= maxx)
			cout << 1 en;
		else
			cout << 0 en;
	}
	
	return 0;
}