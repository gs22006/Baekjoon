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

string S;
ll n;
string all;

struct suffixautomaton
{
	ll last;
	
	struct node
	{
		ll ln, lk, nx[30];
	}emp;
	
	vector<node> SAM;
	
	void push(ll ln, ll lk)
	{
		SAM.push_back(emp);
		SAM.back().ln = ln;
		SAM.back().lk = lk;
		
		for(ll i = 1 ; i <= 26 ; i++)
			SAM.back().nx[i] = -1;
	}
	
	void init(void)
	{
		push(0, -1);
	}
	
	void extend(ll c)
	{
		ll cur = (ll)SAM.size();
		
		push(0, -1);
		SAM[cur].ln = SAM[last].ln + 1;
		
		ll p = last;
		
		while(p != -1 && SAM[p].nx[c] == -1)
		{
			SAM[p].nx[c] = cur;
			p = SAM[p].lk;
		}
		
		if(p == -1)
			SAM[cur].lk = 0;
		
		else
		{
			ll q = SAM[p].nx[c];
			
			if(SAM[q].ln == SAM[p].ln + 1)
				SAM[cur].lk = q;
			
			else
			{
				ll cl = (ll)SAM.size();
				
				SAM.push_back(SAM[q]);
				SAM[cl].ln = SAM[p].ln + 1;
				
				while(p != -1 && SAM[p].nx[c] == q)
				{
					SAM[p].nx[c] = cl;
					p = SAM[p].lk;
				}
				
				SAM[q].lk = SAM[cur].lk = cl;
			}
		}
		
		last = cur;
	}
}sam;

int main(void)
{
	fastio
	
	cin >> S;
	
	sam.init();
	
	for(auto &i : S)
		sam.extend(i - 'A' + 1);
	
	cin >> n;
	
	while(n--)
	{
		ll ans = 1, now = 0;
		
		cin >> all;
		
		for(auto &i : all)
		{
			if(sam.SAM[now].nx[i - 'A' + 1] == -1)
			{
				if(sam.SAM[0].nx[i - 'A' + 1] == -1)
				{
					ans = -1;
					break;
				}
				
				ans++;
				now = sam.SAM[0].nx[i - 'A' + 1];
			}
			
			else
				now = sam.SAM[now].nx[i - 'A' + 1];
		}
		
		cout << ans en;
	}
	
	return 0;
}