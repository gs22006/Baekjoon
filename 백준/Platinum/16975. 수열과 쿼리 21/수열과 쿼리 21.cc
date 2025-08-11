#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, k;
ll all, bll, cll;
ll seg[5000010], lazy[5000010];
ll a[5000010];

ll sta(ll no, ll s, ll e)
{
	if(s == e)
		return seg[no] = a[s];
	
	ll mid = (s + e) / 2;
	ll lef = sta(no * 2, s, mid);
	ll rig = sta(no * 2 + 1, mid + 1, e);
	
	return seg[no] = lef + rig;
}

ll update(ll no, ll s, ll e, ll l, ll r, ll v)
{
	if(lazy[no] != 0)
	{
		seg[no] += lazy[no] * (e - s + 1);
		
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
		seg[no] += v * (e - s + 1);
		
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
	
	return seg[no] = al + bl;
}

ll query(ll no, ll s, ll e, ll l, ll r)
{
	if(lazy[no] != 0)
	{
		seg[no] += lazy[no] * (e - s + 1);
		
		if(s != e)
		{
			lazy[no * 2] += lazy[no];
			lazy[no * 2 + 1] += lazy[no];
		}
		
		lazy[no] = 0;
	}
	
	if(l > e || r < s)
		return 0;
	
	if(l <= s && e <= r)
		return seg[no];
	
	ll mid = (s + e) / 2;
	ll lef = query(no * 2, s, mid, l, r);
	ll rig = query(no * 2 + 1, mid + 1, e, l, r);
	
	return lef + rig;
}

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld", &a[i]);
	
	sta(1, 1, n);
	
	scanf("%lld", &m);
	
	while(m--)
	{
		scanf("%lld", &all);
		
		if(all == 2)
		{
			scanf("%lld", &bll);
			printf("%lld\n", query(1, 1, n, bll, bll));
		}
		
		else if(all == 1)
		{
			scanf("%lld %lld %lld", &all, &bll, &cll);
			update(1, 1, n, all, bll, cll);
		}
	}
	
	return 0;
}