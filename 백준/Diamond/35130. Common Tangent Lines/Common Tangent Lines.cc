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

ll t;
pll a[10];
ld ans;
pll b[10];
ld PI = 3.14159265358979;
ld DR = PI / 180.0;
ld d1 = 0, d2 = 0, d3 = 0, d4 = 0;
ld a1 = INF, a2 = INF, a3 = INF, a4 = INF;

void solve(void)
{
	for(ll i = 1 ; i <= 4 ; i++)
		b[i] = a[i];
	
	ld al1 = (b[1].fi + b[2].fi) / 2.0;
	ld al2 = (b[3].fi + b[4].fi) / 2.0;
	
	if(al1 != al2)
		return;
	
	if(b[3].fi == b[4].fi)
		return;
	
	if(b[1].fi == b[3].fi || b[1].fi == b[4].fi || b[2].fi == b[3].fi || b[2].fi == b[4].fi)
		return;
	
	d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	a1 = INF, a2 = INF, a3 = INF, a4 = INF;
	
	if(b[1].fi == b[2].fi)
	{
		d1 = 0.5;
		d2 = 0.5;
	}
	
	else
	{
		d1 += sin(DR * b[2].fi) / sin(DR * (b[2].fi - b[1].fi)) * cos(DR * al1);
		d1 += cos(DR * b[2].fi) / sin(DR * (b[1].fi - b[2].fi)) * sin(DR * al1);
		d2 += -sin(DR * b[1].fi) / sin(DR * (b[2].fi - b[1].fi)) * cos(DR * al1);
		d2 += -cos(DR * b[1].fi) / sin(DR * (b[1].fi - b[2].fi)) * sin(DR * al1);
	}
	
	d3 += sin(DR * b[4].fi) / sin(DR * (b[4].fi - b[3].fi)) * cos(DR * al2);
	d3 += cos(DR * b[4].fi) / sin(DR * (b[3].fi - b[4].fi)) * sin(DR * al2);
	d4 += -sin(DR * b[3].fi) / sin(DR * (b[4].fi - b[3].fi)) * cos(DR * al2);
	d4 += -cos(DR * b[3].fi) / sin(DR * (b[3].fi - b[4].fi)) * sin(DR * al2);
	
	if(d1 != 0)
		a1 = abs(((d3 * b[3].se + d4 * b[4].se - d2 * b[2].se) / d1) - b[1].se);
	
	if(d2 != 0)
		a2 = abs(((d3 * b[3].se + d4 * b[4].se - d1 * b[1].se) / d2) - b[2].se);
	
	if(d3 != 0)
		a3 = abs(((d1 * b[1].se + d2 * b[2].se - d4 * b[4].se) / d3) - b[3].se);
	
	if(d4 != 0)
		a4 = abs(((d1 * b[1].se + d2 * b[2].se - d3 * b[3].se) / d4) - b[4].se);
	
	ans = min(ans, a1);
	ans = min(ans, a2);
	ans = min(ans, a3);
	ans = min(ans, a4);
}

