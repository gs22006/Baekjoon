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

ll n, x, y, t;
ll digit;
ll m;
vector<ll> vec[2000010], vec2[2000010];
ll nf, nb;
ll xf, xb;
ll yf, yb;
ll chk[2000010];

ll find_path(ll X, ll Y)
{
	for(ll i = 0 ; i <= m ; i++)
		chk[i] = 0;
	
	queue<pll> q;
	
	chk[X] = 1;
	q.push({X, 0});
	
	while(!q.empty())
	{
		pll qq = q.front();
		q.pop();
		
		if(qq.fi == Y)
			return qq.se;
		
		for(auto &i : vec[qq.fi])
		{
			if(chk[i])
				continue;
			
			chk[i] = 1;
			q.push({i, qq.se + 1});
		}
	}
	
	return -1;
}

ll find_path2(ll X, ll Y)
{
	for(ll i = 0 ; i <= m ; i++)
		chk[i] = 0;
	
	queue<pll> q;
	
	chk[X] = 1;
	q.push({X, 0});
	
	while(!q.empty())
	{
		pll qq = q.front();
		q.pop();
		
		if(qq.fi == Y)
			return qq.se;
		
		for(auto &i : vec2[qq.fi])
		{
			if(chk[i])
				continue;
			
			chk[i] = 1;
			q.push({i, qq.se + 1});
		}
	}
	
	return -1;
}

int main(void)
{
	fastio
	
	cin >> n >> x >> y >> t;
	
	if(t == 0)
	{
		if(x > y)
		{
			cout << -1;
			return 0;
		}
		
		cout << y - x;
		return 0;
	}
	
	for(ll i = 0 ; ; i++)
	{
		if(t < (1LL << i))
		{
			digit = i;
			break;
		}
	}
	
	n--;
	
	m = (1LL << digit);
	nb = (n & (m - 1));
	nf = (n - nb) / m;
	xb = (x & (m - 1));
	xf = (x - xb) / m;
	yb = (y & (m - 1));
	yf = (y - yb) / m;
	
	for(ll i = 0 ; i < m ; i++)
	{
		vec[i].push_back((i ^ t));
		vec[i].push_back((i ^ t) + 1);
	}
	
	for(ll i = 0 ; i < m ; i++)
	{
		if(i <= nb)
		{
			if((i ^ t) <= nb)
				vec2[i].push_back(i ^ t);
			
			if((i ^ t) + 1 <= nb)
				vec2[i].push_back((i ^ t) + 1);
		}
	}
	
	if(y < x)
	{
		if(xf != yf)
		{
			cout << -1;
			return 0;
		}
		
		ll gap = 0;
		
		if(xf == nf)
			gap = find_path2(xb, yb);
		else
			gap = find_path(xb, yb);
		
		cout << gap;
		return 0;
	}
	
	if(xf == yf)
	{
		if(xf == nf)
			cout << find_path2(xb, yb);
		else
			cout << find_path(xb, yb);
		
		return 0;
	}
	
	ll ans = 0;
	ll gap = 0;
	
	gap = find_path(xb, m);
	
	if(gap == -1)
	{
		cout << -1;
		return 0;
	}
	
	ans += gap;
	xf++;
	
	gap = find_path(0, m);
	
	if(gap == -1)
	{
		cout << -1;
		return 0;
	}
	
	ans += gap * (yf - xf);
	
	if(yf == nf)
		gap = find_path2(0, yb);
	else
		gap = find_path(0, yb);
	
	if(gap == -1)
	{
		cout << -1;
		return 0;
	}
	
	ans += gap;
	
	cout << ans;
	return 0;
}