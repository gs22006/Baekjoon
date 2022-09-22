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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

ll n, m;
ll all;
ordered_set st;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all;
		st.insert(all);
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all;
		
		if(st.find(all) != st.end())
			st.erase(all);
	}
	
	cout << (ll)st.size() en;
	
	for(auto &i : st)
		cout << i sp;
	
	return 0;
}