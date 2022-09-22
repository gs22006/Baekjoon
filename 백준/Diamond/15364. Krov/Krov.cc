#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define fi first
#define se second

ll n;
ll a[100010];
ll P[100010], M[100010];
vector<ll> ZIP;
map<ll, ll> zip;
ll gap[400010];
ll cc;
ll ans = MAX;

struct segt
{
	ll seg[2000010];
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(w < s || e < w)
			return;
		
		if(s == e)
		{
			seg[no] += v;
			return;
		}
		
		update(no * 2, s, (s + e) / 2, w, v);
		update(no * 2 + 1, (s + e) / 2 + 1, e, w, v);
		
		seg[no] = seg[no * 2] + seg[no * 2 + 1];
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return query(no * 2, s, (s + e) / 2, l, r) + query(no * 2 + 1, (s + e) / 2 + 1, e, l, r);
	}
}segt1, segt2, segt3, segt4;

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		scanf("%lld", &a[i]);
		
		P[i] = a[i] + i;
		M[i] = a[i] - i;
		
		ZIP.push_back(P[i]);
		ZIP.push_back(M[i]);
	}
	
	sort(ZIP.begin(), ZIP.end());
	
	for(ll i = 0 ; i < ZIP.size() ; i++)
	{
		if(i != 0 && ZIP[i] == ZIP[i - 1])
			continue;
		
		zip[ZIP[i]] = ++cc;
		gap[cc] = ZIP[i];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		segt1.update(1, 1, cc, zip[P[i]], 1);
		segt3.update(1, 1, cc, zip[P[i]], P[i]);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll l = -10000000LL;
		ll r = 100000000000LL;
		
		while(l <= r)
		{
			ll mid = (l + r) / 2;
			
			ll L = 1;
			ll R = cc;
			
			while(L <= R)
			{
				ll MID = (L + R) / 2;
				
				if(gap[MID] <= mid + i)
					L = MID + 1;
				else
					R = MID - 1;
			}
			
			ll gapp = segt1.query(1, 1, cc, 1, R);
			
			L = 1;
			R = cc;
			
			while(L <= R)
			{
				ll MID = (L + R) / 2;
				
				if(gap[MID] <= mid - i)
					L = MID + 1;
				else
					R = MID - 1;
			}
			
			gapp += segt2.query(1, 1, cc, 1, R);
			
			if(gapp >= (n + 1) / 2)
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		ll tired = min(l - i + 1, l - n + i);
		
		if(tired <= 0)
			l += 1 - tired;
		
		ll L = 1;
		ll R = cc;
		
		while(L <= R)
		{
			ll MID = (L + R) / 2;
			
			if(gap[MID] <= l + i)
				L = MID + 1;
			else
				R = MID - 1;
		}
		
		ll hubo = 0;
		ll gaet = segt1.query(1, 1, cc, 1, R);
		ll hap = segt3.query(1, 1, cc, 1, R);
		
		hubo += gaet * (l + i) - hap;
		
		gaet = segt1.query(1, 1, cc, R + 1, cc);
		hap = segt3.query(1, 1, cc, R + 1, cc);
		
		hubo += hap - gaet * (l + i);
		
		L = 1;
		R = cc;
		
		while(L <= R)
		{
			ll MID = (L + R) / 2;
			
			if(gap[MID] <= l - i)
				L = MID + 1;
			else
				R = MID - 1;
		}
		
		gaet = segt2.query(1, 1, cc, 1, R);
		hap = segt4.query(1, 1, cc, 1, R);
		
		hubo += gaet * (l - i) - hap;
		
		gaet = segt2.query(1, 1, cc, R + 1, cc);
		hap = segt4.query(1, 1, cc, R + 1, cc);
		
		hubo += hap - gaet * (l - i);
		
		ans = min(ans, hubo);
		
		segt1.update(1, 1, cc, zip[P[i]], -1);
		segt3.update(1, 1, cc, zip[P[i]], -P[i]);
		segt2.update(1, 1, cc, zip[M[i]], 1);
		segt4.update(1, 1, cc, zip[M[i]], M[i]);
	}
	
	printf("%lld", ans);
	return 0;
}