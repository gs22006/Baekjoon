#include "squirrel.h"
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

ll n, D[500010], H[500010], W[500010], L, R;
ll d[500010];

struct line
{
	ll gi, S, E, Y;
};

long long fly(vector<int> DD, vector<int> HH, vector<int> WW, int LL, int RR)
{
	n = (ll)DD.size();
	
	for(ll i = 0 ; i < n ; i++)
	{
		D[i + 1] = DD[i];
		H[i + 1] = HH[i];
		W[i + 1] = WW[i];
	}
	
	L = LL, R = RR;
	
	for(ll i = 1 ; i < n ; i++)
		d[i] = D[i + 1] - D[i];
	
	for(ll i = 1 ; i < n ; i++)
	{
		if(H[i] - d[i] < 0)
			return -1;
	}
	
	deque<line> dq;
	ll mv = 0;
	
	dq.push_back({0, 0, L, 0});
	dq.push_back({W[1], L, H[1], (H[1] - L) * W[1]});
	
	for(ll i = 2 ; i <= n ; i++)
	{
		mv += d[i - 1];
		
		line help;
		
		while(!dq.empty() && dq.front().E - mv <= 0)
		{
			help = dq.front();
			dq.pop_front();
		}
		
		if(!dq.empty())
		{
			line qq = dq.front();
			dq.pop_front();
			qq.S = mv;
			dq.push_front(qq);
		}
		
		else
		{
			line tmp;
			
			tmp.gi = W[i];
			tmp.S = mv;
			tmp.E = mv + H[i];
			tmp.Y = help.Y + (tmp.E - tmp.S) * tmp.gi;
			
			dq.push_back(tmp);
			continue;
		}
		
		ll ny = 0;
		line QQ;
		
		while(!dq.empty() && (dq.back().gi >= W[i] || dq.back().S - mv > H[i]))
		{
			QQ = dq.back();
			dq.pop_back();
		}
		
		if(dq.empty())
			dq.push_back({W[i], 0 + mv, H[i] + mv, QQ.Y - (QQ.E - QQ.S) * QQ.gi + H[i] * W[i]});
		
		else
		{
			line qq = dq.back();
			dq.pop_back();
			
			if(qq.E - mv >= H[i])
			{
				qq.Y -= qq.gi * (qq.E - mv - H[i]);
				qq.E = H[i] + mv;
				dq.push_back(qq);
			}
			
			else
			{
				dq.push_back(qq);
				dq.push_back({W[i], qq.E, H[i] + mv, qq.Y + (H[i] + mv - qq.E) * W[i]});
			}
		}
	}
	
	for(auto &i : dq)
	{
		if(i.S - mv <= R && R <= i.E - mv)
			return i.Y - i.gi * (i.E - mv - R);
	}
}