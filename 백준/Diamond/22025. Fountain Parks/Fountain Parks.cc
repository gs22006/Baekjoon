//park.cpp
#include "parks.h"

#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL

vector< pair<ll, ll> > X[200010], Y[200010];
vector<ll> U, V, A, B;
unordered_map<ll, ll> helpmemap, hmmmap;
ll N;
vector<ll> vec[200010];
ll chk[200010];
ll pa[200010], ra[200010];

ll ffind(ll here)
{
	if(here == pa[here])
		return here;
	
	return pa[here] = ffind(pa[here]);
}

void uunion(ll XX, ll YY)
{
	XX = ffind(XX);
	YY = ffind(YY);
	
	if(XX == YY)
		return;
	
	if(ra[XX] < ra[YY])
		pa[XX] = YY;
	else if(ra[YY] < ra[XX])
		pa[YY] = XX;
	
	else
	{
		pa[XX] = YY;
		ra[YY]++;
	}
}

ll chkf(void)
{
	ll m = U.size();
	ll cou = 0;
	queue<ll> q;
	
	for(ll i = 0 ; i < m ; i++)
	{
		vec[U[i]].push_back(V[i]);
		vec[V[i]].push_back(U[i]);
	}
	
	q.push(0);
	chk[0] = 1;
	cou++;
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		for(ll nx : vec[qq])
		{
			if(chk[nx])
				continue;
			
			q.push(nx);
			chk[nx] = 1;
			cou++;
		}
	}
	
	if(cou == N)
		return 1;
	else
		return 0;
}

int construct_roads(vector<int> x, vector<int> y)
{
	ll n;
	n = x.size();
	N = n;
	
	for(ll i = 0 ; i < n ; i++)
	{
		X[x[i]].push_back(make_pair(y[i], i));
		pa[i] = i;
	}
	
	for(ll i = 0 ; i < n ; i++)
		Y[y[i]].push_back(make_pair(x[i], i));
	
	for(ll i = 0 ; i < 200010 ; i++)
	{
		sort(X[i].begin(), X[i].end());
		sort(Y[i].begin(), Y[i].end());
	}
	
	for(ll i = 2 ; i <= 200000 ; i += 2)
	{
		ll siz = X[i].size();
		
		for(ll j = 1 ; j < siz ; j++)
		{
			ll y1 = X[i][j - 1].first, y2 = X[i][j].first;
			
			if((y2 - y1) != 2)
				continue;
			
			if(ffind(X[i][j - 1].second) == ffind(X[i][j].second))
				continue;
			
			if((i + y1) % 4 == 0)
			{
				//left is white
				if(!helpmemap[(i - 1) * 1000000 + (y1 + 1)])
				{
					helpmemap[(i - 1) * 1000000 + (y1 + 1)] = 1;
					U.push_back(X[i][j - 1].second);
					V.push_back(X[i][j].second);
					A.push_back(i - 1);
					B.push_back(y1 + 1);
					uunion(X[i][j - 1].second, X[i][j].second);
				}
			}
			
			else if((i + y1 + 2) % 4 == 0)
			{
				//right is white
				if(!helpmemap[(i + 1) * 1000000 + (y1 + 1)])
				{
					helpmemap[(i + 1) * 1000000 + (y1 + 1)] = 1;
					U.push_back(X[i][j - 1].second);
					V.push_back(X[i][j].second);
					A.push_back(i + 1);
					B.push_back(y1 + 1);
					uunion(X[i][j - 1].second, X[i][j].second);
				}
			}
		}
		
		siz = Y[i].size();
		
		for(ll j = 1 ; j < siz ; j++)
		{
			ll x1 = Y[i][j - 1].first, x2 = Y[i][j].first;
			
			if((x2 - x1) != 2)
				continue;
				
			if(ffind(Y[i][j - 1].second) == ffind(Y[i][j].second))
				continue;
			
			if((i + x1 + 2) % 4 == 2)
			{
				//up is black
				if(!hmmmap[(x1 + 1) * 1000000 + (i + 1)])
				{
					hmmmap[(x1 + 1) * 1000000 + (i + 1)] = 1;
					U.push_back(Y[i][j - 1].second);
					V.push_back(Y[i][j].second);
					A.push_back(x1 + 1);
					B.push_back(i + 1);
					uunion(Y[i][j - 1].second, Y[i][j].second);
				}
			}
			
			else if((i + x1) % 4 == 2)
			{
				//down is black
				if(!hmmmap[(x1 + 1) * 1000000 + (i - 1)])
				{
					hmmmap[(x1 + 1) * 1000000 + (i - 1)] = 1;
					U.push_back(Y[i][j - 1].second);
					V.push_back(Y[i][j].second);
					A.push_back(x1 + 1);
					B.push_back(i - 1);
					uunion(Y[i][j - 1].second, Y[i][j].second);
				}
			}
		}
	}
	
	if((ll)U.size() < N - 1)
		return 0;
	
	build(U, V, A, B);
	return 1;
}
//