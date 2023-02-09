#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
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
ll a[100010], b[100010], c[100010];
ll L1 = MIN, L2 = MIN, R1 = MAX, R2 = MAX;
ll chk[3];

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		chk[(a[i] + b[i] + c[i]) & 1]++;
	}
	
	if(chk[0] && chk[1])
	{
		cout << "NO";
		return 0;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		L1 = max(L1, a[i] + b[i] - c[i]);
		R1 = min(R1, a[i] + b[i] + c[i]);
		L2 = max(L2, a[i] - b[i] - c[i]);
		R2 = min(R2, a[i] - b[i] + c[i]);
	}
	
	if(L1 > R1 || L2 > R2)
	{
		cout << "NO";
		return 0;
	}
	
	cout << (L1 + L2) / 2 sp << (L1 - L2) / 2;
	return 0;
}