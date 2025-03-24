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

ll n, m;
string a[210];
ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1}; //UDLR
ll sl[] = {3, 2, 1, 0};
ll ysl[] = {2, 3, 0, 1};
vector< pair<pll, pair<char, ll> > > vec;
vector< pair<char, ll> > ans;
ll mir;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 0 ; i < n ; i++)
		cin >> a[i];
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < m ; j++)
		{
			if(a[i][j] != '.')
				mir++;
		}
	}
	
	for(ll i = 0 ; i < m ; i++)
	{
		vec.push_back({{0, i}, {'N', 1}});
		vec.push_back({{n - 1, i}, {'S', 0}});
	}
	
	for(ll i = 0 ; i < n ; i++)
	{
		vec.push_back({{i, 0}, {'W', 3}});
		vec.push_back({{i, m - 1}, {'E', 2}});
	}
	
	for(auto &S : vec)
	{
		ll X = S.fi.fi;
		ll Y = S.fi.se;
		ll D = S.se.se;
		unordered_set<ll> st;
		
		while(1)
		{
			if(X < 0 || Y < 0 || X >= n || Y >= m)
				break;
			
			if(a[X][Y] != '.')
			{
				st.insert(X * m + Y);
				
				if(a[X][Y] == '/')
					D = sl[D];
				else
					D = ysl[D];
			}
			
			X += dx[D];
			Y += dy[D];
		}
		
		if((ll)st.size() == mir)
		{
			if(S.se.se <= 1)
				ans.push_back({S.se.fi, S.fi.se});
			else
				ans.push_back({S.se.fi, S.fi.fi});
		}
	}
	
	cout << (ll)ans.size() en;
	
	for(auto &i : ans)
		cout << i.fi << i.se + 1 sp;
	
	return 0;
}