#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

ll t;
ll n;
ll a[1000010];
ll m;
ll b[1000010];
set<ll> st;

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		st.clear();
		
		cin >> n;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			cin >> a[i];
			st.insert(a[i]);
		}
		
		cin >> m;
		
		for(ll i = 1 ; i <= m ; i++)
		{
			cin >> b[i];
			cout << st.count(b[i]) en;
		}
	}
	
	return 0;
}