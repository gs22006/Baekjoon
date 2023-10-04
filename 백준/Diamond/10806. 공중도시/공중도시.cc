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

ll n, m;
ll all, bll;
vector<ll> vec[100010], vec2[100010];
vector<pll> ans;
ll dep[100010];
ll up[100010];
ll P[100010], R[100010];
ll deg[100010];
ll V[100010];
map<pll, ll> mp;
vector<pll> leaf;

ll ffind(ll here)
{
	if(P[here] == here)
		return here;
	
	return P[here] = ffind(P[here]);
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	if(X == Y)
		return;
	
	if(R[X] < R[Y])
		P[X] = Y;
	else if(R[Y] < R[X])
		P[Y] = X;
	
	else
	{
		P[X] = Y;
		R[Y]++;
	}
}

void dfs(ll here, ll pa, ll D)
{
	dep[here] = D;
	up[here] = D;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		if(dep[i])
		{
			up[here] = min(up[here], dep[i]);
			continue;
		}
		
		dfs(i, here, D + 1);
		
		if(dep[here] >= up[i])
			uunion(i, here);
		
		up[here] = min(up[here], up[i]);
	}
}

vector<ll> why[100010];
ll sub[100010];
ll help[100010];

void dfs0(ll here, ll pa)
{
	ll C = 0;
	
	help[here] = pa;
	
	for(auto &i : vec2[here])
	{
		if(i == pa)
			continue;
		
		dfs0(i, here);
		C++;
		sub[here] += sub[i];
	}
	
	if(!C)
		sub[here] = 1;
}

void dfs2(ll here, ll pa, ll OR)
{
	ll C = 0;
	
	for(auto &i : vec2[here])
	{
		if(i == pa)
			continue;
		
		C++;
		dfs2(i, here, OR);
	}
	
	if(!C)
		leaf.push_back({here, OR});
}

ll get_C(ll here, ll pa, ll SIZ)
{
	for(auto &i : vec2[here])
	{
		if(i == pa)
			continue;
		
		if(sub[i] * 2 > SIZ)
			return get_C(i, here, SIZ);
	}
	
	return here;
}

bool comp(pll X, pll Y)
{
	return X.se < Y.se;
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
		mp[{min(all, bll), max(all, bll)}]++;
	}
	
	for(ll i = 1 ; i <= n ; i++)
		P[i] = i, R[i] = 0;
	
	dfs(1, 0, 1);
	
	for(auto &i : mp)
	{
		if(i.se >= 2)
			uunion(i.fi.fi, i.fi.se);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		V[ffind(i)] = i;
		
		for(auto &j : vec[i])
		{
			if(ffind(i) == ffind(j))
				continue;
			
			vec2[ffind(i)].push_back(ffind(j));
			deg[ffind(i)]++;
		}
	}
	
	ll cou = 0;
	vector<ll> vv, vv2;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(deg[i] == 1)
		{
			cou++;
			vv.push_back(i);
		}
		
		else if(deg[i])
			vv2.push_back(i);
	}
	
	if(cou)
	{
		if(cou == 2)
			ans.push_back({V[vv[0]], V[vv[1]]});
		
		else
		{
			ll rt = vv2[0];
			ll maxx = 0;
			
			dfs0(rt, 0);
			rt = get_C(rt, 0, sub[rt]);
			dfs0(rt, 0);
			
			for(auto &i : vec2[rt])
			{
				if(i == help[rt])
					continue;
				
				dfs2(i, rt, i);
			}
			
			map<ll, ll> mp2;
			vector<pll> asdf;
			
			if((ll)leaf.size() % 2 == 1)
				leaf.push_back({rt, rt});
			
			for(auto &i : leaf)
			{
				why[i.se].push_back(i.fi);
				mp2[i.se]++;
			}
			
			priority_queue<pll> pq;
			
			for(auto &i : mp2)
				pq.push({why[i.fi].size() - 1, i.fi});
			
			ll siz = (ll)leaf.size();
			
			for(ll i = 0 ; i < siz / 2 ; i++)
			{
				pll TP1 = pq.top();
				pq.pop();
				pll TP2 = pq.top();
				pq.pop();
				
				ans.push_back({why[TP1.se][TP1.fi], why[TP2.se][TP2.fi]});
				TP1.fi--, TP2.fi--;
				
				if(TP1.fi >= 0)
					pq.push(TP1);
				
				if(TP2.fi >= 0)
					pq.push(TP2);
			}
		}
	}
	
	cout << (ll)ans.size() en;
	
	for(auto &i : ans)
		cout << i.fi sp << i.se en;
	
	return 0;
}