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
vector< pair<ll, pll> > vv;
vector<ll> vec[2010];
ll pa[2010], ra[2010];

ll ffind(ll here)
{
	if(here == pa[here])
		return here;
	
	return pa[here] = ffind(pa[here]);
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	if(ra[X] < ra[Y])
		pa[X] = Y;
	else if(ra[Y] < ra[X])
		pa[Y] = X;
	
	else
	{
		pa[X] = Y;
		ra[Y]++;
	}
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = i + 1 ; j <= n ; j++)
		{
			cin >> all;
			vv.push_back({all, {i, j}});
		}
	}
	
	sort(vv.begin(), vv.end());
	
	for(ll i = 1 ; i <= n ; i++)
		pa[i] = i;
	
	for(auto &i : vv)
	{
		if(ffind(i.se.fi) == ffind(i.se.se))
			continue;
		
		uunion(i.se.fi, i.se.se);
		vec[i.se.fi].push_back(i.se.se);
		vec[i.se.se].push_back(i.se.fi);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cout << (ll)vec[i].size() sp;
		
		sort(vec[i].begin(), vec[i].end());
		
		for(auto &j : vec[i])
			cout << j sp;
		
		cout en;
	}
	
	return 0;
}