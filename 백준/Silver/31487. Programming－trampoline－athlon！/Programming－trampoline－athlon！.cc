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

struct gujo
{
	string C;
	ll sum, num;
	
	bool operator < (const gujo &x) const
	{
		if(sum == x.sum)
			return num < x.num;
		
		return sum > x.sum;
	}
};

ll n;
gujo a[100010];
ll P, E[10];

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].C >> P;
		
		for(ll j = 1 ; j <= 6 ; j++)
			cin >> E[j];
		
		sort(E + 1, E + 1 + 6);
		
		a[i].sum = P * 10 + E[2] + E[3] + E[4] + E[5];
		a[i].num = i;
	}
	
	sort(a + 1, a + 1 + n);
	
	ll sad = INF, last = 1, gaet = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i].sum < sad)
		{
			sad = a[i].sum;
			gaet += i - last;
			last = i;
		}
		
		if(gaet >= 3)
			break;
		
		cout << a[i].C sp << a[i].sum en;
	}
	
	return 0;
}