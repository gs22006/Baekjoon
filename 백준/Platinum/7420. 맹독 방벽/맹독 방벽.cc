#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
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

struct circle
{
	ll A, B, R;
	
	bool operator < (const circle &xx) const
	{
		if(B + R == xx.B + xx.R)
			return A < xx.A;
		
		return B + R < xx.B + xx.R;
	}
};

ll n;
circle all;
vector<circle> a;
vector<ll> S[5000010];
ld PI = acos(-1);
vector< pair<pld, ll> > vec;
vector< pair<pld, ll> > cvh, cvh2;

ld ccw(pld X, pld Y, pld Z)
{
	ld ret = (X.fi * Y.se + Y.fi * Z.se + Z.fi * X.se) - (X.se * Y.fi + Y.se * Z.fi + Z.se * X.fi);
	
	if(ret < 0)
		return -1;
	else if(!ret)
		return 0;
	
	return 1;
}

ll ccw2(pll X, pll Y, pll Z)
{
	ll ret = (X.fi * Y.se + Y.fi * Z.se + Z.fi * X.se) - (X.se * Y.fi + Y.se * Z.fi + Z.se * X.fi);
	
	if(ret == 0)
		return 0;
	
	if(ret < 0)
		return -1;
	
	return 1;
}

ld buho(ld X)
{
	if(abs(X) <= 0.000000001)
		return 0;
	else if(X > 0)
		return 1;
	
	return -1;
}

vector<pld> help;

pld gyo(ld A1, ld B1, ld A2, ld B2)
{
	pld ret;
	
	ret.fi = (B2 - B1) / (A1 - A2);
	ret.se = A1 * ret.fi + B1;
	
	return ret;
}

void getpnt(circle X, circle Y, ld M)
{
	ld a1 = X.A;
	ld a2 = Y.A;
	ld b1 = X.B;
	ld b2 = Y.B;
	ld r1 = X.R;
	ld r2 = Y.R;
	
	if(M == 0)
	{
		if(r1 + b1 == r2 + b2)
		{
			help.push_back({a1, r1 + b1});
			help.push_back({a2, r2 + b2});
		}
		
		if(b1 - r1 == b2 - r2)
		{
			help.push_back({a1, b1 - r1});
			help.push_back({a2, b2 - r2});
		}
		
		return;
	}
	
	if(X.R == Y.R)
	{
		ld A1 = M;
		ld B1 = (ld)r1 * sqrt(M * M + 1) + (ld)b1 - M * (ld)a1;
		ld A2 = M;
		ld B2 = (ld)r2 * sqrt(M * M + 1) + (ld)b2 - M * (ld)a2;
		ld A3 = -1.0 / M;
		ld B3 = -A3 * (ld)a1 + (ld)b1;
		ld A4 = -1.0 / M;
		ld B4 = -A4 * (ld)a2 + (ld)b2;
		
		help.push_back(gyo(A1, B1, A3, B3));
		help.push_back(gyo(A2, B2, A4, B4));
		
		A1 = M;
		B1 = (ld)(-r1) * sqrt(M * M + 1) + (ld)b1 - M * (ld)a1;
		A2 = M;
		B2 = (ld)(-r2) * sqrt(M * M + 1) + (ld)b2 - M * (ld)a2;
		A3 = -1.0 / M;
		B3 = -A3 * (ld)a1 + (ld)b1;
		A4 = -1.0 / M;
		B4 = -A4 * (ld)a2 + (ld)b2;
		
		help.push_back(gyo(A1, B1, A3, B3));
		help.push_back(gyo(A2, B2, A4, B4));
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
		
		help.push_back(gyo(A1, B1, A3, B3));
		help.push_back(gyo(A2, B2, A4, B4));
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
		
		help.push_back(gyo(A1, B1, A3, B3));
		help.push_back(gyo(A2, B2, A4, B4));
	}
}

