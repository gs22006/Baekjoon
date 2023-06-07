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
ll dist[100010];
ll a[100010], b[100010];
ll nu[100010];
ll dp[100010];

struct line
{
	ll A, B;
	ld S;
};

ld gyo(ll A1, ll B1, ll A2, ll B2)
{
	return (ld)(B2 - B1) / (ld)(A1 - A2);
}

struct CHT
{
	line lin[100010];
	ll siz;
	
	void update(ll X, ll Y)
	{
		if(!siz)
		{
			lin[siz++] = {X, Y, -INF};
			return;
		}
		
		while(siz)
		{
			if(gyo(lin[siz - 1].A, lin[siz - 1].B, X, Y) < lin[siz - 1].S)
				siz--;
			else
				break;
		}
		
		line tmp;
		
		tmp.A = X;
		tmp.B = Y;
		
		if(siz)
			tmp.S = gyo(lin[siz - 1].A, lin[siz - 1].B, X, Y);
		else
			tmp.S = -INF;
		
		lin[siz++] = tmp;
	}
	
	ll query(ll X)
	{
		ll l = 0, r = siz - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) / 2;
			
			if(lin[mid].S <= X)
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		return lin[r].A * X + lin[r].B;
	}
}cht;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 2 ; i <= n ; i++)
		cin >> dist[i];
	
	for(ll i = 1 ; i < n ; i++)
		cin >> a[i] >> b[i];
	
	for(ll i = 2 ; i <= n ; i++)
		nu[i] = nu[i - 1] + dist[i];
	
	cht.update(-nu[n], dp[n]);
	
	for(ll i = n - 1 ; i >= 1 ; i--)
	{
		dp[i] = cht.query(b[i]) + nu[i] * b[i] - a[i];
		cht.update(-nu[i], dp[i]);
	}
	
	cout << -dp[1];
	return 0;
}