#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

ll t;
ll k;

int main(void)
{
	scanf("%lld", &t);
	
	while(t--)
	{
		scanf("%lld", &k);
		
		if(k % 2)
		{
			printf("-1\n");
			continue;
		}
		
		k /= 2;
		
		vector<ll> vec, ans;
		ll gap = 0;
		
		while(k > 0)
		{
			if(k % 2 == 1)
				vec.push_back(gap);
			
			gap++;
			k /= 2;
		}
		
		for(ll i = 0 ; i < vec.size() ; i++)
		{
			if(vec[i] == 0)
				ans.push_back(1);
			
			else
			{
				ans.push_back(1);
				
				for(ll j = 1 ; j < vec[i] ; j++)
					ans.push_back(0);
				
				ans.push_back(1);
			}
		}
		
		printf("%lld\n", (ll)ans.size());
		
		for(ll i = 0 ; i < ans.size() ; i++)
			printf("%lld ", ans[i]);
		
		printf("\n");
	}
	
	return 0;
}