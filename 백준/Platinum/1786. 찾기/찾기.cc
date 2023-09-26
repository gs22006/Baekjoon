#include <bits/stdc++.h>

using namespace std;
typedef int ll;
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

char a[1000010];
char b[1000010];
ll n, m;
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
	
	while(a[n - 1] == '\n' || a[n - 1] == '\r')
		n--;
	
	while(b[m - 1] == '\n' || b[m - 1] == '\r')
		m--;
	
	fail[0] = 0;
	p = 0;
	
	for(ll i = 1 ; i < m ; i++)
	{
		while(p > 0 && b[i] != b[p])
			p = fail[p - 1];
		
		if(b[i] == b[p])
			fail[i] = ++p;
	}
	
	p = 0;
	
	for(ll i = 0 ; i < n ; i++)
	{
		while(p > 0 && a[i] != b[p])
			p = fail[p - 1];
		
		if(a[i] == b[p])
		{
			if(p == m - 1)
			{
				ans.push_back(i - m + 2);
				p = fail[p];
			}
			
			else
				p++;
		}
	}
	
	cout << (ll)ans.size() en;
	
	for(auto &i : ans)
		cout << i sp;
	
	return 0;
}