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

ll t, n;
string s;
ll all;
string bll;
ld ans;

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> s >> all >> bll;
		
		n += all;
		
		ll sc = 0;
		
		if(bll[0] == 'A')
			sc = 400;
		else if(bll[0] == 'B')
			sc = 300;
		else if(bll[0] == 'C')
			sc = 200;
		else if(bll[0] == 'D')
			sc = 100;
		else
			continue;
		
		if(bll[1] == '+')
			sc += 30;
		else if(bll[1] == '-')
			sc -= 30;
		
		ans += sc * all;
	}
	
	ans /= n;
	ans = round(ans);
	
	printf("%.2Lf", ans / 100.0);
	return 0;
}