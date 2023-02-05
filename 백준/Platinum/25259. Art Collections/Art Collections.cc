#include "art.h"
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

void solve(int N)
{
	int n = N;
    vector<int> tmp;
    vector<int> gap;
    vector< pair<int, int> > ans;
    
    for(int i = 1 ; i <= n ; i++)
    {
    	tmp.clear();
    	
    	for(int j = 0 ; j < n ; j++)
    		tmp.push_back((i + j - 1) % n + 1);
    	
    	gap.push_back(publish(tmp));
	}
	
	gap.push_back(gap[0]);
	
	for(int i = 0 ; i < n ; i++)
		ans.push_back({gap[i] - gap[i + 1], i + 1});
	
	sort(ans.begin(), ans.end());
	
	vector<int> yay;
	
	for(int i = 0 ; i < n ; i++)
		yay.push_back(ans[i].second);
	
	answer(yay);
	return;
}