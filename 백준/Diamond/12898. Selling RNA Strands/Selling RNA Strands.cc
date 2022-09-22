#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n, m;
char a[2000010];
ll num[30];
pair< pair<ll, ll>, pair<ll, ll> > qry[2000010];
vector< pair< pair<ll, ll>, pair<ll, ll> > > vec1, vec2;
ll ans[2000010];
ll poi[2000010][3];

struct TRIE
{
	vector<ll> trie[2000010];
	ll go[2000010][5];
	ll CC, CCC;
	ll ETT[2000010][3];
	
	void update(char S[], ll numm, ll d)
	{
		ll len = strlen(S);
		ll w = 0;
		
		for(ll i = 0 ; i < len ; i++)
		{
			if(go[w][num[S[i] - 'A']])
				w = go[w][num[S[i] - 'A']];
			
			else
			{
				go[w][num[S[i] - 'A']] = ++CC;
				trie[w].push_back(CC);
				trie[CC].push_back(w);
				w = CC;
			}
		}
		
		poi[numm][d] = w;
	}
	
	void ett(ll here, ll pa)
	{
		ETT[here][0] = ++CCC;
		
		for(auto &i : trie[here])
		{
			if(i == pa)
				continue;
			
			ett(i, here);
		}
		
		ETT[here][1] = CCC;
	}
	
	pair<ll, ll> query(ll here, char S[], ll p, ll len)
	{
		if(go[here][num[S[p] - 'A']])
		{
			here = go[here][num[S[p] - 'A']];
			p++;
			
			if(p == len)
				return {ETT[here][0], ETT[here][1]};
			
			return query(here, S, p, len);
		}
		
		else
			return {-1, -1};
	}
}pre, suf;

struct segtree
{
	ll seg[10000010];
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(w < s || e < w)
			return;
		
		if(s == e)
		{
			seg[no] += v;
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
}psegt, ssegt;

int main(void)
{
	scanf("%lld %lld", &n, &m);
	
	num['A' - 'A'] = 1;
	num['G' - 'A'] = 2;
	num['T' - 'A'] = 3;
	num['C' - 'A'] = 4;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		scanf("%s", a);
		
		ll len = strlen(a);
		
		pre.update(a, i, 0);
		reverse(a, a + len);
		suf.update(a, i, 1);
	}
	
	pre.ett(0, -1);
	suf.ett(0, -1);
	
	for(ll i = 1 ; i <= m ; i++)
	{
		scanf("%s", a);
		qry[i].fi = pre.query(0, a, 0, strlen(a));
		
		scanf("%s", a);
		
		ll len = strlen(a);
		
		reverse(a, a + len);
		qry[i].se = suf.query(0, a, 0, len);
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(qry[i].fi.fi == -1 || qry[i].se.fi == -1)
			continue;
		
		vec1.push_back({{qry[i].se.fi - 1, i}, qry[i].fi});
		vec2.push_back({{qry[i].se.se, i}, qry[i].fi});
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!poi[i][0])
			continue;
		
		vec1.push_back({{suf.ETT[poi[i][1]][0], -1}, {pre.ETT[poi[i][0]][0], -1}});
		vec2.push_back({{suf.ETT[poi[i][1]][0], -1}, {pre.ETT[poi[i][0]][0], -1}});
	}
	
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());
	
	for(auto &i : vec1)
	{
		if(i.fi.se == -1)
			psegt.update(1, 0, 2000001, i.se.fi, 1);
		
		else
		{
			ll num = i.fi.se;
			ans[num] -= psegt.query(1, 0, 2000001, i.se.fi, i.se.se);
		}
	}
	
	for(auto &i : vec2)
	{
		if(i.fi.se == -1)
			ssegt.update(1, 0, 2000001, i.se.fi, 1);
		
		else
		{
			ll num = i.fi.se;
			ans[num] += ssegt.query(1, 0, 2000001, i.se.fi, i.se.se);
		}
	}
	
	for(ll i = 1 ; i <= m ; i++)
		printf("%lld\n", ans[i]);
	
	return 0;
}