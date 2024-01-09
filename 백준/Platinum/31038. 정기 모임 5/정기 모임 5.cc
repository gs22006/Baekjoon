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

ll n;
ll all, bll;
vector<ll> vec[300010];
ll dist[300010], last[300010];

void f(ll here)
{
	queue<ll> q;
	
	for(ll i = 1 ; i <= n ; i++)
		dist[i] = last[i] = 0;
	
	q.push(here);
	dist[here] = 1;
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		for(auto &i : vec[qq])
		{
			if(dist[i])
				continue;
			
			dist[i] = dist[qq] + 1;
			last[i] = qq;
			q.push(i);
		}
	}
}

vector<ll> help;
ll chk[300010];

void fff(ll D, ll V)
{
	set<ll> st;
	vector<ll> now;
	ll gap = n - 1;
	
	for(ll i = 1 ; i <= n ; i++)
		chk[i] = 0;
	
	help.clear();
	help.push_back(V);
	now.push_back(V);
	chk[V] = 1;
	
	while(1)
	{
		vector<ll> tmp;
		
		for(auto &i : now)
		{
			for(auto &j : vec[i])
			{
				if(chk[j])
					continue;
				
				chk[j] = 1;
				tmp.push_back(j);
				st.insert(j);
			}
		}
		
		if((ll)st.empty())
			break;
		
		compress(tmp);
		now = tmp;
		gap -= (ll)tmp.size();
		
		if(gap <= 0)
			break;
		
		if(D == -1)
		{
			auto p = st.begin();
			ll gapp = (*p);
			st.erase(gapp);
			
			if(gapp > (ll)help.back())
				break;
			
			help.push_back(gapp);
		}
		
		else
		{
			auto p = st.rbegin();
			ll gapp = (*p);
			st.erase(gapp);
			
			if(gapp < (ll)help.back())
				break;
			
			help.push_back(gapp);
		}
		
		D *= -1;
	}
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	f(1);
	
	ll maxx = 0, w = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(maxx < dist[i])
		{
			maxx = dist[i];
			w = i;
		}
	}
	
	f(w);
	
	maxx = 0, w = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(maxx < dist[i])
		{
			maxx = dist[i];
			w = i;
		}
	}
	
	vector<ll> tmp;
	
	while(w)
	{
		tmp.push_back(w);
		w = last[w];
	}
	
	ll V = tmp[(ll)tmp.size() / 2];
	
	fff(1, V);
	vector<ll> ans1 = help;
	
	fff(-1, V);
	vector<ll> ans2 = help;
	
	if((ll)ans1.size() < (ll)ans2.size())
		swap(ans1, ans2);
	
	cout << (ll)ans1.size() en;
	
	for(auto &i : ans1)
		cout << i sp;
	
	return 0;
}