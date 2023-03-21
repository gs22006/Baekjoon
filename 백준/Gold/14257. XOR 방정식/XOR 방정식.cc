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

ll S, X;
ll sum;
vector<ll> vec;
ll ans = 1;

int main(void)
{
	fastio
	
	cin >> S >> X;
	
	if(X > S)
	{
		cout << 0;
		return 0;
	}
	
	for(ll i = 0 ; i <= 60 ; i++)
	{
		if(X & (1LL << i))
		{
			sum += (1LL << i);
			ans <<= 1;
		}
		
		else
			vec.push_back(1LL << (i + 1));
	}
	
	S -= sum;
	
	if(!S)
		ans -= 2;
	
	reverse(vec.begin(), vec.end());
	
	for(auto &i : vec)
	{
		if(i <= S)
			S -= i;
	}
	
	if(S)
		cout << 0;
	else
		cout << ans;
	
	return 0;
}