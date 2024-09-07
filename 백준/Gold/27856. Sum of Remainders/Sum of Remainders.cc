#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
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
ll a[110];
ll m;
vector<ll> ans;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	m = a[1];
	
	for(ll i = 2 ; i <= n ; i++)
	{
		ll cha = a[i - 1] + m - a[i];
		
		if(!cha)
			continue;
		
		for(auto &j : ans)
		{
			if(i % j == 0)
				cha -= j;
		}
		
		for(ll j = 0 ; j < cha / i ; j++)
			ans.push_back(i);
	}
	
	cout << m sp;
	
	for(auto &i : ans)
		cout << i sp;
	
	return 0;
}