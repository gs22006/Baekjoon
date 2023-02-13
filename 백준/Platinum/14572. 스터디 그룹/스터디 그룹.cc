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

struct student
{
	ll d, siz;
	vector<ll> vec;
	
	bool operator < (const student &xx) const
	{
		return d < xx.d;
	}
};

ll n, K, D;
student a[100010];
ll p;
ll cou[50];
ll ans;

int main(void)
{
	fastio
	
	cin >> n >> K >> D;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll all;
		
		cin >> a[i].siz >> a[i].d;
		
		for(ll j = 0 ; j < a[i].siz ; j++)
		{
			cin >> all;
			a[i].vec.push_back(all);
		}
	}
	
	sort(a + 1, a + 1 + n);
	
	p = 1;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(p <= n && a[p].d - a[i].d <= D)
		{
			for(auto &j : a[p].vec)
				cou[j]++;
			
			p++;
		}
		
		ll gaet = p - i;
		ll gap = 0;
		
		for(ll j = 1 ; j <= K ; j++)
		{
			if(cou[j] != gaet && cou[j])
				gap += gaet;
		}
		
		ans = max(ans, gap);
		
		for(auto &j : a[i].vec)
			cou[j]--;
	}
	
	cout << ans;
	return 0;
}