#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

struct Fast_Fourier_Transform
{
	void FFT(vector< complex<ld> > &X, complex<ld> Y)
	{
		ll siz = (ll)X.size();
		
		if(siz == 1)
			return;
		
		vector< complex<ld> > EVEN(siz >> 1), ODD(siz >> 1);
		
		for(ll i = 0 ; i < siz ; i++)
		{
			if(i & 1)
				ODD[i >> 1] = X[i];
			else
				EVEN[i >> 1] = X[i];
		}
		
		FFT(EVEN, Y * Y);
		FFT(ODD, Y * Y);
		
		complex<ld> WP(1, 0);
		
		for(ll i = 0 ; i < (siz >> 1) ; i++)
		{
			X[i] = EVEN[i] + WP * ODD[i];
			X[i + (siz >> 1)] = EVEN[i] - WP * ODD[i];
			WP = WP * Y;
		}
	}
	
	vector< complex<ld> > mul(vector< complex<ld> > X, vector< complex<ld> > Y)
	{
		ll siz = 1;
		
		while(siz <= (ll)X.size() || siz <= (ll)Y.size())
			siz <<= 1;
		
		siz <<= 1;
		
		X.resize(siz);
		Y.resize(siz);
		
		vector< complex<ld> > ret(siz);
		complex<ld> W(cos(2 * acos(-1) / siz), sin(2 * acos(-1) / siz));
		
		FFT(X, W);
		FFT(Y, W);
		
		for(ll i = 0 ; i < siz ; i++)
			ret[i] = X[i] * Y[i];
		
		FFT(ret, complex<ld>(W.real(), -W.imag()));
		
		for(ll i = 0 ; i < siz ; i++)
		{
			ret[i] /= complex<ld>(siz, 0);
			ret[i] = complex<ld>(round(ret[i].real()), round(ret[i].imag()));
		}
		
		return ret;
	}
}fft;

ll n;
ll all;
vector< complex<ld> > vec1, vec2, vec3;
ll ans;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 0 ; i < n ; i++)
	{
		cin >> all;
		vec1.push_back(complex<ld>(all, 0));
	}
	
	for(ll i = 0 ; i < n ; i++)
	{
		cin >> all;
		vec2.push_back(complex<ld>(all, 0));
	}
	
	for(ll i = 0 ; i < n ; i++)
		vec1.push_back(vec1[i]);
	
	reverse(vec2.begin(), vec2.end());
	
	vec3 = fft.mul(vec1, vec2);
	
	for(auto &i : vec3)
		ans = max(ans, (ll)round(i.real()));
	
	cout << ans;
	return 0;
}