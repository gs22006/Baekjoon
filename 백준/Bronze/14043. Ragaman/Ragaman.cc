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

string a, b;
ll cou[30];

int main(void)
{
	fastio
	
	cin >> a;
	cin >> b;
	
	ll len = (ll)b.size();
	
	for(ll i = 0 ; i < len ; i++)
	{
		if(b[i] == '*')
			cou[0]++;
		else
			cou[b[i] - 'a' + 1]++;
	}
	
	for(ll i = 0 ; i < len ; i++)
	{
		if(cou[a[i] - 'a' + 1])
			cou[a[i] - 'a' + 1]--;
		
		else
		{
			if(cou[0])
				cou[0]--;
			
			else
			{
				cout << "N";
				return 0;
			}
		}
	}
	
	cout << "A";
	return 0;
}