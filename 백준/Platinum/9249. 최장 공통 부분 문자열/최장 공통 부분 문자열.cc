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

char a[200010], b[200010];
ll n, m;
ll grp[200010], SA[200010];
ll LCP[200010];
ll tmp[200010];
ll last;
ll twoo;

bool cmp(ll X, ll Y)
{
	if(grp[X] != grp[Y])
		return grp[X] < grp[Y];
	
	X += twoo;
	Y += twoo;
	
	if(X >= n || Y >= n)
		return X > Y;
	
	return grp[X] < grp[Y];
}

int main(void)
{
	fastio
	
	cin >> a >> b;
	
	n = strlen(a);
	m = strlen(b);
	
	a[n++] = '$';
	
	for(ll i = 0 ; i < m ; i++)
		a[n++] = b[i];
	
	for(ll i = 0 ; i < n ; i++)
	{
		grp[i] = a[i];
		SA[i] = i;
	}
	
	for(twoo = 1 ; ; twoo <<= 1)
	{
		sort(SA, SA + n, cmp);
		
		ll cc = 0;
		
		tmp[SA[0]] = 0;
		
		for(ll i = 1 ; i < n ; i++)
		{
			if(cmp(SA[i - 1], SA[i]))
				cc++;
			
			tmp[SA[i]] = cc;
		}
		
		for(ll i = 0 ; i < n ; i++)
			grp[i] = tmp[i];
		
		if(cc == n - 1)
			break;
	}
	
	for(ll i = 0 ; i < n ; i++)
		tmp[SA[i]] = i;
	
	for(ll i = 0 ; i < n ; i++, last = max(last - 1, 0LL))
	{
		ll num1 = tmp[i];
		ll num2 = num1 + 1;
		ll bun1 = i, bun2 = SA[num2];
		
		if(num1 == n - 1)
		{
			LCP[i] = -1;
			continue;
		}
		
		for(ll j = last ; ; j++)
		{
			if(bun1 + j >= n || bun2 + j >= n)
				break;
			
			if(a[bun1 + j] == a[bun2 + j])
				last++;
			else
				break;
		}
		
		LCP[i] = last;
	}
	
	ll ans = 0, ans2 = 0;
	
	for(ll i = 0 ; i < n - 1 ; i++)
	{
		if((n - SA[i] > m + 1 && n - SA[i + 1] <= m) || (n - SA[i] <= m && n - SA[i + 1] > m + 1))
		{
			if(ans < LCP[SA[i]])
			{
				ans = LCP[SA[i]];
				ans2 = SA[i];
			}
		}
	}
	
	cout << ans en;
	
	for(ll i = 0 ; i < ans ; i++)
		cout << a[ans2 + i];
	
	return 0;
}