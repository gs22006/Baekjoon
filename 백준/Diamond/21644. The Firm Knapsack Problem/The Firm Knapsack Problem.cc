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
ll n, W;
pair<pll, ll> a[100010];

bool comp(pair<pll, ll> X, pair<pll, ll> Y)
{
	return X.fi.se * Y.fi.fi > Y.fi.se * X.fi.fi;
}

bool comp2(pair<pll, ll> X, pair<pll, ll> Y)
{
	return X.fi.fi < Y.fi.fi;
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n >> W;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			cin >> a[i].fi.fi >> a[i].fi.se;
			a[i].se = i;
		}
		
		vector< pair<pll, ll> > vec1, vec2;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			if(a[i].fi.fi * 2 <= W)
				vec1.push_back(a[i]);
			else
				vec2.push_back(a[i]);
		}
		
		vec2.push_back({{0, 0}, 0});
		
		sort(vec1.begin(), vec1.end(), comp);
		sort(vec2.begin(), vec2.end(), comp2);
		reverse(vec2.begin(), vec2.end());
		
		ll p = 0, hap = 0, Whap = 0;
		ll maxx = 0, P = 0, I = 0;
		
		for(auto &i : vec2)
		{
			ll sum = i.fi.se;
			
			if(i.fi.fi * 2 > W * 3)
				continue;
			
			while(p < (ll)vec1.size() && (i.fi.fi + Whap + vec1[p].fi.fi) * 2 <= W * 3)
			{
				Whap += vec1[p].fi.fi;
				hap += vec1[p].fi.se;
				p++;
			}
			
			if(maxx < sum + hap)
			{
				maxx = sum + hap;
				P = p;
				I = i.se;
			}
		}
		
		vector<ll> ans;
		
		if(I != 0)
			ans.push_back(I);
		
		for(ll i = 0 ; i < P ; i++)
			ans.push_back(vec1[i].se);
		
		cout << (ll)ans.size() en;
		
		for(auto &i : ans)
			cout << i sp;
		
		cout en;
	}
	
	return 0;
}