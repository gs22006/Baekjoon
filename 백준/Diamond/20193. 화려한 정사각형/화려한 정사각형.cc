#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

struct point
{
	ll x;
	ll y;
	ll color;
	
	bool operator < (const point &xx) const
	{
		return y < xx.y;
	}
}a[250010];

ll n, k;
ll l, r;
multiset<ll> ms[250010];
vector< pair<ll, ll> > pm;

struct lazysegtree
{
	ll seg[2000010], lazy[2000010];
	
	ll update(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		if(lazy[no])
		{
			seg[no] += lazy[no];
			
			if(s != e)
			{
				lazy[no * 2] += lazy[no];
				lazy[no * 2 + 1] += lazy[no];
			}
			
			lazy[no] = 0;
		}
		
		if(l > e || r < s)
			return seg[no];
		
		if(l <= s && e <= r)
		{
			seg[no] += v;
			
			if(s != e)
			{
				lazy[no * 2] += v;
				lazy[no * 2 + 1] += v;
			}
			
			return seg[no];
		}
		
		ll mid = (s + e) / 2;
		ll al = update(no * 2, s, mid, l, r, v);
		ll bl = update(no * 2 + 1, mid + 1, e, l, r, v);
		
		seg[no] = max(al, bl);
		return seg[no];
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(lazy[no])
		{
			seg[no] += lazy[no];
			
			if(s != e)
			{
				lazy[no * 2] += lazy[no];
				lazy[no * 2 + 1] += lazy[no];
			}
			
			lazy[no] = 0;
		}
		
		if(l > e || r < s)
			return MIN;
		
		if(l <= s && e <= r)
			return seg[no];
		
		ll mid = (s + e) / 2;
		ll lef = query(no * 2, s, mid, l, r);
		ll rig = query(no * 2 + 1, mid + 1, e, l, r);
		
		return max(lef, rig);
	}
}segt;

int main(void)
{
	scanf("%lld %lld", &n, &k);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld %lld %lld", &a[i].x, &a[i].y, &a[i].color);
	
	l = 0;
	r = 250010;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		ll ff = 0;
		
		for(ll i = 0 ; i <= k ; i++)
			ms[i].clear();
		
		pm.clear();
		
		for(ll i = 1 ; i <= n ; i++)
		{
			pm.push_back(make_pair(a[i].x, i));
			pm.push_back(make_pair(a[i].x + mid + 1, -i));
		}
		
		for(ll i = 0 ; i < 2000010 ; i++)
		{
			segt.seg[i] = 0;
			segt.lazy[i] = 0;
		}
		
		sort(pm.begin(), pm.end());
		//printf("%lld : \n", mid); 
		for(ll i = 0 ; i < pm.size() ; i++)
		{
			//printf("%lld %lld\n", pm[i].first, pm[i].second);
			if(pm[i].second > 0LL)
			{
				//add point
				ll X = pm[i].second;
				ll L = 0, R = -1;
				
				multiset<ll>::iterator p = ms[a[X].color].lower_bound(a[X].y);
				
				if((ll)ms[a[X].color].size() == 0LL)
				{
					L = a[X].y;
					R = a[X].y + mid;
				}
				
				else if(p == ms[a[X].color].begin())
				{
					L = a[X].y;
					R = min(a[X].y + mid, (*p) - 1LL);
				}
				
				else if(p == ms[a[X].color].end())
				{
					p--;
					
					L = max(a[X].y, (*p) + mid + 1LL);
					R = a[X].y + mid;
				}
				
				else
				{
					R = min(a[X].y + mid, (*p) - 1LL);
					
					p--;
					
					L = max(a[X].y, (*p) + mid + 1LL);
				}
				
				segt.update(1LL, 0LL, 250010LL, L, R, 1LL);
				ms[a[X].color].insert(a[X].y);
				//printf("+%lld %lld %lld %lld ", X, a[X].x, L, R);
			}
			
			else
			{
				//remove point
				ll X = -pm[i].second;
				ll L = 0, R = -1;
				
				ms[a[X].color].erase(ms[a[X].color].lower_bound(a[X].y));
				multiset<ll>::iterator p = ms[a[X].color].lower_bound(a[X].y);
				
				if((ll)ms[a[X].color].size() == 0LL)
				{
					L = a[X].y;
					R = a[X].y + mid;
				}
				
				else if(p == ms[a[X].color].begin())
				{
					L = a[X].y;
					R = min(a[X].y + mid, (*p) - 1LL);
				}
				
				else if(p == ms[a[X].color].end())
				{
					p--;
					
					L = max(a[X].y, (*p) + mid + 1LL);
					R = a[X].y + mid;
				}
				
				else
				{
					R = min(a[X].y + mid, (*p) - 1LL);
					
					p--;
					
					L = max(a[X].y, (*p) + mid + 1LL);
				}
				
				segt.update(1, 0, 250010, L, R, -1);
				//printf("-%lld %lld %lld %lld ", X, a[X].x, L, R);
			}
			
			//printf("%lld\n", segt.query(1, 0, 300010, 0, 300010));
			
			if(segt.query(1, 0, 250010, 0, 250010) == k)
				ff = 1;
		}
		
		if(ff)
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	printf("%lld", l);
	return 0;
}