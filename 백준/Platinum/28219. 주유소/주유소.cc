#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second

ll n, k;
ll gap[200010];
vector<ll> vec[200010];
ll all, bll;
ll chk[200010];

void dfs(ll here, ll pa)
{
	vector<ll> vec2;

	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs(i, here);
		vec2.push_back(gap[i] + 1);
	}

	sort(vec2.begin(), vec2.end());
	reverse(vec2.begin(), vec2.end());

	if((ll)vec2.size() == 0)
		return;
	
	if((ll)vec2.size() == 1)
	{
		if(vec2[0] >= k)
		{
			chk[here] = 1;
			gap[here] = -1;
		}
		
		else
			gap[here] = vec2[0];
	}

	else if((ll)vec2.size() >= 2)
	{
		if(vec2[0] + vec2[1] >= k)
		{
			chk[here] = 1;
			gap[here] = -1;
		}

		else
			gap[here] = vec2[0];
	}
}

int main(void)
{
	scanf("%lld %lld", &n, &k);

	for(ll i = 1 ; i < n ; i++)
	{
		scanf("%lld %lld", &all, &bll);

		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}

	dfs(1, 0);

	ll ans = 0;

	for(ll i = 1 ; i <= n ; i++)
		ans += chk[i];
	
	printf("%lld", ans);
	return 0;
}