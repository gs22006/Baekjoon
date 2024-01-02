#include <bits/stdc++.h>

using namespace std;
typedef int ll;
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
ll n, m;
ll sum[10];
ll cc;
vector<ll> srt;

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		vector< vector<ll> > vec;
		
		cin >> n >> m;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			vector<ll> tmp;
			ll all;
			
			for(ll j = 0 ; j < m ; j++)
			{
				cin >> all;
				tmp.push_back(all);
			}
			
			vec.push_back(tmp);
		}
		
		srt.clear();
		
		for(ll j = 0 ; j < m ; j++)
			srt.push_back(j);
		
		ll maxx = 0;
		
		do
		{
			ll summ = 0;
			
			for(auto &i : vec)
			{
				ll gap = 0;
				ll now = 0;
				
				for(ll j = 0 ; j < m ; j++)
				{
					now += i[srt[j]];
					gap = max(gap, now);
				}
				
				summ += gap;
			}
			
			maxx = max(maxx, summ);
		}while(next_permutation(srt.begin(), srt.end()));
		
		cc++;
		cout << "Case #" << cc << ": ";
		cout << maxx en;
	}
	
	return 0;
}