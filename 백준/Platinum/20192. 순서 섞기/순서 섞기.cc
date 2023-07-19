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
ll a[300010];
vector<ll> vec;
ll cou;
ll ans;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(vec.empty() || vec.back() != a[i])
			vec.push_back(a[i]);
	}
	
	n = 0;
	
	for(auto &i : vec)
		a[++n] = i;
	
	if(n == 1)
	{
		cout << 0;
		return 0;
	}
	
	cou = 1;
	
	for(ll i = 3 ; i <= n ; i++)
		cou += ((a[i] < a[i - 1]) != (a[i - 1] < a[i - 2]));
	
	if(cou == 1 && a[1] > a[2])
		ans++;
	
	if(cou >= 2 && !(cou & (cou - 1)) && a[1] > a[2] && a[n - 1] < a[n])
		ans++;
	
	while(1)
	{
		if(cou == 1)
			break;
		
		cou = (cou + 1) / 2;
		ans++;
	}
	
	cout << ans;
	return 0;
}