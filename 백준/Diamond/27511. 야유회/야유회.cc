#include "workshop.h"
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

void init() { }

ll comp(ll X, ll Y)
{
	for(ll i = 0 ; ; i++)
	{
		if((X & (1LL << i)) != (Y & (1LL << i)))
			return i * 2 + !!(X & (1LL << i));
	}
}

int morning(int my_num, int right_num)
{
	return comp(my_num, right_num);
}

int afternoon(int left_num, int my_num, int right_num)
{
	return my_num;
}

int evening(int left_num, int my_num, int right_num)
{
	return my_num;
}