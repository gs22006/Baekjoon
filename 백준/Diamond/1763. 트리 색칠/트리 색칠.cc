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

ll n, R;
ll a[2010];
ll all, bll;
ll P[2010];
ll pa[2010], ra[2010];
ll sum[2010], siz[2010];
ll ans;

ll ffind(ll here)
{
	if(pa[here] == here)
		return here;
	
	return pa[here] = ffind(pa[here]);
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	if(X == Y)
		return;
	
	if(ra[X] < ra[Y])
	{
		pa[X] = Y;
		sum[Y] += sum[X];
		siz[Y] += siz[X];
	}
	
	else if(ra[Y] < ra[X])
	{
		pa[Y] = X;
		sum[X] += sum[Y];
		siz[X] += siz[Y];
	}
	
	else
	{
		pa[X] = Y;
		ra[Y]++;
		sum[Y] += sum[X];
		siz[Y] += siz[X];
	}
}

int main(void)
{
	fastio
	
	cin >> n >> R;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		ans += a[i];
	}
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll;
		P[bll] = all;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		pa[i] = i;
		sum[i] = a[i];
		siz[i] = 1;
	}
	
	for(ll i = 1 ; i < n ; i++)
	{
		ld maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			ll V = ffind(j);
			
			if(P[V] && maxx < (ld)sum[V] / siz[V])
			{
				maxx = (ld)sum[V] / siz[V];
				w = V;
			}
		}
		
		ll tmp = ffind(P[w]);
		
		ans += sum[w] * siz[tmp];
		uunion(w, P[w]);
		P[w] = P[tmp];
	}
	
	cout << ans;
	return 0;
}