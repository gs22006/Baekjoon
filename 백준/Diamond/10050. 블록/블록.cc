#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n;
ll a[1010];

void move(ll x, ll y)
{
	printf("%lld to %lld\n", x, y);
	swap(a[x + 2 * n], a[y + 2 * n]);
	swap(a[x + 2 * n + 1], a[y + 2 * n + 1]);
}

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= 2 * n ; i++)
		a[i] = 0;
	
	for(ll i = 1 ; i <= 2 * n ; i++)
		a[2 * n + i] = (i - 1) % 2 + 1;
	
	if(n <= 8)
	{
		if(n == 3)
		{
			move(2, -1);
			move(5, 2);
			move(3, -3);
		}
		
		else if(n == 4)
		{
			move(6, -1);
			move(3, 6);
			move(0, 3);
			move(7, 0);
		}
		
		else if(n == 5)
		{
			move(8, -1);
			move(3, 8);
			move(6, 3);
			move(0, 6);
			move(9, 0);
		}
		
		else if(n == 6)
		{
			move(10, -1);
			move(7, 10);
			move(2, 7);
			move(6, 2);
			move(0, 6);
			move(11, 0);
		}
		
		else if(n == 7)
		{
			move(8, -1);
			move(5, 8);
			move(12, 5);
			move(3, 12);
			move(9, 3);
			move(0, 9);
			move(13, 0);
		}
		
		else if(n == 8)
		{
			move(4, -1);
			move(9, 4);
			move(14, 9);
			move(11, 14);
			move(0, 11);
			move(8, 0);
			move(3, 8);
			move(15, 3);
		}
	}
	
	else if(n % 4 == 2)
	{
		ll mid1 = n - 2;
		ll mid2 = n - 1;
		vector<ll> w;
		ll bin = -1;
		ll cou = 0;
		
		move(2 * n - 2, bin);
		cou++;
		bin = 2 * n - 2;
		
		w.push_back(3);
		
		while(1)
		{
			ll plu = 0;
			
			if((ll)w.size() % 2 == 1)
				plu = 5;
			else
				plu = 3;
			
			if(w.back() + plu >= mid1 - 2)
				break;
			
			w.push_back(w.back() + plu);
		}
		
		w.push_back(2 * n - 5);
		ll help = 0;
		
		while(1)
		{
			ll mi = 0;
			
			if(help % 2 == 0)
				mi = 5;
			else
				mi = 3;
			
			if(w.back() - mi <= mid2)
				break;
			
			w.push_back(w.back() - mi);
			help++;
		}
		
		sort(w.begin(), w.end());
		w.push_back(n - 4);
		
		for(ll i : w)
		{
			move(i, bin);
			cou++;
			bin = i;
		}
		
		while(1)
		{
			if(cou == n)
				break;
			
			ll w = 0;
			
			if(bin <= n - 2)
			{
				for(ll i = n - 1 ; i <= 2 * n ; i++)
				{
					if(a[i + 2 * n] == 2)
					{
						w = i;
						break;
					}
				}
			}
			
			else
			{
				for(ll i = -1 ; i <= n - 2 ; i++)
				{
					if(a[i + 2 * n] == 1)
					{
						w = i;
						break;
					}
				}
			}
			
			move(w, bin);
			cou++;
			bin = w;
		}
	}
	
	else if(n % 4 == 3)
	{
		ll bin = -1;
		ll cou = 0;
		ll mid1 = n - 4, mid2 = n - 1;
		vector<ll> w;
		
		move(2 * n - 2, bin);
		cou++;
		bin = 2 * n - 2;
		
		w.push_back(3);
		
		while(1)
		{
			ll plu = 0;
			
			if((ll)w.size() % 2 == 1)
				plu = 5;
			else
				plu = 3;
			
			if(w.back() + plu >= mid1 - 1)
				break;
			
			w.push_back(w.back() + plu);
		}
		
		if((ll)w.size() % 2 == 0)
		{
			w.push_back(mid2 - 1);
			ll ccc = 0;
			
			while(1)
			{
				ll plu = 0;
				
				if(ccc % 2 == 0)
					plu = 3;
				else
					plu = 5;
				
				if(w.back() + plu >= 2 * n - 4)
					break;
				
				w.push_back(w.back() + plu);
				ccc++;
			}
			
			w.push_back(mid1);
		}
		
		else
		{
			w.push_back(mid2 + 2);
			w.push_back(mid2 - 1);
			w.push_back(mid2 + 6);
			
			ll ccc = 0;
			
			while(1)
			{
				ll plu = 0;
				
				if(ccc % 2 == 0)
					plu = 5;
				else
					plu = 3;
				
				if(w.back() + plu >= 2 * n - 3)
					break;
				
				w.push_back(w.back() + plu);
				ccc++;
			}
			
			w.push_back(mid1);
		}
		
		for(ll i : w)
		{
			move(i, bin);
			cou++;
			bin = i;
		}
		
		while(1)
		{
			if(cou == n)
				break;
			
			ll w = 0;
			
			if(bin <= n - 2)
			{
				for(ll i = n - 1 ; i <= 2 * n ; i++)
				{
					if(a[i + 2 * n] == 2)
					{
						w = i;
						break;
					}
				}
			}
			
			else
			{
				for(ll i = -1 ; i <= n - 2 ; i++)
				{
					if(a[i + 2 * n] == 1)
					{
						w = i;
						break;
					}
				}
			}
			
			move(w, bin);
			cou++;
			bin = w;
		}
	}
	
	else
	{	
		ll bin1 = -1, bin2 = 0;
		ll s = 3;
		ll e = 2 * n - 2;
		ll cou = 0;
		
		while(1)
		{
			if(cou % 2 == 0)
			{
				if(a[e + n * 2] && a[e + 1 + n * 2])
				{
					move(e, bin1);
					bin1 = e;
					bin2 = e + 1;
					e -= 4;
				}
				
				else
					break;
			}
			
			else
			{
				if(a[s + n * 2] && a[s + 1 + n * 2])
				{
					move(s, bin1);
					bin1 = s;
					bin2 = s + 1;
					s += 4;
				}
				
				else
					break;
			}
			
			cou++;
		}
		
		if(a[bin2 + 2 + n * 2] == 2)
		{
			ll w = bin2 + 2;
			
			cou++;
			move(w, bin1);
			bin1 = w;
			bin2 = w + 1;
		}
		
		else if(a[bin1 - 2 + n * 2] == 2)
		{
			ll w = bin1 - 3;
			
			cou++;
			move(w, bin1);
			bin1 = w;
			bin2 = w + 1;
		}
		
		ll ss = 0, ee = 0;
		
		for(ll i = 1 ; i <= 4 * n ; i++)
		{
			if(a[i] == 1 && a[i + 1] == 1)
			{
				ss = i - 2 * n;
				break;
			}
		}
		
		ll ff = 0, gg = 0;
		
		for(ll i = 1 ; i <= 4 * n ; i++)
		{
			if(a[i] == 2)
				gg = 1;
			
			if(gg && a[i] == 0)
				ff = 1;
			
			if(ff && a[i] == 2 && a[i + 1] == 2)
			{
				ee = i - 2 * n;
				break;
			}
		}
		
		ll cc = 1;
		
		while(1)
		{
			if(cou == n)
				break;
			
			if(cc & 1)
			{
				move(ss, bin1);
				bin1 = ss;
				bin2 = ss + 1;
				
				ss += 4;
			}
			
			else
			{
				move(ee, bin1);
				bin1 = ee;
				bin2 = ee + 1;
				
				ee += 4;
			}
			
			cou++;
			cc++;
		}
	}
	
	return 0;
}