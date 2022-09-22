#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

ll n, m;
char all[20];
char a[20][20];
ll ss = 10007;
map< pair<string, ll>, ll> dp[20][20];
pair<string, ll> ttmp;
ll couu = 0;

void ord(pair<string, ll>& gap)
{
	ll num[31] = {0, };
	ll cc = 0;
	
	for(ll i = 0 ; i < m ; i++)
	{
		if(!gap.fi[i])
			continue;
		
		if(!num[gap.fi[i]])
			num[gap.fi[i]] = ++cc;
	}
	
	if(gap.se && !num[gap.se])
		num[gap.se] = ++cc;
	
	for(ll i = 0 ; i < m ; i++)
		gap.fi[i] = num[gap.fi[i]];
	
	gap.se = num[gap.se];
}

ll f(ll X, ll Y, pair<string, ll> cur)
{
	if(dp[X][Y].count(cur))
		return dp[X][Y][cur];
	
	if(X >= n + 1)
	{
		ll ff = 0;
		
		for(ll i = 0 ; i < m - 1 ; i++)
		{
			if(cur.fi[i])
				ff = 1;
		}
		
		if(!cur.fi[m - 1])
			ff = 1;
		
		if(cur.se)
			ff = 1;
		
		if(!ff)
			return dp[X][Y][cur] = 1;
		
		return dp[X][Y][cur] = 0;
	}
	
	ll ret = 0;
	ll nx = X, ny = Y;
	
	if(ny == m)
	{
		ny = 1;
		nx++;
	}
	
	else
		ny++;
	
	if(cur.fi[0] && cur.se)
	{
		if(a[X][Y] == '#' || cur.fi[0] == cur.se)
			return dp[X][Y][cur] = 0;
		
		pair<string, ll> nxt;
		
		nxt = cur;
		
		for(ll i = 1 ; i < m ; i++)
		{
			if(nxt.fi[i] == nxt.fi[0] || nxt.fi[i] == nxt.se)
				nxt.fi[i] = 30;
		}
		
		nxt.fi.erase(nxt.fi.begin());
		nxt.fi.push_back(0);
		nxt.se = 0;
		ord(nxt);
		
		ret = (ret + f(nx, ny, nxt)) % ss;
	}
	
	else if(cur.fi[0])
	{
		if(a[X][Y] == '#')
			return dp[X][Y][cur] = 0;
		
		pair<string, ll> nxt = cur;
		ll tmp = nxt.fi[0];
		
		if(Y < m)
		{
			nxt.fi.erase(nxt.fi.begin());
			nxt.fi.push_back(0);
			nxt.se = tmp;
			ord(nxt);
			
			ret = (ret + f(nx, ny, nxt)) % ss;
		}
		
		nxt = cur;
		tmp = nxt.fi[0];
		
		nxt.fi.erase(nxt.fi.begin());
		nxt.fi.push_back(tmp);
		nxt.se = 0;
		ord(nxt);
		
		ret = (ret + f(nx, ny, nxt)) % ss;
	}
	
	else if(cur.se)
	{
		if(a[X][Y] == '#')
			return dp[X][Y][cur] = 0;
		
		pair<string, ll> nxt = cur;
		ll tmp = nxt.se;
		
		if(Y < m)
		{
			nxt.fi.erase(nxt.fi.begin());
			nxt.fi.push_back(0);
			nxt.se = tmp;
			ord(nxt);
			
			ret = (ret + f(nx, ny, nxt)) % ss;
		}
		
		nxt = cur;
		tmp = nxt.se;
		
		nxt.fi.erase(nxt.fi.begin());
		nxt.fi.push_back(tmp);
		nxt.se = 0;
		ord(nxt);
		
		ret = (ret + f(nx, ny, nxt)) % ss;
	}
	
	else
	{
		pair<string, ll> nxt = cur;
		
		nxt.fi.erase(nxt.fi.begin());
		nxt.fi.push_back(0);
		nxt.se = 0;
		ord(nxt);
		
		ret = (ret + f(nx, ny, nxt)) % ss;
		
		if(a[X][Y] != '#' && Y < m)
		{
			nxt = cur;
			
			nxt.fi.erase(nxt.fi.begin());
			nxt.fi.push_back(30);
			nxt.se = 30;
			ord(nxt);
			
			ret = (ret + f(nx, ny, nxt)) % ss;
		}
	}
	
	return dp[X][Y][cur] = ret;
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all;
		strcpy(a[i] + 1, all);
	}
	
	ttmp.fi.push_back(1);
	
	for(ll i = 1 ; i < m ; i++)
		ttmp.fi.push_back(0);
	
	ttmp.se = 0;
	
	ll ans = f(1, 1, ttmp) % ss;
	ans = ans < 0 ? ans + ss : ans;
	
	cout << ans;
	return 0;
}