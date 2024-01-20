#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n, K;
vector<ll> vec[1000010], vec3[1000010];
vector<pll> vv2[1000010];
vector<pll> LR[1000010];
ll bun[1000010];
multiset<ll> ST[1000010];
map<ll, pll> MP[1000010];
ll BUN[1000010];
ll s[1000010], e[1000010];
ll dep[1000010];
ll spa[1000010][21];
ll tp[1000010];
ll ETT[1000010];
ll cc;
ll lf[1000010], rg[1000010];
ll ans, ans2, ans3 = 1;

struct segtree
{
	ll seg[4000010];
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no] = v;
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, w, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, w, v);
		
		seg[no] = min(seg[no << 1], seg[no << 1 | 1]);
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(l > r)
			assert(0);
		
		if(e < l || r < s)
			return (1LL << 29);
		
		if(l <= s && e <= r)
			return seg[no];
		
		return min(query(no << 1, s, (s + e) >> 1, l, r), query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r));
	}
}segt;

void dfs0(ll here, ll pa)
{
	spa[here][0] = pa;
	dep[here] = dep[pa] + 1;
	
	lf[here] = ++cc;
	ETT[cc] = here;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs0(i, here);
		
		cc++;
		ETT[cc] = here;
	}
	
	rg[here] = ++cc;
	ETT[cc] = here;
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

void dfs(ll here, ll pa)
{
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs(i, here);
	}
	
	sort(vv2[here].begin(), vv2[here].end());
	
	while((ll)vv2[here].size() > 2)
		vv2[here].pop_back();
	
	if((ll)vv2[here].size() == 2)
	{
		if(vv2[here][0].se != vv2[here][1].se)
		{
			ll maxx = vv2[here][1].fi;
			
			if(dep[here] - maxx > ans)
			{
				ans = dep[here] - maxx;
				ans2 = vv2[here][0].se - 1;
				ans3 = vv2[here][1].se - 1;
			}
		}
	}
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		for(auto &j : vv2[i])
		{
			for(auto &k : vv2[here])
			{
				if(j.se == k.se)
					continue;
				
				ll maxx = max(j.fi, k.fi);
				
				if(ans < dep[here] - maxx)
				{
					ans = dep[here] - maxx;
					ans2 = j.se - 1;
					ans3 = k.se - 1;
				}
			}
		}
		
		for(auto &j : vv2[i])
			vv2[here].push_back(j);
		
		sort(vv2[here].begin(), vv2[here].end());
		
		while((ll)vv2[here].size() > 2)
			vv2[here].pop_back();
	}
}

void ans1(void)
{
	for(ll i = 1 ; i <= K ; i++)
		tp[i] = LCA(s[i], e[i]);
	
	for(ll i = 1 ; i <= K ; i++)
	{
		vector<pll> vv;
		
		if(tp[i] == s[i] || tp[i] == e[i])
			vv.push_back({s[i], e[i]});
		
		else
		{
			//assert(0);
			vv.push_back({s[i], tp[i]});
			vv.push_back({e[i], tp[i]});
		}
		
		for(auto &j : vv)
		{
			if(dep[j.fi] < dep[j.se])
				swap(j.fi, j.se);
			
			vv2[j.fi].push_back({dep[j.se], i});
		}
	}
	
	dfs(1, 0);
}

ll RT;

