#include "closing.h"
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
 
ll n, x, y;
vector<pll> vec[500010];
ll dist1[500010], dist2[500010];
ll yuk[500010], chk[500010];
ll A[500010], B[500010], C[500010];
ll D[500010];
 
void dfs1(ll here, ll pa)
{
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		dist1[i.fi] = dist1[here] + i.se;
		dfs1(i.fi, here);
	}
}
 
void dfs2(ll here, ll pa)
{
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		yuk[i.fi] = here;
		dist2[i.fi] = dist2[here] + i.se;
		dfs2(i.fi, here);
	}
}
 
int max_score(int N, int X, int Y, long long K, vector<int> U, vector<int> V, vector<int> W)
{
	n = N;
	x = X + 1;
	y = Y + 1;
	
	ll ans = -INF;
	
	for(ll i = 1 ; i <= n * 2 + 3 ; i++)
	{
		vec[i].clear();
		dist1[i] = dist2[i] = yuk[i] = chk[i] = 0;
	}
	
	for(ll i = 0 ; i <= n * 2 + 3 ; i++)
		A[i] = B[i] = C[i] = D[i] = INF;
	
	A[0] = B[0] = C[0] = D[0] = 0;
	
	for(ll i = 0 ; i < n - 1 ; i++)
	{
		vec[U[i] + 1].push_back({V[i] + 1, W[i]});
		vec[V[i] + 1].push_back({U[i] + 1, W[i]});
	}
	
	dfs1(x, 0);
	dfs2(y, 0);
	
	vector<ll> vvv;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		vvv.push_back(dist1[i]);
		vvv.push_back(dist2[i]);
	}
	
	sort(vvv.begin(), vvv.end());
	
	ll hap = 0;
	
	for(ll i = 0 ; i < (ll)vvv.size() ; i++)
	{
		hap += vvv[i];
		
		if(hap <= K)
			ans = max(ans, i + 1);
	}
	
	vector<ll> vv;
	
	for(ll i = x ; i != y ; i = yuk[i])
	{
		vv.push_back(i);
		chk[i] = 1;
	}
	
	vv.push_back(y);
	chk[y] = 1;
	
	vector<ll> vv2, vv3;
	ll len = (ll)vv.size();
	
	A[len * 2] = 0;
	
	for(auto &i : vv)
	{
		vv2.push_back(dist1[i]);
		vv2.push_back(dist2[i]);
		vv3.push_back(max(dist1[i], dist2[i]) - dist1[i]);
		vv3.push_back(max(dist1[i], dist2[i]) - dist2[i]);
		A[len * 2] += max(dist1[i], dist2[i]);
	}
	
	sort(vv2.begin(), vv2.end());
	sort(vv3.begin(), vv3.end());
	reverse(vv3.begin(), vv3.end());
	
	ll cc = 0;
	
	for(ll i = 1 ; i <= len ; i++)
		A[i] = A[i - 1] + vv2[i - 1];
	
	for(ll i = len * 2 - 1 ; i > len ; i--)
		A[i] = A[i + 1] - vv3[cc++];
	
	for(ll i = 0 ; i <= len ; i++)
		A[i] = A[i + len];
	
	for(ll i = len + 1 ; i <= len * 2 ; i++)
		A[i] = INF;
	
	vector<pll> vv4;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!chk[i])
			vv4.push_back({min(dist1[i], dist2[i]), max(dist1[i], dist2[i])});
	}
	
	vector<ll> vv5;
	vector<pll> vv6;
	ll minn = INF;
	
	for(auto &i : vv4)
	{
		if(i.fi * 2 <= i.se)
		{
			vv5.push_back(i.fi);
			vv5.push_back(i.se - i.fi);
		}
		
		else
		{
			vv6.push_back(i);
			minn = min(minn, i.fi);
		}
	}
	
	ll nam = (ll)vv6.size();
	
	sort(vv5.begin(), vv5.end());
	
	for(ll i = 0 ; i < (ll)vv5.size() ; i++)
		B[i + 1] = B[i] + vv5[i];
	
	if(nam >= 1)
		C[1] = minn;
	
	multiset<pll> st1;
	multiset<ll> st3, st2;
	
	for(auto &i : vv6)
	{
		st1.insert({i.se, i.fi - i.se});
		st3.insert(i.fi);
	}
	
	ll sum = 0;
	
	for(ll i = 2 ; i <= nam * 2 ; i++)
	{
		if(i % 2 == 0)
		{
			sum += (*st1.begin()).fi;
			st3.erase(st3.find((*st1.begin()).fi + (*st1.begin()).se));
			st2.insert((*st1.begin()).se);
			st1.erase(st1.find(*st1.begin()));
			C[i] = sum;
		}
		
		else
		{
			C[i] = INF;
			C[i] = min(C[i], sum + (*st3.begin()));
			
			if(!st1.empty())
				C[i] = min(C[i], sum + (*st2.begin()) + (*st1.begin()).fi);
		}
	}
	
	ll p1 = 1, p2 = 1;
	cc = 1;
	D[0] = A[0];
	
	while(1)
	{
		if(A[p1] == INF && B[p2] == INF)
			break;
		
		if(A[p1] == INF)
		{
			D[cc] = D[cc - 1] + B[p2] - B[p2 - 1];
			p2++, cc++;
		}
		
		else if(B[p2] == INF)
		{
			D[cc] = D[cc - 1] + A[p1] - A[p1 - 1];
			p1++, cc++;
		}
		
		else
		{
			if(B[p2] - B[p2 - 1] < A[p1] - A[p1 - 1])
			{
				D[cc] = D[cc - 1] + B[p2] - B[p2 - 1];
				p2++, cc++;
			}
			
			else
			{
				D[cc] = D[cc - 1] + A[p1] - A[p1 - 1];
				p1++, cc++;
			}
		}
	}
	
	ll p = -1;
	
	for(ll i = 0 ; i <= n * 2 ; i++)
	{
		if(C[i] != INF)
			p = i;
	}
	
	for(ll i = 0 ; i <= n * 2 ; i++)
	{
		if(D[i] == INF)
			break;
		
		while(p >= 0 && D[i] + C[p] > K)
			p--;
		
		if(p < 0)
			break;
		
		ans = max(ans, i + p + len);
	}
	
	return ans;
}