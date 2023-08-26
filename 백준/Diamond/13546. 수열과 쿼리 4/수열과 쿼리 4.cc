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

ll n, K;
ll a[1000010];
ll m;
ll sq, sq2;
vector<ll> w[1000010];
ll idx[1000010];
ll cou[1000010], cou2[1000010];
ll lf[1000010], rg[1000010];
ll s, e;
ll ans[1000010];

struct Query
{
	ll L, R;
	ll num;
	
	bool operator < (const Query &xx) const
	{
		if(L / sq == xx.L / sq)
			return R < xx.R;
		
		return L / sq < xx.L / sq;
	}
};

Query Q[1000010];

void add(ll X)
{
	if(lf[a[X]] <= rg[a[X]])
	{
		cou[w[a[X]][rg[a[X]]] - w[a[X]][lf[a[X]]]]--;
		cou2[(w[a[X]][rg[a[X]]] - w[a[X]][lf[a[X]]]) / sq2]--;
	}
	
	lf[a[X]] = min(lf[a[X]], idx[X]);
	rg[a[X]] = max(rg[a[X]], idx[X]);
	
	cou[w[a[X]][rg[a[X]]] - w[a[X]][lf[a[X]]]]++;
	cou2[(w[a[X]][rg[a[X]]] - w[a[X]][lf[a[X]]]) / sq2]++;
}

void del(ll X)
{
	cou[w[a[X]][rg[a[X]]] - w[a[X]][lf[a[X]]]]--;
	cou2[(w[a[X]][rg[a[X]]] - w[a[X]][lf[a[X]]]) / sq2]--;
	
	if(w[a[X]][lf[a[X]]] == X)
		lf[a[X]]++;
	
	if(w[a[X]][rg[a[X]]] == X)
		rg[a[X]]--;
	
	if(lf[a[X]] <= rg[a[X]])
	{
		cou[w[a[X]][rg[a[X]]] - w[a[X]][lf[a[X]]]]++;
		cou2[(w[a[X]][rg[a[X]]] - w[a[X]][lf[a[X]]]) / sq2]++;
	}
}

void moveS(ll QL)
{
	while(s < QL)
	{
		del(s);
		s++;
	}
	
	while(s > QL)
	{
		s--;
		add(s);
	}
}

void moveE(ll QR)
{
	while(e < QR)
	{
		e++;
		add(e);
	}
	
	while(e > QR)
	{
		del(e);
		e--;
	}
}

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	cin >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> Q[i].L >> Q[i].R;
		Q[i].num = i;
	}
	
	sq = n / sqrt(m + 1) + 1;
	sq2 = sqrt(n + 1) + 1;
	
	sort(Q + 1, Q + 1 + m);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		idx[i] = (ll)w[a[i]].size();
		w[a[i]].push_back(i);
	}
	
	s = e = 1;
	cou[0] = K;
	cou2[0] = K;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(Q[i].R > e)
		{
			moveE(Q[i].R);
			moveS(Q[i].L);
		}
		
		else
		{
			moveS(Q[i].L);
			moveE(Q[i].R);
		}
		
		for(ll j = n / sq2 + 1 ; j >= 0 ; j--)
		{
			if(cou2[j])
			{
				ll siz = min(n + 1, (j + 1) * sq2);
				
				for(ll k = siz - 1 ; k >= j * sq2 ; k--)
				{
					if(cou[k])
					{
						ans[Q[i].num] = k;
						break;
					}
				}
				
				break;
			}
		}
	}
	
	for(ll i = 1 ; i <= m ; i++)
		cout << ans[i] en;
	
	return 0;
}