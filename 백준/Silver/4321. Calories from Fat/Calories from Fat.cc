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

ld a[10], A[10];
ll cal[10] = {0, 9, 4, 4, 4, 7};
string s;
ll cou;

ll st_to_int(string X)
{
	ll ret = 0;
	
	for(auto &i : X)
		ret = ret * 10 + i - '0';
	
	return ret;
}

int main(void)
{
	fastio
	
	while(1)
	{
		cin >> s;
		
		if(s == "-")
		{
			if(cou)
				break;
			
			ld sum = 0;
			
			for(ll i = 1 ; i <= 5 ; i++)
				sum += a[i];
			
			ll ans = round((ld)a[1] * 100.0 / (ld)sum);
			
			cout << ans << "%\n";
			
			for(ll i = 1 ; i <= 5 ; i++)
				a[i] = 0;
			
			cou = 1;
			continue;
		}
		
		ll P = 0, summ = 0;
		cou = 0;
		
		for(ll i = 1 ; i <= 5 ; i++)
		{
			char all = s.back();
			s.pop_back();
			
			ll bll = st_to_int(s);
			
			if(all == 'g')
				A[i] = cal[i] * bll, summ += cal[i] * bll;
			else if(all == 'C')
				A[i] = bll, summ += bll;
			else
				A[i] = -bll, P += bll;
			
			if(i < 5)
				cin >> s;
		}
		
		ld Tsumm = summ * 100.0 / (ld)(100 - P);
		
		for(ll i = 1 ; i <= 5 ; i++)
		{
			if(A[i] < 0)
				A[i] = Tsumm * -A[i] / 100.0;
		}
		
		for(ll i = 1 ; i <= 5 ; i++)
			a[i] += A[i];
	}
	
	return 0;
}