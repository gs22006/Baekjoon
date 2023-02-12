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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n;
pair<ll, ll> a[200010];
vector< pair<ll, ll> > cvh;
ll ans = MIN;
ll t;

ll ccw(pair<ll, ll> X, pair<ll, ll> Y, pair<ll, ll> Z)
{
	return X.fi * Y.se + Y.fi * Z.se + Z.fi * X.se - X.se * Y.fi - Y.se * Z.fi - Z.se * X.fi;
}

void solve(void)
{
	vector< pair<ll, ll> > h1, h2;
	
	h1.push_back(a[1]);
	h1.push_back(a[2]);
	
	for(ll i = 3 ; i <= n ; i++)
	{
		while((ll)h1.size() >= 2 && ccw(h1[(ll)h1.size() - 2], h1[(ll)h1.size() - 1], a[i]) >= 0)
			h1.pop_back();
		
		h1.push_back(a[i]);
	}
	
	h2.push_back(a[n]);
	h2.push_back(a[n - 1]);
	
	for(ll i = n - 2 ; i >= 1 ; i--)
	{
		while((ll)h2.size() >= 2 && ccw(h2[(ll)h2.size() - 2], h2[(ll)h2.size() - 1], a[i]) >= 0)
			h2.pop_back();
		
		h2.push_back(a[i]);
	}
	
	for(auto &i : h1)
		cvh.push_back(i);
	
	for(auto &i : h2)
	{
		if(i == cvh.back())
			continue;
		
		cvh.push_back(i);
	}
	
	cvh.pop_back();
	return;
}

ll dist(pair<ll, ll> X, pair<ll, ll> Y)
{
	return (X.fi - Y.fi) * (X.fi - Y.fi) + (X.se - Y.se) * (X.se - Y.se);
}

ll cccw(pair<ll, ll> X1, pair<ll, ll> Y1, pair<ll, ll> X2, pair<ll, ll> Y2)
{
	ll Xcha = X2.fi - Y1.fi;
	ll Ycha = X2.se - Y1.se;
	
	X2.fi -= Xcha;
	X2.se -= Ycha;
	Y2.fi -= Xcha;
	Y2.se -= Ycha;
	
	return ccw(X1, Y1, Y2);
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		for(ll i = 1 ; i <= n ; i++)
			cin >> a[i].fi >> a[i].se;
		
		sort(a + 1, a + 1 + n);
		
		if(n == 2)
		{
			cout << a[1].fi sp << a[1].se sp << a[2].fi sp << a[2].se en;
			return 0;
		}
		
		cvh.clear();
		solve();
		
		reverse(cvh.begin(), cvh.end());
		
		ll p = 1;
		ll siz = (ll)cvh.size();
		ll ff = 0;
		ans = MIN;
		ll ans1 = 0, ans2 = 0;
		
		for(ll i = 0 ; i < siz ; i++)
			cvh.push_back(cvh[i]);
		
		siz *= 2;
		cvh.push_back({0, 0});
		
		for(ll i = 0 ; i < siz ; i++)
		{
			while((p + 1) % siz != i && cccw(cvh[i], cvh[i + 1], cvh[p % siz], cvh[(p + 1) % siz]) > 0)
			{
				if(ans < dist(cvh[i], cvh[p % siz]))
				{
					ans = dist(cvh[i], cvh[p % siz]);
					ans1 = i;
					ans2 = p % siz;
				}
				
				p++;
			}
			
			if(ans < dist(cvh[i], cvh[p % siz]))
			{
				ans = dist(cvh[i], cvh[p % siz]);
				ans1 = i;
				ans2 = p % siz;
			}
		}
		
		cout << cvh[ans1].fi sp << cvh[ans1].se sp << cvh[ans2].fi sp << cvh[ans2].se en;
	}
	
	return 0;
}