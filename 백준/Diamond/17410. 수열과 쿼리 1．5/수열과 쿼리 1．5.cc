#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n;
ll a[100010];
ll num[100010];
ll sq;
ll m;
ll all, bll, cll;
vector<ll> vec[510];

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(sq = 1 ; sq * sq <= n ; sq++);
	sq--;
	
	for(ll i = 1 ; i <= n ; i++)
		num[i] = (i - 1) / sq;
	
	for(ll i = 1 ; i <= n ; i++)
		vec[num[i]].push_back(a[i]);
	
	for(ll i = 0 ; i <= num[n] ; i++)
		sort(vec[i].begin(), vec[i].end());
	
	cin >> m;
	
	while(m--)
	{
		cin >> all;
		
		if(all == 1)
		{
			vector<ll> tmp;
			ll ff = 0, gg = 0;
			
			cin >> all >> bll;
			
			for(ll i : vec[num[all]])
			{
				if(i > bll && !ff)
				{
					ff = 1;
					tmp.push_back(bll);
				}
				
				if(i == a[all] && !gg)
				{
					gg = 1;
					continue;
				}
				
				tmp.push_back(i);
			}
			
			if(!ff)
				tmp.push_back(bll);
			
			vec[num[all]] = tmp;
			a[all] = bll;
		}
		
		else
		{
			cin >> all >> bll >> cll;
			
			ll num1 = num[all], num2 = num[bll];
			ll ans = 0;
			
			if(num1 == num2)
			{
				for(ll i = all ; i <= bll ; i++)
				{
					if(a[i] > cll)
						ans++;
				}
			}
			
			else
			{
				for(ll i = all ; num[i] == num1 ; i++)
				{
					if(a[i] > cll)
						ans++;
				}
				
				for(ll i = bll ; num[i] == num2 ; i--)
				{
					if(a[i] > cll)
						ans++;
				}
				
				for(ll i = num1 + 1 ; i < num2 ; i++)
					ans += vec[i].end() - upper_bound(vec[i].begin(), vec[i].end(), cll);
			}
			
			cout << ans << '\n';
		}
	}
	
	return 0;
}