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

ll n, m;
ll a[100010], b[100010];
pll qry[100010];
ll nu[100010], T[100010];
ll gap[100010];
ll ans[100010];
vector<ll> W[100010];

ll ccw(pll X, pll Y, pll Z)
{
	return (X.fi * Y.se + Y.fi * Z.se + Z.fi * X.se) - (X.se * Y.fi + Y.se * Z.fi + Z.se * X.fi);
}

struct upperhull
{
	pll pnt[100010];
	ll siz;
	
	void init(void)
	{
		siz = 0;
		return;
	}
	
	void update(pll X)
	{
		if(siz <= 1)
		{
			pnt[siz++] = X;
			return;
		}
		
		while(siz >= 2 && ccw(pnt[siz - 2], pnt[siz - 1], X) >= 0)
			siz--;
		
		pnt[siz++] = X;
	}
	
	ll query(pll X)
	{
		if(siz == 1)
			return (X.se - pnt[0].se) / (X.fi - pnt[0].fi);
		
		ll l = 0, r = siz - 2;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if((pnt[mid + 1].se - pnt[mid].se) / (pnt[mid + 1].fi - pnt[mid].fi) <= (X.se - pnt[mid].se) / (X.fi - pnt[mid].fi))
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		return (X.se - pnt[l].se) / (X.fi - pnt[l].fi);
	}
}Uhull;

vector<int> testset(vector<int> A, vector<int> B, vector<int> L, vector<int> U)
{
	n = (ll)A.size();
	
	for(ll i = 1 ; i <= n ; i++)
		a[i] = A[i - 1];
	
	for(ll i = 2 ; i <= n ; i++)
		b[i] = B[i - 2];
	
	m = (ll)L.size();
	
	for(ll i = 0 ; i < m ; i++)
	{
		qry[i + 1] = {L[i] + 1, U[i] + 1};
		W[qry[i + 1].se].push_back(i + 1);
	}
	
	for(ll i = 1 ; i <= n ; i++)
		nu[i] = nu[i - 1] + a[i] + b[i];
	
	for(ll i = 1 ; i <= n ; i++)
		T[i] = nu[i] + b[i + 1];
	
	Uhull.init();
	Uhull.update({0, 0});
	
	for(ll i = 1 ; i <= n ; i++)
	{
		gap[i] = Uhull.query({i, T[i]});
		Uhull.update({i, nu[i]});
	}
	
	ll minn = INF;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		minn = min(minn, gap[i]);
		
		for(auto &j : W[i])
			ans[j] = minn;
	}
	
	vector<int> ret;
	
	for(ll i = 1 ; i <= m ; i++)
		ret.push_back(ans[i]);
	
	return ret;
}