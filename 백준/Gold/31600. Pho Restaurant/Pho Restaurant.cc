#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second

ll n;
char a[200010];
pll cou[100010];
ll chk[2];
ll ans;
ll ff;

int main(void)
{
    scanf("%lld", &n);

    for(ll i = 1 ; i <= n ; i++)
    {
        scanf("%s", a);

        ll len = strlen(a);

        for(ll j = 0 ; j < len ; j++)
        {
            if(a[j] == '0')
                cou[i].fi++;
            else
                cou[i].se++;
        }

        if(cou[i].fi && cou[i].se)
            ff = 1;
    }

    if(!ff)
    {
        printf("0");
        return 0;
    }

    for(ll i = 1 ; i <= n ; i++)
    {
        if(cou[i].fi != cou[i].se)
        {
            if(cou[i].fi < cou[i].se)
            {
                chk[0] = 1;
                ans += cou[i].fi;
            }

            else
            {
                chk[1] = 1;
                ans += cou[i].se;
            }
        }
    }

    for(ll i = 1 ; i <= n ; i++)
    {
        if(cou[i].fi == cou[i].se)
        {
            if(!chk[0])
            {
                ans += cou[i].fi;
                chk[0] = 1;
            }

            else
            {
                ans += cou[i].se;
                chk[1] = 1;
            }
        }
    }

    if(!chk[0])
    {
        ll minn = (1LL << 60);

        for(ll i = 1 ; i <= n ; i++)
            minn = min(minn, cou[i].fi - cou[i].se);
        
        ans += minn;
    }

    else if(!chk[1])
    {
        ll minn = (1LL << 60);

        for(ll i = 1 ; i <= n ; i++)
            minn = min(minn, cou[i].se - cou[i].fi);
        
        ans += minn;
    }

    printf("%lld", ans);
    return 0;
}