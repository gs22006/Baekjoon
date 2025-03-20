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

ll n, K;
string A, B;
ll ans;
deque< pair<pll, ll> > dq;

int main(void)
{
	fastio
	
	cin >> n >> K;
	cin >> A;
	cin >> B;
	
	for(ll i = 0 ; i < n ; i++)
	{
		while(!dq.empty())
		{
			pair<pll, ll> qq = dq.front();
			
			if(qq.fi.fi < i)
			{
				dq.pop_front();
				qq.fi.fi += K;
				ans += qq.fi.se;
				dq.push_back(qq);
			}
			
			else
				break;
		}
		
		if(A[i] == B[i])
			continue;
		
		if(!dq.empty())
		{
			if(dq.front().se == A[i] - '0')
			{
				pair<pll, ll> qq = dq.front();
				
				if(qq.fi.fi == i)
				{
					dq.pop_front();
					dq.push_front({{qq.fi.fi, qq.fi.se + 1}, qq.se});
				}
				
				else
					dq.push_front({{i, 1}, A[i] - '0'});
			}
			
			else
			{
				pair<pll, ll> qq = dq.front();
				dq.pop_front();
				
				if(qq.fi.se > 1)
				{
					qq.fi.se--;
					dq.push_front(qq);
				}
			}
		}
		
		else
			dq.push_front({{i, 1}, A[i] - '0'});
	}
	
	cout << ans;
	return 0;
}