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

ll n, K;
string a[210];
vector<ll> vec[210];
queue<ll> q;
ll chk[210];

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = i + 1 ; j <= n ; j++)
		{
			ll len1 = a[i].length();
			ll len2 = a[j].length();
			ll ff = 0;
			
			for(ll k = 0 ; k <= len1 - K ; k++)
			{
				for(ll l = 0 ; l <= len2 - K ; l++)
				{
					ll F = 0;
					
					for(ll o = 0 ; o < K ; o++)
					{
						if(a[i][k + o] != a[j][l + o])
							F = 1;
					}
					
					if(!F)
						ff = 1;
				}
			}
			
			if(ff)
			{
				vec[i].push_back(j);
				vec[j].push_back(i);
			}
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(chk[i])
			continue;
		
		q.push(i);
		chk[i] = 1;
		
		while(!q.empty())
		{
			ll qq = q.front();
			q.pop();
			
			for(auto &j : vec[qq])
			{
				if(chk[j])
					continue;
				
				chk[j] = 3 - chk[qq];
				q.push(j);
			}
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(auto &j : vec[i])
		{
			if(chk[i] == chk[j])
			{
				cout << "No";
				return 0;
			}
		}
	}
	
	ll Comeon = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(chk[i] != 1)
			Comeon = 1;
	}
	
	if(!Comeon)
		chk[1] = 2;
	
	cout << "Yes\n";
	
	for(ll i = 1 ; i <= n ; i++)
		cout << chk[i] en;
	
	return 0;
}