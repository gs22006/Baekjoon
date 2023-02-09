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

ll n, m;
ll q;
string all;
ll chk[4010];

struct TRIE
{
	map<ll, ll> chld[4000010];
	ll is_end[4000010];
	ll cc = 0;
	
	void update(string X)
	{
		ll w = 0;
		
		for(auto &i : X)
		{
			if(chld[w].find(i - 'a') != chld[w].end())
				w = chld[w][i - 'a'];
			else
				w = chld[w][i - 'a'] = ++cc;
		}
		
		is_end[w] = 1;
	}
}trie1, trie2;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all;
		trie1.update(all);
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all;
		
		reverse(all.begin(), all.end());
		trie2.update(all);
	}
	
	cin >> q;
	
	while(q--)
	{
		cin >> all;
		
		ll len = (ll)all.length();
		ll w = 0;
		ll ff = 0;
		
		for(ll i = 0 ; i <= len ; i++)
			chk[i] = 0;
		
		for(ll i = 0 ; i < len ; i++)
		{
			if(trie1.chld[w].find(all[i] - 'a') != trie1.chld[w].end())
				w = trie1.chld[w][all[i] - 'a'];
			else
				break;
			
			if(trie1.is_end[w])
				chk[i + 1] = 1;
		}
		
		reverse(all.begin(), all.end());
		
		w = 0;
		
		for(ll i = 0 ; i < len ; i++)
		{
			if(trie2.chld[w].find(all[i] - 'a') != trie2.chld[w].end())
				w = trie2.chld[w][all[i] - 'a'];
			else
				break;
			
			if(trie2.is_end[w] && chk[len - i - 1])
			{
				ff = 1;
				break;
			}
		}
		
		if(ff)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	
	return 0;
}