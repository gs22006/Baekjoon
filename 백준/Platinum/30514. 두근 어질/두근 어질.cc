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
set<ll> st[100010];
ll bun[100010];
ll all, bll;
pll a[100010];
ll chk[100010];

ll ffind(ll here)
{
	if(bun[here] == here)
		return here;
	
	return bun[here] = ffind(bun[here]);
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all;
		
		st[i].insert(all);
		bun[i] = i;
		chk[1]++;
		a[1].fi ^= 1;
	}
	
	a[1].se = chk[1];
	
	for(ll i = 2 ; i <= n ; i++)
	{
		a[i].fi = a[i - 1].fi;
		
		cin >> all >> bll;
		
		ll BA = ffind(bun[all]);
		ll BB = ffind(bun[bll]);
		
		if((ll)st[BA].size() > (ll)st[BB].size())
		{
			swap(all, bll);
			swap(BA, BB);
		}
		
		chk[(ll)st[BA].size()]--;
		chk[(ll)st[BB].size()]--;
		a[i].fi ^= (ll)st[BA].size();
		a[i].fi ^= (ll)st[BB].size();
		
		for(auto &j : st[BA])
			st[BB].insert(j);
		
		st[BA].clear();
		chk[(ll)st[BB].size()]++;
		a[i].fi ^= (ll)st[BB].size();
		a[i].se = chk[1];
		bun[all] = bun[bll];
	}
	
	ll W = 1;
	
	for(ll i = n ; i >= 1 ; i--)
	{
		if(W == 1)
		{
			if(a[i].fi)
				W = 1;
			else
				W = 0;
		}
		
		else
		{
			if(a[i].se == n - i + 1)
			{
				if((n - i + 1) & 1)
					W = 0;
				else
					W = 1;
			}
			
			else
			{
				if(a[i].fi)
					W = 1;
				else
					W = 0;
			}
		}
	}
	
	if(W)
		cout << "Sejong";
	else
		cout << "Areum";
	
	return 0;
}