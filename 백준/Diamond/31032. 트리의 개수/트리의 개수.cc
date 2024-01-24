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

ll n, K;
ll a[300010];
ll all, bll;
vector<ll> vec[300010];
ll ss = 998244353;
ll dp1[300010], dp2[300010], dp3[300010];
ll par[300010], ra[300010], G[300010];
ll dep[300010];
pll b[300010];
ll chk[300010], now, ans;

void dfs(ll here, ll pa)
{
	dp1[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dep[i] = dep[here] + 1;
		dfs(i, here);
		dp1[here] = dp1[here] * (dp1[i] + 1) % ss;
	}
	
	dp2[here] = dp1[here];
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dp2[here] = (dp2[here] + dp2[i]) % ss;
	}
}

void dfs2(ll here, ll pa, ll P, ll H)
{
	dp3[here] = H;
	
	vector<ll> pre, suf;
	ll sum = 0;
	
	for(ll i = 0 ; i < (ll)vec[here].size() ; i++)
	{
		if(vec[here][i] == pa)
		{
			pre.push_back(1);
			suf.push_back(1);
			continue;
		}
		
		sum = (sum + dp2[vec[here][i]]) % ss;
		pre.push_back(dp1[vec[here][i]] + 1);
		suf.push_back(dp1[vec[here][i]] + 1);
	}
	
	for(ll i = 1 ; i < (ll)pre.size() ; i++)
		pre[i] = pre[i] * pre[i - 1] % ss;
	
	for(ll i = (ll)suf.size() - 2 ; i >= 0 ; i--)
		suf[i] = suf[i + 1] * suf[i] % ss;
	
	for(ll i = 0 ; i < (ll)vec[here].size() ; i++)
	{
		if(vec[here][i] == pa)
			continue;
		
		ll P2 = 0, H2 = 0;
		ll gap = 1;
		
		if(i > 0)
			gap = gap * pre[i - 1] % ss;
		
		if(i < (ll)vec[here].size() - 1)
			gap = gap * suf[i + 1] % ss;
		
		P2 = (P + 1) * gap % ss;
		H2 = (H + P2 + sum - dp2[vec[here][i]]) % ss;
		
		dfs2(vec[here][i], here, P2, H2);
	}
}

ll ffind(ll X)
{
	if(X == par[X])
		return X;
	
	return par[X] = ffind(par[X]);
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	if(X == Y)
		return;
	
	if(ra[X] < ra[Y])
		par[X] = Y;
	else if(ra[X] > ra[Y])
		par[Y] = X;
	
	else
	{
		par[X] = Y;
		ra[Y]++;
	}
}

void merge(ll X, ll Y)
{
	if(dep[X] > dep[Y])
		swap(X, Y);
	
	ll paX = ffind(X);
	ll paY = ffind(Y);
	ll gapX = G[paX];
	ll gapY = G[paY];
	
	now = (now - dp2[1] + G[paX]) % ss;
	now = (now - dp2[1] + G[paY]) % ss;
	
	uunion(X, Y);
	
	G[ffind(X)] = (G[paX] - dp2[Y] + G[paY] - dp3[Y]) % ss;
	now = (now + dp2[1] - G[ffind(X)]) % ss;
}

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		b[i] = {a[i], i};
	}
	
	sort(b + 1, b + 1 + n);
	reverse(b + 1, b + 1 + n);
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	dfs(1, 0);
	dfs2(1, 0, 0, 0);
	
	for(ll i = 1 ; i <= n ; i++)
		par[i] = i;
	
	for(ll o = 1 ; o <= n ; o++)
	{
		if(1 < o && b[o].fi != b[o - 1].fi)
			ans = (ans + now * (b[o - 1].fi - b[o].fi) % ss) % ss;
		
		ll i = b[o].se;
		
		chk[i] = 1;
		
		for(auto &j : vec[i])
		{
			if(dep[j] < dep[i])
				G[i] = (G[i] + dp3[i]) % ss;
			else
				G[i] = (G[i] + dp2[j]) % ss;
		}
		
		now = (now + dp2[1] - G[i]) % ss;
		
		for(auto &j : vec[i])
		{
			if(chk[j])
				merge(i, j);
		}
	}
	
	if(b[n].fi != 1)
		ans = (ans + (b[n].fi - 1) * dp2[1] % ss) % ss;
	
	ans = (ans + ss) % ss;
	
	cout << ans;
	return 0;
}