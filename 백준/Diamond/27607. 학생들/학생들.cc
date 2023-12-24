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

using namespace std;

ll n, m;
pll a[250010];
ll gap1[250010], gap2[250010];

bool comp(pll A, pll B)
{
	if(A.se == B.se)
		return A.fi < B.fi;
	
	return A.se < B.se;
}

pair<ll, vector<ll> > complaint(ll N, vector<ll> L, vector<ll> R)
{
	n = N;
	m = (ll)L.size();
	
	for(ll i = 0 ; i < m ; i++)
		a[i + 1] = {L[i] + 1, R[i] + 1};
	
	sort(a + 1, a + 1 + m, comp);
	
	ll coco = 0;
	ll last = 0;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(last < a[i].fi)
		{
			last = a[i].se;
			coco++;
			gap1[a[i].se] = coco;
		}
	}
	
	sort(a + 1, a + 1 + m);
	reverse(a + 1, a + 1 + m);
	
	coco = 0;
	last = 987654321;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(last > a[i].se)
		{
			last = a[i].fi;
			coco++;
			gap2[a[i].fi] = coco;
		}
	}
	
	last = 0;
	
	for(ll i = 1 ; i <= n ; i++)
		gap1[i] = max(gap1[i - 1], gap1[i]);
	
	for(ll i = n - 1 ; i >= 1 ; i--)
		gap2[i] = max(gap2[i + 1], gap2[i]);
	
	vector<ll> ans;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(gap1[i - 1] + gap2[i + 1] + 1 == coco)
			ans.push_back(i - 1);
	}
	
	return {coco, ans};
}