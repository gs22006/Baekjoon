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

struct circle
{
	ll A, B, R;
};

ll t;
ll n;
circle a[110];
vector< pair< pair<ld, ld>, ll> > vec;
ld PI = 3.14159265358979;

ll dist(ll X, ll Y)
{
	return (a[X].A - a[Y].A) * (a[X].A - a[Y].A) + (a[X].B - a[Y].B) * (a[X].B - a[Y].B);
}

ll buho(ld X)
{
	if(X > 0)
		return 1;
	else if(!X)
		return 0;
	
	return -1;
}

pair<ld, ld> gyo(ld A1, ld B1, ld A2, ld B2)
{
	pair<ld, ld> ret;
	
	ret.fi = (B2 - B1) / (A1 - A2);
	ret.se = A1 * ret.fi + B1;
	
	return ret;
}

ld ccw(pair<ld, ld> X, pair<ld, ld> Y, pair<ld, ld> Z)
{
	return X.fi * Y.se + Y.fi * Z.se + Z.fi * X.se - X.se * Y.fi - Y.se * Z.fi - Z.se * X.fi;
}

vector< pair< pair<ld, ld>, ll> > getcvh(vector< pair< pair<ld, ld>, ll> > X)
{
	vector< pair< pair<ld, ld>, ll> > ret;
	vector< pair< pair<ld, ld>, ll> > h1, h2;
	vector< pair< pair<ld, ld>, ll> > ttmp;
	
	sort(X.begin(), X.end());
	
	for(ll i = 0 ; i < (ll)X.size() ; i++)
	{
		if(i && X[i] == X[i - 1])
			continue;
		
		ttmp.push_back(X[i]);
	}
	
	X = ttmp;
	ll sz = (ll)X.size();
	
	h1.push_back(X[0]);
	h1.push_back(X[1]);
	
	for(ll i = 2 ; i < sz ; i++)
	{
		while(1)
		{
			ll siz = (ll)h1.size();
			
			if(siz < 2 || ccw(h1[siz - 2].fi, h1[siz - 1].fi, X[i].fi) > 0)
				break;
			
			h1.pop_back();
		}
		
		h1.push_back(X[i]);
	}
	
	h2.push_back(X[sz - 1]);
	h2.push_back(X[sz - 2]);
	
	for(ll i = sz - 3 ; i >= 0 ; i--)
	{
		while(1)
		{
			ll siz = (ll)h2.size();
			
			if(siz < 2 || ccw(h2[siz - 2].fi, h2[siz - 1].fi, X[i].fi) > 0)
				break;
			
			h2.pop_back();
		}
		
		h2.push_back(X[i]);
	}
	
	for(auto &i : h1)
		ret.push_back(i);
	
	for(auto &i : h2)
	{
		if(ret.back() == i)
			continue;
		
		ret.push_back(i);
	}
	
	ret.pop_back();
	return ret;
}

