#include "bogoSort.h"
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

void sort_array(int N)
{
	for(ll i = 0 ; i < N ; i++)
	{
		vector<int> tmp;
		
		while(1)
		{
			tmp = copy_array();
			
			if(tmp[i] == i)
				break;
			
			ll w = -1;
			
			for(ll j = i + 1 ; j < N ; j++)
			{
				if(tmp[j] == i)
				{
					w = j;
					break;
				}
			}
			
			shuffle_array(i, w);
		}
	}
}