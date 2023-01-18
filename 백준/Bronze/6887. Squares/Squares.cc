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

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; ; i++)
	{
		if(i * i > n)
		{
			cout << "The largest square has side length " << i - 1 << ".";
			return 0;
		}
	}
	
	return 0;
}