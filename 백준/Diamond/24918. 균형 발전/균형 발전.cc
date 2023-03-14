#include <bits/stdc++.h>
#pragma GCC optimize("O3") 
#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target("avx,avx2,fma") 

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
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n;
ll all, bll, cll;
vector<ll> fir1, fir2;
vector< pair<ll, ll> > vec[200010];
ll PPP[200010];
ll T[200010], tmm[200010];
ll C[200010], R[200010], X[200010];
ll dep[200010];
ll mid;
ll ans[200010];
vector<ll> zip, hwal;
ll deg[200010];
ll yu[200010];
ll PA[200010];
ll chkk[200010], cc;
ll siz;

struct fenwicktree
{
	ll bit[1000010];
	
	void update(ll p, ll v)
	{
		for(ll i = p ; i <= siz ; i += (i & (-i)))
			bit[i] += v;
	}
	
	long long query(ll p)
	{
		ll ret = 0;
		
		for(ll i = p ; i >= 1 ; i -= (i & (-i)))
			ret += bit[i];
		
		return ret;
	}
}BIT;

void dfs0(ll here, ll pa)
{
	PPP[here] = pa;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		dep[i.fi] = dep[here] + i.se;
		dfs0(i.fi, here);
	}
}

ll get_num(ll X)
{
	return lower_bound(zip.begin(), zip.end(), X) - zip.begin() + 1;
}

void dfs(ll here, ll pa)
{
	ll gap = get_num(dep[here]);
	ll gap2 = get_num(dep[here] + R[here] + 1);
	ll ff = 0;
	
	yu[here] = BIT.query(gap);
	
	if(tmm[here] <= mid || yu[here] >= C[here])
	{
		hwal.push_back(here);
		chkk[here] = cc;
		BIT.update(gap, X[here]);
		BIT.update(gap2, -X[here]);
		ff = 1;
	}
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		dfs(i.fi, here);
	}
	
	if(ff)
	{
		BIT.update(gap, -X[here]);
		BIT.update(gap2, X[here]);
	}
}

void dfs2(ll here, ll pa, ll chch, ll last, ll last2)
{
	if(chkk[here] == chch)
	{
		PA[here] = last;
		last = here;
	}
	
	if(chkk[here] == chch + 1)
	{
		PA[here] = last2;
		last2 = here;
	}
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		dfs2(i.fi, here, chch, last, last2);
	}
}

void f(vector<ll> &V, vector<ll> &P, ll s, ll e)
{
	if(s > e)
		return;
	
	if(s == e)
	{
		for(auto &i : V)
			ans[i] = s;
		
		return;
	}
	
	for(auto &i : V)
	{
		vec[i].clear();
		deg[i] = 0;
	}
	
	for(ll i = 0 ; i < (ll)V.size() ; ++i)
	{
		if(!P[i])
			continue;
		
		vec[P[i]].push_back({V[i], dep[V[i]] - dep[P[i]]});
		deg[V[i]]++;
	}
	
	mid = (s + e) >> 1;
	
	cc += 2;
	
	for(auto &i : V)
	{
		if(!deg[i])
			dfs(i, 0);
	}
	
	//cout << mid en;
	
	for(auto &i : V)
	{
		if(chkk[i] != cc)
			chkk[i] = cc + 1;
	}
	
	for(auto &i : V)
	{
		if(!deg[i])
			dfs2(i, 0, cc, 0, 0);
	}
	
	vector<ll> XX, PX, YY, PY;
	
	for(auto &i : V)
	{
		if(chkk[i] == cc + 1)
		{
			YY.push_back(i);
			PY.push_back(PA[i]);
			C[i] -= yu[i];
		}
		
		else
		{
			XX.push_back(i);
			PX.push_back(PA[i]);
		}
	}
	
	f(XX, PX, s, (s + e) >> 1);
	f(YY, PY, ((s + e) >> 1) + 1, e);
}

int main(void)
{
	fastio
	
	cin >> n;
	//asdfsadfasdfsafddf
	for(ll i = 1 ; i < n ; ++i)
	{
		cin >> all >> bll >> cll;
		
		vec[all].emplace_back(bll, cll);
		vec[bll].emplace_back(all, cll);
	}
	
	for(ll i = 1 ; i <= n ; ++i)
	{
		cin >> T[i];
		tmm[T[i]] = i;
	}
	
	for(ll i = 1 ; i <= n ; ++i)
		cin >> C[i] >> R[i] >> X[i];
	
	dfs0(1, 0);
	
	for(ll i = 1 ; i <= n ; ++i)
	{
		fir1.push_back(i);
		fir2.push_back(PPP[i]);
	}
	
	for(ll i = 1 ; i <= n ; ++i)
	{
		//cout << i sp << ": ";
		//cout << dep[i] sp;
		//cout << dep[i] + R[i] en;
		zip.push_back(dep[i]);
		zip.push_back(dep[i] + R[i] + 1);
	}
	
	compress(zip);
	
	siz = (ll)zip.size();
	
	f(fir1, fir2, 1, n);
	
	for(ll i = 1 ; i <= n ; ++i)
		cout << ans[i] sp;
	
	return 0;
}