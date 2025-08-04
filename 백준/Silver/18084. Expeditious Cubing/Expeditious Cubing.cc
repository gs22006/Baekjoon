#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll a[10];
ll X;

ll input(void)
{
    ll w, f;
    char dot;
    
    cin >> w >> dot >> f;
    return w * 100 + f;
}

int main(void)
{
    fastio
    
    for(ll i = 1 ; i <= 4 ; i++)
        a[i] = input();
    
    X = input();
    
    sort(a + 1, a + 1 + 4);
    
    if((a[2] + a[3] + a[4]) <= X * 3)
    {
        cout << "infinite";
        return 0;
    }
    
    ll x2 = X * 3 - (a[2] + a[3]);
    
    if(a[1] <= x2 && x2 <= a[4])
    {
        ll ans = x2;
        ll ans2 = ans % 100;
        
		cout << ans / 100 << "." << ans2 / 10 << ans2 % 10;
        return 0;
    }
    
	if((a[1] + a[2] + a[3]) <= X * 3)
    {
        ll ans = a[1];
        ll ans2 = ans % 100;
        
		cout << ans / 100 << "." << ans2 / 10 << ans2 % 10;
        return 0;
    }
    
    cout << "impossible";
    return 0;
}
