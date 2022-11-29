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

#include <ext/rope>
using namespace __gnu_cxx;

char s[100010], tmp[100010];
ll q;
ll all, bll;
crope tmp2;

int main(void)
{
	fastio
	
	cin >> s;
	cin >> q;
	
	crope rp = s;
	
	while(q--)
	{
		cin >> all;
		
		if(all == 3)
		{
			cin >> all;
			cout << rp.substr(all, 1) en;
		}
		
		else if(all == 1)
		{
			cin >> all >> bll;
			
			tmp2 = rp.substr(all, bll - all + 1);
			rp.erase(all, bll - all + 1);
			tmp2 += rp;
			rp = tmp2;
		}
		
		else if(all == 2)
		{
			cin >> all >> bll;
			
			tmp2 = rp.substr(all, bll - all + 1);
			rp.erase(all, bll - all + 1);
			rp += tmp2;
		}
	}
	
	return 0;
}