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
ll a[20][20];
map<string, ll> dp[20][20];
ll chch[20][20];
ll arr[20][20];
ll ccc, cccc;

void ord(string& X)
{
	ll num[110] = {0, };
	ll cc = 0;
	
	for(auto &i : X)
	{
		if(!i)
			continue;
		
		if(!num[i])
			num[i] = ++cc;
	}
	
	for(ll i = 0 ; i < m ; i++)
		X[i] = num[X[i]];
}

void renum(string& gap, ll X, ll Y)
{
	if(Y == 1)
	{
		ll tmp = gap[0];
		
		gap.erase(gap.begin());
		
		if(!tmp)
			tmp = 20;
		
		gap.push_back(tmp);
	}
	
	else
	{
		ll tmp = gap[0];
		
		if(!tmp)
			tmp = 20;
		
		for(ll i = 0 ; i < m ; i++)
		{
			if(gap[i] == gap[m - 1] && gap[m - 1])
				gap[i] = tmp;
		}
		
		gap.erase(gap.begin());
		gap.push_back(tmp);
	}
	
	ord(gap);
}

ll f(ll X, ll Y, string cur)
{
	ll cou[20] = {0, };
	ll gap = 0;
	ll nx = X, ny = Y;
	
	for(auto &i : cur)
		cou[i]++;
	
	for(ll i = 1 ; i < 10 ; i++)
		gap += (!!cou[i]);
	
	if(X >= n + 1)
	{
		if(gap <= 1)
			return 0;
		
		return INF;
	}
	
	if(dp[X][Y].count(cur))
		return dp[X][Y][cur];
	
	if(ny == m)
	{
		nx++;
		ny = 1;
	}
	
	else
		ny++;
	
	ll ret = INF;
	ll ff = 0;
	string nxt = cur;
	
	if(!cur[0])
		ff = 1;
	
	for(ll i = 1 ; i < m ; i++)
	{
		if(cur[0] == cur[i])
			ff = 1;
	}
	
	nxt.erase(nxt.begin());
	nxt.push_back(0);
	ord(nxt);
	
	if(ff)
		ret = min(ret, f(nx, ny, nxt));
	
	nxt = cur;
	renum(nxt, X, Y);
	
	ret = min(ret, f(nx, ny, nxt) + a[X][Y]);
	
	if(gap <= 1)
		ret = min(ret, 0LL);
	
	return dp[X][Y][cur] = ret;
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	}
	
	string ttmp;
	
	ttmp.clear();
	
	for(ll i = 0 ; i < m ; i++)
		ttmp.push_back(0);
	
	cout << f(1, 1, ttmp);
	return 0;
}