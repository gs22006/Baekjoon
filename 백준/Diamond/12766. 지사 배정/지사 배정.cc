#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n, b, s, r;
ll all, bll, cll;
vector< pair<ll, ll> > vec[5010], yuk[5010];
ll dist1[5010], dist2[5010], gap[5010];
ll nu[5010];
ll dp[5010][5010];
ll ans;

void dijk1(void)
{
	for(ll i = 1 ; i <= n ; i++)
		dist1[i] = INF;
	
	priority_queue< pair<ll, ll> > pq;
	
	dist1[b + 1] = 0;
	pq.push({0, b + 1});
	
	while(!pq.empty())
	{
		pair<ll, ll> qq = pq.top();
		pq.pop();
		
		for(auto &i : vec[qq.se])
		{
			if(dist1[i.fi] > dist1[qq.se] + i.se)
			{
				dist1[i.fi] = dist1[qq.se] + i.se;
				pq.push({-dist1[i.fi], i.fi});
			}
		}
	}
	
	return;
}

void dijk2(void)
{
	for(ll i = 1 ; i <= n ; i++)
		dist2[i] = INF;
	
	priority_queue< pair<ll, ll> > pq;
	
	dist2[b + 1] = 0;
	pq.push({0, b + 1});
	
	while(!pq.empty())
	{
		pair<ll, ll> qq = pq.top();
		pq.pop();
		
		for(auto &i : yuk[qq.se])
		{
			if(dist2[i.fi] > dist2[qq.se] + i.se)
			{
				dist2[i.fi] = dist2[qq.se] + i.se;
				pq.push({-dist2[i.fi], i.fi});
			}
		}
	}
	
	return;
}

ll cost(ll X, ll Y)
{
	return (Y - X) * (nu[Y] - nu[X - 1]);
}

void dnc(ll s, ll e, ll L, ll R, ll grp)
{
	ll mid = (s + e) / 2;
	ll st = L;
	ll ed = min(mid - 1, R);
	ll w = -1;
	
	if(s > e)
		return;
	
	ans += ed - st + 1;
	
	for(ll i = st ; i <= ed ; i++)
	{
		if(dp[mid][grp] > dp[i][grp - 1] + cost(i + 1, mid))
		{
			dp[mid][grp] = dp[i][grp - 1] + cost(i + 1, mid);
			w = i;
		}
	}
	
	dnc(s, mid - 1, L, w, grp);
	dnc(mid + 1, e, w, R, grp);
}

int main(void)
{
	scanf("%lld %lld %lld %lld", &n, &b, &s, &r);
	
	for(ll i = 1 ; i <= r ; i++)
	{
		scanf("%lld %lld %lld", &all, &bll, &cll);
		
		vec[all].push_back({bll, cll});
		yuk[bll].push_back({all, cll});
	}
	
	dijk1();
	dijk2();
	
	for(ll i = 1 ; i <= b ; i++)
		gap[i] = dist1[i] + dist2[i];
	
	for(ll i = 0 ; i <= b ; i++)
	{
		for(ll j = 0 ; j <= s ; j++)
			dp[i][j] = INF;
	}
	
	dp[0][0] = 0;
	sort(gap + 1, gap + 1 + b);
	reverse(gap + 1, gap + 1 + b);
	
	for(ll i = 1 ; i <= b ; i++)
		nu[i] = nu[i - 1] + gap[i];
	
	for(ll j = 1 ; j <= s ; j++)
		dnc(j, b, j - 1, b - 1, j);
	
	printf("%lld", dp[b][s]);
	return 0;
}