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

ll a[10][10], b[10][10];
ll chk[10][10];
vector<ll> vv;
ll pn[10][10], ja[10][10];
ll t;
string S[10];
ll chkk[1000010];
ll dp[1000010];
ll wn[1000010];
ll SOS[1000010];

ll ret_num(void)
{
	ll ret = 0;
	
	for(ll i = 1 ; i <= 4 ; i++)
	{
		for(ll j = 1 ; j <= 4 ; j++)
			ret = ret * 5 + pn[i][j];
	}
	
	return ret;
}

void ret_pan(ll num)
{
	for(ll i = 4 ; i >= 1 ; i--)
	{
		for(ll j = 4 ; j >= 1 ; j--)
		{
			pn[i][j] = num % 5;
			num /= 5;
		}
	}
}

void find_pan(ll here)
{
	if(here > 4)
	{
		for(ll i = 1 ; i <= 4 ; i++)
		{
			for(ll j = 1 ; j <= 4 ; j++)
				pn[i][j] = a[i][j];
		}
		
		vv.push_back(ret_num());
		return;
	}
	
	vector<ll> tmp;
	
	for(ll i = 1 ; i <= 4 ; i++)
		tmp.push_back(i);
	
	do
	{
		ll ff = 0;
		
		for(ll i = 0 ; i < 4 ; i++)
		{
			if(chk[tmp[i]][i + 1])
				ff = 1;
		}
		
		if(ff)
			continue;
		
		for(ll i = 0 ; i < 4 ; i++)
		{
			a[here][i + 1] = tmp[i];
			chk[tmp[i]][i + 1] = 1;
		}
		
		find_pan(here + 1);
		
		for(ll i = 0 ; i < 4 ; i++)
		{
			a[here][i + 1] = 0;
			chk[tmp[i]][i + 1] = 0;
		}
	}while(next_permutation(tmp.begin(), tmp.end()));
}

int main(void)
{
	fastio
	
	ll now = 1;
	ll m = (1LL << 16);
	
	for(ll i = 4 ; i >= 1 ; i--)
	{
		for(ll j = 4 ; j >= 1 ; j--)
		{
			ja[i][j] = now;
			now *= 5;
		}
	}
	
	find_pan(1);
	
	cin >> t;
	
	while(t--)
	{
		ll F = 0;
		
		for(ll i = 0 ; i < 4 ; i++)
			cin >> S[i];
		
		for(ll i = 0 ; i < 4 ; i++)
		{
			for(ll j = 0 ; j < 4 ; j++)
			{
				if(S[i][j] == 'G')
					a[i + 1][j + 1] = 1;
				else if(S[i][j] == 'L')
					a[i + 1][j + 1] = 2;
				else if(S[i][j] == 'M')
					a[i + 1][j + 1] = 3;
				else if(S[i][j] == 'S')
					a[i + 1][j + 1] = 4;
				else
					a[i + 1][j + 1] = 0;
				
				F += (!!a[i + 1][j + 1]);
			}
		}
		
		for(ll i = 0 ; i < m ; i++)
			chkk[i] = SOS[i] = 0;
		
		for(auto &i : vv)
		{
			ll gap = 0;
			
			ret_pan(i);
			
			for(ll i = 1 ; i <= 4 ; i++)
			{
				for(ll j = 1 ; j <= 4 ; j++)
				{
					if(a[i][j] == pn[i][j])
						gap |= (1LL << ((i - 1) * 4 + j - 1));
				}
			}
			
			SOS[gap]++;
		}
		
		for(ll i = 0 ; i < 16 ; i++)
		{
			for(ll j = 0 ; j < m ; j++)
			{
				if(!(j & (1LL << i)))
					SOS[j] += SOS[j ^ (1LL << i)];
			}
		}
		
		for(ll i = 0 ; i < m ; i++)
		{
			if(SOS[i] == 1)
				chkk[i] = 1;
			else
				chkk[i] = 0;
		}
		
		ll lst = 0;
		
		for(ll i = 0 ; i < 16 ; i++)
		{
			if(a[i / 4 + 1][i % 4 + 1] != 0)
				lst |= (1LL << i);
		}
		
		for(ll i = 0 ; i < m ; i++)
		{
			dp[i] = 0;
			wn[i] = 0;
			
			for(ll j = 0 ; j < 16 ; j++)
			{
				if(a[j / 4 + 1][j % 4 + 1] == 0 && (i & (1LL << j)))
					chkk[i] = 0;
			}
		}
		
		for(ll i = 0 ; i < m ; i++)
		{
			if(!chkk[i])
				continue;
			
			dp[i] = 0;
			wn[i] = 0;
			
			ll ff = 0;
			
			for(ll j = 0 ; j < 16 ; j++)
			{
				if((i & (1LL << j)) && chkk[i ^ (1LL << j)])
				{
					ff = 1;
					
					if(wn[i ^ (1LL << j)] == 0)
						wn[i] = 1;
				}
			}
			
			if(!ff)
				continue;
			
			if(wn[i] == 1)
			{
				dp[i] = 0;
				
				for(ll j = 0 ; j < 16 ; j++)
				{
					if(wn[i ^ (1LL << j)] == 0 && (i & (1LL << j)) && chkk[i ^ (1LL << j)])
						dp[i] = max(dp[i], dp[i ^ (1LL << j)] + 1);
				}
			}
			
			else
			{
				dp[i] = INF;
				
				for(ll j = 0 ; j < 16 ; j++)
				{
					if((i & (1LL << j)) && chkk[i ^ (1LL << j)])
						dp[i] = min(dp[i], dp[i ^ (1LL << j)] + 1);
				}
			}
		}
		
		cout << F - dp[lst] en;
	}
	
	return 0;
}