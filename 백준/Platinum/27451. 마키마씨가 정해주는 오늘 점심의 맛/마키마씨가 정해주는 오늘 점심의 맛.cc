#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n, m;
ll A, B, C;
ll all, bll;
vector<ll> vec[50];
ll chk1[200010][50], chk2[200010][50], chk3[200010][50];
ll yuk1[200010][50], yuk2[200010][50], yuk3[200010][50];
ll ans1, ans2;

int main(void)
{
	fastio
	
	cin >> n >> m;
	cin >> A >> B >> C;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll;
		vec[all].push_back(bll);
	}
	
	chk1[0][A] = 1;
	chk2[0][B] = 1;
	chk3[0][C] = 1;
	
	for(ll i = 1 ; i <= 200000 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			if(chk1[i - 1][j])
			{
				for(auto &k : vec[j])
				{
					chk1[i][k] = 1;
					yuk1[i][k] = j;
				}
			}
			
			if(chk2[i - 1][j])
			{
				for(auto &k : vec[j])
				{
					chk2[i][k] = 1;
					yuk2[i][k] = j;
				}
			}
			
			if(chk3[i - 1][j])
			{
				for(auto &k : vec[j])
				{
					chk3[i][k] = 1;
					yuk3[i][k] = j;
				}
			}
		}
		
		for(ll j = 1 ; j <= n ; j++)
		{
			if(chk1[i][j] && chk2[i][j] && chk3[i][j])
			{
				ans1 = j;
				ans2 = i;
				break;
			}
		}
		
		if(ans1)
			break;
	}
	
	if(!ans1)
	{
		cout << -1;
		return 0;
	}
	
	cout << ans1 sp << ans2 en;
	
	vector<ll> hmm;
	ll gap = ans2;
	
	for(ll i = ans1 ; gap ; i = yuk1[gap][i], gap--)
		hmm.push_back(i);
	
	hmm.push_back(A);
	
	reverse(hmm.begin(), hmm.end());
	
	for(auto &i : hmm)
		cout << i sp;
	
	cout en;
	hmm.clear();
	gap = ans2;
	
	for(ll i = ans1 ; gap ; i = yuk2[gap][i], gap--)
		hmm.push_back(i);
	
	hmm.push_back(B);
	
	reverse(hmm.begin(), hmm.end());
	
	for(auto &i : hmm)
		cout << i sp;
	
	cout en;
	hmm.clear();
	gap = ans2;
	
	for(ll i = ans1 ; gap ; i = yuk3[gap][i], gap--)
		hmm.push_back(i);
	
	hmm.push_back(C);
	
	reverse(hmm.begin(), hmm.end());
	
	for(auto &i : hmm)
		cout << i sp;
	
	return 0;
}