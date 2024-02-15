#include <bits/stdc++.h>

using namespace std;
typedef int ll;
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

ll pos[30], chk[30];
ll fail[1000010];
ll pos2[1000010], pos3[1000010];

int findP(char T[], char P[], int n, int m)
{
	for(ll i = 0 ; i < 26 ; i++)
		pos[i] = chk[i] = -1;
	
	for(ll i = 0 ; i < m ; i++)
		fail[i] = 0;
	
	for(ll i = 0 ; i < m ; i++)
	{
		if(pos[P[i] - 'a'] == -1)
			pos[P[i] - 'a'] = i;
	}
	
	for(ll i = 0 ; i < m ; i++)
	{
		pos2[i] = chk[P[i] - 'a'];
		chk[P[i] - 'a'] = i;
	}
	
	for(ll i = 0 ; i < 26 ; i++)
		chk[i] = -1;
	
	for(ll i = 0 ; i < n ; i++)
	{
		pos3[i] = chk[T[i] - 'a'];
		chk[T[i] - 'a'] = i;
	}
	
	ll p = 0;
	
	fail[0] = 0;
	
	for(ll i = 1 ; i < m ; i++)
	{
		while(p)
		{
			if(P[i - p + pos[P[p] - 'a']] == P[i] && (pos2[i] == -1 || p - i + pos2[i] < 0 || (P[p - i + pos2[i]] == P[p])))
				break;
			
			p = fail[p - 1];
		}
		
		if(P[i - p + pos[P[p] - 'a']] == P[i] && (pos2[i] == -1 || p - i + pos2[i] < 0 || (P[p - i + pos2[i]] == P[p])))
			p++;
		
		fail[i] = p;
	}
	
	ll ans = 0;
	p = 0;
	
	for(ll i = 0 ; i < n ; i++)
	{
		while(p)
		{
			if(T[i - p + pos[P[p] - 'a']] == T[i] && (pos3[i] == -1 || p - i + pos3[i] < 0 || (P[p - i + pos3[i]] == P[p])))
				break;
			
			p = fail[p - 1];
		}
		
		if(T[i - p + pos[P[p] - 'a']] == T[i] && (pos3[i] == -1 || p - i + pos3[i] < 0 || (P[p - i + pos3[i]] == P[p])))
			p++;
		
		if(p == m)
		{
			ans++;
			p = fail[m - 1];
		}
	}
	
	return ans;
}