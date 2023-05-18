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
	ll X, Y, D;
};

ll n;
ll W, H;
gujo a[500010];
vector<ll> L[500010], R[500010];
vector<pll> w[500010];
vector< pair<pll, ll> > vec[500010];
map<ll, ll> mp[10];
vector< pair<ll, pll> > gu;
ll cc;
ll life[500010];
priority_queue< pair<pll, pll> > pq;
vector< pair<ll, pll> > G, S;
ll ans;
vector<ll> zip;
ll tp[500010];
vector< pair<pll, ll> > tmtmp;

void add0(ll I, ll typ)
{
	if(mp[0].find(a[I].X) == mp[0].end())
		mp[0][a[I].X] = cc++;
	
	tp[mp[0][a[I].X]] = 0;
	vec[mp[0][a[I].X]].push_back({{a[I].Y, I}, typ});
}

void add1(ll I, ll typ)
{
	if(mp[1].find(a[I].Y) == mp[1].end())
		mp[1][a[I].Y] = cc++;
	
	tp[mp[1][a[I].Y]] = 1;
	vec[mp[1][a[I].Y]].push_back({{a[I].X, I}, typ});
}

void add2(ll I, ll typ)
{
	if(mp[2].find(a[I].X + a[I].Y) == mp[2].end())
		mp[2][a[I].X + a[I].Y] = cc++;
	
	tp[mp[2][a[I].X + a[I].Y]] = 2;
	vec[mp[2][a[I].X + a[I].Y]].push_back({{a[I].Y, I}, typ});
}

void add3(ll I, ll typ)
{
	if(mp[3].find(a[I].X + a[I].Y) == mp[3].end())
		mp[3][a[I].X + a[I].Y] = cc++;
	
	tp[mp[3][a[I].X + a[I].Y]] = 3;
	vec[mp[3][a[I].X + a[I].Y]].push_back({{a[I].Y, I}, typ});
}

void add4(ll I, ll typ)
{
	if(mp[4].find(a[I].X - a[I].Y) == mp[4].end())
		mp[4][a[I].X - a[I].Y] = cc++;
	
	tp[mp[4][a[I].X - a[I].Y]] = 4;
	vec[mp[4][a[I].X - a[I].Y]].push_back({{a[I].Y, I}, typ});
}

void add5(ll I, ll typ)
{
	if(mp[5].find(a[I].X - a[I].Y) == mp[5].end())
		mp[5][a[I].X - a[I].Y] = cc++;
	
	tp[mp[5][a[I].X - a[I].Y]] = 5;
	vec[mp[5][a[I].X - a[I].Y]].push_back({{a[I].Y, I}, typ});
}

void die(ll X)
{
	if(life[X])
		return;
	
	for(auto &i : w[X])
	{
		if(R[i.fi][i.se] < (ll)vec[i.fi].size())
			L[i.fi][R[i.fi][i.se]] = L[i.fi][i.se];
		
		if(L[i.fi][i.se] >= 0)
			R[i.fi][L[i.fi][i.se]] = R[i.fi][i.se];
	}
}

struct segtree
{
	ll seg[1500010];
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no] += v;
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, w, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, w, v);
		
		seg[no] = seg[no << 1] + seg[no << 1 | 1];
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return query(no << 1, s, (s + e) >> 1, l, r) + query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
	}
}segt;

void ud(ll x, ll y)
{
	if(x < 0 || y < 0)
		return;
	
	x = lower_bound(zip.begin(), zip.end(), x) - zip.begin() + 1;
	y = lower_bound(zip.begin(), zip.end(), y) - zip.begin() + 1;
	
	segt.update(1, 0, (ll)zip.size() + 2, x, 1);
	segt.update(1, 0, (ll)zip.size() + 2, y + 1, -1);
}

