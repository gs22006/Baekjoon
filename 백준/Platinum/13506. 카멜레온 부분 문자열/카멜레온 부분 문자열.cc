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

char s[1000010], s2[1000010];
ll n;
ll fail[1000010], fail2[1000010];
ll p;
vector<ll> hubo;
ll chk1[1000010], chk2[1000010];

int main(void)
{
	fastio
	
	cin >> s;
	
	n = strlen(s);
	
	for(ll i = 0 ; i < n ; i++)
		s2[i] = s[n - 1 - i];
	
	fail[0] = 0;
	p = 0;
	
	for(ll i = 1 ; i < n ; i++)
	{
		while(p > 0 && s[i] != s[p])
			p = fail[p - 1];
		
		if(s[i] == s[p])
			fail[i] = ++p;
	}
	
	fail2[0] = 0;
	p = 0;
	
	for(ll i = 1 ; i < n ; i++)
	{
		while(p > 0 && s2[i] != s2[p])
			p = fail2[p - 1];
		
		if(s2[i] == s2[p])
			fail2[i] = ++p;
	}
	
	p = n - 1;
	
	while(p > 0)
	{
		if(fail[p])
			hubo.push_back(fail[p]);
		
		p = fail[p] - 1;
	}
	
	for(ll i = 0 ; i < n - 1 ; i++)
		chk1[fail[i]] = 1;
	
	for(ll i = 1 ; i < n ; i++)
		chk2[fail2[i]] = 1;
	
	for(auto &i : hubo)
	{
		if(chk1[i] && chk2[i])
		{
			for(ll j = 0 ; j < i ; j++)
				cout << s[j];
			
			return 0;
		}
	}
	
	cout << -1;
	return 0;
}