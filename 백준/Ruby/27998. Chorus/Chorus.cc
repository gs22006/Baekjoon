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

ll n, K;
string s;
ll h[2000010];
ll x, y;
ll nu[2000010];
ll idx[2000010];
ll p = 1;
ll dp[2000010], yuk[2000010];

struct line
{
	ll A, B;
	ld S;
	ll I;
};

ld gyo(ll A1, ll B1, ll A2, ll B2)
{
	return (ld)(B2 - B1) / (ld)(A1 - A2);
}

struct CHT
{
	vector<line> lin;
	
	void init(void)
	{
		lin.clear();
	}
	
	void update(ll X, ll Y, ll I)
	{
		while(!lin.empty())
		{
			if(gyo(X, Y, lin.back().A, lin.back().B) < lin.back().S)
				lin.pop_back();
			else
				break;
		}
		
		if(lin.empty())
		{
			lin.push_back({X, Y, -INF, I});
			return;
		}
		
		lin.push_back({X, Y, gyo(X, Y, lin.back().A, lin.back().B), I});
	}
	
	pll query(ll X)
	{
		ll l = 0, r = (ll)lin.size() - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(lin[mid].S <= X)
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		return {lin[r].A * X + lin[r].B, lin[r].I};
	}
}cht;

pll solve(ll lambda)
{
	deque<pll> dq;
	
	cht.init();
	cht.update(0, n * n + 1, 0);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		dp[i] = nu[i] + lambda;
		yuk[i] = 1;
		
		while(!dq.empty() && dq.front().fi <= i)
		{
			ll num = dq.front().se;
			
			cht.update(-num, dp[num] + num * (idx[num] - 1) - nu[idx[num] - 1], num);
			dq.pop_front();
		}
		
		if(!dq.empty())
		{
			if(dp[i] > dp[dq.front().se] + lambda)
			{
				dp[i] = dp[dq.front().se] + lambda;
				yuk[i] = yuk[dq.front().se] + 1;
			}
		}
		
		pll gap = cht.query(i);
		
		gap.fi += nu[i];
		
		if(dp[i] > gap.fi + lambda)
		{
			dp[i] = gap.fi + lambda;
			yuk[i] = yuk[gap.se] + 1;
		}
		
		while(!dq.empty() && dp[dq.front().se] > dp[i])
			dq.pop_back();
		
		dq.push_back({idx[i], i});
	}
	
	return {dp[n], yuk[n]};
}

int main(void)
{
	fastio
	
	cin >> n >> K;
	cin >> s;
	
	for(ll i = 0 ; i < n * 2 ; i++)
	{
		if(s[i] == 'A')
			x++, h[x] = y;
		else
			y++;
	}
	
	for(ll i = 1 ; i <= n ; i++)
		nu[i] = nu[i - 1] + h[i];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(p <= n && h[p] < i)
			p++;
		
		idx[i] = max(i + 1, p);
	}
	
	ll l = -n * n, r = n * n;
	ll ans = -INF;
	
	while(l <= r)
	{
		ll mid = (l + r) >> 1;
		pll gap = solve(mid);
		
		ans = max(ans, gap.fi - mid * K);
		
		if(gap.se <= K)
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	cout << ans;
	return 0;
}