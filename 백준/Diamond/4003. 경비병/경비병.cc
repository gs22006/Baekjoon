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

struct gu
{
	ll L, R;
	
	bool operator < (const gu &xx) const
	{
		if(R == xx.R)
			return L > xx.L;
		
		return R < xx.R;
	}
};

ll n, K, m;
ll a[100010], b[100010], c[100010];
vector<ll> ans, vec[100010], yuk[100010];
ll z[100010];
ll l[100010], r[100010];
ll sum;
ll deg[100010], deg2[100010];
ll dp[100010], dp2[100010];
ll l2[100010], r2[100010];
ll nu[100010], nu2[100010];

int main(void)
{
	fastio
	
	cin >> n >> K >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		
		if(!c[i])
		{
			z[a[i]]++;
			z[b[i] + 1]--;
		}
	}
	
	sum = n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		z[i] += z[i - 1];
		
		if(z[i])
			sum--;
	}
	
	ll w = -1;
	
	for(ll i = n ; i >= 1 ; i--)
	{
		if(!z[i])
		{
			w = -1;
			continue;
		}
		
		w = max(w, i);
		r[i] = w;
	}
	
	w = INF;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!z[i])
		{
			w = INF;
			continue;
		}
		
		w = min(w, i);
		l[i] = w;
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(c[i])
		{
			if(r[a[i]])
				a[i] = r[a[i]] + 1;
			
			if(l[b[i]])
				b[i] = l[b[i]] - 1;
		}
	}
	
	vector<gu> tmp1, vv;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(c[i])
			tmp1.push_back({a[i], b[i]});
	}
	
	sort(tmp1.begin(), tmp1.end());
	
	ll maxx = 0;
	
	for(ll i = 0 ; i < (ll)tmp1.size() ; i++)
	{
		if(tmp1[i].L <= maxx)
			continue;
		
		maxx = max(maxx, tmp1[i].L);
		vv.push_back(tmp1[i]);
	}
	
	queue<ll> q;
	
	for(ll i = 0 ; i < (ll)vv.size() ; i++)
	{
		while(!q.empty() && vv[q.front()].R < vv[i].L)
		{
			yuk[i].push_back(q.front());
			vec[q.front()].push_back(i);
			deg[q.front()]++;
			deg2[i]++;
			q.pop();
		}
		
		q.push(i);
	}
	
	while(!q.empty())
		q.pop();
	
	for(ll i = 0 ; i < (ll)vv.size() ; i++)
	{
		if(!deg[i])
		{
			q.push(i);
			dp[i] = 1;
		}
	}
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		for(auto &i : yuk[qq])
		{
			deg[i]--;
			dp[i] = max(dp[i], dp[qq] + 1);
			
			if(!deg[i])
				q.push(i);
		}
	}
	
	while(!q.empty())
		q.pop();
	
	for(ll i = 0 ; i < (ll)vv.size() ; i++)
	{
		if(!deg2[i])
		{
			q.push(i);
			dp2[i] = 1;
		}
	}
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		for(auto &i : vec[qq])
		{
			deg2[i]--;
			dp2[i] = max(dp2[i], dp2[qq] + 1);
			
			if(!deg2[i])
				q.push(i);
		}
	}
	
	for(ll i = 0 ; i < (ll)vv.size() ; i++)
	{
		nu[vv[i].R] = max(nu[vv[i].R], dp2[i]);
		nu2[vv[i].L] = max(nu2[vv[i].L], dp[i]);
	}
	
	for(ll i = 1 ; i <= n ; i++)
		nu[i] = max(nu[i], nu[i - 1]);
	
	for(ll i = n ; i >= 1 ; i--)
		nu2[i] = max(nu2[i], nu2[i + 1]);
	
	ll wd = 0;
	
	for(ll i = 0 ; i < (ll)vv.size() ; i++)
		wd = max(wd, dp[i]);
	
	for(ll i = 1 ; i <= n ; i++)
		l2[i] = r2[i] = -1;
	
	for(ll i = 0 ; i < (ll)vv.size() ; i++)
	{
		if(l2[vv[i].L] != -1)
			assert(0);
		
		if(r2[vv[i].R] != -1)
			assert(0);
		
		l2[vv[i].L] = i;
		r2[vv[i].R] = i;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll gap = 0;
		
		if(z[i])
			continue;
		
		if(sum - 1 < K)
		{
			ans.push_back(i);
			continue;
		}
		
		gap = wd;
		
		if(r2[i] != -1)
		{
			ll w = r2[i];
			gu nx = vv[w];
			
			nx.R--;
			
			if(l[nx.R])
				nx.R = l[nx.R] - 1;
			
			if(nx.L > nx.R)
			{
				ans.push_back(i);
				continue;
			}
			
			gap = max(gap, nu[nx.L - 1] + 1 + nu2[nx.R + 1]);
		}
		
		if(l2[i] != -1)
		{
			ll w = l2[i];
			gu nx = vv[w];
			
			nx.L++;
			
			if(r[nx.L])
				nx.L = r[nx.L] + 1;
			
			if(nx.L > nx.R)
			{
				ans.push_back(i);
				continue;
			}
			
			gap = max(gap, nu[nx.L - 1] + 1 + nu2[nx.R + 1]);
		}
		
		if(l2[i] != -1 && r2[i] != -1)
		{
			ll w1 = l2[i];
			ll w2 = r2[i];
			
			gu nx = vv[w1];
			gu nx2 = vv[w2];
			
			nx2.R--;
			
			if(l[nx2.R])
				nx2.R = l[nx2.R] - 1;
			
			nx.L++;
			
			if(r[nx.L])
				nx.L = r[nx.L] + 1;
			
			if(nx2.R < nx.L)
				gap = max(gap, nu[nx2.L - 1] + 2 + nu2[nx.R + 1]);
		}
		
		if(gap > K)
			ans.push_back(i);
	}
	
	if(ans.empty())
		cout << -1;
	
	else
	{
		for(auto &i : ans)
			cout << i en;
	}
	
	return 0;
}