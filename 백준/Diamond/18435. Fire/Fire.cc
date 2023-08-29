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
	ll T, L, R, num;
	
	bool operator < (const gujo &xx) const
	{
		return T < xx.T;
	}
};

struct gujo2
{
	ll T, gap, typ, X;
	
	bool operator < (const gujo2 &xx) const
	{
		return T < xx.T;
	}
};

ll n, q;
ll a[200010];
gujo Q[200010];
ll Lidx[200010], Ridx[200010];
ll h[200010], w[200010];
vector<gujo2> vec2;
ll ans[200010];

struct lazysegtree
{
	ll seg[4000010];
	ll lazy[4000010];
	
	void prop(ll no, ll s, ll e)
	{
		if(lazy[no])
		{
			seg[no] += lazy[no] * (e - s + 1);
			
			if(s != e)
			{
				lazy[no << 1] += lazy[no];
				lazy[no << 1 | 1] += lazy[no];
			}
			
			lazy[no] = 0;
		}
	}
	
	void update(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			seg[no] += v * (e - s + 1);
			
			if(s != e)
			{
				lazy[no << 1] += v;
				lazy[no << 1 | 1] += v;
			}
			
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, l, r, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, v);
		
		seg[no] = seg[no << 1] + seg[no << 1 | 1];
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return query(no << 1, s, (s + e) >> 1, l, r) + query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
	}
}segt1, segt2;

void LR(void)
{
	stack<ll> stk;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(!stk.empty() && a[stk.top()] <= a[i])
			stk.pop();
		
		if(!stk.empty())
			Lidx[i] = stk.top();
		
		stk.push(i);
	}
	
	while(!stk.empty())
		stk.pop();
	
	for(ll i = n ; i >= 1 ; i--)
	{
		while(!stk.empty() && a[stk.top()] < a[i])
			stk.pop();
		
		if(!stk.empty())
			Ridx[i] = stk.top();
		
		stk.push(i);
	}
}

void diag(ll X, ll S, ll E, ll gp)
{
	vec2.push_back({S, X, 1, gp});
	vec2.push_back({E + 1, X, -1, -gp});
}

void rect(ll X, ll S, ll E, ll gp)
{
	vec2.push_back({S, X, 2, gp});
	vec2.push_back({E + 1, X, -2, -gp});
}

void tri(ll idx, ll len, ll S, ll E, ll gp)
{
	diag(S - idx, S, E, gp);
	rect(idx + len, S, E, -gp);
}

int main(void)
{
	fastio
	
	cin >> n >> q;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= q ; i++)
	{
		cin >> Q[i].T >> Q[i].L >> Q[i].R;
		Q[i].num = i;
	}
	
	sort(Q + 1, Q + 1 + q);
	
	LR();
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!Lidx[i])
			h[i] = n + 1;
		else
			h[i] = i - Lidx[i];
		
		if(!Ridx[i])
			w[i] = n - i + 1;
		else
			w[i] = Ridx[i] - i;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		tri(i - h[i] + 1, h[i] + w[i] - 1, 0, h[i] + w[i] - 2, a[i]);
		tri(i - h[i] + 1, h[i] - 1, 0, h[i] - 2, -a[i]);
		tri(i + 1, w[i] - 1, 0, w[i] - 2, -a[i]);
	}
	
	sort(vec2.begin(), vec2.end());
	
	ll p = 0;
	
	for(ll i = 1 ; i <= q ; i++)
	{
		while(p < (ll)vec2.size() && vec2[p].T <= Q[i].T)
		{
			if(abs(vec2[p].typ) == 1)
				segt1.update(1, 0, 3 * n, 0, vec2[p].gap + n, vec2[p].X);
			else
				segt2.update(1, 0, n, vec2[p].gap, n, vec2[p].X);
			
			p++;
		}
		
		ans[Q[i].num] = segt1.query(1, 0, 3 * n, Q[i].T - Q[i].R + n, Q[i].T - Q[i].L + n);
		ans[Q[i].num] += segt2.query(1, 0, n, Q[i].L, Q[i].R);
	}
	
	for(ll i = 1 ; i <= q ; i++)
		cout << ans[i] en;
	
	return 0;
}