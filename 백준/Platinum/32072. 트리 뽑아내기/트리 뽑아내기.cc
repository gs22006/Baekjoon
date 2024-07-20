#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second

ll n;
ll P[300010];
ll a[300010];
vector<ll> vec[300010], ans;
ll L[300010], R[300010];
ll cc;
ll yuk[300010];
ll INF;

void dfs0(ll here, ll pa)
{
    L[here] = ++cc;

    for(auto &i : vec[here])
    {
        if(i == pa)
            continue;
        
        dfs0(i, here);
    }
    
    R[here] = cc;
}

struct lazysegtree
{
    ll seg[2000010];
    ll lazy[2000010];

    void prop(ll no, ll s, ll e)
    {
        seg[no] += lazy[no];

        if(s != e)
        {
            lazy[no << 1] += lazy[no];
            lazy[no << 1 | 1] += lazy[no];
        }

        lazy[no] = 0;
    }

    void update(ll no, ll s, ll e, ll l, ll r, ll v)
    {
        prop(no, s, e);

        if(e < l || r < s)
            return;

        if(l <= s && e <= r)
        {
            seg[no] += v;

            if(s != e)
            {
                lazy[no << 1] += v;
                lazy[no << 1 | 1] += v;
            }

            return;
        }

        update(no << 1, s, (s + e) >> 1, l, r, v);
        update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, v);

        seg[no] = max(seg[no << 1], seg[no << 1 | 1]);
    }

    ll query(ll no, ll s, ll e, ll l, ll r)
    {
        prop(no, s, e);

        if(e < l || r < s)
            return -(1LL << 60);
        
        if(l <= s && e <= r)
            return seg[no];
        
        return max(query(no << 1, s, (s + e) >> 1, l, r), query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r));
    }
}segt;

void f(ll here)
{
    segt.update(1, 1, n, L[here], L[here], -INF);

    while(1)
    {
        ll gap = segt.query(1, 1, n, L[here], R[here]);

        if(gap < 0)
            break;

        ll W = yuk[gap];

        f(W);
    }

    ans.push_back(a[here]);
}

int main(void)
{
    scanf("%lld", &n);

    for(ll i = 2 ; i <= n ; i++)
    {
        scanf("%lld", &P[i]);

        vec[P[i]].push_back(i);
        vec[i].push_back(P[i]);
    }

    for(ll i = 1 ; i <= n ; i++)
    {
        scanf("%lld", &a[i]);
        yuk[a[i]] = i;
    }
    
    dfs0(1, 0);

    for(ll i = 1 ; i <= n ; i++)
        segt.update(1, 1, n, L[i], L[i], a[i]);
    
    INF = 300000 * 100;

    f(1);

    reverse(ans.begin(), ans.end());

    for(auto &i : ans)
        printf("%lld\n", i);
    
    return 0;
}