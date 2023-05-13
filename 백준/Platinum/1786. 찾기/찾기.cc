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
char a[1000010], b[1000010];
ll fail[1000010];
ll p;
vector<ll> ans;

int main(void)
{
	fastio
	
	fgets(a, 1000010, stdin);
	fgets(b, 1000010, stdin);
	
	n = strlen(a);
	m = strlen(b);
	
	while(n > 0 && (a[n - 1] == '\n' || a[n - 1] == '\r'))
		n--;
	
	while(m > 0 && (b[m - 1] == '\n' || b[m - 1] == '\r'))
		m--;
	
	for(ll i = 1 ; i < m ; i++)
	{
		while(p > 0 && b[p] != b[i])
			p = fail[p - 1];
		
		if(b[p] == b[i])
		{
			p++;
			fail[i] = p;
		}
	}
	
	p = 0;
	
	for(ll i = 0 ; i < n ; i++)
	{
		while(p > 0 && b[p] != a[i])
			p = fail[p - 1];
		
		if(b[p] == a[i])
		{
			p++;
			
			if(p == m)
			{
				ans.push_back(i - m + 2);
				p = fail[m - 1];
			}
		}
	}
	
	cout << (ll)ans.size() en;
	
	for(auto &i : ans)
		cout << i sp;
	
	return 0;
}