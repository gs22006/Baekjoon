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
ll n;
ll gan[] = {4, 4, 6, 6, 4, 4, 6, 4, 4, 12};
ll chk[5000010], chk2[5000010];
ll now = 0;

int main(void)
{
	fastio
	
	cin >> t;
	
	for(ll i = 0 ; i < 10 ; i++)
	{
		now += gan[i];
		chk[now] = 1;
	}
	
	chk2[4] = 1;
	chk2[8] = 1;
	chk2[18] = 1;
	chk2[22] = 1;
	chk2[0] = 1;
	
	while(t--)
	{
		cin >> n;
		
		if(chk[n])
		{
			cout << "Platina\n";
			continue;
		}
		
		if(n >= now && chk2[(n - now) % 34])
		{
			cout << "Platina\n";
			continue;
		}
		
		cout << "Yuto\n";
	}
	
	return 0;
}