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

ll n;
pair<ll, ll> a[1000010];
ll dep[1000010];

ll bi_length(ll X)
{
	ll ret = 0;
	
	while(X)
	{
		ret++;
		X /= 2;
	}
	
	return ret;
}

pair<ll, ll> dfs(ll here)
{
	pair<ll, ll> L, R;
	ll depL = 0, depR = 0;
	
	if(a[here].fi < 0)
	{
		L.fi = -a[here].fi;
		L.se = 0;
		depL = 1;
	}
	
	else
	{
		L = dfs(a[here].fi);
		depL = dep[a[here].fi] + 1;
	}
	
	if(a[here].se < 0)
	{
		R.fi = -a[here].se;
		R.se = 0;
		depR = 1;
	}
	
	else
	{
		R = dfs(a[here].se);
		depR = dep[a[here].se] + 1;
	}
	
	ll lenL = bi_length(L.fi);
	ll lenR = bi_length(R.fi);
	pair<ll, ll> mx;
	ll maxx = max(depL, depR) - 1;
	
	dep[here] = maxx;
	
	if(lenL + L.se < lenR + R.se)
		mx = R;
	else if(lenL + L.se > lenR + R.se)
		mx = L;
	
	else
	{
		if(lenL < lenR)
		{
			for(ll i = 0 ; i < lenR - lenL ; i++)
				L.fi *= 2;
		}
		
		else
		{
			for(ll i = 0 ; i < lenL - lenR ; i++)
				R.fi *= 2;
		}
		
		mx = {max(L.fi, R.fi), min(L.se, R.se)};
	}
	
	while(mx.fi % 2 == 0)
	{
		mx.fi /= 2;
		mx.se++;
	}
	
	if(maxx > mx.se)
	{
		maxx -= mx.se;
		ll twoo = 1;
		
		for(ll i = 0 ; i < maxx ; i++)
			twoo *= 2;
		
		mx.fi = (mx.fi + twoo - 1) / twoo * twoo;
	}
	
	while(mx.fi % 2 == 0)
	{
		mx.fi /= 2;
		mx.se++;
	}
	
	mx.se++;
	return mx;
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	
	pair<ll, ll> ans = dfs(1);
	vector<ll> vec;
	
	while(ans.fi)
	{
		vec.push_back(ans.fi & 1);
		ans.fi /= 2;
	}
	
	reverse(vec.begin(), vec.end());
	
	for(ll i = 0 ; i < ans.se ; i++)
		vec.push_back(0);
	
	for(auto &i : vec)
		cout << i;
	
	return 0;
}