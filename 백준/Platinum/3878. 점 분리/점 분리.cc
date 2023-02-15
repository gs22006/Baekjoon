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

ll ccw(pll X, pll Y, pll Z)
{
	return X.fi * Y.se + Y.fi * Z.se + Z.fi * X.se - X.se * Y.fi - Y.se * Z.fi - Z.se * X.fi;
}

vector<pll> getcvh(vector<pll> X)
{
	vector<pll> ret;
	vector<pll> h1, h2;
	
	if((ll)X.size() <= 2)
		return X;
	
	sort(X.begin(), X.end());
	
	ll sz = (ll)X.size();
	
	h1.push_back(X[0]);
	h1.push_back(X[1]);
	
	for(ll i = 2 ; i < sz ; i++)
	{
		while(1)
		{
			ll siz = (ll)h1.size();
			
			if(siz < 2 || ccw(h1[siz - 2], h1[siz - 1], X[i]) > 0)
				break;
			
			h1.pop_back();
		}
		
		h1.push_back(X[i]);
	}
	
	h2.push_back(X[sz - 1]);
	h2.push_back(X[sz - 2]);
	
	for(ll i = sz - 3 ; i >= 0 ; i--)
	{
		while(1)
		{
			ll siz = (ll)h2.size();
			
			if(siz < 2 || ccw(h2[siz - 2], h2[siz - 1], X[i]) > 0)
				break;
			
			h2.pop_back();
		}
		
		h2.push_back(X[i]);
	}
	
	for(auto &i : h1)
		ret.push_back(i);
	
	for(auto &i : h2)
	{
		if(ret.back() == i)
			continue;
		
		ret.push_back(i);
	}
	
	ret.pop_back();
	return ret;
}

ll LineIntersect(pll AA, pll BB, pll CC, pll DD)
{
    ll ret = 0;
    ll ccwAB = ccw(AA, BB, CC) * ccw(AA, BB, DD);
    ll ccwCD = ccw(CC, DD, AA) * ccw(CC, DD, BB);
    
    if(ccwAB == 0 && ccwCD == 0)
    {
        if(AA >= BB)
            swap(AA, BB);
        
        if(CC >= DD)
            swap(CC, DD);
        
        ret = ((CC <= BB) && (AA <= DD));
    }
    
    else
        ret = ((ccwAB <= 0) && (ccwCD <= 0));
    
    return ret;
}

ll on_line(pll X, pll Y, pll Z)
{
	if(Y.fi < min(X.fi, Z.fi) || max(X.fi, Z.fi) < Y.fi)
		return 0;
	
	if(Y.se < min(X.se, Z.se) || max(X.se, Z.se) < Y.se)
		return 0;
	
	if(X.fi == Z.fi)
	{
		if(Y.fi != X.fi)
			return 0;
		
		return 1;
	}
	
	if(X.se == Z.se)
	{
		if(Y.se != X.se)
			return 0;
		
		return 1;
	}
	
	if((X.se - Y.se) * (Y.fi - Z.fi) == (Y.se - Z.se) * (X.fi - Y.fi))
		return 1;
	
	return 0;
}

ll t;
ll n, m;
vector<pll> vec1, vec2;
ll all, bll;

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		
		vec1.clear();
		vec2.clear();
		
		for(ll i = 0 ; i < n ; i++)
		{
			cin >> all >> bll;
			vec1.push_back({all, bll});
		}
		
		for(ll i = 0 ; i < m ; i++)
		{
			cin >> all >> bll;
			vec2.push_back({all, bll});
		}
		
		vector<pll> cvh1, cvh2;
		ll siz1, siz2;
		
		cvh1 = getcvh(vec1);
		cvh2 = getcvh(vec2);
		siz1 = (ll)cvh1.size();
		siz2 = (ll)cvh2.size();
		
		if(siz1 == 1 && siz2 == 1)
		{
			cout << "YES\n";
			continue;
		}
		
		ll ff = 0;
		
		if(siz1 >= 2)
		{
			cvh1.push_back(cvh1[0]);
			
			for(ll i = 0 ; i < siz1 ; i++)
			{
				for(ll j = 0 ; j < siz2 ; j++)
				{
					if(on_line(cvh1[i], cvh2[j], cvh1[i + 1]))
						ff = 1;
				}
			}
			
			cvh1.pop_back();
		}
		
		if(siz2 >= 2)
		{
			cvh2.push_back(cvh2[0]);
			
			for(ll i = 0 ; i < siz2 ; i++)
			{
				for(ll j = 0 ; j < siz1 ; j++)
				{
					if(on_line(cvh2[i], cvh1[j], cvh2[i + 1]))
						ff = 1;
				}
			}
			
			cvh2.pop_back();
		}
		
		if(siz1 >= 2 && siz2 >= 2)
		{
			cvh1.push_back(cvh1[0]);
			cvh2.push_back(cvh2[0]);
			
			for(ll i = 0 ; i < siz1 ; i++)
			{
				for(ll j = 0 ; j < siz2 ; j++)
				{
					if(LineIntersect(cvh1[i], cvh1[i + 1], cvh2[j], cvh2[j + 1]))
						ff = 1;
				}
			}
			
			cvh1.pop_back();
			cvh2.pop_back();
		}
		
		if(ff)
		{
			cout << "NO\n";
			continue;
		}
		
		if(siz1 >= 3)
		{
			cvh1.push_back(cvh1[0]);
			
			for(ll i = 0 ; i < siz2 ; i++)
			{
				ll gg = 0;
				ll gap = ccw(cvh1[0], cvh1[1], cvh2[i]);
				
				for(ll j = 0 ; j < siz1 ; j++)
				{
					if(ccw(cvh1[j], cvh1[j + 1], cvh2[i]) * gap <= 0)
						gg = 1;
				}
				
				if(!gg)
					ff = 1;
			}
			
			cvh1.pop_back();
		}
		
		if(siz2 >= 3)
		{
			cvh2.push_back(cvh2[0]);
			
			for(ll i = 0 ; i < siz1 ; i++)
			{
				ll gg = 0;
				ll gap = ccw(cvh2[0], cvh2[1], cvh1[i]);
				
				for(ll j = 0 ; j < siz2 ; j++)
				{
					if(ccw(cvh2[j], cvh2[j + 1], cvh1[i]) * gap <= 0)
						gg = 1;
				}
				
				if(!gg)
					ff = 1;
			}
			
			cvh2.pop_back();
		}
		
		if(ff)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	
	return 0;
}