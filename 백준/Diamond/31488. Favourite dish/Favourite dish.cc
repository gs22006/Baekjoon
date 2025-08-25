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

struct gujo
{
    ll X, Y, num;
    
    bool operator < (const gujo &xx) const
    {
        if(X == xx.X)
            return Y < xx.Y;
        
        return X < xx.X;
    }
};

ll n, m;
pll b[500010];
gujo a[500010];
vector<gujo> hull;
vector<pll> gi;
map<pll, ll> mp;

ll ccw(gujo p1, gujo p2, gujo p3)
{
    return p1.X * p2.Y + p2.X * p3.Y + p3.X * p1.Y - (p1.Y * p2.X + p2.Y * p3.X + p3.Y * p1.X);
}

pll ret_slope(gujo p1, gujo p2)
{
	ll mo = p1.X - p2.X;
	ll ja = p1.Y - p2.Y;
	
	if(mo < 0)
		ja *= -1, mo *= -1;
	
	ll G = __gcd(ja, mo);
	
	ja /= G;
	mo /= G;
	
	return {ja, mo};
}

void get_convex_hull(void)
{
    ll maxx = 0;
    
    sort(a + 1, a + 1 + n);
    
    for(ll i = 1 ; i <= n ; i++)
        maxx = max(maxx, a[i].Y);
    
    for(ll i = 1 ; i <= n ; i++)
    {
        while((ll)hull.size() >= 2)
        {
            ll siz = (ll)hull.size();
            
            if(ccw(hull[siz - 2], hull[siz - 1], a[i]) > 0)
                hull.pop_back();
            else
            	break;
        }
        
        hull.push_back(a[i]);
    }
    
    ll siz = (ll)hull.size(), siz2 = 0;
    
    for(ll i = siz - 1 ; i >= 0 ; i--)
    {
        if(hull[i].Y == maxx)
        {
            siz2 = i + 1;
            break;
        }
    }
    
    while((ll)hull.size() > siz2)
        hull.pop_back();
}

int main(void)
{
    fastio
    
    cin >> n >> m;
    
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> a[i].X >> a[i].Y;

        a[i].X *= -1;
        a[i].num = i;
    }
    
    for(ll i = 1 ; i <= m ; i++)
        cin >> b[i].fi >> b[i].se;
    
    get_convex_hull();
    
    ll siz = (ll)hull.size();
    
    for(ll i = 1 ; i < siz ; i++)
    {
    	pll gap = ret_slope(hull[i - 1], hull[i]);
    	
    	gi.push_back(gap);
    	
    	if(mp[gap] == 0)
    		mp[gap] = min(hull[i - 1].num, hull[i].num);
		else
			mp[gap] = min(mp[gap], min(hull[i - 1].num, hull[i].num));
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		pll g;
		
		g.fi = b[i].fi;
		g.se = b[i].se;
		
		ll G = __gcd(g.fi, g.se);
		
		g.fi /= G;
		g.se /= G;
		
		if(mp[g] != 0)
		{
			cout << mp[g] en;
			continue;
		}
		
		ll l = 0, r = (ll)gi.size() - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(gi[mid].fi * g.se < g.fi * gi[mid].se)
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		cout << hull[l].num en;
	}
	
	return 0;
}