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
string S, S2;
vector<ll> vec;
ll now = -1, cou;
ll ff;
ll a[1000010];
pll rng[1000010];
ll last;
ll ans[1000010], ansp[1000010];
ll nu1[1000010], nu2[1000010];
ll siz;

void solve(void)
{
	for(ll i = 0 ; i < siz ; i++)
		a[i + 1] = vec[i];
	
	for(ll i = 1 ; i <= siz ; i++)
	{
		nu1[i] = nu1[i - 1];
		nu2[i] = nu2[i - 1];
		
		if(a[i] == 1)
			nu1[i]++;
		else
			nu2[i]++;
	}
	
	last = -1;
	
	for(ll i = 1 ; i <= siz ; i++)
	{
		if(a[i] == 1)
		{
			if(last == -1)
				last = i;
			
			rng[i].fi = last;
		}
		
		else
			last = -1;
	}
	
	last = -1;
	
	for(ll i = siz ; i >= 1 ; i--)
	{
		if(a[i] == 1)
		{
			if(last == -1)
				last = i;
			
			rng[i].se = last;
		}
		
		else
			last = -1;
	}
	
	pll gu = make_pair(1, 0);
	queue<pll> q;
	
	for(ll i = 1 ; i <= siz ; i++)
	{
		while(!q.empty() && q.front().se < i)
		{
			if(gu.se - gu.fi < q.front().se - q.front().fi)
				gu = q.front();
			
			q.pop();
		}
		
		ll L, R;
		
		ans[i] = 1;
		
		if(a[1] == 1)
		{
			L = 1;
			R = min(i, rng[1].se);
			
			if(R - L + 1 > nu1[i] - nu1[R] + max(0LL, nu2[i] - nu2[R] - 1))
				ans[i] = 0;
		}
		
		if(a[i] == 1)
		{
			L = rng[i].fi;
			R = i;
			
			if(R - L + 1 > nu1[L - 1] + max(0LL, nu2[L - 1] - 1))
				ans[i] = 0;
		}
		
		if(gu.fi != 0)
		{
			L = gu.fi;
			R = gu.se;
			
			if(R - L + 1 > nu1[L - 1] + nu1[i] - nu1[R] + max(0LL, nu2[L - 1] - 1) + max(0LL, nu2[i] - nu2[R] - 1))
				ans[i] = 0;
		}
		
		if(rng[i].fi > 1)
			q.push(rng[i]);
	}
}

int main(void)
{
	fastio
	
	cin >> n;
	cin >> S;
	
	for(auto &i : S)
	{
		if(i == '.')
			continue;
		
		S2.push_back(i);
	}
	
	S = S2;
	S.push_back('.');
	
	for(auto &i : S)
	{
		if(i == '.')
		{
			if(cou)
				vec.push_back(min(2LL, cou));
			
			now = -1;
			cou = 0;
		}
		
		else if(i == 'B')
		{
			if(now == 1)
			{
				vec.push_back(min(2LL, cou));
				cou = 0;
			}
			
			now = 2;
			cou++;
		}
		
		else
		{
			if(now == 2)
			{
				vec.push_back(min(2LL, cou));
				cou = 0;
			}
			
			now = 1;
			cou++;
		}
	}
	
	siz = (ll)vec.size();
	
	solve();
	
	for(ll i = 1 ; i <= siz ; i++)
		ansp[i] = ans[i];
	
	reverse(vec.begin(), vec.end());
	solve();
	
	if(siz & 1)
	{
		if(ansp[siz])
			cout << "YES";
		else
			cout << "NO";
	}
	
	else
	{
		for(ll i = 1 ; i < siz ; i++)
		{
			if((i & 1) && ansp[i] && ans[siz - i])
			{
				cout << "YES";
				return 0;
			}
		}
		
		cout << "NO";
	}
	
	return 0;
}