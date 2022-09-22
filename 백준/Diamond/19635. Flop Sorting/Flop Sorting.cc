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

ll n;
ll a[5010];
vector< pair<ll, ll> > ans, ans2;

void rev(ll l, ll r)
{
	if(l > r)
		return;
	
	for(ll i = l ; i < (l + r + 1) / 2 ; i++)
	{
		ans.push_back({i, r + l - i});
		swap(a[i], a[r + l - i]);
	}
}

void merge(ll l, ll r)
{
	if(l >= r)
		return;
	
	ll mid = -1;
	
	for(ll i = l ; i < r ; i++)
	{
		if(a[i] > a[i + 1])
		{
			mid = i;
			break;
		}
	}
	
	if(mid == -1)
		return;
	
	ll sun = mid - l + 1;
	vector<ll> vec;
	
	for(ll i = l ; i <= r ; i++)
		vec.push_back(a[i]);
	
	sort(vec.begin(), vec.end());
	
	ll gap = vec[sun - 1];
	ll w = mid + 1;
	ll w2 = mid;
	
	for(ll i = l ; i <= mid ; i++)
	{
		if(a[i] > gap)
		{
			w = i;
			break;
		}
	}
	
	for(ll i = r ; i >= mid + 1 ; i--)
	{
		if(a[i] <= gap)
		{
			w2 = i;
			break;
		}
	}
	
	rev(w, mid);
	rev(mid + 1, w2);
	rev(w, w2);
	
	merge(l, mid);
	merge(mid + 1, r);
}

void merge_sort(ll l, ll r)
{
	if(l >= r)
		return;
	
	ll mid = (l + r) / 2;
	
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	merge(l, r);
}

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld", &a[i]);
	
	merge_sort(1, n);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld", &a[i]);
	
	ans2 = ans;
	ans.clear();
	
	merge_sort(1, n);
	reverse(ans.begin(), ans.end());
	
	for(auto &i : ans)
		ans2.push_back(i);
	
	assert((ll)ans2.size() <= 3000000);
	
	printf("%lld\n", (ll)ans2.size());
	
	for(auto &i : ans2)
		printf("%lld %lld\n", i.fi, i.se);
	
	return 0;
}