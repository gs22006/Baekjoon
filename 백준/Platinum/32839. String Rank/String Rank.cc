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

string s;
int len;
int dp[3000010];
int minn[30];
int ans;

int main(void)
{
	fastio
	
	cin >> s;
	
	len = s.length();
	
	for(int i = len - 1 ; i >= 0 ; i--)
	{
		dp[i] = minn[s[i] - 'a'] + 1;
		
		for(int j = 0 ; j < 26 ; j++)
			minn[j] = min(minn[j], dp[i]);
		
		minn[s[i] - 'a'] = dp[i];
	}
	
	for(int i = 0 ; i < len ; i++)
		ans = max(ans, dp[i]);
	
	cout << ans;
	return 0;
}