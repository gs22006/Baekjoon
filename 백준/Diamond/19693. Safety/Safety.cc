#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n, h;
ll a[200010];
priority_queue<ll> pq1;
priority_queue<ll, vector<ll>, greater<ll> > pq2;
ll mv1, mv2;
ll ans;

int main(void)
{
	scanf("%lld %lld", &n, &h);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld", &a[i]);
	
	pq1.push(a[1]);
	pq2.push(a[1]);
	
	for(ll i = 2 ; i <= n ; i++)
	{
		mv1 -= h;
		mv2 += h;
		
		ll lef = pq1.top() + mv1;
		ll rig = pq2.top() + mv2;
		
		if(lef <= a[i] && a[i] <= rig)
		{
			pq1.push(a[i] - mv1);
			pq2.push(a[i] - mv2);
		}
		
		else if(a[i] < lef)
		{
			pq1.pop();
			pq2.push(lef - mv2);
			pq1.push(a[i] - mv1);
			pq1.push(a[i] - mv1);
			ans += lef - a[i];
		}
		
		else
		{
			pq2.pop();
			pq1.push(rig - mv1);
			pq2.push(a[i] - mv2);
			pq2.push(a[i] - mv2);
			ans += a[i] - rig;
		}
	}
	
	printf("%lld", ans);
	return 0;
}