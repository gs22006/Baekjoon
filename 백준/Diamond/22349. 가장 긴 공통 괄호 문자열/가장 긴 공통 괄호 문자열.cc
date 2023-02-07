#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

using namespace std;
typedef int ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

struct help
{
	ll X, Y, num;
};

ll SISIZ;

ll t;
char a[2000010], b[2000010];
ll n, m;
ll len;
ll grp[2000010], tmp[2000010];
help SA[2000010];
ll twoo;
ll LCP[2000010], last;
ll bun1, bun2;

struct lazysegtree
{
	ll seg[8000010], lazy[8000010];
	
	void init(ll no, ll s, ll e)
	{
		seg[no] = lazy[no] = 0;
		
		if(s == e)
			return;
		
		init(no << 1, s, (s + e) >> 1);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e);
	}
	
	void prop(ll no, ll s, ll e)
	{
		seg[no] += lazy[no];
		
		if(s != e)
		{
			lazy[no << 1] += lazy[no];
			lazy[no << 1 | 1] += lazy[no];
		}
		
		lazy[no] = 0;
	}
	
	void update(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			seg[no] += v;
			
			if(s != e)
			{
				lazy[no << 1] += v;
				lazy[no << 1 | 1] += v;
			}
			
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, l, r, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, v);
		
		if(seg[no << 1] <= seg[no << 1 | 1])
			seg[no] = seg[no << 1];
		else
			seg[no] = seg[no << 1 | 1];
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return 987654321;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return min(query(no << 1, s, (s + e) >> 1, l, r), query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r));
	}
	
	ll query2(ll no, ll s, ll e, ll v)
	{
		prop(no, s, e);
		
		if(s == e)
			return s;
		
		prop(no << 1, s, (s + e) >> 1);
		prop(no << 1 | 1, (s + e) >> 1 + 1, e);
		
		if(seg[no << 1] < v)
			return query2(no << 1, s, (s + e) >> 1, v);
		
		return query2(no << 1 | 1, ((s + e) >> 1) + 1, e, v);
	}
	
	ll query3(ll no, ll s, ll e, ll v)
	{
		prop(no, s, e);
		
		if(s == e)
			return s;
		
		prop(no << 1, s, (s + e) >> 1);
		prop(no << 1 | 1, (s + e) >> 1 + 1, e);
		
		if(seg[no << 1 | 1] == v)
			return query3(no << 1 | 1, ((s + e) >> 1) + 1, e, v);
		
		return query3(no << 1, s, (s + e) >> 1, v);
	}
}segt;

ll solve(ll X, ll Y)
{
	ll gap = 0;
	
	if(X)
		gap = segt.query(1, 0, n - 1, X - 1, X - 1);
	
	if(0 <= X - 1)
		segt.update(1, 0, n - 1, 0, X - 1, 17654321);
	
	if(Y + 1 <= n - 1)
		segt.update(1, 0, n - 1, Y + 1, n - 1, 17654321);
	
	ll w = Y + 1;
	
	if(segt.query(1, 0, n - 1, X, Y) < gap)
		w = segt.query2(1, 0, n - 1, gap);
	
	--w;
	
	if(w + 1 <= Y)
		segt.update(1, 0, n - 1, w + 1, Y, 17654321);
	
	ll ret = -1;
	
	if(segt.query(1, 0, n - 1, X, w) == gap)
		ret = max(ret, segt.query3(1, 0, n - 1, gap) - X + 1);
	
	if(0 <= X - 1)
		segt.update(1, 0, n - 1, 0, X - 1, -17654321);
	
	if(Y + 1 <= n - 1)
		segt.update(1, 0, n - 1, Y + 1, n - 1, -17654321);
	
	if(w + 1 <= Y)
		segt.update(1, 0, n - 1, w + 1, Y, -17654321);
	
	return ret;
}

help tmp2[8000010];
ll rdx[8000010];

