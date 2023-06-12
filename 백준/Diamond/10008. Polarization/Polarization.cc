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
ll all, bll;
vector<ll> vec[1000010];
ll siz[1000010];
ll rt;
ll dep[1000010];
vector<ll> vv;
vector<pll> gap;
ll ans;
bitset<1000010> dp;

void dfs0(ll here, ll pa)
{
	siz[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs0(i, here);
		siz[here] += siz[i];
	}
}

ll get_centroid(ll here, ll pa, ll SIZ)
{
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		if(siz[i] * 2 > SIZ)
			return get_centroid(i, here, SIZ);
	}
	
	return here;
}

void dfs(ll here, ll pa)
{
	siz[here] = 1;
	dep[here] = dep[pa] + 1;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs(i, here);
		siz[here] += siz[i];
	}
}

int main(void)
{
	fastio
	
	cin >> n;
	
	if(n == 1)
	{
		cout << 0 sp << 0 en;
		return 0;
	}
	
	for(ll i = 2 ; i <= n ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	dfs0(1, 0);
	rt = get_centroid(1, 0, siz[1]);
	dfs(rt, 0);
	
	for(auto &i : vec[rt])
		vv.push_back(siz[i]);
	
	sort(vv.begin(), vv.end());
	
	ll cou = 1;
	
	for(ll i = 1 ; i < (ll)vv.size() ; i++)
	{
		if(vv[i] != vv[i - 1])
		{
			gap.push_back({vv[i - 1], cou});
			cou = 1;
		}
		
		else
			cou++;
	}
	
	gap.push_back({vv.back(), cou});
	
	dp.set(0, true);
	
	for(auto &i : gap)
	{
		for(ll j = 0 ; j <= 20 ; j++)
		{
			if((1LL << j) <= i.se)
			{
				dp |= (dp << ((1LL << j) * i.fi));
				i.se -= (1LL << j);
			}
		}
		
		dp |= (dp << (i.se * i.fi));
	}
	
	for(ll i = 0 ; i < 1000010 ; i++)
	{
		if(dp[i])
			ans = max(ans, i * (n - 1 - i));
	}
	
	for(ll i = 1 ; i <= n ; i++)
		ans += dep[i];
	
	cout << n - 1 sp << ans - n;
	return 0;
}