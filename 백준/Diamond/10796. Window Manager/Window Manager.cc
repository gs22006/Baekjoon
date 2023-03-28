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

struct rect
{
	ll x, y, w, h, t;
	
	bool operator < (const rect &xx) const
	{
		return t < xx.t;
	}
};

ll xmax, ymax;
vector<rect> vec;
char s[20];
ll all, bll, cll, dll;
ll cc;
ll chk[510];

ll cross(rect X, rect Y)
{
	ll L1 = X.x;
	ll R1 = X.x + X.w;
	ll L2 = Y.x;
	ll R2 = Y.x + Y.w;
	ll U1 = X.y;
	ll D1 = X.y + X.h;
	ll U2 = Y.y;
	ll D2 = Y.y + Y.h;
	
	if(R1 < L2 || R2 < L1 || D1 < U2 || D2 < U1)
		return 0;
	
	else if(L1 == R2 || R1 == L2 || U1 == D2 || U2 == D1)
		return 0;
	
	return 1;
}

ll outofbounds(rect X)
{
	ll L1 = X.x;
	ll R1 = X.x + X.w;
	ll U1 = X.y;
	ll D1 = X.y + X.h;
	
	if(L1 < 0 || U1 < 0 || R1 > xmax || D1 > ymax)
		return 1;
	
	return 0;
}

ll in_rect(rect X, pll Y)
{
	ll L1 = X.x;
	ll R1 = X.x + X.w;
	ll U1 = X.y;
	ll D1 = X.y + X.h;
	
	if(L1 <= Y.fi && Y.fi < R1 && U1 <= Y.se && Y.se < D1)
		return 1;
	
	return 0;
}

ll dist(rect X, rect Y, ll dx, ll dy)
{
	if(dx)
	{
		if(dx > 0)
		{
			if(Y.x < X.x + X.w)
				return INF;
		}
		
		else if(dx < 0)
		{
			if(Y.x + Y.w > X.x)
				return INF;
		}
		
		ll L1 = X.y;
		ll R1 = X.y + X.h;
		ll L2 = Y.y;
		ll R2 = Y.y + Y.h;
		
		if(R1 <= L2 || R2 <= L1)
			return INF;
		
		if(dx > 0)
			return Y.x - (X.x + X.w);
		
		return X.x - (Y.x + Y.w);
	}
	
	else
	{
		if(dy > 0)
		{
			if(Y.y < X.y + X.h)
				return INF;
		}
		
		else if(dy < 0)
		{
			if(Y.y + Y.h > X.y)
				return INF;
		}
		
		ll L1 = X.x;
		ll R1 = X.x + X.w;
		ll L2 = Y.x;
		ll R2 = Y.x + Y.w;
		
		if(R1 <= L2 || R2 <= L1)
			return INF;
		
		if(dy > 0)
			return Y.y - (X.y + X.h);
		
		return X.y - (Y.y + Y.h);
	}
}

