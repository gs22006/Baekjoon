#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define fi first
#define se second

ll n, m;
ll all, bll;
vector<ll> vec[1010];
ll e1, e2;
ll yuk[1010];
ll chk[1010];
queue<ll> q, cq;
ll dia[1010];
vector<ll> ans;
ll cou = 2;
ll dep[1010];

int main(void)
{
	scanf("%lld %lld", &n, &m);
	
	if(n - 1 != m)
	{
		printf("NO");
		return 0;
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		scanf("%lld %lld", &all, &bll);
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	if(n == 1)
	{
		printf("YES\n1\n1");
		return 0;
	}
	
	else if(n == 2)
	{
		printf("YES\n2\n1 1");
		return 0;
	}
	
	q.push(1);
	chk[1] = 1;
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		e1 = qq;
		
		for(ll i : vec[qq])
		{
			if(chk[i])
				continue;
			
			q.push(i);
			chk[i] = 1;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
		chk[i] = 0;
	
	q.push(e1);
	chk[e1] = 1;
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		e2 = qq;
		
		for(ll i : vec[qq])
		{
			if(chk[i])
				continue;
			
			q.push(i);
			yuk[i] = qq;
			chk[i] = 1;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
		chk[i] = 0;
	
	for(ll i = e2 ; i ; i = yuk[i])
	{
		dia[i] = 1;
		chk[i] = 1;
	}
	
	ll ff = 0;
	
	for(ll i = e2 ; i ; i = yuk[i])
	{
		for(ll j : vec[i])
		{
			if(dia[j])
				continue;
			
			q.push(j);
			cq.push(1);
			chk[j] = cou;
			
			while(!q.empty())
			{
				ll qq = q.front();
				q.pop();
				ll cc = cq.front();
				cq.pop();
				
				if(cc >= 3)
					ff = 1;
				
				dep[cou] = max(dep[cou], cc);
				
				for(ll k : vec[qq])
				{
					if(chk[k])
						continue;
					
					chk[k] = cou;
					q.push(k);
					cq.push(cc + 1);
				}
			}
			
			cou++;
		}
	}
	
	if(ff)
	{
		printf("NO");
		return 0;
	}
	
	printf("YES\n");
	
	for(ll i = e2 ; i ; i = yuk[i])
	{
		if(i == e2 || i == e1)
			continue;
		
		ans.push_back(i);
		
		for(ll j : vec[i])
		{
			if(dia[j] || dep[chk[j]] <= 1)
				continue;
			
			ans.push_back(j);
			ans.push_back(i);
		}
	}
	
	printf("%lld\n", (ll)ans.size() * 2);
	
	for(ll i : ans)
		printf("%lld ", i);
	
	if((ll)ans.size() % 2 == 1)
	{
		for(ll i : ans)
			printf("%lld ", i);
	}
	
	else
	{
		for(ll i = (ll)ans.size() - 1 ; i >= 0 ; i--)
			printf("%lld ", ans[i]);
	}
	
	return 0;
}