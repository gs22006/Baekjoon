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

ll n, m;
ll a[2510], b[2510];
vector<pll> A, B;
vector<ll> tmp1, tmp2, tmp3, seqA, seqB;
ll chk[2510], go[2510];
ll omin[2], emin[2];
ll oidx[2], eidx[2];
ll idx[2510];
ll ansA, ansB;

ll op_num(void)
{
	ll siz = (ll)tmp1.size();
	ll ret = 0;
	vector<ll> lol;
	tmp3.clear();
	
	for(ll i = 0 ; i < siz ; i++)
	{
		chk[i] = go[i] = 0;
		idx[tmp1[i]] = i;
	}
	
	for(ll i = 0 ; i < siz ; i++)
		go[tmp1[i]] = tmp2[i];
	
	for(ll i = 0 ; i < siz ; i++)
	{
		ll now = tmp1[i];
		
		if(chk[now])
			continue;
		
		chk[now] = 1;
		ll tmp = 1, ff = 0;
		vector<ll> vv;
		
		while(1)
		{
			if(now == 0)
				ff = 1;
			
			vv.push_back(idx[now]);
			now = go[now];
			
			if(chk[now])
				break;
			
			chk[now] = 1;
			tmp++;
		}
		
		if(tmp <= 1)
			continue;
		
		if(ff)
			ret += tmp - 1;
		else
			ret += tmp + 1;
		
		if(!ff)
		{
			reverse(vv.begin(), vv.end());
			vv.push_back(idx[0]);
			reverse(vv.begin(), vv.end());
			vv.push_back(vv[0]);
		}
		
		else
		{
			lol = vv;
			continue;
		}
		
		for(ll j = 0 ; j < (ll)vv.size() - 1 ; j++)
			tmp3.push_back((vv[j + 1] - vv[j] + siz) % siz);
	}
	
	for(ll j = 0 ; j < (ll)lol.size() - 1 ; j++)
		tmp3.push_back((lol[j + 1] - lol[j] + siz) % siz);
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= m ; i++)
		cin >> b[i];
	
	tmp1.clear();
	tmp2.clear();
	tmp1.push_back(0);
	tmp2.push_back(0);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		tmp1.push_back(a[i]);
		tmp2.push_back(0);
	}
	
	for(ll i = 0 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= n ; j++)
		{
			ll idx = (i + j) % (n + 1);
			tmp2[idx] = j;
		}
		
		A.push_back({i, op_num()});
	}
	
	tmp1.clear();
	tmp2.clear();
	tmp1.push_back(0);
	tmp2.push_back(0);
	
	for(ll i = 1 ; i <= m ; i++)
	{
		tmp1.push_back(b[i]);
		tmp2.push_back(0);
	}
	
	for(ll i = 0 ; i <= m ; i++)
	{
		for(ll j = 0 ; j <= m ; j++)
		{
			ll idx = (i + j) % (m + 1);
			tmp2[idx] = j;
		}
		
		B.push_back({i, op_num()});
	}
	
	omin[0] = omin[1] = emin[0] = emin[1] = INF;
	
	for(auto &i : A)
	{
		if(i.se & 1)
		{
			if(omin[0] > i.se)
			{
				omin[0] = i.se;
				oidx[0] = i.fi;
			}
		}
		
		else
		{
			if(emin[0] > i.se)
			{
				emin[0] = i.se;
				eidx[0] = i.fi;
			}
		}
	}
	
	for(auto &i : B)
	{
		if(i.se & 1)
		{
			if(omin[1] > i.se)
			{
				omin[1] = i.se;
				oidx[1] = i.fi;
			}
		}
		
		else
		{
			if(emin[1] > i.se)
			{
				emin[1] = i.se;
				eidx[1] = i.fi;
			}
		}
	}
	
	if(min(max(omin[0], omin[1]), max(emin[0], emin[1])) == INF)
	{
		cout << -1;
		return 0;
	}
	
	if(max(omin[0], omin[1]) < max(emin[0], emin[1]))
	{
		ansA = oidx[0];
		ansB = oidx[1];
	}
	
	else
	{
		ansA = eidx[0];
		ansB = eidx[1];
	}
	
	tmp1.clear();
	tmp2.clear();
	tmp1.push_back(0);
	tmp2.push_back(0);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		tmp1.push_back(a[i]);
		tmp2.push_back(0);
	}
	
	for(ll i = ansA ; i <= ansA ; i++)
	{
		for(ll j = 0 ; j <= n ; j++)
		{
			ll idx = (i + j) % (n + 1);
			tmp2[idx] = j;
		}
		
		op_num();
		seqA = tmp3;
	}
	
	tmp1.clear();
	tmp2.clear();
	tmp1.push_back(0);
	tmp2.push_back(0);
	
	for(ll i = 1 ; i <= m ; i++)
	{
		tmp1.push_back(b[i]);
		tmp2.push_back(0);
	}
	
	for(ll i = ansB ; i <= ansB ; i++)
	{
		for(ll j = 0 ; j <= m ; j++)
		{
			ll idx = (i + j) % (m + 1);
			tmp2[idx] = j;
		}
		
		op_num();
		seqB = tmp3;
	}
	
	ll siz1 = (ll)seqA.size();
	ll siz2 = (ll)seqB.size();
	
	if(siz1 < siz2)
	{
		for(ll i = 0 ; i < siz2 - siz1 ; i += 2)
		{
			seqA.push_back(1);
			seqA.push_back(n);
		}
	}
	
	else
	{
		for(ll i = 0 ; i < siz1 - siz2 ; i += 2)
		{
			seqB.push_back(1);
			seqB.push_back(m);
		}
	}
	
	cout << (ll)seqA.size() en;
	
	for(ll i = 0 ; i < (ll)seqA.size() ; i++)
		cout << seqA[i] sp << seqB[i] en;
	
	return 0;
}