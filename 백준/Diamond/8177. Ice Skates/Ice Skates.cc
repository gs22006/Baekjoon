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

ll n, m, K, d;
ll all, bll;
ll now[200010];

struct node
{
	ll gap, L, R, sum;
};

struct segtree
{
	node seg[1000010];
	
	node merge(node X, node Y)
	{
		node ret;
		
		ret.sum = X.sum + Y.sum;
		ret.gap = max(0LL, max(max(X.gap, Y.gap), X.R + Y.L));
		ret.L = max(0LL, max(X.L, X.sum + Y.L));
		ret.R = max(0LL, max(Y.R, Y.sum + X.R));
		
		return ret;
	}
	
	void update(ll no, ll s, ll e, ll w)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no].gap = seg[no].L = seg[no].R = max(0LL, now[w]);
			seg[no].sum = now[w];
			
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, w);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, w);
		
		seg[no] = merge(seg[no << 1], seg[no << 1 | 1]);
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n >> m >> K >> d;
	
	for(ll i = 0 ; i < 1000010 ; i++)
		segt.seg[i] = {0, 0, 0, 0};
	
	for(ll i = 1 ; i <= n ; i++)
	{
		now[i] = -K;
		segt.update(1, 1, n - d, i);
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll;
		
		now[all] += bll;
		segt.update(1, 1, n - d, all);
		
		if(segt.seg[1].gap - K * d > 0)
			cout << "NIE\n";
		else
			cout << "TAK\n";
	}
	
	return 0;
}