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

int main(void)
{
	fastio
	
	cin >> n;
	
	if(n == 1)
		cout << "11\nA B C D E F G H J L M";
	else if(n <= 3)
		cout << "9\nA C E F G H I L M";
	else if(n == 4)
		cout << "9\nA B C E F G H L M";
	else if(n <= 9)
		cout << "8\nA C E F G H L M";
	else if(n == 10)
		cout << "8\nA B C F G H L M";
	
	return 0;
}