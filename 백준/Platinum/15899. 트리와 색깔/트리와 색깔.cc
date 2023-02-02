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

ll n, m, C;
ll a[200010], b[200010];
vector<ll> vec[200010];
ll all, bll;
ll IN[200010], OUT[200010];
ll cc;
ll ans;
ll ss = 1000000007;

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

struct mergesorttree
{
	vector<ll> seg[800010];
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
		{
			seg[no].push_back(b[s]);
			return;
		}
		
		init(no * 2, s, (s + e) / 2);
		init(no * 2 + 1, (s + e) / 2 + 1, e);
		
		for(auto &i : seg[no * 2])
			seg[no].push_back(i);
		
		for(auto &i : seg[no * 2 + 1])
			seg[no].push_back(i);
		
		sort(seg[no].begin(), seg[no].end());
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
		{
			ll L = 0, R = (ll)seg[no].size() - 1;
			
			while(L <= R)
			{
				ll mid = (L + R) / 2;
				
				if(seg[no][mid] <= v)
					L = mid + 1;
				else
					R = mid - 1;
			}
			
			return L;
		}
		
		return query(no * 2, s, (s + e) / 2, l, r, v) + query(no * 2 + 1, (s + e) / 2 + 1, e, l, r, v);
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n >> m >> C;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	dfs(1, 0);
	
	for(ll i = 1 ; i <= n ; i++)
		b[IN[i]] = a[i];
	
	segt.init(1, 1, cc);
	
	while(m--)
	{
		cin >> all >> bll;
		ans = (ans + segt.query(1, 1, cc, IN[all], OUT[all], bll)) % ss;
	}
	
	cout << ans;
	return 0;
}