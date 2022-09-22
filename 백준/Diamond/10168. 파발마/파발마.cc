#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL
 
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
     
    void insert(ll xx, ll yy)
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
}ccw, cw;
 
ll n;
ll a[1000010];
ll nu;
ll ccwdp[1000010];
ll ans = MAX;
ll chk1, chk2;
 
int main(void)
{
    scanf("%lld", &n);
     
    for(ll i = 1 ; i <= n ; i++)
        scanf("%lld", &a[i]);
     
    ccw.insert(1, 0);
    nu = 0;
     
    for(ll i = 1 ; i <= n ; i++)
    {
        nu += a[i];
         
        if(!a[i])
        {
            ccwdp[i] = ccwdp[i - 1];
            continue;
        }
         
        if(chk1)
            ccwdp[i] = min(ccw.query(i) + nu * i, (nu + 1) * i);
         
        else
        {
            chk1 = 1;
            ccwdp[i] = (nu + 1) * i;
        }
         
        ccw.insert(1 - nu, ccwdp[i]);
    }
     
    reverse(a + 1, a + 1 + n);
     
    cw.insert(1, 0);
    nu = 0;
     
    for(ll i = 1 ; i <= n ; i++)
    {
        nu += a[i];
         
        if(!a[i])
        {
            a[i] = a[i - 1];
            continue;
        }
         
        if(chk2)
            a[i] = min(cw.query(i) + nu * i, (nu + 1) * i);
         
        else
        {
            chk2 = 1;
            a[i] = (nu + 1) * i;
        }
         
        cw.insert(1 - nu, a[i]);
    }
     
    reverse(a + 1, a + 1 + n);
     
    for(ll i = 0 ; i < n ; i++)
    {
        //printf("%lld %lld\n", ccwdp[i + 1], a[i + 1]);
        ans = min(ans, ccwdp[i] + a[i + 1]);
    }
      
    printf("%lld", min(ans, ccwdp[n] + a[0]));
    return 0;
}