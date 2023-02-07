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

ll L, n, C;
ll all;
set<ll> st;
ll a[10010];
ll dp[10010];
ll l, r;

ll solve(ll X)
{
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i] - a[i + 1] > X)
			return -1;
	}
	
	for(ll i = 1 ; i <= n ; i++)
		dp[i] = 0;
	
	deque< pair<ll, ll> > dq;
	
	dp[1] = 0;
	dq.push_back({a[1], 0});
	
	for(ll i = 2 ; i <= n ; i++)
	{
		while(!dq.empty() && dq.front().fi - a[i] > X)
			dq.pop_front();
		
		dp[i] = dq.front().se + 1;
		
		while(!dq.empty() && dq.front().se > dp[i])
			dq.pop_back();
		
		dq.push_back({a[i], dp[i]});
	}
	
	ll minn = INF;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i] <= X && dp[i] <= C)
			minn = min(minn, a[i]);
	}
	
	return minn;
}

int main(void)
{
	fastio
	
	cin >> L >> n >> C;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all;
		st.insert(all);
	}
	
	st.insert(L);
	
	n = 0;
	
	for(auto &i : st)
		a[++n] = i;
	
	reverse(a + 1, a + 1 + n);
	
	l = 0, r = L;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		ll gap = solve(mid);
		
		if(gap == -1 || gap == INF)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	cout << l sp << solve(l) en;
	return 0;
}