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

struct building
{
	ll L, H, R;
	
	bool operator < (const building &xx) const
	{
		return L < xx.L;
	}
};

ll n;
building a[100010];
priority_queue< pair<ll, ll> > pq;
ll p;
vector<ll> vec;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].L >> a[i].H >> a[i].R;
		
		vec.push_back(a[i].L);
		vec.push_back(a[i].R);
	}
	
	sort(a + 1, a + 1 + n);
	
	pq.push({0, 10000000000LL});
	compress(vec);
	
	ll last = 0;
	
	for(auto &i : vec)
	{
		while(p <= n && a[p].L <= i)
		{
			pq.push({a[p].H, a[p].R});
			p++;
		}
		
		while(!pq.empty() && pq.top().se <= i)
			pq.pop();
		
		if(pq.top().fi != last)
		{
			last = pq.top().fi;
			cout << i sp << last sp;
		}
	}
	
	return 0;
}