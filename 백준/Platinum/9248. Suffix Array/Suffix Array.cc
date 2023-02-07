#include <bits/stdc++.h>

using namespace std;
typedef int ll;
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

struct help
{
	ll X, Y, num;
};

char a[2000010];
ll n;
ll grp[2000010];
ll twoo;
help SA[2000010];
ll tmp[2000010];
ll rdx[2000010];
help tmp2[2000010];
ll SISIZ;
ll LCP[2000010], last;

void do_sort(void)
{
	for(ll i = 0 ; i <= SISIZ ; i++)
		rdx[i] = 0;
	
	for(ll i = 0 ; i < n ; i++)
		rdx[SA[i].Y]++;
	
	for(ll i = 1 ; i <= SISIZ ; i++)
		rdx[i] += rdx[i - 1];
	
	for(ll i = n - 1 ; i >= 0 ; i--)
		tmp2[rdx[SA[i].Y]--] = SA[i];
	
	for(ll i = 0 ; i < n ; i++)
		SA[i] = tmp2[i + 1];
	
	for(ll i = 0 ; i <= SISIZ ; i++)
		rdx[i] = 0;
	
	for(ll i = 0 ; i < n ; i++)
		rdx[SA[i].X]++;
	
	for(ll i = 1 ; i <= SISIZ ; i++)
		rdx[i] += rdx[i - 1];
	
	for(ll i = n - 1 ; i >= 0 ; i--)
		tmp2[rdx[SA[i].X]--] = SA[i];
	
	for(ll i = 0 ; i < n ; i++)
		SA[i] = tmp2[i + 1];
}

int main(void)
{
	fastio
	
	cin >> a;
	
	n = strlen(a);
	
	SISIZ = n * 2;
	
	for(ll i = 0 ; i < n ; i++)
	{
		grp[i] = a[i] - 'a' + 1;
		SISIZ = max(SISIZ, grp[i] + n);
	}
	
	for(twoo = 1 ; ; twoo <<= 1)
	{
		for(ll i = 0 ; i < n ; i++)
		{
			SA[i].X = grp[i];
			
			if(i + twoo >= n)
				SA[i].Y = -1 + n;
			else
				SA[i].Y = grp[i + twoo] + n;
			
			SA[i].num = i;
		}
		
		for(ll i = 0 ; i < n ; i++)
		{
			if(SA[i].X > 2000000 || SA[i].Y > 2000000)
				assert(0);
		}
		
		do_sort();
		
		ll cc = 0;
		
		tmp[SA[0].num] = 0;
		
		for(ll i = 1 ; i < n ; i++)
		{
			if(SA[i].X != SA[i - 1].X || SA[i].Y != SA[i - 1].Y)
				cc++;
			
			tmp[SA[i].num] = cc;
		}
		
		for(ll i = 0 ; i < n ; i++)
			grp[i] = tmp[i];
		
		if(cc == n - 1)
			break;
	}
	
	for(ll i = 0 ; i < n ; i++)
		cout << SA[i].num + 1 sp;
	
	cout en;
	
	for(ll i = 0 ; i < n ; i++)
		tmp[SA[i].num] = i;
	
	for(ll i = 0 ; i < n ; i++, last = max(0, last - 1))
	{
		ll num1 = i, num2 = 0;
		
		if(tmp[i] == n - 1)
		{
			LCP[i] = -1;
			continue;
		}
		
		num2 = SA[tmp[i] + 1].num;
		
		for(ll j = last ; ; j++)
		{
			if(num1 + j >= n || num2 + j >= n)
				break;
			
			if(a[num1 + j] == a[num2 + j])
				last++;
			else
				break;
		}
		
		LCP[i] = last;
	}
	
	cout << "x ";
	
	for(ll i = 0 ; i < n - 1 ; i++)
		cout << LCP[SA[i].num] sp;
	
	return 0;
}