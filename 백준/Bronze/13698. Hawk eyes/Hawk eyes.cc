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

string s;
ll a[10];

int main(void)
{
	fastio
	
	cin >> s;
	
	a[1] = 1, a[2] = 2, a[3] = 3, a[4] = 4;
	
	for(auto &i : s)
	{
		if(i == 'A')
			swap(a[1], a[2]);
		else if(i == 'B')
			swap(a[1], a[3]);
		else if(i == 'C')
			swap(a[1], a[4]);
		else if(i == 'D')
			swap(a[2], a[3]);
		else if(i == 'E')
			swap(a[2], a[4]);
		else
			swap(a[3], a[4]);
	}
	
	for(ll i = 1 ; i <= 4 ; i++)
	{
		if(a[i] == 1)
			cout << i en;
	}
	
	for(ll i = 1 ; i <= 4 ; i++)
	{
		if(a[i] == 4)
			cout << i en;
	}
	
	return 0;
}