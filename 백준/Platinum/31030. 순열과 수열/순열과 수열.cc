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
ll a[5010], X[5010];
vector< vector<ll> > cyc;
ll chk[5010];
ll gap[5010];
ll ans;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> X[i];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(chk[i])
			continue;
		
		ll w = i;
		vector<ll> tmp;
		
		while(1)
		{
			chk[w] = 1;
			tmp.push_back(w);
			w = a[w];
			
			if(chk[w])
				break;
		}
		
		cyc.push_back(tmp);
	}
	
	for(auto &i : cyc)
	{
		ll maxx = 0;
		
		for(auto &j : cyc)
		{
			if((ll)i.size() % (ll)j.size())
				continue;
			
			ll siz = (ll)j.size();
			ll siz2 = (ll)i.size();
			
			for(ll k = 0 ; k < siz ; k++)
			{
				ll idx = k;
				ll sum = 0;
				
				for(ll l = 0 ; l < siz2 ; l++)
				{
					sum += X[i[l]] * j[idx++];
					idx %= siz;
				}
				
				maxx = max(maxx, sum);
			}
		}
		
		ans += maxx;
	}
	
	cout << ans;
	return 0;
}