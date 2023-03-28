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

ll n, m;
char a[110][110];
ll DP = 2, CC = 1;
ll chk[110][110];
ll dx[] = {0, -1, 0, 1, 0};
ll dy[] = {0, 0, 1, 0, -1};

pll move(ll X, ll Y)
{
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < m ; j++)
			chk[i][j] = 0;
	}
	
	queue<pll> q;
	vector<pll> vv;
	
	q.push({X, Y});
	chk[X][Y] = 1;
	
	while(!q.empty())
	{
		pll qq = q.front();
		q.pop();
		
		vv.push_back(qq);
		
		for(ll d = 1 ; d <= 4 ; d++)
		{
			pll nxt;
			
			nxt.fi = qq.fi + dx[d];
			nxt.se = qq.se + dy[d];
			
			if(nxt.fi < 0 || nxt.fi >= n || nxt.se < 0 || nxt.se >= m)
				continue;
			
			if(chk[nxt.fi][nxt.se] || a[X][Y] != a[nxt.fi][nxt.se])
				continue;
			
			q.push(nxt);
			chk[nxt.fi][nxt.se] = 1;
		}
	}
	
	ll gap = MIN;
	
	for(auto &i : vv)
		gap = max(gap, i.fi * dx[DP] + i.se * dy[DP]);
	
	ll DR = DP;
	
	if(CC == 1)
	{
		DR--;
		
		if(DR <= 0)
			DR = 4;
	}
	
	else
	{
		DR++;
		
		if(DR >= 5)
			DR = 1;
	}
	
	ll gapa = MIN;
	pll hey;
	
	for(auto &i : vv)
	{
		if(i.fi * dx[DP] + i.se * dy[DP] != gap)
			continue;
		
		if(gapa < i.fi * dx[DR] + i.se * dy[DR])
		{
			gapa = i.fi * dx[DR] + i.se * dy[DR];
			hey = i;
		}
	}
	
	pll nxnx;
	
	nxnx.fi = hey.fi + dx[DP];
	nxnx.se = hey.se + dy[DP];
	
	if(nxnx.fi < 0 || nxnx.se < 0 || nxnx.fi >= n || nxnx.se >= m)
		return {-1, -1};
	
	if(a[nxnx.fi][nxnx.se] == 'X')
		return {-1, -1};
	
	return nxnx;
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 0 ; i < n ; i++)
		cin >> a[i];
	
	ll x = 0, y = 0;
	
	while(1)
	{
		cout << a[x][y];
		
		ll ff = 0;
		
		while(ff <= 8)
		{
			pll tmp = move(x, y);
			
			if(tmp.fi != -1)
			{
				x = tmp.fi;
				y = tmp.se;
				break;
			}
			
			ff++;
			CC = 3 - CC;
			tmp = move(x, y);
			
			if(tmp.fi != -1)
			{
				x = tmp.fi;
				y = tmp.se;
				break;
			}
			
			ff++;
			DP++;
			
			if(DP >= 5)
				DP = 1;
		}
		
		if(ff > 8)
			break;
	}
	
	return 0;
}