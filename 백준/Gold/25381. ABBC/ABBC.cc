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

char a[300010];
ll len;
ll chk[300010];
deque<ll> cq, aq;
ll ans;

int main(void)
{
	fastio
	
	cin >> a;
	
	len = strlen(a);
	
	for(ll i = 0 ; i < len ; i++)
	{
		if(a[i] == 'C')
			cq.push_back(i);
		else if(a[i] == 'A')
			aq.push_back(i);
	}
	
	for(ll i = 0 ; i < len ; i++)
	{
		if(a[i] == 'B')
		{
			while(!cq.empty() && cq.front() < i)
				cq.pop_front();
			
			if(!cq.empty())
			{
				chk[i] = 1;
				cq.pop_front();
			}
		}
	}
	
	for(ll i = len - 1 ; i >= 0 ; i--)
	{
		if(a[i] == 'B')
		{
			if(chk[i])
				continue;
			
			while(!aq.empty() && aq.back() > i)
				aq.pop_back();
			
			if(!aq.empty())
			{
				chk[i] = 1;
				aq.pop_back();
			}
		}
	}
	
	for(ll i = 0 ; i < len ; i++)
		ans += chk[i];
	
	cout << ans;
	return 0;
}