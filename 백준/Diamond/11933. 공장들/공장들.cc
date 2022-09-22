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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

ll n, q;
ll all, bll, cll;
vector< pair<ll, ll> > vec[500010], vec2[500010];
vector<ll> tmp1, tmp2;
ll dp1[500010], dp2[500010];
ll IN[500010], OUT[500010];
ll spa[500010][21], hap[500010][21];
ll dep[500010];
ll cc;

void dfs(ll here, ll pa)
{
	IN[here] = ++cc;
	spa[here][0] = pa;
	dep[here] = dep[pa] + 1;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		hap[i.fi][0] = i.se;
		dfs(i.fi, here);
	}
	
	OUT[here] = cc;
}

ll LCA(ll X, ll Y)
{
	if(dep[X] < dep[Y])
		swap(X, Y);
	
	ll cha = dep[X] - dep[Y];
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if(cha >= (1LL << i))
		{
			cha -= (1LL << i);
			X = spa[X][i];
		}
	}
	
	if(X == Y)
		return X;
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if(spa[X][i] != spa[Y][i])
		{
			X = spa[X][i];
			Y = spa[Y][i];
		}
	}
	
	return spa[X][0];
}

ll cost(ll X, ll Y)
{
	if(dep[X] < dep[Y])
		swap(X, Y);
	
	ll cha = dep[X] - dep[Y];
	ll ret = 0;
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if(cha >= (1LL << i))
		{
			ret += hap[X][i];
			X = spa[X][i];
			cha -= (1LL << i);
		}
	}
	
	return ret;
}

void dfs2(ll here, ll pa)
{
	for(auto &i : vec2[here])
	{
		if(i.fi == pa)
			continue;
		
		dfs2(i.fi, here);
		dp1[here] = min(dp1[here], dp1[i.fi] + i.se);
		dp2[here] = min(dp2[here], dp2[i.fi] + i.se);
	}
}

int main(void)
{
	fastio
	
	cin >> n >> q;
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll >> cll;
		
		all++;
		bll++;
		
		vec[all].push_back({bll, cll});
		vec[bll].push_back({all, cll});
	}
	
	dfs(1, 0);
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			hap[j][i] = hap[j][i - 1] + hap[spa[j][i - 1]][i - 1];
	}
	
	while(q--)
	{
		vector< pair<ll, ll> > tmp;
		
		tmp1.clear();
		tmp2.clear();
		
		cin >> all >> bll;
		
		for(ll i = 1 ; i <= all ; i++)
		{
			cin >> cll;
			
			tmp1.push_back(cll + 1);
			tmp.push_back({IN[cll + 1], cll + 1});
		}
		
		for(ll i = 1 ; i <= bll ; i++)
		{
			cin >> cll;
			
			tmp2.push_back(cll + 1);
			tmp.push_back({IN[cll + 1], cll + 1});
		}
		
		sort(tmp.begin(), tmp.end());
		
		ll siz = (ll)tmp.size();
		
		for(ll i = 1 ; i < siz ; i++)
		{
			ll num1 = tmp[i - 1].se;
			ll num2 = tmp[i].se;
			ll lca = LCA(num1, num2);
			
			tmp.push_back({IN[lca], lca});
		}
		
		tmp.push_back({IN[1], 1});
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
		
		stack<ll> stk;
		
		for(auto &i : tmp)
		{
			vec2[i.se].clear();
			dp1[i.se] = dp2[i.se] = INF;
		}
		
		for(auto &i : tmp1)
			dp1[i] = 0;
		
		for(auto &i : tmp2)
			dp2[i] = 0;
		
		for(auto &i : tmp)
		{
			while(!stk.empty() && OUT[i.se] > OUT[stk.top()])
				stk.pop();
			
			if(!stk.empty())
			{
				ll num = stk.top();
				ll cos = cost(num, i.se);
				
				vec2[num].push_back({i.se, cos});
				vec2[i.se].push_back({num, cos});
			}
			
			stk.push(i.se);
		}
		
		dfs2(1, 0);
		
		ll ans = INF;
		
		for(auto &i : tmp)
			ans = min(ans, dp1[i.se] + dp2[i.se]);
		
		cout << ans en;
	}
	
	return 0;
}