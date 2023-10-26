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

ll n, q;
pll a[100010];
ld all, bll;

struct line
{
	pll L;
	ld S;
};

ld gyo(pll L1, pll L2)
{
	return (ld)(L2.se - L1.se) / (L1.fi - L2.fi);
}

struct MaxCHT
{
	line lin[100010];
	ll siz;
	
	void update(pll L)
	{
		if(!siz)
		{
			lin[siz++] = {L, -INF};
			return;
		}
		
		while(siz)
		{
			if(lin[siz - 1].L.fi == L.fi)
			{
				if(lin[siz - 1].L.se >= L.se)
					return;
				
				siz--;
				continue;
			}
			
			if(gyo(lin[siz - 1].L, L) < lin[siz - 1].S)
				siz--;
			else
				break;
		}
		
		if(!siz)
			lin[siz++] = {L, -INF};
		else
			lin[siz++] = {L, gyo(lin[siz - 1].L, L)};
	}
	
	ld query(ld X)
	{
		ll l = 0, r = siz - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(lin[mid].S <= X)
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		return lin[r].L.fi * X + lin[r].L.se;
	}
}maxcht;

struct MinCHT
{
	line lin[100010];
	ll siz;
	
	void update(pll L)
	{
		if(!siz)
		{
			lin[siz++] = {L, INF};
			return;
		}
		
		while(siz)
		{
			if(lin[siz - 1].L.fi == L.fi)
			{
				if(lin[siz - 1].L.se <= L.se)
					return;
				
				siz--;
				continue;
			}
			
			if(gyo(lin[siz - 1].L, L) > lin[siz - 1].S)
				siz--;
			else
				break;
		}
		
		if(!siz)
			lin[siz++] = {L, INF};
		else
			lin[siz++] = {L, gyo(lin[siz - 1].L, L)};
	}
	
	ld query(ld X)
	{
		ll l = 0, r = siz - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(lin[mid].S >= X)
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		return lin[r].L.fi * X + lin[r].L.se;
	}
}mincht;

int main(void)
{
	fastio
	
	cin >> n >> q;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		maxcht.update(a[i]);
		mincht.update(a[i]);
	}
	
	while(q--)
	{
		cin >> all >> bll;
		
		if(bll == 1)
			cout << maxcht.query(all) en;
		else
			cout << mincht.query(all) en;
	}
	
	return 0;
}