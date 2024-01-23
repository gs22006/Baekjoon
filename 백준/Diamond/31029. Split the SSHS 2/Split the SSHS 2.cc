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
vector<ll> vec[500010];
ll dep[500010];
vector< pair<ll, pll> > bedg[500010];
ll ans;
ll P[500010], spa[500010][21];
ll deg[500010];

void dfs0(ll here)
{
	for(auto &i : vec[here])
	{
		if(dep[i])
			continue;
		
		P[i] = here;
		spa[i][0] = here;
		deg[i]++, deg[here]++;
		dep[i] = dep[here] + 1;
		dfs0(i);
	}
}

void add(ll X, ll A, ll B, ll D)
{
	if(dep[A] < dep[B])
		swap(A, B);
	
	for(auto &i : bedg[X])
	{
		if(i.fi == D && i.se.fi == A && i.se.se == B)
			return;
	}
	
	bedg[X].push_back({D, {A, B}});
	sort(bedg[X].begin(), bedg[X].end());
	
	if((ll)bedg[X].size() > 2)
		bedg[X].pop_back();
}

void dfs(ll here)
{
	for(auto &i : vec[here])
	{
		if(P[here] == i)
			continue;
		
		if(dep[i] < dep[here])
		{
			add(here, here, i, dep[i]);
			continue;
		}
		
		if(P[i] == here)
		{
			dfs(i);
			
			for(auto &j : bedg[i])
				add(here, j.se.fi, j.se.se, j.fi);
		}
	}
}

ll UP(ll X, ll Y)
{
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if(Y >= (1LL << i))
		{
			Y -= (1LL << i);
			X = spa[X][i];
		}
	}
	
	return X;
}

void dfs2(ll here)
{
	multiset<ll> st;
	set<ll> st2;
	ll minn = INF;
	
	for(auto &i : vec[here])
	{
		if(P[i] == here)
		{
			if(bedg[i].empty())
				st.insert(INF);
			else
				st.insert(bedg[i][0].fi);
			
			dfs2(i);
		}
		
		else if(P[here] != i && dep[i] < dep[here])
			minn = min(minn, dep[i]);
		
		else if(dep[i] > dep[here] && P[i] != here)
			st2.insert(UP(i, dep[i] - dep[here] - 1));
	}
	
	if(P[here])
	{
		for(auto &i : vec[here])
		{
			ll ff = 0;
			
			if(P[i] == here)
			{
				if(bedg[i].empty() || ((ll)bedg[i].size() == 1 && bedg[i][0].se.fi == i && bedg[i][0].se.se == P[here]))
					ff = 1;
				
				if(bedg[here].empty() || ((ll)bedg[here].size() == 1 && bedg[here][0].se.fi == i && bedg[here][0].se.se == P[here]))
					ff = 1;
				
				ll gap = 0;
				
				if(bedg[i].empty())
					gap = INF;
				else
					gap = bedg[i][0].fi;
				
				st.erase(st.find(gap));
				
				ll gap2 = INF;
				
				if(!st.empty())
					gap2 = (*st.begin());
				
				gap2 = min(gap2, minn);
				
				if(st2.find(i) == st2.end() && gap2 >= dep[here])
					ff = 1;
			
				st.insert(gap);
				ans += ff;
			}
		}
	}
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
	}
	
	dep[1] = 1;
	dfs0(1);
	dfs(1);
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(!bedg[i].empty() && bedg[i].back().fi >= dep[i])
			bedg[i].pop_back();
	}
	
	dfs2(1);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll cou1 = 0, cou2 = 0;
		
		for(auto &j : vec[i])
		{
			if(P[j] == i)
			{
				if(!bedg[j].empty())
					cou2++;
				
				cou1++;
			}
		}
		
		ans += (cou1 - 1) * cou1 / 2 - (cou2 - 1) * cou2 / 2;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!P[i])
			continue;
		
		if(bedg[i].empty())
			ans += n - deg[i] - deg[P[i]];
		
		else
		{
			if((ll)bedg[i].size() != 1)
				continue;
			
			if(bedg[i][0].se.fi == i)
			{
				if(bedg[i][0].se.se != P[P[i]])
					ans++;
			}
			
			else if(bedg[i][0].se.se == P[i])
			{
				if(P[bedg[i][0].se.fi] != i)
					ans++;
			}
		}
	}
	
	cout << ans;
	return 0;
}