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
ll a[100010];
stack<ll> stk;
ll chk[100010];
vector<ll> ans;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n * 2 ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n * 2 ; i++)
	{
		if(!chk[a[i]])
		{
			stk.push(a[i]);
			chk[a[i]] = 1;
		}
		
		else
		{
			vector<ll> vec;
			
			while(stk.top() != a[i])
			{
				ans.push_back((ll)stk.size());
				vec.push_back(stk.top());
				stk.pop();
			}
			
			stk.pop();
			
			reverse(vec.begin(), vec.end());
			
			for(auto &i : vec)
				stk.push(i);
		}
	}
	
	cout << (ll)ans.size() en;
	
	for(auto &i : ans)
		cout << i en;
	
	return 0;
}