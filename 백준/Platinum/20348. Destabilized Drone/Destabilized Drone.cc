#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll w, h;
ll qry[1010][1010];
vector<pll> d, W;
set<pll> ans;

ll query(ll X, ll Y)
{
	char ret[10];
	
	if(qry[X][Y] != INF)
		return qry[X][Y];
	
	printf("? %lld %lld\n", X, Y);
	fflush(stdout);
	
	scanf("%s", ret);
	
	if(!strcmp(ret, "sky"))
		return qry[X][Y] = -1;
	else if(!strcmp(ret, "horizon"))
		return qry[X][Y] = 0;
	else
		return qry[X][Y] = 1;
}

int main(void)
{
	scanf("%lld %lld", &w, &h);
	
	for(ll i = 1 ; i <= w ; i++)
	{
		for(ll j = 1 ; j <= h ; j++)
			qry[i][j] = INF;
	}
	
	ll l1 = 1, r1 = h;
	
	while(l1 + 1 < r1)
	{
		ll mid = (l1 + r1) / 2;
		
		if(query(1, mid) == -1)
			r1 = mid;
		else
			l1 = mid;
	}
	
	ll l2 = 1, r2 = h;
	
	while(l2 + 1 < r2)
	{
		ll mid = (l2 + r2) / 2;
		
		if(query(w, mid) == -1)
			r2 = mid;
		else
			l2 = mid;
	}
	
	if(query(1, l1) == 0)
		ans.insert({1, l1});
	
	if(query(w, l2) == 0)
		ans.insert({w, l2});
	
	if(query(1, r1) == 0)
		ans.insert({1, r1});
	
	if(query(w, r2) == 0)
		ans.insert({w, r2});
	
	for(ll i = 1 ; i <= w ; i++)
	{
		for(ll j = 1 ; j <= h ; j++)
		{
			if(((l2 - l1) * i + w * l1 - l2) <= j * (w - 1) && j * (w - 1) <= ((r2 - r1) * i + w * r1 - r2))
				W.push_back({i, j});
		}
	}
	
	sort(W.begin(), W.end());
	
	ll l = 0, r = (ll)W.size() - 1;
	ll cc = 0;
	ll lf = 0, rf = 0;
	
	while(l <= r)
	{
		if((ll)ans.size() >= 2)
			break;
		
		if((cc & 1) && !rf)
		{
			if(query(W[r].fi, W[r].se) == 0)
			{
				ans.insert(W[r]);
				rf = 1;
			}
			
			r--;
		}
		
		else if(!lf)
		{
			if(query(W[l].fi, W[l].se) == 0)
			{
				ans.insert(W[l]);
				lf = 1;
			}
			
			l++;
		}
		
		cc++;
	}
	
	assert((ll)ans.size() >= 2);
	
	vector<pll> hmm;
	
	for(auto &i : ans)
		hmm.push_back(i);
	
	printf("! %lld %lld %lld %lld\n", hmm[0].fi, hmm[0].se, hmm[1].fi, hmm[1].se);
	fflush(stdout);
	
	return 0;
}