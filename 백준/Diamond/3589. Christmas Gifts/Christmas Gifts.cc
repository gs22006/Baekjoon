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

struct gujo
{
	ll typ;
	bitset<1010> jip[3];
	ll num[3];
	ll jsiz, nsiz;
	
	void init(void)
	{
		typ = 0;
		jip[0].reset();
		jip[1].reset();
		num[0] = num[1] = 0;
		jsiz = nsiz = 0;
	}
};

ll t;
ll n, m;
bitset<1010> bs[110];
vector<gujo> vec[110];
ll all, bll, cll;

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		
		for(ll i = 1 ; i <= m ; i++)
		{
			bs[i].reset();
			vec[i].clear();
		}
		
		for(ll i = 1 ; i <= m ; i++)
		{
			cin >> all >> bll;
			
			while(bll--)
			{
				cin >> cll;
				
				if(cll == -1)
				{
					gujo tmp;
					ll sz, gp;
					
					tmp.init();
					tmp.typ = 1;
					
					cin >> sz;
					
					while(sz--)
					{
						cin >> gp;
						tmp.jip[0].set(gp, 1);
					}
					
					vec[all].push_back(tmp);
				}
				
				else if(cll == -2)
				{
					ll gp;
					gujo tmp;
					
					tmp.init();
					tmp.typ = 2;
					
					cin >> gp;
					tmp.num[0] = gp;
					
					vec[all].push_back(tmp);
				}
				
				else if(cll == -3)
				{
					ll sz, gp;
					gujo tmp;
					
					tmp.init();
					tmp.typ = 3;
					
					cin >> gp;
					
					if(gp == -1)
					{
						cin >> sz;
						
						while(sz--)
						{
							cin >> gp;
							tmp.jip[tmp.jsiz].set(gp, 1);
						}
						
						tmp.jsiz++;
					}
					
					else if(gp == -2)
					{
						cin >> gp;
						
						tmp.num[tmp.nsiz] = gp;
						tmp.nsiz++;
					}
					
					cin >> gp;
					
					if(gp == -1)
					{
						cin >> sz;
						
						while(sz--)
						{
							cin >> gp;
							tmp.jip[tmp.jsiz].set(gp, 1);
						}
						
						tmp.jsiz++;
					}
					
					else if(gp == -2)
					{
						cin >> gp;
						
						tmp.num[tmp.nsiz] = gp;
						tmp.nsiz++;
					}
					
					vec[all].push_back(tmp);
				}
				
				else if(cll == -4)
				{
					ll sz, gp;
					gujo tmp;
					
					tmp.init();
					tmp.typ = 4;
					
					cin >> gp;
					cin >> gp;
					tmp.num[0] = gp;
					cin >> gp;
					cin >> sz;
					
					while(sz--)
					{
						cin >> gp;
						tmp.jip[0].set(gp, 1);
					}
					
					vec[all].push_back(tmp);
				}
			}
		}
		
		/*for(ll i = 1 ; i <= m ; i++)
		{
			cout << "iiii : " << i en;
			for(auto &j : vec[i])
			{
				cout << "typ : " << j.typ en;
				
				for(ll k = 1 ; k <= n ; k++)
					cout << j.jip[0][k] sp;
				
				cout en;
				
				for(ll k = 1 ; k <= n ; k++)
					cout << j.jip[1][k] sp;
				
				cout en;
				cout << j.num[0] sp << j.num[1] en;
			}
		}
		*/
		while(1)
		{
			ll ff = 0;
			
			for(ll i = 1 ; i <= m ; i++)
			{
				ll yo = (ll)bs[i].count();
				
				for(auto &j : vec[i])
				{
					if(j.typ == 1)
						bs[i] |= j.jip[0];
					else if(j.typ == 2)
						bs[i] |= bs[j.num[0]];
					
					else if(j.typ == 3)
					{
						if(j.jsiz == 2)
							bs[i] |= (j.jip[0] & j.jip[1]);
						else if(j.nsiz == 2)
							bs[i] |= (bs[j.num[0]] & bs[j.num[1]]);
						else
							bs[i] |= (bs[j.num[0]] & j.jip[0]);
					}
					
					else if(j.typ == 4)
						bs[i] |= (bs[j.num[0]] & (~j.jip[0]));
				}
				
				if(yo != (ll)bs[i].count())
					ff = 1;
			}
			
			if(!ff)
				break;
		}
		
		for(ll i = 1 ; i <= m ; i++)
		{
			cout << i sp;
			
			for(ll j = 1 ; j <= n ; j++)
			{
				if(bs[i][j])
					cout << j sp;
			}
			
			cout en;
		}
	}
	
	return 0;
}