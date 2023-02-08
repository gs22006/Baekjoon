#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n, m, K;
ll a[4000010];
ll b[10010];
ll pa[4000010];

ll ffind(ll here)
{
	if(pa[here] == here)
		return here;
	
	return pa[here] = ffind(pa[here]);
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	pa[X] = Y;
}

int main(void)
{
	fastio
	
	cin >> n >> m >> K;
	
	for(ll i = 1 ; i <= m ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= K ; i++)
		cin >> b[i];
	
	sort(a + 1, a + 1 + m);
	
	for(ll i = 1 ; i <= n ; i++)
		pa[i] = i;
	
	for(ll i = 1 ; i <= K ; i++)
	{
		ll l = 1, r = m;
		
		while(l <= r)
		{
			ll mid = (l + r) / 2;
			
			if(a[mid] <= b[i])
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		ll w = ffind(l);
		
		cout << a[w] en;
		
		uunion(w, w + 1);
	}
	
	return 0;
}