void dfs3(ll here, ll pa)
{
	auto p = ST[here].begin();
	
	while(1)
	{
		if(p == ST[here].end())
			break;
		
		auto p2 = p;
		p2++;
		
		if(p2 == ST[here].end())
			break;
		
		ll gap = dep[here] - dep[RT];
		gap += segt.query(1, 1, cc, (*p), (*p2)) - dep[RT];
		
		if(gap > ans)
		{
			ans = gap;
			
			if((*p) == (*p2))
			{
				ans2 = MP[here][(*p)].fi - 1;
				ans3 = MP[here][(*p2)].se - 1;
			}
			
			else
			{
				ans2 = MP[here][(*p)].fi - 1;
				ans3 = MP[here][(*p2)].fi - 1;
			}
		}
		
		p++;
	}
	
	ll maxx = 0, w = -1;
	
	for(auto &i : vec3[here])
	{
		if(i == pa)
			continue;
		
		dfs3(i, here);
		
		if((ll)MP[BUN[i]].size() > maxx)
		{
			maxx = (ll)MP[BUN[i]].size();
			w = i;
		}
	}
	
	if(w == -1)
	{
		BUN[here] = here;
		return;
	}
	
	BUN[here] = BUN[w];
	
	for(auto &i : MP[here])
	{
		if(!i.se.fi)
			continue;
		
		if(MP[BUN[here]][i.fi].fi == 0)
			MP[BUN[here]][i.fi].fi = i.se.fi;
		else
			MP[BUN[here]][i.fi].se = i.se.fi;
		
		if(!i.se.se)
			continue;
		
		if(MP[BUN[here]][i.fi].fi == 0)
			MP[BUN[here]][i.fi].fi = i.se.se;
		else
			MP[BUN[here]][i.fi].se = i.se.se;
	}
	
	for(auto &i : ST[here])
	{
		ST[BUN[here]].insert(i);
		
		auto p = ST[BUN[here]].lower_bound(i);
		
		if(p != ST[BUN[here]].begin())
		{
			auto p2 = p;
			p2--;
			
			ll gap = dep[here] - dep[RT];
			gap += segt.query(1, 1, cc, (*p2), (*p)) - dep[RT];
			
			if(gap > ans)
			{
				ans = gap;
				
				if((*p) == (*p2))
				{
					ans2 = MP[BUN[here]][(*p2)].fi - 1;
					ans3 = MP[BUN[here]][(*p)].se - 1;
				}
				
				else
				{
					ans2 = MP[BUN[here]][(*p2)].fi - 1;
					ans3 = MP[BUN[here]][(*p)].fi - 1;
				}
			}
		}
		
		auto p2 = p;
		p2++;
		
		if(p2 != ST[BUN[here]].end())
		{
			ll gap = dep[here] - dep[RT];
			gap += segt.query(1, 1, cc, (*p), (*p2)) - dep[RT];
			
			if(gap > ans)
			{
				ans = gap;
				
				if((*p) == (*p2))
				{
					ans2 = MP[BUN[here]][(*p2)].fi - 1;
					ans3 = MP[BUN[here]][(*p)].se - 1;
				}
				
				else
				{
					ans2 = MP[BUN[here]][(*p2)].fi - 1;
					ans3 = MP[BUN[here]][(*p)].fi - 1;
				}
			}
		}
	}
	
	for(auto &j : vec3[here])
	{
		if(j == pa || j == w)
			continue;
		
		for(auto &i : MP[BUN[j]])
		{
			if(!i.se.fi)
				continue;
			
			if(MP[BUN[here]][i.fi].fi == 0)
				MP[BUN[here]][i.fi].fi = i.se.fi;
			else
				MP[BUN[here]][i.fi].se = i.se.fi;
			
			if(!i.se.se)
				continue;
			
			if(MP[BUN[here]][i.fi].fi == 0)
				MP[BUN[here]][i.fi].fi = i.se.se;
			else
				MP[BUN[here]][i.fi].se = i.se.se;
		}
		
		for(auto &i : ST[BUN[j]])
		{
			ST[BUN[here]].insert(i);
			
			auto p = ST[BUN[here]].lower_bound(i);
			
			if(p != ST[BUN[here]].begin())
			{
				auto p2 = p;
				p2--;
				
				ll gap = dep[here] - dep[RT];
				gap += segt.query(1, 1, cc, (*p2), (*p)) - dep[RT];
				
				if(gap > ans)
				{
					ans = gap;
					
					if((*p) == (*p2))
					{
						ans2 = MP[BUN[here]][(*p2)].fi - 1;
						ans3 = MP[BUN[here]][(*p)].se - 1;
					}
					
					else
					{
						ans2 = MP[BUN[here]][(*p2)].fi - 1;
						ans3 = MP[BUN[here]][(*p)].fi - 1;
					}
				}
			}
			
			if(p == ST[BUN[here]].end())
				continue;
			
			auto p2 = p;
			p2++;
			
			if(p2 != ST[BUN[here]].end())
			{
				ll gap = dep[here] - dep[RT];
				gap += segt.query(1, 1, cc, (*p), (*p2)) - dep[RT];
				
				if(gap > ans)
				{
					ans = gap;
					
					if((*p) == (*p2))
					{
						ans2 = MP[BUN[here]][(*p2)].fi - 1;
						ans3 = MP[BUN[here]][(*p)].se - 1;
					}
					
					else
					{
						ans2 = MP[BUN[here]][(*p2)].fi - 1;
						ans3 = MP[BUN[here]][(*p)].fi - 1;
					}
				}
			}
		}
	}
}

