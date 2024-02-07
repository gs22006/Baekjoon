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
ll a[500010], b[500010];
ll arr[500010];
vector<pll> cvh;
vector<ll> A, B;
ll ans, x, y;

ll ccw(pll X, pll Y, pll Z)
{
	return (X.fi * Y.se + Y.fi * Z.se + Z.fi * X.se) - (X.se * Y.fi + Y.se * Z.fi + Z.se * X.fi);
}

void f(ll siz)
{
	cvh.clear();
	
	for(ll i = 1 ; i <= siz ; i++)
	{
		while(cvh.size() >= 2)
		{
			ll now = (ll)cvh.size();
			
			if(ccw(cvh[now - 2], cvh[now - 1], {i, arr[i]}) <= 0)
				cvh.pop_back();
			else
				break;
		}
		
		cvh.push_back({i, arr[i]});
	}
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	n++, m++;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= m ; i++)
		cin >> b[i];
	
	for(ll i = 1 ; i <= n ; i++)
		arr[i] = a[i];
	
	f(n);
	
	for(auto &i : cvh)
		A.push_back(i.fi);
	
	for(ll i = 1 ; i <= m ; i++)
		arr[i] = b[i];
	
	f(m);
	
	for(auto &i : cvh)
		B.push_back(i.fi);
	
	x = 0, y = 0;
	ll sizA = (ll)A.size(), sizB = (ll)B.size();
	
	while(1)
	{
		if(x == sizA - 1 && y == sizB - 1)
			break;
		
		pll gapA, gapB;
		
		gapA = {INF / 2000000000, 1};
		gapB = {INF / 2000000000, 1};
		
		if(x < sizA - 1)
			gapA = {a[A[x + 1]] - a[A[x]], A[x + 1] - A[x]};
		
		if(y < sizB - 1)
			gapB = {b[B[y + 1]] - b[B[y]], B[y + 1] - B[y]};
		
		if(gapA.fi * gapB.se > gapB.fi * gapA.se)
		{
			ans += a[A[x]] * (B[y + 1] - B[y]);
			y++;
		}
		
		else
		{
			ans += b[B[y]] * (A[x + 1] - A[x]);
			x++;
		}
	}
	
	cout << ans;
	return 0;
}