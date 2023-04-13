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

ll n;
char all[500010];
char s[500010];
ll z[500010];
ll nu[500010];
vector<ll> vec;

void get_z(void)
{
	ll l = 0, r = 0;
	
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
	
	z[0] = n;
}

int main(void)
{
	fastio
	
	cin >> all;
	
	n = strlen(all);
	strcat(s, all);
	
	get_z();
	
	for(ll i = 0 ; i < n ; i++)
	{
		nu[z[i]]++;
		
		if(i + z[i] == n)
			vec.push_back(z[i]);
	}
	
	for(ll i = n ; i >= 0 ; i--)
		nu[i] += nu[i + 1];
	
	compress(vec);
	
	cout << (ll)vec.size() en;
	
	for(auto &i : vec)
		cout << i sp << nu[i] en;
	
	return 0;
}