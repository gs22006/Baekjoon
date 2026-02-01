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
vector<pll> vec[400010];
ll m, q;
ll all, bll, cll;
ll sub[400010];
ll R[400010];
ll chk[400010];
ll sum[400010];
vector<ll> ju[400010], bat[400010];
 
void dfs0(ll here, ll pa)
{
	sub[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa || R[i.fi])
			continue;
		
		dfs0(i.fi, here);
		sub[here] += sub[i.fi];
	}
}
 
ll get_centroid(ll here, ll pa, ll SIZ)
{
	for(auto &i : vec[here])
	{
		if(i.fi == pa || R[i.fi])
			continue;
		
		if(sub[i.fi] * 2 > SIZ)
			return get_centroid(i.fi, here, SIZ);
	}
	
	return here;
}
 
void get_qry(ll here, ll num)
{
	bat[here].push_back(num);
	
	for(auto &i : vec[here])
	{
		if(R[i.fi])
			continue;
		
		if(!i.se)
			get_qry(i.fi, num);
	}
}
 
void get_label(ll here, ll num)
{
	ju[here].push_back(num);
	
	for(auto &i : vec[here])
	{
		if(R[i.fi])
			continue;
		
		if(i.se)
			get_label(i.fi, num);
	}
}
 
void f(ll here)
{
	dfs0(here, 0);
	
	ll cent = get_centroid(here, 0, sub[here]);
	
	for(auto &i : vec[cent])
	{
		if(R[i.fi])
			continue;
		
		if(!i.se)
			get_qry(i.fi, cent);
		else
			get_label(i.fi, cent);
	}
	
	ju[cent].push_back(cent);
	bat[cent].push_back(cent);
	R[cent] = 1;
	
	for(auto &i : vec[cent])
	{
		if(R[i.fi])
			continue;
		
		f(i.fi);
	}
}
 
int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back({bll, 1});
		vec[bll].push_back({all, 0});
	}
	
	cin >> m >> q;
	
	m += q;
	
	f(1);
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> bll >> cll;
			
			for(auto &j : ju[bll])
				sum[j] += cll;
		}
		
		else
		{
			cin >> bll;
			
			ll ans = 0;
			
			for(auto &j : bat[bll])
				ans += sum[j];
			
			cout << ans en;
		}
	}
	
	return 0;
}