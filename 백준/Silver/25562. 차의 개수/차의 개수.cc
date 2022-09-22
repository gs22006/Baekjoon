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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

ll n;

int main(void)
{
	cin >> n;
	
	cout << n * (n - 1) / 2 en;
	
	for(ll i = 0 ; i < n ; i++)
		cout << (1LL << i) sp;
	
	cout en;
	
	cout << n - 1 en;
	
	for(ll i = 1 ; i <= n ; i++)
		cout << i sp;
	
	return 0;
}