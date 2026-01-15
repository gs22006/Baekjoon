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
pll a[300010];
ll T[300010], nxt[300010];
ll spa[300010][21];
ll tspa[300010][21];
ll q;
ll all, bll;

ll ffind(ll X)
{
	if(X < a[1].fi)
		return 0;
	
	ll l = 1, r = n;
	
	while(l <= r)
	{
		ll mid = (l + r) >> 1;
		
		if(a[mid].fi <= X)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	return r;
}

void calc(ll X)
{
	if(X == n)
	{
		T[X] = 300000000000000001LL;
		nxt[X] = 0;
		return;
	}
	
	ll now = a[X].se;
	ll tmp = 0;
	
	for(ll i = 1 ; ; i++)
	{
		if(a[X].fi + now >= a[X + 1].fi)
		{
			tmp = i;
			break;
		}
		
		now <<= 1;
	}
	
	nxt[X] = ffind(a[X].fi + now);
	T[X] = tmp + a[X].se * ((1LL << tmp) - 1) - (a[nxt[X]].fi - a[X].fi);
}

ll solve(ll X, ll Y)
{
	if(X < a[1].fi)
		return X - Y;
	
	ll w = ffind(X);
	
	if(Y <= X - a[w].fi)
		return X - Y;
	
	Y -= X - a[w].fi;
	X = a[w].fi;
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if(tspa[w][i] <= Y)
		{
			Y -= tspa[w][i];
			w = spa[w][i];
		}
	}
	
	ll P = a[w].se;
	X = a[w].fi;
	
	for(ll i = 1 ; ; i++)
	{
		if(!Y)
			return X;
		
		Y--;
		X += P;
		P <<= 1;
		
		if(Y <= X - a[w].fi)
			return X - Y;
		
		Y -= (X - a[w].fi);
		X = a[w].fi;
	}
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	
	for(ll i = 1 ; i <= n ; i++)
		calc(i);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		spa[i][0] = nxt[i];
		tspa[i][0] = min(T[i], 300000000000000001LL);
	}
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
			
			if(spa[j][i] == 0)
				tspa[j][i] = 300000000000000001LL;
			else
				tspa[j][i] = min(300000000000000001LL, tspa[j][i - 1] + tspa[spa[j][i - 1]][i - 1]);
		}
	}
	
	cin >> q;
	
	while(q--)
	{
		cin >> all >> bll;
		cout << solve(all, bll) en;
	}
	
	return 0;
}