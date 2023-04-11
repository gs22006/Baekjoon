#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL

ll n;
ll a[100010], b[100010];
ll w[100010];
ll yuk[100010];

struct maxsegtree
{
	ll seg[500010];
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(w < s || e < w)
			return;
		
		if(s == e)
		{
			seg[no] = v;
			return;
		}
		
		update(no * 2, s, (s + e) / 2, w, v);
		update(no * 2 + 1, (s + e) / 2 + 1, e, w, v);
		
		seg[no] = max(seg[no * 2], seg[no * 2 + 1]);
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(r < s || e < l)
			return MIN;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return max(query(no * 2, s, (s + e) / 2, l, r), query(no * 2 + 1, (s + e) / 2 + 1, e, l, r));
	}
}segt;

void f(ll s, ll e)
{
	if(s > e)
		return;
	
	ll rt = b[segt.query(1, 1, n, s, e)];
	
	printf("%lld ", rt);
	
	f(s, yuk[rt] - 1);
	f(yuk[rt] + 1, e);
}

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		scanf("%lld", &a[i]);
		yuk[a[i]] = i;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		scanf("%lld", &b[i]);
		w[b[i]] = i;
	}
	
	for(ll i = 1 ; i <= n ; i++)
		segt.update(1, 1, n, i, w[a[i]]);
	
	f(1, n);
	
	return 0;
}