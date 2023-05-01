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
ll A, B;
ll C, D;
pll a[100010];
ll chk[5010][5010];
ll tmp[5010][5010];

ll can_eat(ll X1, ll Y1, ll X2, ll Y2)
{
	set<pll> st;
	
	st.insert({X1, Y1});
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll nx = X1 + a[i].fi;
		ll ny = Y1 + a[i].se;
		
		if(nx <= 0 || ny <= 0 || nx > n || ny > n)
			continue;
		
		st.insert({nx, ny});
	}
	
	if(st.count({X2, Y2}))
		return 1;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll nx = X2 - a[i].fi;
		ll ny = Y2 - a[i].se;
		
		if(nx <= 0 || ny <= 0 || nx > n || ny > n)
			continue;
		
		if(st.count({nx, ny}))
			return 1;
	}
	
	return 0;
}

int main(void)
{
	fastio
	
	srand(time(NULL));
	
	cin >> n;
	cin >> A >> B;
	cin >> C >> D;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	
	if(can_eat(A, B, C, D))
	{
		cout << "Alice wins";
		return 0;
	}
	
	if(n <= 5000)
	{
		queue<pll> q;
		queue<ll> cq;
		
		chk[C][D] = 1;
		q.push({C, D});
		cq.push(0);
		
		while(!q.empty())
		{
			pll qq = q.front();
			q.pop();
			ll cc = cq.front();
			cq.pop();
			
			if(cc == 2)
				continue;
			
			for(ll i = 1 ; i <= n ; i++)
			{
				ll nx = qq.fi + a[i].fi;
				ll ny = qq.se + a[i].se;
				
				if(nx <= 0 || ny <= 0 || nx > n || ny > n)
					continue;
				
				if(chk[nx][ny])
					continue;
				
				chk[nx][ny] = 1;
				q.push({nx, ny});
				cq.push(cc + 1);
			}
		}
		
		pll ans = {-1, -1};
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
			{
				if(!chk[i][j])
					ans = {i, j};
			}
		}
		
		if(ans.fi == -1)
			cout << "Bob wins\n";
		else
			cout << "tie " << ans.fi sp << ans.se en;
	}
	
	else
	{
		for(ll o = 0 ; o < 100 ; o++)
		{
			ll X = rand() % n + 1;
			ll Y = rand() % n + 1;
			
			if(can_eat(C, D, X, Y))
				continue;
			
			cout << "tie " << X sp << Y en;
			return 0;
		}
		
		cout << "Bob wins\n";
	}
	
	return 0;
}