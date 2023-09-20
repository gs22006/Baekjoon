#include "longesttrip.h"
#include <bits/stdc++.h>

using namespace std;
typedef int ll;
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

ll n;
ll chk[310];

ll query(ll X, ll Y)
{
	vector<ll> tmp1, tmp2;
	
	tmp1.push_back(X);
	tmp2.push_back(Y);
	
	return are_connected(tmp1, tmp2);
}

vector<ll> longest_trip(ll N, ll D)
{
	vector<ll> ans;
	set<ll> st;
	n = N;
	
	for(ll i = 0 ; i < n ; i++)
	{
		chk[i] = 0;
		st.insert(i);
	}
	
	if(D == 3)
	{
		for(ll i = 0 ; i < n ; i++)
			ans.push_back(i);
		
		return ans;
	}
	
	if(D == 2)
	{
		ans.push_back(0);
		chk[0] = 1;
		st.erase(0);
		
		while(1)
		{
			ll ff = 0;
			
			for(auto &i : st)
			{
				if(query(ans.back(), i))
				{
					ans.push_back(i);
					chk[i] = 1;
					st.erase(i);
					ff = 1;
					break;
				}
			}
			
			if(!ff)
				break;
		}
		
		reverse(ans.begin(), ans.end());
		
		for(auto &i : st)
			ans.push_back(i);
		
		return ans;
	}
	
	vector<ll> P1, P2;
	ll ST = 0;
	
	if(n % 2 == 0)
	{
		if(query(0, 1))
		{
			P1.push_back(0);
			P1.push_back(1);
		}
		
		else
		{
			P1.push_back(0);
			P2.push_back(1);
		}
		
		ST = 2;
	}
	
	else
	{
		P1.push_back(0);
		ST = 1;
	}
	
	for(ll i = ST ; i < n ; i += 2)
	{
		if(P2.empty())
		{
			ll Q1 = query(i, i + 1);
			ll Q2 = query(P1.back(), i);
			ll Q3 = query(P1.back(), i + 1);
			
			if(Q1)
			{
				if(Q2)
				{
					P1.push_back(i);
					P1.push_back(i + 1);
				}
				
				else if(Q3)
				{
					P1.push_back(i + 1);
					P1.push_back(i);
				}
				
				else
				{
					P2.push_back(i);
					P2.push_back(i + 1);
				}
			}
			
			else
			{
				if(Q2)
				{
					P1.push_back(i);
					P2.push_back(i + 1);
				}
				
				else
				{
					P1.push_back(i + 1);
					P2.push_back(i);
				}
			}
		}
		
		else
		{
			ll Q1 = query(i, i + 1);
			
			if(Q1)
			{
				ll Q2 = query(P1.back(), i);
				
				if(!Q2)
					swap(P1, P2);
				
				P1.push_back(i);
				
				if(query(P2.back(), i + 1))
				{
					P2.push_back(i + 1);
					reverse(P2.begin(), P2.end());
					
					for(auto &j : P2)
						P1.push_back(j);
					
					P2.clear();
				}
				
				else
					P1.push_back(i + 1);
			}
			
			else
			{
				ll Q2 = query(P1.back(), i);
				
				if(!Q2)
					swap(P1, P2);
				
				if(query(P2.back(), i + 1))
				{
					P1.push_back(i);
					P2.push_back(i + 1);
				}
				
				else
				{
					P1.push_back(i + 1);
					P2.push_back(i);
				}
			}
		}
		
		if((ll)P1.size() < (ll)P2.size())
			swap(P1, P2);
	}
	
	if(P2.empty())
		return P1;
	
	if(!are_connected(P1, P2))
		return P1;
	
	vector<ll> tmp1;
	
	tmp1.push_back(P2[0]);
	
	if((ll)P2.size() > 1)
		tmp1.push_back(P2.back());
	
	if(are_connected({P1.back()}, tmp1))
	{
		if(are_connected({P1.back()}, {P2[0]}))
		{
			for(auto &i : P2)
				P1.push_back(i);
			
			return P1;
		}
		
		reverse(P2.begin(), P2.end());
		
		for(auto &i : P2)
			P1.push_back(i);
		
		return P1;
	}
	
	else if(are_connected({P1[0]}, tmp1))
	{
		reverse(P1.begin(), P1.end());
		
		if(are_connected({P1.back()}, {P2[0]}))
		{
			for(auto &i : P2)
				P1.push_back(i);
			
			return P1;
		}
		
		reverse(P2.begin(), P2.end());
		
		for(auto &i : P2)
			P1.push_back(i);
		
		return P1;
	}
	
	ll l = 0, r = (ll)P1.size() - 1;
	
	while(l <= r)
	{
		ll mid = (l + r) >> 1;
		vector<ll> Pcut;
		
		for(ll i = 0 ; i <= mid ; i++)
			Pcut.push_back(P1[i]);
		
		if(are_connected(Pcut, P2))
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	ll idx1 = l;
	
	l = 0, r = (ll)P2.size() - 1;
	
	while(l <= r)
	{
		ll mid = (l + r) >> 1;
		vector<ll> Pcut;
		
		for(ll i = 0 ; i <= mid ; i++)
			Pcut.push_back(P2[i]);
		
		if(are_connected({P1[idx1]}, Pcut))
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	ll idx2 = l;
	
	for(ll i = idx1 - 1 ; i >= 0 ; i--)
		ans.push_back(P1[i]);
	
	for(ll i = (ll)P1.size() - 1 ; i >= idx1 ; i--)
		ans.push_back(P1[i]);
	
	for(ll i = idx2 ; i < (ll)P2.size() ; i++)
		ans.push_back(P2[i]);
	
	for(ll i = 0 ; i < idx2 ; i++)
		ans.push_back(P2[i]);
	
	return ans;
}