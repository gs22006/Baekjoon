#include "gap.h"
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

ll findGap(int T, int N)
{
	ll mini, maxi;
	
	if(T == 1)
	{
		vector<ll> vec;
		ll l = 0, r = 1000000000000000000LL;
		
		while(1)
		{
			MinMax(l, r, &mini, &maxi);
			
			if(mini == -1)
				break;
			
			if(mini == maxi)
			{
				vec.push_back(mini);
				break;
			}
			
			vec.push_back(mini);
			vec.push_back(maxi);
			
			l = mini + 1;
			r = maxi - 1;
			
			if((ll)vec.size() == N)
				break;
		}
		
		sort(vec.begin(), vec.end());
		
		ll ans = 0;
		
		for(ll i = 1 ; i < N ; i++)
			ans = max(ans, vec[i] - vec[i - 1]);
		
		return ans;
	}
	
	vector<ll> vec;
	ll l = 0, r = 1000000000000000000;
	
	MinMax(l, r, &mini, &maxi);
	
	l = mini;
	r = maxi;
	
	vec.push_back(l);
	vec.push_back(r);
	
	ll rng = (r - l + N - 2) / (N - 1);
	ll L = l;
	
	while(1)
	{
		L++;
		ll R = min(r, L + rng - 1);
		
		if(L > R)
			break;
		
		MinMax(L, R, &mini, &maxi);
		
		if(mini != -1)
		{
			if(mini == maxi)
				vec.push_back(mini);
			
			else
			{
				vec.push_back(mini);
				vec.push_back(maxi);
			}
		}
		
		if(R == r)
			break;
		
		L = R;
	}
	
	sort(vec.begin(), vec.end());
	
	ll ans = 0;
	
	for(ll i = 1 ; i < (ll)vec.size() ; i++)
		ans = max(ans, vec[i] - vec[i - 1]);
	
	return ans;
}