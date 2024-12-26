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

ll n, A, B, C, D;
ll X[200010], Y[200010];
ll minX = INF, minY = INF;
ll gaet, sum, p;

int main(void)
{
	fastio
	
	cin >> n >> A >> B >> C >> D;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> X[i] >> Y[i];
	
	sort(X + 1, X + 1 + n);
	sort(Y + 1, Y + 1 + n);
	
	gaet = sum = 0;
	p = 1;
	
	for(ll i = 1 ; i <= n ; i++)
		sum += A * (X[i] + 1000000);
	
	for(ll i = -1000000 ; i <= 1000001 ; i++)
	{
		while(p <= n && X[p] <= i)
		{
			gaet++;
			p++;
		}
		
		minX = min(minX, sum);
		sum += gaet * B;
		sum -= (n - gaet) * A;
	}
	
	gaet = sum = 0;
	p = 1;
	
	for(ll i = 1 ; i <= n ; i++)
		sum += C * (Y[i] + 1000000);
	
	for(ll i = -1000000 ; i <= 1000001 ; i++)
	{
		while(p <= n && Y[p] <= i)
		{
			gaet++;
			p++;
		}
		
		minY = min(minY, sum);
		sum += gaet * D;
		sum -= (n - gaet) * C;
	}
	
	cout << minX + minY;
	return 0;
}