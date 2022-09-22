#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

ll n, m, k;
ll all, bll, cll, dll, ell;
ll cc, ccc, coco;
vector< pair<ll, ll> > vec[3000010];
vector<ll> tmp[2];
ll dist[3000010];
priority_queue< pair<ll, ll> > pq;
ll num[3000010], num2[3000010];

void init(ll s, ll e)
{
	cc++;
	
	if(s == e)
		return;
	
	init(s, (s + e) / 2);
	init((s + e) / 2 + 1, e);
}

void connect(ll no, ll s, ll e)
{
	num2[no] = ++coco;
	
	if(s == e)
	{
		num[s] = no;
		vec[num2[no]].push_back({num2[no] + cc, 0});
		return;
	}
	
	connect(no * 2, s, (s + e) / 2);
	connect(no * 2 + 1, (s + e) / 2 + 1, e);
	
	vec[num2[no]].push_back({num2[no * 2], 0});
	vec[num2[no]].push_back({num2[no * 2 + 1], 0});
	vec[num2[no * 2] + cc].push_back({num2[no] + cc, 0});
	vec[num2[no * 2 + 1] + cc].push_back({num2[no] + cc, 0});
}

void query(ll no, ll s, ll e, ll l, ll r, ll typ)
{
	if(e < l || r < s)
		return;
	
	if(l <= s && e <= r)
	{
		tmp[typ].push_back(num2[no] + cc * typ);
		return;
	}
	
	query(no * 2, s, (s + e) / 2, l, r, typ);
	query(no * 2 + 1, (s + e) / 2 + 1, e, l, r, typ);
}

int main(void)
{
	fastio
	
	cin >> n >> m >> k;
	
	init(1, n);
	connect(1, 1, n);
	
	ccc = cc * 2;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll >> cll >> dll >> ell;
		
		tmp[0].clear();
		tmp[1].clear();
		
		query(1, 1, n, bll, cll, 1);
		query(1, 1, n, dll, ell, 0);
		
		ccc++;
		
		for(auto &i : tmp[1])
			vec[i].push_back({ccc, 0});
		
		for(auto &i : tmp[0])
			vec[ccc].push_back({i, all});
	}
	
	for(ll i = 1 ; i <= ccc ; i++)
		dist[i] = INF;
	
	dist[num2[num[k]] + cc] = 0;
	pq.push({0, num2[num[k]] + cc});
	
	while(!pq.empty())
	{
		pair<ll, ll> qq = pq.top();
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
	
	for(ll i = 1 ; i <= n ; i++)
		cout << (dist[num2[num[i]] + cc] == INF ? -1 : dist[num2[num[i]] + cc]) sp;
	
	return 0;
}