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

ll n, B;
ll q;
ll a[5010];
ll chk[5010];
ll all, bll;
vector<ll> vec[5010];
ll dp1[5010][5010], dp2[5010][5010];
ll cou[5010];
ll tmp1[5010], tmp2[5010];
ll mini[5010], maxi[5010];
ll ans;

void dfs0(ll here, ll pa)
{
	cou[here] = chk[here];
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs0(i, here);
		cou[here] += cou[i];
	}
}

void dfs(ll here, ll pa)
{
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs(i, here);
	}
	
	ll siz = 1;
	
	if(chk[here])
	{
		dp1[here][0] = INF;
		dp1[here][1] = 1;
		dp2[here][0] = -INF;
		dp2[here][1] = 1;
	}
	
	else
	{
		dp1[here][0] = 1;
		dp1[here][1] = INF;
		dp2[here][0] = 1;
		dp2[here][1] = -INF;
	}
	
	for(auto &nxt : vec[here])
	{
		if(nxt == pa)
			continue;
		
		for(ll j = 0 ; j <= n ; j++)
		{
			tmp1[j] = dp1[here][j];
			tmp2[j] = dp2[here][j];
		}
		
		for(ll i = 0 ; i <= cou[nxt] ; i++)
		{
			for(ll j = 0 ; j <= siz ; j++)
			{
				tmp1[i + j] = min(tmp1[i + j], dp1[here][j] + dp1[nxt][i]);
				tmp2[i + j] = max(tmp2[i + j], dp2[here][j] + dp2[nxt][i]);
			}
		}
		
		for(ll j = 0 ; j <= n ; j++)
		{
			dp1[here][j] = tmp1[j];
			dp2[here][j] = tmp2[j];
		}
		
		siz += cou[nxt];
	}
}

int main(void)
{
	fastio
	
	cin >> n >> B;
	
	for(ll i = 1 ; i <= B ; i++)
	{
		cin >> a[i];
		chk[a[i]] = 1;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= n ; j++)
			dp1[i][j] = INF, dp2[i][j] = -INF;
	}
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	dfs0(1, 0);
	dfs(1, 0);
	
	for(ll i = 0 ; i <= n ; i++)
		mini[i] = INF, maxi[i] = -INF;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= n ; j++)
		{
			//cout << "(" << dp1[i][j] sp << dp2[i][j] << ") ";
			mini[j] = min(mini[j], dp1[i][j]);
			maxi[j] = max(maxi[j], dp2[i][j]);
		}
		
		//cout en;
	}
	
	cin >> q;
	
	while(q--)
	{
		cin >> bll >> all;
		
		if(mini[all] <= bll && bll <= maxi[all])
			ans++;
	}
	
	cout << ans;
	return 0;
}