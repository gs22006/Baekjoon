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

ll n, k, w;
ll m;
ll a[200010];
ll l, r;
ll chk[200010];

int main(void)
{
	fastio
	
	cin >> n >> k >> w;
	cin >> m;
	
	for(ll i = 1 ; i <= m ; i++)
		cin >> a[i];
	
	l = 1, r = m;
	
	while(l <= r)
	{
		ll mid = (l + r) >> 1;
		
		for(ll i = 0 ; i <= n ; i++)
			chk[i] = 0;
		
		for(ll i = 1 ; i <= mid ; i++)
			chk[a[i]] = 1;
		
		ll C = 0;
		ll cou = 0;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(chk[i] == 0)
				C++;
			else
				C = 0;
			
			if(C >= w)
			{
				C = 0;
				cou++;
				chk[i + 1] = 1;
			}
		}
		
		if(cou >= k)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	if(l == m + 1)
		cout << -1;
	else
		cout << l;
	
	return 0;
}