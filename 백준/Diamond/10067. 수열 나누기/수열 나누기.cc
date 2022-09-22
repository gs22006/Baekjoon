#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n, k;
ll a[100010];
ll nu[100010];
ll dp[100010], last[100010], gaet[100010];
ll l, r;
vector<ll> vv, L, R, ans;
ll sum;

struct CHT
{
	struct line_func
	{
		ll A, B;
		ld S;
		ll num;
	};
	
	line_func lin[100010];
	ll tp = 1;
	
	ld crossX(line_func X, line_func Y)
	{
		return (ld)(Y.B - X.B) / (ld)(X.A - Y.A);
	}
	
	void update(ll A, ll B, ll NUM)
	{
		line_func tmp;
		
		tmp.A = A;
		tmp.B = B;
		tmp.num = NUM;
		
		if(tmp.A == lin[tp].A && tp)
		{
			if(tmp.B >= lin[tp].B)
				return;
			
			tp--;
		}
		
		while(tp)
		{	
			tmp.S = crossX(tmp, lin[tp]);
			
			if(tmp.S > lin[tp].S)
				break;
			
			tp--;
		}
		
		lin[++tp] = tmp;
	}
	
	pair<ll, ll> query(ll X)
	{
		ll LL = 1;
		ll RR = tp;
		
		while(LL <= RR)
		{
			ll mid = (LL + RR) / 2;
			
			if(lin[mid].S > X)
				RR = mid - 1;
			else
				LL = mid + 1;
		}
		
		return {lin[RR].A * X + lin[RR].B, lin[RR].num};
	}
}cht;

void init(void)
{
	for(ll i = 1 ; i <= n ; i++)
	{
		dp[i] = 0;
		last[i] = 0;
		gaet[i] = 0;
		cht.lin[i] = {0, 0, 0.0, 0};
	}
	
	cht.tp = 1;
}

void solve(ll lambda2)
{
	init();
	
	for(ll i = 1 ; i <= n ; i++)
	{
		pair<ll, ll> qry = cht.query(nu[i]);
		dp[i] = qry.fi + 2 * nu[i] * nu[i];
		last[i] = qry.se;
		gaet[i] = gaet[last[i]] + 1;
		cht.update(-4 * nu[i], dp[i] + 2 * nu[i] * nu[i] + lambda2, i);
	}
	
	vv.clear();
	
	for(ll i = n ; i != 0 ; i = last[i])
		vv.push_back(i);
	
	vv.push_back(0);
	reverse(vv.begin(), vv.end());
	
	return;
}

int main(void)
{
	scanf("%lld %lld", &n, &k);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		scanf("%lld", &a[i]);
		nu[i] = nu[i - 1] + a[i];
	}
	
	k++;
	l = -1, r = INF / 4;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		
		solve(mid * 2 + 1);
		
		if(gaet[n] < k)
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	solve(l * 2 + 1);
	L = vv;
	
	solve(r * 2 + 1);
	R = vv;
	
	if((ll)L.size() - 1 == k)
		ans = L;
	else if((ll)R.size() - 1 == k)
		ans = R;
	
	else
	{
		ll p = 0;
		
		for(ll i = 0 ; i < (ll)R.size() - 1 ; i++)
		{
			while(p < (ll)L.size() && L[p] <= R[i])
				p++;
			
			if(p == (ll)L.size())
				break;
			
			if(!p)
				continue;
			
			if(L[p - 1] <= R[i] && R[i + 1] <= L[p])
			{
				for(ll j = 0 ; j <= i ; j++)
					ans.push_back(R[j]);
				
				for(ll j = p ; j < (ll)L.size() ; j++)
					ans.push_back(L[j]);
				
				if((ll)ans.size() - 1 == k)
					break;
				
				ans.clear();
			}
		}
	}
	
	for(ll i = 1 ; i < (ll)ans.size() ; i++)
	{
		ll gap = 0;
		
		for(ll j = ans[i - 1] + 1 ; j <= ans[i] ; j++)
			gap += a[j];
		
		sum += gap * gap;
	}
	
	if((ll)ans.size() == 0)
	{
		assert(0);
	}
	
	printf("%lld\n", (nu[n] * nu[n] - sum) / 2);
	
	for(ll i = 1 ; i < (ll)ans.size() - 1 ; i++)
		printf("%lld ", ans[i]);
	
	return 0;
}