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
ll m;
ll q;
pll a[200010];
ll L, R;
pll b[200010];
ll Lspa[200010][21];
ll Rspa[200010][21];

struct segtree
{
	pll seg[1000010][2];
	pll lazy[1000010][2];
	
	void init(ll no, ll s, ll e)
	{
		lazy[no][0] = {-INF, 0};
		lazy[no][1] = {INF, 0};
		seg[no][0] = {-INF, 0};
		seg[no][1] = {INF, 0};

		if(s == e)
			return;
		
		init(no << 1, s, (s + e) >> 1);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e);
	}
	
	void prop(ll no, ll s, ll e)
	{
		if(seg[no][0].fi < lazy[no][0].fi)
			seg[no][0] = lazy[no][0];
		
		if(s != e)
		{
			if(lazy[no << 1][0].fi < lazy[no][0].fi)
				lazy[no << 1][0] = lazy[no][0];
			
			if(lazy[no << 1 | 1][0].fi < lazy[no][0].fi)
				lazy[no << 1 | 1][0] = lazy[no][0];
		}
		
		lazy[no][0] = {-INF, 0};

		if(seg[no][1].fi > lazy[no][1].fi)
			seg[no][1] = lazy[no][1];
		
		if(s != e)
		{
			if(lazy[no << 1][1].fi > lazy[no][1].fi)
				lazy[no << 1][1] = lazy[no][1];
			
			if(lazy[no << 1 | 1][1].fi > lazy[no][1].fi)
				lazy[no << 1 | 1][1] = lazy[no][1];
		}
		
		lazy[no][1] = {INF, 0};
	}
	
	void update(ll no, ll s, ll e, ll l, ll r, ll v1, ll v2)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			if(seg[no][0].fi < v1)
				seg[no][0] = {v1, v2};

			if(seg[no][1].fi > v1)
				seg[no][1] = {v1, v2};

			if(s != e)
			{
				if(lazy[no << 1][0].fi < v1)
					lazy[no << 1][0] = {v1, v2};

				if(lazy[no << 1][1].fi > v1)
					lazy[no << 1][1] = {v1, v2};
				
				if(lazy[no << 1 | 1][0].fi < v1)
					lazy[no << 1 | 1][0] = {v1, v2};

				if(lazy[no << 1 | 1][1].fi > v1)
					lazy[no << 1 | 1][1] = {v1, v2};
			}

			return;
		}
		
		update(no << 1, s, (s + e) >> 1, l, r, v1, v2);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, v1, v2);
		
		if(seg[no << 1][0].fi < seg[no << 1 | 1][0].fi)
			seg[no][0] = seg[no << 1 | 1][0];
		else
			seg[no][0] = seg[no << 1][0];
		
		if(seg[no << 1][1].fi > seg[no << 1 | 1][1].fi)
			seg[no][1] = seg[no << 1 | 1][1];
		else
			seg[no][1] = seg[no << 1][1];
	}
	
	pair<pll, pll> query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return {{-INF, 0}, {INF, 0}};
		
		if(l <= s && e <= r)
			return {seg[no][0], seg[no][1]};
		
		pair<pll, pll> LL = query(no << 1, s, (s + e) >> 1, l, r);
		pair<pll, pll> RR = query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
		pair<pll, pll> ret;
		
		if(LL.fi.fi > RR.fi.fi)
			ret.fi = LL.fi;
		else
			ret.fi = RR.fi;
		
		if(LL.se.fi < RR.se.fi)
			ret.se = LL.se;
		else
			ret.se = RR.se;

		return ret;
	}
}segt, segt2;

void RR(void)
{
	ll cc = 0;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(a[i].fi < a[i].se)
			b[cc++] = {a[i].fi, i};
	}
	
	sort(b, b + cc);
	
	if(!cc)
		return;
	
	segt.init(1, 1, n);
	
	ll num = b[cc - 1].se;
	
	segt.update(1, 1, n, a[num].fi, min(a[num].se, a[num].fi + K - 1), a[num].se, num);
	
	for(ll i = cc - 2 ; i >= 0 ; i--)
	{
		num = b[i].se;
		
		pair<pll, pll> qry = segt.query(1, 1, n, a[num].fi, a[num].se);

		if(qry.fi.se && a[num].se < qry.fi.fi)
			Rspa[num][0] = qry.fi.se;
		
		segt.update(1, 1, n, a[num].fi, min(a[num].se, a[num].fi + K - 1), a[num].se, num);
	}
}

void LL(void)
{
	ll cc = 0;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(a[i].fi > a[i].se)
			b[cc++] = {a[i].fi, i};
	}
	
	sort(b, b + cc);
	reverse(b, b + cc);
	
	if(!cc)
		return;
	
	segt2.init(1, 1, n);
	
	ll num = b[cc - 1].se;
	
	segt2.update(1, 1, n, max(a[num].fi - K + 1, a[num].se), a[num].fi, a[num].se, num);
	
	for(ll i = cc - 2 ; i >= 0 ; i--)
	{
		num = b[i].se;

		pair<pll, pll> qry = segt2.query(1, 1, n, a[num].se, a[num].fi);

		if(qry.se.se && a[num].se > qry.se.fi)
			Lspa[num][0] = qry.se.se;

		segt2.update(1, 1, n, max(a[num].fi - K + 1, a[num].se), a[num].fi, a[num].se, num);
	}
}

