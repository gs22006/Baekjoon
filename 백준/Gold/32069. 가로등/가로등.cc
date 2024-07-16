#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second

ll L, n, K;
ll a[500010];
queue<pll> q;
map<ll, ll> chk;
ll cou;

int main(void)
{
    scanf("%lld %lld %lld", &L, &n, &K);

    for(ll i = 1 ; i <= n ; i++)
    {
        scanf("%lld", &a[i]);

        if(cou < K)
        {
            q.push({a[i], 0});
            chk[a[i]] = 1;
            cou++;
        }
    }

    while(!q.empty())
    {
        pll qq = q.front();
        q.pop();

        printf("%lld\n", qq.se);

        if(qq.fi - 1 >= 0 && chk.find(qq.fi - 1) == chk.end() && cou < K)
        {
            q.push({qq.fi - 1, qq.se + 1});
            chk[qq.fi - 1] = 1;
            cou++;
        }

        if(qq.fi + 1 <= L && chk.find(qq.fi + 1) == chk.end() && cou < K)
        {
            q.push({qq.fi + 1, qq.se + 1});
            chk[qq.fi + 1] = 1;
            cou++;
        }
    }

    return 0;
}