int main(void)
{
	fastio
	
	cin >> xmax >> ymax;
	
	while(cin >> s)
	{
		cc++;
		
		if(!strcmp(s, "OPEN"))
		{
			cin >> all >> bll >> cll >> dll;
			
			rect tmp;
			ll ff = 0;
			
			tmp.x = all;
			tmp.y = bll;
			tmp.w = cll;
			tmp.h = dll;
			tmp.t = cc;
			
			for(auto &i : vec)
			{
				if(cross(i, tmp))
					ff = 1;
			}
			
			if(outofbounds(tmp))
				ff = 1;
			
			if(ff)
				cout << "Command " << cc << ": OPEN - window does not fit\n";
			else
				vec.push_back(tmp);
		}
		
		else if(!strcmp(s, "CLOSE"))
		{
			cin >> all >> bll;
			
			vector<rect> vec2;
			ll ff = 0;
			
			for(auto &i : vec)
			{
				if(in_rect(i, {all, bll}))
				{
					ff = 1;
					continue;
				}
				
				vec2.push_back(i);
			}
			
			if(!ff)
			{
				cout << "Command " << cc << ": CLOSE - no window at given position\n";
				continue;
			}
			
			vec = vec2;
		}
		
		else if(!strcmp(s, "RESIZE"))
		{
			cin >> all >> bll >> cll >> dll;
			
			rect tar;
			vector<rect> vec2;
			ll ff = 0;
			
			for(auto &i : vec)
			{
				if(in_rect(i, {all, bll}))
				{
					tar = i;
					ff = 1;
					break;
				}
			}
			
			for(auto &i : vec)
			{
				if(i.t != tar.t)
					vec2.push_back(i);
			}
			
			if(!ff)
			{
				cout << "Command " << cc << ": RESIZE - no window at given position\n";
				continue;
			}
			
			tar.w = cll;
			tar.h = dll;
			ff = 0;
			
			for(auto &i : vec2)
			{
				if(cross(i, tar))
					ff = 1;
			}
			
			if(outofbounds(tar))
				ff = 1;
			
			if(ff)
			{
				cout << "Command " << cc << ": RESIZE - window does not fit\n";
				continue;
			}
			
			vec2.push_back(tar);
			vec = vec2;
		}
		
		else if(!strcmp(s, "MOVE"))
		{
			cin >> all >> bll >> cll >> dll;
			
			for(ll i = 0 ; i < 310 ; i++)
				chk[i] = 0;
			
			ll sisi = (ll)vec.size();
			vector<rect> vec2;
			ll ff = 0;
			
			for(auto &i : vec)
			{
				if(in_rect(i, {all, bll}))
				{
					vec2.push_back(i);
					chk[i.t] = 1;
					ff = 1;
					break;
				}
			}
			
			if(!ff)
			{
				cout << "Command " << cc << ": MOVE - no window at given position\n";
				continue;
			}
			
			if(!cll && !dll)
				continue;
			
			ll mx = 0, my = 0;
			
			while(1)
			{
				ll mind = INF;
				rect tar;
				ll oooo = 0;
				
				for(auto &i : vec)
				{
					if(chk[i.t])
						continue;
					
					for(auto &j : vec2)
					{
						ll D = dist(j, i, cll, dll);
						
						if(D < mind)
						{
							mind = D;
							tar = i;
							oooo = 1;
						}
					}
				}
				
				ll fff = 0;
				
				if(cll && abs(cll) <= mx + mind)
					mind = abs(cll) - mx;
				else if(dll && abs(dll) <= my + mind)
					mind = abs(dll) - my;
				
				ll minX = INF, maxX = -INF;
				ll minY = INF, maxY = -INF;
				
				for(auto &i : vec2)
				{
					minX = min(minX, i.x);
					maxX = max(maxX, i.x + i.w);
					minY = min(minY, i.y);
					maxY = max(maxY, i.y + i.h);
				}
				
				if(cll && cll < 0)
				{
					if(minX <= mind)
					{
						mind = minX;
						fff = 1;
					}
				}
				
				else if(cll && cll > 0)
				{
					if(xmax - maxX <= mind)
					{
						mind = xmax - maxX;
						fff = 1;
					}
				}
				
				else if(dll && dll < 0)
				{
					if(minY <= mind)
					{
						mind = minY;
						fff = 1;
					}
				}
				
				else if(dll && dll > 0)
				{
					if(ymax - maxY <= mind)
					{
						mind = ymax - maxY;
						fff = 1;
					}
				}
				
				for(auto &i : vec2)
				{
					if(cll && cll < 0)
						i.x -= mind;
					else if(cll && cll > 0)
						i.x += mind;
					else if(dll && dll < 0)
						i.y -= mind;
					else if(dll && dll > 0)
						i.y += mind;
				}
				
				if(cll)
					mx += mind;
				else if(dll)
					my += mind;
				
				if(oooo)
				{
					chk[tar.t] = 1;
					vec2.push_back(tar);
				}
				
				if(fff)
					break;
				
				if(cll && abs(cll) == mx)
					break;
				
				if(dll && abs(dll) == my)
					break;
			}
			
			for(auto &i : vec)
			{
				if(!chk[i.t])
					vec2.push_back(i);
			}
			
			vec = vec2;
			
			if(cll && abs(cll) != mx)
			{
				cout << "Command " << cc << ": MOVE - moved " << mx sp << "instead of " << abs(cll) en;
				continue;
			}
			
			else if(dll && abs(dll) != my)
			{
				cout << "Command " << cc << ": MOVE - moved " << my sp << "instead of " << abs(dll) en;
				continue;
			}
		}
	}
	
	ll sizz = (ll)vec.size();
	
	cout << sizz sp << "window(s):\n";
	
	sort(vec.begin(), vec.end());
	
	for(auto &i : vec)
		cout << i.x sp << i.y sp << i.w sp << i.h en;
	
	return 0;
}