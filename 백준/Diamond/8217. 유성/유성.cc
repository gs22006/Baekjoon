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
ll o[300010];
ll p[300010];
ll q;
pair<pll, ll> qry[300010];
vector<ll> hmm[300010];
vector<ll> W[300010];
ll L[300010], R[300010], mid[300010];

struct fenwicktree
{
	ll seg[300010];
	
	void init(void)
	{
		for(ll i = 1 ; i <= m ; i++)
			seg[i] = 0;
	}
	
	void update(ll w, ll v)
	{
		for(ll i = w ; i <= m ; i += (i & (-i)))
			seg[i] += v;
	}
	
	ll query(ll X)
	{
		ll ret = 0;
		
		for(ll i = X ; i >= 1 ; i -= (i & (-i)))
			ret += seg[i];
		
		return ret;
	}
}BIT;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> o[i];
		W[o[i]].push_back(i);
	}
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> p[i];
	
	cin >> q;
	
	for(ll i = 1 ; i <= q ; i++)
		cin >> qry[i].fi.fi >> qry[i].fi.se >> qry[i].se;
	
	for(ll i = 1 ; i <= n ; i++)
		L[i] = 1, R[i] = q;
	
	for(ll oo = 0 ; oo < 20 ; oo++)
	{
		BIT.init();
		
		for(ll i = 1 ; i <= n ; i++)
			mid[i] = (L[i] + R[i]) >> 1;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(L[i] <= R[i])
				hmm[mid[i]].push_back(i);
		}
		
		for(ll i = 1 ; i <= q ; i++)
		{
			if(qry[i].fi.fi <= qry[i].fi.se)
			{
				BIT.update(qry[i].fi.fi, qry[i].se);
				BIT.update(qry[i].fi.se + 1, -qry[i].se);
			}
			
			else
			{
				BIT.update(qry[i].fi.fi, qry[i].se);
				BIT.update(1, qry[i].se);
				BIT.update(qry[i].fi.se + 1, -qry[i].se);
			}
			
			while(!hmm[i].empty())
			{
				ll ww = hmm[i].back();
				hmm[i].pop_back();
				ll sum = 0;
				
				for(auto &j : W[ww])
				{
					sum += BIT.query(j);
					
					if(sum >= p[ww])
						break;
				}
				
				if(sum < p[ww])
					L[ww] = mid[ww] + 1;
				else
					R[ww] = mid[ww] - 1;
			}
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(L[i] == q + 1)
			cout << "NIE\n";
		else
			cout << L[i] en;
	}
	
	return 0;
}