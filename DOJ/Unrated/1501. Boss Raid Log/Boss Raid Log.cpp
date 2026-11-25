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

ll k, m, n, d;
ll a[200010];
ll b[200010];
ll now[200010];
ll ans1[200010], ans2[200010];

void input(void)
{
	cin >> k >> m >> n >> d;
	
	for(ll i = 1 ; i <= m ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> b[i];
}

void solve2(void)
{
	for(ll i = 1 ; i <= k ; i++)
		now[i] = 0;
	
	now[a[1]] = 1;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ans2[i] = now[b[i]];
		
		if(i >= d && ans2[i - d + 1])
			now[a[ans2[i - d + 1] + 1]] = max(now[a[ans2[i - d + 1] + 1]], ans2[i - d + 1] + 1);
	}
}

void solve(void)
{
	solve2();
	
	for(ll i = 1 ; i <= n ; i++)
		ans1[i] = ans2[i];
	
	reverse(a + 1, a + 1 + m);
	reverse(b + 1, b + 1 + n);
	solve2();
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(ans1[i] < m - ans2[n - i + 1] + 1)
		{
			cout << "NO";
			return;
		}
	}
	
	cout << "YES";
}

int main(void)
{
	fastio
	
	input();
	solve();
	
	return 0;
}