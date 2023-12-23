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
ll a[500010], b[500010];
vector<pll> vec[500010];
ll dep[500010], D[500010], spa[500010][21];
ll siz[500010], R[500010], P[500010];

struct line
{
	ll A, B;
	ld S;
};

ld gyo(ll A1, ll B1, ll A2, ll B2)
{
	return (ld)(B1 - B2) / (ld)(A2 - A1);
}

struct CHT
{
	vector<line> lin;
	
	void update(ll X, ll Y)
	{
		if(lin.empty())
		{
			lin.push_back({X, Y, -INF});
			return;
		}
		
		while(!lin.empty())
		{
			if(lin.back().A == X)
			{
				if(lin.back().B <= Y)
					return;
				
				lin.pop_back();
				continue;
			}
			
			if(gyo(lin.back().A, lin.back().B, X, Y) < lin.back().S)
            {
				lin.pop_back();
                continue;
            }
			
			break;
		}
		
		ld SS = -INF;
		
		if(!lin.empty())
			SS = gyo(lin.back().A, lin.back().B, X, Y);
		
		lin.push_back({X, Y, SS});
	}
	
	ll query(ll X)
	{
		if(lin.empty())
			return INF;
		
		ll l = 0, r = (ll)lin.size() - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(lin[mid].S <= X)
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		return lin[r].A * X + lin[r].B;
	}
};

CHT cht[500010];
ll gap[500010];
ll ans[500010];

void dfs0(ll here, ll pa)
{
	spa[here][0] = pa;
	dep[here] = dep[pa] + 1;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		D[i.fi] = D[here] + i.se;
		dfs0(i.fi, here);
	}
}

ll LCA(ll X, ll Y)
{
	if(dep[X] < dep[Y])
		swap(X, Y);
	
	ll cha = dep[X] - dep[Y];
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if(cha >= (1LL << i))
		{
			cha -= (1LL << i);
			X = spa[X][i];
		}
	}
	
	if(X == Y)
		return X;
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if(spa[X][i] != spa[Y][i])
		{
			X = spa[X][i];
			Y = spa[Y][i];
		}
	}
	
	return spa[X][0];
}

ll dist(ll X, ll Y)
{
	return D[X] + D[Y] - 2 * D[LCA(X, Y)];
}

void dfs(ll here, ll pa)
{
	siz[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa || R[i.fi])
			continue;
		
		dfs(i.fi, here);
		siz[here] += siz[i.fi];
	}
}

ll get_centroid(ll here, ll pa, ll SIZ)
{
	for(auto &i : vec[here])
	{
		if(i.fi == pa || R[i.fi])
			continue;
		
		if(siz[i.fi] * 2 > SIZ)
			return get_centroid(i.fi, here, SIZ);
	}
	
	return here;
}

void f(ll here, ll pa)
{
	dfs(here, 0);
	ll rt = get_centroid(here, 0, siz[here]);
	
	P[rt] = pa;
	R[rt] = 1;
	
	for(auto &i : vec[rt])
	{
		if(R[i.fi])
			continue;
		
		f(i.fi, rt);
	}
}

void update(ll V, ll B, ll A)
{
	ll tmp = V;
	
	while(tmp)
	{
		cht[tmp].update(B, dist(V, tmp) * B + A);
		tmp = P[tmp];
	}
}

ll query(ll V)
{
	ll tmp = V;
	ll ret = INF;
	
	while(tmp)
	{
		ret = min(ret, cht[tmp].query(dist(V, tmp)));
		tmp = P[tmp];
	}
	
	return ret;
}

vector<long long> travel(vector<ll> A, vector<int> B, vector<int> U, vector<int> V, vector<int> W)
{
	n = (ll)A.size();
	
	for(ll i = 0 ; i < n ; i++)
	{
		a[i + 1] = A[i];
		b[i + 1] = B[i];
	}
	
	for(ll i = 0 ; i < n - 1 ; i++)
	{
		U[i]++, V[i]++;
		vec[U[i]].push_back({V[i], W[i]});
		vec[V[i]].push_back({U[i], W[i]});
	}
	
	dfs0(1, 0);
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	f(1, 0);
	
	vector<pll> vv;
	
	for(ll i = 1 ; i <= n ; i++)
		vv.push_back({b[i], -i});
	
	sort(vv.begin(), vv.end());
	reverse(vv.begin(), vv.end());
	
	ll ff = 0;
	
	for(auto &i : vv)
	{
		i.se *= -1;
		
		if(i.se == 1)
			ff = 1;
		
		if(!ff)
			continue;
		
		if(i.se != 1)
			gap[i.se] = query(i.se);
		
		update(i.se, b[i.se], a[i.se] + gap[i.se]);
	}
	
	vector<ll> ret;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ans[i] = query(i);
		
		if(gap[i] != 0)
			ans[i] = min(ans[i], gap[i]);
		
		if(i >= 2)
			ret.push_back(ans[i]);
	}
	
	return ret;
}