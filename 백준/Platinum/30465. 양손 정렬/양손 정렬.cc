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
ll a[200010];
ll b[200010];
ll ans;
ll chk[200010];
ll AA, BB;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	if(n % 2 == 1 && n / 2 + 1 != a[n / 2 + 1])
	{
		cout << -1;
		return 0;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(chk[a[i]])
			continue;
		
		ll w = a[i];
		vector<ll> vv;
		
		while(1)
		{
			if(chk[w])
				break;
			
			chk[w] = 1;
			vv.push_back(w);
			w = a[w];
		}
		
		if((ll)vv.size() == 1)
			continue;
		
		ll A = 0, B = 0;
		
		for(auto &i : vv)
		{
			if(i <= n / 2)
				A++;
			else if(n - i + 1 <= n / 2)
				B++;
		}
		
		ans += (ll)vv.size() - 1;
		
		if(A && !B)
			AA++;
		else if(B && !A)
			BB++;
	}
	
	ans += max(AA, BB) * 2;
	
	cout << ans;
	return 0;
}