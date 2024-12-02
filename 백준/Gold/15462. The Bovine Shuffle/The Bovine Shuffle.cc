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
ll all;
vector<ll> vec[100010];
ll deg[100010];
ll ans;
queue<ll> q;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all;
		
		vec[i].push_back(all);
		deg[all]++;
	}
	
	ans = n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!deg[i])
			q.push(i), ans--;
	}
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		for(auto &i : vec[qq])
		{
			deg[i]--;
			
			if(!deg[i])
				q.push(i), ans--;
		}
	}
	
	cout << ans;
	return 0;
}