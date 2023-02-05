#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
 
ll n;
ll a[100010];
set<ll> ans;
 
int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld", &a[i]);
	
	printf("3\n");
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(1 <= a[i] && a[i] <= n / 4)
		{
			ans.insert(i);
			ans.insert(a[i]);
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(ans.size() == n / 2)
			break;
		
		ans.insert(i);
	}
	
	for(ll i : ans)
		printf("%lld ", i);
	
	printf("\n");
	
	vector<ll> vec;
	
	for(ll i : ans)
		vec.push_back(a[i]);
	
	sort(vec.begin(), vec.end());
	
	ll cc = 0;
	
	for(ll i : ans)
		a[i] = vec[cc++];
	
	ans.clear();
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(n / 4 + 1 <= a[i] && a[i] <= n / 2)
		{
			ans.insert(i);
			ans.insert(a[i]);
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(ans.size() == n / 2)
			break;
		
		ans.insert(i);
	}
	
	for(ll i : ans)
		printf("%lld ", i);
	
	printf("\n");
	
	for(ll i = n / 2 + 1 ; i <= n ; i++)
		printf("%lld ", i);
	
	return 0;
}