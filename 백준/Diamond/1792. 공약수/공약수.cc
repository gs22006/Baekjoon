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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

ll t;
ll a, b, d;
ll mo[50010];
ll nu[50010];

int main(void)
{
	fastio
	
	cin >> t;
	
	mo[1] = 1;
	
	for(ll i = 1 ; i < 50010 ; i++)
	{
		for(ll j = 2 * i ; j < 50010 ; j += i)
			mo[j] -= mo[i];
	}
	
	for(ll i = 1 ; i < 50010 ; i++)
		nu[i] = nu[i - 1] + mo[i];
	
	while(t--)
	{
		cin >> a >> b >> d;
		
		ll gapa = a / d;
		ll gapb = b / d;
		vector<ll> veca, vecb;
		ll p1 = 1, p2 = 1;
		ll last = 0;
		ll ans = 0;
		
		veca.push_back(0);
		
		for(ll i = 1, last = 0 ; i <= gapa ; i = last + 1)
		{
			last = gapa / (gapa / i);
			veca.push_back(last);
		}
		
		vecb.push_back(0);
		
		for(ll i = 1, last = 0 ; i <= gapb ; i = last + 1)
		{
			last = gapb / (gapb / i);
			vecb.push_back(last);
		}
		
		ll siza = (ll)veca.size();
		ll sizb = (ll)vecb.size();
		
		while(1)
		{
			if(p1 >= siza || p2 >= sizb)
				break;
			
			if(veca[p1] < vecb[p2])
			{
				ans += (nu[veca[p1]] - nu[last]) * (gapa / veca[p1]) * (gapb / vecb[p2]);
				last = veca[p1];
				p1++;
			}
			
			else
			{
				ans += (nu[vecb[p2]] - nu[last]) * (gapa / veca[p1]) * (gapb / vecb[p2]);
				last = vecb[p2];
				p2++;
			}
		}
		
		cout << ans en;
	}
	
	return 0;
}