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

ll t;
ll n;
ll a[100010];
ll deg[100010];
queue<ll> q;

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		ll ans = 0;
		
		cin >> n;
		
		for(ll i = 1 ; i <= n ; i++)
			cin >> a[i];
		
		for(ll i = 1 ; i <= n ; i++)
			deg[i] = 0;
		
		for(ll i = 1 ; i <= n ; i++)
			deg[a[i]]++;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(!deg[i])
				q.push(i);
		}
		
		while(!q.empty())
		{
			ll qq = q.front();
			q.pop();
			
			ans++;
			deg[a[qq]]--;
			
			if(!deg[a[qq]])
				q.push(a[qq]);
		}
		
		cout << ans en;
	}
	
	return 0;
}