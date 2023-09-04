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

ll n, m;
ll all, bll;
ll adj[3010][3010];
ll chk[3010];

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll;
		adj[all][bll] = adj[bll][all] = 1;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(chk[i])
			continue;
		
		for(ll j = i + 1 ; j <= n ; j++)
		{
			if(!adj[i][j] && !chk[j])
			{
				chk[i] = chk[j] = 1;
				break;
			}
		}
	}
	
	ll cou = n / 3;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!chk[i] && cou)
		{
			cout << i sp;
			cou--;
		}
	}
	
	return 0;
}