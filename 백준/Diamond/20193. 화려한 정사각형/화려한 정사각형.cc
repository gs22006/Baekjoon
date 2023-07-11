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
}a[100010];

ll n, k;
ll l, r;
ll chk[100010];

int main(void)
{
	scanf("%lld %lld", &n, &k);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld %lld %lld", &a[i].x, &a[i].y, &a[i].color);
	
	sort(a + 1, a + 1 + n);
	
	l = 0;
	r = 250010;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		ll ff = 0;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			vector< pair<ll, ll> > vec;
			
			for(ll j = 0 ; j <= k ; j++)
				chk[j] = 0;
			
			for(ll j = 1 ; j <= n ; j++)
			{
				if(a[i].x <= a[j].x && a[j].x <= a[i].x + mid)
					vec.push_back(make_pair(a[j].y, a[j].color));
			}
			
			ll p = 0;
			ll cou = 0;
			
			for(ll j = 0 ; j < vec.size() ; j++)
			{
				while(p < vec.size() && vec[p].first - vec[j].first <= mid)
				{
					chk[vec[p].second]++;
					
					if(chk[vec[p].second] == 1)
						cou++;
					
					p++;
				}
				
				if(cou == k)
					ff = 1;
				
				chk[vec[j].second]--;
				
				if(!chk[vec[j].second])
					cou--;
			}
		}
		
		if(ff)
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	printf("%lld", l);
	return 0;
}