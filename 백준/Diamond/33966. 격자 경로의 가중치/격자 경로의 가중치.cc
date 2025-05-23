#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;
typedef vector<ll> poly;
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

const ll w = 3;
const ll mod = 998244353;
ll n, K;
ll a[500010];
ll dp[500010];
ll fac[500010], inv[500010];
ll ss = 998244353;
ll cat[500010];
ll sum[500010];

ll pw(ll X, ll Y)
{
ll ret = 1;

while(Y)
{
	if(Y & 1)
		ret = ret * X % ss;

	X = X * X % ss;
	Y >>= 1;
}

return ret;


}

//prewrittencode(https://www.acmicpc.net/source/share/5f604fba09ee46099107595863571b89)
void ntt(poly &f, bool inv = 0){
int n = f.size(), j = 0;
vector<ll> root(n >> 1);
for(int i=1; i<n; ++i){
int bit = (n >> 1);
while(j >= bit){
j -= bit; bit >>= 1;
}
j += bit;
if(i < j) swap(f[i], f[j]);
}
ll ang = pw(w, (mod - 1) / n); if(inv) ang = pw(ang, mod - 2);
root[0] = 1; for(int i=1; i<(n >> 1); ++i) root[i] = root[i-1] * ang % mod;
for(int i=2; i<=n; i<<=1){
int step = n / i;
for(int j=0; j<n; j+=i){
for(int k=0; k<(i >> 1); k++){
ll u = f[j | k], v = f[j | k | i >> 1] * root[step * k] % mod;
f[j | k] = (u + v) % mod;
f[j | k | i >> 1] = (u - v) % mod;
if(f[j | k | i >> 1] < 0) f[j | k | i >> 1] += mod;
}
}
}
ll t = pw(n, mod - 2);
if(inv) for(ll i=0; i<n; ++i) f[i] = f[i] * t % mod;
}

vector<ll> multiply(poly &_a, poly &_b){
vector<ll> a, b;
a = _a, b = _b;
ll n = 2;
while(n < a.size() + b.size()) n <<= 1;
a.resize(n); b.resize(n);
ntt(a); ntt(b);
for(ll i=0; i<n; ++i) a[i] = a[i] * b[i] % mod;
ntt(a, 1);
return a;
}

ll C(ll xx, ll yy)
{
if(xx < yy)
return 0;

if(xx == yy || !yy)
    return 1;

ll r = (fac[xx] * inv[xx - yy]) % ss;
r = (r * inv[yy]) % ss;
return r;


}

void f(ll L, ll R)
{
if(L == R)
{
if(L == 0)
dp[L] = a[L];
else if(L < K)
dp[L] = 0;
else
dp[L] = sum[L] % ss * a[L] % ss;

	return;
}

ll mid = (L + R) >> 1;

f(L, mid);

ll L1 = mid - L + 1, L2 = R - L - K + 1;

if(L2 > 0)
{
	vector<ll> P1, P2;

	for(ll i = 0 ; i < L1 ; ++i)
		P1.push_back(dp[L + i]);

	for(ll i = 0 ; i < L2 ; ++i)
		P2.push_back(cat[i]);

	vector<ll> gop = multiply(P1, P2);
	ll SZ = (ll)gop.size();

	for(ll i = mid + 1 ; i <= R ; ++i)
	{
		if(i - K - L >= 0 && i - K - L < SZ)
			sum[i] = (sum[i] + gop[i - K - L]);
	}
}

f(mid + 1, R);


}

int main(void)
{
fastio

cin >> n >> K;

for(ll i = 0 ; i <= n ; ++i)
	cin >> a[i];

fac[0] = 1;

for(ll i = 1 ; i <= 400000 ; ++i)
	fac[i] = fac[i - 1] * i % ss;

for(ll i = 0 ; i <= 400000 ; ++i)
	inv[i] = pw(fac[i], ss - 2);

for(ll i = 0 ; i <= 200000 ; ++i)
	cat[i] = C(i * 2, i) * pw(i + 1, ss - 2) % ss;

f(0, n);

for(ll i = K ; i <= n ; ++i)
	cout << (dp[i] + ss) % ss sp;

return 0;


}