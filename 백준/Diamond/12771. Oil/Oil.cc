#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

struct point
{
	ll x, y, idx;
};

struct line
{
	ll x0, x1;
	ll y;
};

ll delta(point A, point B, point C)
{
	return A.x * B.y - B.x * A.y + B.x * C.y - C.x * B.y + C.x * A.y - A.x * C.y;
}

ll n;
line a[2010];
ll gap[4010];
vector<point> vec;
ll ans;

bool sort1(point X, point Y)
{
	if(delta(X, vec[0], Y))
		return delta(X, vec[0], Y) < 0;
	
	return gap[X.idx] > gap[Y.idx];
}

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		scanf("%lld %lld %lld", &a[i].x0, &a[i].x1, &a[i].y);
		
		if(a[i].x0 > a[i].x1)
			swap(a[i].x0, a[i].x1);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		//left
		
		for(ll j = 0 ; j <= 2 * n ; j++)
			gap[j] = 0;
		
		ll cc = 0;
		vec.clear();
		vec.push_back({a[i].x0, a[i].y, 0});
		
		for(ll j = 1 ; j <= n ; j++)
		{
			if(a[j].y == a[i].y)
				continue;
			
			ll X0 = a[j].x0;
			ll X1 = a[j].x1;
			ll Y = a[j].y;
			
			if(Y > a[i].y)
			{
				Y = 2 * a[i].y - Y;
				X0 = 2 * a[i].x0 - X0;
				X1 = 2 * a[i].x0 - X1;
				
				swap(X0, X1);
			}
			
			gap[++cc] = X1 - X0;
			vec.push_back({X0, Y, cc});
			gap[++cc] = X0 - X1;
			vec.push_back({X1, Y, cc});
		}
		
		sort(vec.begin() + 1, vec.end(), sort1);
		
		ll cou = a[i].x1 - a[i].x0;
		
		for(ll j = 1 ; j < vec.size() ; j++)
		{
			ans = max(ans, cou);
			cou += gap[vec[j].idx];
		}
		
		ans = max(ans, cou);
		
		for(ll j = 0 ; j <= 2 * n ; j++)
			gap[j] = 0;
		
		cc = 0;
		vec.clear();
		vec.push_back({a[i].x1, a[i].y, 0});
		
		for(ll j = 1 ; j <= n ; j++)
		{
			if(a[j].y == a[i].y)
				continue;
			
			ll X0 = a[j].x0;
			ll X1 = a[j].x1;
			ll Y = a[j].y;
			
			if(Y > a[i].y)
			{
				Y = 2 * a[i].y - Y;
				X0 = 2 * a[i].x1 - X0;
				X1 = 2 * a[i].x1 - X1;
				
				swap(X0, X1);
			}
			
			gap[++cc] = X1 - X0;
			vec.push_back({X0, Y, cc});
			gap[++cc] = X0 - X1;
			vec.push_back({X1, Y, cc});
		}
		
		sort(vec.begin() + 1, vec.end(), sort1);
		
		cou = a[i].x1 - a[i].x0;
		
		for(ll j = 1 ; j < vec.size() ; j++)
		{
			ans = max(ans, cou);
			cou += gap[vec[j].idx];
		}
		
		ans = max(ans, cou);
	}
	
	printf("%lld", ans);
	return 0;
}