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

ll n, m;
string a[110];
set<ll> st1, st2;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 0 ; i < n ; i++)
		st1.insert(i);
	
	for(ll i = 0 ; i < m ; i++)
		st2.insert(i);
	
	for(ll i = 0 ; i < n ; i++)
	{
		cin >> a[i];
		
		for(ll j = 0 ; j < m ; j++)
		{
			if(a[i][j] != '.')
			{
				if(st1.find(i) != st1.end())
					st1.erase(i);
				
				if(st2.find(j) != st2.end())
					st2.erase(j);
			}
		}
	}
	
	cout << max((ll)st1.size(), (ll)st2.size());
	return 0;
}