#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n, k;
ll all, bll, cll;
vector<ll> vec[1000010], cvec[1000010];
ll R[1000010], siz[1000010];
ll cou[1000010];
pair<ll, ll> tmp[1000010];
ll cc;
ll ans = 987654321;
ll tmp2[1000010];
ll cc2;

void dfs(ll here, ll pa)
{
	siz[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(i == pa || R[i])
			continue;
		
		dfs(i, here);
		siz[here] += siz[i];
	}
}

ll get_centroid(ll here, ll pa, ll TS)
{
	for(auto &i : vec[here])
	{
		if(i == pa || R[i])
			continue;
		
		if(siz[i] * 2 > TS)
			return get_centroid(i, here, TS);
	}
	
	return here;
}

void dfs2(ll here, ll pa, ll gap, ll gap2)
{
	tmp[cc++] = {gap, gap2};
	
	ll sizz = (ll)vec[here].size();
	
	for(ll i = 0 ; i < sizz ; i++)
	{
		if(vec[here][i] == pa || R[vec[here][i]])
			continue;
		
		dfs2(vec[here][i], here, gap + cvec[here][i], gap2 + 1);
	}
}

void f(ll here)
{
	dfs(here, 0);
	
	ll rt = get_centroid(here, 0, siz[here]);
	cc2 = 0;
	
	ll sizz = (ll)vec[rt].size();
	
	for(ll i = 0 ; i < sizz ; i++)
	{
		if(R[vec[rt][i]])
			continue;
		
		cc = 0;
		dfs2(vec[rt][i], rt, cvec[rt][i], 1);
		
		for(ll oo = 0 ; oo < cc ; oo++)
		{
			pair<ll, ll> j = tmp[oo];
			
			if(j.fi > k)
				continue;
			
			if(j.fi == k)
				ans = min(ans, j.se);
			else if(cou[k - j.fi] != -1)
				ans = min(ans, cou[k - j.fi] + j.se);
		}
		
		for(ll oo = 0 ; oo < cc ; oo++)
		{
			pair<ll, ll> j = tmp[oo];
			
			if(j.fi > k)
				continue;
			
			tmp2[cc2++] = j.fi;
			
			if(cou[j.fi] == -1)
				cou[j.fi] = j.se;
			else
				cou[j.fi] = min(cou[j.fi], j.se);
		}
	}
	
	for(ll i = 0 ; i < cc2 ; i++)
		cou[tmp2[i]] = -1;
	
	R[rt] = 1;
	
	for(auto &i : vec[rt])
	{
		if(!R[i])
			f(i);
	}
}

int main(void)
{
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin >> n >> k;
	
	for(ll i = 0 ; i <= k ; i++)
		cou[i] = -1;
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll >> cll;
		
		all++;
		bll++;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
		cvec[all].push_back(cll);
		cvec[bll].push_back(cll);
	}
	
	f(1);
	
	cout << (ans == 987654321 ? -1 : ans);
	return 0;
}