void ans22(void)
{
	for(ll i = 1 ; i <= cc ; i++)
		segt.update(1, 1, cc, i, dep[ETT[i]]);
	
	vector< pair<ll, pll> > vv;
	map< pair<ll, pll>, vector<ll> > mp;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(auto &j : vec[i])
		{
			if(j == spa[i][0])
				continue;
			
			LR[i].push_back({lf[j], rg[j]});
		}
		
		sort(LR[i].begin(), LR[i].end());
	}
	
	for(ll i = 1 ; i <= K ; i++)
	{
		if(tp[i] == s[i] || tp[i] == e[i])
			continue;
		
		pair<ll, pll> tmp;
		
		tmp = {tp[i], {0, 0}};
		
		ll l = 0, r = (ll)LR[tp[i]].size() - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) / 2;
			
			if(LR[tp[i]][mid].fi <= lf[s[i]])
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		tmp.se.fi = r;
		
		l = 0, r = (ll)LR[tp[i]].size() - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) / 2;
			
			if(LR[tp[i]][mid].fi <= lf[e[i]])
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		tmp.se.se = r;
		
		if(tmp.se.fi > tmp.se.se)
			swap(tmp.se.fi, tmp.se.se);
		
		mp[tmp].push_back(i);
	}
	
	for(auto &o : mp)
	{
		RT = o.fi.fi;
		vector<ll> vec2 = o.se;
		vector<pll> vtx;
		
		for(auto &i : vec2)
			vtx.push_back({lf[e[i]], e[i]});
		
		compress(vtx);
		
		ll siz = (ll)vtx.size();
		
		for(ll i = 1 ; i < siz ; i++)
		{
			ll lca = LCA(vtx[i - 1].se, vtx[i].se);
			vtx.push_back({lf[lca], lca});
		}
		
		vtx.push_back({lf[1], 1});
		
		compress(vtx);
		
		for(auto &i : vtx)
		{
			vec3[i.se].clear();
			ST[i.se].clear();
			MP[i.se].clear();
			BUN[i.se] = 0;
		}
		
		stack<ll> stk;
		ll mini = (1LL << 29), rtrt = 0;
		
		for(auto &i : vtx)
		{
			if(dep[i.se] < mini)
			{
				mini = dep[i.se];
				rtrt = i.se;
			}
			
			while(!stk.empty() && rg[i.se] > rg[stk.top()])
				stk.pop();
			
			if(!stk.empty())
			{
				vec3[stk.top()].push_back(i.se);
				vec3[i.se].push_back(stk.top());
			}
			
			stk.push(i.se);
		}
		
		if(rtrt == 0)
			continue;
		
		for(auto &i : vec2)
		{
			ST[e[i]].insert(lf[s[i]]);
			
			if(MP[e[i]][lf[s[i]]].fi == 0)
				MP[e[i]][lf[s[i]]].fi = i;
			else
				MP[e[i]][lf[s[i]]].se = i;
		}
		
		dfs3(rtrt, 0);
	}
}

vector<int> post(void)
{
	vector<int> ret;
	/*
	n = (ll)U.size() + 1;
	K = (ll)S.size();
	
	for(ll i = 0 ; i < n - 1 ; i++)
	{
		vec[U[i] + 1].push_back(V[i] + 1);
		vec[V[i] + 1].push_back(U[i] + 1);
	}
	
	for(ll i = 0 ; i < K ; i++)
	{
		s[i + 1] = S[i] + 1;
		e[i + 1] = E[i] + 1;
	}
	*/
	dfs0(1, 0);
	
	for(ll i = 1 ; i <= K ; i++)
	{
		if(lf[s[i]] > lf[e[i]])
			swap(s[i], e[i]);
	}
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	ans1();
	ans22();
	
	ret.push_back(ans);
	ret.push_back(ans2 + 1);
	ret.push_back(ans3 + 1);
	
	return ret;
}

ll tmtm;

int main()
{
	scanf("%d %d", &n, &K);
	
	for(ll i = 2 ; i <= n ; i++)
	{
		scanf("%d", &tmtm);
		
		vec[i].push_back(tmtm);
		vec[tmtm].push_back(i);
	}
	
	for(ll i = 1 ; i <= K ; i++)
		scanf("%d %d", &s[i], &e[i]);
	
	std::vector<int> ans = post();

	if (int(ans.size()) != 3) puts("INVALID ANSWER!!!");
	else printf("%d\n%d %d", ans[0], ans[1], ans[2]);

    return 0;
}