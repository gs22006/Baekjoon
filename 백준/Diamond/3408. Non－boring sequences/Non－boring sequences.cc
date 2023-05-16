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

ll t;
ll n;
ll a[200010];
ll l[200010], r[200010];
ll w[200010];
ll ans;

void f(ll L, ll R)
{
	if(L > R)
		return;
	
	if(L == R)
	{
		ans++;
		return;
	}
	
	ll s = L, e = R;
	ll pp = -1;
	
	for(ll i = L ; i <= R ; i++)
	{
		if(i & 1)
		{
			if(l[s] < L && R < r[s])
			{
				pp = s;
				break;
			}
			
			s++;
		}
		
		else
		{
			if(l[e] < L && R < r[e])
			{
				pp = e;
				break;
			}
			
			e--;
		}
	}
	
	if(pp == -1)
		return;
	
	ans++;
	
	f(L, pp - 1);
	f(pp + 1, R);
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		for(ll i = 1 ; i <= n ; i++)
			cin >> a[i];
		
		vector<ll> zip;
		
		for(ll i = 1 ; i <= n ; i++)
			zip.push_back(a[i]);
		
		compress(zip);
		
		for(ll i = 1 ; i <= n ; i++)
			a[i] = lower_bound(zip.begin(), zip.end(), a[i]) - zip.begin() + 1;
		
		for(ll i = 1 ; i <= n ; i++)
			w[i] = l[i] = r[i] = 0;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			l[i] = w[a[i]];
			w[a[i]] = i;
		}
		
		for(ll i = 1 ; i <= n ; i++)
			w[i] = n + 1;
		
		for(ll i = n ; i >= 1 ; i--)
		{
			r[i] = w[a[i]];
			w[a[i]] = i;
		}
		
		ans = 0;
		f(1, n);
		
		if(ans == n)
			cout << "non-boring\n";
		else
			cout << "boring\n";
	}
	
	return 0;
}