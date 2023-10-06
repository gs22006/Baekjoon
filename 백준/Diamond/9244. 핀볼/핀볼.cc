#include <bits/stdc++.h>
 
using namespace std;
typedef int ll;
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
	ll x1, y1, x2, y2;
	ll num;
	
	bool operator < (const gujo &xx) const
	{
		ll X;
		
		if(xx.x1 <= x1 && x1 <= xx.x2)
			X = x1;
		else if(xx.x1 <= x2 && x2 <= xx.x2)
			X = x2;
		else if(x1 <= xx.x1 && xx.x1 <= x2)
			X = xx.x1;
		else if(x1 <= xx.x2 && xx.x2 <= x2)
			X = xx.x2;
		
		ld A1 = (ld)(y2 - y1) / (x2 - x1);
		ld B1 = (ld)y1 - A1 * x1;
		ld A2 = (ld)(xx.y2 - xx.y1) / (xx.x2 - xx.x1);
		ld B2 = (ld)xx.y1 - A2 * xx.x1;
		
		return A1 * X + B1 > A2 * X + B2;
	}
};

struct gujo2
{
	ll X, typ, num;
	
	bool operator < (const gujo2 &xx) const
	{
		if(X != xx.X)
			return X < xx.X;
		
		return typ < xx.typ;
	}
};

ll n;
gujo a[100010];
ll x0;
ll GO[100010];
set<gujo> st;
vector<pll> vec;
vector<gujo2> vec2;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
		a[i].num = i;
		
		if(a[i].x1 > a[i].x2)
		{
			swap(a[i].x1, a[i].x2);
			swap(a[i].y1, a[i].y2);
		}
		
		vec2.push_back({a[i].x1, 1, i});
		vec2.push_back({a[i].x2, 3, i});
		
		if(a[i].y1 < a[i].y2)
			vec2.push_back({a[i].x1, 2, i});
		else
			vec2.push_back({a[i].x2, 2, i});
	}
	
	sort(vec2.begin(), vec2.end());
	
	cin >> x0;
	
	for(auto &k : vec2)
	{
		ll i = k.num;
		
		if(k.typ == 1)
			st.insert(a[i]);
		
		else if(k.typ == 2)
		{
			auto p = st.lower_bound(a[i]);
			p++;
			
			if(p != st.end())
				GO[i] = (*p).num;
		}
		
		else
			st.erase(a[i]);
	}
	
	ld maxx = -INF;
	ll idx = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i].x1 <= x0 && x0 <= a[i].x2)
		{
			ld A = (ld)(a[i].y2 - a[i].y1) / (a[i].x2 - a[i].x1);
			ld B = (ld)a[i].y1 - A * a[i].x1;
			
			if(maxx < A * x0 + B)
			{
				maxx = A * x0 + B;
				idx = i;
			}
		}
	}
	
	if(idx == 0)
		cout << x0;
	
	else
	{
		while(1)
		{
			if(GO[idx] == 0)
				break;
			
			idx = GO[idx];
		}
		
		if(a[idx].y1 < a[idx].y2)
			cout << a[idx].x1;
		else
			cout << a[idx].x2;
	}
	
	return 0;
}