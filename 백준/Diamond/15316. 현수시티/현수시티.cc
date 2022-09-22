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

struct edge
{
	ll tL, tR, u, v;
};

ll n, m, q;
ll all, bll, cll;
map< pair<ll, ll>, ll> chk;
vector<edge> vec;
vector< pair<ll, ll> > qry, edg, cov[800010];
ll cc = -1;
ll pa[200010], ra[200010];
stack< pair< pair<ll, ll>, ll> > stk;
ll ans[200010];

ll ffind(ll here)
{
	if(pa[here] == here)
		return here;
	
	return ffind(pa[here]);
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	if(X == Y)
		return;
	
	if(ra[X] < ra[Y])
	{
		stk.push({{X, Y}, 0});
		pa[X] = Y;
	}
	
	else if(ra[Y] < ra[X])
	{
		stk.push({{Y, X}, 0});
		pa[Y] = X;
	}
	
	else
	{
		stk.push({{X, Y}, 1});
		pa[X] = Y;
		ra[Y]++;
	}
}

void init(ll no, ll s, ll e, ll num)
{
	if(e < vec[num].tL || vec[num].tR < s)
		return;
		
	if(vec[num].tL <= s && e <= vec[num].tR)
	{
		cov[no].push_back({vec[num].u, vec[num].v});
		return;
	}
	
	if(s == e)
		return;
	
	init(no * 2, s, (s + e) / 2, num);
	init(no * 2 + 1, (s + e) / 2 + 1, e, num);
}

void rollback(ll siz)
{
	while(siz--)
	{
		pair< pair<ll, ll>, ll> tp = stk.top();
		stk.pop();
		
		pa[tp.fi.fi] = tp.fi.fi;
		
		if(tp.se)
			ra[tp.fi.se]--;
	}
}

void solve(ll no, ll s, ll e)
{
	ll cou = 0;
	
	for(auto &i : cov[no])
	{
		if(ffind(i.fi) != ffind(i.se))
		{
			uunion(i.fi, i.se);
			cou++;
		}
	}
	
	if(s == e)
	{
		if(ffind(qry[s].fi) == ffind(qry[s].se))
			ans[s] = 1;
		else
			ans[s] = 0;
		
		rollback(cou);
		return;
	}
	
	solve(no * 2, s, (s + e) / 2);
	solve(no * 2 + 1, (s + e) / 2 + 1, e);
	
	rollback(cou);
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> bll >> cll;
		
		if(bll > cll)
			swap(bll, cll);
		
		edg.push_back({bll, cll});
		chk[{bll, cll}] = -1;
	}
	
	for(ll i = 0 ; i < m ; i++)
	{
		cin >> all;
		
		if(all)
			chk[edg[i]] = cc + 1;
	}
	
	cin >> q;
	
	while(q--)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> bll;
			
			bll--;
			
			if(chk[edg[bll]] != -1)
			{
				vec.push_back({chk[edg[bll]], cc, edg[bll].fi, edg[bll].se});
				chk[edg[bll]] = -1;
			}
			
			else
				chk[edg[bll]] = cc + 1;
		}
		
		else
		{
			cin >> bll >> cll;
			
			if(bll > cll)
				swap(bll, cll);
			
			cc++;
			qry.push_back({bll, cll});
		}
	}
	
	for(auto &i : edg)
	{
		if(chk[i] != -1)
		{
			vec.push_back({chk[i], cc, i.fi, i.se});
			chk[i] = -1;
		}
	}
	
	for(ll i = 0 ; i < (ll)vec.size() ; i++)
	{
		if(vec[i].tL > vec[i].tR)
			continue;
		
		init(1, 0, cc, i);
	}
	
	for(ll i = 1 ; i <= n ; i++)
		pa[i] = i;
	
	solve(1, 0, cc);
	
	for(ll i = 0 ; i <= cc ; i++)
		cout << (ans[i] ? "YES\n" : "NO\n");
	
	return 0;
}