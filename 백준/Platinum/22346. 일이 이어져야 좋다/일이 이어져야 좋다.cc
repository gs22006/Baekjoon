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

ll n;
ll q;
ll all, bll, cll;
vector<ll> vec;

struct node
{
	vector<ll> L;
	vector<ll> R;
	ll mx;
	ll ze;
	ll len;
}Z, O, H;

node a[110];

node merge(node n1, node n2, ll K)
{
	node ret;
	
	if(n1.ze == -1)
		return n2;
	
	if(n2.ze == -1)
		return n1;
	
	if(n1.ze <= K)
	{
		for(ll i = 0 ; i < n1.ze ; i++)
			ret.L.push_back(n1.L[i]);
		
		for(ll i = n1.ze ; i <= K ; i++)
			ret.L.push_back(n1.len + n2.L[i - n1.ze]);
	}
	
	else
	{
		for(ll i = 0 ; i <= K ; i++)
			ret.L.push_back(n1.L[i]);
	}
	
	if(n2.ze <= K)
	{
		for(ll i = 0 ; i < n2.ze ; i++)
			ret.R.push_back(n2.R[i]);
		
		for(ll i = n2.ze ; i <= K ; i++)
			ret.R.push_back(n2.len + n1.R[i - n2.ze]);
	}
	
	else
	{
		for(ll i = 0 ; i <= K ; i++)
			ret.R.push_back(n2.R[i]);
	}
	
	ret.mx = max(n1.mx, n2.mx);
	
	for(ll i = 0 ; i <= K ; i++)
		ret.mx = max(ret.mx, n1.R[i] + n2.L[K - i]);
	
	ret.ze = n1.ze + n2.ze;
	ret.len = n1.len + n2.len;
	
	return ret;
}

ll coco = 0;

node query(ll no, ll s, ll e, ll l, ll r)
{
	if(no < 0)
		return H;

	if(e < l || r < s || e < s)
		return H;

	if(l <= s && e <= r)
		return a[no];
	
	ll mid = ((s + e) >> 1);
	node LL, RR;
	
	LL = query(no - 1, s, mid - 1, l, r);
	RR = query(no - 1, mid + 1, e, l, r);
	
	if(l <= mid && mid <= r)
	{
		if(vec[no] & 1)
			return merge(merge(LL, O, cll), RR, cll);
		
		return merge(merge(LL, Z, cll), RR, cll);
	}
	
	if(r < mid)
		return LL;

	return RR;
}

int main(void)
{
	fastio
	
	cin >> n >> q;

	ll tmp = n;
	
	while(tmp)
	{
		vec.push_back(tmp);
		tmp >>= 1;
	}
	
	compress(vec);

	while(q--)
	{
		cin >> all >> bll >> cll;
		
		Z.L.clear();
		O.L.clear();
		Z.R.clear();
		O.R.clear();

		for(ll i = 0 ; i <= cll ; i++)
		{
			Z.L.push_back(1);
			O.L.push_back(1);
			Z.R.push_back(1);
			O.R.push_back(1);
		}
		
		Z.L[0] = Z.R[0] = 0;
		O.mx = 1;
		
		if(cll)
			Z.mx = 1;
		else
			Z.mx = 0;
		
		Z.ze = 1;
		O.ze = 0;
		Z.len = O.len = 1;
		H.ze = -1;
		
		a[0] = O;
		
		for(ll i = 1 ; i < (ll)vec.size() ; i++)
		{
			if(vec[i] & 1)
				a[i] = merge(a[i - 1], O, cll);
			else
				a[i] = merge(a[i - 1], Z, cll);
			
			a[i] = merge(a[i], a[i - 1], cll);
		}
		
		ll siz = (ll)vec.size();
		node ans = query(siz - 1, 1, a[siz - 1].len, all, bll);
		
		cout << ans.mx en;
	}
	
	return 0;
}