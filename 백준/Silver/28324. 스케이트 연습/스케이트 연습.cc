#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, a[500010];
ll ans;
ll gap;

int main(void)
{
	scanf("%lld", &n);

	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = n ; i >= 1 ; i--)
	{
		gap = min(a[i], gap + 1);
		ans += gap;
	}

	printf("%lld", ans);
	return 0;
}