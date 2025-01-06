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

ll n, m, q;
vector<pll> vec[1000010];
ll N, NN;
ll all, bll, cll;
ll V[1000010], D[1000010];
pll Q[1000010];
pair<pll, pll> edg[1000010];

void input(void)
{
	cin >> n >> m >> q;
	
	N = n;
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll >> cll;
		
		vec[all].push_back({bll, i});
		vec[bll].push_back({all, i});
		edg[i] = {{all, bll}, {N + 1, N + cll}};
		N += cll;
	}
	
	NN = N;
	
	for(ll i = 1 ; i <= m ; i++)
		cin >> V[i] >> D[i];
	
	for(ll i = 1 ; i <= q ; i++)
		cin >> Q[i].fi >> Q[i].se;
}

pair<pll, ll> Enum[1000010];
ll now;
ll dep[1000010], spa[1000010][21], Pedg[1000010], nspa[1000010][21], Vdep[1000010];
vector< pair<pll, pll> > Einfo, Einfo2;

void dfs0(ll here, ll pa)
{
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		ll gaet = edg[i.se].se.se - edg[i.se].se.fi + 1;
		ll dir = 0;
		
		if(edg[i.se].fi.fi == here)
			dir = 1;
		else
			dir = -1;
		
		Enum[i.se] = {{now + 1, now + gaet * 2 + 1}, dir};
		now += gaet * 2 + 1;
		
		dfs0(i.fi, here);
	}
}

void give_number(void)
{
	now = n;
	
	dfs0(1, 0);
	
	vector< pair<pll, ll> > help;
	
	for(ll i = 1 ; i < n ; i++)
		help.push_back({{edg[i].se.fi, edg[i].se.se}, i});
	
	sort(help.begin(), help.end());
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(V[i] > n)
		{
			//cout << V[i] sp << "->";
			ll l = 0, r = (ll)help.size() - 1;
			
			while(l <= r)
			{
				ll mid = (l + r) >> 1;
				
				if(help[mid].fi.fi <= V[i])
					l = mid + 1;
				else
					r = mid - 1;
			}
			
			ll num = help[r].se;
			
			if(Enum[num].se == -1)
				V[i] = help[r].fi.fi + help[r].fi.se - V[i];
			
			V[i] = V[i] - help[r].fi.fi + 1;
			V[i] = Enum[num].fi.fi + V[i] * 2 - 1;
			//cout << V[i] en;
		}
		
		D[i] *= 2;
	}
}

void dfs1(ll here, ll pa)
{
	spa[here][0] = pa;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		nspa[i.fi][0] = Enum[i.se].fi.se - Enum[i.se].fi.fi + 2;
		Pedg[i.fi] = i.se;
		Vdep[i.fi] = Vdep[here] + 1;
		dep[i.fi] = dep[here] + 2 + Enum[i.se].fi.se - Enum[i.se].fi.fi;
		dfs1(i.fi, here);
	}
}

ll find_edge(ll X)
{
	ll l = 0, r = (ll)Einfo.size() - 1;
	
	while(l <= r)
	{
		ll mid = (l + r) >> 1;
		
		if(Einfo[mid].fi.fi <= X)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	return r;
}

ll get_depth(ll X)
{
	if(1 <= X && X <= n)
		return dep[X];
	
	ll r = find_edge(X);
	
	return dep[Einfo[r].se.fi] + X - Einfo[r].fi.fi + 1;
}

ll to_edge_top(ll X)
{
	if(X <= n)
		return X;
	
	ll numm = find_edge(X);
	
	return Einfo[numm].se.fi;
}

ll lift(ll X, ll Y)
{
	ll numm;
	
	if(X > n)
	{
		numm = find_edge(X);
		
		if(X - Einfo[numm].fi.fi + 1 <= Y)
		{
			Y -= (X - Einfo[numm].fi.fi + 1);
			X = Einfo[numm].se.fi;
		}
		
		else
			return X - Y;
	}
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if(nspa[X][i] <= Y)
		{
			Y -= nspa[X][i];
			X = spa[X][i];
		}
	}
	
	numm = Pedg[X] - 1;
	
	if(!Y)
		return X;
	
	Y--;
	X = Einfo2[numm].fi.se;
	X -= Y;
	
	return X;
}

