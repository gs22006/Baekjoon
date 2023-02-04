#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

struct point
{
	ll x;
	ll y;
	ll idx;
};

ll delta(point A, point B, point C)
{
	return A.x * B.y - B.x * A.y + B.x * C.y - C.x * B.y + C.x * A.y - A.x * C.y;
}

ld dist(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	ll A = y1 - y2;
	ll B = x2 - x1;
	ll C = (x1 - x2) * y1 - (y1 - y2) * x1;
	ld D = (ld)abs(A * x3 + B * y3 + C) / (ld)(sqrt((ld)(A * A + B * B)));
	
	return D;
}

ll t;
ll n;
point a[100010];
stack<point> stk;
vector<point> cvh;

bool sort1(point X, point Y)
{
	if(X.y == Y.y)
		return X.x < Y.x;
	else
		return X.y < Y.y;
}

bool sort2(point X, point Y)
{
	if(delta(a[0], X, Y))
		return delta(a[0], X, Y) > 0;
	else
		return (X.x + X.y) < (Y.x + Y.y);
}

int main(void)
{
	scanf("%lld", &t);
	
	while(t--)
	{
		cvh.clear();
		
		while(!stk.empty())
			stk.pop();
		
		scanf("%lld", &n);
		
		for(ll i = 0 ; i < n ; i++)
			scanf("%lld %lld", &a[i].x, &a[i].y);
		
		sort(a, a + n, sort1);
		sort(a + 1, a + n, sort2);
		
		stk.push(a[0]);
		stk.push(a[1]);
		
		for(ll i = 2 ; i < n ; i++)
		{
			while((ll)stk.size() >= 2)
			{
				point tmp2 = stk.top();
				stk.pop();
				point tmp1 = stk.top();
				
				if(delta(tmp1, tmp2, a[i]) > 0)
				{
					stk.push(tmp2);
					break;
				}
			}
			
			stk.push(a[i]);
		}
		
		while(!stk.empty())
		{
			cvh.push_back(stk.top());
			stk.pop();
		}
		
		ll N = cvh.size();
		
		if(N <= 2)
		{
			printf("0\n");
			continue;
		}
		
		else if(N == 3)
		{
			ll gap = abs(cvh[0].x * cvh[1].y + cvh[1].x * cvh[2].y + cvh[2].x * cvh[0].y - cvh[1].x * cvh[0].y - cvh[2].x * cvh[1].y - cvh[0].x * cvh[2].y);
			
			if(gap & 1)
				printf("%lld.5\n", gap / 2);
			else
				printf("%lld\n", gap / 2);
			
			continue;
		}
		
		ll ans = 0;
		
		for(ll i = 0 ; i < N ; i++)
		{
			ll p1 = i + 1, p2 = i + 1;
			
			for(ll j = 2 ; j <= N - 2 ; j++)
			{
				ll O = i;
				ll T = i + j;
				
				p1 = max(p1, O + 1);
				p2 = max(p2, T + 1);
				
				//printf("%lld %lld : ", O, T);
				
				while(1)
				{
					ll p5 = p1 % N;
					ll p3 = (p1 + 1) % N;
					
					if(dist(cvh[O].x, cvh[O].y, cvh[T].x, cvh[T].y, cvh[p5].x, cvh[p5].y) >= dist(cvh[O].x, cvh[O].y, cvh[T].x, cvh[T].y, cvh[p3].x, cvh[p3].y))
						break;
					
					if(p1 + 1 >= T)
						break;
						
					p1++;
				}
				//printf("\n");
				while(1)
				{
					ll p6 = p2 % N;
					ll p4 = (p2 + 1) % N;
					
					if(dist(cvh[O].x, cvh[O].y, cvh[T].x, cvh[T].y, cvh[p6].x, cvh[p6].y) >= dist(cvh[O].x, cvh[O].y, cvh[T].x, cvh[T].y, cvh[p4].x, cvh[p4].y))
						break;
					
					if((p2 + 1) % N == O % N)
						break;
						
					p2++;
				}
				
				ll p3 = p1 % N;
				ll p4 = p2 % N;
				ll p5 = O % N;
				ll p6 = T % N;
				
				//printf("%lld %lld %lld %lld\n", O, p3, T, p4);
				//printf("%lld %lld %lld %lld %lld %lld %lld %lld\n", cvh[p5].x, cvh[p5].y, cvh[p3].x, cvh[p3].y, cvh[p6].x, cvh[p6].y, cvh[p4].x, cvh[p4].y);
				ll gap = abs(cvh[p5].x * cvh[p3].y + cvh[p3].x * cvh[p6].y + cvh[p6].x * cvh[p4].y + cvh[p4].x * cvh[p5].y - cvh[p5].y * cvh[p3].x - cvh[p3].y * cvh[p6].x - cvh[p6].y * cvh[p4].x - cvh[p4].y * cvh[p5].x);
				ans = max(ans, gap);
			}
		}
		
		if(ans & 1)
			printf("%lld.5\n", ans / 2);
		else
			printf("%lld\n", ans / 2);
	}
	
	return 0;
}