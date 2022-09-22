#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;

struct lin
{
	ll A;
	ll B;
	ld G;
};

ld cross(lin xx, lin yy)
{
	return (ld)(yy.B - xx.B) / (ld)(xx.A - yy.A);
}

struct CHT
{
	lin a[1000010];
	ll idx = 0;
	
	void insert(ll xx, ll yy)
	{
		a[idx].A = xx;
		a[idx].B = yy;
		
		while(1 < idx && cross(a[idx - 2], a[idx - 1]) > cross(a[idx - 1], a[idx]))
		{
			a[idx - 1] = a[idx];
			idx--;
		}
		
		idx++;
	}
	
	ll query(ll xx)
	{
		ll lef = 0;
		ll rig = idx - 1;
		
		while(lef < rig)
		{
			ll mid = (lef + rig) / 2;
			
			if(cross(a[mid], a[mid + 1]) <= xx)
				lef = mid + 1;
			else
				rig = mid;
		}
		
		return a[lef].A * xx + a[lef].B;
	}
}cht;

ll n;
ll s[200010];
ll nu1[200010];
ll nu2[200010];
ll ans;

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld", &s[i]);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		s[i] *= -1;
		nu1[i] = nu1[i - 1] + s[i];
		nu2[i] = nu2[i - 1] + nu1[i];
	}
	
	ans = min((ll)0, s[1]);
	
	cht.insert(-1, 0);
	
	for(ll i = 2 ; i <= n ; i++)
	{
		ll gap = cht.query(nu1[i]) + nu1[i] * (i + 1) - nu2[i - 1];
		
		ans = min(ans, s[i]);
		ans = min(ans, gap);
		
		cht.insert(-i, nu2[i - 2]);
	}
	
	printf("%lld", ans * -1);
	return 0;
}