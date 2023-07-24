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
ll a[200010];
stack<pll> stk;
set<ll> st;
ll last;
ll ans[200010];
 
int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(st.find(a[i]) == st.end())
		{
			stk.push({a[i], i});
			st.insert(a[i]);
		}
		
		else
		{
			while(!stk.empty() && stk.top().fi != a[i])
			{
				st.erase(stk.top().fi);
				stk.pop();
			}
			
			stk.pop();
			stk.push({a[i], i});
		}
	}
	
	while(!stk.empty())
	{
		pll qq = stk.top();
		stk.pop();
		
		if(!stk.empty())
			last = stk.top().se + 1;
		else
			last = 1;
		
		for(ll i = last ; i <= qq.se ; i++)
			ans[i] = qq.fi;
	}
	
	for(ll i = 1 ; i <= n ; i++)
		cout << ans[i] en;
	
	return 0;
}