ld deg(circle X, circle Y)
{
	ld a1 = X.A;
	ld a2 = Y.A;
	ld b1 = X.B;
	ld b2 = Y.B;
	ld r1 = X.R;
	ld r2 = Y.R;
	ld aa, bb, cc;
	ld m;
	
	help.clear();
	
	if((X.A - Y.A) * (X.A - Y.A) + (X.B - Y.B) * (X.B - Y.B) <= (X.R - Y.R) * (X.R - Y.R))
		return INF;
	
	if(a1 == a2 && b1 == b2 && r1 == r2)
		return INF;
		
	if(a1 + r1 == a2 + r2)
	{
		help.push_back({a1 + r1, b1});
		help.push_back({a2 + r2, b2});
	}
	
	if(a1 - r1 == a2 - r2)
	{
		help.push_back({a1 - r1, b1});
		help.push_back({a2 - r2, b2});
	}
	
	aa = (r1 - r2) * (r1 - r2) - (a1 - a2) * (a1 - a2);
	bb = 2 * (a1 - a2) * (b1 - b2);
	cc = (r1 - r2) * (r1 - r2) - (b1 - b2) * (b1 - b2);
	
	if(aa == 0)
	{
		if(bb)
			getpnt(X, Y, -(ld)cc / (ld)bb);
	}
	
	else
	{
		if(bb * bb / 4 >= aa * cc)
		{
			m = (-(ld)bb + (ld)sqrt((ld)bb * bb - 4 * aa * cc)) / (ld)(2 * aa);
			getpnt(X, Y, m);
			m = (-(ld)bb - (ld)sqrt((ld)bb * bb - 4 * aa * cc)) / (ld)(2 * aa);
			getpnt(X, Y, m);
		}
	}
	
	vector<pld> yea;
	
	/*//cout << "Help before\n";
	for(auto &i : help)
		//cout << "*" << i.fi sp << i.se en;*/
	
	while((ll)help.size() > 4)
		help.pop_back();
	
	if((ll)help.size() == 4)
	{
		if(ccw(help[0], help[1], help[2]) < 0)
		{
			yea.push_back(help[0]);
			yea.push_back(help[1]);
		}
		
		else
		{
			//what if same...???
			yea.push_back(help[2]);
			yea.push_back(help[3]);
		}
	}
	
	else if((ll)help.size() == 2)
	{
		yea.push_back(help[0]);
		yea.push_back(help[1]);
	}
	
	else
		assert(0);
	
	help = yea;
	
	if(help[0].fi == help[1].fi)
	{
		if(help[0].se < help[1].se)
			return PI * 1.5;
		
		return PI * 0.5;
	}
	
	//cout << "help\n";
	//cout << help[0].fi sp << help[0].se en;
	//cout << help[1].fi sp << help[1].se en;
	
	if(help[0].fi == help[1].fi)
	{
		if(help[0].se < help[1].se)
			return PI * 1.5;
		
		return PI * 0.5;
	}
	
	if(help[0].se == help[1].se)
	{
		if(help[0].fi < help[1].fi)
			return PI * 2;
		
		return PI;
	}
	
	ld somad = abs((help[1].se - help[0].se) / (help[1].fi - help[0].fi));
	
	if(help[0].fi < help[1].fi && help[0].se < help[1].se)
		return 2 * PI - atan(somad);
	else if(help[0].fi > help[1].fi && help[0].se < help[1].se)
		return PI + atan(somad);
	else if(help[0].fi < help[1].fi && help[0].se > help[1].se)
		return atan(somad);
	else
		return PI - atan(somad);
}

