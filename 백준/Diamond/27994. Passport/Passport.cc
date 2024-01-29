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
pll a[200010];
ll q;
ll X;
vector<pll> vec[1000010], yuk[1000010];
ll num[1000010];
ll dist[1000010];
ll A[1000010], B[1000010];
ll siz;
ll ans[1000010];

void init(ll no, ll s, ll e)
{
	siz = max(siz, no);
	
	if(s == e)
	{
		num[s] = no;
		return;
	}
	
	vec[no << 1].push_back({no, 0});
	vec[no << 1 | 1].push_back({no, 0});
	
	init(no << 1, s, (s + e) >> 1);
	init(no << 1 | 1, ((s + e) >> 1) + 1, e);
}

void update(ll no, ll s, ll e, ll l, ll r, ll V)
{
	if(e < l || r < s)
		return;
	
	if(l <= s && e <= r)
	{
		vec[no].push_back({V, 1});
		return;
	}
	
	update(no << 1, s, (s + e) >> 1, l, r, V);
	update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, V);
}

void f(ll sta)
{
	for(ll i = 0 ; i <= siz ; i++)
		dist[i] = INF / (siz + 10);
	
	deque<ll> dq;
	
	dist[sta] = 0;
	dq.push_back(sta);
	
	while(!dq.empty())
	{
		ll qq = dq.front();
		dq.pop_front();
		
		for(auto &i : vec[qq])
		{
			if(dist[i.fi] > dist[qq] + i.se)
			{
				if(i.se == 0)
				{
					dist[i.fi] = dist[qq];
					dq.push_front(i.fi);
				}
				
				else
				{
					dist[i.fi] = dist[qq] + 1;
					dq.push_back(i.fi);
				}
			}
		}
	}
}

void f2(ll sta)
{
	priority_queue<pll> pq;
	
	for(ll i = 1 ; i <= siz ; i++)
		dist[i] = INF;
	
	dist[sta] = 0;
	pq.push({0, sta});
	
	while(!pq.empty())
	{
		pll qq = pq.top();
		pq.pop();
		
		for(auto &i : vec[qq.se])
		{
			if(dist[i.fi] > dist[qq.se] + i.se)
			{
				dist[i.fi] = dist[qq.se] + i.se;
				pq.push({-dist[i.fi], i.fi});
			}
		}
	}
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	
	init(1, 1, n);
	
	for(ll i = 1 ; i <= n ; i++)
		update(1, 1, n, a[i].fi, a[i].se, num[i]);
	
	f(num[1]);
	
	for(ll i = 1 ; i <= siz ; i++)
		A[i] = dist[i];
	
	f(num[n]);
	
	for(ll i = 1 ; i <= siz ; i++)
		B[i] = dist[i];
	
	for(ll i = 1 ; i <= n ; i++)
		vec[siz + 1].push_back({num[i], max(A[num[i]] - 1, 0LL) + max(B[num[i]] - 1, 0LL) + 1});
	
	siz++;
	
	f2(siz);
	
	for(ll i = 1 ; i <= siz ; i++)
		ans[i] = dist[i];
	
	cin >> q;
	
	while(q--)
	{
		cin >> X;
		
		if(ans[num[X]] >= INF / (siz + 10))
			cout << -1 en;
		else
			cout << ans[num[X]] en;
	}
	
	return 0;
}