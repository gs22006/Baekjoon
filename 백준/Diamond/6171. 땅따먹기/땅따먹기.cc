#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

ll n;
pair<ll, ll> a[50010];
ll now = -1, las;

struct lin
{
    ll A;
    ll B;
    ld G;
};

ld cross(lin xx, lin yy)
{
    return (ld)(yy.B - xx.B) / (ld)(xx.A - yy.A);
}

struct CHT
{
    lin LL[1000010];
    ll idx = 0;
     
    void update(ll xx, ll yy)
    {
        LL[idx].A = xx;
        LL[idx].B = yy;
         
        while(1 < idx && cross(LL[idx - 2], LL[idx - 1]) > cross(LL[idx - 1], LL[idx]))
        {
            LL[idx - 1] = LL[idx];
            idx--;
        }
         
        idx++;
    }
     
    ll query(ll xx)
    {
        ll lef = 0;
        ll rig = idx - 1;
         
        while(lef < rig)
        {
            ll mid = (lef + rig) / 2;
             
            if(cross(LL[mid], LL[mid + 1]) <= xx)
                lef = mid + 1;
            else
                rig = mid;
        }
         
        return LL[lef].A * xx + LL[lef].B;
    }
}cht;

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld %lld", &a[i].first, &a[i].second);
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = n ; i >= 1 ; i--)
	{
		if(now >= a[i].second)
			continue;
		
		now = a[i].second;
		cht.update(a[i].first, las);
		las = cht.query(a[i].second);
	}
	
	printf("%lld", las);
	return 0;
}