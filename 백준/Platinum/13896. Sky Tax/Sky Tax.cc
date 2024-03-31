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
ll n, q, R;
ll all, bll;
vector<ll> vec[100010];
ll CCC;
ll gap[100010], siz[100010];
ll spa[100010][21], hspa[100010][21];
ll dep[100010];

void dfs0(ll here, ll pa)
{
	spa[here][0] = pa;
	dep[here] = dep[pa] + 1;
	siz[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs0(i, here);
		siz[here] += siz[i];
	}
}

void dfs(ll here, ll pa)
{
	ll sum = 1;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs(i, here);
		sum += siz[i];
	}
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		hspa[i][0] = sum - siz[i];
	}
}

ll lift(ll X, ll Y)
{
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if((1LL << i) <= Y)
		{
			Y -= (1LL << i);
			X = spa[X][i];
		}
	}
	
	return X;
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n >> q >> R;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			vec[i].clear();
			gap[i] = dep[i] = siz[i] = 0;
			
			for(ll j = 0 ; j <= 20 ; j++)
				spa[i][j] = hspa[i][j] = 0;
		}
		
		for(ll i = 1 ; i < n ; i++)
		{
			cin >> all >> bll;
			
			vec[all].push_back(bll);
			vec[bll].push_back(all);
		}
		
		dfs0(1, 0);
		dfs(1, 0);
		
		for(ll i = 1 ; i <= 20 ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
			{
				spa[j][i] = spa[spa[j][i - 1]][i - 1];
				hspa[j][i] = hspa[j][i - 1] + hspa[spa[j][i - 1]][i - 1];
			}
		}
		
		CCC++;
		cout << "Case #" << CCC << ":\n";
		
		while(q--)
		{
			cin >> all >> bll;
			
			if(all == 0)
			{
				R = bll;
				continue;
			}
			
			if(R == bll)
			{
				cout << n en;
				continue;
			}
			
			if(dep[R] < dep[bll])
			{
				cout << siz[bll] en;
				continue;
			}
			
			if(lift(R, dep[R] - dep[bll]) != bll)
			{
				cout << siz[bll] en;
				continue;
			}
			
			ll ans = siz[bll], now = dep[R] - dep[1], now2 = R;
			
			for(ll i = 20 ; i >= 0 ; i--)
			{
				if((1LL << i) <= now)
				{
					now -= (1LL << i);
					ans += hspa[now2][i];
					now2 = spa[now2][i];
				}
			}
			
			now = dep[R] - dep[bll], now2 = R;
			
			for(ll i = 20 ; i >= 0 ; i--)
			{
				if((1LL << i) <= now)
				{
					now -= (1LL << i);
					ans -= hspa[now2][i];
					now2 = spa[now2][i];
				}
			}
			
			ans -= siz[lift(R, dep[R] - dep[bll] - 1)];
			cout << ans en;
		}
	}
	
	return 0;
}