void do_sort(void)
{
	for(ll i = 0 ; i <= SISIZ ; ++i)
		rdx[i] = 0;
	
	for(ll i = 0 ; i < len ; ++i)
		rdx[SA[i].Y]++;
	
	for(ll i = 1 ; i <= SISIZ ; ++i)
		rdx[i] += rdx[i - 1];
	
	for(ll i = len - 1 ; i >= 0 ; --i)
		tmp2[rdx[SA[i].Y]--] = SA[i];
	
	for(ll i = 0 ; i < len ; ++i)
		SA[i] = tmp2[i + 1];
	
	for(ll i = 0 ; i <= SISIZ ; ++i)
		rdx[i] = 0;
	
	for(ll i = 0 ; i < len ; ++i)
		rdx[SA[i].X]++;
	
	for(ll i = 1 ; i <= SISIZ ; ++i)
		rdx[i] += rdx[i - 1];
	
	for(ll i = len - 1 ; i >= 0 ; --i)
		tmp2[rdx[SA[i].X]--] = SA[i];
	
	for(ll i = 0 ; i < len ; ++i)
		SA[i] = tmp2[i + 1];
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> a >> b;
		
		n = strlen(a);
		m = strlen(b);
		
		segt.init(1, 0, n - 1);
		
		for(ll i = 0 ; i < n ; ++i)
		{
			if(a[i] == '(')
				segt.update(1, 0, n - 1, i, n - 1, 1);
			else
				segt.update(1, 0, n - 1, i, n - 1, -1);
		}
		
		len = n;
		
		a[len++] = '$';
		
		for(ll i = 0 ; i < m ; ++i)
			a[len++] = b[i];
		
		SISIZ = len + 2;
		
		for(ll i = 0 ; i < len ; ++i)
		{
			grp[i] = a[i] - '$' + 1;
			SISIZ = max(SISIZ, grp[i] + 1);
			LCP[i] = 0;
		}
		
		for(twoo = 1 ; ; twoo <<= 1)
		{
			for(ll i = 0 ; i < len ; ++i)
			{
				SA[i].X = grp[i] + 1;
				
				if(i + twoo >= len)
					SA[i].Y = 0;
				else
					SA[i].Y = grp[i + twoo] + 1;
				
				SA[i].num = i;
			}
			
			do_sort();
			
			ll cc = 0;
			
			grp[SA[0].num] = 0;
			
			for(ll i = 1 ; i < len ; ++i)
			{
				if(SA[i].X != SA[i - 1].X || SA[i].Y != SA[i - 1].Y)
					cc++;
				
				grp[SA[i].num] = cc;
			}
			
			if(cc == len - 1)
				break;
		}
		
		last = 0;
		
		for(ll i = 0 ; i < len ; ++i)
			tmp[SA[i].num] = i;
		
		for(ll i = 0 ; i < len ; ++i, last = max(0, last - 1))
		{
			bun1 = i;
			bun2 = 0;
			
			if(tmp[i] == len - 1)
			{
				LCP[i] = -1;
				continue;
			}
			
			bun2 = SA[tmp[i] + 1].num;
			
			for(ll j = last ; ; ++j)
			{
				if(bun1 + j >= len || bun2 + j >= len)
					break;
				
				if(a[bun1 + j] == a[bun2 + j])
					last++;
				else
					break;
			}
			
			LCP[i] = last;
		}
		
		ll ans = 0;
		
		for(ll i = 1 ; i < len ; ++i)
		{
			if(len - SA[i].num > m + 1 && len - SA[i + 1].num <= m)
			{
				if(SA[i].num <= SA[i].num + LCP[SA[i].num] - 1)
					ans = max(ans, solve(SA[i].num, SA[i].num + LCP[SA[i].num] - 1));
			}
			
			else if(len - SA[i].num <= m && len - SA[i + 1].num > m + 1)
			{
				if(SA[i + 1].num <= SA[i + 1].num + LCP[SA[i].num] - 1)
					ans = max(ans, solve(SA[i + 1].num, SA[i + 1].num + LCP[SA[i].num] - 1));
			}
		}
		
		cout << ans en;
	}
	
	return 0;
}