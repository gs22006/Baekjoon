#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

ll n;
ll a[100010];
ll L, R;
vector<ll> vec;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	L = 1;
	R = n - 1;
	
	vec.push_back(a[n]);
	
	for(ll i = 0 ; ; i++)
	{
		if(L > R)
			break;
		
		if(i & 1)
			vec.push_back(a[R--]);
		else
			vec.push_back(a[L++]);
	}
	
	ll ans = 0;
	
	for(ll i = 1 ; i < n ; i++)
		ans += max(0LL, vec[i] - vec[i - 1]);
	
	ans += vec[0];
	reverse(vec.begin(), vec.end());
	
	ll sum = 0;
	
	for(ll i = 1 ; i < n ; i++)
		sum += max(0LL, vec[i] - vec[i - 1]);
	
	sum += vec[0];
	cout << max(ans, sum);
	return 0;
}