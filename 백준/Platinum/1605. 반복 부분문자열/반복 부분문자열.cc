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

char s[500010];
ll n;
ll SA[500010];
ll tmp[500010];
ll ttmp[500010];
ll LCP[500010];
ll twoo;
ll last;

bool cmp(ll X, ll Y)
{
	if(SA[X] != SA[Y])
		return SA[X] < SA[Y];
	
	X += twoo;
	Y += twoo;
	
	if(X >= n || Y >= n)
		return X > Y;
	
	return SA[X] < SA[Y];
}

int main(void)
{
	fastio
	
	cin >> n;
	cin >> s;
	
	for(ll i = 0 ; i < n ; i++)
	{
		SA[i] = s[i] - 'a';
		tmp[i] = i;
	}
	
	for(twoo = 1 ; ; (twoo <<= 1))
	{
		sort(tmp, tmp + n, cmp);
		
		ll cc = 0;
		
		ttmp[tmp[0]] = 0;
		
		for(ll i = 1 ; i < n ; i++)
		{
			if(cmp(tmp[i - 1], tmp[i]))
				cc++;
			
			ttmp[tmp[i]] = cc;
		}
		
		for(ll i = 0 ; i < n ; i++)
			SA[i] = ttmp[i];
		
		if(cc == n - 1)
			break;
	}
	
	for(ll i = 0 ; i < n ; i++)
		SA[i] = tmp[i];
	
	for(ll i = 0 ; i < n ; i++)
		tmp[SA[i]] = i;
	
	for(ll i = 0 ; i < n ; i++)
	{
		if(tmp[i] == n - 1)
		{
			last = max(last - 1, 0LL);
			continue;
		}
		
		ll bun1 = i, bun2 = SA[tmp[i] + 1];
		
		for(ll i = last ; ; i++)
		{
			if(bun1 + i >= n || bun2 + i >= n)
				break;
			
			if(s[bun1 + i] == s[bun2 + i])
				last++;
			else
				break;
		}
		
		LCP[i] = last;
		last = max(last - 1, 0LL);
	}
	
	ll ans = 0;
	
	for(ll i = 0 ; i < n ; i++)
		ans = max(ans, LCP[i]);
	
	cout << ans;
	return 0;
}