void solve2(void)
{
	for(ll i = 1 ; i <= 4 ; i++)
		b[i] = a[i];
	
	ld al1 = (b[1].fi + b[2].fi) / 2.0;
	ld al2 = (b[3].fi + b[4].fi) / 2.0;
	
	if(b[1].fi != b[2].fi)
		al1 = (b[1].fi + b[2].fi) / 2.0 + 90;
	
	if(al1 != al2)
		return;
	
	if(b[3].fi == b[4].fi)
		return;
	
	if(b[1].fi == b[3].fi || b[1].fi == b[4].fi || b[2].fi == b[3].fi || b[2].fi == b[4].fi)
		return;
	
	d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	a1 = INF, a2 = INF, a3 = INF, a4 = INF;
	
	if(b[1].fi == b[2].fi)
	{
		d1 = 0.5;
		d2 = 0.5;
	}
	
	else
	{
		d1 += sin(DR * b[2].fi) / sin(DR * (b[2].fi - b[1].fi)) * cos(DR * al1);
		d1 += cos(DR * b[2].fi) / sin(DR * (b[1].fi - b[2].fi)) * sin(DR * al1);
		d2 += -sin(DR * b[1].fi) / sin(DR * (b[2].fi - b[1].fi)) * cos(DR * al1);
		d2 += -cos(DR * b[1].fi) / sin(DR * (b[1].fi - b[2].fi)) * sin(DR * al1);
	}
	
	d3 += sin(DR * b[4].fi) / sin(DR * (b[4].fi - b[3].fi)) * cos(DR * al2);
	d3 += cos(DR * b[4].fi) / sin(DR * (b[3].fi - b[4].fi)) * sin(DR * al2);
	d4 += -sin(DR * b[3].fi) / sin(DR * (b[4].fi - b[3].fi)) * cos(DR * al2);
	d4 += -cos(DR * b[3].fi) / sin(DR * (b[3].fi - b[4].fi)) * sin(DR * al2);
	
	if(d1 != 0)
		a1 = abs(((d3 * b[3].se + d4 * b[4].se - d2 * b[2].se) / d1) - b[1].se);
	
	if(d2 != 0)
		a2 = abs(((d3 * b[3].se + d4 * b[4].se - d1 * b[1].se) / d2) - b[2].se);
	
	if(d3 != 0)
		a3 = abs(((d1 * b[1].se + d2 * b[2].se - d4 * b[4].se) / d3) - b[3].se);
	
	if(d4 != 0)
		a4 = abs(((d1 * b[1].se + d2 * b[2].se - d3 * b[3].se) / d4) - b[4].se);
	
	ans = min(ans, a1);
	ans = min(ans, a2);
	ans = min(ans, a3);
	ans = min(ans, a4);
}

void solve3(void)
{
	for(ll i = 1 ; i <= 4 ; i++)
		b[i] = a[i];
	
	ld al1 = (b[1].fi + b[2].fi) / 2.0;
	ld al2 = (b[3].fi + b[4].fi) / 2.0;
	
	al2 = (b[3].fi + b[4].fi) / 2.0 + 90;
	
	if(al1 != al2)
		return;
	
	if(b[3].fi == b[4].fi)
		return;
	
	if(b[1].fi == b[3].fi || b[1].fi == b[4].fi || b[2].fi == b[3].fi || b[2].fi == b[4].fi)
		return;
	
	d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	a1 = INF, a2 = INF, a3 = INF, a4 = INF;
	
	if(b[1].fi == b[2].fi)
	{
		d1 = 0.5;
		d2 = 0.5;
	}
	
	else
	{
		d1 += sin(DR * b[2].fi) / sin(DR * (b[2].fi - b[1].fi)) * cos(DR * al1);
		d1 += cos(DR * b[2].fi) / sin(DR * (b[1].fi - b[2].fi)) * sin(DR * al1);
		d2 += -sin(DR * b[1].fi) / sin(DR * (b[2].fi - b[1].fi)) * cos(DR * al1);
		d2 += -cos(DR * b[1].fi) / sin(DR * (b[1].fi - b[2].fi)) * sin(DR * al1);
	}
	
	d3 += sin(DR * b[4].fi) / sin(DR * (b[4].fi - b[3].fi)) * cos(DR * al2);
	d3 += cos(DR * b[4].fi) / sin(DR * (b[3].fi - b[4].fi)) * sin(DR * al2);
	d4 += -sin(DR * b[3].fi) / sin(DR * (b[4].fi - b[3].fi)) * cos(DR * al2);
	d4 += -cos(DR * b[3].fi) / sin(DR * (b[3].fi - b[4].fi)) * sin(DR * al2);
	
	if(d1 != 0)
		a1 = abs(((d3 * b[3].se + d4 * b[4].se - d2 * b[2].se) / d1) - b[1].se);
	
	if(d2 != 0)
		a2 = abs(((d3 * b[3].se + d4 * b[4].se - d1 * b[1].se) / d2) - b[2].se);
	
	if(d3 != 0)
		a3 = abs(((d1 * b[1].se + d2 * b[2].se - d4 * b[4].se) / d3) - b[3].se);
	
	if(d4 != 0)
		a4 = abs(((d1 * b[1].se + d2 * b[2].se - d3 * b[3].se) / d4) - b[4].se);
	
	ans = min(ans, a1);
	ans = min(ans, a2);
	ans = min(ans, a3);
	ans = min(ans, a4);
}

