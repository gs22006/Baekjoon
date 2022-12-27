#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define MAX 2005
#define MOD (ll)(1e9+7)
#define INF (ll)(1e16)
constexpr double PI = acos(-1);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef complex<double> cpx;

ll N, M, K, Q;
ll dp[MAX][MAX][2];
ll arr[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    for(ll i = 1; i <= N; ++i) cin >> arr[i];
    
    ll sum = 0;
    for(ll i = 1; i <= N; ++i) sum += arr[i];
    
    ll ans = 0;
    for(ll i = 0; i <= N; ++i) for(ll j = 0; j <= K; ++j) dp[i][j][0] = dp[i][j][1] = -INF;
    
    ll maxx = 0;
    
    for(ll i = 1 ; i <= N ; i++)
    	maxx = max(maxx, arr[i]);
    
    if(K == 1)
    {
    	cout << maxx;
    	return 0;
	}
    
    dp[1][1][1] = arr[1];
    for(ll i = 2; i <= N; ++i) {
        for(ll k = 0; k <= K; ++k) {
            dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1]);
            if(k >= 1) dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - 1][0] + arr[i]);
            if(k >= 1 && i >= 2) dp[i][k][1] = max(dp[i][k][1], dp[i - 2][k - 1][1] + arr[i] + arr[i - 1]);
        }
    }
    if(dp[N][K][0] < 0 || dp[N - 1][K][1] < 0) {
        cout << sum; return 0;
    }
    ans = max(ans, max(dp[N - 1][K][1] + arr[N], dp[N][K][0]));
    
    for(ll i = 0; i <= N; ++i) for(ll j = 0; j <= K; ++j) dp[i][j][0] = dp[i][j][1] = -INF;
    dp[1][0][0] = 0;
    for(ll i = 2; i <= N; ++i) {
        for(ll k = 0; k <= K; ++k) {
            dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1]);
            if(k >= 1) dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - 1][0] + arr[i]);
            if(k >= 1 && i >= 2) dp[i][k][1] = max(dp[i][k][1], dp[i - 2][k - 1][1] + arr[i] + arr[i - 1]);
        }
    }
    if(dp[N][K][0] < 0 || dp[N][K][1] < 0) {
        cout << sum; return 0;
    }
    ans = max(ans, max(dp[N][K][0], dp[N][K][1]));
    
    for(ll i = 1; i <= N/2; ++i) swap(arr[i], arr[N - i + 1]);
    for(ll i = 0; i <= N; ++i) for(ll j = 0; j <= K; ++j) dp[i][j][0] = dp[i][j][1] = -INF;
    
    dp[1][1][1] = arr[1];
    for(ll i = 2; i <= N; ++i) {
        for(ll k = 0; k <= K; ++k) {
            dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1]);
            if(k >= 1) dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - 1][0] + arr[i]);
            if(k >= 1 && i >= 2) dp[i][k][1] = max(dp[i][k][1], dp[i - 2][k - 1][1] + arr[i] + arr[i - 1]);
        }
    }
    if(dp[N][K][0] < 0 || dp[N - 1][K][1] < 0) {
        cout << sum; return 0;
    }
    ans = max(ans, max(dp[N - 1][K][1] + arr[N], dp[N][K][0]));
    
    for(ll i = 0; i <= N; ++i) for(ll j = 0; j <= K; ++j) dp[i][j][0] = dp[i][j][1] = -INF;
    
    dp[1][0][0] = 0;
    for(ll i = 2; i <= N; ++i) {
        for(ll k = 0; k <= K; ++k) {
            dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1]);
            if(k >= 1) dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - 1][0] + arr[i]);
            if(k >= 1 && i >= 2) dp[i][k][1] = max(dp[i][k][1], dp[i - 2][k - 1][1] + arr[i] + arr[i - 1]);
        }
    }
    if(dp[N][K][0] < 0 || dp[N][K][1] < 0) {
        cout << sum; return 0;
    }
    ans = max(ans, max(dp[N][K][0], dp[N][K][1]));
    ll TMTM = arr[N];
    
    for(ll i = N ; i >= 2 ; i--)
    	arr[i] = arr[i - 1];
    
    arr[1] = TMTM;
    
    sum = 0;
    for(ll i = 1; i <= N; ++i) sum += arr[i];
    
    for(ll i = 0; i <= N; ++i) for(ll j = 0; j <= K; ++j) dp[i][j][0] = dp[i][j][1] = -INF;
    
    dp[1][1][1] = arr[1];
    for(ll i = 2; i <= N; ++i) {
        for(ll k = 0; k <= K; ++k) {
            dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1]);
            if(k >= 1) dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - 1][0] + arr[i]);
            if(k >= 1 && i >= 2) dp[i][k][1] = max(dp[i][k][1], dp[i - 2][k - 1][1] + arr[i] + arr[i - 1]);
        }
    }
    if(dp[N][K][0] < 0 || dp[N - 1][K][1] < 0) {
        cout << sum; return 0;
    }
    ans = max(ans, max(dp[N - 1][K][1] + arr[N], dp[N][K][0]));
    
    for(ll i = 0; i <= N; ++i) for(ll j = 0; j <= K; ++j) dp[i][j][0] = dp[i][j][1] = -INF;
    dp[1][0][0] = 0;
    for(ll i = 2; i <= N; ++i) {
        for(ll k = 0; k <= K; ++k) {
            dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1]);
            if(k >= 1) dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - 1][0] + arr[i]);
            if(k >= 1 && i >= 2) dp[i][k][1] = max(dp[i][k][1], dp[i - 2][k - 1][1] + arr[i] + arr[i - 1]);
        }
    }
    if(dp[N][K][0] < 0 || dp[N][K][1] < 0) {
        cout << sum; return 0;
    }
    ans = max(ans, max(dp[N][K][0], dp[N][K][1]));
    
    for(ll i = 1; i <= N/2; ++i) swap(arr[i], arr[N - i + 1]);
    for(ll i = 0; i <= N; ++i) for(ll j = 0; j <= K; ++j) dp[i][j][0] = dp[i][j][1] = -INF;
    
    dp[1][1][1] = arr[1];
    for(ll i = 2; i <= N; ++i) {
        for(ll k = 0; k <= K; ++k) {
            dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1]);
            if(k >= 1) dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - 1][0] + arr[i]);
            if(k >= 1 && i >= 2) dp[i][k][1] = max(dp[i][k][1], dp[i - 2][k - 1][1] + arr[i] + arr[i - 1]);
        }
    }
    if(dp[N][K][0] < 0 || dp[N - 1][K][1] < 0) {
        cout << sum; return 0;
    }
    ans = max(ans, max(dp[N - 1][K][1] + arr[N], dp[N][K][0]));
    
    for(ll i = 0; i <= N; ++i) for(ll j = 0; j <= K; ++j) dp[i][j][0] = dp[i][j][1] = -INF;
    
    dp[1][0][0] = 0;
    for(ll i = 2; i <= N; ++i) {
        for(ll k = 0; k <= K; ++k) {
            dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1]);
            if(k >= 1) dp[i][k][1] = max(dp[i][k][1], dp[i - 1][k - 1][0] + arr[i]);
            if(k >= 1 && i >= 2) dp[i][k][1] = max(dp[i][k][1], dp[i - 2][k - 1][1] + arr[i] + arr[i - 1]);
        }
    }
    if(dp[N][K][0] < 0 || dp[N][K][1] < 0) {
        cout << sum; return 0;
    }
    ans = max(ans, max(dp[N][K][0], dp[N][K][1]));
    
    cout << ans;
    return 0;
}
