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

ll n;
ll a[1000010];
ll all, bll;
vector<ll> vec[1000010];
ll m;
ll sq;
ll IN[1000010], OUT[1000010];
ll tr[1000010], cc;
ll spa[1000010][21];
ll chk[1000010], cou[1000010];
ll ans;
ll l, r;
ll ans2[1000010];
ll dep[1000010];

struct QUERY
{
	ll L, R;
	ll u, v;
	ll lca;
	ll num;
	
	bool operator < (const QUERY &xx) const
	{
		if(L / sq != xx.L / sq)
			return L / sq < xx.L / sq;
		
		return R < xx.R;
	}
};

QUERY q[1000010];

void dfs0(ll here, ll pa)
{
	tr[++cc] = here;
	IN[here] = cc;
	spa[here][0] = pa;
	dep[here] = dep[pa] + 1;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs0(i, here);
	}
	
	tr[++cc] = here;
	OUT[here] = cc;
}

void add(ll X)
{
	if(chk[tr[X]])
	{
		cou[a[tr[X]]]--;
		
		if(!cou[a[tr[X]]])
			ans--;
	}
	
	else
	{
		cou[a[tr[X]]]++;
		
		if(cou[a[tr[X]]] == 1)
			ans++;
	}
	
	chk[tr[X]] ^= 1;
}

ll LCA(ll X, ll Y)
{
	if(dep[X] < dep[Y])
		swap(X, Y);
	
	ll cha = dep[X] - dep[Y];
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if((1LL << i) <= cha)
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
	
	dfs0(1, 0);
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	cin >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> q[i].u >> q[i].v;
		
		q[i].num = i;
		q[i].lca = LCA(q[i].u, q[i].v);
		
		if(IN[q[i].u] > IN[q[i].v])
			swap(q[i].u, q[i].v);
		
		if(q[i].lca != q[i].u && q[i].lca != q[i].v)
		{
			q[i].L = OUT[q[i].u];
			q[i].R = IN[q[i].v];
		}
		
		else
		{
			q[i].L = IN[q[i].u];
			q[i].R = IN[q[i].v];
		}
	}
	
	sq = cc / sqrt(m);
	sort(q + 1, q + 1 + m);
	
	for(ll i = q[1].L ; i <= q[1].R ; i++)
		add(i);
	
	if(q[1].lca != q[1].u && q[1].lca != q[1].v)
	{
		add(IN[q[1].lca]);
		ans2[q[1].num] = ans;
		add(IN[q[1].lca]);
	}
	
	else
		ans2[q[1].num] = ans;
	
	l = q[1].L, r = q[1].R;
	
	for(ll i = 2 ; i <= m ; i++)
	{
		ll ff = 0;
		
		if(q[i].lca != q[i].u && q[i].lca != q[i].v)
			ff = 1;
		
		while(r < q[i].R)
		{
			r++;
			add(r);
		}
		
		while(q[i].L < l)
		{
			l--;
			add(l);
		}
		
		while(l < q[i].L)
		{
			add(l);
			l++;
		}
		
		while(q[i].R < r)
		{
			add(r);
			r--;
		}
		
		if(ff)
			add(IN[q[i].lca]);
		
		ans2[q[i].num] = ans;
		
		if(ff)
			add(IN[q[i].lca]);
	}
	
	for(ll i = 1 ; i <= m ; i++)
		cout << ans2[i] en;
	
	return 0;
}