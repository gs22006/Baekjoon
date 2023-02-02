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

ll n;
ll a[100010];
ll m;
ll all, bll, cll;

struct mergesorttree
{
	vector<ll> seg[400010];
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
		{
			seg[no].push_back(a[s]);
			return;
		}
		
		init(no * 2, s, (s + e) / 2);
		init(no * 2 + 1, (s + e) / 2 + 1, e);
		
		ll l = 0, r = 0;
		ll L = no * 2, R = no * 2 + 1;
		
		while(1)
		{
			if(l == (ll)seg[L].size() && r == (ll)seg[R].size())
				break;
			
			if(l == (ll)seg[L].size())
				seg[no].push_back(seg[R][r++]);
			else if(r == (ll)seg[R].size())
				seg[no].push_back(seg[L][l++]);
			
			else
			{
				if(seg[L][l] < seg[R][r])
					seg[no].push_back(seg[L][l++]);
				else
					seg[no].push_back(seg[R][r++]);
			}
		}
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
			
			return (ll)seg[no].size() - L;
		}
		
		return query(no * 2, s, (s + e) / 2, l, r, v) + query(no * 2 + 1, (s + e) / 2 + 1, e, l, r, v);
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	segt.init(1, 1, n);
	
	cin >> m;
	
	while(m--)
	{
		cin >> all >> bll >> cll;
		cout << segt.query(1, 1, n, all, bll, cll) en;
	}
	
	return 0;
}