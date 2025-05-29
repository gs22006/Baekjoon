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

ll n, q;
ll ss = 998244353;
pll qry[2010];
ll B;
map< vector<ll>, ll> mp;
ll ans = 1;
ll fac[2010];
vector<ll> JU;

struct gujo
{
ll gap[2010];
};

gujo a[2010];

int main(void)
{
fastio

cin >> n >> q;

for(ll i = 1 ; i <= n ; i++)
{
	for(ll j = 1 ; j <= n ; j++)
		cin >> a[i].gap[j];
}

fac[0] = 1;

for(ll i = 1 ; i <= 2000 ; i++)
	fac[i] = fac[i - 1] * i % ss;

for(ll i = 1 ; i <= q ; i++)
{
	cin >> qry[i].fi >> qry[i].se;

	if(qry[i].fi == 1)
		B = 1;
}

if(!B)
{
	cout << 1;
	return 0;
}

for(ll i = q ; i >= 1 ; i--)
{
	JU.push_back(qry[i].se);

	if(qry[i].fi == 1)
		break;
}

for(ll i = 1 ; i <= n ; i++)
{
	vector<ll> tmp;

	for(auto &j : JU)
		tmp.push_back(a[i].gap[j]);

	mp[tmp]++;
}

for(auto &i : mp)
	ans = ans * fac[i.se] % ss;

cout << (ans + ss) % ss;
return 0;


}