void solve4(void)
{
	for(ll i = 1 ; i <= 4 ; i++)
		b[i] = a[i];
	
	ld al1 = (b[1].fi + b[2].fi) / 2.0;
	ld al2 = (b[3].fi + b[4].fi) / 2.0;
	
	if(b[1].fi != b[2].fi)
		al1 = (b[1].fi + b[2].fi) / 2.0 - 90;
	
	if(al1 != al2)
		return;
	
	if(b[3].fi == b[4].fi)
		return;
	
	if(b[1].fi == b[3].fi || b[1].fi == b[4].fi || b[2].fi == b[3].fi || b[2].fi == b[4].fi)
		return;
	
	d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	a1 = INF, a2 = INF, a3 = INF, a4 = INF;
	
	if(b[1].fi == b[2].fi)
	{
		d1 = 0.5;
		d2 = 0.5;
	}
	
	else
	{
		d1 += sin(DR * b[2].fi) / sin(DR * (b[2].fi - b[1].fi)) * cos(DR * al1);
		d1 += cos(DR * b[2].fi) / sin(DR * (b[1].fi - b[2].fi)) * sin(DR * al1);
		d2 += -sin(DR * b[1].fi) / sin(DR * (b[2].fi - b[1].fi)) * cos(DR * al1);
		d2 += -cos(DR * b[1].fi) / sin(DR * (b[1].fi - b[2].fi)) * sin(DR * al1);
	}
	
	d3 += sin(DR * b[4].fi) / sin(DR * (b[4].fi - b[3].fi)) * cos(DR * al2);
	d3 += cos(DR * b[4].fi) / sin(DR * (b[3].fi - b[4].fi)) * sin(DR * al2);
	d4 += -sin(DR * b[3].fi) / sin(DR * (b[4].fi - b[3].fi)) * cos(DR * al2);
	d4 += -cos(DR * b[3].fi) / sin(DR * (b[3].fi - b[4].fi)) * sin(DR * al2);
	
	if(d1 != 0)
		a1 = abs(((d3 * b[3].se + d4 * b[4].se - d2 * b[2].se) / d1) - b[1].se);
	
	if(d2 != 0)
		a2 = abs(((d3 * b[3].se + d4 * b[4].se - d1 * b[1].se) / d2) - b[2].se);
	
	if(d3 != 0)
		a3 = abs(((d1 * b[1].se + d2 * b[2].se - d4 * b[4].se) / d3) - b[3].se);
	
	if(d4 != 0)
		a4 = abs(((d1 * b[1].se + d2 * b[2].se - d3 * b[3].se) / d4) - b[4].se);
	
	ans = min(ans, a1);
	ans = min(ans, a2);
	ans = min(ans, a3);
	ans = min(ans, a4);
}