pld get_jup(circle X, ld D)
{
	if(abs(D - 2 * PI) <= 0.0000000001)
		D = 0;
	
	if(abs(D - 0) <= 0.0000000001)
		return {X.A, X.B + X.R};
	else if(abs(D - PI * 0.5) <= 0.0000000001)
		return {X.A + X.R, X.B};
	else if(abs(D - PI) <= 0.0000000001)
		return {X.A, X.B - X.R};
	else if(abs(D - PI * 1.5) <= 0.0000000001)
		return {X.A - X.R, X.B};
	
	ld M = tan(2 * PI - D);
	ld AA = -1;
	ld BB = -2.0 * X.A * M + 2.0 * X.B;
	ld CC = -X.A * X.A * M * M + 2.0 * X.A * X.B * M - X.B * X.B + M * M * X.R * X.R + X.R * X.R;
	
	ld N1 = (-BB + sqrt(BB * BB - 4.0 * AA * CC)) / (2 * AA);
	ld N2 = (-BB - sqrt(BB * BB - 4.0 * AA * CC)) / (2 * AA);
	pld P1, P2, PP1, PP2;
	ld MM = -1.0 / M;
	ld HELP1 = X.B + X.A / M;
	P1 = gyo(MM, HELP1, M, N1);
	P2 = gyo(MM, HELP1, M, N2);
	ll winner = 0;
	
	if(abs(D - 2 * PI) <= 0.0000000001)
		D = 0;
	
	if(abs(D - 0) <= 0.0000000001)
	{
		if(P1.se > P2.se)
			winner = -1;
		else
			winner = 1;
	}
	
	else if(abs(D - PI * 0.5) <= 0.0000000001)
	{
		if(P1.fi > P2.fi)
			winner = -1;
		else
			winner = 1;
	}
	
	else if(abs(D - PI) <= 0.0000000001)
	{
		if(P1.se < P2.se)
			winner = -1;
		else
			winner = 1;
	}
	
	else if(abs(D - PI * 1.5) <= 0.0000000001)
	{
		if(P1.fi < P2.fi)
			winner = -1;
		else
			winner = 1;
	}
	
	else
	{
		if(PI * 0.5 <= D && D <= PI * 1.5)
			PP1 = {P1.fi - 1, P1.se - tan(2 * PI - D)};
		else
			PP1 = {P1.fi + 1, P1.se + tan(2 * PI - D)};
		
		if(PI * 0.5 <= D && D <= PI * 1.5)
			PP2 = {P2.fi - 1, P2.se - tan(2 * PI - D)};
		else
			PP2 = {P2.fi + 1, P2.se + tan(2 * PI - D)};
		
		if(ccw(P1, PP1, P2) < 0)
			winner = -1;
		else
			winner = 1;
	}
	
	//cout << "JUPJUM\n";
	//cout << P1.fi sp << P1.se en;
	//cout << P2.fi sp << P2.se en;
	//cout << PP1.fi sp << PP1.se en;
	//cout << PP2.fi sp << PP2.se en;
	
	if(winner == -1)
		return P1;
	
	return P2; //what if same...?
}

ll dome(pld X, pld Y, ld D)
{
	pld X2, Y2;
	
	if(abs(D - 2 * PI) <= 0.000000001)
		D = 0;
	
	if(abs(D - 0) <= 0.000000001)
	{
		if(X.se > Y.se)
			return -1;
		else if(X.se < Y.se)
			return 1;
		
		return 0;
	}
	
	if(abs(D - PI * 0.5) <= 0.000000001)
	{
		if(X.fi > Y.fi)
			return -1;
		else if(X.fi < Y.fi)
			return 1;
		
		return 0;
	}
	
	if(abs(D - PI) <= 0.000000001)
	{
		if(X.se < Y.se)
			return -1;
		else if(X.se > Y.se)
			return 1;
		
		return 0;
	}
	
	if(abs(D - PI * 1.5) <= 0.000000001)
	{
		if(X.fi < Y.fi)
			return -1;
		else if(X.fi > Y.fi)
			return 1;
		
		return 0;
	}
	
	if(PI * 0.5 <= D && D <= PI * 1.5)
	{
		X2.fi = X.fi - 1;
		X2.se = X.se - tan(2 * PI - D);
		Y2.fi = Y.fi - 1;
		Y2.se = Y.se - tan(2 * PI - D);
	}
	
	else
	{
		X2.fi = X.fi + 1;
		X2.se = X.se + tan(2 * PI - D);
		Y2.fi = Y.fi + 1;
		Y2.se = Y.se + tan(2 * PI - D);
	}
	
	ld ggaapp = ccw(X, X2, Y);
	
	if(abs(ggaapp - 0) <= 0.000000001)
		return 0;
	
	if(ggaapp < 0)
		return -1;
	
	return 1;
}

ll sisi = 0;
ll sisisi = 0;

