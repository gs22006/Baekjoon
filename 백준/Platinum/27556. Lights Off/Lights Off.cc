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

ll t, n, m;
ll chk[21][2000010];
vector<ll> grp[21];
string all, bll;

ll shft(ll X)
{
	ll gap = (X & 1);
	
	X >>= 1;
	X += (1LL << (n - 1)) * gap;
	
	return X;
}

int main(void)
{
	fastio
	
	cin >> t >> n;
	
	m = (1LL << n);
	
	for(ll i = 1 ; i < m ; i++)
	{
		vector<ll> vv;
		ll cou = 0;
		
		for(ll j = 0 ; j < n ; j++)
		{
			if(i & (1LL << j))
			{
				vv.push_back(j);
				cou++;
			}
		}
		
		if(cou == n)
		{
			grp[n].push_back(i);
			continue;
		}
		
		ll ff1 = 0, ff2 = 0;
		
		for(ll j = 1 ; j < (ll)vv.size() ; j++)
		{
			if(vv[j - 1] + 1 != vv[j])
				ff1 = 1;
		}
		
		if(!ff1)
		{
			grp[cou].push_back(i);
			continue;
		}
		
		ll now = 0, cou2 = 0;
		
		for(ll j = 0 ; j < (ll)vv.size() ; j++)
		{
			if(vv[j] != now)
				break;
			
			now++;
			cou2++;
		}
		
		now = n - 1;
		
		for(ll j = (ll)vv.size() - 1 ; j >= 0 ; j--)
		{
			if(vv[j] != now)
				break;
			
			now--;
			cou2++;
		}
		
		if(cou2 == cou)
			grp[cou].push_back(i);
	}
	
	vector<ll> last;
	
	chk[0][0] = 1;
	last.push_back(0);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(auto &j : grp[i])
		{
			for(auto &k : last)
				chk[i][k ^ j] = 1;
		}
		
		last.clear();
		
		for(ll j = 0 ; j < m ; j++)
		{
			if(chk[i][j])
				last.push_back(j);
		}
	}
	
	while(t--)
	{
		cin >> all >> bll;
		
		ll A = 0, B = 0;
		
		for(auto &i : all)
			A = A * 2 + (i - '0');
		
		for(auto &i : bll)
			B = B * 2 + (i - '0');
		
		ll now = 0;
		ll ans = 0;
		
		for(ll i = 0 ; i <= n ; i++)
		{
			ll gap = (A ^ now);
			
			if(chk[i][gap])
			{
				ans = i;
				break;
			}
			
			now ^= B;
			B = shft(B);
		}
		
		cout << ans en;
	}
	
	return 0;
}