int main(void)
{
	fastio
	
	cin >> W >> H;
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].Y >> a[i].X >> a[i].D;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i].D == 0)
		{
			add0(i, 0);
			add2(i, 0);
			add4(i, 0);
		}
		
		else if(a[i].D == 1)
		{
			add1(i, 1);
			add3(i, 0);
			add4(i, 1);
		}
		
		else if(a[i].D == 2)
		{
			add0(i, 1);
			add3(i, 1);
			add5(i, 1);
		}
		
		else if(a[i].D == 3)
		{
			add1(i, 0);
			add2(i, 1);
			add5(i, 0);
		}
	}
    
	for(ll i = 0 ; i < cc ; i++)
	{
		sort(vec[i].begin(), vec[i].end());
		
		for(ll j = 0 ; j < (ll)vec[i].size() ; j++)
		{
			w[vec[i][j].fi.se].push_back({i, j});
			L[i].push_back(j - 1);
			R[i].push_back(j + 1);
		}
		
		for(ll j = 1 ; j < (ll)vec[i].size() ; j++)
		{
			if(vec[i][j - 1].se == 0 && vec[i][j].se == 1)
			{
				if(tp[i] == 0 || tp[i] == 1)
					pq.push({{-vec[i][j].fi.fi + vec[i][j - 1].fi.fi, i}, {vec[i][j - 1].fi.se, vec[i][j].fi.se}});
				else
					pq.push({{2 * (-vec[i][j].fi.fi + vec[i][j - 1].fi.fi), i}, {vec[i][j - 1].fi.se, vec[i][j].fi.se}});
			}
		}
	}
    
	while(!pq.empty())
	{
		pair<pll, pll> qq = pq.top();
		pq.pop();
        
		if(life[qq.se.fi])
		{
			ll J = 0;
			ll J2 = 0;
			
			for(auto &i : w[qq.se.fi])
			{
				if(i.fi == qq.fi.se)
				{
					J = i.se;
					break;
				}
			}
			
			for(auto &i : w[qq.se.se])
			{
				if(i.fi == qq.fi.se)
				{
					J2 = i.se;
					break;
				}
			}
			
			if(L[qq.fi.se][J] < 0)
				continue;
			
			ll lf = L[qq.fi.se][J];
			
			if(vec[qq.fi.se][lf].se == 1)
				continue;
			
			if(tp[qq.fi.se] == 0 || tp[qq.fi.se] == 1)
				pq.push({{vec[qq.fi.se][lf].fi.fi - vec[qq.fi.se][J2].fi.fi, qq.fi.se}, {vec[qq.fi.se][lf].fi.se, vec[qq.fi.se][J2].fi.se}});
			else
				pq.push({{(vec[qq.fi.se][lf].fi.fi - vec[qq.fi.se][J2].fi.fi) * 2, qq.fi.se}, {vec[qq.fi.se][lf].fi.se, vec[qq.fi.se][J2].fi.se}});
			
			continue;
		}
		
		if(life[qq.se.se])
		{
			ll J = 0;
			ll J2 = 0;
			
			for(auto &i : w[qq.se.se])
			{
				if(i.fi == qq.fi.se)
				{
					J = i.se;
					break;
				}
			}
			
			for(auto &i : w[qq.se.fi])
			{
				if(i.fi == qq.fi.se)
				{
					J2 = i.se;
					break;
				}
			}
			
			if(R[qq.fi.se][J] >= (ll)vec[qq.fi.se].size())
				continue;
			
			ll rg = R[qq.fi.se][J];
			
			if(vec[qq.fi.se][rg].se == 0)
				continue;
			
			if(tp[qq.fi.se] == 0 || tp[qq.fi.se] == 1)
				pq.push({{-vec[qq.fi.se][rg].fi.fi + vec[qq.fi.se][J2].fi.fi, qq.fi.se}, {vec[qq.fi.se][J2].fi.se, vec[qq.fi.se][rg].fi.se}});
			else
				pq.push({{(-vec[qq.fi.se][rg].fi.fi + vec[qq.fi.se][J2].fi.fi) * 2, qq.fi.se}, {vec[qq.fi.se][J2].fi.se, vec[qq.fi.se][rg].fi.se}});
			
			continue;
		}
		
		vector< pair<pll, pll> > vv;
		
		vv.push_back(qq);
		
		while(!pq.empty() && pq.top().fi.fi == vv[0].fi.fi)
		{
			pair<pll, pll> QQ = pq.top();
			pq.pop();
			
			if(life[QQ.se.fi])
			{
				ll J = 0;
				ll J2 = 0;
				
				for(auto &i : w[QQ.se.fi])
				{
					if(i.fi == QQ.fi.se)
					{
						J = i.se;
						break;
					}
				}
				
				for(auto &i : w[QQ.se.se])
				{
					if(i.fi == QQ.fi.se)
					{
						J2 = i.se;
						break;
					}
				}
				
				if(L[QQ.fi.se][J] < 0)
					continue;
				
				ll lf = L[QQ.fi.se][J];
				
				if(vec[QQ.fi.se][lf].se == 1)
					continue;
				
				if(tp[QQ.fi.se] == 0 || tp[QQ.fi.se] == 1)
					pq.push({{vec[QQ.fi.se][lf].fi.fi - vec[QQ.fi.se][J2].fi.fi, QQ.fi.se}, {vec[QQ.fi.se][lf].fi.se, vec[QQ.fi.se][J2].fi.se}});
				else
					pq.push({{(vec[QQ.fi.se][lf].fi.fi - vec[QQ.fi.se][J2].fi.fi) * 2, QQ.fi.se}, {vec[QQ.fi.se][lf].fi.se, vec[QQ.fi.se][J2].fi.se}});
				
				continue;
			}
			
			if(life[QQ.se.se])
			{
				ll J = 0;
				ll J2 = 0;
				
				for(auto &i : w[QQ.se.se])
				{
					if(i.fi == QQ.fi.se)
					{
						J = i.se;
						break;
					}
				}
				
				for(auto &i : w[QQ.se.fi])
				{
					if(i.fi == QQ.fi.se)
					{
						J2 = i.se;
						break;
					}
				}
				
				if(R[QQ.fi.se][J] >= (ll)vec[QQ.fi.se].size())
					continue;
				
				ll rg = R[QQ.fi.se][J];
				
				if(vec[QQ.fi.se][rg].se == 0)
					continue;
				
				if(tp[QQ.fi.se] == 0 || tp[QQ.fi.se] == 1)
					pq.push({{-vec[QQ.fi.se][rg].fi.fi + vec[QQ.fi.se][J2].fi.fi, QQ.fi.se}, {vec[QQ.fi.se][J2].fi.se, vec[QQ.fi.se][rg].fi.se}});
				else
					pq.push({{(-vec[QQ.fi.se][rg].fi.fi + vec[QQ.fi.se][J2].fi.fi) * 2, QQ.fi.se}, {vec[QQ.fi.se][J2].fi.se, vec[QQ.fi.se][rg].fi.se}});
				
				continue;
			}
			
			vv.push_back(QQ);
		}
		
		for(auto &i : vv)
		{
			die(i.se.fi);
			die(i.se.se);
			
			if(tp[i.fi.se] == 0 || tp[i.fi.se] == 1)
				life[i.se.fi] = life[i.se.se] = -i.fi.fi;
			else
				life[i.se.fi] = life[i.se.se] = (-i.fi.fi) / 2;
		}
		
		for(auto &i : vv)
		{
			ll num1 = i.se.fi;
			ll num2 = i.se.se;
			ll J1 = 0, J2 = 0;
			
			for(auto &j : w[num1])
			{
				if(j.fi == i.fi.se)
				{
					J1 = j.se;
					break;
				}
			}
			
			for(auto &j : w[num2])
			{
				if(j.fi == i.fi.se)
				{
					J2 = j.se;
					break;
				}
			}
			
			ll lf = L[i.fi.se][J1];
			ll rg = R[i.fi.se][J2];
			
			if(lf < 0 || rg >= (ll)vec[i.fi.se].size())
				continue;
			
			if(vec[i.fi.se][lf].se == 0 && vec[i.fi.se][rg].se == 1)
			{
				if(tp[i.fi.se] == 0 || tp[i.fi.se] == 1)
					pq.push({{vec[i.fi.se][lf].fi.fi - vec[i.fi.se][rg].fi.fi, i.fi.se}, {vec[i.fi.se][lf].fi.se, vec[i.fi.se][rg].fi.se}});
				else
					pq.push({{(vec[i.fi.se][lf].fi.fi - vec[i.fi.se][rg].fi.fi) * 2, i.fi.se}, {vec[i.fi.se][lf].fi.se, vec[i.fi.se][rg].fi.se}});
			}
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(life[i])
		{
			life[i]++;
			continue;
		}
		
		if(a[i].D == 0)
			life[i] = W - a[i].Y + 1;
		else if(a[i].D == 1)
			life[i] = a[i].X;
		else if(a[i].D == 2)
			life[i] = a[i].Y;
		else if(a[i].D == 3)
			life[i] = H - a[i].X + 1;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i].D == 0)
		{
			G.push_back({a[i].X, {a[i].Y, a[i].Y + life[i] - 1}});
			zip.push_back(a[i].X);
			zip.push_back(a[i].Y);
			zip.push_back(a[i].Y + life[i] - 1);
		}
		
		else if(a[i].D == 2)
		{
			G.push_back({a[i].X, {a[i].Y - life[i] + 1, a[i].Y}});
			zip.push_back(a[i].X);
			zip.push_back(a[i].Y);
			zip.push_back(a[i].Y - life[i] + 1);
		}
		
		else if(a[i].D == 1)
		{
			S.push_back({a[i].Y, {a[i].X - life[i] + 1, a[i].X}});
			zip.push_back(a[i].Y);
			zip.push_back(a[i].X - life[i] + 1);
			zip.push_back(a[i].X);
		}
		
		else if(a[i].D == 3)
		{
			S.push_back({a[i].Y, {a[i].X, a[i].X + life[i] - 1}});
			zip.push_back(a[i].Y);
			zip.push_back(a[i].X + life[i] - 1);
			zip.push_back(a[i].X);
		}
	}
	
	compress(zip);
	sort(G.begin(), G.end());
	
	ll last = -1;
	vector<pll> help;
	
	if(!G.empty())
	{
		last = G[0].fi;
		help.push_back(G[0].se);
	}
	
	for(ll i = 1 ; i < (ll)G.size() ; i++)
	{
		if(last != G[i].fi)
		{
			if(!help.empty())
			{
				ll s = help[0].fi;
				ll e = help[0].se;
				
				for(ll j = 1 ; j < (ll)help.size() ; j++)
				{
					if(help[j].fi <= e)
						e = max(help[j].se, e);
					
					else
					{
						gu.push_back({last, {s, e}});
						s = help[j].fi;
						e = help[j].se;
					}
				}
				
				gu.push_back({last, {s, e}});
			}
			
			last = G[i].fi;
			help.clear();
			help.push_back(G[i].se);
		}
		
		else
			help.push_back(G[i].se);
	}
	
	if(!help.empty())
	{
		ll s = help[0].fi;
		ll e = help[0].se;
		
		for(ll j = 1 ; j < (ll)help.size() ; j++)
		{
			if(help[j].fi <= e)
				e = max(e, help[j].se);
			
			else
			{
				gu.push_back({last, {s, e}});
				s = help[j].fi;
				e = help[j].se;
			}
		}
		
		gu.push_back({last, {s, e}});
	}
	
	for(auto &i : gu)
		ans += i.se.se - i.se.fi + 1;
	
	last = -1;
	vector< pair<ll, pll> > gu2;
	help.clear();
	
	sort(S.begin(), S.end());
	
	if(!S.empty())
	{
		last = S[0].fi;
		help.push_back(S[0].se);
	}
	
	for(ll i = 1 ; i < (ll)S.size() ; i++)
	{
		if(last != S[i].fi)
		{
			if(!help.empty())
			{
				ll s = help[0].fi;
				ll e = help[0].se;
				
				for(ll j = 1 ; j < (ll)help.size() ; j++)
				{
					if(help[j].fi <= e)
						e = max(help[j].se, e);
					
					else
					{
						gu2.push_back({last, {s, e}});
						s = help[j].fi;
						e = help[j].se;
					}
				}
				
				gu2.push_back({last, {s, e}});
			}
			
			last = S[i].fi;
			help.clear();
			help.push_back(S[i].se);
		}
		
		else
			help.push_back(S[i].se);
	}
	
	if(!help.empty())
	{
		ll s = help[0].fi;
		ll e = help[0].se;
		
		for(ll j = 1 ; j < (ll)help.size() ; j++)
		{
			if(help[j].fi <= e)
				e = max(e, help[j].se);
			
			else
			{
				gu2.push_back({last, {s, e}});
				s = help[j].fi;
				e = help[j].se;
			}
		}
		
		gu2.push_back({last, {s, e}});
	}
    
	for(auto &i : gu2)
	{
		ans += i.se.se - i.se.fi + 1;
		tmtmp.push_back({{i.se.fi - 1, i.fi}, 1});
		tmtmp.push_back({{i.se.se, i.fi}, -1});
	}
	
	sort(tmtmp.begin(), tmtmp.end());
	ll p = 0;
	
	for(auto &i : tmtmp)
	{
		while(p < (ll)gu.size() && gu[p].fi <= i.fi.fi)
		{
			ud(gu[p].se.fi, gu[p].se.se);
			p++;
		}
		
		ll numm = lower_bound(zip.begin(), zip.end(), i.fi.se) - zip.begin() + 1;
		
		ans += segt.query(1, 0, (ll)zip.size() + 2, 0, numm) * i.se;
	}
	
	cout << ans;
	return 0;
}