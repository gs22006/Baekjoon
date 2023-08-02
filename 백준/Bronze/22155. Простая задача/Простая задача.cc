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
ll all, bll;

int main(void)
{
	fastio
	
	cin >> n;
	
	while(n--)
	{
		cin >> all >> bll;
		
		if(all <= 2 && bll <= 1)
			cout << "Yes\n";
		else if(all <= 1 && bll <= 2)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	
	return 0;
}