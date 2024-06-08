#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;

ll n;
ll a[100010];
stack<ll> s;
ll ans;

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 0 ; i < n ; i++)
		scanf("%lld", &a[i]);
	
	for(ll i = 0 ; i <= n ; i++)
	{
		while(!s.empty() && a[i] < a[s.top()])
		{
			ll ss = s.top();
			s.pop();
			
			if(!s.empty())
				ans = max(ans, a[ss] * (i - s.top() - 1));
			else
				ans = max(ans, a[ss] * i);
		}
		
		s.push(i);
	}
	
	printf("%lld", ans);
	return 0;
}