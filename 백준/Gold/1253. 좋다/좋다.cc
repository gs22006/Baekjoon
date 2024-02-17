#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

ll n;
ll a[2010];
unordered_map<ll, ll> chk;
ll ans;
ll z;

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld", &a[i]);
	
	sort(a + 1, a + 1 + n);
    
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = i + 1 ; j <= n ; j++)
			chk[a[i] + a[j]]++;
	}
	
	for(ll i = 1 ; i <= n ; i++)
    {
        for(ll j = 1 ; j <= n ; j++)
        {
            if(i == j)
                continue;
            
            chk[a[i] + a[j]]--;
        }
        
		ans += !!chk[a[i]];
        
        for(ll j = 1 ; j <= n ; j++)
        {
            if(i == j)
                continue;
            
            chk[a[i] + a[j]]++;
        }
    }
	
	printf("%lld", ans);
	return 0;
}