void solve5(void)
{
	for(ll i = 1 ; i <= 4 ; i++)
		b[i] = a[i];
	
	ld al1 = (b[1].fi + b[2].fi) / 2.0;
	ld al2 = (b[3].fi + b[4].fi) / 2.0;
	
	al2 = (b[3].fi + b[4].fi) / 2.0 - 90;
	
	if(al1 != al2)
		return;
	
	if(b[3].fi == b[4].fi)
		return;
	
	if(b[1].fi == b[3].fi || b[1].fi == b[4].fi || b[2].fi == b[3].fi || b[2].fi == b[4].fi)
		return;
	
	d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	a1 = INF, a2 = INF, a3 = INF, a4 = INF;
	
	if(b[1].fi == b[2].fi)
	{
		d1 = 0.5;
		d2 = 0.5;
	}
	
	else
	{
		d1 += sin(DR * b[2].fi) / sin(DR * (b[2].fi - b[1].fi)) * cos(DR * al1);
		d1 += cos(DR * b[2].fi) / sin(DR * (b[1].fi - b[2].fi)) * sin(DR * al1);
		d2 += -sin(DR * b[1].fi) / sin(DR * (b[2].fi - b[1].fi)) * cos(DR * al1);
		d2 += -cos(DR * b[1].fi) / sin(DR * (b[1].fi - b[2].fi)) * sin(DR * al1);
	}
	
	d3 += sin(DR * b[4].fi) / sin(DR * (b[4].fi - b[3].fi)) * cos(DR * al2);
	d3 += cos(DR * b[4].fi) / sin(DR * (b[3].fi - b[4].fi)) * sin(DR * al2);
	d4 += -sin(DR * b[3].fi) / sin(DR * (b[4].fi - b[3].fi)) * cos(DR * al2);
	d4 += -cos(DR * b[3].fi) / sin(DR * (b[3].fi - b[4].fi)) * sin(DR * al2);
	
	if(d1 != 0)
		a1 = abs(((d3 * b[3].se + d4 * b[4].se - d2 * b[2].se) / d1) - b[1].se);
	
	if(d2 != 0)
		a2 = abs(((d3 * b[3].se + d4 * b[4].se - d1 * b[1].se) / d2) - b[2].se);
	
	if(d3 != 0)
		a3 = abs(((d1 * b[1].se + d2 * b[2].se - d4 * b[4].se) / d3) - b[3].se);
	
	if(d4 != 0)
		a4 = abs(((d1 * b[1].se + d2 * b[2].se - d3 * b[3].se) / d4) - b[4].se);
	
	ans = min(ans, a1);
	ans = min(ans, a2);
	ans = min(ans, a3);
	ans = min(ans, a4);
}

void solve6(void)
{
	for(ll i = 1 ; i <= 4 ; i++)
		b[i] = a[i];
	
	ld al1 = (b[1].fi + b[2].fi) / 2.0;
	ld al2 = (b[3].fi + b[4].fi) / 2.0;
	
	if(b[1].fi != b[2].fi)
		al1 = (b[1].fi + b[2].fi) / 2.0 - 90;
	
	al2 = (b[3].fi + b[4].fi) / 2.0 - 90;
	
	if(al1 != al2)
		return;
	
	if(b[3].fi == b[4].fi)
		return;
	
	if(b[1].fi == b[3].fi || b[1].fi == b[4].fi || b[2].fi == b[3].fi || b[2].fi == b[4].fi)
		return;
	
	d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	a1 = INF, a2 = INF, a3 = INF, a4 = INF;
	
	if(b[1].fi == b[2].fi)
	{
		d1 = 0.5;
		d2 = 0.5;
	}
	
	else
	{
		d1 += sin(DR * b[2].fi) / sin(DR * (b[2].fi - b[1].fi)) * cos(DR * al1);
		d1 += cos(DR * b[2].fi) / sin(DR * (b[1].fi - b[2].fi)) * sin(DR * al1);
		d2 += -sin(DR * b[1].fi) / sin(DR * (b[2].fi - b[1].fi)) * cos(DR * al1);
		d2 += -cos(DR * b[1].fi) / sin(DR * (b[1].fi - b[2].fi)) * sin(DR * al1);
	}
	
	d3 += sin(DR * b[4].fi) / sin(DR * (b[4].fi - b[3].fi)) * cos(DR * al2);
	d3 += cos(DR * b[4].fi) / sin(DR * (b[3].fi - b[4].fi)) * sin(DR * al2);
	d4 += -sin(DR * b[3].fi) / sin(DR * (b[4].fi - b[3].fi)) * cos(DR * al2);
	d4 += -cos(DR * b[3].fi) / sin(DR * (b[3].fi - b[4].fi)) * sin(DR * al2);
	
	if(d1 != 0)
		a1 = abs(((d3 * b[3].se + d4 * b[4].se - d2 * b[2].se) / d1) - b[1].se);
	
	if(d2 != 0)
		a2 = abs(((d3 * b[3].se + d4 * b[4].se - d1 * b[1].se) / d2) - b[2].se);
	
	if(d3 != 0)
		a3 = abs(((d1 * b[1].se + d2 * b[2].se - d4 * b[4].se) / d3) - b[3].se);
	
	if(d4 != 0)
		a4 = abs(((d1 * b[1].se + d2 * b[2].se - d3 * b[3].se) / d4) - b[4].se);
	
	ans = min(ans, a1);
	ans = min(ans, a2);
	ans = min(ans, a3);
	ans = min(ans, a4);
}

