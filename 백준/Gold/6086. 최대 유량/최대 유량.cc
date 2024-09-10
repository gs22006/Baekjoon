#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

ll atol(char x)
{
	if(x <= 'Z')
		return x - 'A';
	
	return x - 'a' + 26;
}

ll n;
char all, bll;
ll cll;
map< pair<ll, ll>, ll> C; //capacity
map< pair<ll, ll>, ll> F; //flow
vector<ll> vec[110];
ll ans;

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		scanf(" %c %c %lld", &all, &bll, &cll);
		
		ll dll = atol(all);
		ll ell = atol(bll);
		
		C[make_pair(dll, ell)] += cll;
		C[make_pair(ell, dll)] += cll;
		vec[dll].push_back(ell);
		vec[ell].push_back(dll);
	}
	
	while(1)
	{
		ll chk[110] = {0, };
		
		for(ll i = 0 ; i < 110 ; i++)
			chk[i] = -1;
		
		queue<ll> q;
		
		q.push(0);
		
		while(!q.empty())
		{
			ll qq = q.front();
			q.pop();
			
			for(ll i = 0 ; i < vec[qq].size() ; i++)
			{
				if(chk[vec[qq][i]] != -1)
					continue;
				
				if(C[make_pair(qq, vec[qq][i])] - F[make_pair(qq, vec[qq][i])] > 0)
				{
					q.push(vec[qq][i]);
					chk[vec[qq][i]] = qq;
				}
			}
		}
		
		if(chk[25] == -1)
			break;
		
		ll minn = MAX;
		
		for(ll i = 25 ; i != 0 ; i = chk[i])
			minn = min(minn, C[make_pair(chk[i], i)] - F[make_pair(chk[i], i)]);
		
		for(ll i = 25 ; i != 0 ; i = chk[i])
		{
			F[make_pair(chk[i], i)] += minn;
			F[make_pair(i, chk[i])] -= minn;
		}
		
		ans += minn;
	}
	
	printf("%lld", ans);
	return 0;
}