pair<pll, ld> advance(ll no, ll X, ll Y, ld gak, ll l, ll r)
{
	//cout << "advance\n";
	//cout << a[S[X][l]].A sp << a[S[X][l]].B sp << a[S[X][l]].R en;
	//cout << a[S[Y][r]].A sp << a[S[Y][r]].B sp << a[S[Y][r]].R en;
	
	ld a1 = deg(a[S[X][l]], a[S[Y][r]]);
	ld a2 = deg(a[S[X][l]], a[S[X][(l + 1) % (ll)S[X].size()]]);
	ld a3 = deg(a[S[Y][r]], a[S[Y][(r + 1) % (ll)S[Y].size()]]);
	ld a4 = deg(a[S[Y][r]], a[S[X][l]]);
	
	if(abs(a1 - 2 * PI) <= 0.000000001)
		a1 = 0;
	
	if(abs(a2 - 2 * PI) <= 0.000000001)
		a2 = 0;
	
	if(abs(a3 - 2 * PI) <= 0.000000001)
		a3 = 0;
	
	if(abs(a4 - 2 * PI) <= 0.000000001)
		a4 = 0;
	
	if(gak <= a1)
		a1 -= gak;
	else
		a1 = 2 * PI - gak + a1;
	
	if(gak <= a2)
		a2 -= gak;
	else
		a2 = 2 * PI - gak + a2;
	
	if(gak <= a3)
		a3 -= gak;
	else
		a3 = 2 * PI - gak + a3;
	
	if(gak <= a4)
		a4 -= gak;
	else
		a4 = 2 * PI - gak + a4;
	
	if(abs(a1 - 2 * PI) <= 0.000000001)
		a1 = 0;
	
	if(abs(a2 - 2 * PI) <= 0.000000001)
		a2 = 0;
	
	if(abs(a3 - 2 * PI) <= 0.000000001)
		a3 = 0;
	
	if(abs(a4 - 2 * PI) <= 0.000000001)
		a4 = 0;
	
	//cout << a1 sp << a2 sp << a3 sp << a4 en;
	
	if(a1 < a4)
	{
		if(a1 < min(a2, a3))
		{
			if(S[no].empty() || S[no].back() != S[Y][r])
			{
				if((ll)S[no].size() >= 2 && S[no][0] == S[no].back() && S[no][1] == S[Y][r])
				{
					sisi = INF;
					return {{0, 0}, 0};
				}
				//cout << "PUSH : " << a[S[Y][r]].A sp << a[S[Y][r]].B sp << a[S[Y][r]].R en;
				S[no].push_back(S[Y][r]);
				sisi++;
			}
		}
		
		if(a4 < min(a2, a3))
		{
			if(S[no].empty() || S[no].back() != S[X][l])
			{
				if((ll)S[no].size() >= 2 && S[no][0] == S[no].back() && S[no][1] == S[X][l])
				{
					sisi = INF;
					return {{0, 0}, 0};
				}
				//cout << "PUSH : " << a[S[X][l]].A sp << a[S[X][l]].B sp << a[S[X][l]].R en;
				S[no].push_back(S[X][l]);
				sisi++;
			}
		}
	}
	
	else
	{
		if(a4 < min(a2, a3))
		{
			if(S[no].empty() || S[no].back() != S[X][l])
			{
				if((ll)S[no].size() >= 2 && S[no][0] == S[no].back() && S[no][1] == S[X][l])
				{
					sisi = INF;
					return {{0, 0}, 0};
				}
				//cout << "PUSH : " << a[S[X][l]].A sp << a[S[X][l]].B sp << a[S[X][l]].R en;
				S[no].push_back(S[X][l]);
				sisi++;
			}
		}
		
		if(a1 < min(a2, a3))
		{
			if(S[no].empty() || S[no].back() != S[Y][r])
			{
				if((ll)S[no].size() >= 2 && S[no][0] == S[no].back() && S[no][1] == S[Y][r])
				{
					sisi = INF;
					return {{0, 0}, 0};
				}
				//cout << "PUSH : " << a[S[Y][r]].A sp << a[S[Y][r]].B sp << a[S[Y][r]].R en;
				S[no].push_back(S[Y][r]);
				sisi++;
			}
		}
	}
	
	if(a2 < a3)
	{
		gak += a2;
		l = (l + 1) % (ll)S[X].size();
		
		if(abs(gak - 2 * PI) <= 0.000000001)
			gak = 0;
	}
	
	else
	{
		gak += a3;
		r = (r + 1) % (ll)S[Y].size();
		
		if(abs(gak - 2 * PI) <= 0.000000001)
			gak = 0;
	}
	
	if(gak >= 2 * PI)
		gak -= 2 * PI;
	
	if(gak < 0)
		gak += 2 * PI;
	
	return {{l, r}, gak};
}

