#include <bits/stdc++.h>

using namespace std;
typedef int ll;
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
ll a[100010];
ll all, bll;
vector<ll> vec[100010];
pair<pll, ll> qry[100010];
ll LC[100010];
ll IN[100010], OUT[100010];
ll cc;
long long l[100010], r[100010], mid[100010];
pll b[100010];
ll dep[100010], spa[100010][21];
ll now[100010];

struct fenwicktree
{
	ll bit[100010];
	
	void init(void)
	{
		for(ll i = 0 ; i <= n ; i++)
			bit[i] = 0;
	}
	
	void update(ll w, ll v)
	{
		for(ll i = w ; i <= n ; i += (i & (-i)))
			bit[i] += v;
	}
	
	ll query(ll X)
	{
		ll ret = 0;
		
		for(ll i = X ; i > 0 ; i -= (i & (-i)))
			ret += bit[i];
		
		return ret;
	}
}BIT;

ll LCA(ll X, ll Y)
{
	if(dep[X] < dep[Y])
		swap(X, Y);
	
	ll cha = dep[X] - dep[Y];
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if(cha >= (1LL << i))
		{
			cha -= (1LL << i);
			X = spa[X][i];
		}
	}
	
	if(X == Y)
		return X;
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if(spa[X][i] != spa[Y][i])
		{
			X = spa[X][i];
			Y = spa[Y][i];
		}
	}
	
	return spa[X][0];
}

ll cost(ll X, ll Y, ll I)
{
	ll L = LC[I];
	return BIT.query(IN[X]) + BIT.query(IN[Y]) - 2 * BIT.query(IN[L]) + now[L];
}

void dfs0(ll here, ll pa)
{
	dep[here] = dep[pa] + 1;
	spa[here][0] = pa;
	IN[here] = ++cc;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs0(i, here);
	}
	
	OUT[here] = cc;
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		b[i] = {a[i], i};
	}
	
	sort(b + 1, b + 1 + n);
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	dfs0(1, 0);
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> qry[i].fi.fi >> qry[i].fi.se >> qry[i].se;
		LC[i] = LCA(qry[i].fi.fi, qry[i].fi.se);
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		l[i] = -(1LL << 31);
		r[i] = (1LL << 31) - 1;
	}
	
	while(1)
	{
		ll ff = 0;
		vector<pll> Q;
		
		BIT.init();
		
		for(ll i = 1 ; i <= n ; i++)
			now[i] = 0;
		
		for(ll i = 1 ; i <= m ; i++)
		{
			if(l[i] <= r[i])
			{
				ff = 1;
				mid[i] = (l[i] + r[i]) >> 1;
				Q.push_back({mid[i], i});
			}
		}
		
		if(!ff)
			break;
		
		sort(Q.begin(), Q.end());
		
		ll p = 1;
		
		for(auto &i : Q)
		{
			while(p <= n && b[p].fi <= i.fi)
			{
				now[b[p].se] = 1;
				BIT.update(IN[b[p].se], 1);
				BIT.update(OUT[b[p].se] + 1, -1);
				p++;
			}
			
			ll D = cost(qry[i.se].fi.fi, qry[i.se].fi.se, i.se);
			
			if(D >= qry[i.se].se)
				r[i.se] = mid[i.se] - 1;
			else
				l[i.se] = mid[i.se] + 1;
		}
	}
	
	for(ll i = 1 ; i <= m ; i++)
		cout << l[i] en;
	
	return 0;
}