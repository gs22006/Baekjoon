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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

struct star
{
	ll x, y, dx, dy;
};

ll n, T;
star a[30010];
ll l, r;
ll ans1 = INF, ans2 = -1;

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

ll dist(pll X, pll Y)
{
	return (X.fi - Y.fi) * (X.fi - Y.fi) + (X.se - Y.se) * (X.se - Y.se);
}

ll cccw(pll X1, pll Y1, pll X2, pll Y2)
{
	ll xcha = X2.fi - Y1.fi;
	ll ycha = X2.se - Y1.se;
	
	Y2.fi -= xcha;
	Y2.se -= ycha;
	
	return ccw(X1, Y1, Y2);
}

ll rotcali(vector<pll> X)
{
	ll siz = (ll)X.size();
	ll ret = MIN;
	
	if(siz == 2)
		return dist(X[0], X[1]);
	
	X.push_back({0, 0});
	
	ll p = 1;
	
	for(ll i = 0 ; i < siz ; i++)
	{
		while((p + 1) % siz != i && cccw(X[i], X[i + 1], X[p % siz], X[(p + 1) % siz]) > 0)
		{
			ret = max(ret, dist(X[i], X[p % siz]));
			p++;
		}
		
		ret = max(ret, dist(X[i], X[p % siz]));
	}
	
	return ret;
}

ll solve(ll X)
{
	vector< pair<ll, ll> > w;
	
	for(ll i = 1 ; i <= n ; i++)
		w.push_back({a[i].x + a[i].dx * X, a[i].y + a[i].dy * X});
	
	vector<pll> cvh = getcvh(w);
	ll ret = rotcali(cvh);
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n >> T;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].x >> a[i].y >> a[i].dx >> a[i].dy;
	
	l = 0;
	r = T;
	
	while(l <= r)
	{
		ll mid1 = (l * 2 + r) / 3;
		ll mid2 = (l + r * 2) / 3;
		ll gap1 = solve(mid1);
		ll gap2 = solve(mid2);
		
		if(gap1 > gap2)
			l = mid1 + 1;
		else
			r = mid2 - 1;
	}
	
	for(ll i = l - 5 ; i <= l + 5 ; i++)
	{
		if(0 <= i && i <= T)
		{
			ll gap = solve(i);
			
			if(ans1 > gap)
			{
				ans1 = gap;
				ans2 = i;
			}
		}
	}
	
	cout << ans2 en << ans1;
	return 0;
}