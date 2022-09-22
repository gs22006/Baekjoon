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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

struct giji
{
	ll X, Y, A, B, num;
	
	bool operator < (const giji &xx) const
	{
		return X < xx.X;
	}
};

ll n;
giji a[250010];
pair< pair<ll, ll>, ll> b[250010];
ll ans[250010];
ll ff;

struct maxsegtree
{
	ll seg[2000010];
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
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
		if(e < l || r < s)
			return MIN;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return max(query(no * 2, s, (s + e) / 2, l, r), query(no * 2 + 1, (s + e) / 2 + 1, e, l, r));
	}
}segt1;

struct minsegtree
{
	ll seg[2000010];
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no] = v;
			return;
		}
		
		update(no * 2, s, (s + e) / 2, w, v);
		update(no * 2 + 1, (s + e) / 2 + 1, e, w, v);
		
		seg[no] = min(seg[no * 2], seg[no * 2 + 1]);
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return MAX;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return min(query(no * 2, s, (s + e) / 2, l, r), query(no * 2 + 1, (s + e) / 2 + 1, e, l, r));
	}
}segt2;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].X >> a[i].Y >> a[i].A >> a[i].B;
		a[i].num = i;
	}
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll gap = segt1.query(1, 1, n, 1, a[i].Y - 1);
		
		a[i].A = max(a[i].A, gap + 1);
		segt1.update(1, 1, n, a[i].Y, a[i].A);
		segt2.update(1, 1, n, a[i].Y, INF);
	}
	
	for(ll i = n ; i >= 1 ; i--)
	{
		ll gap = segt2.query(1, 1, n, a[i].Y + 1, n);
		
		a[i].B = min(a[i].B, gap - 1);
		segt2.update(1, 1, n, a[i].Y, a[i].B);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i].A > a[i].B)
			ff = 1;
		
		b[i] = {{a[i].A, a[i].B}, a[i].num};
	}
	
	sort(b + 1, b + 1 + n);
	
	ll p = 1;
	priority_queue< pair<ll, ll> > pq;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(p <= n && b[p].fi.fi <= i)
		{
			pq.push({-b[p].fi.se, b[p].se});
			p++;
		}
		
		if(pq.empty())
		{
			ff = 1;
			break;
		}
		
		pair<ll, ll> qq = pq.top();
		pq.pop();
		
		if(-qq.fi < i)
		{
			ff = 1;
			break;
		}
		
		ans[qq.se] = i;
	}
	
	if(ff)
	{
		cout << "NO";
		return 0;
	}
	
	cout << "YES\n";
	
	for(ll i = 1 ; i <= n ; i++)
		cout << ans[i] sp;
	
	return 0;
}