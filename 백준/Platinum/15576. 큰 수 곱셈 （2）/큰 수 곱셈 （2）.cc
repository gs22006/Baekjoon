#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

char all[300010], bll[300010];
vector< complex<ld> > a, b, c;
vector<ll> gap, ans;
ll lena, lenb;
ll n;
ld PI = acos(-1);

void FFT(vector< complex<ld> > &F, complex<ld> w)
{
	ll siz = (ll)F.size();
	
	if(siz == 1)
		return;
	
	vector< complex<ld> > ev, od;
	
	for(ll i = 0 ; i < siz ; i++)
	{
		if(i & 1)
			od.push_back(F[i]);
		else
			ev.push_back(F[i]);
	}
	
	FFT(od, w * w);
	FFT(ev, w * w);
	
	complex<ld> tmp(1, 0);
	
	for(ll i = 0 ; i < siz / 2 ; i++)
	{
		F[i] = ev[i] + tmp * od[i];
		F[i + siz / 2] = ev[i] - tmp * od[i];
		tmp *= w;
	}
}

int main(void)
{
	scanf("%s %s", all + 1, bll + 1);
	
	if(all[1] == '0' || bll[1] == '0')
	{
		printf("0");
		return 0;
	}
	
	lena = strlen(all + 1);
	lenb = strlen(bll + 1);
	
	for(ll i = lena ; i >= 1 ; i--)
		a.push_back(all[i] - '0');
	
	for(ll i = lenb ; i >= 1 ; i--)
		b.push_back(bll[i] - '0');
	
	n = 1;
	
	while(n < (ll)a.size() || n < (ll)b.size())
		n <<= 1;
	
	n <<= 1;
	
	a.resize(n);
	b.resize(n);
	
	complex<ld> w(cos(2 * PI / n), sin(2 * PI / n));
	
	FFT(a, w);
	FFT(b, w);
	
	for(ll i = 0 ; i < n ; i++)
		c.push_back(a[i] * b[i]);
	
	complex<ld> ww(cos(2 * PI / n), -sin(2 * PI / n));
	
	FFT(c, ww);
	
	for(ll i = 0 ; i < n ; i++)
		c[i] /= n;
	
	for(ll i = 0 ; i < n ; i++)
		gap.push_back((ll)(c[i].real() + 0.5));
	
	for(ll i = 0 ; i < n - 1 ; i++)
	{
		ans.push_back(gap[i] % 10);
		gap[i + 1] += gap[i] / 10;
	}
	
	ans.push_back(gap[n - 1] % 10);
	ans.push_back(gap[n - 1] / 10);
	
	while(!ans.empty() && !ans.back())
		ans.pop_back();
	
	reverse(ans.begin(), ans.end());
	
	for(auto &i : ans)
		printf("%d", i);
	
	return 0;
}