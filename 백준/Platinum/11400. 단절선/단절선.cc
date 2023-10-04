#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n, m;
ll all, bll;
ll pa[100010][3], ra[100010][3];
vector<ll> vec[100010];
ll dfsn[100010], cc;
vector< pair<ll, ll> > ans;

ll ffind(ll here, ll num)
{
	if(pa[here][num] == here)
		return here;
	
	return pa[here][num] = ffind(pa[here][num], num);
}

void uunion(ll X, ll Y, ll num)
{
	X = ffind(X, num);
	Y = ffind(Y, num);
	
	if(X == Y)
		return;
	
	if(ra[X][num] < ra[Y][num])
		pa[X][num] = Y;
	else if(ra[Y][num] < ra[X][num])
		pa[Y][num] = X;
	
	else
	{
		pa[X][num] = Y;
		ra[Y][num]++;
	}
}

ll dfs(ll here, ll pa)
{
	ll ret;
	
	dfsn[here] = ++cc;
	ret = cc;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		if(dfsn[i])
		{
			ret = min(ret, dfsn[i]);
			continue;
		}
		
		ll gap = dfs(i, here);
		
		if(gap > dfsn[here])
			ans.push_back({min(i, here), max(i, here)});
		
		ret = min(ret, gap);
	}
	
	return ret;
}

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
		pa[i][0] = pa[i][1] = i;
	
	while(m--)
	{
		cin >> all >> bll;
		vec[all].push_back(bll);
		vec[bll].push_back(all);
		/*if(ffind(all, 0) != ffind(bll, 0))
		{
			uunion(all, bll, 0);
			vec[all].push_back(bll);
			vec[bll].push_back(all);
		}
		
		else if(ffind(all, 1) != ffind(bll, 1))
		{
			uunion(all, bll, 1);
			vec[all].push_back(bll);
			vec[bll].push_back(all);
		}*/
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!dfsn[i])
			dfs(i, 0);
	}
	
	cout << (ll)ans.size() << '\n';
	
	sort(ans.begin(), ans.end());
	
	for(auto &i : ans)
		cout << i.fi << ' ' << i.se << '\n';
	
	return 0;
}