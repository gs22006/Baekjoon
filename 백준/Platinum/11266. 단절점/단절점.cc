#include <bits/stdc++.h>

using namespace std;
typedef int ll;
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

ll n, m;
ll all, bll;
vector<ll> vec[10010];
ll dfsn[10010];
stack< pair<ll, ll> > stk;
vector< vector< pair<ll, ll> > > BCC;
ll cc;
ll cou[10010];
vector<ll> ans;

ll dfs(ll here, ll pa)
{
	ll ret = dfsn[here] = ++cc;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		if(dfsn[here] > dfsn[i])
			stk.push({here, i});
		
		if(dfsn[i] > 0)
			ret = min(ret, dfsn[i]);
		
		else
		{
			ll tmp = dfs(i, here);
			
			ret = min(ret, tmp);
			
			if(tmp >= dfsn[here])
			{
				vector< pair<ll, ll> > ttmp;
				pair<ll, ll> hmm = {here, i};
				
				while(!stk.empty() && stk.top() != hmm)
				{
					ttmp.push_back(stk.top());
					stk.pop();
				}
				
				ttmp.push_back(stk.top());
				stk.pop();
				BCC.push_back(ttmp);
			}
		}
	}
	
	return ret;
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
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!dfsn[i])
			dfs(i, 0);
	}
	
	for(auto &i : BCC)
	{
		set<ll> st;
		
		for(auto &j : i)
		{
			st.insert(j.fi);
			st.insert(j.se);
		}
		
		for(auto &j : st)
			cou[j]++;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(cou[i] >= 2)
			ans.push_back(i);
	}
	
	cout << (ll)ans.size() en;
	
	for(auto &i : ans)
		cout << i sp;
	
	return 0;
}