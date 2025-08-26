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

ll n, K, T;
ll a[110];
ll ss = 1000000007;
vector<ll> now;
vector< vector<ll> > bun;
map<vector<ll>, ll> mp;
ll dp[10010][60];
vector<ll> nxt[10010];
ll fac[1000010];
ll chk[110];
ll dp2[10010];
ll inv[1000010];

void f(ll sum, ll last)
{
	if(sum == n)
	{
		bun.push_back(now);
		return;
	}
	
	if(sum + last > n)
		return;
	
	for(ll i = last ; i <= n - sum ; i++)
	{
		now.push_back(i);
		f(sum + i, i);
		now.pop_back();
	}
}

void get_dp(void)
{
	dp2[1] = dp2[2] = 1;
	
	for(ll i = 3 ; i <= 100 ; i++)
	{
		for(ll j = 1 ; j <= i / 2 ; j++)
		{
			ll gop = i;
			
			if(j == i - j)
				gop /= 2;
			
			dp2[i] = (dp2[i] + gop * dp2[j] % ss * dp2[i - j] % ss) % ss;
		}
	}
}

ll sqrmtp(ll X, ll Y)
{
	ll ret = 1;
	
	while(Y)
	{
		if(Y & 1)
			ret = ret * X % ss;
		
		X = X * X % ss;
		Y >>= 1;
	}
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n >> K >> T;
	
	f(0, 1);
	get_dp();
	
	for(ll i = 0 ; i < (ll)bun.size() ; i++)
		mp[bun[i]] = i;
	
	ll siz = (ll)bun.size();
	
	fac[0] = 1;
	
	for(ll i = 1 ; i <= 1000000 ; i++)
	{
		fac[i] = fac[i - 1] * i % ss;
		inv[i] = sqrmtp(fac[i], ss - 2);
	}
	
	dp[0][0] = 1;
	
	for(ll i = 0 ; i < siz ; i++)
	{
		vector<ll> now = bun[i];
		ll sz = (ll)now.size();
		
		for(ll j = 0 ; j < sz ; j++)
		{
			for(ll k = j + 1 ; k < sz ; k++)
			{
				vector<ll> nw;
				
				for(ll l = 0 ; l < sz ; l++)
				{
					if(l == j || l == k)
						continue;
					
					nw.push_back(now[l]);
				}
				
				nw.push_back(now[j] + now[k]);
				sort(nw.begin(), nw.end());
				
				nxt[i].push_back(mp[nw]);
			}
		}
		
		for(ll j = 0 ; j < sz ; j++)
		{
			for(ll k = 1 ; k <= now[j] / 2 ; k++)
			{
				vector<ll> nw;
				
				for(ll l = 0 ; l < sz ; l++)
				{
					if(l == j)
						continue;
					
					nw.push_back(now[l]);
				}
				
				nw.push_back(k);
				nw.push_back(now[j] - k);
				sort(nw.begin(), nw.end());
				
				nxt[i].push_back(mp[nw]);
			}
		}
	}
	
	for(ll j = 0 ; j <= 50 ; j++)
	{
		for(ll i = 0 ; i < siz ; i++)
		{
			vector<ll> now = bun[i];
			ll sz = (ll)now.size();
			ll p = 0;
			
			for(ll k = 0 ; k < sz ; k++)
			{
				for(ll l = k + 1 ; l < sz ; l++)
				{
					dp[nxt[i][p]][j + 1] = (dp[nxt[i][p]][j + 1] + dp[i][j] * now[k] % ss * now[l] % ss) % ss;
					p++;
				}
			}
			
			for(ll k = 0 ; k < sz ; k++)
			{
				for(ll l = 1 ; l <= now[k] / 2 ; l++)
				{
					ll gop = now[k];
					
					if(l == now[k] - l)
						gop /= 2;
					
					dp[nxt[i][p]][j + 1] = (dp[nxt[i][p]][j + 1] + dp[i][j] * gop % ss) % ss;
					p++;
				}
			}
		}
	}
	
	while(T--)
	{
		for(ll i = 1 ; i <= n ; i++)
			cin >> a[i];
		
		for(ll i = 1 ; i <= n ; i++)
			chk[i] = 0;
		
		ll p = 0, cou = 0;
		vector<ll> tmp;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(chk[i])
				continue;
			
			p = i;
			cou = 0;
			
			while(1)
			{
				if(chk[p])
					break;
				
				chk[p] = 1;
				cou++;
				p = a[p];
			}
			
			tmp.push_back(cou);
		}
		
		sort(tmp.begin(), tmp.end());
		
		ll ans = dp[mp[tmp]][K];
		ll nanu = fac[n];
		
		cou = 1;
		
		for(ll i = 1 ; i < (ll)tmp.size() ; i++)
		{
			if(tmp[i] == tmp[i - 1])
				cou++;
			
			else
			{
				nanu = nanu * inv[cou] % ss;
				cou = 1;
			}
		}
		
		nanu = nanu * inv[cou] % ss;
		
		for(auto &i : tmp)
			nanu = nanu * sqrmtp(i, ss - 2) % ss;
		
		ans = ans * sqrmtp(nanu, ss - 2) % ss;
		ans = (ans + ss) % ss;
		
		cout << ans en;
	}
	
	return 0;
}