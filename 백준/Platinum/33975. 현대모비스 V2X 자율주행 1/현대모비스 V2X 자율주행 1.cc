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
string a, b;
vector<ll> Wa, Wb;
ll sum1, sum2;

ll solve(void)
{
ll ret = 0;

ret += Wa[0];
ret += n * 2 - 1 - Wb.back();

for(ll i = 0 ; i < n - 1 ; i++)
{
	if(Wa[i + 1] <= Wb[i])
		continue;

	ret += abs(Wa[i + 1] - Wb[i]);
}

return ret;


}

int main(void)
{
fastio

cin >> n;
cin >> a;
cin >> b;

for(ll i = 0 ; i < n * 2 ; i++)
{
	if(a[i] == 'R')
		Wa.push_back(i);

	if(b[i] == 'R')
		Wb.push_back(i);
}

ll ans = solve();

swap(Wa, Wb);

ans = min(ans, solve());

cout << ans;
return 0;

}