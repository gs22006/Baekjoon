#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define fi first
#define se second

ll n;
ll a[200010];
ll L[200010], R[200010];
set<ll> st;
pair<ll, ll> b[200010];
ll ans[200010], gap1[200010], gap2[200010];
ll now;
ll bt[200010];

struct segtree
{
	ll seg[1000010];

	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no] = v;
			return;
		}

		update(no << 1, s, (s + e) >> 1, w, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, w, v);

		seg[no] = seg[no << 1] + seg[no << 1 | 1];
	}

	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return query(no << 1, s, (s + e) >> 1, l, r) + query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
	}
}nu, gw;

ll find_left(ll X)
{
	if(X == -1)
		return -1;

	auto p = st.lower_bound(X);

	if(p == st.begin())
		return -1;
	
	p--;
	return (*p);
}

ll find_right(ll X)
{
	if(X == -1)
		return -1;

	auto p = st.upper_bound(X);

	if(p == st.end())
		return -1;
	
	return (*p);
}

ll get_gap(ll X)
{
	ll LF = find_left(X);
	ll AI = X - LF;
	ll IDX = X;
	ll AI2 = 0;
	ll RG = find_right(X);
	ll RG2 = find_right(RG);
	ll IDX2 = 0;

	if(RG2 != -1)
		AI2 = RG2 - RG;
	
	if(RG != -1)
		IDX2 = n + 1 - RG;
	
	return AI2 * IDX - AI * IDX2;
}

void f(ll X)
{
	if(X == -1)
		return;

	ll ngw = gw.query(1, 1, n, X, X);
	ll nnu = nu.query(1, 1, n, 1, X);
	ll gp;

	now -= ngw * nnu;
	gp = get_gap(X);
	now += nnu * gp;

	gw.update(1, 1, n, X, gp);
}

void nupdate(ll X)
{
	if(X == -1)
		return;

	ll LF = find_left(X);
	ll RG = find_right(X);
	ll nw = 0;

	if(LF == 0 || LF == -1 || RG == n + 1 || RG == -1)
		nw = 0;
	else if(a[LF] < a[X] && a[X] > a[RG])
		nw = 1;
	else if(a[LF] > a[X] && a[X] < a[RG])
		nw = 1;
	
	ll AL = nw - bt[X];
	now += gw.query(1, 1, n, X, n) * AL;
	bt[X] = nw;
	nu.update(1, 1, n, X, nw);
}

int main(void)
{
	scanf("%lld", &n);

	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld", &a[i]);
	
	st.insert(0);
	st.insert(n + 1);

	for(ll i = 1 ; i <= n ; i++)
		b[i] = {a[i], i};
	
	sort(b + 1, b + 1 + n);

	for(ll i = 1 ; i <= n ; i++)
	{
		ll W = b[i].se;
		ll L1 = find_left(W);
		ll R1 = find_right(W);
		ll L2 = find_left(L1);
		st.insert(W);

		f(L1);
		f(R1);
		f(L2);
		f(W);
		nupdate(L1);
		nupdate(W);
		nupdate(R1);

		ans[i] = now;
		
		gap2[i] = gap2[i - 1] + (W - L1) * (R1 - W);
		gap1[i] = gap1[i - 1];

		ll R2 = find_right(R1);
		ll GI = R1 - L1;
		ll AA = R1 - W;
		ll BB = W - L1;

		if(L2 != -1)
		{
			gap1[i] -= (L1 - L2) * GI;
			gap1[i] += (L1 - L2) * BB;
		}

		if(R2 != -1)
		{
			gap1[i] -= (R2 - R1) * GI;
			gap1[i] += (R2 - R1) * AA;
		}

		gap1[i] += AA * BB;
	}
	
	for(ll i = 1 ; i <= n ; i++)
		printf("%lld\n", ans[i] - gap1[i] + 2 * gap2[i]);
	
	return 0;
}