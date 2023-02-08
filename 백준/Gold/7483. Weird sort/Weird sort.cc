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
ll all;

int main(void)
{
	fastio
	
	while(1)
	{
		vector<ll> vec, ans;
		map<ll, ll> cou;
		
		cin >> n;
		
		if(!n)
			break;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			cin >> all;
			
			vec.push_back(all);
			cou[all]++;
		}
		
		compress(vec);
		
		priority_queue< pair<ll, ll> > pq;
		
		for(auto &i : vec)
			pq.push({-i, cou[i]});
		
		ans.push_back(-INF);
		
		while(!pq.empty())
		{
			pair<ll, ll> qq = pq.top();
			pq.pop();
			
			if(ans.back() + 1 != -qq.fi)
			{
				ans.push_back(-qq.fi);
				qq.se--;
				
				if(qq.se)
					pq.push(qq);
				
				continue;
			}
			
			if(pq.empty())
			{
				pq.push(qq);
				break;
			}
			
			pair<ll, ll> qqq = pq.top();
			pq.pop();
			
			ans.push_back(-qqq.fi);
			qqq.se--;
			
			if(qqq.se)
				pq.push(qqq);
			
			if(qq.se)
				pq.push(qq);
		}
		
		if(!pq.empty())
		{
			ll siz = (ll)ans.size();
			ll w = 0;
			pair<ll, ll> tp = pq.top();
			
			for(ll i = siz - 1 ; i >= 0 ; i--)
			{
				if(ans[i] == ans.back())
					w = i;
				else
					break;
			}
			
			w--;
			
			for(ll i = 1 ; i <= w ; i++)
				cout << ans[i] sp;
			
			for(ll i = 0 ; i < tp.se ; i++)
				cout << -tp.fi sp;
			
			for(ll i = w + 1 ; i < siz ; i++)
				cout << ans[i] sp;
			
			cout en;
		}
		
		else
		{
			ll siz = (ll)ans.size();
			
			for(ll i = 1 ; i < siz ; i++)
				cout << ans[i] sp;
			
			cout en;
		}
	}
	
	return 0;
}