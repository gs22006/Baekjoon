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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

ll n;
ll a[1000010];
priority_queue<ll> pq;
ll gap[1000010];
ll nu[1000010];

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		gap[i] = -1;
	}
	
	pq.push(-a[1]);
	
	for(ll i = 2 ; i <= n ; i += 2)
	{
		gap[-pq.top()] = 1;
		pq.pop();
		pq.push(-a[i]);
		pq.push(-a[i + 1]);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		nu[i] = nu[i - 1] + gap[i];
		
		if(nu[i] < 0)
		{
			cout << "NIE";
			return 0;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(gap[i] == 1)
			cout << "(";
		else
			cout << ")";
	}
	
	return 0;
}