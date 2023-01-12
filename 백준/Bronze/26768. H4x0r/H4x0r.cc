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

char s[1000010];
ll len;

int main(void)
{
	fastio
	
	cin >> s;
	
	len = strlen(s);
	
	for(ll i = 0 ; i < len ; i++)
	{
		if(s[i] == 'a')
			s[i] = '4';
		else if(s[i] == 'e')
			s[i] = '3';
		else if(s[i] == 'i')
			s[i] = '1';
		else if(s[i] == 'o')
			s[i] = '0';
		else if(s[i] == 's')
			s[i] = '5';
	}
	
	cout << s;
	return 0;
}