#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

void one(ll X);
void four(ll X);

ll n;
ll gaet;

ll query(ll X)
{
	ll ret = 0;
	
	printf("%lld\n", X);
	fflush(stdout);
	
	gaet -= X;
	
	if(!gaet)
		return 0;
	
	scanf("%lld", &ret);
	
	return ret;
}

void one(ll X)
{
	if(!X)
		return;
	
	if(X % 5 == 1)
	{
		ll gap = query(1);
		
		gaet -= gap;
		one(X - gap - 1);
	}
	
	else if(X % 5 == 2 || X % 5 == 3)
	{
		ll gap = query(X % 5);
		
		gaet -= gap;
		one(X - gap - X % 5);
	}
	
	else if(X % 5 == 4)
		four(X);
	
	else if(X % 5 == 0)
		assert(0);
}

void four(ll X)
{
	if(!X)
		return;
	
	if(X % 5 == 4)
	{
		ll gap = query(1);
		
		gaet -= gap;
		four(X - gap - 1);
	}
	
	else if(X % 5 == 1)
		one(X);
	
	else if(X % 5 == 2 || X % 5 == 3)
	{
		ll gap = query(X % 5);
		
		gaet -= gap;
		four(X - gap - X % 5);
	}
	
	else if(X % 5 == 0)
		assert(0);
}

int main(void)
{
	scanf("%lld", &n);
	
	gaet = n;
	
	if(n % 5 == 2 || n % 5 == 3 || n % 5 == 0)
	{
		printf("NO\n");
		fflush(stdout);
		
		return 0;
	}
	
	printf("YES\n");
	fflush(stdout);
	
	if(n % 5 == 1)
		one(n);
	else
		four(n);
	
	return 0;
}