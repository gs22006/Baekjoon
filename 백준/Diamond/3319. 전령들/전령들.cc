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
vector<pll> vec[200010];
ll SS[200010], V[200010];
ll dp[200010], dep[200010];

struct line
{
	ll A, B;
	ld S; 
};

ld gyo(ll A1, ll B1, ll A2, ll B2)
{
	if(A1 == A2)
		assert(0);
	
	return (ld)(B2 - B1) / (ld)(A1 - A2);
}

pair<line, ll> lin[200010];
pair<ll, ll> W[200010];
line his[200010];
ll siz, cc;

void init(void)
{
	lin[0] = {{0, 0, 0}, 0};
	his[0] = {0, 0, 0};
	W[0] = {0, 0};
	siz++;
	cc++;
}

void update(ll X, ll Y)
{
	ll l = 0, r = siz - 1;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		
		if(gyo(lin[mid].fi.A, lin[mid].fi.B, X, Y) <= lin[mid].fi.S)
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	W[cc] = {lin[l].se, siz};
	
	lin[l] = {{X, Y, gyo(lin[r].fi.A, lin[r].fi.B, X, Y)}, cc};
	his[cc] = lin[l].fi;
	cc++;
	siz = l + 1;
}

ll query(ll X)
{
	ll l = 0, r = siz - 1;
	
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
	ll num = lin[siz - 1].se;
	pair<ll, ll> L = W[num];
	
	if(L.fi == -1)
	{
		lin[siz - 1] = {{0, 0, 0}, 0};
		siz = L.se;
	}
	
	else
	{
		lin[siz - 1].fi = his[L.fi];
		lin[siz - 1].se = L.fi;
		siz = L.se;
	}
}

void dfs(ll here, ll pa)
{
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		dep[i.fi] = dep[here] + i.se;
		dfs(i.fi, here);
	}
}

void f(ll here, ll pa)
{
	if(here != 1)
	{
		dp[here] = query(V[here]) + dep[here] * V[here] + SS[here];
		update(-dep[here], dp[here]);
	}
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		f(i.fi, here);
	}
	
	erase();
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
	
	for(ll i = 2 ; i <= n ; i++)
		cin >> SS[i] >> V[i];
	
	init();
	
	dfs(1, 0);
	f(1, 0);
	
	for(ll i = 2 ; i <= n ; i++)
		cout << dp[i] sp;
	
	return 0;
}