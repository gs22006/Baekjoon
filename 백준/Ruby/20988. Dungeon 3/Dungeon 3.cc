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
	ll S, T, U;
	ll num;
	
	bool operator < (const gujo &xx) const
	{
		return S > xx.S;
	}
};

ll n, m;
ll a[500010], b[500010];
gujo Q[500010];
ll X[500010];
ll L[500010], R[500010];
vector<ll> yL[500010];
vector<ll> zip;
ll siz;
ll ans[500010];

void getL(void)
{
	stack<pll> stk;
	stack<ll> nstk;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(!stk.empty() && stk.top().fi >= b[i])
		{
			stk.pop();
			nstk.pop();
		}
		
		if(stk.empty())
			L[i] = -INF;
		
		else
		{
			L[i] = stk.top().se;
			yL[nstk.top()].push_back(i);
		}
		
		stk.push({b[i], X[i]});
		nstk.push(i);
	}
}

void getR(void)
{
	stack<pll> stk;
	
	for(ll i = n ; i >= 1 ; i--)
	{
		while(!stk.empty() && stk.top().fi > b[i])
			stk.pop();
		
		if(stk.empty())
			R[i] = X[n + 1];
		else
			R[i] = stk.top().se;
		
		stk.push({b[i], X[i]});
	}
}

struct segtree
{
	ll seg[5000010];
	
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
		
		seg[no] = max(seg[no << 1], seg[no << 1 | 1]);
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return MIN;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return max(query(no << 1, s, (s + e) >> 1, l, r), query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r));
	}
}segt;

struct segtree2
{
	ll seg[5000010];
	
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
		
		if(b[seg[no << 1]] <= b[seg[no << 1 | 1]])
			seg[no] = seg[no << 1];
		else
			seg[no] = seg[no << 1 | 1];
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return MIN;
		
		if(l <= s && e <= r)
			return seg[no];
		
		ll gap1 = query(no << 1, s, (s + e) >> 1, l, r);
		ll gap2 = query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
		
		if(gap1 == MIN)
			return gap2;
		
		if(gap2 == MIN)
			return gap1;
		
		if(b[gap1] <= b[gap2])
			return gap1;
		
		return gap2;
	}
}segt2;

struct fenwicktree
{
	ll bit[5000010];
	
	void update(ll w, ll v)
	{
		for(ll i = w ; i <= siz ; i += (i & (-i)))
			bit[i] += v;
	}
	
	ll query(ll w)
	{
		ll ret = 0;
		
		for(ll i = w ; i > 0 ; i -= (i & (-i)))
			ret += bit[i];
		
		return ret;
	}
}ABIT, BBIT;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> b[i];
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> Q[i].S >> Q[i].T >> Q[i].U;
		Q[i].num = i;
	}
	
	X[1] = 0;
	
	for(ll i = 2 ; i <= n + 1 ; i++)
		X[i] = X[i - 1] + a[i - 1];
	
	getL();
	getR();
	
	zip.push_back(0);
	zip.push_back(INF);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(L[i] != -INF)
		{
			zip.push_back(X[i] - L[i]);
			zip.push_back(R[i] - L[i]);
		}
		
		zip.push_back(R[i] - X[i]);
	}
	
	compress(zip);
	siz = (ll)zip.size() + 2;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		segt.update(1, 1, n, i, a[i]);
		segt2.update(1, 1, n, i, i);
	}
	
	ll p = n;
	ll ccc = m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(segt.query(1, 1, n, Q[i].S, Q[i].T - 1) > Q[i].U)
			continue;
		
		ll l = Q[i].S, r = Q[i].T - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) / 2;
			
			if(X[mid] + Q[i].U < X[Q[i].T])
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		ccc++;
		
		ll qry = segt2.query(1, 1, n, l, Q[i].T - 1);

		ans[Q[i].num] += (X[Q[i].T] - X[qry]) * b[qry];
		Q[ccc].S = qry;
		Q[ccc].num = -Q[i].num;
		Q[ccc].U = Q[i].U;
	}
	
	sort(Q + 1, Q + 1 + ccc);
	
	for(ll i = 1 ; i <= ccc ; i++)
	{
		if(Q[i].num > 0 && segt.query(1, 1, n, Q[i].S, Q[i].T - 1) > Q[i].U)
		{
			ans[Q[i].num] = -1;
			continue;
		}

		while(p >= Q[i].S)
		{
			ll w = R[p] - X[p];
			ll idx = lower_bound(zip.begin(), zip.end(), w) - zip.begin() + 1;
			
			if(p)
			{
				ABIT.update(1, b[p]);
				ABIT.update(idx, -b[p]);
				BBIT.update(idx, b[p] * w);
			}
			
			for(auto &j : yL[p])
			{
				w = X[j] - L[j];
				idx = lower_bound(zip.begin(), zip.end(), w) - zip.begin() + 1;
				ll w2 = R[j] - L[j];
				ll idx2 = lower_bound(zip.begin(), zip.end(), w2) - zip.begin() + 1;
				ll w3 = R[j] - X[j];
				ll idx3 = lower_bound(zip.begin(), zip.end(), w3) - zip.begin() + 1;
				
				ABIT.update(1, -b[j]);
				ABIT.update(idx3, b[j]);
				BBIT.update(idx3, -b[j] * w3);
				
				if(w < w3)
				{
					ABIT.update(1, b[j]);
					ABIT.update(idx, -b[j]);
					BBIT.update(idx, b[j] * w);
					BBIT.update(idx3, -b[j] * w);
					ABIT.update(idx3, -b[j]);
					BBIT.update(idx3, b[j] * w2);
					ABIT.update(idx2, b[j]);
					BBIT.update(idx2, -b[j] * w2);
				}
				
				else
				{
					ABIT.update(1, b[j]);
					ABIT.update(idx3, -b[j]);
					BBIT.update(idx3, b[j] * w3);
					BBIT.update(idx, -b[j] * w3);
					ABIT.update(idx, -b[j]);
					BBIT.update(idx, b[j] * w2);
					ABIT.update(idx2, b[j]);
					BBIT.update(idx2, -b[j] * w2);
				}
			}
			
			p--;
		}
		
		ll idx = lower_bound(zip.begin(), zip.end(), Q[i].U) - zip.begin();
		ll A = ABIT.query(idx);
		ll B = BBIT.query(idx);
		
		if(Q[i].num > 0)
			ans[Q[i].num] += A * Q[i].U + B;
		else
			ans[-Q[i].num] += -A * Q[i].U - B;
	}
	
	for(ll i = 1 ; i <= m ; i++)
		cout << ans[i] en;
	
	return 0;
}
