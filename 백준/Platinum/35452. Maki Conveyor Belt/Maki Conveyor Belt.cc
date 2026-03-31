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

struct plate
{
	ll s, t, x, c;
};

ll n, m, K, pa, pb;
ll a[200010], b[200010];
ll tmpa[200010], tmpb[200010];
plate P[200010];
multiset<pll> st[200010];

bool comp(ll X, ll Y)
{
	return P[X].c < P[Y].c;
}

pll solve(ll X)
{
	for(ll i = 0 ; i <= m ; i++)
	{
		st[i].clear();
		tmpa[i] = a[i];
		tmpb[i] = b[i];
	}
	
	vector<ll> A, B, AB;
	
	for(ll i = 1 ; i <= K ; i++)
	{
		ll S = P[i].s;
		ll E = P[i].s + X;
		ll chkA = 0, chkB = 0;
		
		if(E > n)
			E -= n;
		
		if(S <= E && S <= pa && pa <= E)
			chkA = 1;
		else if(S > E && (pa <= E || S <= pa))
			chkA = 1;
		
		if(S <= E && S <= pb && pb <= E)
			chkB = 1;
		else if(S > E && (pb <= E || S <= pb))
			chkB = 1;
		
		if(chkA && chkB)
			AB.push_back(i);
		else if(chkA)
			A.push_back(i);
		else if(chkB)
			B.push_back(i);
	}
	
	sort(A.begin(), A.end(), comp);
	sort(B.begin(), B.end(), comp);
	sort(AB.begin(), AB.end(), comp);
	
	ll ret = 0, gaet = 0;
	
	for(auto &i : A)
	{
		plate now = P[i];
		
		if(!tmpa[now.t])
			continue;
		
		gaet = min(tmpa[now.t], now.x);
		ret += gaet * now.c;
		st[now.t].insert({now.c, gaet});
		tmpa[now.t] -= gaet;
	}
	
	for(auto &i : B)
	{
		plate now = P[i];
		
		if(!tmpb[now.t])
			continue;
		
		gaet = min(tmpb[now.t], now.x);
		ret += gaet * now.c;
		st[now.t].insert({now.c, gaet});
		tmpb[now.t] -= gaet;
	}
	
	for(auto &i : AB)
	{
		plate now = P[i];
		
		if(tmpa[now.t])
		{
			gaet = min(tmpa[now.t], now.x);
			ret += gaet * now.c;
			st[now.t].insert({now.c, gaet});
			tmpa[now.t] -= gaet;
			now.x -= gaet;
		}
		
		if(tmpb[now.t] && now.x)
		{
			gaet = min(tmpb[now.t], now.x);
			ret += gaet * now.c;
			st[now.t].insert({now.c, gaet});
			tmpb[now.t] -= gaet;
			now.x -= gaet;
		}
		
		while(now.x)
		{
			if(st[now.t].empty())
				break;
			
			pll gap = (*st[now.t].rbegin());
			
			if(now.c >= gap.fi)
				break;
			
			gaet = min(now.x, gap.se);
			
			st[now.t].erase(st[now.t].find(gap));
			ret -= gap.fi * gaet;
			ret += now.c * gaet;
			gap.se -= gaet;
			now.x -= gaet;
			
			if(gap.se)
				st[now.t].insert(gap);
			
			st[now.t].insert({now.c, gaet});
		}
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(tmpa[i] || tmpb[i])
			return {0, -1};
	}
	
	return {1, ret};
}

int main(void)
{
	fastio
	
	cin >> n >> m >> K >> pa >> pb;
	
	for(ll i = 1 ; i <= m ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= m ; i++)
		cin >> b[i];
	
	for(ll i = 1 ; i <= K ; i++)
		cin >> P[i].s >> P[i].t >> P[i].x >> P[i].c;
	
	ll l = 0, r = n - 1;
	
	while(l <= r)
	{
		ll mid = (l + r) >> 1;
		
		if(solve(mid).fi)
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	if(l == n)
		cout << "impossible";
	else
		cout << l sp << solve(l).se;
	
	return 0;
}