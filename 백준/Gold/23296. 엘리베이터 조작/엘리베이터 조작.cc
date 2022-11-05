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

ll n;
ll a[100010];
ll deg[100010];
set< pair<ll, ll> > st;
vector<ll> ans;
ll chk[100010];
ll w;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		deg[a[i]]++;
	}
	
	for(ll i = 1 ; i <= n ; i++)
		st.insert({deg[i], i});
	
	w = 1;
	
	while(1)
	{
		if(!chk[w])
		{
			chk[w] = 1;
			st.erase({deg[w], w});
			ans.push_back(a[w]);
			w = a[w];
		}
		
		else
		{
			if(st.empty())
				break;
			
			auto p = st.begin();
			
			w = (*p).second;
			ans.push_back(w);
		}
	}
	
	cout << (ll)ans.size() en;
	
	for(auto &i : ans)
		cout << i sp;
	
	return 0;
}