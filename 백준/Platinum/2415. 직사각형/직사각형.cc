#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

struct lin
{
	ll x1y1, x2y2, A, B, C;
	
	bool operator < (const lin &xx) const
	{
		if(A != xx.A)
			return A < xx.A;
		
		if(B != xx.B)
			return B < xx.B;
		
		if(C != xx.C)
			return C < xx.C;
		
		return x1y1 / 1000000000LL < xx.x1y1 / 1000000000LL;
	}
};

ll n;
ll x[1510], y[1510];
vector<lin> vec;
ll ans;
vector< pair<ll, ll> > hmm;

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld %lld", &x[i], &y[i]);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = i + 1 ; j <= n ; j++)
		{
			ll I = i, J = j;
			
			if(x[I] > x[J])
				swap(I, J);
			
			vec.push_back({(x[I] + 100000000LL) * 1000000000LL + (y[I] + 100000000LL), (x[J] + 100000000LL) * 1000000000LL + (y[J] + 100000000LL), x[J] - x[I], y[J] - y[I], (y[J] - y[I]) * (y[I] + y[J]) - (x[I] - x[J]) * (x[I] + x[J])});
		}
	}
	
	sort(vec.begin(), vec.end());
	vec.push_back({MAX, MAX, MAX, MAX, MAX});
	
	hmm.push_back(make_pair(vec[0].x1y1 / 1000000000LL - 100000000LL, vec[0].x1y1 % 1000000000LL - 100000000LL));
	hmm.push_back(make_pair(vec[0].x2y2 / 1000000000LL - 100000000LL, vec[0].x2y2 % 1000000000LL - 100000000LL));
	
	for(ll o = 1 ; o < vec.size() ; o++)
	{
		if(vec[o].A != vec[o - 1].A || vec[o].B != vec[o - 1].B || vec[o].C != vec[o - 1].C)
		{
			hmm.push_back(make_pair(vec[o - 1].x2y2 / 1000000000LL - 100000000LL, vec[o - 1].x2y2 % 1000000000LL - 100000000LL));
			hmm.push_back(make_pair(vec[o - 1].x1y1 / 1000000000LL - 100000000LL, vec[o - 1].x1y1 % 1000000000LL - 100000000LL));
			hmm.push_back(hmm[0]);
			
			ll gap = 0;
			
			for(ll j = 1 ; j < hmm.size() ; j++)
				gap += hmm[j].fi * hmm[j - 1].se - hmm[j].se * hmm[j - 1].fi;
			
			ans = max(ans, abs(gap) / 2);
			hmm.clear();
			
			hmm.push_back(make_pair(vec[o].x1y1 / 1000000000LL - 100000000LL, vec[o].x1y1 % 1000000000LL - 100000000LL));
			hmm.push_back(make_pair(vec[o].x2y2 / 1000000000LL - 100000000LL, vec[o].x2y2 % 1000000000LL - 100000000LL));
		}
	}
	
	printf("%lld", ans);
	return 0;
}