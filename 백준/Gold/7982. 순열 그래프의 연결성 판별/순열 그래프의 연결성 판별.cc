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

ll n;
ll a[1000010];
priority_queue< pair<ll, ll> > pq;
ll last = 1;
ll pa[1000010], ra[1000010];
ll maxx = 0, w = 0;
vector<ll> ans[1000010];
ll chk[1000010];
set<ll> st;

ll ffind(ll here)
{
	if(here == pa[here])
		return here;
	
	return pa[here] = ffind(pa[here]);
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	if(X == Y)
		return;
	
	if(ra[X] < ra[Y])
		pa[X] = Y;
	else if(ra[Y] < ra[X])
		pa[Y] = X;
	
	else
	{
		pa[X] = Y;
		ra[Y]++;
	}
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		pa[i] = i;
	}
	
	for(ll i = 1 ; i <= n ; i++)
		pq.push({-a[i], i});
	
	while(!pq.empty())
	{
		pair<ll, ll> qq = pq.top();
		pq.pop();
		
		if(qq.se < last)
			continue;
		
		vector<ll> tmp;
		
		if(maxx > -qq.fi)
			uunion(w, qq.se);
		
		for(ll i = last ; i <= (ll)qq.se ; i++)
		{
			uunion(last, i);
			
			if(maxx < a[i])
			{
				maxx = a[i];
				w = i;
			}
		}
		
		last = qq.se + 1;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ans[ffind(i)].push_back(i);
		st.insert(ffind(i));
	}
	
	cout << (ll)st.size() en;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!chk[ffind(i)])
		{
			chk[ffind(i)] = 1;
			
			cout << (ll)ans[ffind(i)].size() sp;
			
			for(auto &j : ans[ffind(i)])
				cout << j sp;
			
			cout en;
		}
	}
	
	return 0;
}