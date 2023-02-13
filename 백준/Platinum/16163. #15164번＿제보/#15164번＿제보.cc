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

char a[2000010];
char b[4000010];
ll len;
ll n;
ll mana[4000010];
ll p, maxx;
ll ans;

int main(void)
{
	fastio
	
	cin >> a;
	
	len = strlen(a);
	
	for(ll i = 0 ; i < len ; i++)
	{
		b[n++] = a[i];
		b[n++] = '#';
	}
	
	n--;
	
	for(ll i = 0 ; i < n ; i++)
	{
		if(maxx < i)
			mana[i] = 0;
		else
			mana[i] = min(maxx - i, mana[p * 2 - i]);
		
		while(i + mana[i] + 1 < n && i - mana[i] - 1 >= 0 && b[i + mana[i] + 1] == b[i - mana[i] - 1])
			mana[i]++;
		
		if(mana[i] + i > maxx)
		{
			maxx = i + mana[i];
			p = i;
		}
	}
	
	for(ll i = 0 ; i < n ; i++)
	{
		if(i & 1)
			ans += (mana[i] + 1) / 2;
		else
			ans += mana[i] / 2 + 1;
	}
	
	cout << ans;
	return 0;
}