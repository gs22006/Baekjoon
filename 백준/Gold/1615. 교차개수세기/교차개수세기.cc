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

ll n, m;
ll all, bll;
vector<ll> edg[2010];
ll ans;

struct segtree
{
	ll K;
	ll seg[1000010];
	
	void init(ll siz)
	{
		K = 1;
		
		while(K <= siz)
			K *= 2;
	}
	
	void update(ll w, ll v)
	{
		w += K;
		
		while(w)
		{
			seg[w] += v;
			w >>= 1;
		}
	}
	
	ll query(ll l, ll r)
	{
		ll ret = 0;
		
		l += K;
		r += K;
		
		while(l <= r)
		{
			if(l == r)
			{
				ret += seg[l];
				break;
			}
			
			if(l & 1)
			{
				ret += seg[l];
				l++;
			}
			
			if(!(r & 1))
			{
				ret += seg[r];
				r--;
			}
			
			l >>= 1;
			r >>= 1;
		}
		
		return ret;
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll;
		edg[all].push_back(bll);
	}
	
	segt.init(n + 10);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(auto &j : edg[i])
			ans += segt.query(j + 1, n);
		
		for(auto &j : edg[i])
			segt.update(j, 1);
	}
	
	cout << ans;
	return 0;
}