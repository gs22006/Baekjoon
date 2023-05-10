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

ll n, m, k;
ll all, bll, cll;
vector<pll> w[100010], h[100010];
vector<ll> vec[100010];
ll pa[100010], ra[100010];
set<ll> st;
ll gaet;
ll ans = 1;
ll ss = 1000000000;
ll chk[100010];
ll chk2[100010];

ll ffind(ll here)
{
	if(pa[here] == here)
		return here;
	
	return pa[here] = ffind(pa[here]);
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	if(X == Y)
		return;
	
	if(ra[X] < ra[Y])
		pa[X] = Y;
	else if(ra[Y] < ra[X])
		pa[Y] = X;
	
	else
	{
		pa[X] = Y;
		ra[Y]++;
	}
}

int main(void)
{
	fastio
	
	cin >> n >> m >> k;
	
	gaet = n;
	
	for(ll i = 1 ; i <= n ; i++)
		pa[i] = i;
	
	for(ll i = 1 ; i <= k ; i++)
	{
		cin >> all >> bll >> cll;
		
		w[all].push_back({bll, cll});
		h[bll].push_back({all, cll});
		st.insert(bll);
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(h[i].empty())
			continue;
		
		for(auto &j : h[i])
		{
			if(ffind(h[i][0].fi) != ffind(j.fi))
			{
				vec[h[i][0].fi].push_back(j.fi);
				vec[j.fi].push_back(h[i][0].fi);
				uunion(h[i][0].fi, j.fi);
				gaet--;
			}
		}
	}
	
	for(ll i = 1 ; i <= m ; i++)
		chk2[i] = -1;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(chk[i])
			continue;
		
		queue<ll> q;
		
		chk[i] = 1;
		q.push(i);
		
		while(!q.empty())
		{
			ll qq = q.front();
			q.pop();
			
			if(qq != i)
			{
				ll hol = -1, jjak = -1;
				
				for(auto &j : w[qq])
				{
					if(chk2[j.fi] == -1)
						continue;
					
					if(chk2[j.fi] != j.se)
					{
						if((j.fi & 1))
						{
							if(hol == 0)
							{
								cout << 0;
								return 0;
							}
							
							hol = 1;
						}
						
						else
						{
							if(jjak == 0)
							{
								cout << 0;
								return 0;
							}
							
							jjak = 1;
						}
					}
					
					else
					{
						if((j.fi & 1))
						{
							if(hol == 1)
							{
								cout << 0;
								return 0;
							}
							
							hol = 0;
						}
						
						else
						{
							if(jjak == 1)
							{
								cout << 0;
								return 0;
							}
							
							jjak = 0;
						}
					}
				}
				
				if((qq - i) & 1)
				{
					if(!jjak && !hol)
					{
						cout << 0;
						return 0;
					}
					
					if(jjak == 1 && hol == 1)
					{
						cout << 0;
						return 0;
					}
					
					if(jjak == 0)
						hol = 1;
					else if(jjak == 1)
						hol = 0;
					else if(hol == 0)
						jjak = 1;
					else if(hol == 1)
						jjak = 0;
				}
				
				else
				{
					if(hol == 1 && jjak == 0)
					{
						cout << 0;
						return 0;
					}
					
					if(hol == 0 && jjak == 1)
					{
						cout << 0;
						return 0;
					}
					
					if(hol == 0)
						jjak = 0;
					else if(hol == 1)
						jjak = 1;
					else if(jjak == 0)
						hol = 0;
					else if(jjak == 1)
						hol = 1;
				}
				
				for(auto &j : w[qq])
				{
					if(j.fi & 1)
					{
						if(chk2[j.fi] == -1)
							chk2[j.fi] = (j.se ^ hol);
						
						else if(chk2[j.fi] != (j.se ^ hol))
						{
							cout << 0;
							return 0;
						}
					}
					
					else
					{
						if(chk2[j.fi] == -1)
							chk2[j.fi] = (j.se ^ jjak);
						
						else if(chk2[j.fi] != (j.se ^ jjak))
						{
							cout << 0;
							return 0;
						}
					}
				}
			}
			
			else
			{
				for(auto &j : w[qq])
					chk2[j.fi] = j.se;
			}
			
			for(auto &j : vec[qq])
			{
				if(chk[j])
					continue;
				
				chk[j] = 1;
				q.push(j);
			}
		}
	}
	
	gaet += m - (ll)st.size() - 1;
	
	while(gaet--)
		ans = ans * 2 % ss;
	
	cout << ans;
	return 0;
}