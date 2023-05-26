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

char a[600010];
ll len;
long long dp[600010];

struct node
{
	ll adj[26] = {0, };
	ll suffixlink = 0;
	ll LEN = 0, COU = 0;
};

struct eertree
{
	vector<node> eer;
	ll pos = 0;
	
	void init(void)
	{
		node tmp;
		
		tmp.suffixlink = 0;
		tmp.LEN = -1;
		tmp.COU = 1;
		
		eer.push_back(tmp);
		
		tmp.suffixlink = 0;
		tmp.LEN = 0;
		tmp.COU = 1;
		
		eer.push_back(tmp);
	}
	
	void add(ll I)
	{
		while(1)
		{
			if(I - eer[pos].LEN - 1 >= 0 && a[I] == a[I - eer[pos].LEN - 1])
				break;
			
			pos = eer[pos].suffixlink;
		}
		
		if(eer[pos].adj[a[I] - 'a'])
		{
			pos = eer[pos].adj[a[I] - 'a'];
			eer[pos].COU++;
			
			return;
		}
		
		node tmp;
		
		eer[pos].adj[a[I] - 'a'] = (ll)eer.size();
		
		tmp.LEN = eer[pos].LEN + 2;
		tmp.COU = 1;
		
		if(tmp.LEN == 1)
			tmp.suffixlink = 1;
		
		else
		{
			pos = eer[pos].suffixlink;
			
			while(1)
			{
				if(I - eer[pos].LEN - 1 >= 0 && a[I] == a[I - eer[pos].LEN - 1])
					break;
				
				pos = eer[pos].suffixlink;
			}
			
			if(!eer[pos].adj[a[I] - 'a'])
				assert(0);
			
			tmp.suffixlink = eer[pos].adj[a[I] - 'a'];
		}
		
		pos = (ll)eer.size();
		eer.push_back(tmp);
	}
}eert;

vector<ll> vec[600010];
ll siz;
long long ans;

void dfs(ll here, ll pa)
{
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs(i, here);
		dp[here] += dp[i];
	}
}

int main(void)
{
	fastio
	
	cin >> a;
	
	len = strlen(a);
	eert.init();
	
	for(ll i = 0 ; i < len ; i++)
		eert.add(i);
	
	siz = (ll)eert.eer.size();
	
	for(ll i = 1 ; i < siz ; i++)
		vec[eert.eer[i].suffixlink].push_back(i);
	
	for(ll i = 0 ; i < siz ; i++)
		dp[i] = eert.eer[i].COU;
	
	dfs(0, -1);
	
	for(ll i = 0 ; i < siz ; i++)
		ans = max(ans, (long long)eert.eer[i].LEN * dp[i]);
	
	cout << ans;
	return 0;
}