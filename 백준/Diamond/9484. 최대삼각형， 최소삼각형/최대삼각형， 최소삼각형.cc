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
pll a[2010];
ll ord[2010];
ll w[2010];
ll ans1, ans2;

struct line
{
	ll P1, P2;
	ll dx, dy;
	
	bool operator < (const line &xx) const
	{
		if(dy * xx.dx == xx.dy * dx)
		{
			if(P1 == xx.P1)
				return P2 < xx.P2;
			
			return P1 < xx.P1;
		}
		
		return dy * xx.dx < xx.dy * dx;
	}
};

vector<line> vec;

void calc(ll I1, ll I2, ll I3)
{
	ll gap = abs(a[I1].fi * a[I2].se + a[I2].fi * a[I3].se + a[I3].fi * a[I1].se - a[I1].se * a[I2].fi - a[I2].se * a[I3].fi - a[I3].se * a[I1].fi);
	
	ans1 = min(ans1, gap);
	ans2 = max(ans2, gap);
}

int main(void)
{
	fastio
	
	while(1)
	{
		cin >> n;
		
		if(!n)
			break;
		
		vec.clear();
		
		for(ll i = 1 ; i <= n ; i++)
			cin >> a[i].fi >> a[i].se;
		
		sort(a + 1, a + 1 + n);
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = i + 1 ; j <= n ; j++)
				vec.push_back({i, j, a[j].fi - a[i].fi, a[j].se - a[i].se});
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			ord[i] = i;
			w[i] = i;
		}
		
		sort(vec.begin(), vec.end());
		
		ans1 = MAX, ans2 = MIN;
		
		for(auto &i : vec)
		{
			ll w1 = w[i.P1];
			ll w2 = w[i.P2];
			
			swap(ord[w1], ord[w2]);
			swap(w[i.P1], w[i.P2]);
			
			ll idx;
			
			idx = w1 - 1;
			
			if(1 <= idx && idx <= n && idx != w1 && idx != w2)
				calc(ord[w1], ord[w2], ord[idx]);
			
			idx = w1 + 1;
			
			if(1 <= idx && idx <= n && idx != w1 && idx != w2)
				calc(ord[w1], ord[w2], ord[idx]);
			
			idx = w2 - 1;
			
			if(1 <= idx && idx <= n && idx != w1 && idx != w2)
				calc(ord[w1], ord[w2], ord[idx]);
			
			idx = w2 + 1;
			
			if(1 <= idx && idx <= n && idx != w1 && idx != w2)
				calc(ord[w1], ord[w2], ord[idx]);
			
			idx = 1;
			
			if(1 <= idx && idx <= n && idx != w1 && idx != w2)
				calc(ord[w1], ord[w2], ord[idx]);
			
			idx = n;
			
			if(1 <= idx && idx <= n && idx != w1 && idx != w2)
				calc(ord[w1], ord[w2], ord[idx]);
		}
		
		if(ans1 & 1)
			cout << ans1 / 2 << ".5 ";
		else
			cout << ans1 / 2 << ".0 ";
		
		if(ans2 & 1)
			cout << ans2 / 2 << ".5\n";
		else
			cout << ans2 / 2 << ".0\n";
	}
	
	return 0;
}