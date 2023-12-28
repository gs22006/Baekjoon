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
	ll T, L, R, C;
};

struct gujo2
{
	ll A, B, C, D, num;
};

ll n, m;
gujo b[500010];
gujo2 a[500010];
vector<pll> vec[500010];
ll dist[500010];
vector<ll> zip;
priority_queue<pll> pq;
ll P[500010];
ll ans = INF;

struct segtree
{
	pll seg[2000010];
	
	void update(ll no, ll s, ll e, ll w, ll v1, ll v2)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no] = {v1, v2};
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, w, v1, v2);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, w, v1, v2);
		
		seg[no] = min(seg[no << 1], seg[no << 1 | 1]);
	}
	
	pll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return {INF, -1};
		
		if(l <= s && e <= r)
			return seg[no];
		
		pll L = query(no << 1, s, (s + e) >> 1, l, r);
		pll R = query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
		
		return min(L, R);
	}
}segt;

int main(void)
{
	//fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> b[i].T >> b[i].L >> b[i].R >> b[i].C;
		
		a[i].A = b[i].L + b[i].T;
		a[i].B = b[i].R + b[i].T + 1;
		a[i].C = b[i].L - b[i].T;
		a[i].D = b[i].R - b[i].T + 1;
		a[i].num = i;
		zip.push_back(a[i].A), zip.push_back(a[i].B), zip.push_back(a[i].C), zip.push_back(a[i].D);
	}
	
	compress(zip);
	
	for(ll i = 1 ; i <= m ; i++)
	{
		a[i].A = lower_bound(zip.begin(), zip.end(), a[i].A) - zip.begin() + 1;
		a[i].B = lower_bound(zip.begin(), zip.end(), a[i].B) - zip.begin() + 1;
		a[i].C = lower_bound(zip.begin(), zip.end(), a[i].C) - zip.begin() + 1;
		a[i].D = lower_bound(zip.begin(), zip.end(), a[i].D) - zip.begin() + 1;
	}
	
	for(ll i = 1 ; i <= m ; i++)
		dist[i] = INF;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(b[i].L == 1)
		{
			dist[i] = b[i].C;
			pq.push({-b[i].C, i});
		}
		
		vec[a[i].C].push_back({a[i].A, a[i].num});
	}
	
	ll siz = (ll)zip.size();
	
	for(ll i = 1 ; i <= siz ; i++)
	{
		sort(vec[i].begin(), vec[i].end());
		
		if(!vec[i].empty())
		{
			P[i] = 1;
			segt.update(1, 1, siz, i, vec[i][0].fi, vec[i][0].se);
		}
		
		else
			segt.update(1, 1, siz, i, INF, -1);
	}
	
	while(!pq.empty())
	{
		pll qq = pq.top();
		pq.pop();
		
		while(1)
		{
			pll gap = segt.query(1, 1, siz, 1, a[qq.se].D);
			
			if(gap.fi > a[qq.se].B)
				break;
			
			if(dist[gap.se] == INF)
			{
				dist[gap.se] = dist[qq.se] + b[gap.se].C;
				pq.push({-dist[gap.se], gap.se});
			}
			
			if(P[a[gap.se].C] >= (ll)vec[a[gap.se].C].size())
				segt.update(1, 1, siz, a[gap.se].C, INF, -1);
			
			else
			{
				segt.update(1, 1, siz, a[gap.se].C, vec[a[gap.se].C][P[a[gap.se].C]].fi, vec[a[gap.se].C][P[a[gap.se].C]].se);
				P[a[gap.se].C]++;
			}
		}
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(b[i].R == n)
			ans = min(ans, dist[i]);
	}
	
	if(ans == INF)
		cout << -1;
	else
		cout << ans;
	
	return 0;
}