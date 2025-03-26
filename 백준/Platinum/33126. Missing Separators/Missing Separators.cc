#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 987654321
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n;
string all;
char a[5010];
ll LCP[5010][5010];
ll dp[5010][5010];
pll yuk[5010][5010];
pll maxx[5010][5010];
ll chk[5010][5010];
ll ans, X, Y;
vector<pll> ansV;

int main(void)
{
	fastio
	
	cin >> all;
	
	n = (ll)all.size();
	
	for(ll i = 0 ; i < n ; i++)
		a[i + 1] = all[i];
	
	for(ll i = n ; i >= 1 ; i--)
	{
		for(ll j = n ; j >= 1 ; j--)
		{
			dp[i][j] = -INF;
			
			if(a[i] == a[j])
				LCP[i][j] = LCP[i + 1][j + 1] + 1;
		}
	}
	
	maxx[1][1] = {1, 0};
	chk[0][0] = 1;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		pll now = make_pair(-INF, 0);
		ll ff = 0;
		
		for(ll j = i ; j <= n ; j++)
		{
			if(chk[maxx[i][j].se][i - 1])
			{
				ff = 1;
				now = max(now, maxx[i][j]);
			}
			
			dp[i][j] = now.fi;
			yuk[i][j] = {now.se, i - 1};
			chk[i][j] = ff;
		}
		
		for(ll j = i ; j <= n ; j++)
		{
			ll lcp = min(LCP[i][j + 1], j - i + 1);
			ll idx1 = i + lcp;
			ll idx2 = j + 1 + lcp;
			
			if((idx1 > j && idx2 <= n) || (idx1 <= j && idx2 <= n && a[idx1] < a[idx2]))
				maxx[j + 1][idx2] = max(maxx[j + 1][idx2], make_pair(dp[i][j] + 1, i));
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(dp[i][n] > ans)
		{
			ans = dp[i][n];
			X = i, Y = n;
		}
	}
	
	while(1)
	{
		if(X <= 0 || Y <= 0)
			break;
		
		pll tmp = yuk[X][Y];
		
		ansV.push_back({X, Y});
		X = tmp.fi, Y = tmp.se;
	}
	
	reverse(ansV.begin(), ansV.end());
	
	cout << ans en; 
	
	for(auto &i : ansV)
	{
		for(ll j = i.fi ; j <= i.se ; j++)
			cout << a[j];
		
		cout en;
	}
	
	return 0;
}