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
ll a[1000010];
ll sum;
vector<ll> vec;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	vec.push_back(0);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		sum += a[i];
		
		if(sum == i * (i + 1) / 2)
			vec.push_back(i);
	}
	
	cout << (ll)vec.size() - 1 en;
	
	for(ll i = 0 ; i < (ll)vec.size() - 1 ; i++)
	{
		ll siz = (ll)vec[i + 1] - vec[i];
		
		cout << siz sp;
		
		for(ll j = vec[i] + 1 ; j <= vec[i + 1] ; j++)
			cout << j sp;
		
		cout en;
	}
	
	return 0;
}