ll LCA2(ll X, ll Y)
{
	if(Vdep[X] < Vdep[Y])
		swap(X, Y);
	
	ll cha = Vdep[X] - Vdep[Y];
	
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

ll LCA(ll X, ll Y)
{
	//cout << "LCA!!\n";
	ll depX = get_depth(X), depY = get_depth(Y);
	
	if(depX < depY)
	{
		swap(X, Y);
		swap(depX, depY);
	}
	//cout << X sp << Y sp << depX sp << depY en;
	ll cha = depX - depY;
	
	X = lift(X, cha);
	//cout << "lifted: " << X en;
	if(X == Y)
		return X;
	
	X = to_edge_top(X);
	Y = to_edge_top(Y);
	
	if(X == Y)
		return X;
	
	return LCA2(X, Y);
}

ll dist(ll X, ll Y)
{
	if(X == 0 || Y == 0)
	{
		while(1)
			cout <<  "NONO\n";
	}
	return get_depth(X) + get_depth(Y) - 2 * get_depth(LCA(X, Y));
}

ll moveK(ll X, ll Y, ll K)
{
	ll LC = LCA(X, Y);
	ll depX = get_depth(X);
	ll depY = get_depth(Y);
	ll depL = get_depth(LC);
	ll T, V;
	
	if(K <= depX - depL)
	{
		T = K;
		V = X;
	}
	
	else
	{
		K -= depX - depL;
		T = depY - depL - K;
		V = Y;
	}
	
	return lift(V, T);
}

pll merge(pll X, pll Y)
{
	if(X.se < Y.se)
		swap(X, Y);
	
	if(Y.se == -1)
		return Y;
	
	ll D = dist(X.fi, Y.fi);
	//cout << "D: " << X.fi sp << Y.fi sp << D en;
	if(X.se + Y.se < D)
		return {1, -1};
	
	if(X.se >= Y.se + D)
		return Y;
	
	ll ret1 = moveK(X.fi, Y.fi, (D + X.se - Y.se) / 2);
	ll ret2 = (X.se + Y.se - D) / 2;
	
	return {ret1, ret2};
}

struct segtree
{
	pll seg[4000010];
	
	void init(void)
	{
		for(ll i = 0 ; i < 4000010 ; i++)
			seg[i] = {1, INF / 2};
	}
	
	void update(ll no, ll s, ll e, ll w, pll v)
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
		
		seg[no] = merge(seg[no << 1], seg[no << 1 | 1]);
	}
	
	pll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return {1, INF / 2};
		
		if(l <= s && e <= r)
			return seg[no];
		
		return merge(query(no << 1, s, (s + e) >> 1, l, r), query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r));
	}
	/*
	void print(ll no, ll s, ll e)
	{
		cout << "*********" << s << "~" << e en;
		cout << seg[no].fi sp << seg[no].se en;
		
		if(s == e)
			return;
		
		print(no << 1, s, (s + e) >> 1);
		print(no << 1 | 1, ((s + e) >> 1) + 1, e);
	}*/
}segt;

vector<ll> Vqry[1000010], Eqry[1000010];
ll R[1000010], sub[1000010];
vector<ll> vQ, eQ, VV, EE;
ll ans[1000010];
ll Ndep[1000010], rev[1000010];

void dfs(ll here, ll pa)
{
	sub[here] = 1;
	VV.push_back(here);
	
	for(auto &i : Vqry[here])
		vQ.push_back(i);
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa || R[i.fi])
			continue;
		
		for(auto &j : Eqry[i.se])
			eQ.push_back(j);
		
		EE.push_back(i.se);
		dfs(i.fi, here);
		sub[here] += sub[i.fi];
	}
}

ll get_centroid(ll here, ll pa, ll SIZ)
{
	for(auto &i : vec[here])
	{
		if(i.fi == pa || R[i.fi])
			continue;
		
		if(sub[i.fi] * 2 > SIZ)
			return get_centroid(i.fi, here, SIZ);
	}
	
	return here;
}

vector<pll> EDG;

void dfs2(ll here, ll pa)
{
	//cout << "NDEP: " << here sp << Ndep[here] en;
	for(auto &i : vec[here])
	{
		if(i.fi == pa || R[i.fi])
			continue;
		
		Ndep[i.fi] = Ndep[here] + Einfo2[i.se - 1].fi.se - Einfo2[i.se - 1].fi.fi + 2;
		EDG.push_back({Ndep[here] + 1, Ndep[i.fi]});
		
		if(Einfo2[i.se - 1].se.fi == i.fi)
			rev[i.se] = 1;
		
		dfs2(i.fi, here);
	}
}

ll get_new_depth(ll X)
{
	if(1 <= X && X <= n)
		return Ndep[X];
	
	ll r = find_edge(X);
	ll num = Pedg[Einfo[r].se.se];
	ll ret = 0;
	//cout << "GND: " << X sp << Einfo[r].fi.fi sp << Einfo[r].fi.se en;
	if(!rev[num])
		ret += Ndep[Einfo[r].se.fi] + X - Einfo[r].fi.fi + 1;
	else
		ret += Ndep[Einfo[r].se.se] + Einfo[r].fi.se - X + 1;
	
	return ret;
}

