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
	ll S, E, num;
	
	bool operator < (const gujo &xx) const
	{
		return E < xx.E;
	}
};

ll n, K;
gujo a[100010], b[100010];
ll spa[100010][21];
queue<pll> q;

ll cost(ll s, ll e)
{
	if(s > e)
		return 0;
	
	ll l = 1, r = n;
	
	while(l <= r)
	{
		ll mid = (l + r) >> 1;
		
		if(b[mid].E <= s)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	ll ret = 0, now = b[r].num;
	
	if(r == 0)
	{
		if(b[1].E > e)
			return 0;
		
		ret++, now = b[1].num;
	}
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if(a[spa[now][i]].E > e)
			continue;
		
		ret += (1LL << i);
		now = spa[now][i];
	}
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].S >> a[i].E;
		b[i] = a[i], b[i].num = i;
	}
	
	sort(b + 1, b + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
		spa[i][0] = 0;
	
	a[0].E = INF;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(!q.empty() && q.front().fi <= b[i].S)
		{
			spa[q.front().se][0] = b[i].num;
			q.pop();
		}
		
		q.push({b[i].E, b[i].num});
	}
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	if(cost(1, 1000000000) < K)
	{
		cout << -1;
		return 0;
	}
	
	set< pair<pll, ll> > st;
	vector<ll> ans;
	ll sum = cost(1, 1000000000);
	
	st.insert({{1, 1000000000}, sum});
	
	for(ll i = 1 ; i <= n ; i++)
	{
		auto p = st.upper_bound({{a[i].S, INF}, INF});
		
		if(p == st.begin())
			continue;
		
		p--;
		pair<pll, ll> gap = (*p);
		
		if(!(gap.fi.fi <= a[i].S && a[i].E <= gap.fi.se))
			continue;
		
		ll cost1 = cost(gap.fi.fi, a[i].S);
		ll cost2 = cost(a[i].E, gap.fi.se);
		ll new_sum = sum - gap.se + 1 + cost1 + cost2;
		
		if(new_sum < K)
			continue;
		
		sum = new_sum;
		st.erase(gap);
		st.insert({{gap.fi.fi, a[i].S}, cost1});
		st.insert({{a[i].E, gap.fi.se}, cost2});
		
		ans.push_back(i);
		
		if((ll)ans.size() >= K)
			break;
	}
	
	for(auto &i : ans)
		cout << i en;
	
	return 0;
}