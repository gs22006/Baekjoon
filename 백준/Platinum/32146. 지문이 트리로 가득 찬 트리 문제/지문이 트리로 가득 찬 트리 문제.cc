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
pll a[300010];
pair<pll, ll> b[300010];
queue<pll> q;
ll spa[300010][21];
ll idx[300010];
ll K, all;

bool comp(pll X, pll Y)
{
	if(X.se == Y.se)
		return X.fi < Y.fi;
	
	return X.se < Y.se;
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].fi >> a[i].se;
		b[i] = {{a[i].se, a[i].fi}, i};
	}
	
	sort(a + 1, a + 1 + n, comp);
	sort(b + 1, b + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
		idx[b[i].se] = i;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(!q.empty() && q.front().se < a[i].fi)
		{
			spa[q.front().fi][0] = i;
			q.pop();
		}
		
		q.push({i, a[i].se});
	}
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	while(m--)
	{
		cin >> K;
		
		vector<ll> vec;
		
		for(ll i = 0 ; i < K ; i++)
		{
			cin >> all;
			vec.push_back(idx[all]);
		}
		
		ll ans = 0;
		ll now = 1;
		
		for(ll i = 0 ; i < K ; i++)
		{
			if(a[now].se < a[vec[i]].fi)
			{
				for(ll j = 20 ; j >= 0 ; j--)
				{
					if(spa[now][j] == 0)
						continue;
					
					if(a[spa[now][j]].se >= a[vec[i]].fi)
						continue;
					
					now = spa[now][j];
					ans += (1LL << j);
				}
				
				ans++;
			}
			
			now = vec[i];
		}
		
		for(ll j = 20 ; j >= 0 ; j--)
		{
			if(spa[now][j] == 0)
				continue;
			
			now = spa[now][j];
			ans += (1LL << j);
		}
		
		cout << ans + 1 en;
	}
	
	return 0;
}