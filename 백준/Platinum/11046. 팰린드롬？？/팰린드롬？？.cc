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

ll n;
ll a[2000010];
ll M[2000010];
ll q;
ll all, bll;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[(i - 1) * 2 + 1];
	
	ll w = 0;
	n = n * 2 + 1;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(i <= w + M[w])
			M[i] = min(M[2 * w - i], w + M[w] - i);
		else
			M[i] = 0;
		
		while(i - M[i] - 1 >= 1 && i + M[i] + 1 <= n && a[i - M[i] - 1] == a[i + M[i] + 1])
			M[i]++;
		
		if(i + M[i] > w + M[w])
			w = i;
	}
	
	cin >> q;
	
	while(q--)
	{
		cin >> all >> bll;
		
		all = (all - 1) * 2 + 1;
		bll = (bll - 1) * 2 + 1;
		
		ll mid = (all + bll) / 2;
		
		if(mid - all <= M[mid])
			cout << 1 en;
		else
			cout << 0 en;
	}
	
	return 0;
}