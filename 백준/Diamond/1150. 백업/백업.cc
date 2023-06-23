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

ll n, K;
ll a[100010];
ll L[100010], R[100010];
ll ans;
set<pll> st;
map<pll, ll> mp;

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
		L[i] = i - 1, R[i] = i + 1;
	
	for(ll i = 1 ; i < n ; i++)
	{
		mp[{i, i + 1}] = a[i + 1] - a[i];
		st.insert({a[i + 1] - a[i], i});
	}
	
	while(K--)
	{
		auto p = st.begin();
		pll gap = (*p);
		st.erase(p);
		
		ans += gap.fi;
		
		ll w1 = gap.se;
		ll w2 = R[w1];
		ll LL = L[w1];
		ll RR = R[w2];
		
		L[RR] = LL;
		R[LL] = RR;
		
		if(LL > 0)
			st.erase({mp[{LL, w1}], LL});
		
		if(RR <= n)
			st.erase({mp[{w2, RR}], w2});
		
		if(1 <= LL && RR <= n)
		{
			mp[{LL, RR}] = mp[{LL, w1}] + mp[{w2, RR}] - mp[{w1, w2}];
			st.insert({mp[{LL, RR}], LL});
		}
	}
	
	cout << ans;
	return 0;
}