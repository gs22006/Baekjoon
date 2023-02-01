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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

ll n, m;
ll a[50];
vector<ll> vec[50];
ll all, bll;
ll ans = INF;
ll chk[50];

void f(ll here)
{
	if(here == n)
	{
		ll gap = 0;
		set<ll> st;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(chk[i])
			{
				st.insert(i);
				
				for(auto &j : vec[i])
					st.insert(j);
			}
		}
		
		for(auto &i : st)
			gap += a[i];
		
		ans = min(ans, gap);
		return;
	}
	
	for(auto &i : vec[here])
	{
		if(chk[i])
			continue;
		
		ll cou = 0;
		
		for(auto &j : vec[i])
			cou += chk[j];
		
		if(cou >= 2)
			continue;
		
		chk[i] = 1;
		f(i);
		chk[i] = 0;
	}
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	chk[1] = 1;
	f(1);
	
	cout << ans;
	return 0;
}