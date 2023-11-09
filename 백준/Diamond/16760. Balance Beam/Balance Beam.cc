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
ll a[100010];
pair<lll, lll> b[100010];
pair<lll, lll> stk[100010];
ll siz;

ll ccw(pair<lll, lll> X, pair<lll, lll> Y, pair<lll, lll> Z)
{
	lll sad = 0;
	
	sad = ((lll)X.fi * (lll)Y.se + (lll)Y.fi * (lll)Z.se + (lll)Z.fi * (lll)X.se) - ((lll)X.se * (lll)Y.fi + (lll)Y.se * (lll)Z.fi + (lll)Z.se * (lll)X.fi);
	
	return sad >= 0;
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		b[i + 1] = {i, a[i] * 100000};
	}
	
	b[1] = {0, 0};
	b[n + 2] = {n + 1, 0};
	n += 2;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(siz >= 2 && ccw(stk[siz - 2], stk[siz - 1], b[i]))
			siz--;
		
		stk[siz++] = b[i];
	}
	
	ll p = 0;
	
	for(ll i = 1 ; i <= n - 2 ; i++)
	{
		while(stk[p].fi < i)
			p++;
		
		lll JA = (stk[p].se - stk[p - 1].se) * i + stk[p - 1].se * (stk[p].fi - stk[p - 1].fi) - (stk[p].se - stk[p - 1].se) * stk[p - 1].fi;
		lll MO = (stk[p].fi - stk[p - 1].fi);
		
		lll l = 0, r = JA / MO + 100;
		
		while(l <= r)
		{
			lll mid = (l + r) / 2;
			
			if(MO * mid <= JA)
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		cout << (ll)r en;
	}
	
	return 0;
}