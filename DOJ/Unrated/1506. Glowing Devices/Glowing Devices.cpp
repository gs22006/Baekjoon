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

ll n;
pll a[100010];
vector<ll> vec[100010];
ll X[100010];

void input(void)
{
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].se;
}

void solve(void)
{
	for(ll i = 1 ; i <= n ; i++)
		vec[a[i].fi].push_back(a[i].se);
	
	ll sum = 0;
	ll ans = 0, cou = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		X[i] = i - sum;
		sum += (ll)vec[i].size();
	}
	
	priority_queue<ll> pq;
	
	for(ll i = n ; i >= 1 ; i--)
	{
		for(auto &j : vec[i])
			pq.push(-j);
		
		while(cou < X[i])
		{
			ans -= pq.top();
			pq.pop();
			cou++;
		}
	}
	
	cout << ans;
}

int main(void)
{
	fastio
	
	input();
	solve();
	
	return 0;
}