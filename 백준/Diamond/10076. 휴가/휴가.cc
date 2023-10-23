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

ll n, S, D;
ll a[100010];
ll b[100010];
ll won[100010];
ll rt[100010];
vector<ll> zip;
ll ans;
ll siz;

struct node
{
	pair<int, ll> gap;
	int L, R;
};

struct PST
{
	node seg[2000010];
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
			return;
		
		seg[no].L = siz;
		seg[siz++] = {{0, 0}, -1, -1};
		seg[no].R = siz;
		seg[siz++] = {{0, 0}, -1, -1};
		
		init(seg[no].L, s, (s + e) >> 1);
		init(seg[no].R, ((s + e) >> 1) + 1, e);
	}
	
	void update(ll no, ll last, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no].gap.fi = seg[last].gap.fi + 1;
			seg[no].gap.se = seg[last].gap.se + v;
			return;
		}
		
		ll mid = (s + e) >> 1;
		
		if(s <= w && w <= mid)
		{
			seg[no].R = seg[last].R;
			seg[no].L = siz;
			seg[siz++] = {{0, 0}, -1, -1};
			
			update(seg[no].L, seg[last].L, s, mid, w, v);
		}
		
		else
		{
			seg[no].L = seg[last].L;
			seg[no].R = siz;
			seg[siz++] = {{0, 0}, -1, -1};
			
			update(seg[no].R, seg[last].R, mid + 1, e, w, v);
		}
		
		seg[no].gap.fi = seg[seg[no].L].gap.fi + seg[seg[no].R].gap.fi;
		seg[no].gap.se = seg[seg[no].L].gap.se + seg[seg[no].R].gap.se;
	}
	
	ll kth(ll noL, ll noR, ll s, ll e, ll K)
	{
		if(s == e)
		{
			if(seg[noR].gap.fi - seg[noL].gap.fi >= K)
				return s;
			
			return 0;
		}
		
		if(seg[seg[noR].R].gap.fi - seg[seg[noL].R].gap.fi >= K)
			return kth(seg[noL].R, seg[noR].R, ((s + e) >> 1) + 1, e, K);
		
		return kth(seg[noL].L, seg[noR].L, s, (s + e) >> 1, K - seg[seg[noR].R].gap.fi + seg[seg[noL].R].gap.fi);
	}
	
	pll query2(ll noL, ll noR, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return {0, 0};
		
		if(l <= s && e <= r)
			return {seg[noR].gap.fi - seg[noL].gap.fi, seg[noR].gap.se - seg[noL].gap.se};
		
		pll QL = query2(seg[noL].L, seg[noR].L, s, (s + e) >> 1, l, r);
		pll QR = query2(seg[noL].R, seg[noR].R, ((s + e) >> 1) + 1, e, l, r);
		
		return {QL.fi + QR.fi, QL.se + QR.se};
	}
	
	ll query(ll L, ll R, ll K)
	{
		if(K <= 0)
			return 0;
		
		L = max(L, 1LL);
		R = min(R, n);
		
		ll Kth = kth(rt[L - 1], rt[R], 1, n, K);
		pll ret = query2(rt[L - 1], rt[R], 1, n, Kth + 1, n);
		
		return ret.se + (K - ret.fi) * won[Kth];
	}
}segt;

void dnc(ll Rl, ll Rr, ll Ll, ll Lr)
{
	ll mid = (Rl + Rr) >> 1;
	ll maxx = 0, w = Ll;
	
	if(Rl > Rr)
		return;
	
	for(ll i = Ll ; i <= Lr ; i++)
	{
		ll gap = segt.query(S - i, S + mid, D - 2 * mid - i);
		//cout << "*" << S - i sp << S + mid sp << D - 2 * mid - i sp << gap en;
		if(maxx < gap)
		{
			maxx = gap;
			w = i;
		}
	}
	
	ans = max(ans, maxx);
	
	dnc(Rl, mid - 1, w, Lr);
	dnc(mid + 1, Rr, Ll, w);
}

void solve(void)
{
	for(ll i = 1 ; i <= n ; i++)
		b[i] = won[i] = rt[i] = 0;
	
	zip.clear();
	
	for(ll i = 1 ; i <= n ; i++)
		zip.push_back(a[i]);
	
	compress(zip);
	
	rt[0] = 0;
	siz = 0;
	segt.seg[siz++] = {{0, 0}, -1, -1};
	segt.init(0, 1, n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		b[i] = lower_bound(zip.begin(), zip.end(), a[i]) - zip.begin() + 1;
		won[b[i]] = a[i];
		
		rt[i] = siz;
		segt.seg[siz++] = {{0, 0}, -1, -1};
		segt.update(rt[i], rt[i - 1], 1, n, b[i], a[i]);
	}
	
	dnc(0, n, 0, n);
}

int main(void)
{
	fastio
	
	cin >> n >> S >> D;
	
	S++;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	solve();
	//cout << "REV\n";
	reverse(a + 1, a + 1 + n);
	S = n + 1 - S;
	solve();
	
	cout << ans;
	return 0;
}