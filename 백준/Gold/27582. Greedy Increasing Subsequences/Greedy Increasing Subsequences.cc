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
set<pll> st;
ll nxt[200010];
vector< vector<ll> > ans;
ll chk[200010];
vector<ll> tmp;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	st.insert({a[1], -1});
	
	for(ll i = 2 ; i <= n ; i++)
	{
		auto p = st.lower_bound({a[i], -i});
		
		if(p != st.begin())
		{
			p--;
			nxt[-(*p).se] = i;
			st.erase(*p);
		}
		
		st.insert({a[i], -i});
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(chk[i])
			continue;
		
		ll now = i;
		
		tmp.clear();
		
		while(1)
		{
			tmp.push_back(now);
			
			if(!nxt[now])
				break;
			
			now = nxt[now];
			chk[now] = 1;
		}
		
		ans.push_back(tmp);
	}
	
	cout << (ll)ans.size() en;
	
	for(auto &i : ans)
	{
		for(auto &j : i)
			cout << a[j] sp;
		
		cout en;
	}
	
	return 0;
}