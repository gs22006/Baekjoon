#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second

ll a[10], b[10];
vector<ll> hubo, tmp;
map< pair<pll, ll>, ll> mp;
pair<pll, ll> now;
queue<pair<pll, ll> > q;
queue<ll> cq;
pll tmpp[4];
pll nxt[4];
ll GAP[4];

void psh(ll cc)
{
    for(ll i = 1 ; i <= 3 ; i++)
        GAP[nxt[i].se] = nxt[i].fi;

    pair<pll, ll> Q;

    Q = {{GAP[1], GAP[2]}, GAP[3]};

    if(mp[Q])
        return;

    mp[Q] = 1;
    q.push(Q);
    cq.push(cc + 1);
}

int main(void)
{
    for(ll i = 1 ; i <= 3 ; i++)
        scanf("%lld", &a[i]);

    for(ll i = 1 ; i <= 3 ; i++)
        scanf("%lld", &b[i]);

    for(ll i = 1 ; i <= 3 ; i++)
    {
        for(ll j = -4 ; j <= 4 ; j++)
        {
            if(1 <= a[i] + j)
                hubo.push_back(a[i] + j);

            if(1 <= b[i] + j)
                hubo.push_back(b[i] + j);
        }
    }

    sort(hubo.begin(), hubo.end());

    for(auto &i : hubo)
    {
        if(tmp.empty() || tmp.back() != i)
            tmp.push_back(i);
    }

    hubo = tmp;

    now = {{a[1], a[2]}, a[3]};

    q.push(now);
    cq.push(0);
    mp[now] = 1;

    while(!q.empty())
    {
        pair<pll, ll> qq = q.front();
        q.pop();
        ll cc = cq.front();
        cq.pop();

        tmpp[1] = {qq.fi.fi, 1};
        tmpp[2] = {qq.fi.se, 2};
        tmpp[3] = {qq.se, 3};

        if(qq.fi.fi == b[1] && qq.fi.se == b[2] && qq.se == b[3])
        {
            printf("%lld", cc);
            return 0;
        }

        sort(tmpp + 1, tmpp + 4);

        for(auto &i : hubo)
        {
            if(tmpp[2].fi + 1 <= i && i <= tmpp[3].fi - 1)
            {
                nxt[1] = {i, tmpp[1].se};
                nxt[2] = tmpp[2];
                nxt[3] = tmpp[3];
                psh(cc);
            }

            if((1 <= i && i <= tmpp[1].fi - 1) || (tmpp[3].fi + 1 <= i))
            {
                nxt[1] = tmpp[1];
                nxt[2] = {i, tmpp[2].se};
                nxt[3] = tmpp[3];
                psh(cc);
            }

            if(tmpp[1].fi + 1 <= i && i <= tmpp[2].fi - 1)
            {
                nxt[1] = tmpp[1];
                nxt[2] = tmpp[2];
                nxt[3] = {i, tmpp[3].se};
                psh(cc);
            }
        }
    }

    return 0;
}