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
pll a[1000010], b[1000010];
vector<pll> A, B;
ll ans;

void dnc(ll s, ll e, ll l, ll r)
{
	if(s > e)
		return;
	
	ll maxx = -INF;
	ll w = -1;
	ll mid = (s + e) >> 1;
	
	for(ll i = l ; i <= r ; i++)
	{
		if((B[i].fi - A[mid].fi) > 0 && (B[i].fi - A[mid].fi) * (B[i].se - A[mid].se) > maxx)
		{
			maxx = (B[i].fi - A[mid].fi) * (B[i].se - A[mid].se);
			w = i;
		}
	}
	
	if(w == -1)
		return;
	
	ans = max(ans, maxx);
	
	dnc(s, mid - 1, l, w);
	dnc(mid + 1, e, w, r);
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	
	for(ll i = 1 ; i <= m ; i++)
		cin >> b[i].fi >> b[i].se;
	
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	
	ll last = a[1].se;
	A.push_back(a[1]);
	
	for(ll i = 2 ; i <= n ; i++)
	{
		if(a[i].fi == a[i - 1].fi)
			continue;
		
		if(a[i].se < last)
		{
			A.push_back(a[i]);
			last = a[i].se;
		}
	}
	
	last = b[m].se;
	B.push_back(b[m]);
	
	for(ll i = m - 1 ; i >= 1 ; i--)
	{
		if(b[i + 1].fi == b[i].fi)
			continue;
		
		if(b[i].se > last)
		{
			B.push_back(b[i]);
			last = b[i].se;
		}
	}
	
	reverse(B.begin(), B.end());
	dnc(0, (ll)A.size() - 1, 0, (ll)B.size() - 1);
	
	cout << ans;
	return 0;
}