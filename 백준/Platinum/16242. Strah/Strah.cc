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

struct gujo
{
	ll num, w, sum, sum2;
};

ll n, m;
char a[5010][5010];
ll W[5010][5010];
stack<gujo> stk;
ll ans;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll last = m + 1;
		
		for(ll j = m ; j >= 1 ; j--)
		{
			if(a[i][j] == '#')
				last = j;
			
			W[i][j] = last - j;
		}
	}
	
	for(ll j = 1 ; j <= m ; j++)
	{
		while(!stk.empty())
			stk.pop();
		
		for(ll i = n ; i >= 1 ; i--)
		{
			while(!stk.empty() && stk.top().w > W[i][j])
				stk.pop();
			
			ll H = 0;
			gujo tmp;
			
			tmp.num = i;
			tmp.w = W[i][j];
			
			if(stk.empty())
			{
				H = n + 1 - i;
				tmp.sum = (tmp.w * (tmp.w + 1) / 2) * (H * (H + 1) / 2);
				tmp.sum2 = tmp.w * (tmp.w + 1) / 2 * H;
			}
			
			else
			{
				H = stk.top().num - i;
				tmp.sum = stk.top().sum + stk.top().sum2 * H + (tmp.w * (tmp.w + 1) / 2) * (H * (H + 1) / 2);
				tmp.sum2 = stk.top().sum2 + tmp.w * (tmp.w + 1) / 2 * H;
			}
			
			ans += tmp.sum;
			stk.push(tmp);
		}
	}
	
	cout << ans;
	return 0;
}