void RL(void)
{
	ll cc = 0;
	vector<pll> vv;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(a[i].fi < a[i].se)
			b[cc++] = {min(a[i].fi + K - 1, a[i].se), i};
		else
			vv.push_back({a[i].fi, i});
	}

	sort(b, b + cc);
	reverse(b, b + cc);
	sort(vv.begin(), vv.end());
	reverse(vv.begin(), vv.end());
	segt.init(1, 1, n);

	ll p = 0;

	for(ll i = 0 ; i < cc ; i++)
	{
		ll num = b[i].se;

		while(p < (ll)vv.size() && vv[p].fi >= min(a[num].fi + K - 1, a[num].se))
		{
			ll num2 = vv[p].se;

			segt.update(1, 1, n, max(a[num2].se, a[num2].fi - K + 1), a[num2].fi, a[num2].se, num2);
			p++;
		}

		pair<pll, pll> qry = segt.query(1, 1, n, a[num].fi, a[num].se);
		
		if(qry.se.se) //hmm...?
			Lspa[num][0] = qry.se.se;
	}
}

void LR(void)
{
	ll cc = 0;
	vector<pll> vv;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(a[i].fi > a[i].se)
			b[cc++] = {max(a[i].se, a[i].fi - K + 1), i};
		else
			vv.push_back({a[i].fi, i});
	}

	sort(b, b + cc);
	sort(vv.begin(), vv.end());
	segt.init(1, 1, n);

	ll p = 0;

	for(ll i = 0 ; i < cc ; i++)
	{
		ll num = b[i].se;

		while(p < (ll)vv.size() && vv[p].fi <= max(a[num].se, a[num].fi - K + 1))
		{
			ll num2 = vv[p].se;
			
			segt.update(1, 1, n, a[num2].fi, min(a[num2].se, a[num2].fi + K - 1), a[num2].se, num2);
			p++;
		}

		pair<pll, pll> qry = segt.query(1, 1, n, a[num].se, a[num].fi);
		
		if(qry.fi.se) //hmm...?
			Rspa[num][0] = qry.fi.se;
	}
}

int main(void)
{
	fastio
	
	cin >> n >> K;
	cin >> m;
	
	for(ll i = 1 ; i <= m ; i++)
		cin >> a[i].fi >> a[i].se;
	
	LR();
	RL();
	LL();
	RR();

	for(ll i = 1 ; i <= m ; i++)
	{
		if(!Lspa[i][0])
			Lspa[i][0] = i;

		if(!Rspa[i][0])
			Rspa[i][0] = i;
	}

	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			if(a[Lspa[Lspa[j][i - 1]][i - 1]].se < a[Lspa[Rspa[j][i - 1]][i - 1]].se)
				Lspa[j][i] = Lspa[Lspa[j][i - 1]][i - 1];
			else
				Lspa[j][i] = Lspa[Rspa[j][i - 1]][i - 1];

			if(a[Rspa[Lspa[j][i - 1]][i - 1]].se > a[Rspa[Rspa[j][i - 1]][i - 1]].se)
				Rspa[j][i] = Rspa[Lspa[j][i - 1]][i - 1];
			else
				Rspa[j][i] = Rspa[Rspa[j][i - 1]][i - 1];
		}
	}

	cin >> q;

	while(q--)
	{
		cin >> L >> R;

		pair<pll, pll> num = segt.query(1, 1, n, L, L);
		pair<pll, pll> num2 = segt2.query(1, 1, n, L, L);

		if(L < R)
		{
			if(R <= num.fi.fi)
			{
				cout << 1 en;
				continue;
			}
		}

		else
		{
			if(R >= num2.se.fi)
			{
				cout << 1 en;
				continue;
			}
		}

		ll ans = 1;
		ll nR = num.fi.se;
		ll nL = num2.se.se;

		if(!nL && !nR)
		{
			cout << -1 en;
			continue;
		}

		for(ll i = 20 ; i >= 0 ; i--)
		{
			ll LL = INF, nxtL = 0;
			ll RR = -INF, nxtR = 0;

			if(nL)
			{
				if(LL > a[Lspa[nL][i]].se)
				{
					LL = a[Lspa[nL][i]].se;
					nxtL = Lspa[nL][i];
				}

				if(RR < a[Rspa[nL][i]].se)
				{
					RR = a[Rspa[nL][i]].se;
					nxtR = Rspa[nL][i];
				}
			}
			
			if(nR)
			{
				if(LL > a[Lspa[nR][i]].se)
				{
					LL = a[Lspa[nR][i]].se;
					nxtL = Lspa[nR][i];
				}

				if(RR < a[Rspa[nR][i]].se)
				{
					RR = a[Rspa[nR][i]].se;
					nxtR = Rspa[nR][i];
				}
			}

			if(L <= R && R <= RR)
				continue;

			if(R <= L && LL <= R)
				continue;

			ans += (1LL << i);
			nL = nxtL;
			nR = nxtR;
		}

		ll ff = 0;

		for(ll i = 0 ; i >= 0 ; i--)
		{
			ll LL = INF;
			ll RR = -INF;

			if(nL)
			{
				if(LL > a[Lspa[nL][i]].se)
					LL = a[Lspa[nL][i]].se;

				if(RR < a[Rspa[nL][i]].se)
					RR = a[Rspa[nL][i]].se;
			}
			
			if(nR)
			{
				if(LL > a[Lspa[nR][i]].se)
					LL = a[Lspa[nR][i]].se;

				if(RR < a[Rspa[nR][i]].se)
					RR = a[Rspa[nR][i]].se;
			}

			if(L <= R && R <= RR)
				ff = 1;

			if(R <= L && LL <= R)
				ff = 1;
		}

		if(!ff)
			cout << -1 en;
		else
			cout << ans + 1 en;
	}

	return 0;
}