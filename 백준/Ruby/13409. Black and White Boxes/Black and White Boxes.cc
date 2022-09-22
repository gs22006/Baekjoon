#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL

ll n;
char a[110];
ll len[110], gap[110];
unordered_map<ll, ll> chk;
ll ans;

void f(ll here, ll sum, ll gaet)
{
	if(here > n / 2)
	{
		chk[sum] = max(chk[sum], gaet);
		return;
	}
	
	f(here + 1, sum, gaet);
	f(here + 1, sum + gap[here], gaet + len[here]);
}

void ff(ll here, ll sum, ll gaet)
{
	if(here > n)
	{
		if(sum == 0)
			ans = max(ans, gaet + chk[0]);
		else if(chk[-sum])
			ans = max(ans, gaet + chk[-sum]);
		
		return;
	}
	
	ff(here + 1, sum, gaet);
	ff(here + 1, sum + gap[here], gaet + len[here]);
}

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		scanf("%s", a);
		
		len[i] = strlen(a);
		ll ff = 0;
		ll plu = (1LL << 45LL);
		
		for(ll j = 0 ; j < len[i] ; j++)
		{
			if(a[j] != a[0])
				ff = 1;
			
			if(ff)
				plu /= 2;
			
			if(a[j] == 'B')
				gap[i] += plu;
			else
				gap[i] -= plu;
		}
	}
	
	f(1, 0, 0);
	ff(n / 2 + 1, 0, 0);
	
	printf("%lld", ans);
	return 0;
}