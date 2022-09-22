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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set_ll tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_set_ld tree<ld, null_type, less_equal<ld>, rb_tree_tag, tree_order_statistics_node_update>

ll q;
ll all, bll;
ordered_set_ld st, st3;
ordered_set_ll st2;
ll bu = 1;
ll fff;

int main(void)
{
	fastio
	
	cin >> q;
	
	while(q--)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> all >> bll;
			
			if(!all)
			{
				if(bll == 0)
					bu = 0;
				else if(bll < 0)
					bu *= -1;
				
				continue;
			}
			
			if(!bll)
			{
				if(all < 0)
					st3.insert(0);
				else
					st.insert(0);
				
				st2.insert(0);
				continue;
			}
			
			if(all < 0)
				st3.insert(-(ld)bll / (ld)all);
			else
				st.insert((ld)bll / (ld)all);
			
			if(bll % all == 0)
				st2.insert(bll / all);
		}
		
		else
		{
			cin >> all;
			
			if(!bu || st2.find(-all) != st2.end())
			{
				cout << 0 en;
				continue;
			}
			
			ll gaet = st.order_of_key((ld)(-all)) + st3.order_of_key((ld)all);
			
			if(gaet & 1)
			{
				if(bu == 1)
					cout << "-\n";
				else
					cout << "+\n";
			}
			
			else
			{
				if(bu == 1)
					cout << "+\n";
				else
					cout << "-\n";
			}
		}
	}
	
	return 0;
}