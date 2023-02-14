#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n;
ll all;
vector<ll> vec;
ll dp[3000010], chkk[3000010];
ll fibo[100010];
ll ans;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 0 ; i < n ; i++)
	{
		cin >> all;
		vec.push_back(all);
	}
	
	fibo[1] = 1;
	fibo[2] = 2;
	
	for(ll i = 3 ; ; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		
		if(fibo[i] > 3000000)
			break;
	}
	
	for(ll i = 1 ; i <= 3000000 ; i++)
	{
		for(ll j = 1 ; ; j++)
		{
			if(i < fibo[j])
				break;
			
			chkk[dp[i - fibo[j]]] = i;
		}
		
		while(1)
		{
			if(chkk[dp[i]] != i)
				break;
			
			dp[i]++;
		}
	}
	
	for(auto &i : vec)
		ans ^= dp[i];
	
	if(!ans)
		cout << "cubelover";
	else
		cout << "koosaga";
	
	return 0;
}