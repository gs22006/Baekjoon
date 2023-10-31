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

ll L, R, n;
string a[200010], b[200010];
ll dp[200010];
vector<ll> vv[200010];
ll num[30];
string hmm[200010];

void print(ll here)
{
	if(!hmm[here].empty())
	{
		cout << hmm[here];
		return;
	}
	
	for(auto &i : vv[here])
	{
		if(i <= 0)
		{
			cout << (char)(-i + 'a');
			hmm[here].push_back(-i + 'a');
		}
		
		else
		{
			print(i);
			hmm[here] += hmm[i];
		}
	}
}

void dfs(ll here, ll s, ll e)
{
	if(e < L || R < s)
		return;
	
	if(L <= s && e <= R)
	{
		print(here);
		return;
	}
	
	ll Lf = s, Rg = s;
	
	for(auto &i : vv[here])
	{
		if(i <= 0)
		{
			Rg = min(1000000000000000000LL, Lf);
			
			if(L <= Lf && Rg <= R)
				cout << (char)(-i + 'a');
		}
		
		else
		{
			Rg = min(1000000000000000000LL, Lf + dp[i] - 1);
			dfs(i, Lf, Rg);
		}
		
		Lf = Rg + 1;
		
		if(Lf > R)
			break;
	}
}

int main(void)
{
	fastio
	
	cin >> L >> R >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i] >> b[i];
	
	for(ll i = n ; i >= 1 ; i--)
	{
		for(auto &j : b[i])
		{
			if(num[j - 'a'])
			{
				vv[i].push_back(num[j - 'a']);
				dp[i] = min(1000000000000000000LL, dp[i] + dp[num[j - 'a']]);
			}
			
			else
			{
				vv[i].push_back(-(j - 'a'));
				dp[i] = min(1000000000000000000LL, dp[i] + 1);
			}
		}
		
		num[a[i][0] - 'a'] = i;
	}
	
	if(!num[0])
	{
		cout << "a";
		return 0;
	}
	
	dfs(num[0], 1, dp[num[0]]);
	return 0;
}