ll cw(pld X, pld Y, ld D)
{
	if(abs(D - 2 * PI) <= 0.000000001)
		D = 0;
	
	if(abs(D - 0) <= 0.000000001)
	{
		if(X.fi < Y.fi)
			return -1;
		else if(X.fi > Y.fi)
			return 1;
		
		return 0;
	}
	
	if(abs(D - PI * 0.5) <= 0.000000001)
	{
		if(X.se > Y.se)
			return -1;
		else if(X.se < Y.se)
			return 1;
		
		return 0;
	}
	
	if(abs(D - PI) <= 0.000000001)
	{
		if(X.fi > Y.fi)
			return -1;
		else if(X.fi < Y.fi)
			return 1;
		
		return 0;
	}
	
	if(abs(D - PI * 1.5) <= 0.000000001)
	{
		if(X.se < Y.se)
			return -1;
		else if(X.se > Y.se)
			return 1;
		
		return 0;
	}
	
	if(PI * 0.5 <= D && D <= PI * 1.5)
	{
		if(X.fi > Y.fi)
			return -1;
		else if(X.fi < Y.fi)
			return 1;
		
		return 0;
	}
	
	else
	{
		if(X.fi < Y.fi)
			return -1;
		else if(X.fi > Y.fi)
			return 1;
		
		return 0;
	}
}

ll sizz = 0;

void merge(ll no, ll X, ll Y)
{
	if((ll)S[X].empty())
	{
		S[no] = S[Y];
		return;
	}
	
	if((ll)S[Y].empty())
	{
		S[no] = S[X];
		return;
	}
	
	ll l = 0, r = 0;
	ll maxx1 = 0, maxx2 = 0;
	pld p, q;
	ld gak = 0;
	sisi = sisisi = 0;
	
	//cout << "merge : " << no sp << X sp << Y en;
	
	//cout << "X\n";
	
	//for(auto &i : S[X])
		//cout << a[i].A sp << a[i].B sp << a[i].R en;
	
	//cout << "Y\n";
	
	//for(auto &i : S[Y])
		//cout << a[i].A sp << a[i].B sp << a[i].R en;
	
	for(ll i = 0 ; i < (ll)S[X].size() ; i++)
	{
		if(maxx1 < a[S[X][i]].B + a[S[X][i]].R)
		{
			maxx1 = a[S[X][i]].B + a[S[X][i]].R;
			l = i;
		}
		
		else if(maxx1 == a[S[X][i]].B + a[S[X][i]].R && a[S[X][i]].A < a[S[X][l]].A)
			l = i;
	}
	
	for(ll i = 0 ; i < (ll)S[Y].size() ; i++)
	{
		if(maxx2 < a[S[Y][i]].B + a[S[Y][i]].R)
		{
			maxx2 = a[S[Y][i]].B + a[S[Y][i]].R;
			r = i;
		}
		
		else if(maxx2 == a[S[Y][i]].B + a[S[Y][i]].R && a[S[Y][i]].A < a[S[Y][r]].A)
			r = i;
	}
	
	sizz = min(sizz, (ll)S[X].size() + (ll)S[Y].size());
	
	while(sisi < sizz * 2 - 1 && sisisi < sizz * 2 - 1 && gak < INF / 2)
	{
		p = get_jup(a[S[X][l]], gak);
		q = get_jup(a[S[Y][r]], gak);
		
		sisisi++;
		
		//cout << "l : " << a[S[X][l]].A sp << a[S[X][l]].B sp << a[S[X][l]].R en;
		//cout << "r : " << a[S[Y][r]].A sp << a[S[Y][r]].B sp << a[S[Y][r]].R en;
		//cout << "p : " << p.fi sp << p.se en;
		//cout << "q : " << q.fi sp << q.se en;
		//cout << "gak : " << gak / PI * 180 en;
		
		ll dm = dome(p, q, gak);
		
		//cout << dm en;
		
		if(dm == -1)
		{
			if(S[no].empty() || S[no].back() != S[X][l])
			{
				//cout << "PUSH : " << a[S[X][l]].A sp << a[S[X][l]].B sp << a[S[X][l]].R en;
				
				if((ll)S[no].size() >= 2 && S[no][0] == S[no].back() && S[no][1] == S[X][l])
					break;
				
				S[no].push_back(S[X][l]);
				sisi++;
			}
			
			pair<pll, ld> tmp = advance(no, X, Y, gak, l, r);
			
			l = tmp.fi.fi;
			r = tmp.fi.se;
			gak = tmp.se;
		}
		
		else if(dm == 1)
		{
			if(S[no].empty() || S[no].back() != S[Y][r])
			{
				//cout << "PUSH : " << a[S[Y][r]].A sp << a[S[Y][r]].B sp << a[S[Y][r]].R en;
				
				if((ll)S[no].size() >= 2 && S[no][0] == S[no].back() && S[no][1] == S[Y][r])
					break;
				
				S[no].push_back(S[Y][r]);
				sisi++;
			}
			
			pair<pll, ld> tmp = advance(no, Y, X, gak, r, l);
			
			r = tmp.fi.fi;
			l = tmp.fi.se;
			gak = tmp.se;
		}
		
		else
		{
			ll ggg = cw(p, q, gak);
			
			if(ggg == -1)
			{
				if(S[no].empty() || S[no].back() != S[X][l])
				{
					if((ll)S[no].size() >= 2 && S[no][0] == S[no].back() && S[no][1] == S[X][l])
						break;
					//cout << "PUSH : " << a[S[X][l]].A sp << a[S[X][l]].B sp << a[S[X][l]].R en;
					S[no].push_back(S[X][l]);
					sisi++;
				}
				
				pair<pll, ld> tmp = advance(no, X, Y, gak, l, r);
				
				l = tmp.fi.fi;
				r = tmp.fi.se;
				gak = tmp.se;
			}
			
			else
			{
				if(S[no].empty() || S[no].back() != S[Y][r])
				{
					if((ll)S[no].size() >= 2 && S[no][0] == S[no].back() && S[no][1] == S[Y][r])
						break;
					//cout << "PUSH : " << a[S[Y][r]].A sp << a[S[Y][r]].B sp << a[S[Y][r]].R en;
					S[no].push_back(S[Y][r]);
					sisi++;
				}
				
				pair<pll, ld> tmp = advance(no, Y, X, gak, r, l);
				
				r = tmp.fi.fi;
				l = tmp.fi.se;
				gak = tmp.se;
			}
		}
	}
	
	if((ll)S[no].size() > 1 && S[no][0] == S[no].back())
		S[no].pop_back();
}