void getpnt(ll X, ll Y, ld M)
{
	ll a1 = a[X].A;
	ll a2 = a[Y].A;
	ll b1 = a[X].B;
	ll b2 = a[Y].B;
	ll r1 = a[X].R;
	ll r2 = a[Y].R;
	
	if(M == 0)
	{
		if(r1 + b1 == r2 + b2)
		{
			vec.push_back({{a1, r1 + b1}, X});
			vec.push_back({{a2, r2 + b2}, Y});
		}
		
		if(b1 - r1 == b2 - r2)
		{
			vec.push_back({{a1, b1 - r1}, X});
			vec.push_back({{a2, b2 - r2}, Y});
		}
		
		return;
	}
	
	if(r1 == r2)
	{
		ld A1 = M;
		ld B1 = (ld)r1 * sqrt(M * M + 1) + (ld)b1 - M * (ld)a1;
		ld A2 = M;
		ld B2 = (ld)r2 * sqrt(M * M + 1) + (ld)b2 - M * (ld)a2;
		ld A3 = -1.0 / M;
		ld B3 = -A3 * (ld)a1 + (ld)b1;
		ld A4 = -1.0 / M;
		ld B4 = -A4 * (ld)a2 + (ld)b2;
		
		vec.push_back({gyo(A1, B1, A3, B3), X});
		vec.push_back({gyo(A2, B2, A4, B4), Y});
		
		A1 = M;
		B1 = (ld)(-r1) * sqrt(M * M + 1) + (ld)b1 - M * (ld)a1;
		A2 = M;
		B2 = (ld)(-r2) * sqrt(M * M + 1) + (ld)b2 - M * (ld)a2;
		A3 = -1.0 / M;
		B3 = -A3 * (ld)a1 + (ld)b1;
		A4 = -1.0 / M;
		B4 = -A4 * (ld)a2 + (ld)b2;
		
		vec.push_back({gyo(A1, B1, A3, B3), X});
		vec.push_back({gyo(A2, B2, A4, B4), Y});
	}
	
	if(buho(r1 - r2) == buho(M * (ld)(a1 - a2) - (ld)(b1 - b2)))
	{
		ld A1 = M;
		ld B1 = (ld)r1 * sqrt(M * M + 1) + (ld)b1 - M * (ld)a1;
		ld A2 = M;
		ld B2 = (ld)r2 * sqrt(M * M + 1) + (ld)b2 - M * (ld)a2;
		ld A3 = -1.0 / M;
		ld B3 = -A3 * (ld)a1 + (ld)b1;
		ld A4 = -1.0 / M;
		ld B4 = -A4 * (ld)a2 + (ld)b2;
		
		vec.push_back({gyo(A1, B1, A3, B3), X});
		vec.push_back({gyo(A2, B2, A4, B4), Y});
	}
	
	if(buho(r2 - r1) == buho(M * (ld)(a1 - a2) - (ld)(b1 - b2)))
	{
		ld A1 = M;
		ld B1 = (ld)(-r1) * sqrt(M * M + 1) + (ld)b1 - M * (ld)a1;
		ld A2 = M;
		ld B2 = (ld)(-r2) * sqrt(M * M + 1) + (ld)b2 - M * (ld)a2;
		ld A3 = -1.0 / M;
		ld B3 = -A3 * (ld)a1 + (ld)b1;
		ld A4 = -1.0 / M;
		ld B4 = -A4 * (ld)a2 + (ld)b2;
		
		vec.push_back({gyo(A1, B1, A3, B3), X});
		vec.push_back({gyo(A2, B2, A4, B4), Y});
	}
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		vec.clear();
		
		cin >> n;
		
		for(ll i = 1 ; i <= n ; i++)
			cin >> a[i].A >> a[i].B >> a[i].R;
		
		if(n == 1)
		{
			cout << (ld)a[1].R * 2.0 * PI en;
			continue;
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = i + 1 ; j <= n ; j++)
			{
				ll a1 = a[i].A;
				ll a2 = a[j].A;
				ll b1 = a[i].B;
				ll b2 = a[j].B;
				ll r1 = a[i].R;
				ll r2 = a[j].R;
				ll aa, bb, cc;
				ld m;
				
				if(dist(i, j) <= (r1 - r2) * (r1 - r2))
					continue;
				
				if(a1 + r1 == a2 + r2)
				{
					vec.push_back({{a1 + r1, b1}, i});
					vec.push_back({{a2 + r2, b2}, j});
				}
				
				if(a1 - r1 == a2 - r2)
				{
					vec.push_back({{a1 - r1, b1}, i});
					vec.push_back({{a2 - r2, b2}, j});
				}
				
				aa = (r1 - r2) * (r1 - r2) - (a1 - a2) * (a1 - a2);
				bb = 2 * (a1 - a2) * (b1 - b2);
				cc = (r1 - r2) * (r1 - r2) - (b1 - b2) * (b1 - b2);
				
				if(aa == 0)
				{
					if(bb)
						getpnt(i, j, -(ld)cc / (ld)bb);
				}
				
				else
				{
					if(bb * bb - 4 * aa * cc >= 0)
					{
						m = (-(ld)bb + (ld)sqrt((ld)bb * bb - 4 * aa * cc)) / (ld)(2 * aa);
						getpnt(i, j, m);
						m = (-(ld)bb - (ld)sqrt((ld)bb * bb - 4 * aa * cc)) / (ld)(2 * aa);
						getpnt(i, j, m);
					}
				}
			}
		}
		
		vector< pair< pair<ld, ld>, ll> > cvh = getcvh(vec);
		
		ll sizz = (ll)cvh.size();
		ld ans = 0;
		
		cvh.push_back(cvh[0]);
		
		for(ll i = 0 ; i < sizz ; i++)
		{
			if(cvh[i].se == cvh[i + 1].se)
			{
				ll num = cvh[i].se;
				ld xcha = cvh[i].fi.fi - (ld)a[num].A;
				ld ycha = cvh[i].fi.se - (ld)a[num].B;
				ld xx = (ld)a[num].A - xcha;
				ld yy = (ld)a[num].B - ycha;
				
				if(xx == cvh[i + 1].fi.fi && yy == cvh[i + 1].fi.se)
				{
					ans += (ld)a[num].R * PI;
					continue;
				}
				
				ld gak = (2.0 * a[num].R * a[num].R - (ld)(cvh[i].fi.fi - cvh[i + 1].fi.fi) * (cvh[i].fi.fi - cvh[i + 1].fi.fi) - (ld)(cvh[i].fi.se - cvh[i + 1].fi.se) * (cvh[i].fi.se - cvh[i + 1].fi.se)) / (2.0 * a[num].R * a[num].R);
				
				gak = acos(gak);
				
				if(ccw({xx, yy}, cvh[i].fi, cvh[i + 1].fi) > 0)
					ans += (ld)a[num].R * gak;
				else
					ans += (ld)a[num].R * (2.0 * PI - gak);
			}
			
			else
				ans += sqrt((ld)(cvh[i].fi.fi - cvh[i + 1].fi.fi) * (cvh[i].fi.fi - cvh[i + 1].fi.fi) + (ld)(cvh[i].fi.se - cvh[i + 1].fi.se) * (cvh[i].fi.se - cvh[i + 1].fi.se));
		}
		
		cout << ans en;
	}
	
	return 0;
}