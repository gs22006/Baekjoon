#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
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
ll a[1000010];
ll chk[1000010];
ll T;
ll p, p2;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	p = 1;
	p2 = 1;
	
	for(ll i = 0 ; i <= 1000000 ; i++)
	{
		if(p == n + 1)
			break;
		
		if(a[p] == i)
		{
			if(!chk[i])
			{
				cout << "fail";
				return 0;
			}
			
			p++;
		}
		
		else
		{
			if(!T)
				T++;
			
			else if(p2 <= n && a[p2] - m <= i)
			{
				T--;
				chk[a[p2]] = 1;
				p2++;
			}
			
			else
				T++;
		}
	}
	
	cout << "success";
	return 0;
}