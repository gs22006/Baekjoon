#include <bits/stdc++.h>
 
using namespace std;
typedef int ll;
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
ll a[1000010];
vector<ll> zip;
ll w[1000010];
ll gu[1000010];
ll rt[1000010];
ll q;
ll l, r;
ll ans;
vector<ll> S, E;

struct node
{
	ll L, R, gap;
};

struct persistentsegtree
{
	vector<node> seg;
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
			return;
		
		seg[no].L = (ll)seg.size();
		seg.push_back({-1, -1, 0});
		seg[no].R = (ll)seg.size();
		seg.push_back({-1, -1, 0});
		
		init(seg[no].L, s, (s + e) >> 1);
		init(seg[no].R, ((s + e) >> 1) + 1, e);
	}
	
	void update(ll no, ll last, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no].gap += v;
			return;
		}
		
		ll mid = (s + e) >> 1;
		
		if(s <= w && w <= mid)
		{
			seg[no].L = (ll)seg.size();
			seg.push_back({-1, -1, 0});
			seg[no].R = seg[last].R;
			update(seg[no].L, seg[last].L, s, mid, w, v);
		}
		
		else
		{
			seg[no].L = seg[last].L;
			seg[no].R = (ll)seg.size();
			seg.push_back({-1, -1, 0});
			update(seg[no].R, seg[last].R, mid + 1, e, w, v);
		}
		
		seg[no].gap = 0;
		
		if(seg[no].L != -1)
			seg[no].gap += seg[seg[no].L].gap;
		
		if(seg[no].R != -1)
			seg[no].gap += seg[seg[no].R].gap;
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no].gap;
		
		ll ret = 0;
		
		if(seg[no].L != -1)
			ret += query(seg[no].L, s, (s + e) >> 1, l, r);
		
		if(seg[no].R != -1)
			ret += query(seg[no].R, ((s + e) >> 1) + 1, e, l, r);
		
		return ret;
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		zip.push_back(a[i]);
	}
	
	compress(zip);
	
	for(ll i = 1 ; i <= n ; i++)
		a[i] = lower_bound(zip.begin(), zip.end(), a[i]) - zip.begin() + 1;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!w[a[i]])
			S.push_back(i);
		
		if(w[a[i]] && i - w[a[i]] >= 2)
			gu[w[a[i]] + 1] = i - 1;
		
		w[a[i]] = i;
	}
	
	for(ll i = 1 ; i <= (ll)zip.size() ; i++)
		E.push_back(w[i]);
	
	sort(S.begin(), S.end());
	sort(E.begin(), E.end());
	
	segt.seg.push_back({-1, -1, 0});
	segt.init(0, 1, n);
	rt[0] = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		rt[i] = (ll)segt.seg.size();
		segt.seg.push_back({-1, -1, 0});
		
		if(!gu[i])
			segt.update(rt[i], rt[i - 1], 1, n, 1, 0);
		else
			segt.update(rt[i], rt[i - 1], 1, n, gu[i], 1);
	}
	
	cin >> q;
	
	while(q--)
	{
		cin >> l >> r;
		
		l += ans;
		ans = (ll)zip.size() - segt.query(rt[l], 1, n, r, n);
		ans -= S.end() - upper_bound(S.begin(), S.end(), r);
		ans -= lower_bound(E.begin(), E.end(), l) - E.begin();
		
		cout << ans en;
	}
	
	return 0;
}