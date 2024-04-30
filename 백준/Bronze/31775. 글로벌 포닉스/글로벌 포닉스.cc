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

string a, b, c;
string S;

int main(void)
{
	fastio
	
	cin >> a;
	cin >> b;
	cin >> c;
	
	S += a[0];
	S += b[0];
	S += c[0];
	
	sort(S.begin(), S.end());
	
	if(S == "klp")
		cout << "GLOBAL";
	else
		cout << "PONIX";
	
	return 0;
}