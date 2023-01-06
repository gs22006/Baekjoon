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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

ll n, m, q;
ll all, bll;
char cll;
vector<ll> vec[900010];
ll ff;
ll deg[900010];
ll dep[900010];
ll chk[900010];
ll spa[900010][21];

void dfs(ll here, ll pa)
{
	dep[here] = dep[pa] + 1;
	chk[here] = 1;
	spa[here][0] = pa;
	
	for(auto &i : vec[here])
	{
		if(chk[i])
			continue;
		
		dfs(i, here);
	}
}

int main(void)
{
	fastio
	
	cin >> n >> m >> q;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		ll num1 = 0, num2 = 0;
		
		cin >> all >> bll >> cll;
		
		if(cll == 'x')
		{
			num1 = all + n * 2;
			num2 = bll;
		}
		
		else if(cll == 'y')
		{
			num1 = all;
			num2 = bll + n;
		}
		
		else
		{
			num1 = all + n;
			num2 = bll + n * 2;
		}
		
		vec[num2].push_back(num1);
		deg[num1]++;
	}
	
	for(ll i = 1 ; i <= n * 3 ; i++)
	{
		if(!deg[i])
			dfs(i, 0);
	}
	
	queue<ll> Q;
	ll what = 0;
	
	for(ll i = 1 ; i <= n * 3 ; i++)
	{
		if(!deg[i])
			Q.push(i);
	}
	
	while(!Q.empty())
	{
		ll qq = Q.front();
		Q.pop();
		
		what++;
		
		for(auto &i : vec[qq])
		{
			deg[i]--;
			
			if(!deg[i])
				Q.push(i);
		}
	}
	
	if(what != n * 3)
		ff = 1;
	
	if(ff)
	{
		while(q--)
		{
			cin >> all >> bll >> cll;
			cout << 1 en;
		}
		
		return 0;
	}
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n * 3 ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	while(q--)
	{
		ll num1 = 0, num2 = 0;
		
		cin >> all >> bll >> cll;
		
		if(cll == 'x')
		{
			num1 = all + n * 2;
			num2 = bll;
		}
		
		else if(cll == 'y')
		{
			num1 = all;
			num2 = bll + n;
		}
		
		else
		{
			num1 = all + n;
			num2 = bll + n * 2;
		}
		
		swap(num1, num2);
		
		if(dep[num1] < dep[num2])
		{
			cout << 0 en;
			continue;
		}
		
		ll cha = dep[num1] - dep[num2];
		
		for(ll i = 20 ; i >= 0 ; i--)
		{
			if(cha >= (1LL << i))
			{
				cha -= (1LL << i);
				num1 = spa[num1][i];
			}
		}
		
		if(num1 == num2)
			cout << 1 en;
		else
			cout << 0 en;
	}
	
	return 0;
}