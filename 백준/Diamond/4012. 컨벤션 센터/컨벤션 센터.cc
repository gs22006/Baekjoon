#include <bits/stdc++.h>
 
using namespace std;
typedef int ll;
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
	ll S, E;
	ll num;
	
	bool operator < (const gujo &xx) const
	{
		return E < xx.E;
	}
};

ll n;
gujo a[200010], b[200010];
vector<ll> zip;
ll spa[200010][21];
queue<pll> q;
pll minn[400010];
set<ll> st;
ll idx[400010];
vector<ll> ans;

ll f(ll S, ll E)
{
	ll w = minn[S].se;
	
	if(b[w].E > E || w == -1)
		return 0;
	
	ll ret = 1;
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		ll nxt = spa[w][i];
		
		if(!nxt)
			continue;
		
		if(b[nxt].E <= E)
		{
			ret += (1LL << i);
			w = nxt;
		}
	}
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].S >> a[i].E;
		
		a[i].num = i;
		zip.push_back(a[i].S);
		zip.push_back(a[i].E);
	}
	
	compress(zip);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		a[i].S = lower_bound(zip.begin(), zip.end(), a[i].S) - zip.begin() + 1;
		a[i].E = lower_bound(zip.begin(), zip.end(), a[i].E) - zip.begin() + 1;
		b[i] = a[i];
	}
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(!q.empty() && q.front().fi < a[i].S)
		{
			spa[q.front().se][0] = a[i].num;
			q.pop();
		}
		
		q.push({a[i].E, a[i].num});
	}
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	for(ll i = 1 ; i < 400010 ; i++)
		minn[i] = {INF, -1};
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(minn[a[i].S].fi > a[i].E)
			minn[a[i].S] = {a[i].E, a[i].num};
	}
	
	for(ll i = 400008 ; i >= 0 ; i--)
	{
		if(minn[i].fi > minn[i + 1].fi)
			minn[i] = minn[i + 1];
	}
	
	st.insert(0);
	st.insert(400009);
	idx[0] = 0;
	idx[400009] = 400009;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		auto p = st.upper_bound(b[i].E);
		p--;
		
		if(idx[*p] >= b[i].S)
			continue;
		
		ll SS = idx[*p] + 1;
		p++;
		ll EE = (*p) - 1;
		
		if(f(SS, EE) == f(SS, b[i].S - 1) + 1 + f(b[i].E + 1, EE))
		{
			ans.push_back(i);
			st.insert(b[i].S);
			idx[b[i].S] = b[i].E;
		}
	}
	
	cout << (ll)ans.size() en;
	
	for(auto &i : ans)
		cout << i sp;
	
	return 0;
}