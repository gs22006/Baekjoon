#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 987654321
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll t;
ll n;
ll a[400010];
vector<ll> vec[400010], vec2[400010], yuk[400010], col[400010];
ll all, bll;
ll siz[400010], chk[400010], scc[400010];
vector<ll> ord;

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

void connect(ll X, ll Y)
{
	ll notX, notY;
	
	if(X <= n)
		notX = X + n;
	else
		notX = X - n;
	
	if(Y <= n)
		notY = Y + n;
	else
		notY = Y - n;
	
	vec2[notX].push_back(Y);
	vec2[notY].push_back(X);
	yuk[X].push_back(notY);
	yuk[Y].push_back(notX);
}

void dfs(ll here, ll pa)
{
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		connect(i + n, here);
		dfs(i, here);
	}
}

void dfs2(ll here)
{
	chk[here] = 1;
	
	for(auto &i : vec2[here])
	{
		if(chk[i])
			continue;
		
		dfs2(i);
	}
	
	ord.push_back(here);
}

ll cc;

void dfs3(ll here)
{
	scc[here] = cc;
	
	for(auto &i : yuk[here])
	{
		if(!scc[i])
			dfs3(i);
	}
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		n *= 2;
		
		for(ll i = 0 ; i <= n * 2 ; i++)
			vec[i].clear(), vec2[i].clear(), yuk[i].clear(), col[i].clear(), siz[i] = chk[i] = scc[i] = 0;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			cin >> a[i];
			col[a[i]].push_back(i);
		}
		
		for(ll i = 1 ; i < n ; i++)
		{
			cin >> all >> bll;
			
			vec[all].push_back(bll);
			vec[bll].push_back(all);
		}
		
		dfs0(1, 0);
		
		ll rt = get_centroid(1, 0, n);
		
		dfs0(rt, 0);
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(i == rt)
				continue;
			
			if(siz[i] > n / 2)
				assert(0);
		}
		
		dfs(rt, 0);
		
		for(ll i = 1 ; i <= n / 2 ; i++)
		{
			connect(col[i][0] + n, col[i][1] + n);
			connect(col[i][0], col[i][1]);
		}
		
		ord.clear();
		cc = 0;
		
		for(ll i = 1 ; i <= n * 2 ; i++)
		{
			if(!chk[i])
				dfs2(i);
		}
		
		while(!ord.empty())
		{
			if(!scc[ord.back()])
				cc++, dfs3(ord.back());
			
			ord.pop_back();
		}
		
		ll ff = 0;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(scc[i] == scc[i + n])
			{
				ff = 1;
				break;
			}
		}
		
		if(ff)
		{
			cout << -1 en;
			continue;
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(scc[i] > scc[i + n])
				cout << i sp;
		}
		
		cout en;
	}
	
	return 0;
}