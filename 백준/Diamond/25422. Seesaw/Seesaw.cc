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

struct gujo
{
	ll ja, mo;
	
	bool operator < (const gujo &xx) const
	{
		return (ld)ja / (ld)mo < (ld)xx.ja / (ld)xx.mo;
	}
};

ll n;
ll a[200010];
ll nu[200010];
ll L[200010];
gujo gap[200010];
ld ans = INF;
set<gujo> st;
pair<gujo, ll> b[200010];

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		nu[i] = nu[i - 1] + a[i];
	}
	
	if(n == 1)
	{
		cout << 0;
		return 0;
	}
	
	for(ll len = 0 ; len < n - 1 ; len++)
	{
		ll l = 1, r = n - len;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if((ld)(nu[mid + len] - nu[mid - 1]) / (ld)(len + 1) >= (ld)nu[n] / (ld)n)
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		L[len] = r;
	}
	
	ll cc = 0;
	
	for(ll i = 0 ; i < n - 1 ; i++)
	{
		if(L[i] == n - i)
			gap[i] = {-1, 1};
		else
			gap[i] = {nu[L[i] + 1 + i] - nu[L[i]], i + 1};
		
		st.insert(gap[i]);
		
		if(L[i] >= 1)
			b[cc++] = {{nu[L[i] + i] - nu[L[i] - 1], i + 1}, i};
	}
	
	sort(b, b + cc);
	reverse(b, b + cc);
	st.insert({nu[n], n});
	
	gujo gapp = (*st.rbegin());
	
	if(gapp.ja != -1)
		ans = min(ans, (ld)gapp.ja / (ld)gapp.mo - (ld)nu[n] / (ld)n);
	
	for(ll i = 0 ; i < cc ; i++)
	{
		st.erase(gap[b[i].se]);
		st.insert(b[i].fi);
		
		gapp = (*st.rbegin());
		ans = min(ans, (ld)gapp.ja / (ld)gapp.mo - (ld)b[i].fi.ja / (ld)b[i].fi.mo);
	}
	
	cout << ans;
	return 0;
}