void merge2(ll no, ll X, ll Y)
{
	vector< pair<pll, ll> > vvv;
	
	for(auto &i : S[X])
		vvv.push_back({{a[i].A, a[i].B}, i});
	
	for(auto &i : S[Y])
		vvv.push_back({{a[i].A, a[i].B}, i});
	
	sort(vvv.begin(), vvv.end());
	
	vector< pair<pll, ll> > h1, h2;
	vector<ll> ret;
	
	if((ll)vvv.size() <= 2)
	{
		for(ll i = 0 ; i < (ll)vvv.size() ; i++)
			ret.push_back(vvv[i].se);
	}
	
	else
	{
		h1.push_back(vvv[0]);
		h1.push_back(vvv[1]);
		
		for(ll i = 2 ; i < (ll)vvv.size() ; i++)
		{
			while(1)
			{
				ll siz = (ll)h1.size();
				
				if(siz < 2 || ccw2(h1[siz - 2].fi, h1[siz - 1].fi, vvv[i].fi) > 0)
					break;
				
				h1.pop_back();
			}
			
			h1.push_back(vvv[i]);
		}
		
		h2.push_back(vvv[(ll)vvv.size() - 1]);
		h2.push_back(vvv[(ll)vvv.size() - 2]);
		
		for(ll i = (ll)vvv.size() - 3 ; i >= 0 ; i--)
		{
			while(1)
			{
				ll siz = (ll)h2.size();
				
				if(siz < 2 || ccw(h2[siz - 2].fi, h2[siz - 1].fi, vvv[i].fi) > 0)
					break;
				
				h2.pop_back();
			}
			
			h2.push_back(vvv[i]);
		}
		
		for(auto &i : h1)
			ret.push_back(i.se);
		
		for(auto &i : h2)
		{
			if(ret.back() == i.se)
				continue;
			
			ret.push_back(i.se);
		}
		
		ret.pop_back();
	}
	
	reverse(ret.begin(), ret.end());
	
	for(auto &i : ret)
		S[no].push_back(i);
}

