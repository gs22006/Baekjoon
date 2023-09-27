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
ll a[100010];
ll m;
ll sq, sq2;
ll nu[100010];
ll idx[200010];
vector<ll> w[200010];
ll cou[200010], cou2[200010];
ll lf[200010], rg[200010];
ll s, e;
ll ans[100010];

struct gujo
{
	ll L, R;
	ll num;
	
	bool operator < (const gujo &xx) const
	{
		if(L / sq != xx.L / sq)
			return L / sq < xx.L / sq;
		
		return R < xx.R;
	}
};

gujo qry[100010];

void add(ll X)
{
	if(lf[nu[X]] <= rg[nu[X]])
	{
		cou[w[nu[X]][rg[nu[X]]] - w[nu[X]][lf[nu[X]]]]--;
		cou2[(w[nu[X]][rg[nu[X]]] - w[nu[X]][lf[nu[X]]]) / sq2]--;
	}
	
	lf[nu[X]] = min(lf[nu[X]], idx[X]);
	rg[nu[X]] = max(rg[nu[X]], idx[X]);
	
	if(lf[nu[X]] <= rg[nu[X]])
	{
		cou[w[nu[X]][rg[nu[X]]] - w[nu[X]][lf[nu[X]]]]++;
		cou2[(w[nu[X]][rg[nu[X]]] - w[nu[X]][lf[nu[X]]]) / sq2]++;
	}
}

void del(ll X)
{
	if(lf[nu[X]] <= rg[nu[X]])
	{
		cou[w[nu[X]][rg[nu[X]]] - w[nu[X]][lf[nu[X]]]]--;
		cou2[(w[nu[X]][rg[nu[X]]] - w[nu[X]][lf[nu[X]]]) / sq2]--;
	}
	
	if(w[nu[X]][lf[nu[X]]] == X)
		lf[nu[X]]++;
	
	if(w[nu[X]][rg[nu[X]]] == X)
		rg[nu[X]]--;
	
	if(lf[nu[X]] <= rg[nu[X]])
	{
		cou[w[nu[X]][rg[nu[X]]] - w[nu[X]][lf[nu[X]]]]++;
		cou2[(w[nu[X]][rg[nu[X]]] - w[nu[X]][lf[nu[X]]]) / sq2]++;
	}
}

void moveS(ll QL)
{
	while(s < QL)
	{
		del(s);
		s++;
	}
	
	while(QL < s)
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
	
	while(QR < e)
	{
		del(e);
		e--;
	}
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		nu[i] = nu[i - 1] + a[i];
	}
	
	cin >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> qry[i].L >> qry[i].R;
		
		qry[i].num = i;
		qry[i].L--;
	}
	
	sq = n / sqrt(m) + 1;
	sq2 = sqrt(200000);
	
	sort(qry + 1, qry + 1 + m);
	
	for(ll i = 0 ; i <= n ; i++)
	{
		nu[i] += 100000;
		idx[i] = (ll)w[nu[i]].size();
		w[nu[i]].push_back(i);
	}
	
	s = e = 0;
	cou[0] = n;
	cou2[0] = n;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(e < qry[i].R)
		{
			moveE(qry[i].R);
			moveS(qry[i].L);
		}
		
		else
		{
			moveS(qry[i].L);
			moveE(qry[i].R);
		}
		
		for(ll j = 200000 / sq2 + 1 ; j >= 0 ; j--)
		{
			if(cou2[j])
			{
				ll siz = min(200000LL, (j + 1) * sq2 - 1);
				
				for(ll k = siz ; k >= j * sq2 ; k--)
				{
					if(cou[k])
					{
						ans[qry[i].num] = k;
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