#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fi first
#define se second
#define INF (1LL << 60);

ll n;
ll all, bll;
vector<ll> vec[5010];
ll sub[5010];
ll L[5010], R[5010];
ll dp[5010][5010];
ll sum[5010];
ll ans = INF;

void dfs0(ll here, ll pa)
{
    sub[here] = 1;

    for(auto &i : vec[here])
    {
        if(i == pa)
            continue;
        
        dfs0(i, here);
        sub[here] += sub[i];
    }
}

void dfs(ll here, ll pa)
{
    vector<pll> chld;

    chld.push_back({0, 0});

    for(auto &i : vec[here])
    {
        if(i == pa)
            continue;
        
        dfs(i, here);
        chld.push_back({sub[i], i});
    }

    sort(chld.begin(), chld.end());

    ll siz = (ll)chld.size() - 1;

    for(ll i = 1 ; i <= siz ; i++)
        sum[i] = sum[i - 1] + chld[i].fi;
    
    for(ll i = 0 ; i <= siz ; i++)
    {
        for(ll j = 0 ; j <= n ; j++)
            dp[i][j] = INF;
    }

    dp[0][0] = 0;

    for(ll i = 0 ; i < siz ; i++)
    {
        for(ll j = 0 ; j <= n ; j++)
        {
            dp[i + 1][j + chld[i + 1].fi] = min(dp[i + 1][j + chld[i + 1].fi], dp[i][j] + 1 + L[chld[i + 1].se] + j);
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1 + R[chld[i + 1].se] + sum[i] - j);
        }
    }

    L[here] = R[here] = ans = INF;

    for(ll i = 0 ; i <= n ; i++)
    {
        L[here] = min(L[here], dp[siz][i] + i);
        R[here] = min(R[here], dp[siz][i] + sum[siz] - i);
        ans = min(ans, dp[siz][i]);
    }
}

int main(void)
{
    fastio
    
    cin >> n;

    for(ll i = 1 ; i < n ; i++)
    {
        cin >> all >> bll;

        vec[all].push_back(bll);
        vec[bll].push_back(all);
    }

    dfs0(1, 0);
    dfs(1, 0);

    cout << ans;
    return 0;
}