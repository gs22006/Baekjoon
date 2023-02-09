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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(2);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n;
ll all, bll;
vector<pll> vec;
ll saf;

ll ccw(pll X, pll Y, pll Z)
{
	return X.fi * Y.se + Y.fi * Z.se + Z.fi * X.se - X.se * Y.fi - Y.se * Z.fi - Z.se * X.fi;
}

vector<pll> getcvh(vector<pll> X)
{
	vector<pll> ret;
	vector<pll> h1, h2;
	
	sort(X.begin(), X.end());
	
	ll sz = (ll)X.size();
	
	h1.push_back(X[0]);
	h1.push_back(X[1]);
	
	for(ll i = 2 ; i < sz ; i++)
	{
		while(1)
		{
			ll siz = (ll)h1.size();
			
			if(siz < 2 || ccw(h1[siz - 2], h1[siz - 1], X[i]) > 0)
				break;
			
			h1.pop_back();
		}
		
		h1.push_back(X[i]);
	}
	
	h2.push_back(X[sz - 1]);
	h2.push_back(X[sz - 2]);
	
	for(ll i = sz - 3 ; i >= 0 ; i--)
	{
		while(1)
		{
			ll siz = (ll)h2.size();
			
			if(siz < 2 || ccw(h2[siz - 2], h2[siz - 1], X[i]) > 0)
				break;
			
			h2.pop_back();
		}
		
		h2.push_back(X[i]);
	}
	
	for(auto &i : h1)
		ret.push_back(i);
	
	for(auto &i : h2)
	{
		if(ret.back() == i)
			continue;
		
		ret.push_back(i);
	}
	
	ret.pop_back();
	return ret;
}

int main(void)
{
	fastio
	
	while(1)
	{
		vec.clear();
		
		cin >> n;
		
		if(!n)
			break;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			cin >> all >> bll;
			vec.push_back({all, bll});
		}
		
		vector<pll> cvh = getcvh(vec);
		ll siz = (ll)cvh.size();
		ld ans = INF;
		
		cvh.push_back(cvh[0]);
		
		for(ll i = 0 ; i < siz ; i++)
		{
			ld maxx = -INF;
			
			if(cvh[i].fi == cvh[i + 1].fi)
			{
				for(ll j = 0 ; j < n ; j++)
					maxx = max(maxx, (ld)abs(vec[j].fi - cvh[i].fi));
				
				ans = min(ans, maxx);
			}
			
			else
			{
				ld A = (ld)(cvh[i].se - cvh[i + 1].se) / (ld)(cvh[i].fi - cvh[i + 1].fi);
				ld B = -1;
				ld C = (ld)cvh[i].se - A * (ld)cvh[i].fi;
				
				for(ll j = 0 ; j < n ; j++)
					maxx = max(maxx, (ld)abs(A * vec[j].fi + B * vec[j].se + C) / sqrt(A * A + B * B));
				
				ans = min(ans, maxx);
			}
		}
		
		ans = ceil(ans * 100.0) / 100.0;
		cout << "Case " << ++saf << ": " << ans en;
	}
	
	return 0;
}