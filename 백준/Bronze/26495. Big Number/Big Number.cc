#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 987654321
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

string a;

void print(ll X)
{
	if(X == 0)
	{
		cout << "0000" en;
		cout << "0  0" en;
		cout << "0  0" en;
		cout << "0  0" en;
		cout << "0000" en;
	}
	
	else if(X == 1)
	{
		cout << "   1" en;
		cout << "   1" en;
		cout << "   1" en;
		cout << "   1" en;
		cout << "   1" en;
	}
	
	else if(X == 2)
	{
		cout << "2222" en;
		cout << "   2" en;
		cout << "2222" en;
		cout << "2" en;
		cout << "2222" en;
	}
	
	else if(X == 3)
	{
		cout << "3333" en;
		cout << "   3" en;
		cout << "3333" en;
		cout << "   3" en;
		cout << "3333" en;
	}
	
	else if(X == 4)
	{
		cout << "4  4" en;
		cout << "4  4" en;
		cout << "4444" en;
		cout << "   4" en;
		cout << "   4" en;
	}
	
	else if(X == 5)
	{
		cout << "5555" en;
		cout << "5" en;
		cout << "5555" en;
		cout << "   5" en;
		cout << "5555" en;
	}
	
	else if(X == 6)
	{
		cout << "6666" en;
		cout << "6" en;
		cout << "6666" en;
		cout << "6  6" en;
		cout << "6666" en;
	}
	
	else if(X == 7)
	{
		cout << "7777" en;
		cout << "   7" en;
		cout << "   7" en;
		cout << "   7" en;
		cout << "   7" en;
	}
	
	else if(X == 8)
	{
		cout << "8888" en;
		cout << "8  8" en;
		cout << "8888" en;
		cout << "8  8" en;
		cout << "8888" en;
	}
	
	else if(X == 9)
	{
		cout << "9999" en;
		cout << "9  9" en;
		cout << "9999" en;
		cout << "   9" en;
		cout << "   9" en;
	}
}

int main(void)
{
	fastio
	
	cin >> a;
	
	for(ll i = 0 ; i < (ll)a.size() ; i++)
	{
		print(a[i] - '0');
		
		if(i < (ll)a.size() - 1)
			cout en;
	}
	
	return 0;
}