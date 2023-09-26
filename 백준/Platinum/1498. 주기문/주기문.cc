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

char a[1000010];
ll len;
ll fail[1000010], p;
vector<pll> ans;

int main(void)
{
	fastio
	
	cin >> a;
	
	len = strlen(a);
	
	for(ll i = 1 ; i < len ; i++)
	{
		while(p && a[p] != a[i])
			p = fail[p - 1];
		
		if(a[p] == a[i])
			fail[i] = ++p;
	}
	
	for(ll i = 0 ; i < len ; i++)
	{
		ll gap = i + 1 - fail[i];
		
		if((i + 1) != gap && (i + 1) % gap == 0)
			ans.push_back({i + 1, (i + 1) / gap});
	}
	
	for(auto &i : ans)
		cout << i.fi sp << i.se en;
	
	return 0;
}