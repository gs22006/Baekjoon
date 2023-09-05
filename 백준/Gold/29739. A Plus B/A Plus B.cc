#include "aplusb.h"
#include <bits/stdc++.h>

using namespace std;
typedef int ll;

vector<ll> smallest_sums(ll N, vector<ll> A, vector<ll> B)
{
	vector<ll> ans;
	priority_queue< pair<ll, pair<ll, ll> > > pq;
	map< pair<ll, ll>, ll> mp;
	
	pq.push({-A[0] - B[0], {0, 0}});
	mp[{0, 0}] = 1;
	
	while(!pq.empty())
	{
		pair<ll, pair<ll, ll> > qq = pq.top();
		pq.pop();
		
		ans.push_back(-qq.first);
		
		if((ll)ans.size() >= N)
			break;
		
		ll p1 = qq.second.first;
		ll p2 = qq.second.second;
		
		if(p1 < N - 1)
		{
			if(mp[{p1 + 1, p2}] == 0)
			{
				mp[{p1 + 1, p2}] = 1;
				pq.push({-A[p1 + 1] - B[p2], {p1 + 1, p2}});
			}
		}
		
		if(p2 < N - 1)
		{
			if(mp[{p1, p2 + 1}] == 0)
			{
				mp[{p1, p2 + 1}] = 1;
				pq.push({-A[p1] - B[p2 + 1], {p1, p2 + 1}});
			}
		}
	}
	
	return ans;
}