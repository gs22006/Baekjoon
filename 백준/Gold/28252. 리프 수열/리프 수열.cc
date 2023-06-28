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
ll a[100010];
ll m;
vector<ll> vec[100010];

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		m += a[i];
	}
	
	for(ll i = 2 ; i <= n ; i++)
	{
		if(a[i - 1] < a[i])
		{
			cout << -1;
			return 0;
		}
	}
	
	sort(a + 1, a + 1 + n);
	
	if(a[1] >= 3)
	{
		cout << -1;
		return 0;
	}
	
	for(ll i = 2 ; i <= n ; i++)
	{
		if(a[i] == a[i - 1] && a[i] == 1)
		{
			cout << -1;
			return 0;
		}
	}
	
	vector<ll> last;
	ll cc = 2;
	ll siz = 1;
	
	if(a[1] == 1)
	{
		last.push_back(1);
		cc = 2;
		siz = 1;
	}
	
	else
	{
		last.push_back(1);
		last.push_back(2);
		cc = 3;
		siz = 2;
		vec[1].push_back(2);
		vec[2].push_back(1);
	}
	
	for(ll i = 2 ; i <= n ; i++)
	{
		vector<ll> tmp;
		
		for(ll j = 0 ; j < a[i - 1] ; j++)
		{
			vec[last[siz - 1 - j]].push_back(cc);
			vec[cc].push_back(last[siz - 1 - j]);
			tmp.push_back(cc);
			cc++;
		}
		
		for(ll j = 0 ; j < a[i] - a[i - 1] ; j++)
		{
			vec[last[siz - 1]].push_back(cc);
			vec[cc].push_back(last[siz - 1]);
			tmp.push_back(cc);
			cc++;
		}
		
		for(auto &j : tmp)
		{
			last.push_back(j);
			siz++;
		}
	}
	
	cout << siz en;
	
	for(ll i = 1 ; i <= siz ; i++)
	{
		for(auto &j : vec[i])
		{
			if(i < j)
				cout << i sp << j en;
		}
	}
	
	return 0;
}