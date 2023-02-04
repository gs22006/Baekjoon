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
ll all, bll, cll;
vector<pll> vec[100010];
ll C[100010];
ll q;
ll R[100010];
ll siz[100010];
ll dep[100010];
ll dp[100010], dp2[100010];
priority_queue<pll> pq;
ll KING;
ll cc;
ll chk[100010];

struct line
{
	ll A, B;
	ld S;
};

ld gyo(ll A1, ll B1, ll A2, ll B2)
{
	return (ld)(B2 - B1) / (ld)(A1 - A2);
}

struct RollbackCHT
{
	pair<line, ll> lin[200010];
	pair<ll, ll> W[200010];
	line his[200010];
	ll SISIZ, CCCC;
	
	void init(void)
	{
		lin[0] = {{0, 0, 0}, 0};
		his[0] = {0, 0, 0};
		W[0] = {0, 0};
		SISIZ = 1;
		CCCC = 1;
	}
	
	void update(ll X, ll Y)
	{
		ll l = 0, r = SISIZ - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) / 2;
			
			if(gyo(lin[mid].fi.A, lin[mid].fi.B, X, Y) <= lin[mid].fi.S)
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		W[CCCC] = {lin[l].se, SISIZ};
		
		lin[l] = {{X, Y, gyo(lin[r].fi.A, lin[r].fi.B, X, Y)}, CCCC};
		his[CCCC] = lin[l].fi;
		CCCC++;
		SISIZ = l + 1;
	}
	
	ll query(ll X)
	{
		ll l = 0, r = SISIZ - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) / 2;
			
			if(lin[mid].fi.S <= X)
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		return lin[r].fi.A * X + lin[r].fi.B;
	}
	
	void erase(void)
	{
		ll num = lin[SISIZ - 1].se;
		pair<ll, ll> L = W[num];
		
		lin[SISIZ - 1].fi = his[L.fi];
		lin[SISIZ - 1].se = L.fi;
		SISIZ = L.se;
	}
}cht;

void dfs(ll here, ll pa)
{
	siz[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa || R[i.fi])
			continue;
		
		dfs(i.fi, here);
		siz[here] += siz[i.fi];
	}
}

ll get_centroid(ll here, ll pa, ll Tsiz)
{
	for(auto &i : vec[here])
	{
		if(i.fi == pa || R[i.fi])
			continue;
		
		if(siz[i.fi] * 2 > Tsiz)
			return get_centroid(i.fi, here, Tsiz);
	}
	
	return here;
}

void add_centroid(ll X)
{
	ll cen1 = 0, sizz = 0;
	
	dfs(X, -1);
	cen1 = get_centroid(X, -1, siz[X]);
	dfs(cen1, -1);
	
	sizz = siz[cen1];
	
	for(auto &i : vec[cen1])
	{
		if(R[i.fi])
			continue;
		
		if(siz[i.fi] * 2 == siz[cen1])
		{
			cen1 = min(cen1, i.fi);
			break;
		}
	}
	
	pq.push({sizz, -cen1});
}

void dfs2(ll here, ll pa)
{
	dp[here] = dp2[here] = 0;
	chk[here] = cc;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa || R[i.fi])
			continue;
		
		dep[i.fi] = dep[here] + i.se;
		dfs2(i.fi, here);
	}
}

void dfs3(ll here, ll pa)
{
	if(pa != -1)
	{
		dp[here] = cht.query(dep[here]) + C[here] + dep[here] * dep[here];
		cht.update(-2 * dep[here], dep[here] * dep[here] + dp[here]);
	}
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa || R[i.fi])
			continue;
		
		dfs3(i.fi, here);
	}
	
	if(pa != -1)
		cht.erase();
}

void calc_dp(ll here)
{
	cht.init();
	cc++;
	dep[here] = 0;
	dfs2(here, -1);
	dfs3(here, -1);
	
	for(ll i = 0 ; i <= (ll)cht.CCCC ; i++)
	{
		cht.lin[i] = {{0, 0, 0}, 0};
		cht.his[i] = {0, 0, 0};
		cht.W[i] = {0, 0};
	}
	
	cht.CCCC = cht.SISIZ = 0;
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll >> cll;
		
		vec[all].push_back({bll, cll});
		vec[bll].push_back({all, cll});
	}
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> C[i];
	
	add_centroid(1);
	
	KING = -pq.top().se;
	pq.pop();
	calc_dp(KING);
	
	cin >> q;
	
	while(q--)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> all >> bll;
			
			if(chk[all] != cc || R[all])
			{
				cout << -1 en;
				continue;
			}
			
			if(bll == 1)
				cout << dp[all] en;
			else
				cout << dp[all] + C[KING] - C[all] en;
			
			continue;
		}
		
		R[KING] = 1;
		
		for(auto &i : vec[KING])
		{
			if(R[i.fi])
				continue;
			
			add_centroid(i.fi);
		}
		
		KING = -pq.top().se;
		pq.pop();
		calc_dp(KING);
	}
	
	return 0;
}