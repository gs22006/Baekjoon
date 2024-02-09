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

struct gujo
{
	ll X, Y, Z, typ, idx;
	
	bool operator < (const gujo &xx) const
	{
		if(Z == xx.Z)
			return typ < xx.typ;
		
		return Z > xx.Z;
	}
};

ll n, q;
ll all, bll, cll;
vector<gujo> vec;
ll ans[400010];
ll siz;
ll siz2;

struct fenwicktree
{
	ll bit[400010];
	
	void init(ll SIZ)
	{
		for(ll i = 0 ; i <= SIZ ; i++)
			bit[i] = 0;
	}
	
	void update(ll w, ll v)
	{
		for(ll i = w ; i <= siz2 ; i += (i & (-i)))
			bit[i] += v;
	}
	
	ll query(ll w)
	{
		ll ret = 0;
		
		for(ll i = w ; i > 0 ; i -= (i & (-i)))
			ret += bit[i];
		
		return ret;
	}
}BIT;

void f(ll L, ll R)
{
	if(L >= R)
		return;
	
	ll mid = (L + R) >> 1;
	vector<ll> zip;
	vector< pair<pll, pll> > vv;
	
	for(ll i = L ; i <= mid ; i++)
	{
		if(vec[i].typ == 1)
		{
			zip.push_back(vec[i].X);
			zip.push_back(vec[i].Y);
		}
	}
	
	for(ll i = mid + 1 ; i <= R ; i++)
	{
		if(vec[i].typ == 2)
		{
			zip.push_back(vec[i].X);
			zip.push_back(vec[i].Y);
		}
	}
	
	compress(zip);
	siz2 = (ll)zip.size();
	
	for(ll i = L ; i <= mid ; i++)
	{
		if(vec[i].typ == 2)
			continue;
		
		ll x = lower_bound(zip.begin(), zip.end(), vec[i].X) - zip.begin() + 1;
		ll y = lower_bound(zip.begin(), zip.end(), vec[i].Y) - zip.begin() + 1;
		
		vv.push_back({{x, -1}, {y, -1}});
	}
	
	for(ll i = mid + 1 ; i <= R ; i++)
	{
		if(vec[i].typ == 1)
			continue;
		
		ll x = lower_bound(zip.begin(), zip.end(), vec[i].X) - zip.begin() + 1;
		ll y = lower_bound(zip.begin(), zip.end(), vec[i].Y) - zip.begin() + 1;
		
		vv.push_back({{x, -2}, {y, vec[i].idx}});
	}
	
	sort(vv.begin(), vv.end());
	reverse(vv.begin(), vv.end());
	
	for(auto &i : vv)
	{
		if(i.fi.se == -2)
			ans[i.se.se] += BIT.query(siz2) - BIT.query(i.se.fi - 1);
		else
			BIT.update(i.se.fi, 1);
	}
	
	BIT.init(siz2);
	
	f(L, mid);
	f(mid + 1, R);
}

int main(void)
{
	fastio
	
	cin >> n >> q;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all >> bll;
		vec.push_back({all, bll, all + bll, 1, i});
	}
	
	for(ll i = 1 ; i <= q ; i++)
	{
		cin >> all >> bll >> cll;
		vec.push_back({all, bll, cll, 2, i});
	}
	
	sort(vec.begin(), vec.end());
	siz = (ll)vec.size();
	
	f(0, siz - 1);
	
	for(ll i = 1 ; i <= q ; i++)
		cout << ans[i] en;
	
	return 0;
}