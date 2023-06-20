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

ll n, m, K, q;
ll all, bll, cll;
vector<pll> vec[100010], qry, V;
ll sta[100010];
ll dist[100010];
ll L[100010], R[100010];
ll mid[100010];
ll pa[100010], ra[100010];
ll chk[100010];

ll ffind(ll here)
{
	if(pa[here] == here)
		return here;
	
	return pa[here] = ffind(pa[here]);
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	if(ra[X] < ra[Y])
		pa[X] = Y;
	else if(ra[Y] < ra[X])
		pa[Y] = X;
	
	else
	{
		pa[X] = Y;
		ra[Y]++;
	}
}

void dijksta(void)
{
	for(ll i = 1 ; i <= n ; i++)
		dist[i] = INF;
	
	priority_queue<pll> pq;
	
	for(ll i = 1 ; i <= K ; i++)
	{
		pq.push({0, sta[i]});
		dist[sta[i]] = 0;
	}
	
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
	
	return;
}

int main(void)
{
	fastio
	
	cin >> n >> m >> K >> q;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll >> cll;
		
		vec[all].push_back({bll, cll});
		vec[bll].push_back({all, cll});
	}
	
	for(ll i = 1 ; i <= K ; i++)
		cin >> sta[i];
	
	for(ll i = 0 ; i < q ; i++)
	{
		cin >> all >> bll;
		qry.push_back({all, bll});
	}
	
	dijksta();
	
	for(ll i = 1 ; i <= n ; i++)
		V.push_back({dist[i], i});
	
	sort(V.begin(), V.end());
	reverse(V.begin(), V.end());
	
	for(ll i = 0 ; i < q ; i++)
	{
		L[i] = 0;
		R[i] = 500000;
	}
	
	for(ll o = 0 ; o < 20 ; o++)
	{
		vector<pll> Q;
		
		for(ll i = 1 ; i <= n ; i++)
			pa[i] = i, ra[i] = chk[i] = 0;
		
		for(ll i = 0 ; i < q ; i++)
		{
			mid[i] = (L[i] + R[i]) >> 1;
			
			if(L[i] <= R[i])
				Q.push_back({mid[i], i});
		}
		
		sort(Q.begin(), Q.end());
		reverse(Q.begin(), Q.end());
		
		ll p = 0;
		
		for(auto &i : Q)
		{
			while(p < n && V[p].fi >= i.fi)
			{
				ll v = V[p].se;
				
				for(auto &j : vec[v])
				{
					if(chk[j.fi])
						uunion(v, j.fi);
				}
				
				chk[v] = 1;
				p++;
			}
			
			if(ffind(qry[i.se].fi) == ffind(qry[i.se].se))
				L[i.se] = mid[i.se] + 1;
			else
				R[i.se] = mid[i.se] - 1;
		}
	}
	
	for(ll i = 0 ; i < q ; i++)
		cout << R[i] en;
	
	return 0;
}