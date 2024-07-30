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

ll n;
ll all;
ll cou[1010];
vector<pll> vv;
vector<ll> vv1, vv2;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all;
		cou[all]++;
	}
	
	for(ll i = 1 ; i <= 1000 ; i++)
		vv.push_back({cou[i], i});
	
	sort(vv.begin(), vv.end());
	reverse(vv.begin(), vv.end());
	
	ll gap = 0;
	
	for(auto &i : vv)
	{
		if(!i.fi)
			break;
		
		if(i.fi == vv[0].fi)
			vv1.push_back(i.se);
		
		else
		{
			if(!gap)
				gap = i.fi;
			
			if(i.fi == gap)
				vv2.push_back(i.se);
		}
	}
	
	sort(vv1.begin(), vv1.end());
	sort(vv2.begin(), vv2.end());
	
	if((ll)vv2.empty() || (ll)vv1.size() >= 2)
	{
		cout << vv1.back() - vv1[0];
		return 0;
	}
	
	cout << max(abs(vv1[0] - vv2[0]), abs(vv1[0] - vv2.back()));
	return 0;
}