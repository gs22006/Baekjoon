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
ll a[15010];
ll m;
ll b[15010];
ll sum, S[15010];
priority_queue<ll> pq;
ll now, gaet;
vector< bitset<15010> > dp[15010];
bitset<15010> tmp;
ll ans = INF;
ll I, J, K;
vector<ll> box;
priority_queue<pll> pq2;
vector<ll> ans2[15010];

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		
		sum += a[i];
		pq.push(a[i]);
	}
	
	cin >> m;
	
	for(ll i = 1 ; i <= m ; i++)
		cin >> b[i];
	
	now = sum, gaet = 0;
	
	for(ll i = sum ; i >= 1 ; i--)
	{
		while(!pq.empty() && pq.top() >= i)
		{
			now -= pq.top();
			gaet++;
			pq.pop();
		}
		
		S[i] = now + gaet * i;
	}
	
	for(ll i = 0 ; i <= sum ; i++)
	{
		dp[i].push_back(tmp);
		
		for(ll j = 1 ; j <= m ; j++)
		{
			if(b[j] * i <= sum)
				dp[i].push_back(tmp);
			else
				break;
		}
	}
	
	dp[0].push_back(tmp);
	
	for(ll j = 0 ; j < (ll)dp[0].size() ; j++)
		dp[0][j].set(0, 1);
	
	for(ll i = 1 ; i <= sum ; i++)
	{
		for(ll j = S[i - 1] + 1 ; j <= S[i] ; j++)
			tmp.set(j, 1);
		
		ll siz = (ll)dp[i].size() - 1;
		ll siz2 = (ll)dp[i - 1].size() - 1;
		
		for(ll j = siz ; j >= 1 ; j--)
		{
			if(j < siz)
				dp[i][j] |= dp[i][j + 1];
			
			if(j <= siz2)
				dp[i][j] |= (dp[i - 1][j] << b[j]);
			
			dp[i][j] &= tmp;
		}
	}
	
	for(ll i = 0 ; i <= sum ; i++)
	{
		ll siz = (ll)dp[i].size() - 1;
		
		for(ll j = 1 ; j <= siz ; j++)
		{
			if(dp[i][j][sum])
			{
				if(ans > i)
				{
					ans = i;
					I = i, J = j, K = sum;
				}
			}
		}
	}
	
	if(ans == INF)
	{
		cout << -1;
		return 0;
	}
	
	cout << ans en;
	
	while(1)
	{
		if(I == 0)
			break;
		
		if(J < (ll)dp[I].size() - 1 && dp[I][J + 1][K])
		{
			J = J + 1;
			continue;
		}
		
		box.push_back(b[J]);
		I = I - 1, K = K - b[J];
	}
	
	ll num = 1;
	
	for(auto &i : box)
		pq2.push({i, num++});
	
	for(ll i = 1 ; i <= n ; i++)
	{
		vector<pll> tmp3;
		
		for(ll j = 0 ; j < a[i] ; j++)
		{
			tmp3.push_back(pq2.top());
			pq2.pop();
		}
		
		for(auto &j : tmp3)
		{
			ans2[j.se].push_back(i);
			
			if(j.fi > 1)
				pq2.push({j.fi - 1, j.se});
		}
	}
	
	for(ll i = 1 ; i <= ans ; i++)
	{
		cout << (ll)ans2[i].size() sp;
		
		for(auto &j : ans2[i])
			cout << j sp;
		
		cout en;
	}
	
	return 0;
}