#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef double ld;
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
ll n;
ll era[3000010];
vector<ll> sosu;
ll chk1[3000010], chk2[3000010];
complex<ld> vec1[3000010], vec2[3000010];

struct Fast_Fourier_Transform
{
	ll mxsiz = (1LL << 21);
	ld PI = 3.14159265358979;
	
	void FFT(complex<ld> F[], bool inv)
	{
		ll siz = mxsiz;
		
		for(ll i = 1, j = 0 ; i < siz ; i++)
		{
			ll B = siz / 2;
			
			while(!((j ^= B) & B))
				B /= 2;
			
			if(i < j)
				swap(F[i], F[j]);
		}
		
		for(ll k = 1 ; k < siz ; k *= 2)
		{
			ld A = (inv ? PI / (ld)k : -PI / (ld)k);
			complex<ld> w(cos(A), sin(A));
			
			for(ll i = 0 ; i < siz ; i += k * 2)
			{
				complex<ld> wp(1, 0);
				
				for(ll j = 0 ; j < k ; j++)
				{
					complex<ld> X = F[i + j];
					complex<ld> Y = F[i + j + k] * wp;
					
					F[i + j] = X + Y;
					F[i + j + k] = X - Y;
					wp *= w;
				}
			}
		}
		
		if(inv)
		{
			for(ll i = 0 ; i < siz ; i++)
				F[i] /= siz;
		}
	}
	
	void mul(complex<ld> F[], complex<ld> G[])
	{
		FFT(F, 0);
		FFT(G, 0);
		
		for(ll i = 0 ; i < mxsiz ; i++)
			F[i] *= G[i];
		
		FFT(F, 1);
	}
}fft;

int main(void)
{
	fastio
	
	for(ll i = 2 ; i <= 1000000 ; i++)
	{
		if(era[i])
			continue;
		
		sosu.push_back(i);
		
		for(ll j = i * i ; j <= 1000000 ; j += i)
			era[j] = 1;
	}
	
	for(auto &i : sosu)
	{
		if(i & 1)
			vec1[i] = complex<ld>(1, 0);
		
		if(i * 2 <= 1000000)
			vec2[i * 2] = complex<ld>(1, 0);
	}
	
	fft.mul(vec1, vec2);
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		cout << (ll)round(vec1[n].real()) en;
	}
	
	return 0;
}