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
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n;
ll all, bll;

struct TRIE
{
	vector<pll> vec;
	vector<ll> cou;
	ll cc;
	
	void init(void)
	{
		ll w = 0;
		
		vec.push_back({-1, -1});
		cou.push_back(0);
	}
	
	void update(ll X)
	{
		ll w = 0;
		
		cou[0]++;
		
		for(ll i = 30 ; i >= 0 ; i--)
		{
			if(X & (1LL << i))
			{
				if(vec[w].se == -1)
				{
					vec[w].se = ++cc;
					w = cc;
					vec.push_back({-1, -1});
					cou.push_back(0);
				}
				
				else
					w = vec[w].se;
			}
			
			else
			{
				if(vec[w].fi == -1)
				{
					vec[w].fi = ++cc;
					w = cc;
					vec.push_back({-1, -1});
					cou.push_back(0);
				}
				
				else
					w = vec[w].fi;
			}
			
			cou[w]++;
		}
	}
	
	void erase(ll X)
	{
		ll w = 0;
		
		cou[0]--;
		
		for(ll i = 30 ; i >= 0 ; i--)
		{
			if(X & (1LL << i))
				w = vec[w].se;
			else
				w = vec[w].fi;
			
			cou[w]--;
		}
	}
	
	ll query(ll X)
	{
		ll ret = 0;
		ll w = 0;
		
		for(ll i = 30 ; i >= 0 ; i--)
		{
			if(X & (1LL << i))
			{
				if(vec[w].fi == -1)
					w = vec[w].se;
				
				else if(cou[vec[w].fi])
				{
					w = vec[w].fi;
					ret += (1LL << i);
				}
				
				else
					w = vec[w].se;
			}
			
			else
			{
				if(vec[w].se == -1)
					w = vec[w].fi;
				
				else if(cou[vec[w].se])
				{
					w = vec[w].se;
					ret += (1LL << i);
				}
				
				else
					w = vec[w].fi;
			}
		}
		
		return ret;
	}
}trie;

int main(void)
{
	fastio
	
	trie.init();
	trie.update(0);
	
	cin >> n;
	
	while(n--)
	{
		cin >> all >> bll;
		
		if(all == 1)
			trie.update(bll);
		else if(all == 2)
			trie.erase(bll);
		else
			cout << trie.query(bll) en;
	}
	
	return 0;
}