void solve7(void)
{
	for(ll i = 1 ; i <= 4 ; i++)
		b[i] = a[i];
	
	ld al1 = (b[1].fi + b[2].fi) / 2.0;
	ld al2 = (b[3].fi + b[4].fi) / 2.0;
	
	if(b[1].fi != b[2].fi)
		al1 = (b[1].fi + b[2].fi) / 2.0 + 90;
	
	al2 = (b[3].fi + b[4].fi) / 2.0 + 90;
	
	if(al1 != al2)
		return;
	
	if(b[3].fi == b[4].fi)
		return;
	
	if(b[1].fi == b[3].fi || b[1].fi == b[4].fi || b[2].fi == b[3].fi || b[2].fi == b[4].fi)
		return;
	
	d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	a1 = INF, a2 = INF, a3 = INF, a4 = INF;
	
	if(b[1].fi == b[2].fi)
	{
		d1 = 0.5;
		d2 = 0.5;
	}
	
	else
	{
		d1 += sin(DR * b[2].fi) / sin(DR * (b[2].fi - b[1].fi)) * cos(DR * al1);
		d1 += cos(DR * b[2].fi) / sin(DR * (b[1].fi - b[2].fi)) * sin(DR * al1);
		d2 += -sin(DR * b[1].fi) / sin(DR * (b[2].fi - b[1].fi)) * cos(DR * al1);
		d2 += -cos(DR * b[1].fi) / sin(DR * (b[1].fi - b[2].fi)) * sin(DR * al1);
	}
	
	d3 += sin(DR * b[4].fi) / sin(DR * (b[4].fi - b[3].fi)) * cos(DR * al2);
	d3 += cos(DR * b[4].fi) / sin(DR * (b[3].fi - b[4].fi)) * sin(DR * al2);
	d4 += -sin(DR * b[3].fi) / sin(DR * (b[4].fi - b[3].fi)) * cos(DR * al2);
	d4 += -cos(DR * b[3].fi) / sin(DR * (b[3].fi - b[4].fi)) * sin(DR * al2);
	
	if(d1 != 0)
		a1 = abs(((d3 * b[3].se + d4 * b[4].se - d2 * b[2].se) / d1) - b[1].se);
	
	if(d2 != 0)
		a2 = abs(((d3 * b[3].se + d4 * b[4].se - d1 * b[1].se) / d2) - b[2].se);
	
	if(d3 != 0)
		a3 = abs(((d1 * b[1].se + d2 * b[2].se - d4 * b[4].se) / d3) - b[3].se);
	
	if(d4 != 0)
		a4 = abs(((d1 * b[1].se + d2 * b[2].se - d3 * b[3].se) / d4) - b[4].se);
	
	ans = min(ans, a1);
	ans = min(ans, a2);
	ans = min(ans, a3);
	ans = min(ans, a4);
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		ans = INF;
		
		for(ll i = 1 ; i <= 4 ; i++)
		{
			cin >> a[i].fi >> a[i].se;
			a[i].fi = 180 - a[i].fi;
		}
		
		sort(a + 1, a + 5);
		
		do
		{
			solve();
			solve2();
			solve3();
			solve4();
			solve5();
			solve6();
			solve7();
		}while(next_permutation(a + 1, a + 5));
		
		if(abs(ans - INF) <= 0.00001)
			cout << "no\n";
		else
			cout << ans en;
	}
	
	return 0;
}