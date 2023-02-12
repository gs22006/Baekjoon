#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
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

ll n, m;
ll all, bll;
vector<ll> vec[100010];
ll IN[100010], OUT[100010];
ll cc;

struct segtree
{
	ll seg[400010];
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no] += v;
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
}segt;

void dfs(ll here, ll pa)
{
	IN[here] = ++cc;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs(i, here);
	}
	
	OUT[here] = cc;
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all;
		
		if(all == -1)
			continue;
		
		vec[i].push_back(all);
		vec[all].push_back(i);
	}
	
	dfs(1, 0);
	
	while(m--)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> all >> bll;
			segt.update(1, 1, cc, IN[all], bll);
			segt.update(1, 1, cc, OUT[all] + 1, -bll);
		}
		
		else
		{
			cin >> all;
			cout << segt.query(1, 1, cc, 1, IN[all]) en;
		}
	}
	
	return 0;
}