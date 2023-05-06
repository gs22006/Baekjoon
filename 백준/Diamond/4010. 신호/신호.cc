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

ll n;
pll a[1510];
ll gaet1, gaet2;
ll sum;

struct dot
{
	ll x, y;
	
	bool operator < (const dot &xx) const
	{
		ld A1 = 0, A2 = 0;
		
		if(x == 0)
			A1 = INF;
		else
			A1 = (ld)y / (ld)x;
		
		if(xx.x == 0)
			A2 = INF;
		else
			A2 = (ld)xx.y / (ld)xx.x;
		
		return A1 > A2;
	}
};

ll f(ll X)
{
	vector<dot> vec;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(i == X)
			continue;
		
		vec.push_back({a[i].fi - a[X].fi, a[i].se - a[X].se});
	}
	
	sort(vec.begin(), vec.end());
	
	ll L = 0, R = 0;
	ll ret = (n - 1) * (n - 2) * (n - 3) / 6;
	ll cou = 0;
	
	for(auto &i : vec)
	{
		if(i.x == 0)
		{
			if(i.y > 0)
				R++;
			else
				L++;
		}
		
		else if(i.x < 0)
			L++;
		else
			R++;
	}
	
	for(auto &i : vec)
	{
		if(i.x == 0)
		{
			if(i.y > 0)
			{
				R--;
				cou += L * (L - 1) / 2;
				cou += R * (R - 1) / 2;
				L++;
			}
			
			else
			{
				L--;
				cou += L * (L - 1) / 2;
				cou += R * (R - 1) / 2;
				R++;
			}
		}
		
		else if(i.x < 0)
		{
			L--;
			cou += L * (L - 1) / 2;
			cou += R * (R - 1) / 2;
			R++;
		}
		
		else
		{
			R--;
			cou += L * (L - 1) / 2;
			cou += R * (R - 1) / 2;
			L++;
		}
	}
	
	ret -= cou / 2;
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	
	for(ll i = 1 ; i <= n ; i++)
		gaet1 += f(i);
	
	gaet2 = n * (n - 1) * (n - 2) * (n - 3) / 24 - gaet1;
	sum = 3 * n * (n - 1) * (n - 2) / 6 + gaet1 + gaet2 * 2;
	
	cout << (ld)sum / (ld)(n * (n - 1) * (n - 2) / 6);
	return 0;
}