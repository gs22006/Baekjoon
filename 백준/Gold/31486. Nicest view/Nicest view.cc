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
stack<ll> stk;
ll L[100010], R[100010];
ll ja, mo = 1;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(!stk.empty() && a[stk.top()] < a[i])
		{
			R[stk.top()] = i;
			stk.pop();
		}
		
		if(!stk.empty())
			L[i] = stk.top();
		
		stk.push(i);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(L[i] && i - L[i] > 1)
		{
			ll gmo = a[L[i]] - a[L[i] + 1];
			ll gja = (i - L[i] - 1) * gmo + a[i] - a[L[i] + 1];
			
			if(ja * gmo < gja * mo)
				ja = gja, mo = gmo;
		}
		
		if(R[i] && R[i] - i > 1)
		{
			ll gmo = a[R[i]] - a[R[i] - 1];
			ll gja = (R[i] - i - 1) * gmo + a[i] - a[R[i] - 1];
			
			if(ja * gmo < gja * mo)
				ja = gja, mo = gmo;
		}
	}
	
	ll G = __gcd(ja, mo);
	
	ja /= G;
	mo /= G;
	
	if(mo == 1)
		cout << ja;
	else
		cout << ja << "/" << mo;
	
	return 0;
}