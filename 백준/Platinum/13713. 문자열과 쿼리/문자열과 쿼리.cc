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
char s[1000010];
ll z[1000010];
ll l, r;
ll all;

void get_z(void)
{
	l = r = 0;
	
	for(ll i = 1 ; i < n ; i++)
	{
		if(r < i)
		{
			l = r = i;
			
			while(r < n && s[r - l] == s[r])
				r++;
			
			z[i] = r - l;
			r--;
		}
		
		else
		{
			ll K = i - l;
			
			if(z[K] < r - i + 1)
				z[i] = z[K];
			
			else
			{
				l = i;
				
				while(r < n && s[r - l] == s[r])
					r++;
				
				z[i] = r - l;
				r--;
			}
		}
	}
}

int main(void)
{
	fastio
	
	cin >> s;
	
	n = strlen(s);
	
	reverse(s, s + n);
	get_z();
	
	cin >> m;
	
	while(m--)
	{
		cin >> all;
		
		all = n - all;
		
		if(all == 0)
			cout << n en;
		else
			cout << z[all] en;
	}
	
	return 0;
}