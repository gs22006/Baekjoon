#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

ll n;
ll q;
ll a[300010];
char all[210];
ll bll, cll;
vector< pair<ll, pair<ll, ll> > > qry;
vector<ll> vec[300010];
ll pa[300010], ra[300010];
ll dep[300010], IN[300010], p[300010], tp[300010], siz[300010];
ll cc;

struct segtree
{
	ll seg[1500010];
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no] = v;
			return;
		}
		
		update(no * 2, s, (s + e) / 2, w, v);
		update(no * 2 + 1, (s + e) / 2 + 1, e, w, v);
		
		seg[no] = seg[no * 2] + seg[no * 2 + 1];
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return query(no * 2, s, (s + e) / 2, l, r) + query(no * 2 + 1, (s + e) / 2 + 1, e, l, r);
	}
}segt;

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

void dfs1(ll here, ll P)
{
	siz[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(i == P)
			continue;
		
		dep[i] = dep[here] + 1;
		p[i] = here;
		dfs1(i, here);
		siz[here] += siz[i];
		
		if(siz[i] > siz[vec[here][0]])
			swap(i, vec[here][0]);
	}
}

void dfs2(ll here, ll P)
{
	IN[here] = ++cc;
	
	for(auto &i : vec[here])
	{
		if(i == P)
			continue;
		
		if(i == vec[here][0])
			tp[i] = tp[here];
		else
			tp[i] = i;
		
		dfs2(i, here);
	}
}

ll query(ll X, ll Y)
{
	ll ret = 0;
	
	while(tp[X] != tp[Y])
	{
		if(dep[tp[X]] < dep[tp[Y]])
			swap(X, Y);
		
		ll TP = tp[X];
		
		ret += segt.query(1, 1, cc, IN[TP], IN[X]);
		X = p[TP];
	}
	
	if(dep[X] > dep[Y])
		swap(X, Y);
	
	ret += segt.query(1, 1, cc, IN[X], IN[Y]);
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		pa[i] = i;
	}
	
	cin >> q;
	
	while(q--)
	{
		cin >> all >> bll >> cll;
		
		if(!strcmp(all, "bridge"))
			qry.push_back({1, {bll, cll}});
		else if(!strcmp(all, "penguins"))
			qry.push_back({2, {bll, cll}});
		else
			qry.push_back({3, {bll, cll}});
	}
	
	for(auto &i : qry)
	{
		if(i.fi == 1)
		{
			if(ffind(i.se.fi) == ffind(i.se.se))
				continue;
			
			uunion(i.se.fi, i.se.se);
			vec[i.se.fi].push_back(i.se.se);
			vec[i.se.se].push_back(i.se.fi);
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(dep[i])
			continue;
		
		dfs1(i, 0);
		dfs2(i, 0);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		segt.update(1, 1, cc, IN[i], a[i]);
		pa[i] = i;
		ra[i] = 0;
	}
	
	for(auto &i : qry)
	{
		if(i.fi == 1)
		{
			if(ffind(i.se.fi) == ffind(i.se.se))
				cout << "no\n";
			
			else
			{
				cout << "yes\n";
				uunion(i.se.fi, i.se.se);
			}
		}
		
		else if(i.fi == 2)
			segt.update(1, 1, cc, IN[i.se.fi], i.se.se);
		
		else
		{
			if(ffind(i.se.fi) != ffind(i.se.se))
			{
				cout << "impossible\n";
				continue;
			}
			
			cout << query(i.se.fi, i.se.se) en;
		}
	}
	
	return 0;
}