void f(ll no, ll s, ll e)
{
	S[no].clear();
	
	if(s == e)
	{
		S[no].push_back(s);
		return;
	}
	
	ll mid = (s + e) >> 1;
	f(no << 1, s, mid);
	f(no << 1 | 1, mid + 1, e);
	
	sizz = (e - s + 1);
	ll fdsf = 0;
	
	for(ll i = s ; i <= e ; i++)
	{
		if(a[i].R != a[s].R)
			fdsf = 1;
	}
	
	if(fdsf)
		merge(no, no << 1, no << 1 | 1);
	else
		merge2(no, no << 1, no << 1 | 1);
	
	//cout << "merge finished\n";
	
	//for(auto &i : S[no])
		//cout << a[i].A sp << a[i].B sp << a[i].R en;
}

ll t;

int main(void)
{
	fastio
	
	t = 1;
	
	while(t--)
	{
		a.clear();
		vec.clear();
		cvh.clear();
		cvh2.clear();
		
		cin >> n;
		
		ll RRRR = 0;
		
		cin >> RRRR;
		
		assert(n <= 50000);
		
		for(ll i = 1 ; i <= n ; i++)
		{
			cin >> all.A >> all.B;
			all.R = RRRR;
			
			assert(max(all.A, all.B) <= 2000000000);
			assert(min(all.A, all.B) >= -2000000000);
			assert(1 <= all.R && all.R <= 100000);
			
			a.push_back(all);
		}
		
		sort(a.begin(), a.end());
		
		vector<circle> sad;
		
		for(ll i = 0 ; i < (ll)a.size() ; i++)
		{
			if(i && a[i].A == a[i - 1].A && a[i].B == a[i - 1].B && a[i].R == a[i - 1].R)
				continue;
			
			sad.push_back(a[i]);
		}
		
		a = sad;
		n = (ll)a.size();
		
		//cout << "PI" << PI en;
		f(1, 0, n - 1);
		
		//cout << "what\n";
		//for(auto &i : S[1])
			//cout << a[i].A sp << a[i].B sp << a[i].R en;
		
		if((ll)S[1].size() == 1)
		{
			cout << 2.0 * PI * a[S[1][0]].R en;
			continue;
		}
		
		ld ans = 0;
		set< pair<ll, ll> > st;
		vector<ld> gagk;
		vector<ll> hihi;
		
		for(ll i = 0 ; i < (ll)S[1].size() ; i++)
		{
			ll R = i + 1;
			
			if(R > (ll)S[1].size() - 1)
				R = 0;
			
			if(st.find({S[1][i], S[1][R]}) != st.end())
				break;
			
			st.insert({S[1][i], S[1][R]});
			hihi.push_back(S[1][i]);
		}
		//cout << "what\n";
		///for(auto &i : hihi)
			//cout << a[i].A sp << a[i].B sp << a[i].R en;
		
		for(ll i = 0 ; i < (ll)hihi.size() ; i++)
		{
			ll L = i - 1;
			ll R = i + 1;
			
			if(L < 0)
				L = (ll)hihi.size() - 1;
			
			if(R > (ll)hihi.size() - 1)
				R = 0;
			
			ld gak1 = deg(a[hihi[L]], a[hihi[i]]);
			ld gak2 = deg(a[hihi[i]], a[hihi[R]]);
			ld gakk = gak2 - gak1;
			
			if(gakk < 0)
				gakk += 2 * PI;
			//cout << "L : " << a[hihi[L]].A sp << a[hihi[L]].B sp << a[hihi[L]].R sp << gak1 / PI * 180 en;
			//cout << a[hihi[i]].A sp << a[hihi[i]].B sp << a[hihi[i]].R sp << gakk / PI * 180 en;
			//cout << "R : " << a[hihi[R]].A sp << a[hihi[R]].B sp << a[hihi[R]].R en << gak2 / PI * 180 en;
			ans += gakk * a[hihi[i]].R;
			ans += hypot(help[0].fi - help[1].fi, help[0].se - help[1].se);
		}
		
		cout << (ll)round(ans) en;
	}
	
	return 0;
}