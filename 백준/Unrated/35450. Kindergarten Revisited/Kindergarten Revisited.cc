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

ll n;
pair<pll, pll> a[500010];
pll pnt[500010];
ll cc;
vector<pll> lin;
ll mo[500010];
vector<ll> L[500010], R[500010], I[500010];
ll num[1010][1010];
ll ccc;

ll ccw(pll X, pll Y, pll Z)
{
	if(X.fi * Y.se + Y.fi * Z.se + Z.fi * X.se - X.se * Y.fi - Y.se * Z.fi - Z.se * X.fi < 0)
		return -1;
	else if(X.fi * Y.se + Y.fi * Z.se + Z.fi * X.se - X.se * Y.fi - Y.se * Z.fi - Z.se * X.fi > 0)
		return 1;
	
	return 0;
}

ll intersect(pll X, pll Y, pll Z, pll W)
{
	if(ccw(X, Y, Z) * ccw(X, Y, W) < 0)
		return 1;
	
	return 0;
}

ll chk[5000010];

ll f(vector<ll> now)
{
	if((ll)now.size() <= 1)
		return 1;
	
	vector<pll> tmp;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		tmp.push_back({i, chk[i]});
		chk[i] = 0;
	}
	
	for(auto &i : now)
		chk[i] = 1;
	
	vector<ll> Lnum;
	
	for(auto &i : now)
	{
		for(auto &j : now)
		{
			if(i > j)
				continue;
			
			for(ll k = 1 ; k <= 4 ; k++)
			{
				for(ll l = 1 ; l <= 4 ; l++)
				{
					ll num1 = k + (i - 1) * 4;
					ll num2 = l + (j - 1) * 4;
					
					if(num1 < num2)
						Lnum.push_back(num[num1][num2]);
				}
			}
		}
	}
	
	ll ret = 0;
	
	for(auto &i : Lnum)
	{
		ll ff = 0;
		
		for(auto &j : I[i])
		{
			if(chk[j])
			{
				ff = 1;
				break;
			}
		}
		
		if(ff)
			continue;
		
		vector<ll> tmp2, tmp3;
		
		for(auto &o : L[i])
		{
			if(chk[o])
				tmp2.push_back(o);
		}
		
		for(auto &o : R[i])
		{
			if(chk[o])
				tmp3.push_back(o);
		}
		
		if((ll)tmp2.size() == 0 || (ll)tmp3.size() == 0)
			continue;
		
		ret = (f(tmp2) & f(tmp3));
		break;
	}
	
	for(auto &i : tmp)
		chk[i.fi] = i.se;
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se.fi >> a[i].se.se;
		
		pnt[++cc] = {a[i].fi.fi, a[i].fi.se};
		mo[cc] = i;
		pnt[++cc] = {a[i].fi.fi, a[i].se.se};
		mo[cc] = i;
		pnt[++cc] = {a[i].se.fi, a[i].se.se};
		mo[cc] = i;
		pnt[++cc] = {a[i].se.fi, a[i].fi.se};
		mo[cc] = i;
	}
	
	for(ll i = 1 ; i <= cc ; i++)
	{
		for(ll j = i + 1 ; j <= cc ; j++)
		{
			num[i][j] = ++ccc;
			
			for(ll k = 1 ; k <= n ; k++)
			{
				ll ff = 0;
				
				if(intersect(pnt[i], pnt[j], pnt[1 + (k - 1) * 4], pnt[2 + (k - 1) * 4]))
					ff = 1;
				else if(intersect(pnt[i], pnt[j], pnt[2 + (k - 1) * 4], pnt[3 + (k - 1) * 4]))
					ff = 1;
				else if(intersect(pnt[i], pnt[j], pnt[3 + (k - 1) * 4], pnt[4 + (k - 1) * 4]))
					ff = 1;
				else if(intersect(pnt[i], pnt[j], pnt[4 + (k - 1) * 4], pnt[1 + (k - 1) * 4]))
					ff = 1;
				else if(!ccw(pnt[i], pnt[j], pnt[1 + (k - 1) * 4]) && !ccw(pnt[i], pnt[j], pnt[3 + (k - 1) * 4]))
					ff = 1;
				else if(!ccw(pnt[i], pnt[j], pnt[2 + (k - 1) * 4]) && !ccw(pnt[i], pnt[j], pnt[4 + (k - 1) * 4]))
					ff = 1;
				
				if(ff)
				{
					I[ccc].push_back(k);
					continue;
				}
				
				ll M = 0, P = 0;
				ll gap = 0;
				
				gap = ccw(pnt[i], pnt[j], pnt[1 + (k - 1) * 4]);
				
				if(gap > 0)
					P++;
				else if(gap < 0)
					M++;
				
				gap = ccw(pnt[i], pnt[j], pnt[2 + (k - 1) * 4]);
				
				if(gap > 0)
					P++;
				else if(gap < 0)
					M++;
				
				gap = ccw(pnt[i], pnt[j], pnt[3 + (k - 1) * 4]);
				
				if(gap > 0)
					P++;
				else if(gap < 0)
					M++;
				
				gap = ccw(pnt[i], pnt[j], pnt[4 + (k - 1) * 4]);
				
				if(gap > 0)
					P++;
				else if(gap < 0)
					M++;
				
				if(P)
					L[ccc].push_back(k);
				else
					R[ccc].push_back(k);
			}
		}
	}
	
	vector<ll> help;
	
	for(ll i = 1 ; i <= n ; i++)
		help.push_back(i);
	
	if(f(help))
		cout << n - 1;
	else
		cout << "impossible";
	
	return 0;
}