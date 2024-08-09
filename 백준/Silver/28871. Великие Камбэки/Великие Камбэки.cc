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

ll a, b;
char c;

int main(void)
{
	fastio
	
	cin >> a >> c >> b;
	
	if(a * b == 0)
	{
		cout << 0;
		return 0;
	}
	
	ll ans = 0, ans2 = 0;
	ll A = 0, B = 1;
	
	while(1)
	{
		if(A < B)
		{
			A += 2;
			
			if(A > a)
				break;
		}
		
		else
		{
			B += 2;
			
			if(B > b)
				break;
		}
		
		ans++;
	}
	
	A = 1, B = 0;
	
	while(1)
	{
		if(A < B)
		{
			A += 2;
			
			if(A > a)
				break;
		}
		
		else
		{
			B += 2;
			
			if(B > b)
				break;
		}
		
		ans2++;
	}
	
	cout << max(ans, ans2);
	return 0;
}