void dfs3(ll here, ll pa)
{
	for(auto &i : Vqry[here])
		vQ.push_back(i);
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa || R[i.fi])
			continue;
		
		for(auto &j : Eqry[i.se])
			eQ.push_back(j);
		
		EDG.push_back({Ndep[here] + 1, Ndep[i.fi]});
		dfs3(i.fi, here);
	}
}

void f(ll here)
{
	vQ.clear();
	eQ.clear();
	VV.clear();
	EE.clear();
	
	dfs(here, 0);
	
	ll cent = get_centroid(here, 0, sub[here]);
	vector<ll> vq, eq, vv, ee;
	vector<pll> qry;
	//cout << "******************" << here sp << cent en;
	vq = vQ;
	eq = eQ;
	vv = VV;
	ee = EE;
	
	for(auto &i : vv)
		Ndep[i] = 0;
	
	for(auto &i : ee)
		rev[i] = 0;
	
	EDG.clear();
	
	dfs2(cent, 0);
	
	for(auto &i : vq)
	{
		ll DEP = get_new_depth(Q[i].fi);
		
		if(DEP > Q[i].se)
			continue;
		
		qry.push_back({Q[i].se - DEP, i});
	}
	
	for(auto &i : eq)
	{
		ll DEP = get_new_depth(Q[i].fi);
		//cout << "hmm?: " << Q[i].fi sp << DEP en;
		if(DEP > Q[i].se)
			continue;
		
		qry.push_back({Q[i].se - DEP, i});
	}
	
	vector< pair<ll, pll> > tmp;
	
	for(auto &i : qry)
	{
		tmp.push_back({i.fi, {3, i.se}});
		//cout << "qry!: " << i.fi sp << i.se en;
	}
	
	for(auto &i : EDG)
	{
		tmp.push_back({i.fi, {1, i.fi}});
		tmp.push_back({i.se + 1, {2, i.fi}});
	}
	
	sort(tmp.begin(), tmp.end());
	
	ll gaet = 0, sum = 0, lo = 1;
	
	for(auto &i : tmp)
	{
		if(i.se.fi == 1)
		{
			gaet++;
			sum += i.fi;
		}
		
		else if(i.se.fi == 2)
		{
			gaet--;
			sum -= i.se.se;
			lo += (i.fi - i.se.se) / 2;
		}
		
		else
		{
			if(i.fi & 1)
				ans[i.se.se] += lo + (i.fi * gaet - sum) / 2;
			else
				ans[i.se.se] += lo + (i.fi * gaet - sum + gaet) / 2;
		}
	}
	//cout << here sp << ans[1] en;
	for(auto &nxt : vec[cent])
	{
		if(R[nxt.fi])
			continue;
		//cout << "CONFUSED: " << nxt.fi en;
		vector< pair<pll, ll> > qry2;
		ll LEN = Einfo2[nxt.se - 1].fi.se - Einfo2[nxt.se - 1].fi.fi + 2;
		ll VDEP = get_new_depth(nxt.fi);
		
		for(auto &i : Eqry[nxt.se])
		{
			ll DEP = get_new_depth(Q[i].fi);
			
			if(DEP <= Q[i].se)
			{
				ll RNG = Q[i].se - DEP;
				
				if(RNG <= LEN - 1)
					ans[i] -= RNG / 2;
				
				else
				{
					ans[i] -= (LEN - 1) / 2;
					qry2.push_back({{RNG - LEN, i}, -1});
				}
			}
			
			if(VDEP - DEP <= Q[i].se)
				qry2.push_back({{Q[i].se - VDEP + DEP, i}, 1});
			
			if(!(DEP & 1))
			{
				ans[i]++;
				ans[i] += min(Q[i].se, DEP - 1) / 2;
				ans[i] += min(Q[i].se, VDEP - DEP - 1) / 2;
			}
			
			else
			{
				ans[i] += min(Q[i].se + 1, DEP - 1) / 2;
				ans[i] += min(Q[i].se + 1, VDEP - DEP - 1) / 2;
			}
		}
		//cout << "After Eqry: " << ans[1] en;
		vQ.clear();
		eQ.clear();
		EDG.clear();
		
		dfs3(nxt.fi, cent);
		
		//cout << "EDG\n";
		
		//for(auto &i : EDG)
		//	cout << i.fi sp << i.se en;
		
		for(auto &i : vQ)
		{
			ll DEP = get_new_depth(Q[i].fi);
			
			if(DEP <= Q[i].se)
			{
				ll RNG = Q[i].se - DEP;
				
				if(RNG <= LEN - 1)
					ans[i] -= RNG / 2;
				
				else
				{
					ans[i] -= (LEN - 1) / 2;
					qry2.push_back({{RNG - LEN, i}, -1});
				}
			}
			
			ll NAM = Q[i].se - (DEP - VDEP);
			
			if(NAM >= 0)
				ans[i] += min(LEN - 1, NAM) / 2;
		}
		//cout << "After vQ: " << ans[1] en;
		
		for(auto &i : eQ)
		{
			ll DEP = get_new_depth(Q[i].fi);
			//cout << "Eq: " << Q[i].fi sp << Q[i].se sp << DEP en;
			if(DEP <= Q[i].se)
			{
				ll RNG = Q[i].se - DEP;
				
				if(RNG <= LEN - 1)
					ans[i] -= RNG / 2;
				
				else
				{
					ans[i] -= (LEN - 1) / 2;
					qry2.push_back({{RNG - LEN, i}, -1});
					//cout << "in qry2: " << RNG - LEN sp << -1 en;
				}
			}
			
			ll NAM = Q[i].se - (DEP - VDEP);
			
			if(NAM >= 0)
				ans[i] += min(LEN - 1, NAM) / 2;
		}
		
		//cout << "After eQ: " << ans[1] en;
		vector< pair<pll, pll> > tmp2;
		
		for(auto &i : qry2)
		{
			tmp2.push_back({{i.fi.fi, 3}, {i.fi.se, i.se}});
		//	cout << "qry2: " << i.fi.fi sp << i.fi.se sp << i.se en;
		}
		
		for(auto &i : EDG)
		{
			tmp2.push_back({{i.fi - Ndep[nxt.fi], 1}, {1, i.fi - Ndep[nxt.fi]}});
			tmp2.push_back({{i.se - Ndep[nxt.fi] + 1, 2}, {2, i.fi - Ndep[nxt.fi]}});
		}
		
		sort(tmp2.begin(), tmp2.end());
		
		gaet = 0, sum = 0, lo = 1;
		
		for(auto &i : tmp2)
		{
		//	cout << "NOW: " << i.fi.fi sp << i.fi.se sp << i.se.fi sp << i.se.se en;
			if(i.fi.se == 1)
			{
				gaet++;
				sum += i.fi.fi;
			}
			
			else if(i.fi.se == 2)
			{
				gaet--;
				sum -= i.se.se;
				lo += (i.fi.fi - i.se.se) / 2;
			}
			
			else
			{
				if(i.fi.fi & 1)
					ans[i.se.fi] += (lo + (i.fi.fi * gaet - sum) / 2) * i.se.se;
				else
					ans[i.se.fi] += (lo + (i.fi.fi * gaet - sum + gaet) / 2) * i.se.se;
			}
			
			//cout << ans[1] en;
		}
		
		//cout << ans[1] en;
	}
	//cout << here sp << ans[1] en;
	R[cent] = 1;
	
	for(auto &i : vec[cent])
	{
		if(R[i.fi])
			continue;
		
		f(i.fi);
	}
}

