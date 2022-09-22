
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

ll n;
vector<ll> ans, print;
ll yun;
vector<ll> Sosu;
ll era[1000010];
ll won;

ll gop(ll x, ll y, ll ss)
{
	x %= ss;
	y %= ss;
	
	ll r = 0;
	ll w = x;
	
	while(y)
	{
		if(y & 1)
			r = (r + w) % ss;
		
		yun++;
		
		if(yun >= 5e7)
			break;
		w = (w + w) % ss;
		y >>= 1;
	}
	
	return r;
}

struct miller_rabin
{
    //maybe has to use unsigned long long
    
    ll num[20] = {2, 3, 5, 7, 11, 61};
    
    ll pow(ll x, ll y, ll ss)
    {
        ll ret = 1;
        
        x %= ss;
        
        while(y > 0)
        {
            if(y % 2)
                ret = ret * x % ss;
            
            y /= 2;
            x = x * x % ss;
        }
        
        return ret;
    }
    
    ll miller(ll x, ll y)
    {
        if(y % x == 0)
            return 0;
        
        ll z = x - 1;
        
        while(1)
        {
            ll tmp = pow(y, z, x);
            
            if(tmp == x - 1)
                return 1;
            else if(z % 2)
                return (tmp == 1 || tmp == x - 1);
            
            z /= 2;
        }
    }
    
    ll is_sosu(ll x)
    {
        for(ll i = 0 ; i < 6 ; i++)
        {
            if(x == num[i])
                return 1;
            
            if(!miller(x, num[i]))
                return 0;
        }
        
        return 1;
    }
}sosu;

ll G(ll x, ll ss, ll y)
{
	return (gop(x, x, ss) + y) % ss < 0 ? (gop(x, x, ss) + y) % ss + ss : (gop(x, x, ss) + y) % ss;
}

ll p_ro(ll x, ll S, ll P)
{
	ll all = S;
	ll bll = S;
	ll dll = 1;
	
	while(dll == 1)
	{
		all = G(all, x, P);
		bll = G(G(bll, x, P), x, P);
		dll = __gcd(abs(all - bll), x);
		yun++;
		
		if(yun >= 5e7)
			break;
		//printf("%lld %lld %lld\n", all, bll, dll);
	}
	
	if(dll == n)
		return -1;
	else
		return dll;
}

int main(void)
{
	srand(time(0));
	
	for(ll i = 2 ; i < 1000010 ; i++)
	{
		if(era[i])
			continue;
		
		Sosu.push_back(i);
		
		for(ll j = i * i ; j < 1000010 ; j += i)
			era[j] = 1;
	}
	
	scanf("%lld", &n);
	won = n;
	
	while(n > 1)
	{
		ll srt = rand() % n;
		ll plu = rand() % n;
		ll R = p_ro(n, srt, plu);
		if(yun >= 5e7)
		{
			ans.push_back(n);
			break;
		}
		//printf("%lld %lld\n", n, R);
		if(yun >= 5e7)
		{
			ans.push_back(n);
			break;
		}
		if(abs(R) == 1)
		{
			ans.push_back(n);
			break;
		}
		if(yun >= 5e7)
		{
			ans.push_back(n);
			break;
		}
		ans.push_back(R);
		n /= R;
		yun++;
		
		if(yun >= 5e7)
		{
			ans.push_back(n);
			break;
		}
	}	
	
	sort(ans.begin(), ans.end());
	
	for(ll i = 0 ; i < ans.size() ; i++)
	{
		if(sosu.is_sosu(ans[i]))	
		{
			//printf("sosu : %lld\n", ans[i]);
			print.push_back(ans[i]);
			continue;
		}
		
		ll gap = ans[i];
		
		for(ll j = 0 ; j < Sosu.size() ; j++)
		{
			//printf("%lld %lld\n", ans[i], Sosu[j]);
			
			if(Sosu[j] * Sosu[j] > gap)
				break;
			
			if(ans[i] % Sosu[j])
				continue;
				
			while(ans[i] % Sosu[j] == 0)
			{
				print.push_back(Sosu[j]);
				ans[i] /= Sosu[j];
			}
		}
		
		if(ans[i] != 1)
			print.push_back(ans[i]);
	}
	
	sort(print.begin(), print.end());
	
	for(ll i = 0 ; i < print.size() ; i++)
	{
		if(i == 0 || print[i] != print[i - 1])
			won = won / print[i] * (print[i] - 1);
	}
	
	printf("%lld", won);
	return 0;
}