#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n;
ll a[110];
ll era[2010];
ll ff;
vector<ll> vec[110];
vector<ll> ans;
ll ltr[110], rtl[110];
ll chk[110];

ll dfs(ll here)
{
	chk[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(rtl[i] == -1 || (!chk[rtl[i]] && dfs(rtl[i])))
		{
			ltr[here] = i;
			rtl[i] = here;
			return 1;
		}
	}
	
	return 0;
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	era[1] = 1;
	
	for(ll i = 2 ; i < 2010 ; i++)
	{
		if(era[i])
			continue;
		
		for(ll j = i * i ; j < 2010 ; j += i)
			era[j] = 1;
	}
	
	for(ll i = 2 ; i <= n ; i++)
	{
		if(era[a[1] + a[i]])
			continue;
		
		for(ll j = 1 ; j <= n ; j++)
			vec[j].clear();
		
		for(ll j = 2 ; j <= n ; j++)
		{
			for(ll k = 2 ; k <= n ; k++)
			{
				if(j == i || k == i || j == k)
					continue;
				
				if(era[a[j] + a[k]])
					continue;
				
				if(a[j] & 1)
					vec[j].push_back(k);
			}
		}
		
		for(ll j = 1 ; j <= n ; j++)
		{
			chk[j] = 0;
			ltr[j] = rtl[j] = -1;
		}
		
		ll cou = 0;
		
		for(ll j = 2 ; j <= n ; j++)
		{
			if(ltr[j] == -1)
			{
				for(ll k = 1 ; k <= n ; k++)
					chk[k] = 0;
				
				cou += dfs(j);
			}
		}
		
		if(cou == n / 2 - 1)
		{
			ans.push_back(a[i]);
			ff = 1;
		}
	}
	
	if(!ff)
		cout << -1;
	
	else
	{
		sort(ans.begin(), ans.end());
		
		for(auto &i : ans)
			cout << i sp;
	}
	
	return 0;
}