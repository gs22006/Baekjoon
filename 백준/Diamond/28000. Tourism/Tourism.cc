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

struct gujo
{
	ll L, R, num;
	
	bool operator < (const gujo &xx) const
	{
		return L > xx.L;
	}
};

ll n, m, q;
ll all, bll;
vector<ll> vec[100010];
gujo qry[100010];
ll a[100010];
ll IN[100010], OUT[100010], cc;
ll spa[100010][21], dep[100010], siz[100010];
ll tp[100010];
set<pll> st[100010];
ll maxx[100010];
ll ans[100010];

struct fenwicktree
{
	ll bit[100010];
	
	void update(ll w, ll v)
	{
		for(ll i = w ; i <= m + 1 ; i += (i & (-i)))
			bit[i] += v;
	}
	
	ll query(ll w)
	{
		ll ret = 0;
		
		for(ll i = w ; i > 0 ; i -= (i & (-i)))
			ret += bit[i];
		
		return ret;
	}
}BIT;

void dfs0(ll here, ll pa)
{
	siz[here] = 1;
	dep[here] = dep[pa] + 1;
	spa[here][0] = pa;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs0(i, here);
		siz[here] += siz[i];
	}
}

void dfs(ll here)
{
	IN[here] = ++cc;
	
	for(auto &i : vec[here])
	{
		if(i == vec[here][0])
			tp[i] = tp[here];
		else
			tp[i] = i;
		
		dfs(i);
	}
	
	OUT[here] = cc;
}

ll lift(ll X, ll Y)
{
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if((1LL << i) <= Y)
		{
			Y -= (1LL << i);
			X = spa[X][i];
		}
	}
	
	return X;
}

void map_update(ll num, ll X, ll Y, ll Z)
{
	auto p = st[num].upper_bound({X, INF});
	auto p2 = p;
	vector< pair<pll, ll> > vv;
	ll END = maxx[num];
	
	p2--;
	
	while(1)
	{
		vv.push_back({{(*p2).fi, INF}, (*p2).se});
		p2++;
		
		if(p2 == st[num].end())
			break;
		
		if((*p2).fi > Y)
		{
			END = (*p2).fi - 1;
			break;
		}
	}
	
	for(ll i = 0 ; i < (ll)vv.size() ; i++)
	{
		if(i < (ll)vv.size() - 1)
			vv[i].fi.se = vv[i + 1].fi.fi - 1;
		else
			vv[i].fi.se = END;
	}
	
	vector< pair<pll, ll> > vv2;
	
	for(auto &i : vv)
	{
		if(X <= i.fi.fi && i.fi.se <= Y)
			continue;
		
		if(i.fi.fi < X)
		{
			if(X <= i.fi.se)
			{
				vv2.push_back({{i.fi.fi, X - 1}, i.se});
				
				if(Y < i.fi.se)
					vv2.push_back({{Y + 1, i.fi.se}, i.se});
			}
			
			else
				vv2.push_back(i);
		}
		
		else if(Y < i.fi.se)
		{
			if(i.fi.fi <= Y)
				vv2.push_back({{Y + 1, i.fi.se}, i.se});
			else
				vv2.push_back(i);
		}
	}
	
	vv2.push_back({{X, Y}, Z});
	
	for(auto &i : vv)
	{
		BIT.update(i.se, -i.fi.se + i.fi.fi - 1);
		st[num].erase({i.fi.fi, i.se});
	}
	
	for(auto &i : vv2)
	{
		BIT.update(i.se, i.fi.se - i.fi.fi + 1);
		st[num].insert({i.fi.fi, i.se});
	}
}

void update(ll X, ll Y, ll Z)
{
	while(tp[X] != tp[Y])
	{
		if(dep[tp[X]] < dep[tp[Y]])
			swap(X, Y);
		
		map_update(tp[X], IN[tp[X]], IN[X], Z);
		X = spa[tp[X]][0];
	}
	
	if(dep[X] < dep[Y])
		swap(X, Y);
	
	if(X == Y)
		return;
	
	ll tp2 = lift(X, dep[X] - dep[Y] - 1);
	
	map_update(tp[X], IN[tp2], IN[X], Z);
}

int main(void)
{
	fastio
	
	cin >> n >> m >> q;
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	for(ll i = 1 ; i <= m ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= q ; i++)
	{
		cin >> qry[i].L >> qry[i].R;
		qry[i].num = i;
	}
	
	sort(qry + 1, qry + 1 + q);
	
	dfs0(1, 0);
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	for(ll i = 2 ; i <= n ; i++)
	{
		for(ll j = 0 ; j < (ll)vec[i].size() - 1 ; j++)
		{
			if(vec[i][j] == spa[i][0])
				swap(vec[i][j], vec[i][j + 1]);
		}
		
		vec[i].pop_back();
		
		for(ll j = 0 ; j < (ll)vec[i].size() ; j++)
		{
			if(siz[vec[i][j]] > siz[vec[i][0]])
				swap(vec[i][j], vec[i][0]);
		}
	}
	
	tp[1] = 1;
	dfs(1);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		maxx[tp[i]] = max(maxx[tp[i]], IN[i]);
		st[i].insert({IN[i], m + 1});
		BIT.update(m + 1, 1);
	}
	
	ll p = m;
	
	for(ll i = 1 ; i <= q ; i++)
	{
		while(p > qry[i].L)
		{
			update(a[p - 1], a[p], p);
			p--;
		}
		
		ans[qry[i].num] = BIT.query(qry[i].R);
	}
	
	for(ll i = 1 ; i <= q ; i++)
		cout << ans[i] + 1 en;
	
	return 0;
}