void solve(void)
{
	dfs1(1, 0);
	spa[1][0] = 1;
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
			nspa[j][i] = nspa[j][i - 1] + nspa[spa[j][i - 1]][i - 1];
		}
	}
	
	for(ll i = 1 ; i < n ; i++)
	{
		if(spa[edg[i].fi.fi][0] == edg[i].fi.se)
			Einfo.push_back({Enum[i].fi, {edg[i].fi.se, edg[i].fi.fi}});
		else
			Einfo.push_back({Enum[i].fi, {edg[i].fi.fi, edg[i].fi.se}});
	}
	
	Einfo2 = Einfo;
	sort(Einfo.begin(), Einfo.end());
	
	segt.init();
	
	for(ll i = 1 ; i <= m ; i++)
		segt.update(1, 1, m, i, {V[i], D[i]});
	
	//pll GG = merge({5, 10}, {1, 10});
	//cout << "GGG: " << GG.fi sp << GG.se en;
	//segt.print(1, 1, m);
	
	for(ll i = 1 ; i <= q ; i++)
	{
		pll gap = segt.query(1, 1, m, Q[i].fi, Q[i].se);
		Q[i] = gap;
		//cout << "THISISQUERY: " << Q[i].fi sp << Q[i].se en;
		
		if(Q[i].se == -1)
			continue;
		
		if(Q[i].fi <= n)
			Vqry[Q[i].fi].push_back(i);
		else
			Eqry[Pedg[Einfo[find_edge(Q[i].fi)].se.se]].push_back(i);
	}
	
	f(1);
	
	for(ll i = 1 ; i <= q ; i++)
		cout << ans[i] en;
}

int main(void)
{
	fastio
	
	input();
	give_number();
	solve();
	
	return 0;
}