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

ll t;
ll n;
ll all, bll;
vector<ll> vec[100010];
ll siz[100010];
ll cent, cent2;
set<string> st;

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

string dfs(ll here, ll pa)
{
	vector<string> vv;
	string ret;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		vv.push_back(dfs(i, here));
	}
	
	sort(vv.begin(), vv.end());
	
	for(auto &i : vv)
	{
		ret.push_back('1');
		ret += i;
		ret.push_back('0');
	}
	
	return ret;
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

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		vector<pll> edg;
		
		for(ll i = 0 ; i <= 50 ; i++)
			vec[i].clear();
		
		for(ll i = 1 ; i < n ; i++)
		{
			cin >> all >> bll;
			
			vec[all].push_back(bll);
			vec[bll].push_back(all);
			edg.push_back({all, bll});
		}
		
		dfs0(0, -1);
		
		cent = -1, cent2 = -1;
		
		for(ll i = 0 ; i < n ; i++)
		{
			ll ff = 0;
			
			for(auto &j : vec[i])
			{
				if(siz[j] < siz[i])
				{
					if(n < siz[j] * 2)
						ff = 1;
				}
				
				else
				{
					if(n < (n - siz[i]) * 2)
						ff = 1;
				}
			}
			
			if(!ff)
			{
				if(cent == -1)
					cent = i;
				else
					cent2 = i;
			}
		}
		
		vector<string> help;
		
		if(cent != -1)
			help.push_back(dfs(cent, -1));
		
		if(cent2 != -1)
			help.push_back(dfs(cent2, -1));
		
		sort(help.begin(), help.end());
		st.insert(help[0]);
	}
	
	cout << (ll)st.size();
	return 0;
}